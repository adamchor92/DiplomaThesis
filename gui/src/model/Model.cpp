#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <gui/common/FrontendApplication.hpp>
#include <gui_generated/common/FrontendApplicationBase.hpp>

#ifndef SIMULATOR
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "task.h"
#include "string.h"
#include "UART_Frame_Struct.h"
#include "../utilities.h"

extern xQueueHandle msgQueueUART_RX_ProcessedFrame;
extern xQueueHandle msgQueueUARTTransmit;
extern xSemaphoreHandle UART_TxSemaphore;

/*Module initialization parameter names*/
uint8_t Model::m_InitParameter1Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_InitParameter2Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_InitParameter3Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_InitParameter4Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_InitParameter5Name[PAYLOAD_SIZE] = {0};

uint8_t Model::m_InitParameter1NameStringLength = 0;
uint8_t Model::m_InitParameter2NameStringLength = 0;
uint8_t Model::m_InitParameter3NameStringLength = 0;
uint8_t Model::m_InitParameter4NameStringLength = 0;
uint8_t Model::m_InitParameter5NameStringLength = 0;

/*Module initialization parameter values*/
uint8_t Model::m_InitParameter1Value[PAYLOAD_SIZE] = {0};
uint8_t Model::m_InitParameter2Value[PAYLOAD_SIZE] = {0};
uint8_t Model::m_InitParameter3Value[PAYLOAD_SIZE] = {0};
uint8_t Model::m_InitParameter4Value[PAYLOAD_SIZE] = {0};
uint8_t Model::m_InitParameter5Value[PAYLOAD_SIZE] = {0};

uint8_t Model::m_InitParameter1ValueStringLength = 0;
uint8_t Model::m_InitParameter2ValueStringLength = 0;
uint8_t Model::m_InitParameter3ValueStringLength = 0;
uint8_t Model::m_InitParameter4ValueStringLength = 0;
uint8_t Model::m_InitParameter5ValueStringLength = 0;

/*Custom parameter names*/
uint8_t Model::m_Parameter1Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_Parameter2Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_Parameter3Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_Parameter4Name[PAYLOAD_SIZE] = {0};

uint8_t Model::m_Parameter1NameLength = 0;
uint8_t Model::m_Parameter2NameLength = 0;
uint8_t Model::m_Parameter3NameLength = 0;
uint8_t Model::m_Parameter4NameLength = 0;

/*Settable parameter names*/
uint8_t Model::m_SettableParameter1Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_SettableParameter2Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_SettableParameter3Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_SettableParameter4Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_SettableParameter5Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_SettableParameter6Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_SettableParameter7Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_SettableParameter8Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_SettableParameter9Name[PAYLOAD_SIZE] = {0};
uint8_t Model::m_SettableParameter10Name[PAYLOAD_SIZE] = {0};

uint8_t Model::m_SettableParameter1NameLength = 0;
uint8_t Model::m_SettableParameter2NameLength = 0;
uint8_t Model::m_SettableParameter3NameLength = 0;
uint8_t Model::m_SettableParameter4NameLength = 0;
uint8_t Model::m_SettableParameter5NameLength = 0;
uint8_t Model::m_SettableParameter6NameLength = 0;
uint8_t Model::m_SettableParameter7NameLength = 0;
uint8_t Model::m_SettableParameter8NameLength = 0;
uint8_t Model::m_SettableParameter9NameLength = 0;
uint8_t Model::m_SettableParameter10NameLength = 0;

uint8_t Model::m_ActiveModule = 0;

extern UART_HandleTypeDef huart6;
UART_HandleTypeDef* Model::m_pHuart6 = &huart6;

/*Structure to which UART task writes processed UART frame*/
UARTFrameStruct_t s_UARTFrame;
#endif

Model::Model() : m_ModelListener(0)
{
#ifndef SIMULATOR
  m_ReceivedInitFrameCount = 0;
  m_ConnectionState = UNCONNECTED;
#endif
}

