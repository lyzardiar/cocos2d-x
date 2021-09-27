#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_extension.hpp"
#include "cocos-ext.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(ccbind_cocos2dx_extension) {


  class_<Control, base<Layer>>("cc.Control")
    .constructor<>()
    .function("setEnabled", &Control::setEnabled)
    .function("getState", &Control::getState)
    .function("sendActionsForControlEvents", &Control::sendActionsForControlEvents)
    .function("setSelected", &Control::setSelected)
    .function("isEnabled", &Control::isEnabled)
    .function("needsLayout", &Control::needsLayout)
    .function("hasVisibleParents", &Control::hasVisibleParents)
    .function("isSelected", &Control::isSelected)
    .function("isTouchInside", &Control::isTouchInside, allow_raw_pointers())
    .function("setHighlighted", &Control::setHighlighted)
    .function("getTouchLocation", &Control::getTouchLocation, allow_raw_pointers())
    .function("isHighlighted", &Control::isHighlighted)
    .class_function("create", &Control::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Control& _) -> std::string {return "Control";}))    
    ;


  class_<ControlButton, base<Control>>("cc.ControlButton")
    .constructor<>()
    .function("isPushed", &ControlButton::isPushed)
    .function("setTitleLabelForState", &ControlButton::setTitleLabelForState, allow_raw_pointers())
    .function("setAdjustBackgroundImage", &ControlButton::setAdjustBackgroundImage)
    .function("setTitleForState", &ControlButton::setTitleForState)
    .function("setLabelAnchorPoint", &ControlButton::setLabelAnchorPoint)
    .function("getLabelAnchorPoint", &ControlButton::getLabelAnchorPoint)
    .function("initWithBackgroundSprite", &ControlButton::initWithBackgroundSprite, allow_raw_pointers())
    .function("getTitleTTFSizeForState", &ControlButton::getTitleTTFSizeForState)
    .function("setTitleTTFForState", &ControlButton::setTitleTTFForState)
    .function("setTitleTTFSizeForState", &ControlButton::setTitleTTFSizeForState)
    .function("setTitleLabel", &ControlButton::setTitleLabel, allow_raw_pointers())
    .function("setPreferredSize", &ControlButton::setPreferredSize)
    .function("getCurrentTitleColor", &ControlButton::getCurrentTitleColor)
    .function("setZoomOnTouchDown", &ControlButton::setZoomOnTouchDown)
    .function("setBackgroundSprite", &ControlButton::setBackgroundSprite, allow_raw_pointers())
    .function("getBackgroundSpriteForState", &ControlButton::getBackgroundSpriteForState, allow_raw_pointers())
    .function("getHorizontalOrigin", &ControlButton::getHorizontalOrigin)
    .function("initWithTitleAndFontNameAndFontSize", &ControlButton::initWithTitleAndFontNameAndFontSize)
    .function("setTitleBMFontForState", &ControlButton::setTitleBMFontForState)
    .function("getScaleRatio", &ControlButton::getScaleRatio)
    .function("getTitleTTFForState", &ControlButton::getTitleTTFForState)
    .function("getBackgroundSprite", &ControlButton::getBackgroundSprite, allow_raw_pointers())
    .function("getTitleColorForState", &ControlButton::getTitleColorForState)
    .function("setTitleColorForState", &ControlButton::setTitleColorForState)
    .function("doesAdjustBackgroundImage", &ControlButton::doesAdjustBackgroundImage)
    .function("setBackgroundSpriteFrameForState", &ControlButton::setBackgroundSpriteFrameForState, allow_raw_pointers())
    .function("setBackgroundSpriteForState", &ControlButton::setBackgroundSpriteForState, allow_raw_pointers())
    .function("setScaleRatio", &ControlButton::setScaleRatio)
    .function("getTitleBMFontForState", &ControlButton::getTitleBMFontForState)
    .function("getTitleLabel", &ControlButton::getTitleLabel, allow_raw_pointers())
    .function("getPreferredSize", &ControlButton::getPreferredSize)
    .function("getVerticalMargin", &ControlButton::getVerticalMargin)
    .function("getTitleLabelForState", &ControlButton::getTitleLabelForState, allow_raw_pointers())
    .function("setMargins", &ControlButton::setMargins)
    .function("getCurrentTitle", select_overload<std::string()>(&ControlButton::getCurrentTitle))
    // TODO: Only support function overloading with different number of parameters
    .function("initWithLabelAndBackgroundSprite", &ControlButton::initWithLabelAndBackgroundSprite, allow_raw_pointers())
    .function("getZoomOnTouchDown", &ControlButton::getZoomOnTouchDown)
    .function("getTitleForState", &ControlButton::getTitleForState)
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
    .function("setHue", &ControlHuePicker::setHue)
    .function("getStartPos", &ControlHuePicker::getStartPos)
    .function("getHue", &ControlHuePicker::getHue)
    .function("getSlider", &ControlHuePicker::getSlider, allow_raw_pointers())
    .function("setBackground", &ControlHuePicker::setBackground, allow_raw_pointers())
    .function("setHuePercentage", &ControlHuePicker::setHuePercentage)
    .function("getBackground", &ControlHuePicker::getBackground, allow_raw_pointers())
    .function("getHuePercentage", &ControlHuePicker::getHuePercentage)
    .function("setSlider", &ControlHuePicker::setSlider, allow_raw_pointers())
    .class_function("create", &ControlHuePicker::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ControlHuePicker& _) -> std::string {return "ControlHuePicker";}))    
    ;


  class_<ControlSaturationBrightnessPicker, base<Control>>("cc.ControlSaturationBrightnessPicker")
    .constructor<>()
    .function("getShadow", &ControlSaturationBrightnessPicker::getShadow, allow_raw_pointers())
    .function("initWithTargetAndPos", &ControlSaturationBrightnessPicker::initWithTargetAndPos, allow_raw_pointers())
    .function("getStartPos", &ControlSaturationBrightnessPicker::getStartPos)
    .function("getOverlay", &ControlSaturationBrightnessPicker::getOverlay, allow_raw_pointers())
    .function("getSlider", &ControlSaturationBrightnessPicker::getSlider, allow_raw_pointers())
    .function("getBackground", &ControlSaturationBrightnessPicker::getBackground, allow_raw_pointers())
    .function("getSaturation", &ControlSaturationBrightnessPicker::getSaturation)
    .function("getBrightness", &ControlSaturationBrightnessPicker::getBrightness)
    .class_function("create", &ControlSaturationBrightnessPicker::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ControlSaturationBrightnessPicker& _) -> std::string {return "ControlSaturationBrightnessPicker";}))    
    ;


  class_<ControlColourPicker, base<Control>>("cc.ControlColourPicker")
    .constructor<>()
    .function("hueSliderValueChanged", &ControlColourPicker::hueSliderValueChanged, allow_raw_pointers())
    .function("getHuePicker", &ControlColourPicker::getHuePicker, allow_raw_pointers())
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
    .function("setPreviousLocation", &ControlPotentiometer::setPreviousLocation)
    .function("setValue", &ControlPotentiometer::setValue)
    .function("getProgressTimer", &ControlPotentiometer::getProgressTimer, allow_raw_pointers())
    .function("getMaximumValue", &ControlPotentiometer::getMaximumValue)
    .function("angleInDegreesBetweenLineFromPoint_toPoint_toLineFromPoint_toPoint", &ControlPotentiometer::angleInDegreesBetweenLineFromPoint_toPoint_toLineFromPoint_toPoint)
    .function("potentiometerBegan", &ControlPotentiometer::potentiometerBegan)
    .function("setMaximumValue", &ControlPotentiometer::setMaximumValue)
    .function("getMinimumValue", &ControlPotentiometer::getMinimumValue)
    .function("setThumbSprite", &ControlPotentiometer::setThumbSprite, allow_raw_pointers())
    .function("getValue", &ControlPotentiometer::getValue)
    .function("getPreviousLocation", &ControlPotentiometer::getPreviousLocation)
    .function("distanceBetweenPointAndPoint", &ControlPotentiometer::distanceBetweenPointAndPoint)
    .function("potentiometerEnded", &ControlPotentiometer::potentiometerEnded)
    .function("setProgressTimer", &ControlPotentiometer::setProgressTimer, allow_raw_pointers())
    .function("setMinimumValue", &ControlPotentiometer::setMinimumValue)
    .function("getThumbSprite", &ControlPotentiometer::getThumbSprite, allow_raw_pointers())
    .function("initWithTrackSprite_ProgressTimer_ThumbSprite", &ControlPotentiometer::initWithTrackSprite_ProgressTimer_ThumbSprite, allow_raw_pointers())
    .function("potentiometerMoved", &ControlPotentiometer::potentiometerMoved)
    .function("ctor", &cc_bindings_ctor<ControlPotentiometer>, allow_raw_pointers())
    .class_function("create", &ControlPotentiometer::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ControlPotentiometer& _) -> std::string {return "ControlPotentiometer";}))    
    // TODO: assign cc.Class.extend to cc.ControlPotentiometer.extend
    ;


  class_<ControlSlider, base<Control>>("cc.ControlSlider")
    .constructor<>()
    .function("setBackgroundSprite", &ControlSlider::setBackgroundSprite, allow_raw_pointers())
    .function("getMaximumAllowedValue", &ControlSlider::getMaximumAllowedValue)
    .function("initWithSprites", select_overload<bool(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*)>(&ControlSlider::initWithSprites), allow_raw_pointers())
    .function("initWithSprites", select_overload<bool(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*)>(&ControlSlider::initWithSprites), allow_raw_pointers())
    .function("getMinimumAllowedValue", &ControlSlider::getMinimumAllowedValue)
    .function("getMaximumValue", &ControlSlider::getMaximumValue)
    .function("getSelectedThumbSprite", &ControlSlider::getSelectedThumbSprite, allow_raw_pointers())
    .function("setProgressSprite", &ControlSlider::setProgressSprite, allow_raw_pointers())
    .function("setMaximumValue", &ControlSlider::setMaximumValue)
    .function("getMinimumValue", &ControlSlider::getMinimumValue)
    .function("setThumbSprite", &ControlSlider::setThumbSprite, allow_raw_pointers())
    .function("getValue", &ControlSlider::getValue)
    .function("getBackgroundSprite", &ControlSlider::getBackgroundSprite, allow_raw_pointers())
    .function("getThumbSprite", &ControlSlider::getThumbSprite, allow_raw_pointers())
    .function("setValue", &ControlSlider::setValue)
    .function("locationFromTouch", &ControlSlider::locationFromTouch, allow_raw_pointers())
    .function("setMinimumValue", &ControlSlider::setMinimumValue)
    .function("setMinimumAllowedValue", &ControlSlider::setMinimumAllowedValue)
    .function("getProgressSprite", &ControlSlider::getProgressSprite, allow_raw_pointers())
    .function("setSelectedThumbSprite", &ControlSlider::setSelectedThumbSprite, allow_raw_pointers())
    .function("setMaximumAllowedValue", &ControlSlider::setMaximumAllowedValue)
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
    .function("getMinusSprite", &ControlStepper::getMinusSprite, allow_raw_pointers())
    .function("setValue", &ControlStepper::setValue)
    .function("setStepValue", &ControlStepper::setStepValue)
    .function("initWithMinusSpriteAndPlusSprite", &ControlStepper::initWithMinusSpriteAndPlusSprite, allow_raw_pointers())
    .function("setValueWithSendingEvent", &ControlStepper::setValueWithSendingEvent)
    .function("setMaximumValue", &ControlStepper::setMaximumValue)
    .function("getMinusLabel", &ControlStepper::getMinusLabel, allow_raw_pointers())
    .function("getPlusLabel", &ControlStepper::getPlusLabel, allow_raw_pointers())
    .function("setWraps", &ControlStepper::setWraps)
    .function("setMinusLabel", &ControlStepper::setMinusLabel, allow_raw_pointers())
    .function("startAutorepeat", &ControlStepper::startAutorepeat)
    .function("updateLayoutUsingTouchLocation", &ControlStepper::updateLayoutUsingTouchLocation)
    .function("isContinuous", &ControlStepper::isContinuous)
    .function("stopAutorepeat", &ControlStepper::stopAutorepeat)
    .function("setMinimumValue", &ControlStepper::setMinimumValue)
    .function("setPlusLabel", &ControlStepper::setPlusLabel, allow_raw_pointers())
    .function("getValue", &ControlStepper::getValue)
    .function("getPlusSprite", &ControlStepper::getPlusSprite, allow_raw_pointers())
    .function("setPlusSprite", &ControlStepper::setPlusSprite, allow_raw_pointers())
    .function("setMinusSprite", &ControlStepper::setMinusSprite, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ControlStepper>, allow_raw_pointers())
    .class_function("create", &ControlStepper::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ControlStepper& _) -> std::string {return "ControlStepper";}))    
    // TODO: assign cc.Class.extend to cc.ControlStepper.extend
    ;


  class_<ControlSwitch, base<Control>>("cc.ControlSwitch")
    .constructor<>()
    .function("setOn", select_overload<void(bool)>(&ControlSwitch::setOn))
    .function("setOn", select_overload<void(bool, bool)>(&ControlSwitch::setOn))
    .function("locationFromTouch", &ControlSwitch::locationFromTouch, allow_raw_pointers())
    .function("isOn", &ControlSwitch::isOn)
    .function("initWithMaskSprite", select_overload<bool(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Label*, cocos2d::Label*)>(&ControlSwitch::initWithMaskSprite), allow_raw_pointers())
    .function("initWithMaskSprite", select_overload<bool(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*)>(&ControlSwitch::initWithMaskSprite), allow_raw_pointers())
    .function("hasMoved", &ControlSwitch::hasMoved)
    .function("ctor", &cc_bindings_ctor<ControlSwitch>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ControlSwitch*(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*)>(&ControlSwitch::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ControlSwitch*(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Label*, cocos2d::Label*)>(&ControlSwitch::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ControlSwitch& _) -> std::string {return "ControlSwitch";}))    
    // TODO: assign cc.Class.extend to cc.ControlSwitch.extend
    ;


  class_<ScrollView, base<Layer>>("cc.ScrollView")
    .constructor<>()
    .function("isClippingToBounds", &ScrollView::isClippingToBounds)
    .function("setContainer", &ScrollView::setContainer, allow_raw_pointers())
    .function("setContentOffsetInDuration", &ScrollView::setContentOffsetInDuration)
    .function("setZoomScaleInDuration", &ScrollView::setZoomScaleInDuration)
    .function("updateTweenAction", &ScrollView::updateTweenAction)
    .function("setMaxScale", &ScrollView::setMaxScale)
    .function("hasVisibleParents", &ScrollView::hasVisibleParents)
    .function("setSwallowTouches", &ScrollView::setSwallowTouches)
    .function("getContainer", &ScrollView::getContainer, allow_raw_pointers())
    .function("setMinScale", &ScrollView::setMinScale)
    .function("getZoomScale", &ScrollView::getZoomScale)
    .function("updateInset", &ScrollView::updateInset)
    .function("initWithViewSize", &ScrollView::initWithViewSize, allow_raw_pointers())
    .function("initWithViewSize", optional_override(
        [](ScrollView& this_, cocos2d::Size arg0){
        return this_.initWithViewSize(arg0);
      }))
    .function("pause", &ScrollView::pause, allow_raw_pointers())
    .function("setDirection", &ScrollView::setDirection)
    .function("stopAnimatedContentOffset", &ScrollView::stopAnimatedContentOffset)
    .function("setContentOffset", &ScrollView::setContentOffset)
    .function("setContentOffset", optional_override(
        [](ScrollView& this_, cocos2d::Vec2 arg0){
        return this_.setContentOffset(arg0);
      }))
    .function("isDragging", &ScrollView::isDragging)
    .function("isTouchEnabled", &ScrollView::isTouchEnabled)
    .function("isBounceable", &ScrollView::isBounceable)
    .function("setTouchEnabled", &ScrollView::setTouchEnabled)
    .function("getContentOffset", &ScrollView::getContentOffset)
    .function("resume", &ScrollView::resume, allow_raw_pointers())
    .function("setClippingToBounds", &ScrollView::setClippingToBounds)
    .function("setViewSize", &ScrollView::setViewSize)
    .function("getViewSize", &ScrollView::getViewSize)
    .function("maxContainerOffset", &ScrollView::maxContainerOffset)
    .function("setBounceable", &ScrollView::setBounceable)
    .function("isTouchMoved", &ScrollView::isTouchMoved)
    .function("isNodeVisible", &ScrollView::isNodeVisible, allow_raw_pointers())
    .function("minContainerOffset", &ScrollView::minContainerOffset)
    .function("getDirection", &ScrollView::getDirection)
    .function("setZoomScale", select_overload<void(float, bool)>(&ScrollView::setZoomScale))
    .function("setZoomScale", select_overload<void(float)>(&ScrollView::setZoomScale))
    .function("ctor", &cc_bindings_ctor<ScrollView>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ScrollView*()>(&ScrollView::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ScrollView*(cocos2d::Size, cocos2d::Node*)>(&ScrollView::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const ScrollView& _) -> std::string {return "ScrollView";}))    
    // TODO: assign cc.Class.extend to cc.ScrollView.extend
    ;


  class_<TableViewCell, base<Node>>("cc.TableViewCell")
    .constructor<>()
    .function("reset", &TableViewCell::reset)
    .function("getIdx", &TableViewCell::getIdx)
    .function("setIdx", &TableViewCell::setIdx)
    .function("ctor", &cc_bindings_ctor<TableViewCell>, allow_raw_pointers())
    .class_function("create", &TableViewCell::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TableViewCell& _) -> std::string {return "TableViewCell";}))    
    // TODO: assign cc.Class.extend to cc.TableViewCell.extend
    ;


  class_<TableView, base<ScrollView>>("cc.TableView")
    .constructor<>()
    .function("updateCellAtIndex", &TableView::updateCellAtIndex)
    .function("setVerticalFillOrder", &TableView::setVerticalFillOrder)
    .function("scrollViewDidZoom", &TableView::scrollViewDidZoom, allow_raw_pointers())
    .function("_updateContentSize", &TableView::_updateContentSize)
    .function("getVerticalFillOrder", &TableView::getVerticalFillOrder)
    .function("removeCellAtIndex", &TableView::removeCellAtIndex)
    .function("initWithViewSize", &TableView::initWithViewSize, allow_raw_pointers())
    .function("initWithViewSize", optional_override(
        [](TableView& this_, cocos2d::Size arg0){
        return this_.initWithViewSize(arg0);
      }))
    .function("scrollViewDidScroll", &TableView::scrollViewDidScroll, allow_raw_pointers())
    .function("reloadData", &TableView::reloadData)
    .function("insertCellAtIndex", &TableView::insertCellAtIndex)
    .function("cellAtIndex", &TableView::cellAtIndex, allow_raw_pointers())
    .function("dequeueCell", &TableView::dequeueCell, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TableView>, allow_raw_pointers())
    .property("_className",  optional_override([](const TableView& _) -> std::string {return "TableView";}))    
    // TODO: assign cc.Class.extend to cc.TableView.extend
    ;


  class_<EventAssetsManagerEx, base<EventCustom>>("cc.EventAssetsManager")
    .constructor<const std::string&, cocos2d::extension::AssetsManagerEx*, const cocos2d::extension::EventAssetsManagerEx::EventCode&, float, float, const std::string&, const std::string&, int, int>()
    .function("getAssetsManagerEx", &EventAssetsManagerEx::getAssetsManagerEx, allow_raw_pointers())
    .function("getAssetId", &EventAssetsManagerEx::getAssetId)
    .function("getCURLECode", &EventAssetsManagerEx::getCURLECode)
    .function("getMessage", &EventAssetsManagerEx::getMessage)
    .function("getCURLMCode", &EventAssetsManagerEx::getCURLMCode)
    .function("getPercentByFile", &EventAssetsManagerEx::getPercentByFile)
    .function("getEventCode", &EventAssetsManagerEx::getEventCode)
    .function("getPercent", &EventAssetsManagerEx::getPercent)
    .property("_className",  optional_override([](const EventAssetsManagerEx& _) -> std::string {return "EventAssetsManagerEx";}))    
    ;

  class_<Manifest>("cc.Manifest")
    .function("getManifestFileUrl", &Manifest::getManifestFileUrl)
    .function("isVersionLoaded", &Manifest::isVersionLoaded)
    .function("isLoaded", &Manifest::isLoaded)
    .function("getPackageUrl", &Manifest::getPackageUrl)
    .function("getVersion", &Manifest::getVersion)
    .function("getVersionFileUrl", &Manifest::getVersionFileUrl)
    .function("getSearchPaths", &Manifest::getSearchPaths)
    .property("_className",  optional_override([](const Manifest& _) -> std::string {return "Manifest";}))    
    ;


  class_<AssetsManagerEx>("cc.AssetsManager")
    .constructor<const std::string&, const std::string&>()
    .function("getState", &AssetsManagerEx::getState)
    .function("getMaxConcurrentTask", &AssetsManagerEx::getMaxConcurrentTask)
    .function("checkUpdate", &AssetsManagerEx::checkUpdate)
    .function("setVerifyCallback", &AssetsManagerEx::setVerifyCallback)
    .function("getStoragePath", &AssetsManagerEx::getStoragePath)
    .function("update", &AssetsManagerEx::update)
    .function("setVersionCompareHandle", &AssetsManagerEx::setVersionCompareHandle)
    .function("setMaxConcurrentTask", &AssetsManagerEx::setMaxConcurrentTask)
    .function("getLocalManifest", &AssetsManagerEx::getLocalManifest, allow_raw_pointers())
    .function("getRemoteManifest", &AssetsManagerEx::getRemoteManifest, allow_raw_pointers())
    .function("downloadFailedAssets", &AssetsManagerEx::downloadFailedAssets)
    .class_function("create", &AssetsManagerEx::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AssetsManagerEx& _) -> std::string {return "AssetsManagerEx";}))    
    ;


  class_<EventListenerAssetsManagerEx, base<EventListenerCustom>>("cc.EventListenerAssetsManager")
    .constructor<>()
    .property("_className",  optional_override([](const EventListenerAssetsManagerEx& _) -> std::string {return "EventListenerAssetsManagerEx";}))    
    ;}