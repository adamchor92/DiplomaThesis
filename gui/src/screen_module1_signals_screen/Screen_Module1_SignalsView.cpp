#include <gui/screen_module1_signals_screen/Screen_Module1_SignalsView.hpp>
#include <gui/screen_module1_graph_screen/Screen_Module1_GraphView.hpp>
#include <gui/model/Model.hpp>

#define SCALE_FACTOR 1000
#define SINE_PERIOD_DEGREES 360

Screen_Module1_SignalsView::Screen_Module1_SignalsView()
{
  #ifndef SIMULATOR     
  uint8_t parameter1NameLength_int = Model::m_parameter1NameLength - '0';
  uint8_t parameter2NameLength_int = Model::m_parameter2NameLength - '0';
  uint8_t parameter3NameLength_int = Model::m_parameter3NameLength - '0';
  uint8_t parameter4NameLength_int = Model::m_parameter4NameLength - '0';
  
  uint16_t parameter1StringDisplay[10] = { 0 };
  uint16_t parameter2StringDisplay[10] = { 0 };
  uint16_t parameter3StringDisplay[10] = { 0 };
  uint16_t parameter4StringDisplay[10] = { 0 };
  
  for (int i = 0; i < parameter1NameLength_int; i++)
  {
    *(parameter1StringDisplay + i) = *(Model::m_parameter1Name + i);
  }
  
  for (int i = 0; i < parameter2NameLength_int; i++)
  {
    *(parameter2StringDisplay + i) = *(Model::m_parameter2Name + i);
  }
  
  for (int i = 0; i < parameter3NameLength_int; i++)
  {
    *(parameter3StringDisplay + i) = *(Model::m_parameter3Name + i);
  }
  
  for (int i = 0; i < parameter4NameLength_int; i++)
  {
    *(parameter4StringDisplay + i) = *(Model::m_parameter4Name + i);
  }
    
  Unicode::snprintf(textArea_Parameter1NameBuffer, TEXTAREA_PARAMETER1NAME_SIZE, "%s", parameter1StringDisplay);
  textArea_Parameter1Name.invalidate();

  Unicode::snprintf(textArea_Parameter2NameBuffer, TEXTAREA_PARAMETER2NAME_SIZE, "%s", parameter2StringDisplay);
  textArea_Parameter2Name.invalidate();

  Unicode::snprintf(textArea_Parameter3NameBuffer, TEXTAREA_PARAMETER3NAME_SIZE, "%s", parameter3StringDisplay);
  textArea_Parameter3Name.invalidate();

  Unicode::snprintf(textArea_Parameter4NameBuffer, TEXTAREA_PARAMETER4NAME_SIZE, "%s", parameter4StringDisplay);
  textArea_Parameter4Name.invalidate();
  #endif
}

void Screen_Module1_SignalsView::setupScreen()
{
  /*Initialize buttons' states*/
  toggleButton_Parameter1.forceState(Screen_Module1_GraphView::m_parameter1GraphEnabled);
  toggleButton_Parameter2.forceState(Screen_Module1_GraphView::m_parameter2GraphEnabled);
  toggleButton_Parameter3.forceState(Screen_Module1_GraphView::m_parameter3GraphEnabled);
  toggleButton_Parameter4.forceState(Screen_Module1_GraphView::m_parameter4GraphEnabled);
  toggleButton_Auto_Y_Range.forceState(Screen_Module1_GraphView::m_autoRangeEnabled);
  
  /*Initialize sliders' values */
  slider_TimeRange.setValue(Screen_Module1_GraphView::m_graphRangeRight / SINE_PERIOD_DEGREES);
  Unicode::snprintf(textArea_TimeRangeBuffer,6,"%d", Screen_Module1_GraphView::m_graphRangeRight);
  textArea_TimeRange.invalidate();
  
  slider_Y_AxisMin.setValue(Screen_Module1_GraphView::m_graphRangeBottom / SCALE_FACTOR  * (-1));
  Unicode::snprintf(textArea_Y_AxisMinBuffer,6,"%d", Screen_Module1_GraphView::m_graphRangeBottom / SCALE_FACTOR);
  textArea_Y_AxisMin.invalidate();
  
  slider_Y_AxisMax.setValue(Screen_Module1_GraphView::m_graphRangeTop / SCALE_FACTOR);
  Unicode::snprintf(textArea_Y_AxisMaxBuffer,6,"%d", Screen_Module1_GraphView::m_graphRangeTop / SCALE_FACTOR);
  textArea_Y_AxisMax.invalidate();
  
  Screen_Module1_SignalsViewBase::setupScreen();
}

