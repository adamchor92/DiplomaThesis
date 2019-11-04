/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen_module1_signals_screen/Screen_Module1_SignalsViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

Screen_Module1_SignalsViewBase::Screen_Module1_SignalsViewBase() :
    buttonCallback(this, &Screen_Module1_SignalsViewBase::buttonCallbackHandler),
    sliderValueChangedCallback(this, &Screen_Module1_SignalsViewBase::sliderValueChangedCallbackHandler)
{
    backgroundBox_Black.setPosition(0, 0, 800, 480);
    backgroundBox_Black.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    toggleButton_Parameter1.setXY(235, 120);
    toggleButton_Parameter1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_ON_ID));
    toggleButton_Parameter1.setAction(buttonCallback);

    toggleButton_Parameter2.setXY(235, 170);
    toggleButton_Parameter2.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_ON_ID));
    toggleButton_Parameter2.setAction(buttonCallback);

    toggleButton_Parameter3.setXY(235, 220);
    toggleButton_Parameter3.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_ON_ID));
    toggleButton_Parameter3.setAction(buttonCallback);

    toggleButton_Parameter4.setXY(235, 270);
    toggleButton_Parameter4.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_ON_ID));
    toggleButton_Parameter4.setAction(buttonCallback);

    textArea_Title.setXY(328, 0);
    textArea_Title.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_Title.setLinespacing(0);
    textArea_Title.setTypedText(touchgfx::TypedText(T_SINGLEUSEID285));

    textArea_CPU_Usage.setPosition(618, 451, 182, 29);
    textArea_CPU_Usage.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_CPU_Usage.setLinespacing(0);
    Unicode::snprintf(textArea_CPU_UsageBuffer, TEXTAREA_CPU_USAGE_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID287).getText());
    textArea_CPU_Usage.setWildcard(textArea_CPU_UsageBuffer);
    textArea_CPU_Usage.setTypedText(touchgfx::TypedText(T_SINGLEUSEID286));

    buttonWithLabel_Back.setXY(315, 421);
    buttonWithLabel_Back.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonWithLabel_Back.setLabelText(touchgfx::TypedText(T_SINGLEUSEID288));
    buttonWithLabel_Back.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonWithLabel_Back.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonWithLabel_Back.setAction(buttonCallback);

    slider_TimeRange.setXY(410, 120);
    slider_TimeRange.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_SLIDER_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_SLIDER_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_INDICATORS_SLIDER_ROUND_NOB_ID));
    slider_TimeRange.setupHorizontalSlider(2, 19, 2, 1, 310);
    slider_TimeRange.setValueRange(1, 3);
    slider_TimeRange.setValue(2);
    slider_TimeRange.setNewValueCallback(sliderValueChangedCallback);

    slider_Y_AxisMin.setXY(410, 220);
    slider_Y_AxisMin.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_SLIDER_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_SLIDER_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_INDICATORS_SLIDER_ROUND_NOB_ID));
    slider_Y_AxisMin.setupHorizontalSlider(2, 19, 2, 0, 310);
    slider_Y_AxisMin.setValueRange(1, 100);
    slider_Y_AxisMin.setValue(1);
    slider_Y_AxisMin.setNewValueCallback(sliderValueChangedCallback);

    textArea_TimeRange.setPosition(410, 70, 390, 49);
    textArea_TimeRange.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_TimeRange.setLinespacing(0);
    Unicode::snprintf(textArea_TimeRangeBuffer, TEXTAREA_TIMERANGE_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID295).getText());
    textArea_TimeRange.setWildcard(textArea_TimeRangeBuffer);
    textArea_TimeRange.setTypedText(touchgfx::TypedText(T_SINGLEUSEID289));

    textArea_Y_AxisMin.setPosition(410, 170, 390, 49);
    textArea_Y_AxisMin.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_Y_AxisMin.setLinespacing(0);
    Unicode::snprintf(textArea_Y_AxisMinBuffer, TEXTAREA_Y_AXISMIN_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID293).getText());
    textArea_Y_AxisMin.setWildcard(textArea_Y_AxisMinBuffer);
    textArea_Y_AxisMin.setTypedText(touchgfx::TypedText(T_SINGLEUSEID290));

    slider_Y_AxisMax.setXY(410, 320);
    slider_Y_AxisMax.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_SLIDER_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_SLIDER_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_HORIZONTAL_MEDIUM_INDICATORS_SLIDER_ROUND_NOB_ID));
    slider_Y_AxisMax.setupHorizontalSlider(2, 19, 2, 0, 310);
    slider_Y_AxisMax.setValueRange(1, 100);
    slider_Y_AxisMax.setValue(1);
    slider_Y_AxisMax.setNewValueCallback(sliderValueChangedCallback);

    textArea_Y_AxisMax.setPosition(410, 270, 390, 49);
    textArea_Y_AxisMax.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_Y_AxisMax.setLinespacing(0);
    Unicode::snprintf(textArea_Y_AxisMaxBuffer, TEXTAREA_Y_AXISMAX_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID294).getText());
    textArea_Y_AxisMax.setWildcard(textArea_Y_AxisMaxBuffer);
    textArea_Y_AxisMax.setTypedText(touchgfx::TypedText(T_SINGLEUSEID292));

    textArea_Auto_Y_Range.setPosition(568, 7, 130, 25);
    textArea_Auto_Y_Range.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_Auto_Y_Range.setLinespacing(0);
    textArea_Auto_Y_Range.setTypedText(touchgfx::TypedText(T_SINGLEUSEID296));

    toggleButton_Auto_Y_Range.setXY(704, 0);
    toggleButton_Auto_Y_Range.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_OFF_ID), touchgfx::Bitmap(BITMAP_BLUE_TOGGLEBARS_TOGGLE_ROUND_SMALL_BUTTON_ON_ID));
    toggleButton_Auto_Y_Range.setAction(buttonCallback);

    textArea_Parameter1Name.setPosition(0, 110, 235, 49);
    textArea_Parameter1Name.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_Parameter1Name.setLinespacing(0);
    Unicode::snprintf(textArea_Parameter1NameBuffer, TEXTAREA_PARAMETER1NAME_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID321).getText());
    textArea_Parameter1Name.setWildcard(textArea_Parameter1NameBuffer);
    textArea_Parameter1Name.setTypedText(touchgfx::TypedText(T_SINGLEUSEID320));

    textArea_Parameter2Name.setPosition(0, 160, 235, 49);
    textArea_Parameter2Name.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_Parameter2Name.setLinespacing(0);
    Unicode::snprintf(textArea_Parameter2NameBuffer, TEXTAREA_PARAMETER2NAME_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID323).getText());
    textArea_Parameter2Name.setWildcard(textArea_Parameter2NameBuffer);
    textArea_Parameter2Name.setTypedText(touchgfx::TypedText(T_SINGLEUSEID322));

    textArea_Parameter3Name.setPosition(0, 210, 235, 49);
    textArea_Parameter3Name.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_Parameter3Name.setLinespacing(0);
    Unicode::snprintf(textArea_Parameter3NameBuffer, TEXTAREA_PARAMETER3NAME_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID325).getText());
    textArea_Parameter3Name.setWildcard(textArea_Parameter3NameBuffer);
    textArea_Parameter3Name.setTypedText(touchgfx::TypedText(T_SINGLEUSEID324));

    textArea_Parameter4Name.setPosition(0, 260, 235, 49);
    textArea_Parameter4Name.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_Parameter4Name.setLinespacing(0);
    Unicode::snprintf(textArea_Parameter4NameBuffer, TEXTAREA_PARAMETER4NAME_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID327).getText());
    textArea_Parameter4Name.setWildcard(textArea_Parameter4NameBuffer);
    textArea_Parameter4Name.setTypedText(touchgfx::TypedText(T_SINGLEUSEID326));

    add(backgroundBox_Black);
    add(toggleButton_Parameter1);
    add(toggleButton_Parameter2);
    add(toggleButton_Parameter3);
    add(toggleButton_Parameter4);
    add(textArea_Title);
    add(textArea_CPU_Usage);
    add(buttonWithLabel_Back);
    add(slider_TimeRange);
    add(slider_Y_AxisMin);
    add(textArea_TimeRange);
    add(textArea_Y_AxisMin);
    add(slider_Y_AxisMax);
    add(textArea_Y_AxisMax);
    add(textArea_Auto_Y_Range);
    add(toggleButton_Auto_Y_Range);
    add(textArea_Parameter1Name);
    add(textArea_Parameter2Name);
    add(textArea_Parameter3Name);
    add(textArea_Parameter4Name);
}

