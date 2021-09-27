#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_ui.hpp"
#include "ui/CocosGUI.h"
#include "ui/UIScrollViewBar.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(ccbind_cocos2dx_ui) {


  class_<LayoutParameter>("ccui.LayoutParameter")
    .constructor<>()
    .function("clone", &LayoutParameter::clone, allow_raw_pointers())
    .function("getLayoutType", &LayoutParameter::getLayoutType, allow_raw_pointers())
    .function("createCloneInstance", &LayoutParameter::createCloneInstance, allow_raw_pointers())
    .function("copyProperties", &LayoutParameter::copyProperties, allow_raw_pointers())
    .class_function("create", &LayoutParameter::create, allow_raw_pointers())
    .property("_className",  optional_override([](const LayoutParameter& _) -> std::string {return "LayoutParameter";}))    
    ;


  class_<LinearLayoutParameter, base<LayoutParameter>>("ccui.LinearLayoutParameter")
    .constructor<>()
    .function("setGravity", &LinearLayoutParameter::setGravity, allow_raw_pointers())
    .function("getGravity", &LinearLayoutParameter::getGravity, allow_raw_pointers())
    .class_function("create", &LinearLayoutParameter::create, allow_raw_pointers())
    .property("_className",  optional_override([](const LinearLayoutParameter& _) -> std::string {return "LinearLayoutParameter";}))    
    ;


  class_<RelativeLayoutParameter, base<LayoutParameter>>("ccui.RelativeLayoutParameter")
    .constructor<>()
    .function("setAlign", &RelativeLayoutParameter::setAlign, allow_raw_pointers())
    .function("setRelativeToWidgetName", &RelativeLayoutParameter::setRelativeToWidgetName, allow_raw_pointers())
    .function("getRelativeName", &RelativeLayoutParameter::getRelativeName, allow_raw_pointers())
    .function("getRelativeToWidgetName", &RelativeLayoutParameter::getRelativeToWidgetName, allow_raw_pointers())
    .function("setRelativeName", &RelativeLayoutParameter::setRelativeName, allow_raw_pointers())
    .function("getAlign", &RelativeLayoutParameter::getAlign, allow_raw_pointers())
    .class_function("create", &RelativeLayoutParameter::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RelativeLayoutParameter& _) -> std::string {return "RelativeLayoutParameter";}))    
    ;


  class_<Widget, base<ProtectedNode>>("ccui.Widget")
    .constructor<>()
    .function("getVirtualRenderer", &Widget::getVirtualRenderer, allow_raw_pointers())
    .function("getCustomSize", &Widget::getCustomSize, allow_raw_pointers())
    .function("setActionTag", &Widget::setActionTag, allow_raw_pointers())
    .function("setSwallowTouches", &Widget::setSwallowTouches, allow_raw_pointers())
    .function("getPositionType", &Widget::getPositionType, allow_raw_pointers())
    .function("isEnabled", &Widget::isEnabled, allow_raw_pointers())
    .function("findNextFocusedWidget", &Widget::findNextFocusedWidget, allow_raw_pointers())
    .function("setLayoutComponentEnabled", &Widget::setLayoutComponentEnabled, allow_raw_pointers())
    .function("setFocused", &Widget::setFocused, allow_raw_pointers())
    .function("isBright", &Widget::isBright, allow_raw_pointers())
    .function("updateSizeAndPosition", select_overload<void(const cocos2d::Size&)>(&Widget::updateSizeAndPosition), allow_raw_pointers())
    .function("updateSizeAndPosition", select_overload<void()>(&Widget::updateSizeAndPosition), allow_raw_pointers())
    .function("getSizeType", &Widget::getSizeType, allow_raw_pointers())
    .function("getCallbackType", &Widget::getCallbackType, allow_raw_pointers())
    .function("getPositionPercent", &Widget::getPositionPercent, allow_raw_pointers())
    .function("addClickEventListener", &Widget::addClickEventListener, allow_raw_pointers())
    .function("isFlippedX", &Widget::isFlippedX, allow_raw_pointers())
    .function("isFlippedY", &Widget::isFlippedY, allow_raw_pointers())
    .function("isClippingParentContainsPoint", &Widget::isClippingParentContainsPoint, allow_raw_pointers())
    .function("onFocusChange", &Widget::onFocusChange, allow_raw_pointers())
    .function("getSizePercent", &Widget::getSizePercent, allow_raw_pointers())
    .function("getTouchEndPosition", &Widget::getTouchEndPosition, allow_raw_pointers())
    .function("getLayoutSize", &Widget::getLayoutSize, allow_raw_pointers())
    .function("setPositionType", &Widget::setPositionType, allow_raw_pointers())
    .function("isHighlighted", &Widget::isHighlighted, allow_raw_pointers())
    .function("setCallbackName", &Widget::setCallbackName, allow_raw_pointers())
    .function("isTouchEnabled", &Widget::isTouchEnabled, allow_raw_pointers())
    .function("setTouchEnabled", &Widget::setTouchEnabled, allow_raw_pointers())
    .function("getRightBoundary", &Widget::getRightBoundary, allow_raw_pointers())
    .function("setLayoutParameter", &Widget::setLayoutParameter, allow_raw_pointers())
    .function("setFocusEnabled", &Widget::setFocusEnabled, allow_raw_pointers())
    .function("getTouchMovePosition", &Widget::getTouchMovePosition, allow_raw_pointers())
    .function("interceptTouchEvent", &Widget::interceptTouchEvent, allow_raw_pointers())
    .function("addTouchEventListener", select_overload<void(const std::function<void (cocos2d::Ref *, cocos2d::ui::Widget::TouchEventType)>&)>(&Widget::addTouchEventListener), allow_raw_pointers())
    .function("isFocused", &Widget::isFocused, allow_raw_pointers())
    .function("setPropagateTouchEvents", &Widget::setPropagateTouchEvents, allow_raw_pointers())
    .function("isUnifySizeEnabled", &Widget::isUnifySizeEnabled, allow_raw_pointers())
    .function("setPositionPercent", &Widget::setPositionPercent, allow_raw_pointers())
    .function("setHighlighted", &Widget::setHighlighted, allow_raw_pointers())
    .function("getVirtualRendererSize", &Widget::getVirtualRendererSize, allow_raw_pointers())
    .function("addCCSEventListener", &Widget::addCCSEventListener, allow_raw_pointers())
    .function("getTopBoundary", &Widget::getTopBoundary, allow_raw_pointers())
    .function("ignoreContentAdaptWithSize", &Widget::ignoreContentAdaptWithSize, allow_raw_pointers())
    .function("getTouchBeganPosition", &Widget::getTouchBeganPosition, allow_raw_pointers())
    .function("setFlippedY", &Widget::setFlippedY, allow_raw_pointers())
    .function("setEnabled", &Widget::setEnabled, allow_raw_pointers())
    .function("setBrightStyle", &Widget::setBrightStyle, allow_raw_pointers())
    .function("requestFocus", &Widget::requestFocus, allow_raw_pointers())
    .function("setUnifySizeEnabled", &Widget::setUnifySizeEnabled, allow_raw_pointers())
    .function("hitTest", &Widget::hitTest, allow_raw_pointers())
    .function("propagateTouchEvent", &Widget::propagateTouchEvent, allow_raw_pointers())
    .function("setCallbackType", &Widget::setCallbackType, allow_raw_pointers())
    .function("setSizePercent", &Widget::setSizePercent, allow_raw_pointers())
    .function("getLeftBoundary", &Widget::getLeftBoundary, allow_raw_pointers())
    .function("setFlippedX", &Widget::setFlippedX, allow_raw_pointers())
    .function("isFocusEnabled", &Widget::isFocusEnabled, allow_raw_pointers())
    .function("isIgnoreContentAdaptWithSize", &Widget::isIgnoreContentAdaptWithSize, allow_raw_pointers())
    .function("isSwallowTouches", &Widget::isSwallowTouches, allow_raw_pointers())
    .function("getActionTag", &Widget::getActionTag, allow_raw_pointers())
    .function("isLayoutComponentEnabled", &Widget::isLayoutComponentEnabled, allow_raw_pointers())
    .function("getWorldPosition", &Widget::getWorldPosition, allow_raw_pointers())
    .function("clone", &Widget::clone, allow_raw_pointers())
    .function("getBottomBoundary", &Widget::getBottomBoundary, allow_raw_pointers())
    .function("dispatchFocusEvent", &Widget::dispatchFocusEvent, allow_raw_pointers())
    .function("isPropagateTouchEvents", &Widget::isPropagateTouchEvents, allow_raw_pointers())
    .function("getCallbackName", &Widget::getCallbackName, allow_raw_pointers())
    .function("setSizeType", &Widget::setSizeType, allow_raw_pointers())
    .function("setBright", &Widget::setBright, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Widget>, allow_raw_pointers())
    .class_function("enableDpadNavigation", &Widget::enableDpadNavigation, allow_raw_pointers())
    .class_function("getCurrentFocusedWidget", &Widget::getCurrentFocusedWidget, allow_raw_pointers())
    .class_function("create", &Widget::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Widget& _) -> std::string {return "Widget";}))    
    // TODO: assign cc.Class.extend to ccui.Widget.extend
    ;


  class_<Layout, base<Widget>>("ccui.Layout")
    .constructor<>()
    .function("setBackGroundColorVector", &Layout::setBackGroundColorVector, allow_raw_pointers())
    .function("setClippingType", &Layout::setClippingType, allow_raw_pointers())
    .function("setBackGroundColorType", &Layout::setBackGroundColorType, allow_raw_pointers())
    .function("setLoopFocus", &Layout::setLoopFocus, allow_raw_pointers())
    .function("setBackGroundImageColor", &Layout::setBackGroundImageColor, allow_raw_pointers())
    .function("getBackGroundColorVector", &Layout::getBackGroundColorVector, allow_raw_pointers())
    .function("getClippingType", &Layout::getClippingType, allow_raw_pointers())
    .function("getRenderFile", &Layout::getRenderFile, allow_raw_pointers())
    .function("isLoopFocus", &Layout::isLoopFocus, allow_raw_pointers())
    .function("removeBackGroundImage", &Layout::removeBackGroundImage, allow_raw_pointers())
    .function("getBackGroundColorOpacity", &Layout::getBackGroundColorOpacity, allow_raw_pointers())
    .function("isClippingEnabled", &Layout::isClippingEnabled, allow_raw_pointers())
    .function("setBackGroundImageOpacity", &Layout::setBackGroundImageOpacity, allow_raw_pointers())
    .function("setBackGroundImage", &Layout::setBackGroundImage, allow_raw_pointers())
    .function("setBackGroundImage", optional_override(
        [](Layout& this_, const std::string& arg0){
        return this_.setBackGroundImage(arg0);
      }), allow_raw_pointers())
    .function("setBackGroundColor", select_overload<void(const cocos2d::Color3B&, const cocos2d::Color3B&)>(&Layout::setBackGroundColor), allow_raw_pointers())
    .function("setBackGroundColor", select_overload<void(const cocos2d::Color3B&)>(&Layout::setBackGroundColor), allow_raw_pointers())
    .function("requestDoLayout", &Layout::requestDoLayout, allow_raw_pointers())
    .function("getBackGroundImageCapInsets", &Layout::getBackGroundImageCapInsets, allow_raw_pointers())
    .function("getBackGroundColor", &Layout::getBackGroundColor, allow_raw_pointers())
    .function("setClippingEnabled", &Layout::setClippingEnabled, allow_raw_pointers())
    .function("getBackGroundImageColor", &Layout::getBackGroundImageColor, allow_raw_pointers())
    .function("isBackGroundImageScale9Enabled", &Layout::isBackGroundImageScale9Enabled, allow_raw_pointers())
    .function("getBackGroundColorType", &Layout::getBackGroundColorType, allow_raw_pointers())
    .function("getBackGroundEndColor", &Layout::getBackGroundEndColor, allow_raw_pointers())
    .function("setBackGroundColorOpacity", &Layout::setBackGroundColorOpacity, allow_raw_pointers())
    .function("getBackGroundImageOpacity", &Layout::getBackGroundImageOpacity, allow_raw_pointers())
    .function("isPassFocusToChild", &Layout::isPassFocusToChild, allow_raw_pointers())
    .function("setBackGroundImageCapInsets", &Layout::setBackGroundImageCapInsets, allow_raw_pointers())
    .function("getBackGroundImageTextureSize", &Layout::getBackGroundImageTextureSize, allow_raw_pointers())
    .function("forceDoLayout", &Layout::forceDoLayout, allow_raw_pointers())
    .function("getLayoutType", &Layout::getLayoutType, allow_raw_pointers())
    .function("setPassFocusToChild", &Layout::setPassFocusToChild, allow_raw_pointers())
    .function("getBackGroundStartColor", &Layout::getBackGroundStartColor, allow_raw_pointers())
    .function("setBackGroundImageScale9Enabled", &Layout::setBackGroundImageScale9Enabled, allow_raw_pointers())
    .function("setLayoutType", &Layout::setLayoutType, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Layout>, allow_raw_pointers())
    .class_function("create", &Layout::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Layout& _) -> std::string {return "Layout";}))    
    // TODO: assign cc.Class.extend to ccui.Layout.extend
    ;


  class_<Button, base<Widget>>("ccui.Button")
    .constructor<>()
    .function("getNormalTextureSize", &Button::getNormalTextureSize, allow_raw_pointers())
    .function("getTitleText", &Button::getTitleText, allow_raw_pointers())
    .function("setTitleLabel", &Button::setTitleLabel, allow_raw_pointers())
    .function("setTitleFontSize", &Button::setTitleFontSize, allow_raw_pointers())
    .function("resetPressedRender", &Button::resetPressedRender, allow_raw_pointers())
    .function("setScale9Enabled", &Button::setScale9Enabled, allow_raw_pointers())
    .function("resetDisabledRender", &Button::resetDisabledRender, allow_raw_pointers())
    .function("getTitleRenderer", &Button::getTitleRenderer, allow_raw_pointers())
    .function("getRendererClicked", &Button::getRendererClicked, allow_raw_pointers())
    .function("getDisabledFile", &Button::getDisabledFile, allow_raw_pointers())
    .function("getZoomScale", &Button::getZoomScale, allow_raw_pointers())
    .function("getCapInsetsDisabledRenderer", &Button::getCapInsetsDisabledRenderer, allow_raw_pointers())
    .function("setTitleColor", &Button::setTitleColor, allow_raw_pointers())
    .function("resetNormalRender", &Button::resetNormalRender, allow_raw_pointers())
    .function("getRendererDisabled", &Button::getRendererDisabled, allow_raw_pointers())
    .function("setCapInsetsDisabledRenderer", &Button::setCapInsetsDisabledRenderer, allow_raw_pointers())
    .function("getTitleColor", &Button::getTitleColor, allow_raw_pointers())
    .function("loadTextureDisabled", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&Button::loadTextureDisabled), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("init", select_overload<bool(const std::string&, const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&Button::init), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .function("setTitleText", &Button::setTitleText, allow_raw_pointers())
    .function("setCapInsetsNormalRenderer", &Button::setCapInsetsNormalRenderer, allow_raw_pointers())
    .function("loadTexturePressed", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&Button::loadTexturePressed), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setTitleFontName", &Button::setTitleFontName, allow_raw_pointers())
    .function("getCapInsetsNormalRenderer", &Button::getCapInsetsNormalRenderer, allow_raw_pointers())
    .function("setTitleAlignment", select_overload<void(cocos2d::TextHAlignment, cocos2d::TextVAlignment)>(&Button::setTitleAlignment), allow_raw_pointers())
    .function("setTitleAlignment", select_overload<void(cocos2d::TextHAlignment)>(&Button::setTitleAlignment), allow_raw_pointers())
    .function("getCapInsetsPressedRenderer", &Button::getCapInsetsPressedRenderer, allow_raw_pointers())
    .function("loadTextures", &Button::loadTextures, allow_raw_pointers())
    .function("loadTextures", optional_override(
        [](Button& this_, const std::string& arg0, const std::string& arg1){
        return this_.loadTextures(arg0, arg1);
      }), allow_raw_pointers())
    .function("loadTextures", optional_override(
        [](Button& this_, const std::string& arg0, const std::string& arg1, const std::string& arg2){
        return this_.loadTextures(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("isScale9Enabled", &Button::isScale9Enabled, allow_raw_pointers())
    .function("loadTextureNormal", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&Button::loadTextureNormal), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getNormalFile", &Button::getNormalFile, allow_raw_pointers())
    .function("setCapInsetsPressedRenderer", &Button::setCapInsetsPressedRenderer, allow_raw_pointers())
    .function("getPressedFile", &Button::getPressedFile, allow_raw_pointers())
    .function("getTitleLabel", &Button::getTitleLabel, allow_raw_pointers())
    .function("getTitleFontSize", &Button::getTitleFontSize, allow_raw_pointers())
    .function("getRendererNormal", &Button::getRendererNormal, allow_raw_pointers())
    .function("getTitleFontName", &Button::getTitleFontName, allow_raw_pointers())
    .function("setCapInsets", &Button::setCapInsets, allow_raw_pointers())
    .function("setPressedActionEnabled", &Button::setPressedActionEnabled, allow_raw_pointers())
    .function("setZoomScale", &Button::setZoomScale, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Button>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::Button*(const std::string&, const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&Button::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::Button*()>(&Button::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Button& _) -> std::string {return "Button";}))    
    // TODO: assign cc.Class.extend to ccui.Button.extend
    ;

  class_<AbstractCheckButton, base<Widget>>("ccui.AbstractCheckButton")
    .function("setSelected", &AbstractCheckButton::setSelected, allow_raw_pointers())
    .function("getRendererBackgroundSelected", &AbstractCheckButton::getRendererBackgroundSelected, allow_raw_pointers())
    .function("getBackDisabledFile", &AbstractCheckButton::getBackDisabledFile, allow_raw_pointers())
    .function("getBackNormalFile", &AbstractCheckButton::getBackNormalFile, allow_raw_pointers())
    .function("getZoomScale", &AbstractCheckButton::getZoomScale, allow_raw_pointers())
    .function("getRendererFrontCross", &AbstractCheckButton::getRendererFrontCross, allow_raw_pointers())
    .function("loadTextureBackGroundDisabled", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&AbstractCheckButton::loadTextureBackGroundDisabled), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("loadTextureFrontCross", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&AbstractCheckButton::loadTextureFrontCross), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("isSelected", &AbstractCheckButton::isSelected, allow_raw_pointers())
    .function("init", select_overload<bool(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&AbstractCheckButton::init), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getCrossDisabledFile", &AbstractCheckButton::getCrossDisabledFile, allow_raw_pointers())
    .function("loadTextureBackGround", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&AbstractCheckButton::loadTextureBackGround), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getRendererBackground", &AbstractCheckButton::getRendererBackground, allow_raw_pointers())
    .function("getCrossNormalFile", &AbstractCheckButton::getCrossNormalFile, allow_raw_pointers())
    .function("loadTextures", &AbstractCheckButton::loadTextures, allow_raw_pointers())
    .function("loadTextures", optional_override(
        [](AbstractCheckButton& this_, const std::string& arg0, const std::string& arg1, const std::string& arg2, const std::string& arg3, const std::string& arg4){
        return this_.loadTextures(arg0, arg1, arg2, arg3, arg4);
      }), allow_raw_pointers())
    .function("loadTextureFrontCrossDisabled", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&AbstractCheckButton::loadTextureFrontCrossDisabled), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("loadTextureBackGroundSelected", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&AbstractCheckButton::loadTextureBackGroundSelected), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getBackPressedFile", &AbstractCheckButton::getBackPressedFile, allow_raw_pointers())
    .function("getRendererFrontCrossDisabled", &AbstractCheckButton::getRendererFrontCrossDisabled, allow_raw_pointers())
    .function("getRendererBackgroundDisabled", &AbstractCheckButton::getRendererBackgroundDisabled, allow_raw_pointers())
    .function("setZoomScale", &AbstractCheckButton::setZoomScale, allow_raw_pointers())
    .property("_className",  optional_override([](const AbstractCheckButton& _) -> std::string {return "AbstractCheckButton";}))    
    ;


  class_<CheckBox, base<AbstractCheckButton>>("ccui.CheckBox")
    .constructor<>()
    .function("addEventListener", &CheckBox::addEventListener, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<CheckBox>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::CheckBox*(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&CheckBox::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::CheckBox*()>(&CheckBox::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::CheckBox*(const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&CheckBox::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const CheckBox& _) -> std::string {return "CheckBox";}))    
    // TODO: assign cc.Class.extend to ccui.CheckBox.extend
    ;


  class_<RadioButton, base<AbstractCheckButton>>("ccui.RadioButton")
    .constructor<>()
    .function("addEventListener", &RadioButton::addEventListener, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<RadioButton>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::RadioButton*(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&RadioButton::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::RadioButton*()>(&RadioButton::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::RadioButton*(const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&RadioButton::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const RadioButton& _) -> std::string {return "RadioButton";}))    
    // TODO: assign cc.Class.extend to ccui.RadioButton.extend
    ;


  class_<RadioButtonGroup, base<Widget>>("ccui.RadioButtonGroup")
    .constructor<>()
    .function("removeRadioButton", &RadioButtonGroup::removeRadioButton, allow_raw_pointers())
    .function("isAllowedNoSelection", &RadioButtonGroup::isAllowedNoSelection, allow_raw_pointers())
    .function("getSelectedButtonIndex", &RadioButtonGroup::getSelectedButtonIndex, allow_raw_pointers())
    .function("setAllowedNoSelection", &RadioButtonGroup::setAllowedNoSelection, allow_raw_pointers())
    .function("setSelectedButtonWithoutEvent", select_overload<void(cocos2d::ui::RadioButton*)>(&RadioButtonGroup::setSelectedButtonWithoutEvent), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("addEventListener", &RadioButtonGroup::addEventListener, allow_raw_pointers())
    .function("removeAllRadioButtons", &RadioButtonGroup::removeAllRadioButtons, allow_raw_pointers())
    .function("getRadioButtonByIndex", &RadioButtonGroup::getRadioButtonByIndex, allow_raw_pointers())
    .function("getNumberOfRadioButtons", &RadioButtonGroup::getNumberOfRadioButtons, allow_raw_pointers())
    .function("addRadioButton", &RadioButtonGroup::addRadioButton, allow_raw_pointers())
    .function("setSelectedButton", select_overload<void(cocos2d::ui::RadioButton*)>(&RadioButtonGroup::setSelectedButton), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("ctor", &cc_bindings_ctor<RadioButtonGroup>, allow_raw_pointers())
    .class_function("create", &RadioButtonGroup::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RadioButtonGroup& _) -> std::string {return "RadioButtonGroup";}))    
    // TODO: assign cc.Class.extend to ccui.RadioButtonGroup.extend
    ;


  class_<ImageView, base<Widget>>("ccui.ImageView")
    .constructor<>()
    .function("_init", select_overload<bool(const std::string&, cocos2d::ui::Widget::TextureResType)>(&ImageView::init), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setScale9Enabled", &ImageView::setScale9Enabled, allow_raw_pointers())
    .function("getRenderFile", &ImageView::getRenderFile, allow_raw_pointers())
    .function("setTextureRect", &ImageView::setTextureRect, allow_raw_pointers())
    .function("loadTexture", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&ImageView::loadTexture), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getCapInsets", &ImageView::getCapInsets, allow_raw_pointers())
    .function("isScale9Enabled", &ImageView::isScale9Enabled, allow_raw_pointers())
    .function("setCapInsets", &ImageView::setCapInsets, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ImageView>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::ImageView*(const std::string&, cocos2d::ui::Widget::TextureResType)>(&ImageView::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::ImageView*()>(&ImageView::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ImageView& _) -> std::string {return "ImageView";}))    
    // TODO: assign cc.Class.extend to ccui.ImageView.extend
    ;


  class_<Text, base<Widget>>("ccui.Text")
    .constructor<>()
    .function("enableShadow", &Text::enableShadow, allow_raw_pointers())
    .function("enableShadow", optional_override(
        [](Text& this_){
        return this_.enableShadow();
      }), allow_raw_pointers())
    .function("enableShadow", optional_override(
        [](Text& this_, const cocos2d::Color4B& arg0){
        return this_.enableShadow(arg0);
      }), allow_raw_pointers())
    .function("enableShadow", optional_override(
        [](Text& this_, const cocos2d::Color4B& arg0, const cocos2d::Size& arg1){
        return this_.enableShadow(arg0, arg1);
      }), allow_raw_pointers())
    .function("getFontSize", &Text::getFontSize, allow_raw_pointers())
    .function("getString", &Text::getString, allow_raw_pointers())
    .function("disableEffect", select_overload<void(cocos2d::LabelEffect)>(&Text::disableEffect), allow_raw_pointers())
    .function("disableEffect", select_overload<void()>(&Text::disableEffect), allow_raw_pointers())
    .function("getLabelEffectType", &Text::getLabelEffectType, allow_raw_pointers())
    .function("getTextAreaSize", &Text::getTextAreaSize, allow_raw_pointers())
    .function("setTextVerticalAlignment", &Text::setTextVerticalAlignment, allow_raw_pointers())
    .function("setFontName", &Text::setFontName, allow_raw_pointers())
    .function("setTouchScaleChangeEnabled", &Text::setTouchScaleChangeEnabled, allow_raw_pointers())
    .function("getShadowOffset", &Text::getShadowOffset, allow_raw_pointers())
    .function("setString", &Text::setString, allow_raw_pointers())
    .function("getOutlineSize", &Text::getOutlineSize, allow_raw_pointers())
    .function("init", select_overload<bool(const std::string&, const std::string&, float)>(&Text::init), allow_raw_pointers())
    .function("getShadowBlurRadius", &Text::getShadowBlurRadius, allow_raw_pointers())
    .function("isTouchScaleChangeEnabled", &Text::isTouchScaleChangeEnabled, allow_raw_pointers())
    .function("getFontName", &Text::getFontName, allow_raw_pointers())
    .function("setTextAreaSize", &Text::setTextAreaSize, allow_raw_pointers())
    .function("getStringLength", &Text::getStringLength, allow_raw_pointers())
    .function("getAutoRenderSize", &Text::getAutoRenderSize, allow_raw_pointers())
    .function("enableOutline", &Text::enableOutline, allow_raw_pointers())
    .function("enableOutline", optional_override(
        [](Text& this_, const cocos2d::Color4B& arg0){
        return this_.enableOutline(arg0);
      }), allow_raw_pointers())
    .function("getEffectColor", &Text::getEffectColor, allow_raw_pointers())
    .function("getType", &Text::getType, allow_raw_pointers())
    .function("getTextHorizontalAlignment", &Text::getTextHorizontalAlignment, allow_raw_pointers())
    .function("isShadowEnabled", &Text::isShadowEnabled, allow_raw_pointers())
    .function("setFontSize", &Text::setFontSize, allow_raw_pointers())
    .function("getShadowColor", &Text::getShadowColor, allow_raw_pointers())
    .function("setTextColor", &Text::setTextColor, allow_raw_pointers())
    .function("enableGlow", &Text::enableGlow, allow_raw_pointers())
    .function("getLetter", &Text::getLetter, allow_raw_pointers())
    .function("getTextColor", &Text::getTextColor, allow_raw_pointers())
    .function("setTextHorizontalAlignment", &Text::setTextHorizontalAlignment, allow_raw_pointers())
    .function("getTextVerticalAlignment", &Text::getTextVerticalAlignment, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Text>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::Text*(const std::string&, const std::string&, float)>(&Text::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::Text*()>(&Text::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Text& _) -> std::string {return "Text";}))    
    // TODO: assign cc.Class.extend to ccui.Text.extend
    ;


  class_<TextAtlas, base<Widget>>("ccui.TextAtlas")
    .constructor<>()
    .function("getStringLength", &TextAtlas::getStringLength, allow_raw_pointers())
    .function("getString", &TextAtlas::getString, allow_raw_pointers())
    .function("setString", &TextAtlas::setString, allow_raw_pointers())
    .function("getRenderFile", &TextAtlas::getRenderFile, allow_raw_pointers())
    .function("setProperty", &TextAtlas::setProperty, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TextAtlas>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TextAtlas*(const std::string&, const std::string&, int, int, const std::string&)>(&TextAtlas::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TextAtlas*()>(&TextAtlas::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TextAtlas& _) -> std::string {return "TextAtlas";}))    
    // TODO: assign cc.Class.extend to ccui.TextAtlas.extend
    ;


  class_<LoadingBar, base<Widget>>("ccui.LoadingBar")
    .constructor<>()
    .function("setPercent", &LoadingBar::setPercent, allow_raw_pointers())
    .function("setScale9Enabled", &LoadingBar::setScale9Enabled, allow_raw_pointers())
    .function("getRenderFile", &LoadingBar::getRenderFile, allow_raw_pointers())
    .function("setDirection", &LoadingBar::setDirection, allow_raw_pointers())
    .function("loadTexture", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&LoadingBar::loadTexture), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getCapInsets", &LoadingBar::getCapInsets, allow_raw_pointers())
    .function("isScale9Enabled", &LoadingBar::isScale9Enabled, allow_raw_pointers())
    .function("setCapInsets", &LoadingBar::setCapInsets, allow_raw_pointers())
    .function("getDirection", &LoadingBar::getDirection, allow_raw_pointers())
    .function("getPercent", &LoadingBar::getPercent, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<LoadingBar>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::LoadingBar*(const std::string&, float)>(&LoadingBar::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::LoadingBar*()>(&LoadingBar::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::LoadingBar*(const std::string&, cocos2d::ui::Widget::TextureResType, float)>(&LoadingBar::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const LoadingBar& _) -> std::string {return "LoadingBar";}))    
    // TODO: assign cc.Class.extend to ccui.LoadingBar.extend
    ;


  class_<ScrollView, base<Layout>>("ccui.ScrollView")
    .constructor<>()
    .function("isInertiaScrollEnabled", &ScrollView::isInertiaScrollEnabled, allow_raw_pointers())
    .function("setInnerContainerPosition", &ScrollView::setInnerContainerPosition, allow_raw_pointers())
    .function("jumpToPercentVertical", &ScrollView::jumpToPercentVertical, allow_raw_pointers())
    .function("stopScroll", &ScrollView::stopScroll, allow_raw_pointers())
    .function("setScrollBarPositionFromCornerForHorizontal", &ScrollView::setScrollBarPositionFromCornerForHorizontal, allow_raw_pointers())
    .function("setInertiaScrollEnabled", &ScrollView::setInertiaScrollEnabled, allow_raw_pointers())
    .function("getScrollBarColor", &ScrollView::getScrollBarColor, allow_raw_pointers())
    .function("isScrollBarEnabled", &ScrollView::isScrollBarEnabled, allow_raw_pointers())
    .function("getTouchTotalTimeThreshold", &ScrollView::getTouchTotalTimeThreshold, allow_raw_pointers())
    .function("scrollToTopRight", &ScrollView::scrollToTopRight, allow_raw_pointers())
    .function("stopOverallScroll", &ScrollView::stopOverallScroll, allow_raw_pointers())
    .function("setScrollBarAutoHideEnabled", &ScrollView::setScrollBarAutoHideEnabled, allow_raw_pointers())
    .function("jumpToLeft", &ScrollView::jumpToLeft, allow_raw_pointers())
    .function("jumpToRight", &ScrollView::jumpToRight, allow_raw_pointers())
    .function("scrollToBottom", &ScrollView::scrollToBottom, allow_raw_pointers())
    .function("getDirection", &ScrollView::getDirection, allow_raw_pointers())
    .function("scrollToBottomLeft", &ScrollView::scrollToBottomLeft, allow_raw_pointers())
    .function("jumpToBottom", &ScrollView::jumpToBottom, allow_raw_pointers())
    .function("scrollToTopLeft", &ScrollView::scrollToTopLeft, allow_raw_pointers())
    .function("jumpToTopRight", &ScrollView::jumpToTopRight, allow_raw_pointers())
    .function("scrollToPercentBothDirection", &ScrollView::scrollToPercentBothDirection, allow_raw_pointers())
    .function("jumpToBottomRight", &ScrollView::jumpToBottomRight, allow_raw_pointers())
    .function("setScrollBarAutoHideTime", &ScrollView::setScrollBarAutoHideTime, allow_raw_pointers())
    .function("setTouchTotalTimeThreshold", &ScrollView::setTouchTotalTimeThreshold, allow_raw_pointers())
    .function("getScrolledPercentHorizontal", &ScrollView::getScrolledPercentHorizontal, allow_raw_pointers())
    .function("setBounceEnabled", &ScrollView::setBounceEnabled, allow_raw_pointers())
    .function("stopAutoScroll", &ScrollView::stopAutoScroll, allow_raw_pointers())
    .function("getScrollBarPositionFromCornerForHorizontal", &ScrollView::getScrollBarPositionFromCornerForHorizontal, allow_raw_pointers())
    .function("scrollToLeft", &ScrollView::scrollToLeft, allow_raw_pointers())
    .function("jumpToPercentBothDirection", &ScrollView::jumpToPercentBothDirection, allow_raw_pointers())
    .function("setScrollBarPositionFromCorner", &ScrollView::setScrollBarPositionFromCorner, allow_raw_pointers())
    .function("setScrollBarPositionFromCornerForVertical", &ScrollView::setScrollBarPositionFromCornerForVertical, allow_raw_pointers())
    .function("getScrollBarPositionFromCornerForVertical", &ScrollView::getScrollBarPositionFromCornerForVertical, allow_raw_pointers())
    .function("setScrollBarEnabled", &ScrollView::setScrollBarEnabled, allow_raw_pointers())
    .function("jumpToBottomLeft", &ScrollView::jumpToBottomLeft, allow_raw_pointers())
    .function("getInnerContainer", &ScrollView::getInnerContainer, allow_raw_pointers())
    .function("jumpToTop", &ScrollView::jumpToTop, allow_raw_pointers())
    .function("getScrolledPercentVertical", &ScrollView::getScrolledPercentVertical, allow_raw_pointers())
    .function("isBounceEnabled", &ScrollView::isBounceEnabled, allow_raw_pointers())
    .function("isScrolling", &ScrollView::isScrolling, allow_raw_pointers())
    .function("isAutoScrolling", &ScrollView::isAutoScrolling, allow_raw_pointers())
    .function("scrollToPercentVertical", &ScrollView::scrollToPercentVertical, allow_raw_pointers())
    .function("getScrollBarOpacity", &ScrollView::getScrollBarOpacity, allow_raw_pointers())
    .function("scrollToBottomRight", &ScrollView::scrollToBottomRight, allow_raw_pointers())
    .function("getScrollBarWidth", &ScrollView::getScrollBarWidth, allow_raw_pointers())
    .function("scrollToTop", &ScrollView::scrollToTop, allow_raw_pointers())
    .function("scrollToRight", &ScrollView::scrollToRight, allow_raw_pointers())
    .function("scrollToPercentHorizontal", &ScrollView::scrollToPercentHorizontal, allow_raw_pointers())
    .function("getScrolledPercentBothDirection", &ScrollView::getScrolledPercentBothDirection, allow_raw_pointers())
    .function("setScrollBarColor", &ScrollView::setScrollBarColor, allow_raw_pointers())
    .function("setDirection", &ScrollView::setDirection, allow_raw_pointers())
    .function("getInnerContainerPosition", &ScrollView::getInnerContainerPosition, allow_raw_pointers())
    .function("setInnerContainerSize", &ScrollView::setInnerContainerSize, allow_raw_pointers())
    .function("getInnerContainerSize", &ScrollView::getInnerContainerSize, allow_raw_pointers())
    .function("addEventListener", &ScrollView::addEventListener, allow_raw_pointers())
    .function("jumpToTopLeft", &ScrollView::jumpToTopLeft, allow_raw_pointers())
    .function("setScrollBarOpacity", &ScrollView::setScrollBarOpacity, allow_raw_pointers())
    .function("setScrollBarWidth", &ScrollView::setScrollBarWidth, allow_raw_pointers())
    .function("jumpToPercentHorizontal", &ScrollView::jumpToPercentHorizontal, allow_raw_pointers())
    .function("isScrollBarAutoHideEnabled", &ScrollView::isScrollBarAutoHideEnabled, allow_raw_pointers())
    .function("getScrollBarAutoHideTime", &ScrollView::getScrollBarAutoHideTime, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ScrollView>, allow_raw_pointers())
    .class_function("create", &ScrollView::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ScrollView& _) -> std::string {return "ScrollView";}))    
    // TODO: assign cc.Class.extend to ccui.ScrollView.extend
    ;


  class_<ListView, base<ScrollView>>("ccui.ListView")
    .constructor<>()
    .function("setGravity", &ListView::setGravity, allow_raw_pointers())
    .function("removeLastItem", &ListView::removeLastItem, allow_raw_pointers())
    .function("getLeftPadding", &ListView::getLeftPadding, allow_raw_pointers())
    .function("getCenterItemInCurrentView", &ListView::getCenterItemInCurrentView, allow_raw_pointers())
    .function("getCurSelectedIndex", &ListView::getCurSelectedIndex, allow_raw_pointers())
    .function("getScrollDuration", &ListView::getScrollDuration, allow_raw_pointers())
    .function("getMagneticAllowedOutOfBoundary", &ListView::getMagneticAllowedOutOfBoundary, allow_raw_pointers())
    .function("getItemsMargin", &ListView::getItemsMargin, allow_raw_pointers())
    .function("scrollToItem", select_overload<void(int, const cocos2d::Vec2&, const cocos2d::Vec2&, float)>(&ListView::scrollToItem), allow_raw_pointers())
    .function("scrollToItem", select_overload<void(int, const cocos2d::Vec2&, const cocos2d::Vec2&)>(&ListView::scrollToItem), allow_raw_pointers())
    .function("jumpToItem", &ListView::jumpToItem, allow_raw_pointers())
    .function("setTopPadding", &ListView::setTopPadding, allow_raw_pointers())
    .function("getIndex", &ListView::getIndex, allow_raw_pointers())
    .function("pushBackCustomItem", &ListView::pushBackCustomItem, allow_raw_pointers())
    .function("setCurSelectedIndex", &ListView::setCurSelectedIndex, allow_raw_pointers())
    .function("insertDefaultItem", &ListView::insertDefaultItem, allow_raw_pointers())
    .function("setMagneticType", &ListView::setMagneticType, allow_raw_pointers())
    .function("setMagneticAllowedOutOfBoundary", &ListView::setMagneticAllowedOutOfBoundary, allow_raw_pointers())
    .function("addEventListener", &ListView::addEventListener, allow_raw_pointers())
    .function("getTopmostItemInCurrentView", &ListView::getTopmostItemInCurrentView, allow_raw_pointers())
    .function("setPadding", &ListView::setPadding, allow_raw_pointers())
    .function("removeAllItems", &ListView::removeAllItems, allow_raw_pointers())
    .function("getRightPadding", &ListView::getRightPadding, allow_raw_pointers())
    .function("getBottommostItemInCurrentView", &ListView::getBottommostItemInCurrentView, allow_raw_pointers())
    .function("getItems", &ListView::getItems, allow_raw_pointers())
    .function("getLeftmostItemInCurrentView", &ListView::getLeftmostItemInCurrentView, allow_raw_pointers())
    .function("setItemsMargin", &ListView::setItemsMargin, allow_raw_pointers())
    .function("getMagneticType", &ListView::getMagneticType, allow_raw_pointers())
    .function("getItem", &ListView::getItem, allow_raw_pointers())
    .function("removeItem", &ListView::removeItem, allow_raw_pointers())
    .function("getTopPadding", &ListView::getTopPadding, allow_raw_pointers())
    .function("getRightmostItemInCurrentView", &ListView::getRightmostItemInCurrentView, allow_raw_pointers())
    .function("pushBackDefaultItem", &ListView::pushBackDefaultItem, allow_raw_pointers())
    .function("setLeftPadding", &ListView::setLeftPadding, allow_raw_pointers())
    .function("getClosestItemToPosition", &ListView::getClosestItemToPosition, allow_raw_pointers())
    .function("setBottomPadding", &ListView::setBottomPadding, allow_raw_pointers())
    .function("setScrollDuration", &ListView::setScrollDuration, allow_raw_pointers())
    .function("getClosestItemToPositionInCurrentView", &ListView::getClosestItemToPositionInCurrentView, allow_raw_pointers())
    .function("setRightPadding", &ListView::setRightPadding, allow_raw_pointers())
    .function("setItemModel", &ListView::setItemModel, allow_raw_pointers())
    .function("getBottomPadding", &ListView::getBottomPadding, allow_raw_pointers())
    .function("insertCustomItem", &ListView::insertCustomItem, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ListView>, allow_raw_pointers())
    .class_function("create", &ListView::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ListView& _) -> std::string {return "ListView";}))    
    // TODO: assign cc.Class.extend to ccui.ListView.extend
    ;


  class_<Slider, base<Widget>>("ccui.Slider")
    .constructor<>()
    .function("setPercent", &Slider::setPercent, allow_raw_pointers())
    .function("getMaxPercent", &Slider::getMaxPercent, allow_raw_pointers())
    .function("loadSlidBallTextureNormal", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&Slider::loadSlidBallTextureNormal), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("loadProgressBarTexture", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&Slider::loadProgressBarTexture), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getBallNormalFile", &Slider::getBallNormalFile, allow_raw_pointers())
    .function("getSlidBallDisabledRenderer", &Slider::getSlidBallDisabledRenderer, allow_raw_pointers())
    .function("setScale9Enabled", &Slider::setScale9Enabled, allow_raw_pointers())
    .function("getBallPressedFile", &Slider::getBallPressedFile, allow_raw_pointers())
    .function("getZoomScale", &Slider::getZoomScale, allow_raw_pointers())
    .function("setCapInsetProgressBarRenderer", &Slider::setCapInsetProgressBarRenderer, allow_raw_pointers())
    .function("loadSlidBallTextures", &Slider::loadSlidBallTextures, allow_raw_pointers())
    .function("loadSlidBallTextures", optional_override(
        [](Slider& this_, const std::string& arg0){
        return this_.loadSlidBallTextures(arg0);
      }), allow_raw_pointers())
    .function("loadSlidBallTextures", optional_override(
        [](Slider& this_, const std::string& arg0, const std::string& arg1){
        return this_.loadSlidBallTextures(arg0, arg1);
      }), allow_raw_pointers())
    .function("loadSlidBallTextures", optional_override(
        [](Slider& this_, const std::string& arg0, const std::string& arg1, const std::string& arg2){
        return this_.loadSlidBallTextures(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("getSlidBallRenderer", &Slider::getSlidBallRenderer, allow_raw_pointers())
    .function("addEventListener", &Slider::addEventListener, allow_raw_pointers())
    .function("setMaxPercent", &Slider::setMaxPercent, allow_raw_pointers())
    .function("loadBarTexture", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&Slider::loadBarTexture), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getProgressBarFile", &Slider::getProgressBarFile, allow_raw_pointers())
    .function("getCapInsetsBarRenderer", &Slider::getCapInsetsBarRenderer, allow_raw_pointers())
    .function("updateVisualSlider", &Slider::updateVisualSlider, allow_raw_pointers())
    .function("getCapInsetsProgressBarRenderer", &Slider::getCapInsetsProgressBarRenderer, allow_raw_pointers())
    .function("getSlidBallPressedRenderer", &Slider::getSlidBallPressedRenderer, allow_raw_pointers())
    .function("loadSlidBallTexturePressed", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&Slider::loadSlidBallTexturePressed), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getBackFile", &Slider::getBackFile, allow_raw_pointers())
    .function("isScale9Enabled", &Slider::isScale9Enabled, allow_raw_pointers())
    .function("getBallDisabledFile", &Slider::getBallDisabledFile, allow_raw_pointers())
    .function("setCapInsetsBarRenderer", &Slider::setCapInsetsBarRenderer, allow_raw_pointers())
    .function("setZoomScale", &Slider::setZoomScale, allow_raw_pointers())
    .function("setCapInsets", &Slider::setCapInsets, allow_raw_pointers())
    .function("loadSlidBallTextureDisabled", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&Slider::loadSlidBallTextureDisabled), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getSlidBallNormalRenderer", &Slider::getSlidBallNormalRenderer, allow_raw_pointers())
    .function("getPercent", &Slider::getPercent, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Slider>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::Slider*(const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&Slider::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::Slider*()>(&Slider::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Slider& _) -> std::string {return "Slider";}))    
    // TODO: assign cc.Class.extend to ccui.Slider.extend
    ;


  class_<UICCTextField, base<TextFieldTTF>>("ccui.UICCTextField")
    .constructor<>()
    .function("setPasswordText", &UICCTextField::setPasswordText, allow_raw_pointers())
    .function("setAttachWithIME", &UICCTextField::setAttachWithIME, allow_raw_pointers())
    .function("getDeleteBackward", &UICCTextField::getDeleteBackward, allow_raw_pointers())
    .function("getAttachWithIME", &UICCTextField::getAttachWithIME, allow_raw_pointers())
    .function("getInsertText", &UICCTextField::getInsertText, allow_raw_pointers())
    .function("setInsertText", &UICCTextField::setInsertText, allow_raw_pointers())
    .function("getDetachWithIME", &UICCTextField::getDetachWithIME, allow_raw_pointers())
    .function("getCharCount", &UICCTextField::getCharCount, allow_raw_pointers())
    .function("closeIME", &UICCTextField::closeIME, allow_raw_pointers())
    .function("setPasswordEnabled", &UICCTextField::setPasswordEnabled, allow_raw_pointers())
    .function("setMaxLengthEnabled", &UICCTextField::setMaxLengthEnabled, allow_raw_pointers())
    .function("isPasswordEnabled", &UICCTextField::isPasswordEnabled, allow_raw_pointers())
    .function("setPasswordStyleText", &UICCTextField::setPasswordStyleText, allow_raw_pointers())
    .function("getMaxLength", &UICCTextField::getMaxLength, allow_raw_pointers())
    .function("isMaxLengthEnabled", &UICCTextField::isMaxLengthEnabled, allow_raw_pointers())
    .function("openIME", &UICCTextField::openIME, allow_raw_pointers())
    .function("setDetachWithIME", &UICCTextField::setDetachWithIME, allow_raw_pointers())
    .function("setMaxLength", &UICCTextField::setMaxLength, allow_raw_pointers())
    .function("setDeleteBackward", &UICCTextField::setDeleteBackward, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::UICCTextField*(const std::string&, const std::string&, float)>(&UICCTextField::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::UICCTextField*()>(&UICCTextField::create), allow_raw_pointers())
    .property("_className",  optional_override([](const UICCTextField& _) -> std::string {return "UICCTextField";}))    
    ;


  class_<TextField, base<Widget>>("ccui.TextField")
    .constructor<>()
    .function("setAttachWithIME", &TextField::setAttachWithIME, allow_raw_pointers())
    .function("getFontSize", &TextField::getFontSize, allow_raw_pointers())
    .function("getString", &TextField::getString, allow_raw_pointers())
    .function("setPasswordStyleText", &TextField::setPasswordStyleText, allow_raw_pointers())
    .function("getDeleteBackward", &TextField::getDeleteBackward, allow_raw_pointers())
    .function("getTextColor", &TextField::getTextColor, allow_raw_pointers())
    .function("getPlaceHolder", &TextField::getPlaceHolder, allow_raw_pointers())
    .function("getAttachWithIME", &TextField::getAttachWithIME, allow_raw_pointers())
    .function("setFontName", &TextField::setFontName, allow_raw_pointers())
    .function("getInsertText", &TextField::getInsertText, allow_raw_pointers())
    .function("setInsertText", &TextField::setInsertText, allow_raw_pointers())
    .function("setString", &TextField::setString, allow_raw_pointers())
    .function("getDetachWithIME", &TextField::getDetachWithIME, allow_raw_pointers())
    .function("setTextVerticalAlignment", &TextField::setTextVerticalAlignment, allow_raw_pointers())
    .function("addEventListener", &TextField::addEventListener, allow_raw_pointers())
    .function("didNotSelectSelf", &TextField::didNotSelectSelf, allow_raw_pointers())
    .function("isPasswordEnabled", &TextField::isPasswordEnabled, allow_raw_pointers())
    .function("getFontName", &TextField::getFontName, allow_raw_pointers())
    .function("setTextAreaSize", &TextField::setTextAreaSize, allow_raw_pointers())
    .function("attachWithIME", &TextField::attachWithIME, allow_raw_pointers())
    .function("getStringLength", &TextField::getStringLength, allow_raw_pointers())
    .function("getAutoRenderSize", &TextField::getAutoRenderSize, allow_raw_pointers())
    .function("setPasswordEnabled", &TextField::setPasswordEnabled, allow_raw_pointers())
    .function("getPlaceHolderColor", &TextField::getPlaceHolderColor, allow_raw_pointers())
    .function("getPasswordStyleText", &TextField::getPasswordStyleText, allow_raw_pointers())
    .function("setMaxLengthEnabled", &TextField::setMaxLengthEnabled, allow_raw_pointers())
    .function("setDeleteBackward", &TextField::setDeleteBackward, allow_raw_pointers())
    .function("setCursorPosition", &TextField::setCursorPosition, allow_raw_pointers())
    .function("getTextHorizontalAlignment", &TextField::getTextHorizontalAlignment, allow_raw_pointers())
    .function("setFontSize", &TextField::setFontSize, allow_raw_pointers())
    .function("setPlaceHolder", &TextField::setPlaceHolder, allow_raw_pointers())
    .function("setCursorFromPoint", &TextField::setCursorFromPoint, allow_raw_pointers())
    .function("setPlaceHolderColor", select_overload<void(const cocos2d::Color4B&)>(&TextField::setPlaceHolderColor), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setTextHorizontalAlignment", &TextField::setTextHorizontalAlignment, allow_raw_pointers())
    .function("setTextColor", &TextField::setTextColor, allow_raw_pointers())
    .function("setCursorChar", &TextField::setCursorChar, allow_raw_pointers())
    .function("getMaxLength", &TextField::getMaxLength, allow_raw_pointers())
    .function("isMaxLengthEnabled", &TextField::isMaxLengthEnabled, allow_raw_pointers())
    .function("setDetachWithIME", &TextField::setDetachWithIME, allow_raw_pointers())
    .function("setTouchAreaEnabled", &TextField::setTouchAreaEnabled, allow_raw_pointers())
    .function("setMaxLength", &TextField::setMaxLength, allow_raw_pointers())
    .function("setCursorEnabled", &TextField::setCursorEnabled, allow_raw_pointers())
    .function("setTouchSize", &TextField::setTouchSize, allow_raw_pointers())
    .function("getTouchSize", &TextField::getTouchSize, allow_raw_pointers())
    .function("getTextVerticalAlignment", &TextField::getTextVerticalAlignment, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TextField>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TextField*(const std::string&, const std::string&, int)>(&TextField::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TextField*()>(&TextField::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TextField& _) -> std::string {return "TextField";}))    
    // TODO: assign cc.Class.extend to ccui.TextField.extend
    ;


  class_<TextBMFont, base<Widget>>("ccui.TextBMFont")
    .constructor<>()
    .function("getStringLength", &TextBMFont::getStringLength, allow_raw_pointers())
    .function("getString", &TextBMFont::getString, allow_raw_pointers())
    .function("getRenderFile", &TextBMFont::getRenderFile, allow_raw_pointers())
    .function("setFntFile", &TextBMFont::setFntFile, allow_raw_pointers())
    .function("resetRender", &TextBMFont::resetRender, allow_raw_pointers())
    .function("setString", &TextBMFont::setString, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TextBMFont>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TextBMFont*(const std::string&, const std::string&)>(&TextBMFont::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TextBMFont*()>(&TextBMFont::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TextBMFont& _) -> std::string {return "TextBMFont";}))    
    // TODO: assign cc.Class.extend to ccui.TextBMFont.extend
    ;


  class_<PageView, base<ListView>>("ccui.PageView")
    .constructor<>()
    .function("setIndicatorSpaceBetweenIndexNodes", &PageView::setIndicatorSpaceBetweenIndexNodes, allow_raw_pointers())
    .function("insertPage", &PageView::insertPage, allow_raw_pointers())
    .function("setIndicatorIndexNodesOpacity", &PageView::setIndicatorIndexNodesOpacity, allow_raw_pointers())
    .function("setIndicatorSelectedIndexOpacity", &PageView::setIndicatorSelectedIndexOpacity, allow_raw_pointers())
    .function("setAutoScrollStopEpsilon", &PageView::setAutoScrollStopEpsilon, allow_raw_pointers())
    .function("setIndicatorIndexNodesScale", &PageView::setIndicatorIndexNodesScale, allow_raw_pointers())
    .function("setIndicatorEnabled", &PageView::setIndicatorEnabled, allow_raw_pointers())
    .function("setIndicatorSelectedIndexColor", &PageView::setIndicatorSelectedIndexColor, allow_raw_pointers())
    .function("addEventListener", &PageView::addEventListener, allow_raw_pointers())
    .function("getIndicatorPosition", &PageView::getIndicatorPosition, allow_raw_pointers())
    .function("setCurrentPageIndex", &PageView::setCurrentPageIndex, allow_raw_pointers())
    .function("getIndicatorIndexNodesColor", &PageView::getIndicatorIndexNodesColor, allow_raw_pointers())
    .function("getIndicatorSelectedIndexColor", &PageView::getIndicatorSelectedIndexColor, allow_raw_pointers())
    .function("getIndicatorIndexNodesScale", &PageView::getIndicatorIndexNodesScale, allow_raw_pointers())
    .function("setIndicatorPosition", &PageView::setIndicatorPosition, allow_raw_pointers())
    .function("getIndicatorSelectedIndexOpacity", &PageView::getIndicatorSelectedIndexOpacity, allow_raw_pointers())
    .function("scrollToPage", select_overload<void(int, float)>(&PageView::scrollToPage), allow_raw_pointers())
    .function("scrollToPage", select_overload<void(int)>(&PageView::scrollToPage), allow_raw_pointers())
    .function("setIndicatorIndexNodesColor", &PageView::setIndicatorIndexNodesColor, allow_raw_pointers())
    .function("setIndicatorPositionAsAnchorPoint", &PageView::setIndicatorPositionAsAnchorPoint, allow_raw_pointers())
    .function("scrollToItem", select_overload<void(int, float)>(&PageView::scrollToItem), allow_raw_pointers())
    .function("scrollToItem", select_overload<void(int)>(&PageView::scrollToItem), allow_raw_pointers())
    .function("removeAllPages", &PageView::removeAllPages, allow_raw_pointers())
    .function("getIndicatorIndexNodesOpacity", &PageView::getIndicatorIndexNodesOpacity, allow_raw_pointers())
    .function("getIndicatorPositionAsAnchorPoint", &PageView::getIndicatorPositionAsAnchorPoint, allow_raw_pointers())
    .function("getCurrentPageIndex", &PageView::getCurrentPageIndex, allow_raw_pointers())
    .function("removePage", &PageView::removePage, allow_raw_pointers())
    .function("setIndicatorIndexNodesTexture", &PageView::setIndicatorIndexNodesTexture, allow_raw_pointers())
    .function("setIndicatorIndexNodesTexture", optional_override(
        [](PageView& this_, const std::string& arg0){
        return this_.setIndicatorIndexNodesTexture(arg0);
      }), allow_raw_pointers())
    .function("getIndicatorEnabled", &PageView::getIndicatorEnabled, allow_raw_pointers())
    .function("addPage", &PageView::addPage, allow_raw_pointers())
    .function("getIndicatorSpaceBetweenIndexNodes", &PageView::getIndicatorSpaceBetweenIndexNodes, allow_raw_pointers())
    .function("removePageAtIndex", &PageView::removePageAtIndex, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<PageView>, allow_raw_pointers())
    .class_function("create", &PageView::create, allow_raw_pointers())
    .property("_className",  optional_override([](const PageView& _) -> std::string {return "PageView";}))    
    // TODO: assign cc.Class.extend to ccui.PageView.extend
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
    .function("equalType", &RichElement::equalType, allow_raw_pointers())
    .function("init", &RichElement::init, allow_raw_pointers())
    .function("setColor", &RichElement::setColor, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<RichElement>, allow_raw_pointers())
    .property("_className",  optional_override([](const RichElement& _) -> std::string {return "RichElement";}))    
    // TODO: assign cc.Class.extend to ccui.RichElement.extend
    ;


  class_<RichElementText, base<RichElement>>("ccui.RichElementText")
    .constructor<>()
    .function("init", &RichElementText::init, allow_raw_pointers())
    .function("init", optional_override(
        [](RichElementText& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7){
        return this_.init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
      }), allow_raw_pointers())
    .function("init", optional_override(
        [](RichElementText& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7, const cocos2d::Color3B& arg8){
        return this_.init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
      }), allow_raw_pointers())
    .function("init", optional_override(
        [](RichElementText& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7, const cocos2d::Color3B& arg8, int arg9){
        return this_.init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
      }), allow_raw_pointers())
    .function("init", optional_override(
        [](RichElementText& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7, const cocos2d::Color3B& arg8, int arg9, const cocos2d::Color3B& arg10){
        return this_.init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
      }), allow_raw_pointers())
    .function("init", optional_override(
        [](RichElementText& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7, const cocos2d::Color3B& arg8, int arg9, const cocos2d::Color3B& arg10, const cocos2d::Size& arg11){
        return this_.init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
      }), allow_raw_pointers())
    .function("init", optional_override(
        [](RichElementText& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, float arg5, unsigned int arg6, const std::string& arg7, const cocos2d::Color3B& arg8, int arg9, const cocos2d::Color3B& arg10, const cocos2d::Size& arg11, int arg12){
        return this_.init(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
      }), allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<RichElementText>, allow_raw_pointers())
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
    // TODO: assign cc.Class.extend to ccui.RichElementText.extend
    ;


  class_<RichElementImage, base<RichElement>>("ccui.RichElementImage")
    .constructor<>()
    .function("setHeight", &RichElementImage::setHeight, allow_raw_pointers())
    .function("init", &RichElementImage::init, allow_raw_pointers())
    .function("init", optional_override(
        [](RichElementImage& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3){
        return this_.init(arg0, arg1, arg2, arg3);
      }), allow_raw_pointers())
    .function("init", optional_override(
        [](RichElementImage& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4){
        return this_.init(arg0, arg1, arg2, arg3, arg4);
      }), allow_raw_pointers())
    .function("setWidth", &RichElementImage::setWidth, allow_raw_pointers())
    .function("setUrl", &RichElementImage::setUrl, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<RichElementImage>, allow_raw_pointers())
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
    // TODO: assign cc.Class.extend to ccui.RichElementImage.extend
    ;


  class_<RichElementCustomNode, base<RichElement>>("ccui.RichElementCustomNode")
    .constructor<>()
    .function("init", &RichElementCustomNode::init, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<RichElementCustomNode>, allow_raw_pointers())
    .class_function("create", &RichElementCustomNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RichElementCustomNode& _) -> std::string {return "RichElementCustomNode";}))    
    // TODO: assign cc.Class.extend to ccui.RichElementCustomNode.extend
    ;


  class_<RichElementNewLine, base<RichElement>>("ccui.RichElementNewLine")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<RichElementNewLine>, allow_raw_pointers())
    .class_function("create", &RichElementNewLine::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RichElementNewLine& _) -> std::string {return "RichElementNewLine";}))    
    // TODO: assign cc.Class.extend to ccui.RichElementNewLine.extend
    ;


  class_<RichText, base<Widget>>("ccui.RichText")
    .constructor<>()
    .function("insertElement", &RichText::insertElement, allow_raw_pointers())
    .function("setAnchorTextOutline", &RichText::setAnchorTextOutline, allow_raw_pointers())
    .function("setAnchorTextOutline", optional_override(
        [](RichText& this_, bool arg0){
        return this_.setAnchorTextOutline(arg0);
      }), allow_raw_pointers())
    .function("setAnchorTextOutline", optional_override(
        [](RichText& this_, bool arg0, const cocos2d::Color3B& arg1){
        return this_.setAnchorTextOutline(arg0, arg1);
      }), allow_raw_pointers())
    .function("getFontSize", &RichText::getFontSize, allow_raw_pointers())
    .function("pushBackElement", &RichText::pushBackElement, allow_raw_pointers())
    .function("setAnchorTextBold", &RichText::setAnchorTextBold, allow_raw_pointers())
    .function("getAnchorFontColor", &RichText::getAnchorFontColor, allow_raw_pointers())
    .function("getAnchorTextShadowBlurRadius", &RichText::getAnchorTextShadowBlurRadius, allow_raw_pointers())
    .function("setAnchorTextShadow", &RichText::setAnchorTextShadow, allow_raw_pointers())
    .function("setAnchorTextShadow", optional_override(
        [](RichText& this_, bool arg0){
        return this_.setAnchorTextShadow(arg0);
      }), allow_raw_pointers())
    .function("setAnchorTextShadow", optional_override(
        [](RichText& this_, bool arg0, const cocos2d::Color3B& arg1){
        return this_.setAnchorTextShadow(arg0, arg1);
      }), allow_raw_pointers())
    .function("setAnchorTextShadow", optional_override(
        [](RichText& this_, bool arg0, const cocos2d::Color3B& arg1, const cocos2d::Size& arg2){
        return this_.setAnchorTextShadow(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("isAnchorTextItalicEnabled", &RichText::isAnchorTextItalicEnabled, allow_raw_pointers())
    .function("setAnchorFontColor", &RichText::setAnchorFontColor, allow_raw_pointers())
    .function("setFontFace", &RichText::setFontFace, allow_raw_pointers())
    .function("setAnchorTextGlow", &RichText::setAnchorTextGlow, allow_raw_pointers())
    .function("setAnchorTextGlow", optional_override(
        [](RichText& this_, bool arg0){
        return this_.setAnchorTextGlow(arg0);
      }), allow_raw_pointers())
    .function("getHorizontalAlignment", &RichText::getHorizontalAlignment, allow_raw_pointers())
    .function("setHorizontalAlignment", &RichText::setHorizontalAlignment, allow_raw_pointers())
    .function("setAnchorTextDel", &RichText::setAnchorTextDel, allow_raw_pointers())
    .function("getAnchorTextOutlineColor3B", &RichText::getAnchorTextOutlineColor3B, allow_raw_pointers())
    .function("stringWithColor4B", &RichText::stringWithColor4B, allow_raw_pointers())
    .function("initWithXML", &RichText::initWithXML, allow_raw_pointers())
    .function("initWithXML", optional_override(
        [](RichText& this_, const std::string& arg0, const std::unordered_map<std::string, cocos2d::Value>& arg1){
        return this_.initWithXML(arg0, arg1);
      }), allow_raw_pointers())
    .function("getAnchorFontColor3B", &RichText::getAnchorFontColor3B, allow_raw_pointers())
    .function("formatText", &RichText::formatText, allow_raw_pointers())
    .function("getAnchorTextGlowColor3B", &RichText::getAnchorTextGlowColor3B, allow_raw_pointers())
    .function("openUrl", &RichText::openUrl, allow_raw_pointers())
    .function("getFontFace", &RichText::getFontFace, allow_raw_pointers())
    .function("setFontColor", &RichText::setFontColor, allow_raw_pointers())
    .function("isAnchorTextGlowEnabled", &RichText::isAnchorTextGlowEnabled, allow_raw_pointers())
    .function("getDefaults", &RichText::getDefaults, allow_raw_pointers())
    .function("isAnchorTextUnderlineEnabled", &RichText::isAnchorTextUnderlineEnabled, allow_raw_pointers())
    .function("getFontColor", &RichText::getFontColor, allow_raw_pointers())
    .function("isAnchorTextShadowEnabled", &RichText::isAnchorTextShadowEnabled, allow_raw_pointers())
    .function("getAnchorTextOutlineSize", &RichText::getAnchorTextOutlineSize, allow_raw_pointers())
    .function("setVerticalSpace", &RichText::setVerticalSpace, allow_raw_pointers())
    .function("isAnchorTextDelEnabled", &RichText::isAnchorTextDelEnabled, allow_raw_pointers())
    .function("setDefaults", &RichText::setDefaults, allow_raw_pointers())
    .function("setWrapMode", &RichText::setWrapMode, allow_raw_pointers())
    .function("setFontSize", &RichText::setFontSize, allow_raw_pointers())
    .function("removeElement", select_overload<void(cocos2d::ui::RichElement*)>(&RichText::removeElement), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setAnchorTextItalic", &RichText::setAnchorTextItalic, allow_raw_pointers())
    .function("getAnchorTextShadowOffset", &RichText::getAnchorTextShadowOffset, allow_raw_pointers())
    .function("isAnchorTextBoldEnabled", &RichText::isAnchorTextBoldEnabled, allow_raw_pointers())
    .function("getAnchorTextShadowColor3B", &RichText::getAnchorTextShadowColor3B, allow_raw_pointers())
    .function("stringWithColor3B", &RichText::stringWithColor3B, allow_raw_pointers())
    .function("isAnchorTextOutlineEnabled", &RichText::isAnchorTextOutlineEnabled, allow_raw_pointers())
    .function("getFontColor3B", &RichText::getFontColor3B, allow_raw_pointers())
    .function("getWrapMode", &RichText::getWrapMode, allow_raw_pointers())
    .function("setAnchorTextUnderline", &RichText::setAnchorTextUnderline, allow_raw_pointers())
    .function("color3BWithString", &RichText::color3BWithString, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<RichText>, allow_raw_pointers())
    .class_function("create", &RichText::create, allow_raw_pointers())
    .class_function("createWithXML", &RichText::createWithXML, allow_raw_pointers())
    .class_function("createWithXML", optional_override(
      [](const std::string& arg0, const std::unordered_map<std::string, cocos2d::Value>& arg1){
        return RichText::createWithXML(arg0, arg1);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const RichText& _) -> std::string {return "RichText";}))    
    // TODO: assign cc.Class.extend to ccui.RichText.extend
    ;


  class_<HBox, base<Layout>>("ccui.HBox")
    .constructor<>()
    .function("initWithSize", &HBox::initWithSize, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<HBox>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::HBox*(const cocos2d::Size&)>(&HBox::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::HBox*()>(&HBox::create), allow_raw_pointers())
    .property("_className",  optional_override([](const HBox& _) -> std::string {return "HBox";}))    
    // TODO: assign cc.Class.extend to ccui.HBox.extend
    ;


  class_<VBox, base<Layout>>("ccui.VBox")
    .constructor<>()
    .function("initWithSize", &VBox::initWithSize, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<VBox>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::VBox*(const cocos2d::Size&)>(&VBox::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::VBox*()>(&VBox::create), allow_raw_pointers())
    .property("_className",  optional_override([](const VBox& _) -> std::string {return "VBox";}))    
    // TODO: assign cc.Class.extend to ccui.VBox.extend
    ;


  class_<RelativeBox, base<Layout>>("ccui.RelativeBox")
    .constructor<>()
    .function("initWithSize", &RelativeBox::initWithSize, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<RelativeBox>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::RelativeBox*(const cocos2d::Size&)>(&RelativeBox::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::RelativeBox*()>(&RelativeBox::create), allow_raw_pointers())
    .property("_className",  optional_override([](const RelativeBox& _) -> std::string {return "RelativeBox";}))    
    // TODO: assign cc.Class.extend to ccui.RelativeBox.extend
    ;


  class_<Scale9Sprite, base<Sprite>>("ccui.Scale9Sprite")
    .constructor<>()
    .function("updateWithSprite", select_overload<bool(cocos2d::Sprite*, const cocos2d::Rect&, bool, const cocos2d::Vec2&, const cocos2d::Size&, const cocos2d::Rect&)>(&Scale9Sprite::updateWithSprite), allow_raw_pointers())
    .function("updateWithSprite", select_overload<bool(cocos2d::Sprite*, const cocos2d::Rect&, bool, const cocos2d::Rect&)>(&Scale9Sprite::updateWithSprite), allow_raw_pointers())
    .function("resizableSpriteWithCapInsets", &Scale9Sprite::resizableSpriteWithCapInsets, allow_raw_pointers())
    .function("getCapInsets", &Scale9Sprite::getCapInsets, allow_raw_pointers())
    .function("resetRender", &Scale9Sprite::resetRender, allow_raw_pointers())
    .function("setState", &Scale9Sprite::setState, allow_raw_pointers())
    .function("setInsetBottom", &Scale9Sprite::setInsetBottom, allow_raw_pointers())
    .function("initWithSpriteFrameName", select_overload<bool(const std::string&, const cocos2d::Rect&)>(&Scale9Sprite::initWithSpriteFrameName), allow_raw_pointers())
    .function("getSprite", &Scale9Sprite::getSprite, allow_raw_pointers())
    .function("setInsetTop", &Scale9Sprite::setInsetTop, allow_raw_pointers())
    .function("setRenderingType", &Scale9Sprite::setRenderingType, allow_raw_pointers())
    .function("init", select_overload<bool(cocos2d::Sprite*, const cocos2d::Rect&, bool, const cocos2d::Rect&)>(&Scale9Sprite::init), allow_raw_pointers())
    .function("init", select_overload<bool(cocos2d::Sprite*, const cocos2d::Rect&, const cocos2d::Rect&)>(&Scale9Sprite::init), allow_raw_pointers())
    .function("init", select_overload<bool(cocos2d::Sprite*, const cocos2d::Rect&, bool, const cocos2d::Vec2&, const cocos2d::Size&, const cocos2d::Rect&)>(&Scale9Sprite::init), allow_raw_pointers())
    .function("setPreferredSize", &Scale9Sprite::setPreferredSize, allow_raw_pointers())
    .function("copyTo", &Scale9Sprite::copyTo, allow_raw_pointers())
    .function("setSpriteFrame", &Scale9Sprite::setSpriteFrame, allow_raw_pointers())
    .function("getState", &Scale9Sprite::getState, allow_raw_pointers())
    .function("getInsetBottom", &Scale9Sprite::getInsetBottom, allow_raw_pointers())
    .function("setScale9Enabled", &Scale9Sprite::setScale9Enabled, allow_raw_pointers())
    .function("isScale9Enabled", &Scale9Sprite::isScale9Enabled, allow_raw_pointers())
    .function("getRenderingType", &Scale9Sprite::getRenderingType, allow_raw_pointers())
    .function("getInsetRight", &Scale9Sprite::getInsetRight, allow_raw_pointers())
    .function("getOriginalSize", &Scale9Sprite::getOriginalSize, allow_raw_pointers())
    .function("initWithFile", select_overload<bool(const cocos2d::Rect&, const std::string&)>(&Scale9Sprite::initWithFile), allow_raw_pointers())
    .function("initWithFile", select_overload<bool(const std::string&, const cocos2d::Rect&, const cocos2d::Rect&)>(&Scale9Sprite::initWithFile), allow_raw_pointers())
    .function("getInsetTop", &Scale9Sprite::getInsetTop, allow_raw_pointers())
    .function("setInsetLeft", &Scale9Sprite::setInsetLeft, allow_raw_pointers())
    .function("initWithSpriteFrame", &Scale9Sprite::initWithSpriteFrame, allow_raw_pointers())
    .function("getPreferredSize", &Scale9Sprite::getPreferredSize, allow_raw_pointers())
    .function("setCapInsets", &Scale9Sprite::setCapInsets, allow_raw_pointers())
    .function("getInsetLeft", &Scale9Sprite::getInsetLeft, allow_raw_pointers())
    .function("setInsetRight", &Scale9Sprite::setInsetRight, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Scale9Sprite>, allow_raw_pointers())
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
    // TODO: assign cc.Class.extend to ccui.Scale9Sprite.extend
    ;


  class_<EditBox, base<Widget>>("ccui.EditBox")
    .constructor<>()
    .function("getFontSize", &EditBox::getFontSize, allow_raw_pointers())
    .function("getString", &EditBox::getText, allow_raw_pointers())
    .function("setMaxLength", &EditBox::setMaxLength, allow_raw_pointers())
    .function("openKeyboard", &EditBox::openKeyboard, allow_raw_pointers())
    .function("setFontSize", &EditBox::setFontSize, allow_raw_pointers())
    .function("getInputMode", &EditBox::getInputMode, allow_raw_pointers())
    .function("initWithSizeAndBackgroundSprite", select_overload<bool(const cocos2d::Size&, cocos2d::ui::Scale9Sprite*)>(&EditBox::initWithSizeAndBackgroundSprite), allow_raw_pointers())
    .function("initWithSizeAndBackgroundSprite", select_overload<bool(const cocos2d::Size&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&EditBox::initWithSizeAndBackgroundSprite), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("initWithSizeAndBackgroundSprite", select_overload<bool(const cocos2d::Size&, cocos2d::ui::Scale9Sprite*, cocos2d::ui::Scale9Sprite*, cocos2d::ui::Scale9Sprite*)>(&EditBox::initWithSizeAndBackgroundSprite), allow_raw_pointers())
    .function("getPlaceholderFontName", &EditBox::getPlaceholderFontName, allow_raw_pointers())
    .function("setPlaceholderFontName", &EditBox::setPlaceholderFontName, allow_raw_pointers())
    .function("getPlaceholderFontSize", &EditBox::getPlaceholderFontSize, allow_raw_pointers())
    .function("getCapInsetsDisabledRenderer", &EditBox::getCapInsetsDisabledRenderer, allow_raw_pointers())
    .function("getPlaceHolder", &EditBox::getPlaceHolder, allow_raw_pointers())
    .function("setFontName", &EditBox::setFontName, allow_raw_pointers())
    .function("setString", &EditBox::setText, allow_raw_pointers())
    .function("setCapInsetsDisabledRenderer", &EditBox::setCapInsetsDisabledRenderer, allow_raw_pointers())
    .function("setPlaceholderFontSize", &EditBox::setPlaceholderFontSize, allow_raw_pointers())
    .function("loadTextureDisabled", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&EditBox::loadTextureDisabled), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setInputMode", &EditBox::setInputMode, allow_raw_pointers())
    .function("setPlaceholderFontColor", select_overload<void(const cocos2d::Color4B&)>(&EditBox::setPlaceholderFontColor), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getReturnType", &EditBox::getReturnType, allow_raw_pointers())
    .function("setFontColor", select_overload<void(const cocos2d::Color4B&)>(&EditBox::setFontColor), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getFontName", &EditBox::getFontName, allow_raw_pointers())
    .function("setCapInsetsNormalRenderer", &EditBox::setCapInsetsNormalRenderer, allow_raw_pointers())
    .function("loadTexturePressed", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&EditBox::loadTexturePressed), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getFontColor", &EditBox::getFontColor, allow_raw_pointers())
    .function("getInputFlag", &EditBox::getInputFlag, allow_raw_pointers())
    .function("initWithSizeAndTexture", &EditBox::initWithSizeAndTexture, allow_raw_pointers())
    .function("initWithSizeAndTexture", optional_override(
        [](EditBox& this_, const cocos2d::Size& arg0, const std::string& arg1){
        return this_.initWithSizeAndTexture(arg0, arg1);
      }), allow_raw_pointers())
    .function("initWithSizeAndTexture", optional_override(
        [](EditBox& this_, const cocos2d::Size& arg0, const std::string& arg1, const std::string& arg2){
        return this_.initWithSizeAndTexture(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("initWithSizeAndTexture", optional_override(
        [](EditBox& this_, const cocos2d::Size& arg0, const std::string& arg1, const std::string& arg2, const std::string& arg3){
        return this_.initWithSizeAndTexture(arg0, arg1, arg2, arg3);
      }), allow_raw_pointers())
    .function("getTextHorizontalAlignment", &EditBox::getTextHorizontalAlignment, allow_raw_pointers())
    .function("getCapInsetsNormalRenderer", &EditBox::getCapInsetsNormalRenderer, allow_raw_pointers())
    .function("getCapInsetsPressedRenderer", &EditBox::getCapInsetsPressedRenderer, allow_raw_pointers())
    .function("loadTextures", &EditBox::loadTextures, allow_raw_pointers())
    .function("loadTextures", optional_override(
        [](EditBox& this_, const std::string& arg0, const std::string& arg1){
        return this_.loadTextures(arg0, arg1);
      }), allow_raw_pointers())
    .function("loadTextures", optional_override(
        [](EditBox& this_, const std::string& arg0, const std::string& arg1, const std::string& arg2){
        return this_.loadTextures(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("setPlaceHolder", &EditBox::setPlaceHolder, allow_raw_pointers())
    .function("setInputFlag", &EditBox::setInputFlag, allow_raw_pointers())
    .function("setReturnType", &EditBox::setReturnType, allow_raw_pointers())
    .function("loadTextureNormal", select_overload<void(const std::string&, cocos2d::ui::Widget::TextureResType)>(&EditBox::loadTextureNormal), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getMaxLength", &EditBox::getMaxLength, allow_raw_pointers())
    .function("setCapInsetsPressedRenderer", &EditBox::setCapInsetsPressedRenderer, allow_raw_pointers())
    .function("setPlaceholderFont", &EditBox::setPlaceholderFont, allow_raw_pointers())
    .function("getPlaceholderFontColor", &EditBox::getPlaceholderFontColor, allow_raw_pointers())
    .function("setCapInsets", &EditBox::setCapInsets, allow_raw_pointers())
    .function("setFont", &EditBox::setFont, allow_raw_pointers())
    .function("setTextHorizontalAlignment", &EditBox::setTextHorizontalAlignment, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<EditBox>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::EditBox*(const cocos2d::Size&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&EditBox::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::EditBox*(const cocos2d::Size&, cocos2d::ui::Scale9Sprite*, cocos2d::ui::Scale9Sprite*, cocos2d::ui::Scale9Sprite*)>(&EditBox::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::EditBox*(const cocos2d::Size&, const std::string&, const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&EditBox::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const EditBox& _) -> std::string {return "EditBox";}))    
    // TODO: assign cc.Class.extend to ccui.EditBox.extend
    ;


  class_<LayoutComponent, base<Component>>("ccui.LayoutComponent")
    .constructor<>()
    .function("setStretchWidthEnabled", &LayoutComponent::setStretchWidthEnabled, allow_raw_pointers())
    .function("setPercentWidth", &LayoutComponent::setPercentWidth, allow_raw_pointers())
    .function("getAnchorPosition", &LayoutComponent::getAnchorPosition, allow_raw_pointers())
    .function("setPositionPercentXEnabled", &LayoutComponent::setPositionPercentXEnabled, allow_raw_pointers())
    .function("setStretchHeightEnabled", &LayoutComponent::setStretchHeightEnabled, allow_raw_pointers())
    .function("setActiveEnabled", &LayoutComponent::setActiveEnabled, allow_raw_pointers())
    .function("getRightMargin", &LayoutComponent::getRightMargin, allow_raw_pointers())
    .function("getSize", &LayoutComponent::getSize, allow_raw_pointers())
    .function("setAnchorPosition", &LayoutComponent::setAnchorPosition, allow_raw_pointers())
    .function("refreshLayout", &LayoutComponent::refreshLayout, allow_raw_pointers())
    .function("isPercentWidthEnabled", &LayoutComponent::isPercentWidthEnabled, allow_raw_pointers())
    .function("setVerticalEdge", &LayoutComponent::setVerticalEdge, allow_raw_pointers())
    .function("getTopMargin", &LayoutComponent::getTopMargin, allow_raw_pointers())
    .function("setSizeWidth", &LayoutComponent::setSizeWidth, allow_raw_pointers())
    .function("getLeftMargin", &LayoutComponent::getLeftMargin, allow_raw_pointers())
    .function("getVerticalEdge", &LayoutComponent::getVerticalEdge, allow_raw_pointers())
    .function("setPercentWidthEnabled", &LayoutComponent::setPercentWidthEnabled, allow_raw_pointers())
    .function("isStretchWidthEnabled", &LayoutComponent::isStretchWidthEnabled, allow_raw_pointers())
    .function("setLeftMargin", &LayoutComponent::setLeftMargin, allow_raw_pointers())
    .function("getSizeWidth", &LayoutComponent::getSizeWidth, allow_raw_pointers())
    .function("setPositionPercentYEnabled", &LayoutComponent::setPositionPercentYEnabled, allow_raw_pointers())
    .function("getSizeHeight", &LayoutComponent::getSizeHeight, allow_raw_pointers())
    .function("getPositionPercentY", &LayoutComponent::getPositionPercentY, allow_raw_pointers())
    .function("getPositionPercentX", &LayoutComponent::getPositionPercentX, allow_raw_pointers())
    .function("setTopMargin", &LayoutComponent::setTopMargin, allow_raw_pointers())
    .function("getPercentHeight", &LayoutComponent::getPercentHeight, allow_raw_pointers())
    .function("getUsingPercentContentSize", &LayoutComponent::getUsingPercentContentSize, allow_raw_pointers())
    .function("setPositionPercentY", &LayoutComponent::setPositionPercentY, allow_raw_pointers())
    .function("setPositionPercentX", &LayoutComponent::setPositionPercentX, allow_raw_pointers())
    .function("setRightMargin", &LayoutComponent::setRightMargin, allow_raw_pointers())
    .function("isPositionPercentYEnabled", &LayoutComponent::isPositionPercentYEnabled, allow_raw_pointers())
    .function("setPercentHeight", &LayoutComponent::setPercentHeight, allow_raw_pointers())
    .function("setPercentOnlyEnabled", &LayoutComponent::setPercentOnlyEnabled, allow_raw_pointers())
    .function("setHorizontalEdge", &LayoutComponent::setHorizontalEdge, allow_raw_pointers())
    .function("setPosition", &LayoutComponent::setPosition, allow_raw_pointers())
    .function("setUsingPercentContentSize", &LayoutComponent::setUsingPercentContentSize, allow_raw_pointers())
    .function("getPercentContentSize", &LayoutComponent::getPercentContentSize, allow_raw_pointers())
    .function("getPosition", &LayoutComponent::getPosition, allow_raw_pointers())
    .function("setSizeHeight", &LayoutComponent::setSizeHeight, allow_raw_pointers())
    .function("isPositionPercentXEnabled", &LayoutComponent::isPositionPercentXEnabled, allow_raw_pointers())
    .function("getBottomMargin", &LayoutComponent::getBottomMargin, allow_raw_pointers())
    .function("setPercentHeightEnabled", &LayoutComponent::setPercentHeightEnabled, allow_raw_pointers())
    .function("setPercentContentSize", &LayoutComponent::setPercentContentSize, allow_raw_pointers())
    .function("isPercentHeightEnabled", &LayoutComponent::isPercentHeightEnabled, allow_raw_pointers())
    .function("getPercentWidth", &LayoutComponent::getPercentWidth, allow_raw_pointers())
    .function("getHorizontalEdge", &LayoutComponent::getHorizontalEdge, allow_raw_pointers())
    .function("isStretchHeightEnabled", &LayoutComponent::isStretchHeightEnabled, allow_raw_pointers())
    .function("setBottomMargin", &LayoutComponent::setBottomMargin, allow_raw_pointers())
    .function("setSize", &LayoutComponent::setSize, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<LayoutComponent>, allow_raw_pointers())
    .class_function("create", &LayoutComponent::create, allow_raw_pointers())
    .class_function("bindLayoutComponent", &LayoutComponent::bindLayoutComponent, allow_raw_pointers())
    .property("_className",  optional_override([](const LayoutComponent& _) -> std::string {return "LayoutComponent";}))    
    // TODO: assign cc.Class.extend to ccui.LayoutComponent.extend
    ;

  class_<TabHeader, base<AbstractCheckButton>>("ccui.TabHeader")
    .function("getIndexInTabControl", &TabHeader::getIndexInTabControl, allow_raw_pointers())
    .function("getTitleText", &TabHeader::getTitleText, allow_raw_pointers())
    .function("setTitleFontSize", &TabHeader::setTitleFontSize, allow_raw_pointers())
    .function("setTitleFontName", &TabHeader::setTitleFontName, allow_raw_pointers())
    .function("getTitleFontSize", &TabHeader::getTitleFontSize, allow_raw_pointers())
    .function("getTitleFontName", &TabHeader::getTitleFontName, allow_raw_pointers())
    .function("getTitleColor", &TabHeader::getTitleColor, allow_raw_pointers())
    .function("getTitleRenderer", &TabHeader::getTitleRenderer, allow_raw_pointers())
    .function("setTitleText", &TabHeader::setTitleText, allow_raw_pointers())
    .function("setTitleColor", &TabHeader::setTitleColor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TabHeader*(const std::string&, const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&TabHeader::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::TabHeader*()>(&TabHeader::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TabHeader*(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, cocos2d::ui::Widget::TextureResType)>(&TabHeader::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const TabHeader& _) -> std::string {return "TabHeader";}))    
    // TODO: assign cc.Class.extend to ccui.TabHeader.extend
    ;

  class_<TabControl, base<Widget>>("ccui.TabControl")
    .function("setHeaderDockPlace", &TabControl::setHeaderDockPlace, allow_raw_pointers())
    .function("ignoreHeadersTextureSize", &TabControl::ignoreHeadersTextureSize, allow_raw_pointers())
    .function("setHeaderSelectedZoom", &TabControl::setHeaderSelectedZoom, allow_raw_pointers())
    .function("indexOfTabHeader", &TabControl::indexOfTabHeader, allow_raw_pointers())
    .function("getHeaderHeight", &TabControl::getHeaderHeight, allow_raw_pointers())
    .function("getTabCount", &TabControl::getTabCount, allow_raw_pointers())
    .function("insertTab", &TabControl::insertTab, allow_raw_pointers())
    .function("getHeaderSelectedZoom", &TabControl::getHeaderSelectedZoom, allow_raw_pointers())
    .function("setTabChangedEventListener", &TabControl::setTabChangedEventListener, allow_raw_pointers())
    .function("getTabContainer", &TabControl::getTabContainer, allow_raw_pointers())
    .function("removeTab", &TabControl::removeTab, allow_raw_pointers())
    .function("getHeaderWidth", &TabControl::getHeaderWidth, allow_raw_pointers())
    .function("setSelectTab", select_overload<void(cocos2d::ui::TabHeader*)>(&TabControl::setSelectTab), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setHeaderHeight", &TabControl::setHeaderHeight, allow_raw_pointers())
    .function("setHeaderWidth", &TabControl::setHeaderWidth, allow_raw_pointers())
    .function("getHeaderDockPlace", &TabControl::getHeaderDockPlace, allow_raw_pointers())
    .function("getSelectedTabIndex", &TabControl::getSelectedTabIndex, allow_raw_pointers())
    .function("getTabHeader", &TabControl::getTabHeader, allow_raw_pointers())
    .function("isIgnoreHeadersTextureSize", &TabControl::isIgnoreHeadersTextureSize, allow_raw_pointers())
    .class_function("create", &TabControl::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TabControl& _) -> std::string {return "TabControl";}))    
    // TODO: assign cc.Class.extend to ccui.TabControl.extend
    ;


  class_<ScrollViewBar, base<ProtectedNode>>("ccui.ScrollViewBar")
    .constructor<cocos2d::ui::ScrollView*, cocos2d::ui::ScrollView::Direction>()
    .function("setAutoHideEnabled", &ScrollViewBar::setAutoHideEnabled, allow_raw_pointers())
    .function("onScrolled", &ScrollViewBar::onScrolled, allow_raw_pointers())
    .function("isAutoHideEnabled", &ScrollViewBar::isAutoHideEnabled, allow_raw_pointers())
    .function("setAutoHideTime", &ScrollViewBar::setAutoHideTime, allow_raw_pointers())
    .function("getWidth", &ScrollViewBar::getWidth, allow_raw_pointers())
    .function("getPositionFromCorner", &ScrollViewBar::getPositionFromCorner, allow_raw_pointers())
    .function("setPositionFromCorner", &ScrollViewBar::setPositionFromCorner, allow_raw_pointers())
    .function("getAutoHideTime", &ScrollViewBar::getAutoHideTime, allow_raw_pointers())
    .function("setWidth", &ScrollViewBar::setWidth, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ScrollViewBar>, allow_raw_pointers())
    .class_function("create", &ScrollViewBar::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ScrollViewBar& _) -> std::string {return "ScrollViewBar";}))    
    // TODO: assign cc.Class.extend to ccui.ScrollViewBar.extend
    ;}