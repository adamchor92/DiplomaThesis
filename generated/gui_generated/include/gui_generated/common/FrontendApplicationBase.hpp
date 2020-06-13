/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    // Screen_Main
    void gotoScreen_MainScreenNoTransition();

    // Screen_Module1_Data
    void gotoScreen_Module1_DataScreenNoTransition();

    // Screen_Module1_Settings
    void gotoScreen_Module1_SettingsScreenNoTransition();

    // Screen_Module1_Graph
    void gotoScreen_Module1_GraphScreenNoTransition();

    // Screen_Module1_Signals
    void gotoScreen_Module1_SignalsScreenNoTransition();

    // Screen_Module1_Info
    void gotoScreen_Module1_InfoScreenNoTransition();

    // Screen_Module2_Data
    void gotoScreen_Module2_DataScreenNoTransition();

    // Screen_Module2_Settings
    void gotoScreen_Module2_SettingsScreenNoTransition();

    // Screen_Module2_Graph
    void gotoScreen_Module2_GraphScreenNoTransition();

    // Screen_Module2_Signals
    void gotoScreen_Module2_SignalsScreenNoTransition();

    // Screen_Module2_Info
    void gotoScreen_Module2_InfoScreenNoTransition();

    // Screen_Module3_Data
    void gotoScreen_Module3_DataScreenNoTransition();

    // Screen_Module3_Settings
    void gotoScreen_Module3_SettingsScreenNoTransition();

    // Screen_Module3_Graph
    void gotoScreen_Module3_GraphScreenNoTransition();

    // Screen_Module3_Signals
    void gotoScreen_Module3_SignalsScreenNoTransition();

    // Screen_Module3_Info
    void gotoScreen_Module3_InfoScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // Screen_Main
    void gotoScreen_MainScreenNoTransitionImpl();

    // Screen_Module1_Data
    void gotoScreen_Module1_DataScreenNoTransitionImpl();

    // Screen_Module1_Settings
    void gotoScreen_Module1_SettingsScreenNoTransitionImpl();

    // Screen_Module1_Graph
    void gotoScreen_Module1_GraphScreenNoTransitionImpl();

    // Screen_Module1_Signals
    void gotoScreen_Module1_SignalsScreenNoTransitionImpl();

    // Screen_Module1_Info
    void gotoScreen_Module1_InfoScreenNoTransitionImpl();

    // Screen_Module2_Data
    void gotoScreen_Module2_DataScreenNoTransitionImpl();

    // Screen_Module2_Settings
    void gotoScreen_Module2_SettingsScreenNoTransitionImpl();

    // Screen_Module2_Graph
    void gotoScreen_Module2_GraphScreenNoTransitionImpl();

    // Screen_Module2_Signals
    void gotoScreen_Module2_SignalsScreenNoTransitionImpl();

    // Screen_Module2_Info
    void gotoScreen_Module2_InfoScreenNoTransitionImpl();

    // Screen_Module3_Data
    void gotoScreen_Module3_DataScreenNoTransitionImpl();

    // Screen_Module3_Settings
    void gotoScreen_Module3_SettingsScreenNoTransitionImpl();

    // Screen_Module3_Graph
    void gotoScreen_Module3_GraphScreenNoTransitionImpl();

    // Screen_Module3_Signals
    void gotoScreen_Module3_SignalsScreenNoTransitionImpl();

    // Screen_Module3_Info
    void gotoScreen_Module3_InfoScreenNoTransitionImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