void Screen_Module1_SignalsViewBase::setupScreen()
{

}

void Screen_Module1_SignalsViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &toggleButton_Parameter1)
    {
        //Interaction_SetParameter1Graph
        //When toggleButton_Parameter1 clicked call virtual function
        //Call setParameter1GraphVisible
        setParameter1GraphVisible();
    }
    else if (&src == &toggleButton_Parameter2)
    {
        //Interaction_SetParameter2Graph
        //When toggleButton_Parameter2 clicked call virtual function
        //Call setParameter2GraphVisible
        setParameter2GraphVisible();
    }
    else if (&src == &toggleButton_Parameter3)
    {
        //Interaction_SetParameter3Graph
        //When toggleButton_Parameter3 clicked call virtual function
        //Call setParameter3GraphVisible
        setParameter3GraphVisible();
    }
    else if (&src == &toggleButton_Parameter4)
    {
        //Interaction_SetParameter4Graph
        //When toggleButton_Parameter4 clicked call virtual function
        //Call setParameter4GraphVisible
        setParameter4GraphVisible();
    }
    else if (&src == &buttonWithLabel_Back)
    {
        //Interaction_GoBack
        //When buttonWithLabel_Back clicked change screen to Screen_Module1_Graph
        //Go to Screen_Module1_Graph with no screen transition
        application().gotoScreen_Module1_GraphScreenNoTransition();
    }
    else if (&src == &toggleButton_Auto_Y_Range)
    {
        //Interaction_PressedAutoRangeToggleButton
        //When toggleButton_Auto_Y_Range clicked call virtual function
        //Call pressedAutoRangeToggleButton
        pressedAutoRangeToggleButton();
    }
}

void Screen_Module1_SignalsViewBase::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &slider_TimeRange)
    {
        //Interaction_UpdateTimeRange
        //When slider_TimeRange value changed call virtual function
        //Call updateTimeRange
        updateTimeRange(value);
    }
    else if (&src == &slider_Y_AxisMin)
    {
        //Interaction_UpdateYAxisMin
        //When slider_Y_AxisMin value changed call virtual function
        //Call updateY_AxisMin
        updateY_AxisMin(value);
    }
    else if (&src == &slider_Y_AxisMax)
    {
        //Interaction_UpdateYAxisMax
        //When slider_Y_AxisMax value changed call virtual function
        //Call updateY_AxisMax
        updateY_AxisMax(value);
    }
}
