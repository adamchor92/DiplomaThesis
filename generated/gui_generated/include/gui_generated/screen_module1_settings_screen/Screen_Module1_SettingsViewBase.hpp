/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN_MODULE1_SETTINGSVIEWBASE_HPP
#define SCREEN_MODULE1_SETTINGSVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen_module1_settings_screen/Screen_Module1_SettingsPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/ButtonWithLabel.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/containers/scrollers/ScrollWheel.hpp>
#include <gui/containers/DigitTemplate.hpp>

#include <touchgfx/widgets/RadioButtonGroup.hpp>
class Screen_Module1_SettingsViewBase : public touchgfx::View<Screen_Module1_SettingsPresenter>
{
public:
    Screen_Module1_SettingsViewBase();
    virtual ~Screen_Module1_SettingsViewBase() {}
    virtual void setupScreen();

    virtual void scrollWheel_Digit10UpdateItem(DigitTemplate& item, int16_t itemIndex)
    {
        // Override and implement this function in Screen_Module1_Settings
    }

    virtual void scrollWheel_Digit9UpdateItem(DigitTemplate& item, int16_t itemIndex)
    {
        // Override and implement this function in Screen_Module1_Settings
    }

    virtual void scrollWheel_Digit8UpdateItem(DigitTemplate& item, int16_t itemIndex)
    {
        // Override and implement this function in Screen_Module1_Settings
    }

    virtual void scrollWheel_Digit7UpdateItem(DigitTemplate& item, int16_t itemIndex)
    {
        // Override and implement this function in Screen_Module1_Settings
    }

    virtual void scrollWheel_Digit6UpdateItem(DigitTemplate& item, int16_t itemIndex)
    {
        // Override and implement this function in Screen_Module1_Settings
    }

    virtual void scrollWheel_Digit5UpdateItem(DigitTemplate& item, int16_t itemIndex)
    {
        // Override and implement this function in Screen_Module1_Settings
    }

    virtual void scrollWheel_Digit4UpdateItem(DigitTemplate& item, int16_t itemIndex)
    {
        // Override and implement this function in Screen_Module1_Settings
    }

    virtual void scrollWheel_Digit3UpdateItem(DigitTemplate& item, int16_t itemIndex)
    {
        // Override and implement this function in Screen_Module1_Settings
    }

    virtual void scrollWheel_Digit2UpdateItem(DigitTemplate& item, int16_t itemIndex)
    {
        // Override and implement this function in Screen_Module1_Settings
    }

    virtual void scrollWheel_Digit1UpdateItem(DigitTemplate& item, int16_t itemIndex)
    {
        // Override and implement this function in Screen_Module1_Settings
    }

    /*
     * Virtual Action Handlers
     */
    virtual void setNewValue()
    {
        // Override and implement this function in Screen_Module1_Settings
    }

    virtual void enableParameterButtonPushed()
    {
        // Override and implement this function in Screen_Module1_Settings
    }

