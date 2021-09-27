#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_extension.hpp"
#include "cocos-ext.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace cocos2d::extension;

COCOS_BINDINGS(ccbind_cocos2dx_extension) {


  class_<Control, base<Layer>>("cc.Control")
    .constructor<>()
    .function("setSelected", &Control::setSelected, allow_raw_pointers())
    .function("hasVisibleParents", &Control::hasVisibleParents, allow_raw_pointers())
    .function("setHighlighted", &Control::setHighlighted, allow_raw_pointers())
    .function("isHighlighted", &Control::isHighlighted, allow_raw_pointers())
    .function("isEnabled", &Control::isEnabled, allow_raw_pointers())
    .function("sendActionsForControlEvents", &Control::sendActionsForControlEvents, allow_raw_pointers())
    .function("isSelected", &Control::isSelected, allow_raw_pointers())
    .function("setEnabled", &Control::setEnabled, allow_raw_pointers())
    .function("getState", &Control::getState, allow_raw_pointers())
    .function("needsLayout", &Control::needsLayout, allow_raw_pointers())
    .function("getTouchLocation", &Control::getTouchLocation, allow_raw_pointers())
    .function("isTouchInside", &Control::isTouchInside, allow_raw_pointers())
    .class_function("create", &Control::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Control& _) -> std::string {return "Control";}))    
    ;


  class_<ControlButton, base<Control>>("cc.ControlButton")
    .constructor<>()
    .function("isPushed", &ControlButton::isPushed, allow_raw_pointers())
    .function("setTitleLabelForState", &ControlButton::setTitleLabelForState, allow_raw_pointers())
    .function("setAdjustBackgroundImage", &ControlButton::setAdjustBackgroundImage, allow_raw_pointers())
    .function("getLabelAnchorPoint", &ControlButton::getLabelAnchorPoint, allow_raw_pointers())
    .function("setZoomOnTouchDown", &ControlButton::setZoomOnTouchDown, allow_raw_pointers())
    .function("setTitleForState", &ControlButton::setTitleForState, allow_raw_pointers())
    .function("setLabelAnchorPoint", &ControlButton::setLabelAnchorPoint, allow_raw_pointers())
    .function("initWithBackgroundSprite", &ControlButton::initWithBackgroundSprite, allow_raw_pointers())
    .function("getTitleTTFSizeForState", &ControlButton::getTitleTTFSizeForState, allow_raw_pointers())
    .function("setTitleTTFForState", &ControlButton::setTitleTTFForState, allow_raw_pointers())
    .function("setTitleTTFSizeForState", &ControlButton::setTitleTTFSizeForState, allow_raw_pointers())
    .function("setTitleLabel", &ControlButton::setTitleLabel, allow_raw_pointers())
    .function("setPreferredSize", &ControlButton::setPreferredSize, allow_raw_pointers())
    .function("getCurrentTitleColor", &ControlButton::getCurrentTitleColor, allow_raw_pointers())
    .function("setBackgroundSprite", &ControlButton::setBackgroundSprite, allow_raw_pointers())
    .function("getBackgroundSpriteForState", &ControlButton::getBackgroundSpriteForState, allow_raw_pointers())
    .function("getHorizontalOrigin", &ControlButton::getHorizontalOrigin, allow_raw_pointers())
    .function("getCurrentTitle", select_overload<std::string()>(&ControlButton::getCurrentTitle), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getScaleRatio", &ControlButton::getScaleRatio, allow_raw_pointers())
    .function("getTitleTTFForState", &ControlButton::getTitleTTFForState, allow_raw_pointers())
    .function("getBackgroundSprite", &ControlButton::getBackgroundSprite, allow_raw_pointers())
    .function("getTitleColorForState", &ControlButton::getTitleColorForState, allow_raw_pointers())
    .function("initWithTitleAndFontNameAndFontSize", &ControlButton::initWithTitleAndFontNameAndFontSize, allow_raw_pointers())
    .function("setTitleColorForState", &ControlButton::setTitleColorForState, allow_raw_pointers())
    .function("doesAdjustBackgroundImage", &ControlButton::doesAdjustBackgroundImage, allow_raw_pointers())
    .function("setBackgroundSpriteFrameForState", &ControlButton::setBackgroundSpriteFrameForState, allow_raw_pointers())
    .function("setBackgroundSpriteForState", &ControlButton::setBackgroundSpriteForState, allow_raw_pointers())
    .function("setScaleRatio", &ControlButton::setScaleRatio, allow_raw_pointers())
    .function("initWithLabelAndBackgroundSprite", &ControlButton::initWithLabelAndBackgroundSprite, allow_raw_pointers())
    .function("getTitleLabel", &ControlButton::getTitleLabel, allow_raw_pointers())
    .function("getPreferredSize", &ControlButton::getPreferredSize, allow_raw_pointers())
    .function("getVerticalMargin", &ControlButton::getVerticalMargin, allow_raw_pointers())
    .function("getTitleLabelForState", &ControlButton::getTitleLabelForState, allow_raw_pointers())
    .function("setMargins", &ControlButton::setMargins, allow_raw_pointers())
    .function("setTitleBMFontForState", &ControlButton::setTitleBMFontForState, allow_raw_pointers())
    .function("getTitleBMFontForState", &ControlButton::getTitleBMFontForState, allow_raw_pointers())
    .function("getZoomOnTouchDown", &ControlButton::getZoomOnTouchDown, allow_raw_pointers())
    .function("getTitleForState", &ControlButton::getTitleForState, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ControlButton>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ControlButton*(cocos2d::ui::Scale9Sprite*)>(&ControlButton::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ControlButton*()>(&ControlButton::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ControlButton*(cocos2d::Node*, cocos2d::ui::Scale9Sprite*)>(&ControlButton::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ControlButton*(const std::string&, const std::string&, float)>(&ControlButton::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const ControlButton& _) -> std::string {return "ControlButton";}))    
    // TODO: assign cc.Class.extend to cc.ControlButton.extend
    ;


  class_<ControlHuePicker, base<Control>>("cc.ControlHuePicker")
    .constructor<>()
    .function("initWithTargetAndPos", &ControlHuePicker::initWithTargetAndPos, allow_raw_pointers())
    .function("setHue", &ControlHuePicker::setHue, allow_raw_pointers())
    .function("getStartPos", &ControlHuePicker::getStartPos, allow_raw_pointers())
    .function("getHue", &ControlHuePicker::getHue, allow_raw_pointers())
    .function("getSlider", &ControlHuePicker::getSlider, allow_raw_pointers())
    .function("setBackground", &ControlHuePicker::setBackground, allow_raw_pointers())
    .function("setHuePercentage", &ControlHuePicker::setHuePercentage, allow_raw_pointers())
    .function("getBackground", &ControlHuePicker::getBackground, allow_raw_pointers())
    .function("getHuePercentage", &ControlHuePicker::getHuePercentage, allow_raw_pointers())
    .function("setSlider", &ControlHuePicker::setSlider, allow_raw_pointers())
    .class_function("create", &ControlHuePicker::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ControlHuePicker& _) -> std::string {return "ControlHuePicker";}))    
    ;


  class_<ControlSaturationBrightnessPicker, base<Control>>("cc.ControlSaturationBrightnessPicker")
    .constructor<>()
    .function("getShadow", &ControlSaturationBrightnessPicker::getShadow, allow_raw_pointers())
    .function("initWithTargetAndPos", &ControlSaturationBrightnessPicker::initWithTargetAndPos, allow_raw_pointers())
    .function("getStartPos", &ControlSaturationBrightnessPicker::getStartPos, allow_raw_pointers())
    .function("getOverlay", &ControlSaturationBrightnessPicker::getOverlay, allow_raw_pointers())
    .function("getSlider", &ControlSaturationBrightnessPicker::getSlider, allow_raw_pointers())
    .function("getBackground", &ControlSaturationBrightnessPicker::getBackground, allow_raw_pointers())
    .function("getSaturation", &ControlSaturationBrightnessPicker::getSaturation, allow_raw_pointers())
    .function("getBrightness", &ControlSaturationBrightnessPicker::getBrightness, allow_raw_pointers())
    .class_function("create", &ControlSaturationBrightnessPicker::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ControlSaturationBrightnessPicker& _) -> std::string {return "ControlSaturationBrightnessPicker";}))    
    ;


  class_<ControlColourPicker, base<Control>>("cc.ControlColourPicker")
    .constructor<>()
    .function("getHuePicker", &ControlColourPicker::getHuePicker, allow_raw_pointers())
    .function("hueSliderValueChanged", &ControlColourPicker::hueSliderValueChanged, allow_raw_pointers())
    .function("getcolourPicker", &ControlColourPicker::getcolourPicker, allow_raw_pointers())
    .function("setBackground", &ControlColourPicker::setBackground, allow_raw_pointers())
    .function("setcolourPicker", &ControlColourPicker::setcolourPicker, allow_raw_pointers())
    .function("colourSliderValueChanged", &ControlColourPicker::colourSliderValueChanged, allow_raw_pointers())
    .function("setHuePicker", &ControlColourPicker::setHuePicker, allow_raw_pointers())
    .function("getBackground", &ControlColourPicker::getBackground, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ControlColourPicker>, allow_raw_pointers())
    .class_function("create", &ControlColourPicker::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ControlColourPicker& _) -> std::string {return "ControlColourPicker";}))    
    // TODO: assign cc.Class.extend to cc.ControlColourPicker.extend
    ;


  class_<ControlPotentiometer, base<Control>>("cc.ControlPotentiometer")
    .constructor<>()
    .function("setPreviousLocation", &ControlPotentiometer::setPreviousLocation, allow_raw_pointers())
    .function("setProgressTimer", &ControlPotentiometer::setProgressTimer, allow_raw_pointers())
    .function("potentiometerMoved", &ControlPotentiometer::potentiometerMoved, allow_raw_pointers())
    .function("getMinimumValue", &ControlPotentiometer::getMinimumValue, allow_raw_pointers())
    .function("setThumbSprite", &ControlPotentiometer::setThumbSprite, allow_raw_pointers())
    .function("setMinimumValue", &ControlPotentiometer::setMinimumValue, allow_raw_pointers())
    .function("getPreviousLocation", &ControlPotentiometer::getPreviousLocation, allow_raw_pointers())
    .function("setValue", &ControlPotentiometer::setValue, allow_raw_pointers())
    .function("setMaximumValue", &ControlPotentiometer::setMaximumValue, allow_raw_pointers())
    .function("angleInDegreesBetweenLineFromPoint_toPoint_toLineFromPoint_toPoint", &ControlPotentiometer::angleInDegreesBetweenLineFromPoint_toPoint_toLineFromPoint_toPoint, allow_raw_pointers())
    .function("potentiometerEnded", &ControlPotentiometer::potentiometerEnded, allow_raw_pointers())
    .function("distanceBetweenPointAndPoint", &ControlPotentiometer::distanceBetweenPointAndPoint, allow_raw_pointers())
    .function("getProgressTimer", &ControlPotentiometer::getProgressTimer, allow_raw_pointers())
    .function("getMaximumValue", &ControlPotentiometer::getMaximumValue, allow_raw_pointers())
    .function("getValue", &ControlPotentiometer::getValue, allow_raw_pointers())
    .function("potentiometerBegan", &ControlPotentiometer::potentiometerBegan, allow_raw_pointers())
    .function("getThumbSprite", &ControlPotentiometer::getThumbSprite, allow_raw_pointers())
    .function("initWithTrackSprite_ProgressTimer_ThumbSprite", &ControlPotentiometer::initWithTrackSprite_ProgressTimer_ThumbSprite, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ControlPotentiometer>, allow_raw_pointers())
    .class_function("create", &ControlPotentiometer::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ControlPotentiometer& _) -> std::string {return "ControlPotentiometer";}))    
    // TODO: assign cc.Class.extend to cc.ControlPotentiometer.extend
    ;


  class_<ControlSlider, base<Control>>("cc.ControlSlider")
    .constructor<>()
    .function("getSelectedThumbSprite", &ControlSlider::getSelectedThumbSprite, allow_raw_pointers())
    .function("locationFromTouch", &ControlSlider::locationFromTouch, allow_raw_pointers())
    .function("setSelectedThumbSprite", &ControlSlider::setSelectedThumbSprite, allow_raw_pointers())
    .function("setProgressSprite", &ControlSlider::setProgressSprite, allow_raw_pointers())
    .function("getMaximumAllowedValue", &ControlSlider::getMaximumAllowedValue, allow_raw_pointers())
    .function("getMinimumAllowedValue", &ControlSlider::getMinimumAllowedValue, allow_raw_pointers())
    .function("getMinimumValue", &ControlSlider::getMinimumValue, allow_raw_pointers())
    .function("setThumbSprite", &ControlSlider::setThumbSprite, allow_raw_pointers())
    .function("setMinimumValue", &ControlSlider::setMinimumValue, allow_raw_pointers())
    .function("setMinimumAllowedValue", &ControlSlider::setMinimumAllowedValue, allow_raw_pointers())
    .function("setValue", &ControlSlider::setValue, allow_raw_pointers())
    .function("setMaximumValue", &ControlSlider::setMaximumValue, allow_raw_pointers())
    .function("getBackgroundSprite", &ControlSlider::getBackgroundSprite, allow_raw_pointers())
    .function("initWithSprites", select_overload<bool(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*)>(&ControlSlider::initWithSprites), allow_raw_pointers())
    .function("initWithSprites", select_overload<bool(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*)>(&ControlSlider::initWithSprites), allow_raw_pointers())
    .function("getMaximumValue", &ControlSlider::getMaximumValue, allow_raw_pointers())
    .function("getValue", &ControlSlider::getValue, allow_raw_pointers())
    .function("getThumbSprite", &ControlSlider::getThumbSprite, allow_raw_pointers())
    .function("getProgressSprite", &ControlSlider::getProgressSprite, allow_raw_pointers())
    .function("setBackgroundSprite", &ControlSlider::setBackgroundSprite, allow_raw_pointers())
    .function("setMaximumAllowedValue", &ControlSlider::setMaximumAllowedValue, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ControlSlider>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ControlSlider*(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*)>(&ControlSlider::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::extension::ControlSlider*(const char*, const char*, const char*, const char*)>(&ControlSlider::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const ControlSlider& _) -> std::string {return "ControlSlider";}))    
    // TODO: assign cc.Class.extend to cc.ControlSlider.extend
    ;


  class_<ControlStepper, base<Control>>("cc.ControlStepper")
    .constructor<>()
    .function("setMinusSprite", &ControlStepper::setMinusSprite, allow_raw_pointers())
    .function("getMinusLabel", &ControlStepper::getMinusLabel, allow_raw_pointers())
    .function("setWraps", &ControlStepper::setWraps, allow_raw_pointers())
    .function("isContinuous", &ControlStepper::isContinuous, allow_raw_pointers())
    .function("getMinusSprite", &ControlStepper::getMinusSprite, allow_raw_pointers())
    .function("updateLayoutUsingTouchLocation", &ControlStepper::updateLayoutUsingTouchLocation, allow_raw_pointers())
    .function("setValueWithSendingEvent", &ControlStepper::setValueWithSendingEvent, allow_raw_pointers())
    .function("getPlusLabel", &ControlStepper::getPlusLabel, allow_raw_pointers())
    .function("stopAutorepeat", &ControlStepper::stopAutorepeat, allow_raw_pointers())
    .function("setMinimumValue", &ControlStepper::setMinimumValue, allow_raw_pointers())
    .function("getPlusSprite", &ControlStepper::getPlusSprite, allow_raw_pointers())
    .function("setPlusSprite", &ControlStepper::setPlusSprite, allow_raw_pointers())
    .function("setMinusLabel", &ControlStepper::setMinusLabel, allow_raw_pointers())
    .function("setValue", &ControlStepper::setValue, allow_raw_pointers())
    .function("setStepValue", &ControlStepper::setStepValue, allow_raw_pointers())
    .function("setMaximumValue", &ControlStepper::setMaximumValue, allow_raw_pointers())
    .function("startAutorepeat", &ControlStepper::startAutorepeat, allow_raw_pointers())
    .function("initWithMinusSpriteAndPlusSprite", &ControlStepper::initWithMinusSpriteAndPlusSprite, allow_raw_pointers())
    .function("getValue", &ControlStepper::getValue, allow_raw_pointers())
    .function("setPlusLabel", &ControlStepper::setPlusLabel, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ControlStepper>, allow_raw_pointers())
    .class_function("create", &ControlStepper::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ControlStepper& _) -> std::string {return "ControlStepper";}))    
    // TODO: assign cc.Class.extend to cc.ControlStepper.extend
    ;


  class_<ControlSwitch, base<Control>>("cc.ControlSwitch")
    .constructor<>()
    .function("setOn", select_overload<void(bool)>(&ControlSwitch::setOn), allow_raw_pointers())
    .function("setOn", select_overload<void(bool, bool)>(&ControlSwitch::setOn), allow_raw_pointers())
    .function("isOn", &ControlSwitch::isOn, allow_raw_pointers())
    .function("initWithMaskSprite", select_overload<bool(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Label*, cocos2d::Label*)>(&ControlSwitch::initWithMaskSprite), allow_raw_pointers())
    .function("initWithMaskSprite", select_overload<bool(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*)>(&ControlSwitch::initWithMaskSprite), allow_raw_pointers())
    .function("hasMoved", &ControlSwitch::hasMoved, allow_raw_pointers())
    .function("locationFromTouch", &ControlSwitch::locationFromTouch, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ControlSwitch>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ControlSwitch*(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*)>(&ControlSwitch::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ControlSwitch*(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Label*, cocos2d::Label*)>(&ControlSwitch::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ControlSwitch& _) -> std::string {return "ControlSwitch";}))    
    // TODO: assign cc.Class.extend to cc.ControlSwitch.extend
    ;


  class_<ScrollView, base<Layer>>("cc.ScrollView")
    .constructor<>()
    .function("isClippingToBounds", &ScrollView::isClippingToBounds, allow_raw_pointers())
    .function("setContainer", &ScrollView::setContainer, allow_raw_pointers())
    .function("setContentOffsetInDuration", &ScrollView::setContentOffsetInDuration, allow_raw_pointers())
    .function("setZoomScaleInDuration", &ScrollView::setZoomScaleInDuration, allow_raw_pointers())
    .function("setMaxScale", &ScrollView::setMaxScale, allow_raw_pointers())
    .function("hasVisibleParents", &ScrollView::hasVisibleParents, allow_raw_pointers())
    .function("setSwallowTouches", &ScrollView::setSwallowTouches, allow_raw_pointers())
    .function("getContainer", &ScrollView::getContainer, allow_raw_pointers())
    .function("setMinScale", &ScrollView::setMinScale, allow_raw_pointers())
    .function("getZoomScale", &ScrollView::getZoomScale, allow_raw_pointers())
    .function("updateInset", &ScrollView::updateInset, allow_raw_pointers())
    .function("initWithViewSize", &ScrollView::initWithViewSize, allow_raw_pointers())
    .function("initWithViewSize", optional_override(
        [](ScrollView& this_, cocos2d::Size arg0){
        return this_.initWithViewSize(arg0);
      }), allow_raw_pointers())
    .function("pause", select_overload<void(Ref* sender)>(&ScrollView::pause), allow_raw_pointers())
    .function("setDirection", &ScrollView::setDirection, allow_raw_pointers())
    .function("setContentOffset", &ScrollView::setContentOffset, allow_raw_pointers())
    .function("setContentOffset", optional_override(
        [](ScrollView& this_, cocos2d::Vec2 arg0){
        return this_.setContentOffset(arg0);
      }), allow_raw_pointers())
    .function("isDragging", &ScrollView::isDragging, allow_raw_pointers())
    .function("isTouchEnabled", &ScrollView::isTouchEnabled, allow_raw_pointers())
    .function("isBounceable", &ScrollView::isBounceable, allow_raw_pointers())
    .function("setTouchEnabled", &ScrollView::setTouchEnabled, allow_raw_pointers())
    .function("getContentOffset", &ScrollView::getContentOffset, allow_raw_pointers())
    .function("resume", select_overload<void(Ref* sender)>(&ScrollView::resume), allow_raw_pointers())
    .function("setClippingToBounds", &ScrollView::setClippingToBounds, allow_raw_pointers())
    .function("setViewSize", &ScrollView::setViewSize, allow_raw_pointers())
    .function("getViewSize", &ScrollView::getViewSize, allow_raw_pointers())
    .function("maxContainerOffset", &ScrollView::maxContainerOffset, allow_raw_pointers())
    .function("setBounceable", &ScrollView::setBounceable, allow_raw_pointers())
    .function("stopAnimatedContentOffset", &ScrollView::stopAnimatedContentOffset, allow_raw_pointers())
    .function("isTouchMoved", &ScrollView::isTouchMoved, allow_raw_pointers())
    .function("isNodeVisible", &ScrollView::isNodeVisible, allow_raw_pointers())
    .function("minContainerOffset", &ScrollView::minContainerOffset, allow_raw_pointers())
    .function("getDirection", &ScrollView::getDirection, allow_raw_pointers())
    .function("setZoomScale", select_overload<void(float, bool)>(&ScrollView::setZoomScale), allow_raw_pointers())
    .function("setZoomScale", select_overload<void(float)>(&ScrollView::setZoomScale), allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ScrollView>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ScrollView*()>(&ScrollView::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ScrollView*(cocos2d::Size, cocos2d::Node*)>(&ScrollView::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const ScrollView& _) -> std::string {return "ScrollView";}))    
    // TODO: assign cc.Class.extend to cc.ScrollView.extend
    ;


  class_<TableViewCell, base<Node>>("cc.TableViewCell")
    .constructor<>()
    .function("reset", &TableViewCell::reset, allow_raw_pointers())
    .function("getIdx", &TableViewCell::getIdx, allow_raw_pointers())
    .function("setIdx", &TableViewCell::setIdx, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TableViewCell>, allow_raw_pointers())
    .class_function("create", &TableViewCell::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TableViewCell& _) -> std::string {return "TableViewCell";}))    
    // TODO: assign cc.Class.extend to cc.TableViewCell.extend
    ;


  class_<TableView, base<ScrollView>>("cc.TableView")
    .constructor<>()
    .function("updateCellAtIndex", &TableView::updateCellAtIndex, allow_raw_pointers())
    .function("setVerticalFillOrder", &TableView::setVerticalFillOrder, allow_raw_pointers())
    .function("_updateContentSize", &TableView::_updateContentSize, allow_raw_pointers())
    .function("getVerticalFillOrder", &TableView::getVerticalFillOrder, allow_raw_pointers())
    .function("removeCellAtIndex", &TableView::removeCellAtIndex, allow_raw_pointers())
    .function("initWithViewSize", &TableView::initWithViewSize, allow_raw_pointers())
    .function("initWithViewSize", optional_override(
        [](TableView& this_, cocos2d::Size arg0){
        return this_.initWithViewSize(arg0);
      }), allow_raw_pointers())
    .function("reloadData", &TableView::reloadData, allow_raw_pointers())
    .function("insertCellAtIndex", &TableView::insertCellAtIndex, allow_raw_pointers())
    .function("cellAtIndex", &TableView::cellAtIndex, allow_raw_pointers())
    .function("dequeueCell", &TableView::dequeueCell, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TableView>, allow_raw_pointers())
    .property("_className",  optional_override([](const TableView& _) -> std::string {return "TableView";}))    
    // TODO: assign cc.Class.extend to cc.TableView.extend
    ;


  class_<EventAssetsManagerEx, base<EventCustom>>("cc.EventAssetsManager")
    .constructor<const std::string&, cocos2d::extension::AssetsManagerEx*, const cocos2d::extension::EventAssetsManagerEx::EventCode&, float, float, const std::string&, const std::string&, int, int>()
    .function("getAssetsManagerEx", &EventAssetsManagerEx::getAssetsManagerEx, allow_raw_pointers())
    .function("getAssetId", &EventAssetsManagerEx::getAssetId, allow_raw_pointers())
    .function("getCURLECode", &EventAssetsManagerEx::getCURLECode, allow_raw_pointers())
    .function("getMessage", &EventAssetsManagerEx::getMessage, allow_raw_pointers())
    .function("getCURLMCode", &EventAssetsManagerEx::getCURLMCode, allow_raw_pointers())
    .function("getPercentByFile", &EventAssetsManagerEx::getPercentByFile, allow_raw_pointers())
    .function("getEventCode", &EventAssetsManagerEx::getEventCode, allow_raw_pointers())
    .function("getPercent", &EventAssetsManagerEx::getPercent, allow_raw_pointers())
    .property("_className",  optional_override([](const EventAssetsManagerEx& _) -> std::string {return "EventAssetsManagerEx";}))    
    ;

  class_<Manifest>("cc.Manifest")
    .function("getManifestFileUrl", &Manifest::getManifestFileUrl, allow_raw_pointers())
    .function("isVersionLoaded", &Manifest::isVersionLoaded, allow_raw_pointers())
    .function("isLoaded", &Manifest::isLoaded, allow_raw_pointers())
    .function("getPackageUrl", &Manifest::getPackageUrl, allow_raw_pointers())
    .function("getVersion", &Manifest::getVersion, allow_raw_pointers())
    .function("getVersionFileUrl", &Manifest::getVersionFileUrl, allow_raw_pointers())
    .function("getSearchPaths", &Manifest::getSearchPaths, allow_raw_pointers())
    .property("_className",  optional_override([](const Manifest& _) -> std::string {return "Manifest";}))    
    ;


  class_<AssetsManagerEx>("cc.AssetsManager")
    .constructor<const std::string&, const std::string&>()
    .function("getState", &AssetsManagerEx::getState, allow_raw_pointers())
    .function("getMaxConcurrentTask", &AssetsManagerEx::getMaxConcurrentTask, allow_raw_pointers())
    .function("checkUpdate", &AssetsManagerEx::checkUpdate, allow_raw_pointers())
    .function("setVerifyCallback", &AssetsManagerEx::setVerifyCallback, allow_raw_pointers())
    .function("getStoragePath", &AssetsManagerEx::getStoragePath, allow_raw_pointers())
    .function("update", &AssetsManagerEx::update, allow_raw_pointers())
    .function("setVersionCompareHandle", &AssetsManagerEx::setVersionCompareHandle, allow_raw_pointers())
    .function("setMaxConcurrentTask", &AssetsManagerEx::setMaxConcurrentTask, allow_raw_pointers())
    .function("getLocalManifest", &AssetsManagerEx::getLocalManifest, allow_raw_pointers())
    .function("getRemoteManifest", &AssetsManagerEx::getRemoteManifest, allow_raw_pointers())
    .function("downloadFailedAssets", &AssetsManagerEx::downloadFailedAssets, allow_raw_pointers())
    .class_function("create", &AssetsManagerEx::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AssetsManagerEx& _) -> std::string {return "AssetsManagerEx";}))    
    ;


  class_<EventListenerAssetsManagerEx, base<EventListenerCustom>>("cc.EventListenerAssetsManager")
    .constructor<>()
    .property("_className",  optional_override([](const EventListenerAssetsManagerEx& _) -> std::string {return "EventListenerAssetsManagerEx";}))    
    ;
}
