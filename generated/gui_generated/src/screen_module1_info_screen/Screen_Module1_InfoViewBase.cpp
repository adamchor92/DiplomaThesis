/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen_module1_info_screen/Screen_Module1_InfoViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include "BitmapDatabase.hpp"

Screen_Module1_InfoViewBase::Screen_Module1_InfoViewBase() :
    buttonCallback(this, &Screen_Module1_InfoViewBase::buttonCallbackHandler)
{
    backgroundBox_Black.setPosition(0, 0, 800, 480);
    backgroundBox_Black.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    textArea_Version.setPosition(0, 265, 800, 49);
    textArea_Version.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_Version.setLinespacing(0);
    Unicode::snprintf(textArea_VersionBuffer, TEXTAREA_VERSION_SIZE, "%s", TypedText(T_SINGLEUSEID253).getText());
    textArea_Version.setWildcard(textArea_VersionBuffer);
    textArea_Version.setTypedText(TypedText(T_SINGLEUSEID252));

    textArea_Speed.setPosition(0, 216, 800, 49);
    textArea_Speed.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_Speed.setLinespacing(0);
    Unicode::snprintf(textArea_SpeedBuffer, TEXTAREA_SPEED_SIZE, "%s", TypedText(T_SINGLEUSEID255).getText());
    textArea_Speed.setWildcard(textArea_SpeedBuffer);
    textArea_Speed.setTypedText(TypedText(T_SINGLEUSEID254));

    textArea_Type.setPosition(0, 122, 800, 49);
    textArea_Type.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_Type.setLinespacing(0);
    Unicode::snprintf(textArea_TypeBuffer, TEXTAREA_TYPE_SIZE, "%s", TypedText(T_SINGLEUSEID257).getText());
    textArea_Type.setWildcard(textArea_TypeBuffer);
    textArea_Type.setTypedText(TypedText(T_SINGLEUSEID256));

    textArea_Vendor.setPosition(0, 74, 800, 49);
    textArea_Vendor.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_Vendor.setLinespacing(0);
    Unicode::snprintf(textArea_VendorBuffer, TEXTAREA_VENDOR_SIZE, "%s", TypedText(T_SINGLEUSEID259).getText());
    textArea_Vendor.setWildcard(textArea_VendorBuffer);
    textArea_Vendor.setTypedText(TypedText(T_SINGLEUSEID258));

    textArea_Model.setPosition(0, 171, 800, 49);
    textArea_Model.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_Model.setLinespacing(0);
    Unicode::snprintf(textArea_ModelBuffer, TEXTAREA_MODEL_SIZE, "%s", TypedText(T_SINGLEUSEID261).getText());
    textArea_Model.setWildcard(textArea_ModelBuffer);
    textArea_Model.setTypedText(TypedText(T_SINGLEUSEID260));

    textArea_Info.setXY(360, 0);
    textArea_Info.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_Info.setLinespacing(0);
    textArea_Info.setTypedText(TypedText(T_SINGLEUSEID264));

    textArea_CPU_Usage.setPosition(618, 451, 182, 29);
    textArea_CPU_Usage.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textArea_CPU_Usage.setLinespacing(0);
    Unicode::snprintf(textArea_CPU_UsageBuffer, TEXTAREA_CPU_USAGE_SIZE, "%s", TypedText(T_SINGLEUSEID266).getText());
    textArea_CPU_Usage.setWildcard(textArea_CPU_UsageBuffer);
    textArea_CPU_Usage.setTypedText(TypedText(T_SINGLEUSEID265));

    buttonWithLabel_Back.setXY(315, 421);
    buttonWithLabel_Back.setBitmaps(Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonWithLabel_Back.setLabelText(TypedText(T_SINGLEUSEID267));
    buttonWithLabel_Back.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonWithLabel_Back.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonWithLabel_Back.setAction(buttonCallback);

    add(backgroundBox_Black);
    add(textArea_Version);
    add(textArea_Speed);
    add(textArea_Type);
    add(textArea_Vendor);
    add(textArea_Model);
    add(textArea_Info);
    add(textArea_CPU_Usage);
    add(buttonWithLabel_Back);
}

void Screen_Module1_InfoViewBase::setupScreen()
{

}

void Screen_Module1_InfoViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonWithLabel_Back)
    {
        //Interaction_GoBack
        //When buttonWithLabel_Back clicked change screen to Screen_Module1_Data
        //Go to Screen_Module1_Data with no screen transition
        application().gotoScreen_Module1_DataScreenNoTransition();
    }
}
