#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_ui.hpp"
#include "ui/CocosGUI.h"
#include "ui/UIScrollViewBar.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace cocos2d::ui;

COCOS_BINDINGS(ccbind_cocos2dx_ui) {


  class_<LayoutParameter>("ccui.LayoutParameter")
    .constructor<>()
    .function("clone", &LayoutParameter::clone, allow_raw_pointers())
    .function("getLayoutType", &LayoutParameter::getLayoutType)
    .function("createCloneInstance", &LayoutParameter::createCloneInstance, allow_raw_pointers())
    .function("copyProperties", &LayoutParameter::copyProperties, allow_raw_pointers())
    .class_function("create", &LayoutParameter::create, allow_raw_pointers())
    .property("_className",  optional_override([](const LayoutParameter& _) -> std::string {return "LayoutParameter";}))    
    ;


  class_<LinearLayoutParameter, base<LayoutParameter>>("ccui.LinearLayoutParameter")
    .constructor<>()
    .function("setGravity", &LinearLayoutParameter::setGravity)
    .function("getGravity", &LinearLayoutParameter::getGravity)
    .class_function("create", &LinearLayoutParameter::create, allow_raw_pointers())
    .property("_className",  optional_override([](const LinearLayoutParameter& _) -> std::string {return "LinearLayoutParameter";}))    
    ;


  class_<RelativeLayoutParameter, base<LayoutParameter>>("ccui.RelativeLayoutParameter")
    .constructor<>()
    .function("setAlign", &RelativeLayoutParameter::setAlign)
    .function("setRelativeToWidgetName", &RelativeLayoutParameter::setRelativeToWidgetName)
    .function("getRelativeName", &RelativeLayoutParameter::getRelativeName)
    .function("getRelativeToWidgetName", &RelativeLayoutParameter::getRelativeToWidgetName)
    .function("setRelativeName", &RelativeLayoutParameter::setRelativeName)
    .function("getAlign", &RelativeLayoutParameter::getAlign)
    .class_function("create", &RelativeLayoutParameter::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RelativeLayoutParameter& _) -> std::string {return "RelativeLayoutParameter";}))    
    ;


  class_<Widget, base<ProtectedNode>>("ccui.Widget")
    .constructor<>()
    .function("setLayoutComponentEnabled", &Widget::setLayoutComponentEnabled)
    .function("setSizePercent", &Widget::setSizePercent)
    .function("getCustomSize", &Widget::getCustomSize)
    .function("getLeftBoundary", &Widget::getLeftBoundary)
    .function("setFlippedX", &Widget::setFlippedX)
    .function("setCallbackName", &Widget::setCallbackName)
    .function("getVirtualRenderer", &Widget::getVirtualRenderer, allow_raw_pointers())
    .function("setPropagateTouchEvents", &Widget::setPropagateTouchEvents)
    .function("isUnifySizeEnabled", &Widget::isUnifySizeEnabled)
    .function("getSizePercent", &Widget::getSizePercent)
    .function("setPositionPercent", &Widget::setPositionPercent)
    .function("setSwallowTouches", &Widget::setSwallowTouches)
    .function("getLayoutSize", &Widget::getLayoutSize)
    .function("setHighlighted", &Widget::setHighlighted)
    .function("setPositionType", &Widget::setPositionType)
    .function("isIgnoreContentAdaptWithSize", &Widget::isIgnoreContentAdaptWithSize)
    .function("getVirtualRendererSize", &Widget::getVirtualRendererSize)
    .function("isHighlighted", &Widget::isHighlighted)
    .function("addCCSEventListener", &Widget::addCCSEventListener)
    .function("getPositionType", &Widget::getPositionType)
    .function("getTopBoundary", &Widget::getTopBoundary)
    .function("ignoreContentAdaptWithSize", &Widget::ignoreContentAdaptWithSize)
    .function("findNextFocusedWidget", &Widget::findNextFocusedWidget, allow_raw_pointers())
    .function("isEnabled", &Widget::isEnabled)
    .function("isFocused", &Widget::isFocused)
    .function("getTouchBeganPosition", &Widget::getTouchBeganPosition)
    .function("isTouchEnabled", &Widget::isTouchEnabled)
    .function("getCallbackName", &Widget::getCallbackName)
    .function("getActionTag", &Widget::getActionTag)
    .function("getWorldPosition", &Widget::getWorldPosition)
    .function("isFocusEnabled", &Widget::isFocusEnabled)
    .function("setFocused", &Widget::setFocused)
    .function("setActionTag", &Widget::setActionTag)
    .function("setTouchEnabled", &Widget::setTouchEnabled)
    .function("setFlippedY", &Widget::setFlippedY)
    .function("_init", &Widget::init)
    .function("setEnabled", &Widget::setEnabled)
    .function("getRightBoundary", &Widget::getRightBoundary)
    .function("setBrightStyle", &Widget::setBrightStyle)
    .function("setLayoutParameter", &Widget::setLayoutParameter, allow_raw_pointers())
    .function("clone", &Widget::clone, allow_raw_pointers())
    .function("setFocusEnabled", &Widget::setFocusEnabled)
    .function("getBottomBoundary", &Widget::getBottomBoundary)
    .function("isBright", &Widget::isBright)
    .function("dispatchFocusEvent", &Widget::dispatchFocusEvent, allow_raw_pointers())
    .function("setUnifySizeEnabled", &Widget::setUnifySizeEnabled)
    .function("isPropagateTouchEvents", &Widget::isPropagateTouchEvents)
    .function("hitTest", &Widget::hitTest, allow_raw_pointers())
    .function("isLayoutComponentEnabled", &Widget::isLayoutComponentEnabled)
    .function("requestFocus", &Widget::requestFocus)
    .function("updateSizeAndPosition", select_overload<void(const cocos2d::Size&)>(&Widget::updateSizeAndPosition))
    .function("updateSizeAndPosition", select_overload<void()>(&Widget::updateSizeAndPosition))
    .function("onFocusChange", &Widget::onFocusChange, allow_raw_pointers())
    .function("getTouchMovePosition", &Widget::getTouchMovePosition)
    .function("getSizeType", &Widget::getSizeType)
    .function("getCallbackType", &Widget::getCallbackType)
    .function("getTouchEndPosition", &Widget::getTouchEndPosition)
    .function("getPositionPercent", &Widget::getPositionPercent)
    .function("propagateTouchEvent", &Widget::propagateTouchEvent, allow_raw_pointers())
    .function("addClickEventListener", &Widget::addClickEventListener)
    .function("isFlippedX", &Widget::isFlippedX)
    .function("isFlippedY", &Widget::isFlippedY)
    .function("isClippingParentContainsPoint", &Widget::isClippingParentContainsPoint)
    .function("setSizeType", &Widget::setSizeType)
    .function("interceptTouchEvent", &Widget::interceptTouchEvent, allow_raw_pointers())
    .function("setBright", &Widget::setBright)
    .function("setCallbackType", &Widget::setCallbackType)
    .function("isSwallowTouches", &Widget::isSwallowTouches)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("enableDpadNavigation", &Widget::enableDpadNavigation, allow_raw_pointers())
    .class_function("create", &Widget::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Widget& _) -> std::string {return "Widget";}))    
    .allow_subclass<emscripten::wrapper<Widget>>("_subclass.ccui.Widget")
    ;


  class_<Layout, base<Widget>>("ccui.Layout")
    .constructor<>()
    .function("setBackGroundColorVector", &Layout::setBackGroundColorVector)
    .function("setClippingType", &Layout::setClippingType)
    .function("setBackGroundColorType", &Layout::setBackGroundColorType)
    .function("setLoopFocus", &Layout::setLoopFocus)
    .function("setBackGroundImageColor", &Layout::setBackGroundImageColor)
    .function("getBackGroundColorVector", &Layout::getBackGroundColorVector)
    .function("getClippingType", &Layout::getClippingType)
    .function("getRenderFile", &Layout::getRenderFile)
    .function("isLoopFocus", &Layout::isLoopFocus)
    .function("removeBackGroundImage", &Layout::removeBackGroundImage)
    .function("getBackGroundColorOpacity", &Layout::getBackGroundColorOpacity)
    .function("isClippingEnabled", &Layout::isClippingEnabled)
    .function("setBackGroundImageOpacity", &Layout::setBackGroundImageOpacity)
    .function("setBackGroundImage", &Layout::setBackGroundImage)
    .function("setBackGroundImage", optional_override(
        [](Layout& this_, const std::string& arg0){
        return this_.setBackGroundImage(arg0);
      }))
    .function("setBackGroundColor", select_overload<void(const cocos2d::Color3B&, const cocos2d::Color3B&)>(&Layout::setBackGroundColor))
    .function("setBackGroundColor", select_overload<void(const cocos2d::Color3B&)>(&Layout::setBackGroundColor))
    .function("requestDoLayout", &Layout::requestDoLayout)
    .function("getBackGroundImageCapInsets", &Layout::getBackGroundImageCapInsets)
    .function("getBackGroundColor", &Layout::getBackGroundColor)
    .function("setClippingEnabled", &Layout::setClippingEnabled)
    .function("getBackGroundImageColor", &Layout::getBackGroundImageColor)
    .function("isBackGroundImageScale9Enabled", &Layout::isBackGroundImageScale9Enabled)
    .function("getBackGroundColorType", &Layout::getBackGroundColorType)
    .function("getBackGroundEndColor", &Layout::getBackGroundEndColor)
    .function("setBackGroundColorOpacity", &Layout::setBackGroundColorOpacity)
    .function("getBackGroundImageOpacity", &Layout::getBackGroundImageOpacity)
    .function("isPassFocusToChild", &Layout::isPassFocusToChild)
    .function("setBackGroundImageCapInsets", &Layout::setBackGroundImageCapInsets)
    .function("getBackGroundImageTextureSize", &Layout::getBackGroundImageTextureSize)
    .function("forceDoLayout", &Layout::forceDoLayout)
    .function("getLayoutType", &Layout::getLayoutType)
    .function("setPassFocusToChild", &Layout::setPassFocusToChild)
    .function("getBackGroundStartColor", &Layout::getBackGroundStartColor)
    .function("setBackGroundImageScale9Enabled", &Layout::setBackGroundImageScale9Enabled)
    .function("setLayoutType", &Layout::setLayoutType)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", &Layout::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Layout& _) -> std::string {return "Layout";}))    
    .allow_subclass<emscripten::wrapper<Layout>>("_subclass.ccui.Layout")
    ;


  class_<Button, base<Widget>>("ccui.Button")
    .constructor<>()
    .function("getNormalTextureSize", &Button::getNormalTextureSize)
    .function("getTitleText", &Button::getTitleText)
    .function("setTitleLabel", &Button::setTitleLabel, allow_raw_pointers())
    .function("setTitleFontSize", &Button::setTitleFontSize)
    .function("resetPressedRender", &Button::resetPressedRender)
    .function("setScale9Enabled", &Button::setScale9Enabled)
    .function("resetDisabledRender", &Button::resetDisabledRender)
    .function("getTitleRenderer", &Button::getTitleRenderer, allow_raw_pointers())
    .function("getRendererClicked", &Button::getRendererClicked, allow_raw_pointers())
    .function("getDisabledFile", &Button::getDisabledFile)
    .function("getZoomScale", &Button::getZoomScale)
    .function("getCapInsetsDisabledRenderer", &Button::getCapInsetsDisabledRenderer)
    .function("setTitleColor", &Button::setTitleColor)
    .function("getNormalFile", &Button::getNormalFile)
    .function("resetNormalRender", &Button::resetNormalRender)
    .function("getRendererDisabled", &Button::getRendererDisabled, allow_raw_pointers())
    .function("setCapInsetsDisabledRenderer", &Button::setCapInsetsDisabledRenderer)
    .function("setCapInsets", &Button::setCapInsets)
    .function("setTitleText", &Button::setTitleText)
    .function("setCapInsetsNormalRenderer", &Button::setCapInsetsNormalRenderer)
    .function("setTitleFontName", &Button::setTitleFontName)
    .function("getCapInsetsNormalRenderer", &Button::getCapInsetsNormalRenderer)
    .function("setTitleAlignment", select_overload<void(cocos2d::TextHAlignment, cocos2d::TextVAlignment)>(&Button::setTitleAlignment))
    .function("setTitleAlignment", select_overload<void(cocos2d::TextHAlignment)>(&Button::setTitleAlignment))
    .function("getCapInsetsPressedRenderer", &Button::getCapInsetsPressedRenderer)
    .function("loadTextures", &Button::loadTextures)
    .function("loadTextures", optional_override(
        [](Button& this_, const std::string& arg0, const std::string& arg1){
        return this_.loadTextures(arg0, arg1);
      }))
    .function("loadTextures", optional_override(
        [](Button& this_, const std::string& arg0, const std::string& arg1, const std::string& arg2){
        return this_.loadTextures(arg0, arg1, arg2);
      }))
    .function("isScale9Enabled", &Button::isScale9Enabled)
    .function("setCapInsetsPressedRenderer", &Button::setCapInsetsPressedRenderer)
    .function("getPressedFile", &Button::getPressedFile)
    .function("getTitleLabel", &Button::getTitleLabel, allow_raw_pointers())
    .function("getTitleFontSize", &Button::getTitleFontSize)
    .function("getRendererNormal", &Button::getRendererNormal, allow_raw_pointers())
    .function("getTitleFontName", &Button::getTitleFontName)
    .function("getTitleColor", &Button::getTitleColor)
    .function("setPressedActionEnabled", &Button::setPressedActionEnabled)
    .function("setZoomScale", &Button::setZoomScale)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::Button*(const std::string&, const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&Button::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::Button*()>(&Button::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Button& _) -> std::string {return "Button";}))    
    .allow_subclass<emscripten::wrapper<Button>>("_subclass.ccui.Button")
    ;

  class_<AbstractCheckButton, base<Widget>>("ccui.AbstractCheckButton")
    .function("getCrossDisabledFile", &AbstractCheckButton::getCrossDisabledFile)
    .function("getBackDisabledFile", &AbstractCheckButton::getBackDisabledFile)
    .function("getCrossNormalFile", &AbstractCheckButton::getCrossNormalFile)
    .function("setSelected", &AbstractCheckButton::setSelected)
    .function("getBackPressedFile", &AbstractCheckButton::getBackPressedFile)
    .function("getRendererFrontCrossDisabled", &AbstractCheckButton::getRendererFrontCrossDisabled, allow_raw_pointers())
    .function("getRendererBackground", &AbstractCheckButton::getRendererBackground, allow_raw_pointers())
    .function("getRendererBackgroundDisabled", &AbstractCheckButton::getRendererBackgroundDisabled, allow_raw_pointers())
    .function("isSelected", &AbstractCheckButton::isSelected)
    .function("getBackNormalFile", &AbstractCheckButton::getBackNormalFile)
    .function("loadTextures", &AbstractCheckButton::loadTextures)
    .function("loadTextures", optional_override(
        [](AbstractCheckButton& this_, const std::string& arg0, const std::string& arg1, const std::string& arg2, const std::string& arg3, const std::string& arg4){
        return this_.loadTextures(arg0, arg1, arg2, arg3, arg4);
      }))
    .function("getZoomScale", &AbstractCheckButton::getZoomScale)
    .function("getRendererFrontCross", &AbstractCheckButton::getRendererFrontCross, allow_raw_pointers())
    .function("getRendererBackgroundSelected", &AbstractCheckButton::getRendererBackgroundSelected, allow_raw_pointers())
    .function("setZoomScale", &AbstractCheckButton::setZoomScale)
    .property("_className",  optional_override([](const AbstractCheckButton& _) -> std::string {return "AbstractCheckButton";}))    
    ;


  class_<CheckBox, base<AbstractCheckButton>>("ccui.CheckBox")
    .constructor<>()
    .function("addEventListener", &CheckBox::addEventListener)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::CheckBox*(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&CheckBox::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::CheckBox*()>(&CheckBox::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::CheckBox*(const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&CheckBox::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const CheckBox& _) -> std::string {return "CheckBox";}))    
    .allow_subclass<emscripten::wrapper<CheckBox>>("_subclass.ccui.CheckBox")
    ;


  class_<RadioButton, base<AbstractCheckButton>>("ccui.RadioButton")
    .constructor<>()
    .function("addEventListener", &RadioButton::addEventListener)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::RadioButton*(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&RadioButton::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::RadioButton*()>(&RadioButton::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::RadioButton*(const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&RadioButton::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const RadioButton& _) -> std::string {return "RadioButton";}))    
    .allow_subclass<emscripten::wrapper<RadioButton>>("_subclass.ccui.RadioButton")
    ;


  class_<RadioButtonGroup, base<Widget>>("ccui.RadioButtonGroup")
    .constructor<>()
    .function("removeRadioButton", &RadioButtonGroup::removeRadioButton, allow_raw_pointers())
    .function("isAllowedNoSelection", &RadioButtonGroup::isAllowedNoSelection)
    .function("getSelectedButtonIndex", &RadioButtonGroup::getSelectedButtonIndex)
    .function("setAllowedNoSelection", &RadioButtonGroup::setAllowedNoSelection)
    .function("setSelectedButtonWithoutEvent", select_overload<void(cocos2d::ui::RadioButton*)>(&RadioButtonGroup::setSelectedButtonWithoutEvent), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("addEventListener", &RadioButtonGroup::addEventListener)
    .function("removeAllRadioButtons", &RadioButtonGroup::removeAllRadioButtons)
    .function("getRadioButtonByIndex", &RadioButtonGroup::getRadioButtonByIndex, allow_raw_pointers())
    .function("getNumberOfRadioButtons", &RadioButtonGroup::getNumberOfRadioButtons)
    .function("addRadioButton", &RadioButtonGroup::addRadioButton, allow_raw_pointers())
    .function("setSelectedButton", select_overload<void(cocos2d::ui::RadioButton*)>(&RadioButtonGroup::setSelectedButton), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", &RadioButtonGroup::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RadioButtonGroup& _) -> std::string {return "RadioButtonGroup";}))    
    .allow_subclass<emscripten::wrapper<RadioButtonGroup>>("_subclass.ccui.RadioButtonGroup")
    ;


  class_<ImageView, base<Widget>>("ccui.ImageView")
    .constructor<>()
    .function("getBlendFunc", &ImageView::getBlendFunc)
    .function("setBlendFunc", &ImageView::setBlendFunc)
    .function("setScale9Enabled", &ImageView::setScale9Enabled)
    .function("setTextureRect", &ImageView::setTextureRect)
    .function("setCapInsets", &ImageView::setCapInsets)
    .function("getRenderFile", &ImageView::getRenderFile)
    .function("getCapInsets", &ImageView::getCapInsets)
    .function("isScale9Enabled", &ImageView::isScale9Enabled)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::ImageView*(const std::string&, cocos2d::ui::Widget::TextureResType)>(&ImageView::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::ImageView*()>(&ImageView::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ImageView& _) -> std::string {return "ImageView";}))    
    .allow_subclass<emscripten::wrapper<ImageView>>("_subclass.ccui.ImageView")
    ;


  class_<Text, base<Widget>>("ccui.Text")
    .constructor<>()
    .function("enableShadow", &Text::enableShadow)
    .function("enableShadow", optional_override(
        [](Text& this_){
        return this_.enableShadow();
      }))
    .function("enableShadow", optional_override(
        [](Text& this_, const cocos2d::Color4B& arg0){
        return this_.enableShadow(arg0);
      }))
    .function("enableShadow", optional_override(
        [](Text& this_, const cocos2d::Color4B& arg0, const cocos2d::Size& arg1){
        return this_.enableShadow(arg0, arg1);
      }))
    .function("getFontSize", &Text::getFontSize)
    .function("getString", &Text::getString)
    .function("disableEffect", select_overload<void(cocos2d::LabelEffect)>(&Text::disableEffect))
    .function("disableEffect", select_overload<void()>(&Text::disableEffect))
    .function("getLabelEffectType", &Text::getLabelEffectType)
    .function("getTextColor", &Text::getTextColor)
    .function("getBlendFunc", &Text::getBlendFunc)
    .function("setTextVerticalAlignment", &Text::setTextVerticalAlignment)
    .function("setFontName", &Text::setFontName)
    .function("setTouchScaleChangeEnabled", &Text::setTouchScaleChangeEnabled)
    .function("getShadowOffset", &Text::getShadowOffset)
    .function("setString", &Text::setString)
    .function("getOutlineSize", &Text::getOutlineSize)
    .function("getShadowBlurRadius", &Text::getShadowBlurRadius)
    .function("isTouchScaleChangeEnabled", &Text::isTouchScaleChangeEnabled)
    .function("getFontName", &Text::getFontName)
    .function("setTextAreaSize", &Text::setTextAreaSize)
    .function("getStringLength", &Text::getStringLength)
    .function("getAutoRenderSize", &Text::getAutoRenderSize)
    .function("enableOutline", &Text::enableOutline)
    .function("enableOutline", optional_override(
        [](Text& this_, const cocos2d::Color4B& arg0){
        return this_.enableOutline(arg0);
      }))
    .function("getEffectColor", &Text::getEffectColor)
    .function("getType", &Text::getType)
    .function("getTextHorizontalAlignment", &Text::getTextHorizontalAlignment)
    .function("isShadowEnabled", &Text::isShadowEnabled)
    .function("setFontSize", &Text::setFontSize)
    .function("getShadowColor", &Text::getShadowColor)
    .function("setTextColor", &Text::setTextColor)
    .function("enableGlow", &Text::enableGlow)
    .function("getLetter", &Text::getLetter, allow_raw_pointers())
    .function("setBlendFunc", &Text::setBlendFunc)
    .function("getTextVerticalAlignment", &Text::getTextVerticalAlignment)
    .function("getTextAreaSize", &Text::getTextAreaSize)
    .function("setTextHorizontalAlignment", &Text::setTextHorizontalAlignment)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::Text*(const std::string&, const std::string&, float)>(&Text::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::Text*()>(&Text::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Text& _) -> std::string {return "Text";}))    
    .allow_subclass<emscripten::wrapper<Text>>("_subclass.ccui.Text")
    ;


  class_<TextAtlas, base<Widget>>("ccui.TextAtlas")
    .constructor<>()
    .function("getStringLength", &TextAtlas::getStringLength)
    .function("getString", &TextAtlas::getString)
    .function("setString", &TextAtlas::setString)
    .function("getRenderFile", &TextAtlas::getRenderFile)
    .function("setProperty", &TextAtlas::setProperty)
    .function("adaptRenderers", &TextAtlas::adaptRenderers)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TextAtlas*(const std::string&, const std::string&, int, int, const std::string&)>(&TextAtlas::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TextAtlas*()>(&TextAtlas::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TextAtlas& _) -> std::string {return "TextAtlas";}))    
    .allow_subclass<emscripten::wrapper<TextAtlas>>("_subclass.ccui.TextAtlas")
    ;


  class_<LoadingBar, base<Widget>>("ccui.LoadingBar")
    .constructor<>()
    .function("setPercent", &LoadingBar::setPercent)
    .function("setDirection", &LoadingBar::setDirection)
    .function("getRenderFile", &LoadingBar::getRenderFile)
    .function("setScale9Enabled", &LoadingBar::setScale9Enabled)
    .function("setCapInsets", &LoadingBar::setCapInsets)
    .function("getDirection", &LoadingBar::getDirection)
    .function("getCapInsets", &LoadingBar::getCapInsets)
    .function("isScale9Enabled", &LoadingBar::isScale9Enabled)
    .function("getPercent", &LoadingBar::getPercent)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::LoadingBar*(const std::string&, float)>(&LoadingBar::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::LoadingBar*()>(&LoadingBar::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::LoadingBar*(const std::string&, cocos2d::ui::Widget::TextureResType, float)>(&LoadingBar::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const LoadingBar& _) -> std::string {return "LoadingBar";}))    
    .allow_subclass<emscripten::wrapper<LoadingBar>>("_subclass.ccui.LoadingBar")
    ;


  class_<ScrollView, base<Layout>>("ccui.ScrollView")
    .constructor<>()
    .function("scrollToTop", &ScrollView::scrollToTop)
    .function("scrollToPercentHorizontal", &ScrollView::scrollToPercentHorizontal)
    .function("setScrollBarOpacity", &ScrollView::setScrollBarOpacity)
    .function("setScrollBarEnabled", &ScrollView::setScrollBarEnabled)
    .function("isInertiaScrollEnabled", &ScrollView::isInertiaScrollEnabled)
    .function("scrollToBottom", &ScrollView::scrollToBottom)
    .function("getScrolledPercentBothDirection", &ScrollView::getScrolledPercentBothDirection)
    .function("getDirection", &ScrollView::getDirection)
    .function("setScrollBarColor", &ScrollView::setScrollBarColor)
    .function("scrollToBottomLeft", &ScrollView::scrollToBottomLeft)
    .function("getInnerContainer", &ScrollView::getInnerContainer, allow_raw_pointers())
    .function("jumpToBottom", &ScrollView::jumpToBottom)
    .function("setInnerContainerPosition", &ScrollView::setInnerContainerPosition)
    .function("setDirection", &ScrollView::setDirection)
    .function("scrollToTopLeft", &ScrollView::scrollToTopLeft)
    .function("jumpToTopRight", &ScrollView::jumpToTopRight)
    .function("scrollToPercentBothDirection", &ScrollView::scrollToPercentBothDirection)
    .function("setInnerContainerSize", &ScrollView::setInnerContainerSize)
    .function("getInnerContainerPosition", &ScrollView::getInnerContainerPosition)
    .function("jumpToTop", &ScrollView::jumpToTop)
    .function("getScrolledPercentVertical", &ScrollView::getScrolledPercentVertical)
    .function("isBounceEnabled", &ScrollView::isBounceEnabled)
    .function("jumpToPercentVertical", &ScrollView::jumpToPercentVertical)
    .function("addEventListener", &ScrollView::addEventListener)
    .function("setScrollBarAutoHideTime", &ScrollView::setScrollBarAutoHideTime)
    .function("stopScroll", &ScrollView::stopScroll)
    .function("setScrollBarPositionFromCornerForHorizontal", &ScrollView::setScrollBarPositionFromCornerForHorizontal)
    .function("setInertiaScrollEnabled", &ScrollView::setInertiaScrollEnabled)
    .function("setScrollBarAutoHideEnabled", &ScrollView::setScrollBarAutoHideEnabled)
    .function("getScrollBarColor", &ScrollView::getScrollBarColor)
    .function("jumpToTopLeft", &ScrollView::jumpToTopLeft)
    .function("isScrollBarEnabled", &ScrollView::isScrollBarEnabled)
    .function("isAutoScrolling", &ScrollView::isAutoScrolling)
    .function("jumpToBottomRight", &ScrollView::jumpToBottomRight)
    .function("setTouchTotalTimeThreshold", &ScrollView::setTouchTotalTimeThreshold)
    .function("getTouchTotalTimeThreshold", &ScrollView::getTouchTotalTimeThreshold)
    .function("getScrollBarPositionFromCornerForHorizontal", &ScrollView::getScrollBarPositionFromCornerForHorizontal)
    .function("getScrolledPercentHorizontal", &ScrollView::getScrolledPercentHorizontal)
    .function("setBounceEnabled", &ScrollView::setBounceEnabled)
    .function("stopAutoScroll", &ScrollView::stopAutoScroll)
    .function("scrollToTopRight", &ScrollView::scrollToTopRight)
    .function("isScrolling", &ScrollView::isScrolling)
    .function("scrollToLeft", &ScrollView::scrollToLeft)
    .function("jumpToPercentBothDirection", &ScrollView::jumpToPercentBothDirection)
    .function("stopOverallScroll", &ScrollView::stopOverallScroll)
    .function("scrollToPercentVertical", &ScrollView::scrollToPercentVertical)
    .function("setScrollBarWidth", &ScrollView::setScrollBarWidth)
    .function("getScrollBarOpacity", &ScrollView::getScrollBarOpacity)
    .function("scrollToBottomRight", &ScrollView::scrollToBottomRight)
    .function("setScrollBarPositionFromCorner", &ScrollView::setScrollBarPositionFromCorner)
    .function("setScrollBarPositionFromCornerForVertical", &ScrollView::setScrollBarPositionFromCornerForVertical)
    .function("getScrollBarAutoHideTime", &ScrollView::getScrollBarAutoHideTime)
    .function("jumpToLeft", &ScrollView::jumpToLeft)
    .function("scrollToRight", &ScrollView::scrollToRight)
    .function("getScrollBarPositionFromCornerForVertical", &ScrollView::getScrollBarPositionFromCornerForVertical)
    .function("getScrollBarWidth", &ScrollView::getScrollBarWidth)
    .function("isScrollBarAutoHideEnabled", &ScrollView::isScrollBarAutoHideEnabled)
    .function("jumpToBottomLeft", &ScrollView::jumpToBottomLeft)
    .function("jumpToRight", &ScrollView::jumpToRight)
    .function("getInnerContainerSize", &ScrollView::getInnerContainerSize)
    .function("jumpToPercentHorizontal", &ScrollView::jumpToPercentHorizontal)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", &ScrollView::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ScrollView& _) -> std::string {return "ScrollView";}))    
    .allow_subclass<emscripten::wrapper<ScrollView>>("_subclass.ccui.ScrollView")
    ;


  class_<ListView, base<ScrollView>>("ccui.ListView")
    .constructor<>()
    .function("setGravity", &ListView::setGravity)
    .function("removeLastItem", &ListView::removeLastItem)
    .function("getLeftPadding", &ListView::getLeftPadding)
    .function("getCenterItemInCurrentView", &ListView::getCenterItemInCurrentView, allow_raw_pointers())
    .function("getCurSelectedIndex", &ListView::getCurSelectedIndex)
    .function("getScrollDuration", &ListView::getScrollDuration)
    .function("getMagneticAllowedOutOfBoundary", &ListView::getMagneticAllowedOutOfBoundary)
    .function("getItemsMargin", &ListView::getItemsMargin)
    .function("scrollToItem", select_overload<void(ssize_t, const cocos2d::Vec2&, const cocos2d::Vec2&, float)>(&ListView::scrollToItem))
    .function("scrollToItem", select_overload<void(ssize_t, const cocos2d::Vec2&, const cocos2d::Vec2&)>(&ListView::scrollToItem))
    .function("jumpToItem", &ListView::jumpToItem)
    .function("setTopPadding", &ListView::setTopPadding)
    .function("getIndex", &ListView::getIndex, allow_raw_pointers())
    .function("pushBackCustomItem", &ListView::pushBackCustomItem, allow_raw_pointers())
    .function("setCurSelectedIndex", &ListView::setCurSelectedIndex)
    .function("insertDefaultItem", &ListView::insertDefaultItem)
    .function("setMagneticType", &ListView::setMagneticType)
    .function("setMagneticAllowedOutOfBoundary", &ListView::setMagneticAllowedOutOfBoundary)
    .function("addEventListener", select_overload<void (const ListView::ccListViewCallback&)>(&ListView::addEventListener))
    .function("doLayout", &ListView::doLayout)
    .function("getTopmostItemInCurrentView", &ListView::getTopmostItemInCurrentView, allow_raw_pointers())
    .function("setPadding", &ListView::setPadding)
    .function("removeAllItems", &ListView::removeAllItems)
    .function("getRightPadding", &ListView::getRightPadding)
    .function("getBottommostItemInCurrentView", &ListView::getBottommostItemInCurrentView, allow_raw_pointers())
    .function("getItems", &ListView::getItems)
    .function("getLeftmostItemInCurrentView", &ListView::getLeftmostItemInCurrentView, allow_raw_pointers())
    .function("setItemsMargin", &ListView::setItemsMargin)
    .function("getMagneticType", &ListView::getMagneticType)
    .function("getItem", &ListView::getItem, allow_raw_pointers())
    .function("removeItem", &ListView::removeItem)
    .function("getTopPadding", &ListView::getTopPadding)
    .function("pushBackDefaultItem", &ListView::pushBackDefaultItem)
    .function("setLeftPadding", &ListView::setLeftPadding)
    .function("getClosestItemToPosition", &ListView::getClosestItemToPosition, allow_raw_pointers())
    .function("setBottomPadding", &ListView::setBottomPadding)
    .function("setScrollDuration", &ListView::setScrollDuration)
    .function("getClosestItemToPositionInCurrentView", &ListView::getClosestItemToPositionInCurrentView, allow_raw_pointers())
    .function("getRightmostItemInCurrentView", &ListView::getRightmostItemInCurrentView, allow_raw_pointers())
    .function("setRightPadding", &ListView::setRightPadding)
    .function("setItemModel", &ListView::setItemModel, allow_raw_pointers())
    .function("getBottomPadding", &ListView::getBottomPadding)
    .function("insertCustomItem", &ListView::insertCustomItem, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", &ListView::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ListView& _) -> std::string {return "ListView";}))    
    .allow_subclass<emscripten::wrapper<ListView>>("_subclass.ccui.ListView")
    ;


  class_<Slider, base<Widget>>("ccui.Slider")
    .constructor<>()
    .function("setPercent", &Slider::setPercent)
    .function("getMaxPercent", &Slider::getMaxPercent)
    .function("getBallNormalFile", &Slider::getBallNormalFile)
    .function("getSlidBallDisabledRenderer", &Slider::getSlidBallDisabledRenderer, allow_raw_pointers())
    .function("setScale9Enabled", &Slider::setScale9Enabled)
    .function("getBallPressedFile", &Slider::getBallPressedFile)
    .function("getZoomScale", &Slider::getZoomScale)
    .function("setCapInsetProgressBarRenderer", &Slider::setCapInsetProgressBarRenderer)
    .function("loadSlidBallTextures", &Slider::loadSlidBallTextures)
    .function("loadSlidBallTextures", optional_override(
        [](Slider& this_, const std::string& arg0){
        return this_.loadSlidBallTextures(arg0);
      }))
    .function("loadSlidBallTextures", optional_override(
        [](Slider& this_, const std::string& arg0, const std::string& arg1){
        return this_.loadSlidBallTextures(arg0, arg1);
      }))
    .function("loadSlidBallTextures", optional_override(
        [](Slider& this_, const std::string& arg0, const std::string& arg1, const std::string& arg2){
        return this_.loadSlidBallTextures(arg0, arg1, arg2);
      }))
    .function("getSlidBallRenderer", &Slider::getSlidBallRenderer, allow_raw_pointers())
    .function("addEventListener", &Slider::addEventListener)
    .function("setMaxPercent", &Slider::setMaxPercent)
    .function("getProgressBarFile", &Slider::getProgressBarFile)
    .function("getCapInsetsBarRenderer", &Slider::getCapInsetsBarRenderer)
    .function("updateVisualSlider", &Slider::updateVisualSlider)
    .function("getCapInsetsProgressBarRenderer", &Slider::getCapInsetsProgressBarRenderer)
    .function("getSlidBallPressedRenderer", &Slider::getSlidBallPressedRenderer, allow_raw_pointers())
    .function("getBackFile", &Slider::getBackFile)
    .function("isScale9Enabled", &Slider::isScale9Enabled)
    .function("getBallDisabledFile", &Slider::getBallDisabledFile)
    .function("setCapInsetsBarRenderer", &Slider::setCapInsetsBarRenderer)
    .function("getPercent", &Slider::getPercent)
    .function("setCapInsets", &Slider::setCapInsets)
    .function("getSlidBallNormalRenderer", &Slider::getSlidBallNormalRenderer, allow_raw_pointers())
    .function("setZoomScale", &Slider::setZoomScale)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::Slider*(const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&Slider::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::Slider*()>(&Slider::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Slider& _) -> std::string {return "Slider";}))    
    .allow_subclass<emscripten::wrapper<Slider>>("_subclass.ccui.Slider")
    ;


  class_<UICCTextField, base<TextFieldTTF>>("ccui.UICCTextField")
    .constructor<>()
    .function("onTextFieldAttachWithIME", &UICCTextField::onTextFieldAttachWithIME, allow_raw_pointers())
    .function("setPasswordText", &UICCTextField::setPasswordText)
    .function("setAttachWithIME", &UICCTextField::setAttachWithIME)
    .function("getDeleteBackward", &UICCTextField::getDeleteBackward)
    .function("getAttachWithIME", &UICCTextField::getAttachWithIME)
    .function("onTextFieldDeleteBackward", &UICCTextField::onTextFieldDeleteBackward, allow_raw_pointers())
    .function("getInsertText", &UICCTextField::getInsertText)
    .function("setInsertText", &UICCTextField::setInsertText)
    .function("getDetachWithIME", &UICCTextField::getDetachWithIME)
    .function("getCharCount", &UICCTextField::getCharCount)
    .function("closeIME", &UICCTextField::closeIME)
    .function("setPasswordEnabled", &UICCTextField::setPasswordEnabled)
    .function("setMaxLengthEnabled", &UICCTextField::setMaxLengthEnabled)
    .function("isPasswordEnabled", &UICCTextField::isPasswordEnabled)
    .function("insertText", &UICCTextField::insertText, allow_raw_pointers())
    .function("setPasswordStyleText", &UICCTextField::setPasswordStyleText)
    .function("onTextFieldInsertText", &UICCTextField::onTextFieldInsertText, allow_raw_pointers())
    .function("onTextFieldDetachWithIME", &UICCTextField::onTextFieldDetachWithIME, allow_raw_pointers())
    .function("getMaxLength", &UICCTextField::getMaxLength)
    .function("isMaxLengthEnabled", &UICCTextField::isMaxLengthEnabled)
    .function("openIME", &UICCTextField::openIME)
    .function("setDetachWithIME", &UICCTextField::setDetachWithIME)
    .function("setMaxLength", &UICCTextField::setMaxLength)
    .function("setDeleteBackward", &UICCTextField::setDeleteBackward)
    .class_function("create", select_overload<cocos2d::ui::UICCTextField*(const std::string&, const std::string&, float)>(&UICCTextField::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::UICCTextField*()>(&UICCTextField::create), allow_raw_pointers())
    .property("_className",  optional_override([](const UICCTextField& _) -> std::string {return "UICCTextField";}))    
    ;


  class_<TextField, base<Widget>>("ccui.TextField")
    .constructor<>()
    .function("setAttachWithIME", &TextField::setAttachWithIME)
    .function("getFontSize", &TextField::getFontSize)
    .function("getString", &TextField::getString)
    .function("setPasswordStyleText", &TextField::setPasswordStyleText, allow_raw_pointers())
    .function("getDeleteBackward", &TextField::getDeleteBackward)
    .function("getTextColor", &TextField::getTextColor)
    .function("getPlaceHolder", &TextField::getPlaceHolder)
    .function("getAttachWithIME", &TextField::getAttachWithIME)
    .function("setFontName", &TextField::setFontName)
    .function("getInsertText", &TextField::getInsertText)
    .function("setInsertText", &TextField::setInsertText)
    .function("setString", &TextField::setString)
    .function("getDetachWithIME", &TextField::getDetachWithIME)
    .function("setTextVerticalAlignment", &TextField::setTextVerticalAlignment)
    .function("addEventListener", &TextField::addEventListener)
    .function("didNotSelectSelf", &TextField::didNotSelectSelf)
    .function("getFontName", &TextField::getFontName)
    .function("setTextAreaSize", &TextField::setTextAreaSize)
    .function("attachWithIME", &TextField::attachWithIME)
    .function("getStringLength", &TextField::getStringLength)
    .function("getAutoRenderSize", &TextField::getAutoRenderSize)
    .function("setPasswordEnabled", &TextField::setPasswordEnabled)
    .function("getPlaceHolderColor", &TextField::getPlaceHolderColor)
    .function("getPasswordStyleText", &TextField::getPasswordStyleText, allow_raw_pointers())
    .function("setMaxLengthEnabled", &TextField::setMaxLengthEnabled)
    .function("isPasswordEnabled", &TextField::isPasswordEnabled)
    .function("setDeleteBackward", &TextField::setDeleteBackward)
    .function("setCursorPosition", &TextField::setCursorPosition)
    .function("getTextHorizontalAlignment", &TextField::getTextHorizontalAlignment)
    .function("setFontSize", &TextField::setFontSize)
    .function("setPlaceHolder", &TextField::setPlaceHolder)
    .function("setCursorFromPoint", &TextField::setCursorFromPoint, allow_raw_pointers())
    .function("setPlaceHolderColor", select_overload<void(const cocos2d::Color4B&)>(&TextField::setPlaceHolderColor))
    // TODO: Only support function overloading with different number of parameters
    .function("setTextHorizontalAlignment", &TextField::setTextHorizontalAlignment)
    .function("setTextColor", &TextField::setTextColor)
    .function("setCursorChar", &TextField::setCursorChar)
    .function("getMaxLength", &TextField::getMaxLength)
    .function("isMaxLengthEnabled", &TextField::isMaxLengthEnabled)
    .function("setDetachWithIME", &TextField::setDetachWithIME)
    .function("getTextVerticalAlignment", &TextField::getTextVerticalAlignment)
    .function("setTouchAreaEnabled", &TextField::setTouchAreaEnabled)
    .function("setMaxLength", &TextField::setMaxLength)
    .function("setCursorEnabled", &TextField::setCursorEnabled)
    .function("setTouchSize", &TextField::setTouchSize)
    .function("getTouchSize", &TextField::getTouchSize)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TextField*(const std::string&, const std::string&, int)>(&TextField::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TextField*()>(&TextField::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TextField& _) -> std::string {return "TextField";}))    
    .allow_subclass<emscripten::wrapper<TextField>>("_subclass.ccui.TextField")
    ;


  class_<TextBMFont, base<Widget>>("ccui.TextBMFont")
    .constructor<>()
    .function("getStringLength", &TextBMFont::getStringLength)
    .function("getString", &TextBMFont::getString)
    .function("setString", &TextBMFont::setString)
    .function("getRenderFile", &TextBMFont::getRenderFile)
    .function("setFntFile", &TextBMFont::setFntFile)
    .function("resetRender", &TextBMFont::resetRender)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TextBMFont*(const std::string&, const std::string&)>(&TextBMFont::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TextBMFont*()>(&TextBMFont::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TextBMFont& _) -> std::string {return "TextBMFont";}))    
    .allow_subclass<emscripten::wrapper<TextBMFont>>("_subclass.ccui.TextBMFont")
    ;


  class_<PageView, base<ListView>>("ccui.PageView")
    .constructor<>()
    .function("setIndicatorSpaceBetweenIndexNodes", &PageView::setIndicatorSpaceBetweenIndexNodes)
    .function("insertPage", &PageView::insertPage, allow_raw_pointers())
    .function("setIndicatorIndexNodesOpacity", &PageView::setIndicatorIndexNodesOpacity)
    .function("setIndicatorSelectedIndexOpacity", &PageView::setIndicatorSelectedIndexOpacity)
    .function("removeAllPages", &PageView::removeAllPages)
    .function("setAutoScrollStopEpsilon", &PageView::setAutoScrollStopEpsilon)
    .function("setIndicatorIndexNodesScale", &PageView::setIndicatorIndexNodesScale)
    .function("setIndicatorEnabled", &PageView::setIndicatorEnabled)
    .function("setIndicatorSelectedIndexColor", &PageView::setIndicatorSelectedIndexColor)
    .function("addEventListener", select_overload<void (const PageView::ccPageViewCallback&)>(&PageView::addEventListener))
    .function("getIndicatorPosition", &PageView::getIndicatorPosition)
    .function("setCurrentPageIndex", &PageView::setCurrentPageIndex)
    .function("getIndicatorIndexNodesColor", &PageView::getIndicatorIndexNodesColor)
    .function("getIndicatorSelectedIndexColor", &PageView::getIndicatorSelectedIndexColor)
    .function("getIndicatorIndexNodesScale", &PageView::getIndicatorIndexNodesScale)
    .function("setIndicatorPosition", &PageView::setIndicatorPosition)
    .function("getIndicatorSelectedIndexOpacity", &PageView::getIndicatorSelectedIndexOpacity)
    .function("scrollToPage", select_overload<void(ssize_t, float)>(&PageView::scrollToPage))
    .function("scrollToPage", select_overload<void(ssize_t)>(&PageView::scrollToPage))
    .function("setIndicatorPositionAsAnchorPoint", &PageView::setIndicatorPositionAsAnchorPoint)
    .function("scrollToItem", select_overload<void(ssize_t, float)>(&PageView::scrollToItem))
    .function("scrollToItem", select_overload<void(ssize_t)>(&PageView::scrollToItem))
    .function("setIndicatorIndexNodesColor", &PageView::setIndicatorIndexNodesColor)
    .function("getIndicatorIndexNodesOpacity", &PageView::getIndicatorIndexNodesOpacity)
    .function("getIndicatorPositionAsAnchorPoint", &PageView::getIndicatorPositionAsAnchorPoint)
    .function("getCurrentPageIndex", &PageView::getCurrentPageIndex)
    .function("removePage", &PageView::removePage, allow_raw_pointers())
    .function("setIndicatorIndexNodesTexture", &PageView::setIndicatorIndexNodesTexture)
    .function("setIndicatorIndexNodesTexture", optional_override(
        [](PageView& this_, const std::string& arg0){
        return this_.setIndicatorIndexNodesTexture(arg0);
      }))
    .function("getIndicatorEnabled", &PageView::getIndicatorEnabled)
    .function("removePageAtIndex", &PageView::removePageAtIndex)
    .function("getIndicatorSpaceBetweenIndexNodes", &PageView::getIndicatorSpaceBetweenIndexNodes)
    .function("addPage", &PageView::addPage, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", &PageView::create, allow_raw_pointers())
    .property("_className",  optional_override([](const PageView& _) -> std::string {return "PageView";}))    
    .allow_subclass<emscripten::wrapper<PageView>>("_subclass.ccui.PageView")
    ;

  class_<Helper>("ccui.Helper")
    .class_function("getSubStringOfUTF8String", &Helper::getSubStringOfUTF8String, allow_raw_pointers())
    .class_function("convertBoundingBoxToScreen", &Helper::convertBoundingBoxToScreen, allow_raw_pointers())
    .class_function("changeLayoutSystemActiveState", &Helper::changeLayoutSystemActiveState, allow_raw_pointers())
    .class_function("seekActionWidgetByActionTag", &Helper::seekActionWidgetByActionTag, allow_raw_pointers())
    .class_function("seekWidgetByName", &Helper::seekWidgetByName, allow_raw_pointers())
    .class_function("seekWidgetByTag", &Helper::seekWidgetByTag, allow_raw_pointers())
    .class_function("restrictCapInsetRect", &Helper::restrictCapInsetRect, allow_raw_pointers())
    .class_function("doLayout", &Helper::doLayout, allow_raw_pointers())
    .property("_className",  optional_override([](const Helper& _) -> std::string {return "Helper";}))    
    ;


  class_<RichElement>("ccui.RichElement")
    .constructor<>()
    .function("equalType", &RichElement::equalType)
    .function("init", &RichElement::init)
    .function("setColor", &RichElement::setColor)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .property("_className",  optional_override([](const RichElement& _) -> std::string {return "RichElement";}))    
    .allow_subclass<emscripten::wrapper<RichElement>>("_subclass.ccui.RichElement")
    ;


  class_<RichElementText, base<RichElement>>("ccui.RichElementText")
    .constructor<>()
    .function("init", &RichElementText::init)
    .function("init", optional_override(
        [](RichElementText& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7){
        return this_.init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
      }))
    .function("init", optional_override(
        [](RichElementText& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7, const cocos2d::Color3B& arg8){
        return this_.init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
      }))
    .function("init", optional_override(
        [](RichElementText& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7, const cocos2d::Color3B& arg8, int arg9){
        return this_.init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
      }))
    .function("init", optional_override(
        [](RichElementText& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7, const cocos2d::Color3B& arg8, int arg9, const cocos2d::Color3B& arg10){
        return this_.init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
      }))
    .function("init", optional_override(
        [](RichElementText& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7, const cocos2d::Color3B& arg8, int arg9, const cocos2d::Color3B& arg10, const cocos2d::Size& arg11){
        return this_.init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
      }))
    .function("init", optional_override(
        [](RichElementText& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7, const cocos2d::Color3B& arg8, int arg9, const cocos2d::Color3B& arg10, const cocos2d::Size& arg11, int arg12){
        return this_.init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
      }))
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", &RichElementText::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5){
        return RichElementText::create(arg0, arg1, arg2, arg3, arg4, arg5);
      }), allow_raw_pointers())
    .class_function("create", optional_override(
      [](int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6){
        return RichElementText::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
      }), allow_raw_pointers())
    .class_function("create", optional_override(
      [](int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7){
        return RichElementText::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
      }), allow_raw_pointers())
    .class_function("create", optional_override(
      [](int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7, const cocos2d::Color3B& arg8){
        return RichElementText::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
      }), allow_raw_pointers())
    .class_function("create", optional_override(
      [](int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7, const cocos2d::Color3B& arg8, int arg9){
        return RichElementText::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
      }), allow_raw_pointers())
    .class_function("create", optional_override(
      [](int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7, const cocos2d::Color3B& arg8, int arg9, const cocos2d::Color3B& arg10){
        return RichElementText::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
      }), allow_raw_pointers())
    .class_function("create", optional_override(
      [](int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7, const cocos2d::Color3B& arg8, int arg9, const cocos2d::Color3B& arg10, const cocos2d::Size& arg11){
        return RichElementText::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
      }), allow_raw_pointers())
    .class_function("create", optional_override(
      [](int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7, const cocos2d::Color3B& arg8, int arg9, const cocos2d::Color3B& arg10, const cocos2d::Size& arg11, int arg12){
        return RichElementText::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const RichElementText& _) -> std::string {return "RichElementText";}))    
    .allow_subclass<emscripten::wrapper<RichElementText>>("_subclass.ccui.RichElementText")
    ;


  class_<RichElementImage, base<RichElement>>("ccui.RichElementImage")
    .constructor<>()
    .function("setHeight", &RichElementImage::setHeight)
    .function("init", &RichElementImage::init)
    .function("init", optional_override(
        [](RichElementImage& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3){
        return this_.init(arg0, arg1, arg2, arg3);
      }))
    .function("init", optional_override(
        [](RichElementImage& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4){
        return this_.init(arg0, arg1, arg2, arg3, arg4);
      }))
    .function("setWidth", &RichElementImage::setWidth)
    .function("setUrl", &RichElementImage::setUrl)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", &RichElementImage::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3){
        return RichElementImage::create(arg0, arg1, arg2, arg3);
      }), allow_raw_pointers())
    .class_function("create", optional_override(
      [](int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4){
        return RichElementImage::create(arg0, arg1, arg2, arg3, arg4);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const RichElementImage& _) -> std::string {return "RichElementImage";}))    
    .allow_subclass<emscripten::wrapper<RichElementImage>>("_subclass.ccui.RichElementImage")
    ;


  class_<RichElementCustomNode, base<RichElement>>("ccui.RichElementCustomNode")
    .constructor<>()
    .function("init", &RichElementCustomNode::init, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", &RichElementCustomNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RichElementCustomNode& _) -> std::string {return "RichElementCustomNode";}))    
    .allow_subclass<emscripten::wrapper<RichElementCustomNode>>("_subclass.ccui.RichElementCustomNode")
    ;


  class_<RichElementNewLine, base<RichElement>>("ccui.RichElementNewLine")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", &RichElementNewLine::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RichElementNewLine& _) -> std::string {return "RichElementNewLine";}))    
    .allow_subclass<emscripten::wrapper<RichElementNewLine>>("_subclass.ccui.RichElementNewLine")
    ;


  class_<RichText, base<Widget>>("ccui.RichText")
    .constructor<>()
    .function("insertElement", &RichText::insertElement, allow_raw_pointers())
    .function("setAnchorTextOutline", &RichText::setAnchorTextOutline)
    .function("setAnchorTextOutline", optional_override(
        [](RichText& this_, bool arg0){
        return this_.setAnchorTextOutline(arg0);
      }))
    .function("setAnchorTextOutline", optional_override(
        [](RichText& this_, bool arg0, const cocos2d::Color3B& arg1){
        return this_.setAnchorTextOutline(arg0, arg1);
      }))
    .function("getFontSize", &RichText::getFontSize)
    .function("pushBackElement", &RichText::pushBackElement, allow_raw_pointers())
    .function("setAnchorTextBold", &RichText::setAnchorTextBold)
    .function("getAnchorFontColor", &RichText::getAnchorFontColor)
    .function("getAnchorTextShadowBlurRadius", &RichText::getAnchorTextShadowBlurRadius)
    .function("setAnchorTextShadow", &RichText::setAnchorTextShadow)
    .function("setAnchorTextShadow", optional_override(
        [](RichText& this_, bool arg0){
        return this_.setAnchorTextShadow(arg0);
      }))
    .function("setAnchorTextShadow", optional_override(
        [](RichText& this_, bool arg0, const cocos2d::Color3B& arg1){
        return this_.setAnchorTextShadow(arg0, arg1);
      }))
    .function("setAnchorTextShadow", optional_override(
        [](RichText& this_, bool arg0, const cocos2d::Color3B& arg1, const cocos2d::Size& arg2){
        return this_.setAnchorTextShadow(arg0, arg1, arg2);
      }))
    .function("isAnchorTextItalicEnabled", &RichText::isAnchorTextItalicEnabled)
    .function("setAnchorFontColor", &RichText::setAnchorFontColor)
    .function("setFontFace", &RichText::setFontFace)
    .function("setAnchorTextGlow", &RichText::setAnchorTextGlow)
    .function("setAnchorTextGlow", optional_override(
        [](RichText& this_, bool arg0){
        return this_.setAnchorTextGlow(arg0);
      }))
    .function("getHorizontalAlignment", &RichText::getHorizontalAlignment)
    .function("setHorizontalAlignment", &RichText::setHorizontalAlignment)
    .function("setAnchorTextDel", &RichText::setAnchorTextDel)
    .function("getAnchorTextOutlineColor3B", &RichText::getAnchorTextOutlineColor3B)
    .function("stringWithColor4B", &RichText::stringWithColor4B)
    .function("initWithXML", &RichText::initWithXML)
    .function("initWithXML", optional_override(
        [](RichText& this_, const std::string& arg0, const std::unordered_map<std::string, cocos2d::Value>& arg1){
        return this_.initWithXML(arg0, arg1);
      }))
    .function("getAnchorFontColor3B", &RichText::getAnchorFontColor3B)
    .function("formatText", &RichText::formatText)
    .function("getAnchorTextGlowColor3B", &RichText::getAnchorTextGlowColor3B)
    .function("openUrl", &RichText::openUrl)
    .function("getFontFace", &RichText::getFontFace)
    .function("setFontColor", &RichText::setFontColor)
    .function("isAnchorTextGlowEnabled", &RichText::isAnchorTextGlowEnabled)
    .function("getDefaults", &RichText::getDefaults)
    .function("isAnchorTextUnderlineEnabled", &RichText::isAnchorTextUnderlineEnabled)
    .function("getFontColor", &RichText::getFontColor)
    .function("isAnchorTextShadowEnabled", &RichText::isAnchorTextShadowEnabled)
    .function("getAnchorTextOutlineSize", &RichText::getAnchorTextOutlineSize)
    .function("setVerticalSpace", &RichText::setVerticalSpace)
    .function("isAnchorTextDelEnabled", &RichText::isAnchorTextDelEnabled)
    .function("setDefaults", &RichText::setDefaults)
    .function("setWrapMode", &RichText::setWrapMode)
    .function("setFontSize", &RichText::setFontSize)
    .function("removeElement", select_overload<void(cocos2d::ui::RichElement*)>(&RichText::removeElement), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setAnchorTextItalic", &RichText::setAnchorTextItalic)
    .function("getAnchorTextShadowOffset", &RichText::getAnchorTextShadowOffset)
    .function("isAnchorTextBoldEnabled", &RichText::isAnchorTextBoldEnabled)
    .function("getAnchorTextShadowColor3B", &RichText::getAnchorTextShadowColor3B)
    .function("stringWithColor3B", &RichText::stringWithColor3B)
    .function("isAnchorTextOutlineEnabled", &RichText::isAnchorTextOutlineEnabled)
    .function("getFontColor3B", &RichText::getFontColor3B)
    .function("getWrapMode", &RichText::getWrapMode)
    .function("setAnchorTextUnderline", &RichText::setAnchorTextUnderline)
    .function("color3BWithString", &RichText::color3BWithString)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", &RichText::create, allow_raw_pointers())
    .class_function("createWithXML", &RichText::createWithXML, allow_raw_pointers())
    .class_function("createWithXML", optional_override(
      [](const std::string& arg0, const std::unordered_map<std::string, cocos2d::Value>& arg1){
        return RichText::createWithXML(arg0, arg1);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const RichText& _) -> std::string {return "RichText";}))    
    .allow_subclass<emscripten::wrapper<RichText>>("_subclass.ccui.RichText")
    ;


  class_<HBox, base<Layout>>("ccui.HBox")
    .constructor<>()
    .function("initWithSize", &HBox::initWithSize)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::HBox*(const cocos2d::Size&)>(&HBox::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::HBox*()>(&HBox::create), allow_raw_pointers())
    .property("_className",  optional_override([](const HBox& _) -> std::string {return "HBox";}))    
    .allow_subclass<emscripten::wrapper<HBox>>("_subclass.ccui.HBox")
    ;


  class_<VBox, base<Layout>>("ccui.VBox")
    .constructor<>()
    .function("initWithSize", &VBox::initWithSize)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::VBox*(const cocos2d::Size&)>(&VBox::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::VBox*()>(&VBox::create), allow_raw_pointers())
    .property("_className",  optional_override([](const VBox& _) -> std::string {return "VBox";}))    
    .allow_subclass<emscripten::wrapper<VBox>>("_subclass.ccui.VBox")
    ;


  class_<RelativeBox, base<Layout>>("ccui.RelativeBox")
    .constructor<>()
    .function("initWithSize", &RelativeBox::initWithSize)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::RelativeBox*(const cocos2d::Size&)>(&RelativeBox::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::RelativeBox*()>(&RelativeBox::create), allow_raw_pointers())
    .property("_className",  optional_override([](const RelativeBox& _) -> std::string {return "RelativeBox";}))    
    .allow_subclass<emscripten::wrapper<RelativeBox>>("_subclass.ccui.RelativeBox")
    ;


  class_<Scale9Sprite, base<Sprite>>("ccui.Scale9Sprite")
    .constructor<>()
    .function("updateWithSprite", select_overload<bool(cocos2d::Sprite*, const cocos2d::Rect&, bool, const cocos2d::Vec2&, const cocos2d::Size&, const cocos2d::Rect&)>(&Scale9Sprite::updateWithSprite), allow_raw_pointers())
    .function("updateWithSprite", select_overload<bool(cocos2d::Sprite*, const cocos2d::Rect&, bool, const cocos2d::Rect&)>(&Scale9Sprite::updateWithSprite), allow_raw_pointers())
    .function("resizableSpriteWithCapInsets", &Scale9Sprite::resizableSpriteWithCapInsets, allow_raw_pointers())
    .function("getCapInsets", &Scale9Sprite::getCapInsets)
    .function("setState", &Scale9Sprite::setState)
    .function("setInsetBottom", &Scale9Sprite::setInsetBottom)
    .function("getSprite", &Scale9Sprite::getSprite, allow_raw_pointers())
    .function("setInsetTop", &Scale9Sprite::setInsetTop)
    .function("setRenderingType", &Scale9Sprite::setRenderingType)
    .function("init", select_overload<bool(cocos2d::Sprite*, const cocos2d::Rect&, const cocos2d::Rect&)>(&Scale9Sprite::init), allow_raw_pointers())
    .function("init", select_overload<bool(cocos2d::Sprite*, const cocos2d::Rect&, bool, const cocos2d::Rect&)>(&Scale9Sprite::init), allow_raw_pointers())
    .function("init", select_overload<bool(cocos2d::Sprite*, const cocos2d::Rect&, bool, const cocos2d::Vec2&, const cocos2d::Size&, const cocos2d::Rect&)>(&Scale9Sprite::init), allow_raw_pointers())
    .function("setPreferredSize", &Scale9Sprite::setPreferredSize)
    .function("copyTo", &Scale9Sprite::copyTo, allow_raw_pointers())
    .function("setSpriteFrame", select_overload<void (SpriteFrame *, const Rect&)>(&Scale9Sprite::setSpriteFrame), allow_raw_pointers())
    .function("getState", &Scale9Sprite::getState)
    .function("getInsetBottom", &Scale9Sprite::getInsetBottom)
    .function("setScale9Enabled", &Scale9Sprite::setScale9Enabled)
    .function("isScale9Enabled", &Scale9Sprite::isScale9Enabled)
    .function("resetRender", &Scale9Sprite::resetRender)
    .function("getRenderingType", &Scale9Sprite::getRenderingType)
    .function("getInsetRight", &Scale9Sprite::getInsetRight)
    .function("getOriginalSize", &Scale9Sprite::getOriginalSize)
    .function("initWithFile", select_overload<bool(const cocos2d::Rect&, const std::string&)>(&Scale9Sprite::initWithFile))
    .function("initWithFile", select_overload<bool(const std::string&, const cocos2d::Rect&, const cocos2d::Rect&)>(&Scale9Sprite::initWithFile))
    .function("getInsetTop", &Scale9Sprite::getInsetTop)
    .function("setInsetLeft", &Scale9Sprite::setInsetLeft)
    .function("initWithSpriteFrame", select_overload<bool (SpriteFrame*, const Rect&)>(&Scale9Sprite::initWithSpriteFrame), allow_raw_pointers())
    .function("getPreferredSize", &Scale9Sprite::getPreferredSize)
    .function("setCapInsets", &Scale9Sprite::setCapInsets)
    .function("getInsetLeft", &Scale9Sprite::getInsetLeft)
    .function("setInsetRight", &Scale9Sprite::setInsetRight)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::Scale9Sprite*(const std::string&, const cocos2d::Rect&, const cocos2d::Rect&)>(&Scale9Sprite::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::Scale9Sprite*()>(&Scale9Sprite::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::Scale9Sprite*(const cocos2d::Rect&, const std::string&)>(&Scale9Sprite::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::Scale9Sprite*(const std::string&)>(&Scale9Sprite::create), allow_raw_pointers())
    .class_function("createWithSpriteFrameName", select_overload<cocos2d::ui::Scale9Sprite*(const std::string&, const cocos2d::Rect&)>(&Scale9Sprite::createWithSpriteFrameName), allow_raw_pointers())
    .class_function("createWithSpriteFrameName", select_overload<cocos2d::ui::Scale9Sprite*(const std::string&)>(&Scale9Sprite::createWithSpriteFrameName), allow_raw_pointers())
    .class_function("createWithSpriteFrame", select_overload<cocos2d::ui::Scale9Sprite*(cocos2d::SpriteFrame*, const cocos2d::Rect&)>(&Scale9Sprite::createWithSpriteFrame), allow_raw_pointers())
    .class_function("createWithSpriteFrame", select_overload<cocos2d::ui::Scale9Sprite*(cocos2d::SpriteFrame*)>(&Scale9Sprite::createWithSpriteFrame), allow_raw_pointers())
    .property("_className",  optional_override([](const Scale9Sprite& _) -> std::string {return "Scale9Sprite";}))    
    .allow_subclass<emscripten::wrapper<Scale9Sprite>>("_subclass.ccui.Scale9Sprite")
    ;


  class_<EditBox, base<Widget>>("ccui.EditBox")
    .constructor<>()
    .function("getFontSize", &EditBox::getFontSize)
    .function("getString", &EditBox::getText, allow_raw_pointers())
    .function("setMaxLength", &EditBox::setMaxLength)
    .function("openKeyboard", &EditBox::openKeyboard)
    .function("setFontSize", &EditBox::setFontSize)
    .function("getInputMode", &EditBox::getInputMode)
    .function("initWithSizeAndBackgroundSprite", select_overload<bool(const cocos2d::Size&, cocos2d::ui::Scale9Sprite*)>(&EditBox::initWithSizeAndBackgroundSprite), allow_raw_pointers())
    .function("initWithSizeAndBackgroundSprite", select_overload<bool(const cocos2d::Size&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&EditBox::initWithSizeAndBackgroundSprite))
    // TODO: Only support function overloading with different number of parameters
    .function("initWithSizeAndBackgroundSprite", select_overload<bool(const cocos2d::Size&, cocos2d::ui::Scale9Sprite*, cocos2d::ui::Scale9Sprite*, cocos2d::ui::Scale9Sprite*)>(&EditBox::initWithSizeAndBackgroundSprite), allow_raw_pointers())
    .function("getPlaceholderFontName", &EditBox::getPlaceholderFontName, allow_raw_pointers())
    .function("setPlaceholderFontName", &EditBox::setPlaceholderFontName, allow_raw_pointers())
    .function("getPlaceholderFontSize", &EditBox::getPlaceholderFontSize)
    .function("getCapInsetsDisabledRenderer", &EditBox::getCapInsetsDisabledRenderer)
    .function("getPlaceHolder", &EditBox::getPlaceHolder, allow_raw_pointers())
    .function("setFontName", &EditBox::setFontName, allow_raw_pointers())
    .function("setString", &EditBox::setText, allow_raw_pointers())
    .function("setCapInsetsDisabledRenderer", &EditBox::setCapInsetsDisabledRenderer)
    .function("setPlaceholderFontSize", &EditBox::setPlaceholderFontSize)
    .function("setInputMode", &EditBox::setInputMode)
    .function("setPlaceholderFontColor", select_overload<void(const cocos2d::Color4B&)>(&EditBox::setPlaceholderFontColor))
    // TODO: Only support function overloading with different number of parameters
    .function("getReturnType", &EditBox::getReturnType)
    .function("setFontColor", select_overload<void(const cocos2d::Color4B&)>(&EditBox::setFontColor))
    // TODO: Only support function overloading with different number of parameters
    .function("getFontName", &EditBox::getFontName, allow_raw_pointers())
    .function("setCapInsetsNormalRenderer", &EditBox::setCapInsetsNormalRenderer)
    .function("getFontColor", &EditBox::getFontColor)
    .function("getInputFlag", &EditBox::getInputFlag)
    .function("initWithSizeAndTexture", &EditBox::initWithSizeAndTexture)
    .function("initWithSizeAndTexture", optional_override(
        [](EditBox& this_, const cocos2d::Size& arg0, const std::string& arg1){
        return this_.initWithSizeAndTexture(arg0, arg1);
      }))
    .function("initWithSizeAndTexture", optional_override(
        [](EditBox& this_, const cocos2d::Size& arg0, const std::string& arg1, const std::string& arg2){
        return this_.initWithSizeAndTexture(arg0, arg1, arg2);
      }))
    .function("initWithSizeAndTexture", optional_override(
        [](EditBox& this_, const cocos2d::Size& arg0, const std::string& arg1, const std::string& arg2, const std::string& arg3){
        return this_.initWithSizeAndTexture(arg0, arg1, arg2, arg3);
      }))
    .function("getTextHorizontalAlignment", &EditBox::getTextHorizontalAlignment)
    .function("getCapInsetsNormalRenderer", &EditBox::getCapInsetsNormalRenderer)
    .function("getCapInsetsPressedRenderer", &EditBox::getCapInsetsPressedRenderer)
    .function("loadTextures", &EditBox::loadTextures)
    .function("loadTextures", optional_override(
        [](EditBox& this_, const std::string& arg0, const std::string& arg1){
        return this_.loadTextures(arg0, arg1);
      }))
    .function("loadTextures", optional_override(
        [](EditBox& this_, const std::string& arg0, const std::string& arg1, const std::string& arg2){
        return this_.loadTextures(arg0, arg1, arg2);
      }))
    .function("setPlaceHolder", &EditBox::setPlaceHolder, allow_raw_pointers())
    .function("setInputFlag", &EditBox::setInputFlag)
    .function("setReturnType", &EditBox::setReturnType)
    .function("getMaxLength", &EditBox::getMaxLength)
    .function("setCapInsetsPressedRenderer", &EditBox::setCapInsetsPressedRenderer)
    .function("setPlaceholderFont", &EditBox::setPlaceholderFont, allow_raw_pointers())
    .function("getPlaceholderFontColor", &EditBox::getPlaceholderFontColor)
    .function("setCapInsets", &EditBox::setCapInsets)
    .function("setFont", &EditBox::setFont, allow_raw_pointers())
    .function("setTextHorizontalAlignment", &EditBox::setTextHorizontalAlignment)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::EditBox*(const cocos2d::Size&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&EditBox::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::EditBox*(const cocos2d::Size&, cocos2d::ui::Scale9Sprite*, cocos2d::ui::Scale9Sprite*, cocos2d::ui::Scale9Sprite*)>(&EditBox::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::EditBox*(const cocos2d::Size&, const std::string&, const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&EditBox::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const EditBox& _) -> std::string {return "EditBox";}))    
    .allow_subclass<emscripten::wrapper<EditBox>>("_subclass.ccui.EditBox")
    ;


  class_<LayoutComponent, base<Component>>("ccui.LayoutComponent")
    .constructor<>()
    .function("setStretchWidthEnabled", &LayoutComponent::setStretchWidthEnabled)
    .function("setPercentWidth", &LayoutComponent::setPercentWidth)
    .function("getAnchorPosition", &LayoutComponent::getAnchorPosition)
    .function("setPositionPercentXEnabled", &LayoutComponent::setPositionPercentXEnabled)
    .function("setStretchHeightEnabled", &LayoutComponent::setStretchHeightEnabled)
    .function("setActiveEnabled", &LayoutComponent::setActiveEnabled)
    .function("getRightMargin", &LayoutComponent::getRightMargin)
    .function("getSize", &LayoutComponent::getSize)
    .function("setAnchorPosition", &LayoutComponent::setAnchorPosition)
    .function("refreshLayout", &LayoutComponent::refreshLayout)
    .function("isPercentWidthEnabled", &LayoutComponent::isPercentWidthEnabled)
    .function("setVerticalEdge", &LayoutComponent::setVerticalEdge)
    .function("getTopMargin", &LayoutComponent::getTopMargin)
    .function("setSizeWidth", &LayoutComponent::setSizeWidth)
    .function("getPercentContentSize", &LayoutComponent::getPercentContentSize)
    .function("getVerticalEdge", &LayoutComponent::getVerticalEdge)
    .function("setPercentWidthEnabled", &LayoutComponent::setPercentWidthEnabled)
    .function("isStretchWidthEnabled", &LayoutComponent::isStretchWidthEnabled)
    .function("setLeftMargin", &LayoutComponent::setLeftMargin)
    .function("getSizeWidth", &LayoutComponent::getSizeWidth)
    .function("setPositionPercentYEnabled", &LayoutComponent::setPositionPercentYEnabled)
    .function("getSizeHeight", &LayoutComponent::getSizeHeight)
    .function("getPositionPercentY", &LayoutComponent::getPositionPercentY)
    .function("getPositionPercentX", &LayoutComponent::getPositionPercentX)
    .function("setTopMargin", &LayoutComponent::setTopMargin)
    .function("getPercentHeight", &LayoutComponent::getPercentHeight)
    .function("getUsingPercentContentSize", &LayoutComponent::getUsingPercentContentSize)
    .function("setPositionPercentY", &LayoutComponent::setPositionPercentY)
    .function("setPositionPercentX", &LayoutComponent::setPositionPercentX)
    .function("setRightMargin", &LayoutComponent::setRightMargin)
    .function("isPositionPercentYEnabled", &LayoutComponent::isPositionPercentYEnabled)
    .function("setPercentHeight", &LayoutComponent::setPercentHeight)
    .function("setPercentOnlyEnabled", &LayoutComponent::setPercentOnlyEnabled)
    .function("setHorizontalEdge", &LayoutComponent::setHorizontalEdge)
    .function("setPosition", &LayoutComponent::setPosition)
    .function("setUsingPercentContentSize", &LayoutComponent::setUsingPercentContentSize)
    .function("getLeftMargin", &LayoutComponent::getLeftMargin)
    .function("getPosition", &LayoutComponent::getPosition)
    .function("setSizeHeight", &LayoutComponent::setSizeHeight)
    .function("isPositionPercentXEnabled", &LayoutComponent::isPositionPercentXEnabled)
    .function("getBottomMargin", &LayoutComponent::getBottomMargin)
    .function("setPercentHeightEnabled", &LayoutComponent::setPercentHeightEnabled)
    .function("setPercentContentSize", &LayoutComponent::setPercentContentSize)
    .function("isPercentHeightEnabled", &LayoutComponent::isPercentHeightEnabled)
    .function("getPercentWidth", &LayoutComponent::getPercentWidth)
    .function("getHorizontalEdge", &LayoutComponent::getHorizontalEdge)
    .function("isStretchHeightEnabled", &LayoutComponent::isStretchHeightEnabled)
    .function("setBottomMargin", &LayoutComponent::setBottomMargin)
    .function("setSize", &LayoutComponent::setSize)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", &LayoutComponent::create, allow_raw_pointers())
    .class_function("bindLayoutComponent", &LayoutComponent::bindLayoutComponent, allow_raw_pointers())
    .property("_className",  optional_override([](const LayoutComponent& _) -> std::string {return "LayoutComponent";}))    
    .allow_subclass<emscripten::wrapper<LayoutComponent>>("_subclass.ccui.LayoutComponent")
    ;


  class_<TabHeader, base<AbstractCheckButton>>("ccui.TabHeader")
    .constructor<>()
    .function("getIndexInTabControl", &TabHeader::getIndexInTabControl)
    .function("getTitleText", &TabHeader::getTitleText)
    .function("setTitleFontSize", &TabHeader::setTitleFontSize)
    .function("setTitleFontName", &TabHeader::setTitleFontName)
    .function("getTitleFontSize", &TabHeader::getTitleFontSize)
    .function("getTitleFontName", &TabHeader::getTitleFontName)
    .function("getTitleColor", &TabHeader::getTitleColor)
    .function("getTitleRenderer", &TabHeader::getTitleRenderer, allow_raw_pointers())
    .function("setTitleText", &TabHeader::setTitleText)
    .function("setTitleColor", &TabHeader::setTitleColor)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TabHeader*(const std::string&, const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&TabHeader::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::TabHeader*()>(&TabHeader::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TabHeader*(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&TabHeader::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const TabHeader& _) -> std::string {return "TabHeader";}))    
    .allow_subclass<emscripten::wrapper<TabHeader>>("_subclass.ccui.TabHeader")
    ;


  class_<TabControl, base<Widget>>("ccui.TabControl")
    .constructor<>()
    .function("setHeaderWidth", &TabControl::setHeaderWidth)
    .function("removeTab", &TabControl::removeTab)
    .function("getTabCount", &TabControl::getTabCount)
    .function("getHeaderDockPlace", &TabControl::getHeaderDockPlace)
    .function("getSelectedTabIndex", &TabControl::getSelectedTabIndex)
    .function("insertTab", &TabControl::insertTab, allow_raw_pointers())
    .function("ignoreHeadersTextureSize", &TabControl::ignoreHeadersTextureSize)
    .function("getHeaderWidth", &TabControl::getHeaderWidth)
    .function("setHeaderDockPlace", &TabControl::setHeaderDockPlace)
    .function("setSelectTab", select_overload<void(cocos2d::ui::TabHeader*)>(&TabControl::setSelectTab), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getTabHeader", &TabControl::getTabHeader, allow_raw_pointers())
    .function("isIgnoreHeadersTextureSize", &TabControl::isIgnoreHeadersTextureSize)
    .function("setTabChangedEventListener", &TabControl::setTabChangedEventListener)
    .function("setHeaderSelectedZoom", &TabControl::setHeaderSelectedZoom)
    .function("setHeaderHeight", &TabControl::setHeaderHeight)
    .function("indexOfTabHeader", &TabControl::indexOfTabHeader, allow_raw_pointers())
    .function("getTabContainer", &TabControl::getTabContainer, allow_raw_pointers())
    .function("getHeaderSelectedZoom", &TabControl::getHeaderSelectedZoom)
    .function("getHeaderHeight", &TabControl::getHeaderHeight)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", &TabControl::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TabControl& _) -> std::string {return "TabControl";}))    
    .allow_subclass<emscripten::wrapper<TabControl>>("_subclass.ccui.TabControl")
    ;


  class_<ScrollViewBar, base<ProtectedNode>>("ccui.ScrollViewBar")
    .constructor<cocos2d::ui::ScrollView*, cocos2d::ui::ScrollView::Direction>()
    .function("setAutoHideEnabled", &ScrollViewBar::setAutoHideEnabled)
    .function("onScrolled", &ScrollViewBar::onScrolled)
    .function("isAutoHideEnabled", &ScrollViewBar::isAutoHideEnabled)
    .function("setAutoHideTime", &ScrollViewBar::setAutoHideTime)
    .function("getWidth", &ScrollViewBar::getWidth)
    .function("getPositionFromCorner", &ScrollViewBar::getPositionFromCorner)
    .function("setPositionFromCorner", &ScrollViewBar::setPositionFromCorner)
    .function("getAutoHideTime", &ScrollViewBar::getAutoHideTime)
    .function("setWidth", &ScrollViewBar::setWidth)
    .function("ctor", &cc_bindings_ctor, allow_raw_pointers())
    .class_function("create", &ScrollViewBar::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ScrollViewBar& _) -> std::string {return "ScrollViewBar";}))    
    // TODO: I dont understand this compile error
    // .allow_subclass<emscripten::wrapper<ScrollViewBar>>("_subclass.ccui.ScrollViewBar")
    ;
}
