#include "scripting/cc-bindings/CCScriptBindings.h"
#include "scripting/cc-bindings/modules/ccbind_cocos2dx_ui.hpp"
#include "ui/CocosGUI.h"
#include "ui/UIScrollViewBar.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace cocos2d::ui;

COCOS_BINDINGS(ccbind_cocos2dx_ui) {


  class_<LayoutParameter>("ccui.LayoutParameter")
    .constructor(&cc_bindings_constructor<LayoutParameter>, allow_raw_pointers())
    .function("clone", &LayoutParameter::clone, allow_raw_pointers())
    .function("getLayoutType", optional_override(
        [](LayoutParameter& this_){
        return (int32_t)this_.getLayoutType();
      }))
    .function("createCloneInstance", &LayoutParameter::createCloneInstance, allow_raw_pointers())
    .function("copyProperties", &LayoutParameter::copyProperties, allow_raw_pointers())
    .class_function("create", &LayoutParameter::create, allow_raw_pointers())
    .property("_className",  optional_override([](const LayoutParameter& _) -> std::string {return "LayoutParameter";}))    
    ;


  class_<LinearLayoutParameter, base<LayoutParameter>>("ccui.LinearLayoutParameter")
    .constructor(&cc_bindings_constructor<LinearLayoutParameter>, allow_raw_pointers())
    .function("setGravity", optional_override(
        [](LinearLayoutParameter& this_, int32_t arg0){
        return this_.setGravity((cocos2d::ui::LinearLayoutParameter::LinearGravity)arg0);
      }))
    .function("getGravity", optional_override(
        [](LinearLayoutParameter& this_){
        return (int32_t)this_.getGravity();
      }))
    .class_function("create", &LinearLayoutParameter::create, allow_raw_pointers())
    .property("_className",  optional_override([](const LinearLayoutParameter& _) -> std::string {return "LinearLayoutParameter";}))    
    ;


  class_<RelativeLayoutParameter, base<LayoutParameter>>("ccui.RelativeLayoutParameter")
    .constructor(&cc_bindings_constructor<RelativeLayoutParameter>, allow_raw_pointers())
    .function("setAlign", optional_override(
        [](RelativeLayoutParameter& this_, int32_t arg0){
        return this_.setAlign((cocos2d::ui::RelativeLayoutParameter::RelativeAlign)arg0);
      }))
    .function("setRelativeToWidgetName", &RelativeLayoutParameter::setRelativeToWidgetName)
    .function("getRelativeName", &RelativeLayoutParameter::getRelativeName)
    .function("getRelativeToWidgetName", &RelativeLayoutParameter::getRelativeToWidgetName)
    .function("setRelativeName", &RelativeLayoutParameter::setRelativeName)
    .function("getAlign", optional_override(
        [](RelativeLayoutParameter& this_){
        return (int32_t)this_.getAlign();
      }))
    .class_function("create", &RelativeLayoutParameter::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RelativeLayoutParameter& _) -> std::string {return "RelativeLayoutParameter";}))    
    ;


  class_<Widget, base<ProtectedNode>>("ccui.Widget")
    .constructor(&cc_bindings_constructor<Widget>, allow_raw_pointers())
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
    .function("setPositionType", optional_override(
        [](Widget& this_, int32_t arg0){
        return this_.setPositionType((cocos2d::ui::Widget::PositionType)arg0);
      }))
    .function("isIgnoreContentAdaptWithSize", &Widget::isIgnoreContentAdaptWithSize)
    .function("getVirtualRendererSize", &Widget::getVirtualRendererSize)
    .function("isHighlighted", &Widget::isHighlighted)
    .function("addCCSEventListener", &Widget::addCCSEventListener)
    .function("getPositionType", optional_override(
        [](Widget& this_){
        return (int32_t)this_.getPositionType();
      }))
    .function("getTopBoundary", &Widget::getTopBoundary)
    .function("ignoreContentAdaptWithSize", &Widget::ignoreContentAdaptWithSize)
    .function("findNextFocusedWidget", optional_override(
        [](Widget& this_, int32_t arg0, cocos2d::ui::Widget* arg1){
        return this_.findNextFocusedWidget((cocos2d::ui::Widget::FocusDirection)arg0, arg1);
      }), allow_raw_pointers())
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
    .function("setBrightStyle", optional_override(
        [](Widget& this_, int32_t arg0){
        return this_.setBrightStyle((cocos2d::ui::Widget::BrightStyle)arg0);
      }))
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
    .function("getSizeType", optional_override(
        [](Widget& this_){
        return (int32_t)this_.getSizeType();
      }))
    .function("getCallbackType", &Widget::getCallbackType)
    .function("getTouchEndPosition", &Widget::getTouchEndPosition)
    .function("getPositionPercent", &Widget::getPositionPercent)
    .function("propagateTouchEvent", optional_override(
        [](Widget& this_, int32_t arg0, cocos2d::ui::Widget* arg1, cocos2d::Touch* arg2){
        return this_.propagateTouchEvent((cocos2d::ui::Widget::TouchEventType)arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("addClickEventListener", &Widget::addClickEventListener)
    .function("isFlippedX", &Widget::isFlippedX)
    .function("isFlippedY", &Widget::isFlippedY)
    .function("isClippingParentContainsPoint", &Widget::isClippingParentContainsPoint)
    .function("setSizeType", optional_override(
        [](Widget& this_, int32_t arg0){
        return this_.setSizeType((cocos2d::ui::Widget::SizeType)arg0);
      }))
    .function("interceptTouchEvent", optional_override(
        [](Widget& this_, int32_t arg0, cocos2d::ui::Widget* arg1, cocos2d::Touch* arg2){
        return this_.interceptTouchEvent((cocos2d::ui::Widget::TouchEventType)arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("setBright", &Widget::setBright)
    .function("setCallbackType", &Widget::setCallbackType)
    .function("isSwallowTouches", &Widget::isSwallowTouches)
    .function("ctor", &cc_bindings_ctor)
    .class_function("enableDpadNavigation", &Widget::enableDpadNavigation)
    .class_function("create", &Widget::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Widget& _) -> std::string {return "Widget";}))    
    .allow_subclass<wrapper<Widget>>("ccui.Widget._extend")
    ;


  class_<Layout, base<Widget>>("ccui.Layout")
    .constructor(&cc_bindings_constructor<Layout>, allow_raw_pointers())
    .function("setBackGroundColorVector", &Layout::setBackGroundColorVector)
    .function("setClippingType", optional_override(
        [](Layout& this_, int32_t arg0){
        return this_.setClippingType((cocos2d::ui::Layout::ClippingType)arg0);
      }))
    .function("setBackGroundColorType", optional_override(
        [](Layout& this_, int32_t arg0){
        return this_.setBackGroundColorType((cocos2d::ui::Layout::BackGroundColorType)arg0);
      }))
    .function("setLoopFocus", &Layout::setLoopFocus)
    .function("setBackGroundImageColor", &Layout::setBackGroundImageColor)
    .function("getBackGroundColorVector", &Layout::getBackGroundColorVector)
    .function("getClippingType", optional_override(
        [](Layout& this_){
        return (int32_t)this_.getClippingType();
      }))
    .function("getRenderFile", &Layout::getRenderFile)
    .function("isLoopFocus", &Layout::isLoopFocus)
    .function("removeBackGroundImage", &Layout::removeBackGroundImage)
    .function("getBackGroundColorOpacity", &Layout::getBackGroundColorOpacity)
    .function("isClippingEnabled", &Layout::isClippingEnabled)
    .function("setBackGroundImageOpacity", &Layout::setBackGroundImageOpacity)
    .function("setBackGroundImage", optional_override(
        [](Layout& this_, const std::string& arg0, int32_t arg1){
        return this_.setBackGroundImage(arg0, (cocos2d::ui::Widget::TextureResType)arg1);
      }))
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
    .function("getBackGroundColorType", optional_override(
        [](Layout& this_){
        return (int32_t)this_.getBackGroundColorType();
      }))
    .function("getBackGroundEndColor", &Layout::getBackGroundEndColor)
    .function("setBackGroundColorOpacity", &Layout::setBackGroundColorOpacity)
    .function("getBackGroundImageOpacity", &Layout::getBackGroundImageOpacity)
    .function("isPassFocusToChild", &Layout::isPassFocusToChild)
    .function("setBackGroundImageCapInsets", &Layout::setBackGroundImageCapInsets)
    .function("getBackGroundImageTextureSize", &Layout::getBackGroundImageTextureSize)
    .function("forceDoLayout", &Layout::forceDoLayout)
    .function("getLayoutType", optional_override(
        [](Layout& this_){
        return (int32_t)this_.getLayoutType();
      }))
    .function("setPassFocusToChild", &Layout::setPassFocusToChild)
    .function("getBackGroundStartColor", &Layout::getBackGroundStartColor)
    .function("setBackGroundImageScale9Enabled", &Layout::setBackGroundImageScale9Enabled)
    .function("setLayoutType", optional_override(
        [](Layout& this_, int32_t arg0){
        return this_.setLayoutType((cocos2d::ui::Layout::Type)arg0);
      }))
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", &Layout::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Layout& _) -> std::string {return "Layout";}))    
    .allow_subclass<wrapper<Layout>>("ccui.Layout._extend")
    ;


  class_<Button, base<Widget>>("ccui.Button")
    .constructor(&cc_bindings_constructor<Button>, allow_raw_pointers())
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
    .function("setTitleAlignment", optional_override(
        [](Button& this_, int32_t arg0, int32_t arg1){
            return this_.setTitleAlignment((cocos2d::TextHAlignment)arg0, (cocos2d::TextVAlignment)arg1);
        }))
    .function("setTitleAlignment", optional_override(
        [](Button& this_, int32_t arg0){
            return this_.setTitleAlignment((cocos2d::TextHAlignment)arg0);
        }))
    .function("getCapInsetsPressedRenderer", &Button::getCapInsetsPressedRenderer)
    .function("loadTextures", optional_override(
        [](Button& this_, const std::string& arg0, const std::string& arg1, const std::string& arg2, int32_t arg3){
        return this_.loadTextures(arg0, arg1, arg2, (cocos2d::ui::Widget::TextureResType)arg3);
      }))
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
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", optional_override(
        [](const std::string& arg0, const std::string& arg1, const std::string& arg2, int32_t arg3){
            return Button::create(arg0, arg1, arg2, (cocos2d::ui::Widget::TextureResType)arg3);
        }), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::Button*()>(&Button::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Button& _) -> std::string {return "Button";}))    
    .allow_subclass<wrapper<Button>>("ccui.Button._extend")
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
    .function("loadTextures", optional_override(
        [](AbstractCheckButton& this_, const std::string& arg0, const std::string& arg1, const std::string& arg2, const std::string& arg3, const std::string& arg4, int32_t arg5){
        return this_.loadTextures(arg0, arg1, arg2, arg3, arg4, (cocos2d::ui::Widget::TextureResType)arg5);
      }))
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
    .constructor(&cc_bindings_constructor<CheckBox>, allow_raw_pointers())
    .function("addEventListener", &CheckBox::addEventListener)
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", optional_override(
        [](const std::string& arg0, const std::string& arg1, const std::string& arg2, const std::string& arg3, const std::string& arg4, int32_t arg5){
            return CheckBox::create(arg0, arg1, arg2, arg3, arg4, (cocos2d::ui::Widget::TextureResType)arg5);
        }), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::CheckBox*()>(&CheckBox::create), allow_raw_pointers())
    .class_function("create", optional_override(
        [](const std::string& arg0, const std::string& arg1, int32_t arg2){
            return CheckBox::create(arg0, arg1, (cocos2d::ui::Widget::TextureResType)arg2);
        }), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const CheckBox& _) -> std::string {return "CheckBox";}))    
    .allow_subclass<wrapper<CheckBox>>("ccui.CheckBox._extend")
    ;


  class_<RadioButton, base<AbstractCheckButton>>("ccui.RadioButton")
    .constructor(&cc_bindings_constructor<RadioButton>, allow_raw_pointers())
    .function("addEventListener", &RadioButton::addEventListener)
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", optional_override(
        [](const std::string& arg0, const std::string& arg1, const std::string& arg2, const std::string& arg3, const std::string& arg4, int32_t arg5){
            return RadioButton::create(arg0, arg1, arg2, arg3, arg4, (cocos2d::ui::Widget::TextureResType)arg5);
        }), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::RadioButton*()>(&RadioButton::create), allow_raw_pointers())
    .class_function("create", optional_override(
        [](const std::string& arg0, const std::string& arg1, int32_t arg2){
            return RadioButton::create(arg0, arg1, (cocos2d::ui::Widget::TextureResType)arg2);
        }), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const RadioButton& _) -> std::string {return "RadioButton";}))    
    .allow_subclass<wrapper<RadioButton>>("ccui.RadioButton._extend")
    ;


  class_<RadioButtonGroup, base<Widget>>("ccui.RadioButtonGroup")
    .constructor(&cc_bindings_constructor<RadioButtonGroup>, allow_raw_pointers())
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
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", &RadioButtonGroup::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RadioButtonGroup& _) -> std::string {return "RadioButtonGroup";}))    
    .allow_subclass<wrapper<RadioButtonGroup>>("ccui.RadioButtonGroup._extend")
    ;


  class_<ImageView, base<Widget>>("ccui.ImageView")
    .constructor(&cc_bindings_constructor<ImageView>, allow_raw_pointers())
    .function("getBlendFunc", &ImageView::getBlendFunc)
    .function("setBlendFunc", &ImageView::setBlendFunc)
    .function("setScale9Enabled", &ImageView::setScale9Enabled)
    .function("setTextureRect", &ImageView::setTextureRect)
    .function("setCapInsets", &ImageView::setCapInsets)
    .function("getRenderFile", &ImageView::getRenderFile)
    .function("getCapInsets", &ImageView::getCapInsets)
    .function("isScale9Enabled", &ImageView::isScale9Enabled)
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", optional_override(
        [](const std::string& arg0, int32_t arg1){
            return ImageView::create(arg0, (cocos2d::ui::Widget::TextureResType)arg1);
        }), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::ImageView*()>(&ImageView::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ImageView& _) -> std::string {return "ImageView";}))    
    .allow_subclass<wrapper<ImageView>>("ccui.ImageView._extend")
    ;


  class_<Text, base<Widget>>("ccui.Text")
    .constructor(&cc_bindings_constructor<Text>, allow_raw_pointers())
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
    .function("disableEffect", optional_override(
        [](Text& this_, int32_t arg0){
            return this_.disableEffect((cocos2d::LabelEffect)arg0);
        }))
    .function("disableEffect", select_overload<void()>(&Text::disableEffect))
    .function("getLabelEffectType", optional_override(
        [](Text& this_){
        return (int32_t)this_.getLabelEffectType();
      }))
    .function("getTextColor", &Text::getTextColor)
    .function("getBlendFunc", &Text::getBlendFunc)
    .function("setTextVerticalAlignment", optional_override(
        [](Text& this_, int32_t arg0){
        return this_.setTextVerticalAlignment((cocos2d::TextVAlignment)arg0);
      }))
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
    .function("getType", optional_override(
        [](Text& this_){
        return (int32_t)this_.getType();
      }))
    .function("getTextHorizontalAlignment", optional_override(
        [](Text& this_){
        return (int32_t)this_.getTextHorizontalAlignment();
      }))
    .function("isShadowEnabled", &Text::isShadowEnabled)
    .function("setFontSize", &Text::setFontSize)
    .function("getShadowColor", &Text::getShadowColor)
    .function("setTextColor", &Text::setTextColor)
    .function("enableGlow", &Text::enableGlow)
    .function("getLetter", &Text::getLetter, allow_raw_pointers())
    .function("setBlendFunc", &Text::setBlendFunc)
    .function("getTextVerticalAlignment", optional_override(
        [](Text& this_){
        return (int32_t)this_.getTextVerticalAlignment();
      }))
    .function("getTextAreaSize", &Text::getTextAreaSize)
    .function("setTextHorizontalAlignment", optional_override(
        [](Text& this_, int32_t arg0){
        return this_.setTextHorizontalAlignment((cocos2d::TextHAlignment)arg0);
      }))
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", select_overload<cocos2d::ui::Text*(const std::string&, const std::string&, float)>(&Text::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::Text*()>(&Text::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Text& _) -> std::string {return "Text";}))    
    .allow_subclass<wrapper<Text>>("ccui.Text._extend")
    ;


  class_<TextAtlas, base<Widget>>("ccui.TextAtlas")
    .constructor(&cc_bindings_constructor<TextAtlas>, allow_raw_pointers())
    .function("getStringLength", &TextAtlas::getStringLength)
    .function("getString", &TextAtlas::getString)
    .function("setString", &TextAtlas::setString)
    .function("getRenderFile", &TextAtlas::getRenderFile)
    .function("setProperty", &TextAtlas::setProperty)
    .function("adaptRenderers", &TextAtlas::adaptRenderers)
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", select_overload<cocos2d::ui::TextAtlas*(const std::string&, const std::string&, int, int, const std::string&)>(&TextAtlas::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TextAtlas*()>(&TextAtlas::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TextAtlas& _) -> std::string {return "TextAtlas";}))    
    .allow_subclass<wrapper<TextAtlas>>("ccui.TextAtlas._extend")
    ;


  class_<LoadingBar, base<Widget>>("ccui.LoadingBar")
    .constructor(&cc_bindings_constructor<LoadingBar>, allow_raw_pointers())
    .function("setPercent", &LoadingBar::setPercent)
    .function("setDirection", optional_override(
        [](LoadingBar& this_, int32_t arg0){
        return this_.setDirection((cocos2d::ui::LoadingBar::Direction)arg0);
      }))
    .function("getRenderFile", &LoadingBar::getRenderFile)
    .function("setScale9Enabled", &LoadingBar::setScale9Enabled)
    .function("setCapInsets", &LoadingBar::setCapInsets)
    .function("getDirection", optional_override(
        [](LoadingBar& this_){
        return (int32_t)this_.getDirection();
      }))
    .function("getCapInsets", &LoadingBar::getCapInsets)
    .function("isScale9Enabled", &LoadingBar::isScale9Enabled)
    .function("getPercent", &LoadingBar::getPercent)
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", select_overload<cocos2d::ui::LoadingBar*(const std::string&, float)>(&LoadingBar::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::LoadingBar*()>(&LoadingBar::create), allow_raw_pointers())
    .class_function("create", optional_override(
        [](const std::string& arg0, int32_t arg1, float arg2){
            return LoadingBar::create(arg0, (cocos2d::ui::Widget::TextureResType)arg1, arg2);
        }), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const LoadingBar& _) -> std::string {return "LoadingBar";}))    
    .allow_subclass<wrapper<LoadingBar>>("ccui.LoadingBar._extend")
    ;


  class_<ScrollView, base<Layout>>("ccui.ScrollView")
    .constructor(&cc_bindings_constructor<ScrollView>, allow_raw_pointers())
    .function("scrollToTop", &ScrollView::scrollToTop)
    .function("scrollToPercentHorizontal", &ScrollView::scrollToPercentHorizontal)
    .function("setScrollBarOpacity", &ScrollView::setScrollBarOpacity)
    .function("setScrollBarEnabled", &ScrollView::setScrollBarEnabled)
    .function("isInertiaScrollEnabled", &ScrollView::isInertiaScrollEnabled)
    .function("scrollToBottom", &ScrollView::scrollToBottom)
    .function("getScrolledPercentBothDirection", &ScrollView::getScrolledPercentBothDirection)
    .function("getDirection", optional_override(
        [](ScrollView& this_){
        return (int32_t)this_.getDirection();
      }))
    .function("setScrollBarColor", &ScrollView::setScrollBarColor)
    .function("scrollToBottomLeft", &ScrollView::scrollToBottomLeft)
    .function("getInnerContainer", &ScrollView::getInnerContainer, allow_raw_pointers())
    .function("jumpToBottom", &ScrollView::jumpToBottom)
    .function("setInnerContainerPosition", &ScrollView::setInnerContainerPosition)
    .function("setDirection", optional_override(
        [](ScrollView& this_, int32_t arg0){
        return this_.setDirection((cocos2d::ui::ScrollView::Direction)arg0);
      }))
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
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", &ScrollView::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ScrollView& _) -> std::string {return "ScrollView";}))    
    .allow_subclass<wrapper<ScrollView>>("ccui.ScrollView._extend")
    ;


  class_<ListView, base<ScrollView>>("ccui.ListView")
    .constructor(&cc_bindings_constructor<ListView>, allow_raw_pointers())
    .function("setGravity", optional_override(
        [](ListView& this_, int32_t arg0){
        return this_.setGravity((cocos2d::ui::ListView::Gravity)arg0);
      }))
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
    .function("setMagneticType", optional_override(
        [](ListView& this_, int32_t arg0){
        return this_.setMagneticType((cocos2d::ui::ListView::MagneticType)arg0);
      }))
    .function("setMagneticAllowedOutOfBoundary", &ListView::setMagneticAllowedOutOfBoundary)
    .function("addEventListener", select_overload<void(const ListView::ccListViewCallback&)>(&ListView::addEventListener))
    .function("doLayout", &ListView::doLayout)
    .function("getTopmostItemInCurrentView", &ListView::getTopmostItemInCurrentView, allow_raw_pointers())
    .function("setPadding", &ListView::setPadding)
    .function("removeAllItems", &ListView::removeAllItems)
    .function("getRightPadding", &ListView::getRightPadding)
    .function("getBottommostItemInCurrentView", &ListView::getBottommostItemInCurrentView, allow_raw_pointers())
    .function("getItems", &ListView::getItems)
    .function("getLeftmostItemInCurrentView", &ListView::getLeftmostItemInCurrentView, allow_raw_pointers())
    .function("setItemsMargin", &ListView::setItemsMargin)
    .function("getMagneticType", optional_override(
        [](ListView& this_){
        return (int32_t)this_.getMagneticType();
      }))
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
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", &ListView::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ListView& _) -> std::string {return "ListView";}))    
    .allow_subclass<wrapper<ListView>>("ccui.ListView._extend")
    ;


  class_<Slider, base<Widget>>("ccui.Slider")
    .constructor(&cc_bindings_constructor<Slider>, allow_raw_pointers())
    .function("setPercent", &Slider::setPercent)
    .function("getMaxPercent", &Slider::getMaxPercent)
    .function("getBallNormalFile", &Slider::getBallNormalFile)
    .function("getSlidBallDisabledRenderer", &Slider::getSlidBallDisabledRenderer, allow_raw_pointers())
    .function("setScale9Enabled", &Slider::setScale9Enabled)
    .function("getBallPressedFile", &Slider::getBallPressedFile)
    .function("getZoomScale", &Slider::getZoomScale)
    .function("setCapInsetProgressBarRenderer", &Slider::setCapInsetProgressBarRenderer)
    .function("loadSlidBallTextures", optional_override(
        [](Slider& this_, const std::string& arg0, const std::string& arg1, const std::string& arg2, int32_t arg3){
        return this_.loadSlidBallTextures(arg0, arg1, arg2, (cocos2d::ui::Widget::TextureResType)arg3);
      }))
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
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", optional_override(
        [](const std::string& arg0, const std::string& arg1, int32_t arg2){
            return Slider::create(arg0, arg1, (cocos2d::ui::Widget::TextureResType)arg2);
        }), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::Slider*()>(&Slider::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Slider& _) -> std::string {return "Slider";}))    
    .allow_subclass<wrapper<Slider>>("ccui.Slider._extend")
    ;


  class_<UICCTextField, base<TextFieldTTF>>("ccui.UICCTextField")
    .constructor(&cc_bindings_constructor<UICCTextField>, allow_raw_pointers())
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
    .constructor(&cc_bindings_constructor<TextField>, allow_raw_pointers())
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
    .function("setTextVerticalAlignment", optional_override(
        [](TextField& this_, int32_t arg0){
        return this_.setTextVerticalAlignment((cocos2d::TextVAlignment)arg0);
      }))
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
    .function("getTextHorizontalAlignment", optional_override(
        [](TextField& this_){
        return (int32_t)this_.getTextHorizontalAlignment();
      }))
    .function("setFontSize", &TextField::setFontSize)
    .function("setPlaceHolder", &TextField::setPlaceHolder)
    .function("setCursorFromPoint", &TextField::setCursorFromPoint, allow_raw_pointers())
    .function("setPlaceHolderColor", select_overload<void(const cocos2d::Color4B&)>(&TextField::setPlaceHolderColor))
    // TODO: Only support function overloading with different number of parameters
    .function("setTextHorizontalAlignment", optional_override(
        [](TextField& this_, int32_t arg0){
        return this_.setTextHorizontalAlignment((cocos2d::TextHAlignment)arg0);
      }))
    .function("setTextColor", &TextField::setTextColor)
    .function("setCursorChar", &TextField::setCursorChar)
    .function("getMaxLength", &TextField::getMaxLength)
    .function("isMaxLengthEnabled", &TextField::isMaxLengthEnabled)
    .function("setDetachWithIME", &TextField::setDetachWithIME)
    .function("getTextVerticalAlignment", optional_override(
        [](TextField& this_){
        return (int32_t)this_.getTextVerticalAlignment();
      }))
    .function("setTouchAreaEnabled", &TextField::setTouchAreaEnabled)
    .function("setMaxLength", &TextField::setMaxLength)
    .function("setCursorEnabled", &TextField::setCursorEnabled)
    .function("setTouchSize", &TextField::setTouchSize)
    .function("getTouchSize", &TextField::getTouchSize)
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", select_overload<cocos2d::ui::TextField*(const std::string&, const std::string&, int)>(&TextField::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TextField*()>(&TextField::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TextField& _) -> std::string {return "TextField";}))    
    .allow_subclass<wrapper<TextField>>("ccui.TextField._extend")
    ;


  class_<TextBMFont, base<Widget>>("ccui.TextBMFont")
    .constructor(&cc_bindings_constructor<TextBMFont>, allow_raw_pointers())
    .function("getStringLength", &TextBMFont::getStringLength)
    .function("getString", &TextBMFont::getString)
    .function("setString", &TextBMFont::setString)
    .function("getRenderFile", &TextBMFont::getRenderFile)
    .function("setFntFile", &TextBMFont::setFntFile)
    .function("resetRender", &TextBMFont::resetRender)
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", select_overload<cocos2d::ui::TextBMFont*(const std::string&, const std::string&)>(&TextBMFont::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::TextBMFont*()>(&TextBMFont::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TextBMFont& _) -> std::string {return "TextBMFont";}))    
    .allow_subclass<wrapper<TextBMFont>>("ccui.TextBMFont._extend")
    ;


  class_<PageView, base<ListView>>("ccui.PageView")
    .constructor(&cc_bindings_constructor<PageView>, allow_raw_pointers())
    .function("setIndicatorSpaceBetweenIndexNodes", &PageView::setIndicatorSpaceBetweenIndexNodes)
    .function("insertPage", &PageView::insertPage, allow_raw_pointers())
    .function("setIndicatorIndexNodesOpacity", &PageView::setIndicatorIndexNodesOpacity)
    .function("setIndicatorSelectedIndexOpacity", &PageView::setIndicatorSelectedIndexOpacity)
    .function("removeAllPages", &PageView::removeAllPages)
    .function("setAutoScrollStopEpsilon", &PageView::setAutoScrollStopEpsilon)
    .function("setIndicatorIndexNodesScale", &PageView::setIndicatorIndexNodesScale)
    .function("setIndicatorEnabled", &PageView::setIndicatorEnabled)
    .function("setIndicatorSelectedIndexColor", &PageView::setIndicatorSelectedIndexColor)
    .function("addEventListener", select_overload<void(const PageView::ccPageViewCallback&)>(&PageView::addEventListener))
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
    .function("setIndicatorIndexNodesTexture", optional_override(
        [](PageView& this_, const std::string& arg0, int32_t arg1){
        return this_.setIndicatorIndexNodesTexture(arg0, (cocos2d::ui::Widget::TextureResType)arg1);
      }))
    .function("setIndicatorIndexNodesTexture", optional_override(
        [](PageView& this_, const std::string& arg0){
        return this_.setIndicatorIndexNodesTexture(arg0);
      }))
    .function("getIndicatorEnabled", &PageView::getIndicatorEnabled)
    .function("removePageAtIndex", &PageView::removePageAtIndex)
    .function("getIndicatorSpaceBetweenIndexNodes", &PageView::getIndicatorSpaceBetweenIndexNodes)
    .function("addPage", &PageView::addPage, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", &PageView::create, allow_raw_pointers())
    .property("_className",  optional_override([](const PageView& _) -> std::string {return "PageView";}))    
    .allow_subclass<wrapper<PageView>>("ccui.PageView._extend")
    ;

  class_<Helper>("ccui.Helper")
    .class_function("getSubStringOfUTF8String", &Helper::getSubStringOfUTF8String)
    .class_function("convertBoundingBoxToScreen", &Helper::convertBoundingBoxToScreen, allow_raw_pointers())
    .class_function("changeLayoutSystemActiveState", &Helper::changeLayoutSystemActiveState)
    .class_function("seekActionWidgetByActionTag", &Helper::seekActionWidgetByActionTag, allow_raw_pointers())
    .class_function("seekWidgetByName", &Helper::seekWidgetByName, allow_raw_pointers())
    .class_function("seekWidgetByTag", &Helper::seekWidgetByTag, allow_raw_pointers())
    .class_function("restrictCapInsetRect", &Helper::restrictCapInsetRect)
    .class_function("doLayout", &Helper::doLayout, allow_raw_pointers())
    .property("_className",  optional_override([](const Helper& _) -> std::string {return "Helper";}))    
    ;


  class_<RichElement>("ccui.RichElement")
    .constructor(&cc_bindings_constructor<RichElement>, allow_raw_pointers())
    .function("equalType", optional_override(
        [](RichElement& this_, int32_t arg0){
        return this_.equalType((cocos2d::ui::RichElement::Type)arg0);
      }))
    .function("init", &RichElement::init)
    .function("setColor", &RichElement::setColor)
    .function("ctor", &cc_bindings_ctor)
    .property("_className",  optional_override([](const RichElement& _) -> std::string {return "RichElement";}))    
    .allow_subclass<wrapper<RichElement>>("ccui.RichElement._extend")
    ;


  class_<RichElementText, base<RichElement>>("ccui.RichElementText")
    .constructor(&cc_bindings_constructor<RichElementText>, allow_raw_pointers())
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
    .function("ctor", &cc_bindings_ctor)
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
    .allow_subclass<wrapper<RichElementText>>("ccui.RichElementText._extend")
    ;


  class_<RichElementImage, base<RichElement>>("ccui.RichElementImage")
    .constructor(&cc_bindings_constructor<RichElementImage>, allow_raw_pointers())
    .function("setHeight", &RichElementImage::setHeight)
    .function("init", optional_override(
        [](RichElementImage& this_, int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, int32_t arg5){
        return this_.init(arg0, arg1, arg2, arg3, arg4, (cocos2d::ui::Widget::TextureResType)arg5);
      }))
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
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", optional_override(
      [](int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4, int32_t arg5){
        return RichElementImage::create(arg0, arg1, arg2, arg3, arg4, (cocos2d::ui::Widget::TextureResType)arg5);
      }), allow_raw_pointers())
    .class_function("create", optional_override(
      [](int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3){
        return RichElementImage::create(arg0, arg1, arg2, arg3);
      }), allow_raw_pointers())
    .class_function("create", optional_override(
      [](int arg0, const cocos2d::Color3B& arg1, unsigned char arg2, const std::string& arg3, const std::string& arg4){
        return RichElementImage::create(arg0, arg1, arg2, arg3, arg4);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const RichElementImage& _) -> std::string {return "RichElementImage";}))    
    .allow_subclass<wrapper<RichElementImage>>("ccui.RichElementImage._extend")
    ;


  class_<RichElementCustomNode, base<RichElement>>("ccui.RichElementCustomNode")
    .constructor(&cc_bindings_constructor<RichElementCustomNode>, allow_raw_pointers())
    .function("init", &RichElementCustomNode::init, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", &RichElementCustomNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RichElementCustomNode& _) -> std::string {return "RichElementCustomNode";}))    
    .allow_subclass<wrapper<RichElementCustomNode>>("ccui.RichElementCustomNode._extend")
    ;


  class_<RichElementNewLine, base<RichElement>>("ccui.RichElementNewLine")
    .constructor(&cc_bindings_constructor<RichElementNewLine>, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", &RichElementNewLine::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RichElementNewLine& _) -> std::string {return "RichElementNewLine";}))    
    .allow_subclass<wrapper<RichElementNewLine>>("ccui.RichElementNewLine._extend")
    ;


  class_<RichText, base<Widget>>("ccui.RichText")
    .constructor(&cc_bindings_constructor<RichText>, allow_raw_pointers())
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
    .function("getHorizontalAlignment", optional_override(
        [](RichText& this_){
        return (int32_t)this_.getHorizontalAlignment();
      }))
    .function("setHorizontalAlignment", optional_override(
        [](RichText& this_, int32_t arg0){
        return this_.setHorizontalAlignment((cocos2d::ui::RichText::HorizontalAlignment)arg0);
      }))
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
    .function("setWrapMode", optional_override(
        [](RichText& this_, int32_t arg0){
        return this_.setWrapMode((cocos2d::ui::RichText::WrapMode)arg0);
      }))
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
    .function("getWrapMode", optional_override(
        [](RichText& this_){
        return (int32_t)this_.getWrapMode();
      }))
    .function("setAnchorTextUnderline", &RichText::setAnchorTextUnderline)
    .function("color3BWithString", &RichText::color3BWithString)
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", &RichText::create, allow_raw_pointers())
    .class_function("createWithXML", &RichText::createWithXML, allow_raw_pointers())
    .class_function("createWithXML", optional_override(
      [](const std::string& arg0, const std::unordered_map<std::string, cocos2d::Value>& arg1){
        return RichText::createWithXML(arg0, arg1);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const RichText& _) -> std::string {return "RichText";}))    
    .allow_subclass<wrapper<RichText>>("ccui.RichText._extend")
    ;


  class_<HBox, base<Layout>>("ccui.HBox")
    .constructor(&cc_bindings_constructor<HBox>, allow_raw_pointers())
    .function("initWithSize", &HBox::initWithSize)
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", select_overload<cocos2d::ui::HBox*(const cocos2d::Size&)>(&HBox::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::HBox*()>(&HBox::create), allow_raw_pointers())
    .property("_className",  optional_override([](const HBox& _) -> std::string {return "HBox";}))    
    .allow_subclass<wrapper<HBox>>("ccui.HBox._extend")
    ;


  class_<VBox, base<Layout>>("ccui.VBox")
    .constructor(&cc_bindings_constructor<VBox>, allow_raw_pointers())
    .function("initWithSize", &VBox::initWithSize)
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", select_overload<cocos2d::ui::VBox*(const cocos2d::Size&)>(&VBox::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::VBox*()>(&VBox::create), allow_raw_pointers())
    .property("_className",  optional_override([](const VBox& _) -> std::string {return "VBox";}))    
    .allow_subclass<wrapper<VBox>>("ccui.VBox._extend")
    ;


  class_<RelativeBox, base<Layout>>("ccui.RelativeBox")
    .constructor(&cc_bindings_constructor<RelativeBox>, allow_raw_pointers())
    .function("initWithSize", &RelativeBox::initWithSize)
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", select_overload<cocos2d::ui::RelativeBox*(const cocos2d::Size&)>(&RelativeBox::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::RelativeBox*()>(&RelativeBox::create), allow_raw_pointers())
    .property("_className",  optional_override([](const RelativeBox& _) -> std::string {return "RelativeBox";}))    
    .allow_subclass<wrapper<RelativeBox>>("ccui.RelativeBox._extend")
    ;


  class_<Scale9Sprite, base<Sprite>>("ccui.Scale9Sprite")
    .constructor(&cc_bindings_constructor<Scale9Sprite>, allow_raw_pointers())
    .function("updateWithSprite", select_overload<bool(cocos2d::Sprite*, const cocos2d::Rect&, bool, const cocos2d::Vec2&, const cocos2d::Size&, const cocos2d::Rect&)>(&Scale9Sprite::updateWithSprite), allow_raw_pointers())
    .function("updateWithSprite", select_overload<bool(cocos2d::Sprite*, const cocos2d::Rect&, bool, const cocos2d::Rect&)>(&Scale9Sprite::updateWithSprite), allow_raw_pointers())
    .function("resizableSpriteWithCapInsets", &Scale9Sprite::resizableSpriteWithCapInsets, allow_raw_pointers())
    .function("getCapInsets", &Scale9Sprite::getCapInsets)
    .function("setState", optional_override(
        [](Scale9Sprite& this_, int32_t arg0){
        return this_.setState((cocos2d::ui::Scale9Sprite::State)arg0);
      }))
    .function("setInsetBottom", &Scale9Sprite::setInsetBottom)
    .function("getSprite", &Scale9Sprite::getSprite, allow_raw_pointers())
    .function("setInsetTop", &Scale9Sprite::setInsetTop)
    .function("setRenderingType", optional_override(
        [](Scale9Sprite& this_, int32_t arg0){
        return this_.setRenderingType((cocos2d::ui::Scale9Sprite::RenderingType)arg0);
      }))
    .function("init", select_overload<bool(cocos2d::Sprite*, const cocos2d::Rect&, const cocos2d::Rect&)>(&Scale9Sprite::init), allow_raw_pointers())
    .function("init", select_overload<bool(cocos2d::Sprite*, const cocos2d::Rect&, bool, const cocos2d::Rect&)>(&Scale9Sprite::init), allow_raw_pointers())
    .function("init", select_overload<bool(cocos2d::Sprite*, const cocos2d::Rect&, bool, const cocos2d::Vec2&, const cocos2d::Size&, const cocos2d::Rect&)>(&Scale9Sprite::init), allow_raw_pointers())
    .function("setPreferredSize", &Scale9Sprite::setPreferredSize)
    .function("copyTo", &Scale9Sprite::copyTo, allow_raw_pointers())
    .function("setSpriteFrame", select_overload<void(SpriteFrame *, const Rect&)>(&Scale9Sprite::setSpriteFrame), allow_raw_pointers())
    .function("getState", optional_override(
        [](Scale9Sprite& this_){
        return (int32_t)this_.getState();
      }))
    .function("getInsetBottom", &Scale9Sprite::getInsetBottom)
    .function("setScale9Enabled", &Scale9Sprite::setScale9Enabled)
    .function("isScale9Enabled", &Scale9Sprite::isScale9Enabled)
    .function("resetRender", &Scale9Sprite::resetRender)
    .function("getRenderingType", optional_override(
        [](Scale9Sprite& this_){
        return (int32_t)this_.getRenderingType();
      }))
    .function("getInsetRight", &Scale9Sprite::getInsetRight)
    .function("getOriginalSize", &Scale9Sprite::getOriginalSize)
    .function("initWithFile", select_overload<bool(const cocos2d::Rect&, const std::string&)>(&Scale9Sprite::initWithFile))
    .function("initWithFile", select_overload<bool(const std::string&, const cocos2d::Rect&, const cocos2d::Rect&)>(&Scale9Sprite::initWithFile))
    .function("getInsetTop", &Scale9Sprite::getInsetTop)
    .function("setInsetLeft", &Scale9Sprite::setInsetLeft)
    .function("initWithSpriteFrame", select_overload<bool(SpriteFrame*, const Rect&)>(&Scale9Sprite::initWithSpriteFrame), allow_raw_pointers())
    .function("getPreferredSize", &Scale9Sprite::getPreferredSize)
    .function("setCapInsets", &Scale9Sprite::setCapInsets)
    .function("getInsetLeft", &Scale9Sprite::getInsetLeft)
    .function("setInsetRight", &Scale9Sprite::setInsetRight)
    .function("ctor", &cc_bindings_ctor)
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
    .allow_subclass<wrapper<Scale9Sprite>>("ccui.Scale9Sprite._extend")
    ;


  class_<EditBox, base<Widget>>("ccui.EditBox")
    .constructor(&cc_bindings_constructor<EditBox>, allow_raw_pointers())
    .function("getFontSize", &EditBox::getFontSize)
    .function("getString", &EditBox::getText, allow_raw_pointers())
    .function("setMaxLength", &EditBox::setMaxLength)
    .function("openKeyboard", &EditBox::openKeyboard)
    .function("setFontSize", &EditBox::setFontSize)
    .function("getInputMode", optional_override(
        [](EditBox& this_){
        return (int32_t)this_.getInputMode();
      }))
    .function("initWithSizeAndBackgroundSprite", select_overload<bool(const cocos2d::Size&, cocos2d::ui::Scale9Sprite*)>(&EditBox::initWithSizeAndBackgroundSprite), allow_raw_pointers())
    .function("initWithSizeAndBackgroundSprite", optional_override(
        [](EditBox& this_, const cocos2d::Size& arg0, const std::string& arg1, int32_t arg2){
            return this_.initWithSizeAndBackgroundSprite(arg0, arg1, (cocos2d::ui::Widget::TextureResType)arg2);
        }))
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
    .function("setInputMode", optional_override(
        [](EditBox& this_, int32_t arg0){
        return this_.setInputMode((cocos2d::ui::EditBox::InputMode)arg0);
      }))
    .function("setPlaceholderFontColor", select_overload<void(const cocos2d::Color4B&)>(&EditBox::setPlaceholderFontColor))
    // TODO: Only support function overloading with different number of parameters
    .function("getReturnType", optional_override(
        [](EditBox& this_){
        return (int32_t)this_.getReturnType();
      }))
    .function("setFontColor", select_overload<void(const cocos2d::Color4B&)>(&EditBox::setFontColor))
    // TODO: Only support function overloading with different number of parameters
    .function("getFontName", &EditBox::getFontName, allow_raw_pointers())
    .function("setCapInsetsNormalRenderer", &EditBox::setCapInsetsNormalRenderer)
    .function("getFontColor", &EditBox::getFontColor)
    .function("getInputFlag", optional_override(
        [](EditBox& this_){
        return (int32_t)this_.getInputFlag();
      }))
    .function("initWithSizeAndTexture", optional_override(
        [](EditBox& this_, const cocos2d::Size& arg0, const std::string& arg1, const std::string& arg2, const std::string& arg3, int32_t arg4){
        return this_.initWithSizeAndTexture(arg0, arg1, arg2, arg3, (cocos2d::ui::Widget::TextureResType)arg4);
      }))
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
    .function("getTextHorizontalAlignment", optional_override(
        [](EditBox& this_){
        return (int32_t)this_.getTextHorizontalAlignment();
      }))
    .function("getCapInsetsNormalRenderer", &EditBox::getCapInsetsNormalRenderer)
    .function("getCapInsetsPressedRenderer", &EditBox::getCapInsetsPressedRenderer)
    .function("loadTextures", optional_override(
        [](EditBox& this_, const std::string& arg0, const std::string& arg1, const std::string& arg2, int32_t arg3){
        return this_.loadTextures(arg0, arg1, arg2, (cocos2d::ui::Widget::TextureResType)arg3);
      }))
    .function("loadTextures", optional_override(
        [](EditBox& this_, const std::string& arg0, const std::string& arg1){
        return this_.loadTextures(arg0, arg1);
      }))
    .function("loadTextures", optional_override(
        [](EditBox& this_, const std::string& arg0, const std::string& arg1, const std::string& arg2){
        return this_.loadTextures(arg0, arg1, arg2);
      }))
    .function("setPlaceHolder", &EditBox::setPlaceHolder, allow_raw_pointers())
    .function("setInputFlag", optional_override(
        [](EditBox& this_, int32_t arg0){
        return this_.setInputFlag((cocos2d::ui::EditBox::InputFlag)arg0);
      }))
    .function("setReturnType", optional_override(
        [](EditBox& this_, int32_t arg0){
        return this_.setReturnType((cocos2d::ui::EditBox::KeyboardReturnType)arg0);
      }))
    .function("getMaxLength", &EditBox::getMaxLength)
    .function("setCapInsetsPressedRenderer", &EditBox::setCapInsetsPressedRenderer)
    .function("setPlaceholderFont", &EditBox::setPlaceholderFont, allow_raw_pointers())
    .function("getPlaceholderFontColor", &EditBox::getPlaceholderFontColor)
    .function("setCapInsets", &EditBox::setCapInsets)
    .function("setFont", &EditBox::setFont, allow_raw_pointers())
    .function("setTextHorizontalAlignment", optional_override(
        [](EditBox& this_, int32_t arg0){
        return this_.setTextHorizontalAlignment((cocos2d::TextHAlignment)arg0);
      }))
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", optional_override(
        [](const cocos2d::Size& arg0, const std::string& arg1, int32_t arg2){
            return EditBox::create(arg0, arg1, (cocos2d::ui::Widget::TextureResType)arg2);
        }), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ui::EditBox*(const cocos2d::Size&, cocos2d::ui::Scale9Sprite*, cocos2d::ui::Scale9Sprite*, cocos2d::ui::Scale9Sprite*)>(&EditBox::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", optional_override(
        [](const cocos2d::Size& arg0, const std::string& arg1, const std::string& arg2, const std::string& arg3, int32_t arg4){
            return EditBox::create(arg0, arg1, arg2, arg3, (cocos2d::ui::Widget::TextureResType)arg4);
        }), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const EditBox& _) -> std::string {return "EditBox";}))    
    .allow_subclass<wrapper<EditBox>>("ccui.EditBox._extend")
    ;


  class_<LayoutComponent, base<Component>>("ccui.LayoutComponent")
    .constructor(&cc_bindings_constructor<LayoutComponent>, allow_raw_pointers())
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
    .function("setVerticalEdge", optional_override(
        [](LayoutComponent& this_, int32_t arg0){
        return this_.setVerticalEdge((cocos2d::ui::LayoutComponent::VerticalEdge)arg0);
      }))
    .function("getTopMargin", &LayoutComponent::getTopMargin)
    .function("setSizeWidth", &LayoutComponent::setSizeWidth)
    .function("getPercentContentSize", &LayoutComponent::getPercentContentSize)
    .function("getVerticalEdge", optional_override(
        [](LayoutComponent& this_){
        return (int32_t)this_.getVerticalEdge();
      }))
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
    .function("setHorizontalEdge", optional_override(
        [](LayoutComponent& this_, int32_t arg0){
        return this_.setHorizontalEdge((cocos2d::ui::LayoutComponent::HorizontalEdge)arg0);
      }))
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
    .function("getHorizontalEdge", optional_override(
        [](LayoutComponent& this_){
        return (int32_t)this_.getHorizontalEdge();
      }))
    .function("isStretchHeightEnabled", &LayoutComponent::isStretchHeightEnabled)
    .function("setBottomMargin", &LayoutComponent::setBottomMargin)
    .function("setSize", &LayoutComponent::setSize)
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", &LayoutComponent::create, allow_raw_pointers())
    .class_function("bindLayoutComponent", &LayoutComponent::bindLayoutComponent, allow_raw_pointers())
    .property("_className",  optional_override([](const LayoutComponent& _) -> std::string {return "LayoutComponent";}))    
    .allow_subclass<wrapper<LayoutComponent>>("ccui.LayoutComponent._extend")
    ;

  class_<TabHeader, base<AbstractCheckButton>>("ccui.TabHeader")
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
    .class_function("create", optional_override(
        [](const std::string& arg0, const std::string& arg1, const std::string& arg2, int32_t arg3){
            return TabHeader::create(arg0, arg1, arg2, (cocos2d::ui::Widget::TextureResType)arg3);
        }), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::ui::TabHeader*()>(&TabHeader::create), allow_raw_pointers())
    .class_function("create", optional_override(
        [](const std::string& arg0, const std::string& arg1, const std::string& arg2, const std::string& arg3, const std::string& arg4, const std::string& arg5, int32_t arg6){
            return TabHeader::create(arg0, arg1, arg2, arg3, arg4, arg5, (cocos2d::ui::Widget::TextureResType)arg6);
        }), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const TabHeader& _) -> std::string {return "TabHeader";}))    
    .allow_subclass<wrapper<TabHeader>>("ccui.TabHeader._extend")
    ;

  class_<TabControl, base<Widget>>("ccui.TabControl")
    .function("setHeaderWidth", &TabControl::setHeaderWidth)
    .function("removeTab", &TabControl::removeTab)
    .function("getTabCount", &TabControl::getTabCount)
    .function("getHeaderDockPlace", optional_override(
        [](TabControl& this_){
        return (int32_t)this_.getHeaderDockPlace();
      }))
    .function("getSelectedTabIndex", &TabControl::getSelectedTabIndex)
    .function("insertTab", &TabControl::insertTab, allow_raw_pointers())
    .function("ignoreHeadersTextureSize", &TabControl::ignoreHeadersTextureSize)
    .function("getHeaderWidth", &TabControl::getHeaderWidth)
    .function("setHeaderDockPlace", optional_override(
        [](TabControl& this_, int32_t arg0){
        return this_.setHeaderDockPlace((cocos2d::ui::TabControl::Dock)arg0);
      }))
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
    .class_function("create", &TabControl::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TabControl& _) -> std::string {return "TabControl";}))    
    .allow_subclass<wrapper<TabControl>>("ccui.TabControl._extend")
    ;


  class_<ScrollViewBar, base<ProtectedNode>>("ccui.ScrollViewBar")
    .constructor(&cc_bindings_constructor<ScrollViewBar, cocos2d::ui::ScrollView*, cocos2d::ui::ScrollView::Direction>, allow_raw_pointers())
    .function("setAutoHideEnabled", &ScrollViewBar::setAutoHideEnabled)
    .function("onScrolled", &ScrollViewBar::onScrolled)
    .function("isAutoHideEnabled", &ScrollViewBar::isAutoHideEnabled)
    .function("setAutoHideTime", &ScrollViewBar::setAutoHideTime)
    .function("getWidth", &ScrollViewBar::getWidth)
    .function("getPositionFromCorner", &ScrollViewBar::getPositionFromCorner)
    .function("setPositionFromCorner", &ScrollViewBar::setPositionFromCorner)
    .function("getAutoHideTime", &ScrollViewBar::getAutoHideTime)
    .function("setWidth", &ScrollViewBar::setWidth)
    .function("ctor", &cc_bindings_ctor)
    .class_function("create", optional_override(
      [](cocos2d::ui::ScrollView* arg0, int32_t arg1){
        return ScrollViewBar::create(arg0, (cocos2d::ui::ScrollView::Direction)arg1);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const ScrollViewBar& _) -> std::string {return "ScrollViewBar";})) 
    // TODO: it doesn't compile   
    // .allow_subclass<wrapper<ScrollViewBar>>("ccui.ScrollViewBar._extend")
    ;
}