void Screen_Module1_SignalsView::tearDownScreen()
{
  Screen_Module1_GraphView::setGraphRanges(slider_Y_AxisMin.getValue() * SCALE_FACTOR * (-1), slider_Y_AxisMax.getValue() * SCALE_FACTOR, slider_TimeRange.getValue() * SINE_PERIOD_DEGREES);
  
  Screen_Module1_SignalsViewBase::tearDownScreen();
}

void Screen_Module1_SignalsView::setParameter1GraphVisible()
{
  if (toggleButton_Parameter1.getState() == true)
  {
    Screen_Module1_GraphView::m_parameter1GraphEnabled = true;
  }
  else
  {
    Screen_Module1_GraphView::m_parameter1GraphEnabled = false;
  }
}

void Screen_Module1_SignalsView::setParameter2GraphVisible()
{
  if (toggleButton_Parameter2.getState() == true)
  {
    Screen_Module1_GraphView::m_parameter2GraphEnabled = true;
  }
  else
  {
    Screen_Module1_GraphView::m_parameter2GraphEnabled = false;
  }
}

void Screen_Module1_SignalsView::setParameter3GraphVisible()
{
  if (toggleButton_Parameter3.getState() == true)
  {
    Screen_Module1_GraphView::m_parameter3GraphEnabled = true;
  }
  else
  {
    Screen_Module1_GraphView::m_parameter3GraphEnabled = false;
  }
}

void Screen_Module1_SignalsView::setParameter4GraphVisible()
{
  if (toggleButton_Parameter4.getState() == true)
  {
    Screen_Module1_GraphView::m_parameter4GraphEnabled = true;
  }
  else
  {
    Screen_Module1_GraphView::m_parameter4GraphEnabled = false;
  }
}

void Screen_Module1_SignalsView::updateTimeRange(int value)
{
  Unicode::snprintf(textArea_TimeRangeBuffer, 6, "%d", value * SINE_PERIOD_DEGREES);
  textArea_TimeRange.invalidate();
}

void Screen_Module1_SignalsView::updateY_AxisMin(int value)
{
  /*Negate value read from slider*/
  value = value * (-1);
  
  Unicode::snprintf(textArea_Y_AxisMinBuffer, 6, "%d", value);
  textArea_Y_AxisMin.invalidate();
}

void Screen_Module1_SignalsView::updateY_AxisMax(int value)
{
  Unicode::snprintf(textArea_Y_AxisMaxBuffer, 6, "%d", value);
  textArea_Y_AxisMax.invalidate();
}

void Screen_Module1_SignalsView::pressedAutoRangeToggleButton()
{
  if(toggleButton_Auto_Y_Range.getState() == true)
  {
    Screen_Module1_GraphView::m_autoRangeEnabled = true; 
    
    textArea_Y_AxisMin.setVisible(false);
    textArea_Y_AxisMax.setVisible(false);
    slider_Y_AxisMin.setVisible(false);
    slider_Y_AxisMax.setVisible(false);
    
    textArea_Y_AxisMin.invalidate();
    textArea_Y_AxisMax.invalidate();
    slider_Y_AxisMin.invalidate();
    slider_Y_AxisMax.invalidate();
  }
  else
  {
    Screen_Module1_GraphView::m_autoRangeEnabled = false;
    
    textArea_Y_AxisMin.setVisible(true);
    textArea_Y_AxisMax.setVisible(true);
    slider_Y_AxisMin.setVisible(true);
    slider_Y_AxisMax.setVisible(true);
    
    textArea_Y_AxisMin.invalidate();
    textArea_Y_AxisMax.invalidate();
    slider_Y_AxisMin.invalidate();
    slider_Y_AxisMax.invalidate();
  }
}