void Model::tick()
{
#ifndef SIMULATOR
  //get new UART message from message queue (if any)
  if (uxQueueMessagesWaiting(msgQueueUART_RX_ProcessedFrame) > 0)
  {
    /*Clear frame payload*/
    for(int i=0; i < PAYLOAD_SIZE; i++)
    {
      s_UARTFrame.payload[i] = '\0';
    }
    
    /*Frame is validated at this point and can be directly recovered from queue and copied to local s_UARTFrame structure*/    
    xQueueReceive(msgQueueUART_RX_ProcessedFrame, &s_UARTFrame, 0);
    
    if(m_ConnectionState == CONNECTED)
    {
      if(s_UARTFrame.function == '1') //data type frame
      {
        m_ModelListener->notifyNewUART_RX_ParsedFrame(s_UARTFrame);
      }
      else if(s_UARTFrame.function == '3') //deinit connection
      {
        printf("Deinit frame received\n");
        
        /*Set no active modules*/
        m_ActiveModule = 0;
        /*Go back to main menu screen*/
        static_cast<FrontendApplication*>(Application::getInstance())->gotoScreen_MainScreenNoTransition();
        
        m_ConnectionState = UNCONNECTED;
      }
      else
      {
        printf("Wrong frame type in CONNECTED state\n");
      }
    }
    else if(m_ConnectionState == UNCONNECTED)
    {
      if(s_UARTFrame.function == '2') //init type frame
      {
        {
          /*Skip if any module is already active*/
          if(m_ActiveModule == 0)
          {
            if(m_ReceivedInitFrameCount < INIT_FRAME_COUNT)
            {
              switch(s_UARTFrame.parameter)
              {
              case 'a':
                memcpy(m_InitParameter1Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_InitParameter1NameStringLength = s_UARTFrame.length;
                break;
                
              case 'b':
                memcpy(m_InitParameter2Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_InitParameter2NameStringLength = s_UARTFrame.length;
                break;
                
              case 'c':
                memcpy(m_InitParameter3Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_InitParameter3NameStringLength = s_UARTFrame.length;
                break;
                
              case 'd':
                memcpy(m_InitParameter4Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_InitParameter4NameStringLength = s_UARTFrame.length;
                break;
                
              case 'e':
                memcpy(m_InitParameter5Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_InitParameter5NameStringLength = s_UARTFrame.length;
                break;
                
              case 'f':
                memcpy(m_InitParameter1Value, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_InitParameter1ValueStringLength = s_UARTFrame.length;
                break;
                
              case 'g':
                memcpy(m_InitParameter2Value, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_InitParameter2ValueStringLength = s_UARTFrame.length;
                break;
                
              case 'h':
                memcpy(m_InitParameter3Value, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_InitParameter3ValueStringLength = s_UARTFrame.length;
                break;
                
              case 'i':
                memcpy(m_InitParameter4Value, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_InitParameter4ValueStringLength = s_UARTFrame.length;
                break;
                
              case 'j':
                memcpy(m_InitParameter5Value, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_InitParameter5ValueStringLength = s_UARTFrame.length;
                break;
                
              case 'k':
                memcpy(m_Parameter1Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_Parameter1NameLength = s_UARTFrame.length;
                break;
                
              case 'l':
                memcpy(m_Parameter2Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_Parameter2NameLength = s_UARTFrame.length;
                break;
                
              case 'm':
                memcpy(m_Parameter3Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_Parameter3NameLength = s_UARTFrame.length;
                break;
                
              case 'n':
                memcpy(m_Parameter4Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_Parameter4NameLength = s_UARTFrame.length;
                break;
                
              case 'o':
                memcpy(m_SettableParameter1Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_SettableParameter1NameLength = s_UARTFrame.length;
                break;
                
              case 'p':
                memcpy(m_SettableParameter2Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_SettableParameter2NameLength = s_UARTFrame.length;
                break;
                
              case 'q':
                memcpy(m_SettableParameter3Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_SettableParameter3NameLength = s_UARTFrame.length;
                break;
                
              case 'r':
                memcpy(m_SettableParameter4Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_SettableParameter4NameLength = s_UARTFrame.length;
                break;
                
              case 's':
                memcpy(m_SettableParameter5Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_SettableParameter5NameLength = s_UARTFrame.length;
                break;
                
              case 't':
                memcpy(m_SettableParameter6Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_SettableParameter6NameLength = s_UARTFrame.length;
                break;
                
              case 'u':
                memcpy(m_SettableParameter7Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_SettableParameter7NameLength = s_UARTFrame.length;
                break;
                
              case 'v':
                memcpy(m_SettableParameter8Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_SettableParameter8NameLength = s_UARTFrame.length;
                break;
                
              case 'w':
                memcpy(m_SettableParameter9Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_SettableParameter9NameLength = s_UARTFrame.length;
                break;
                
              case 'x':
                memcpy(m_SettableParameter10Name, s_UARTFrame.payload, PAYLOAD_SIZE);
                m_SettableParameter10NameLength = s_UARTFrame.length;
                break;
                
              default:
                printf("UNSUPPORTED INIT FRAME\n");
              }
              
              ++m_ReceivedInitFrameCount;
              
              printf("Received %d out of %d required init frames\n", m_ReceivedInitFrameCount, INIT_FRAME_COUNT);
              
              if(m_ReceivedInitFrameCount == INIT_FRAME_COUNT)
              {
                m_ConnectionState = CONNECTED;
                printf("Received %d init frames\n", m_ReceivedInitFrameCount);
                m_ModelListener->notifyInitFrame(s_UARTFrame); 
                
                /*Set m_ReceivedInitFrameCount back to 0 to make another connection initialization possible after connection deinitialization*/
                m_ReceivedInitFrameCount = 0;
              }
            }
          }
          else
          {
            printf("Skipping frame init due to some module is already active\n");
          }
        }
      }
      else
      {
        printf("Wrong frame type in UNCONNECTED state\n");
      }
    }
    else
    {
      printf("Wrong state in Model.cpp\n");
    }
  }
  m_ModelListener->notifyNewCpuUsageValue(touchgfx::HAL::getInstance()->getMCULoadPct());
#endif
}

void Model::setNewValueToSet(UARTFrameStruct_t & s_UARTFrame)
{
#ifndef SIMULATOR
  uint8_t UART_ValueToTransmit[FRAME_SIZE] = {0};
  
  convertUARTstructToFrameTable(s_UARTFrame, UART_ValueToTransmit);
  
  xQueueSendToBack(msgQueueUARTTransmit, UART_ValueToTransmit, 0);
  
  /*Give semaphore to activate UART_Tx task*/
  xSemaphoreGive(UART_TxSemaphore);
#endif
}