    virtual void disableParameterButtonPushed()
    {
        // Override and implement this function in Screen_Module1_Settings
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box backgroundBox_Black;
    touchgfx::ButtonWithLabel buttonWithLabel_SetValue;
    touchgfx::RadioButton radioButtonParameter2;
    touchgfx::RadioButton radioButtonParameter1;
    touchgfx::TextAreaWithOneWildcard textArea_SettableParameter1Name;
    touchgfx::TextArea textArea_ValueToSet;
    touchgfx::TextArea textArea_ParameterToSet;
    touchgfx::TextArea textArea_Title;
    touchgfx::RadioButton radioButtonParameter3;
    touchgfx::RadioButton radioButtonParameter4;
    touchgfx::ButtonWithLabel buttonWithLabel_Back;
    touchgfx::TextAreaWithOneWildcard textArea_CPU_Usage;
    touchgfx::RadioButton radioButtonParameter5;
    touchgfx::RadioButton radioButtonParameter6;
    touchgfx::RadioButton radioButtonParameter7;
    touchgfx::RadioButton radioButtonParameter8;
    touchgfx::Line line1;
    touchgfx::PainterRGB565 line1Painter;
    touchgfx::ButtonWithLabel buttonWithLabel_EnableParameter;
    touchgfx::RadioButton radioButtonParameter9;
    touchgfx::RadioButton radioButtonParameter10;
    touchgfx::ButtonWithLabel buttonWithLabel_DisableParameter;
    touchgfx::TextAreaWithOneWildcard textArea_SettableParameter2Name;
    touchgfx::TextAreaWithOneWildcard textArea_SettableParameter3Name;
    touchgfx::TextAreaWithOneWildcard textArea_SettableParameter4Name;
    touchgfx::TextAreaWithOneWildcard textArea_SettableParameter5Name;
    touchgfx::TextAreaWithOneWildcard textArea_SettableParameter6Name;
    touchgfx::TextAreaWithOneWildcard textArea_SettableParameter7Name;
    touchgfx::TextAreaWithOneWildcard textArea_SettableParameter8Name;
    touchgfx::TextAreaWithOneWildcard textArea_SettableParameter9Name;
    touchgfx::TextAreaWithOneWildcard textArea_SettableParameter10Name;
    touchgfx::ScrollWheel scrollWheel_Digit10;
    touchgfx::DrawableListItems<DigitTemplate, 2> scrollWheel_Digit10ListItems;

    touchgfx::ScrollWheel scrollWheel_Digit9;
    touchgfx::DrawableListItems<DigitTemplate, 2> scrollWheel_Digit9ListItems;

    touchgfx::ScrollWheel scrollWheel_Digit8;
    touchgfx::DrawableListItems<DigitTemplate, 2> scrollWheel_Digit8ListItems;

    touchgfx::ScrollWheel scrollWheel_Digit7;
    touchgfx::DrawableListItems<DigitTemplate, 2> scrollWheel_Digit7ListItems;

    touchgfx::ScrollWheel scrollWheel_Digit6;
    touchgfx::DrawableListItems<DigitTemplate, 2> scrollWheel_Digit6ListItems;

    touchgfx::ScrollWheel scrollWheel_Digit5;
    touchgfx::DrawableListItems<DigitTemplate, 2> scrollWheel_Digit5ListItems;

    touchgfx::ScrollWheel scrollWheel_Digit4;
    touchgfx::DrawableListItems<DigitTemplate, 2> scrollWheel_Digit4ListItems;

    touchgfx::ScrollWheel scrollWheel_Digit3;
    touchgfx::DrawableListItems<DigitTemplate, 2> scrollWheel_Digit3ListItems;

    touchgfx::ScrollWheel scrollWheel_Digit2;
    touchgfx::DrawableListItems<DigitTemplate, 2> scrollWheel_Digit2ListItems;

    touchgfx::ScrollWheel scrollWheel_Digit1;
    touchgfx::DrawableListItems<DigitTemplate, 2> scrollWheel_Digit1ListItems;

    touchgfx::TextArea textArea_Plus;
    touchgfx::RadioButton radioButton_Plus;
    touchgfx::RadioButton radioButton_Minus;
    touchgfx::TextArea textArea_Minus;
    touchgfx::RadioButtonGroup<10> radioButtonGroup_Parameter;
    touchgfx::RadioButtonGroup<2> radioButtonGroup_Sign;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TEXTAREA_SETTABLEPARAMETER1NAME_SIZE = 11;
    touchgfx::Unicode::UnicodeChar textArea_SettableParameter1NameBuffer[TEXTAREA_SETTABLEPARAMETER1NAME_SIZE];
    static const uint16_t TEXTAREA_CPU_USAGE_SIZE = 6;
    touchgfx::Unicode::UnicodeChar textArea_CPU_UsageBuffer[TEXTAREA_CPU_USAGE_SIZE];
    static const uint16_t TEXTAREA_SETTABLEPARAMETER2NAME_SIZE = 11;
    touchgfx::Unicode::UnicodeChar textArea_SettableParameter2NameBuffer[TEXTAREA_SETTABLEPARAMETER2NAME_SIZE];
    static const uint16_t TEXTAREA_SETTABLEPARAMETER3NAME_SIZE = 11;
    touchgfx::Unicode::UnicodeChar textArea_SettableParameter3NameBuffer[TEXTAREA_SETTABLEPARAMETER3NAME_SIZE];
    static const uint16_t TEXTAREA_SETTABLEPARAMETER4NAME_SIZE = 11;
    touchgfx::Unicode::UnicodeChar textArea_SettableParameter4NameBuffer[TEXTAREA_SETTABLEPARAMETER4NAME_SIZE];
    static const uint16_t TEXTAREA_SETTABLEPARAMETER5NAME_SIZE = 11;
    touchgfx::Unicode::UnicodeChar textArea_SettableParameter5NameBuffer[TEXTAREA_SETTABLEPARAMETER5NAME_SIZE];
    static const uint16_t TEXTAREA_SETTABLEPARAMETER6NAME_SIZE = 11;
    touchgfx::Unicode::UnicodeChar textArea_SettableParameter6NameBuffer[TEXTAREA_SETTABLEPARAMETER6NAME_SIZE];
    static const uint16_t TEXTAREA_SETTABLEPARAMETER7NAME_SIZE = 11;
    touchgfx::Unicode::UnicodeChar textArea_SettableParameter7NameBuffer[TEXTAREA_SETTABLEPARAMETER7NAME_SIZE];
    static const uint16_t TEXTAREA_SETTABLEPARAMETER8NAME_SIZE = 11;
    touchgfx::Unicode::UnicodeChar textArea_SettableParameter8NameBuffer[TEXTAREA_SETTABLEPARAMETER8NAME_SIZE];
    static const uint16_t TEXTAREA_SETTABLEPARAMETER9NAME_SIZE = 11;
    touchgfx::Unicode::UnicodeChar textArea_SettableParameter9NameBuffer[TEXTAREA_SETTABLEPARAMETER9NAME_SIZE];
    static const uint16_t TEXTAREA_SETTABLEPARAMETER10NAME_SIZE = 11;
    touchgfx::Unicode::UnicodeChar textArea_SettableParameter10NameBuffer[TEXTAREA_SETTABLEPARAMETER10NAME_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<Screen_Module1_SettingsViewBase, const touchgfx::AbstractButton&> buttonCallback;
    touchgfx::Callback<Screen_Module1_SettingsViewBase, touchgfx::DrawableListItemsInterface*, int16_t, int16_t> updateItemCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);
    void updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex);

    /*
     * Canvas Buffer Size
     */
    static const uint16_t CANVAS_BUFFER_SIZE = 12000;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

};

#endif // SCREEN_MODULE1_SETTINGSVIEWBASE_HPP
