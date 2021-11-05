#include "scripting/CCScriptBindings.h"
#include "scripting/javascript-bindings/jsb_cocos2dx_extension.hpp"
#include "cocos-ext.h"
#include "renderer/CCTextureCache.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace cocos2d::extension;

class JSB_ScrollViewDelegate
: public Ref
, public ScrollViewDelegate
{
public:
    JSB_ScrollViewDelegate()
        : _JSDelegate(val::undefined())
    {}
    
    virtual void scrollViewDidScroll(ScrollView* scrollView) override
    {
        _JSDelegate.call<void>("scrollViewDidScroll", val(scrollView));
    }
    
    virtual void scrollViewDidZoom(ScrollView* scrollView) override
    {
        _JSDelegate.call<void>("scrollViewDidZoom", val(scrollView));
    }
    
    void setJSDelegate(const val& pJSDelegate)
    {
        _JSDelegate = pJSDelegate;
    }
private:
    val _JSDelegate;
};


class JSB_TableViewDelegate
: public Ref
, public TableViewDelegate
{
public:
    JSB_TableViewDelegate()
        : _JSDelegate(val::undefined())
    {}

    static JSB_TableViewDelegate* create(const val& pJSDelegate)
    {
      JSB_TableViewDelegate* delegate = new (std::nothrow)JSB_TableViewDelegate();
      if (delegate)
      {
        delegate->setJSDelegate(pJSDelegate);
        delegate->autorelease();
      }
      
      return delegate;
    }

    virtual void scrollViewDidScroll(ScrollView* view) override
    {
        _JSDelegate.call<void>("scrollViewDidScroll", val(view));
    }

    virtual void scrollViewDidZoom(ScrollView* view) override
    {
        _JSDelegate.call<void>("scrollViewDidZoom", val(view));
    }

    virtual void tableCellTouched(TableView* table, TableViewCell* cell) override
    {
        _JSDelegate.call<void>("tableCellTouched", val(table), val(cell));
    }

    virtual void tableCellHighlight(TableView* table, TableViewCell* cell) override
    {
        _JSDelegate.call<void>("tableCellHighlight", val(table), val(cell));
    }

    virtual void tableCellUnhighlight(TableView* table, TableViewCell* cell) override
    {
        _JSDelegate.call<void>("tableCellUnhighlight", val(table), val(cell));
    }

    virtual void tableCellWillRecycle(TableView* table, TableViewCell* cell) override
    {
        _JSDelegate.call<void>("tableCellWillRecycle", val(table), val(cell));
    }

    void setJSDelegate(const val& pJSDelegate)
    {
        _JSDelegate = pJSDelegate;
    }
private:
    val _JSDelegate;
};

class JSB_TableViewDataSource
: public Ref
, public TableViewDataSource
{
public:
    JSB_TableViewDataSource()
        : _JSTableViewDataSource(val::undefined())
    {
    }

    static JSB_TableViewDataSource* create(const val& pJSSource)
    {
      JSB_TableViewDataSource* dataSource = new (std::nothrow)JSB_TableViewDataSource();
      if (dataSource)
      {
        dataSource->setTableViewDataSource(pJSSource);
        dataSource->autorelease();
      }
      
      return dataSource;
    }

    virtual Size tableCellSizeForIndex(TableView *table, ssize_t idx) override
    {
      if (_JSTableViewDataSource.hasOwnProperty("tableCellWillRecycle"))
      {
        return _JSTableViewDataSource.call<Size>("tableCellWillRecycle", val(table), val(idx));
      }
      else
      {
        return _JSTableViewDataSource.call<Size>("cellSizeForTable", val(table));
      }
    }

    virtual TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx) override
    {
      val ret = _JSTableViewDataSource.call<val>("tableCellAtIndex", val(table), val(idx));
      return ret.as<TableViewCell*>(allow_raw_pointers());
    }

    virtual ssize_t numberOfCellsInTableView(TableView *table) override
    {
      return _JSTableViewDataSource.call<ssize_t>("numberOfCellsInTableView", val(table));
    }

    void setTableViewDataSource(const val& pJSSource)
    {
      _JSTableViewDataSource = pJSSource;
    }

private:
    val _JSTableViewDataSource;
};

class JSDownloaderDelegator : public Ref
{
public:
  JSDownloaderDelegator()
  {
      _downloader = std::make_shared<cocos2d::network::Downloader>();
  }

  std::shared_ptr<cocos2d::network::Downloader> _downloader;
};

CC_BINDINGS_ALLOW_RAW_POINTERS(Sprite)
CC_BINDINGS_ALLOW_RAW_POINTERS(Label)
CC_BINDINGS_ALLOW_RAW_POINTERS(ProgressTimer)

COCOS_BINDINGS(jsb_cocos2dx_extension) {


  class_<Control, base<Layer>>("cc.Control")
    .constructor(&cc_bindings_constructor<Control>, allow_raw_pointers())
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
    // from manaul
    .function("addTargetWithActionForControlEvents", optional_override(
      [](const val& thisv, const val& target, const val& action, Control::EventType controlEvents)
      {
        CCLOG("Control::addTargetWithActionForControlEvents not implemented, it uses old school raw function pointer but ccbind prefer std::function");
      }
    ))
    .function("removeTargetWithActionForControlEvents", optional_override(
      [](Control& this_, const val& target, const val& action, Control::EventType controlEvents)
      {
        CCLOG("Control.removeTargetWithActionForControlEvents not implemented, it uses old school raw function pointer but ccbind prefer std::function");
      }
    ))
    // end if manaul
    .property("state", &Control::getState)
    .property("enabled", &Control::isEnabled, &Control::setEnabled)
    .property("selected", &Control::isSelected, &Control::setSelected)
    .property("highlighted", &Control::isHighlighted, &Control::setHighlighted)
    .class_function("create", &Control::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Control& _) -> std::string {return "Control";}))
    ;


  class_<ControlButton, base<Control>>("cc.ControlButton")
    .constructor(&cc_bindings_constructor<ControlButton>, allow_raw_pointers())
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
    .function("initWithLabelAndBackgroundSprite", &ControlButton::initWithLabelAndBackgroundSprite, allow_raw_pointers())
    .function("getZoomOnTouchDown", &ControlButton::getZoomOnTouchDown)
    .function("getTitleForState", &ControlButton::getTitleForState)
    .property("adjustBackgroundImage", optional_override([](const ControlButton& this_)
      {
        return const_cast<ControlButton&>(this_).doesAdjustBackgroundImage();
      }), &ControlButton::setAdjustBackgroundImage)
    .property("zoomOnTouchDown", &ControlButton::getZoomOnTouchDown, &ControlButton::setZoomOnTouchDown)
    .property("preferredSize", &ControlButton::getPreferredSize, &ControlButton::setPreferredSize)
    .property("labelAnchor", &ControlButton::getLabelAnchorPoint, &ControlButton::setLabelAnchorPoint)
    .class_function("create", select_overload<cocos2d::extension::ControlButton*(cocos2d::ui::Scale9Sprite*)>(&ControlButton::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ControlButton*()>(&ControlButton::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ControlButton*(cocos2d::Node*, cocos2d::ui::Scale9Sprite*)>(&ControlButton::create), allow_raw_pointers())
    .class_function("create", optional_override(
      [](const val& arg0, const val& arg1, const val& arg2){
      if (!arg2.isNumber())
      {
        return ControlButton::create(arg0.as<cocos2d::Node*>(allow_raw_pointers()), arg1.as<cocos2d::ui::Scale9Sprite*>(allow_raw_pointers()), arg2.as<bool>());
      } else 
      {
        return ControlButton::create(arg0.as<std::string>(), arg1.as<std::string>(), arg2.as<float>());
      }
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const ControlButton& _) -> std::string {return "ControlButton";}))    
    .allow_subclass<wrapper<ControlButton>>("cc.ControlButton._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ControlHuePicker, base<Control>>("cc.ControlHuePicker")
    .constructor(&cc_bindings_constructor<ControlHuePicker>, allow_raw_pointers())
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
    .property("hue", &ControlHuePicker::getHue, &ControlHuePicker::setHue)
    .property("huePercent", &ControlHuePicker::getHuePercentage, &ControlHuePicker::setHuePercentage)
    .property("background", &ControlHuePicker::getBackground)
    .property("slider", &ControlHuePicker::getSlider)
    .property("startPos", &ControlHuePicker::getStartPos)
    .class_function("create", &ControlHuePicker::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ControlHuePicker& _) -> std::string {return "ControlHuePicker";}))
    ;


  class_<ControlSaturationBrightnessPicker, base<Control>>("cc.ControlSaturationBrightnessPicker")
    .constructor(&cc_bindings_constructor<ControlSaturationBrightnessPicker>, allow_raw_pointers())
    .function("getShadow", &ControlSaturationBrightnessPicker::getShadow, allow_raw_pointers())
    .function("initWithTargetAndPos", &ControlSaturationBrightnessPicker::initWithTargetAndPos, allow_raw_pointers())
    .function("getStartPos", &ControlSaturationBrightnessPicker::getStartPos)
    .function("getOverlay", &ControlSaturationBrightnessPicker::getOverlay, allow_raw_pointers())
    .function("getSlider", &ControlSaturationBrightnessPicker::getSlider, allow_raw_pointers())
    .function("getBackground", &ControlSaturationBrightnessPicker::getBackground, allow_raw_pointers())
    .function("getSaturation", &ControlSaturationBrightnessPicker::getSaturation)
    .function("getBrightness", &ControlSaturationBrightnessPicker::getBrightness)
    .property("saturation", &ControlSaturationBrightnessPicker::getSaturation)
    .property("brightness", &ControlSaturationBrightnessPicker::getBrightness)
    .property("background", &ControlSaturationBrightnessPicker::getBackground)
    .property("overlay", &ControlSaturationBrightnessPicker::getOverlay)
    .property("shadow", &ControlSaturationBrightnessPicker::getShadow)
    .property("slider", &ControlSaturationBrightnessPicker::getSlider)
    .property("startPos", &ControlSaturationBrightnessPicker::getStartPos)
    .class_function("create", &ControlSaturationBrightnessPicker::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ControlSaturationBrightnessPicker& _) -> std::string {return "ControlSaturationBrightnessPicker";}))
    ;


  class_<ControlColourPicker, base<Control>>("cc.ControlColourPicker")
    .constructor(&cc_bindings_constructor<ControlColourPicker>, allow_raw_pointers())
    .function("hueSliderValueChanged", &ControlColourPicker::hueSliderValueChanged, allow_raw_pointers())
    .function("getHuePicker", &ControlColourPicker::getHuePicker, allow_raw_pointers())
    .function("getcolourPicker", &ControlColourPicker::getcolourPicker, allow_raw_pointers())
    .function("setBackground", &ControlColourPicker::setBackground, allow_raw_pointers())
    .function("setcolourPicker", &ControlColourPicker::setcolourPicker, allow_raw_pointers())
    .function("colourSliderValueChanged", &ControlColourPicker::colourSliderValueChanged, allow_raw_pointers())
    .function("setHuePicker", &ControlColourPicker::setHuePicker, allow_raw_pointers())
    .function("getBackground", &ControlColourPicker::getBackground, allow_raw_pointers())
    .property("background", &ControlColourPicker::getBackground)
    .class_function("create", &ControlColourPicker::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ControlColourPicker& _) -> std::string {return "ControlColourPicker";}))    
    .allow_subclass<wrapper<ControlColourPicker>>("cc.ControlColourPicker._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ControlPotentiometer, base<Control>>("cc.ControlPotentiometer")
    .constructor(&cc_bindings_constructor<ControlPotentiometer>, allow_raw_pointers())
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
    .property("value", optional_override([](const ControlPotentiometer& this_)
      {
        return const_cast<ControlPotentiometer&>(this_).getValue();
      }), &ControlPotentiometer::setValue)
    .property("minValue", optional_override([](const ControlPotentiometer& this_)
      {
        return const_cast<ControlPotentiometer&>(this_).getMinimumValue();
      }), &ControlPotentiometer::setMinimumValue)
    .property("maxValue", optional_override([](const ControlPotentiometer& this_)
      {
        return const_cast<ControlPotentiometer&>(this_).getMaximumValue();
      }), &ControlPotentiometer::setMaximumValue)
    .property("progressTimer", &ControlPotentiometer::getProgressTimer, &ControlPotentiometer::setProgressTimer)
    .property("thumbSprite", &ControlPotentiometer::getThumbSprite, &ControlPotentiometer::setThumbSprite)
    .property("prevLocation", &ControlPotentiometer::getPreviousLocation, &ControlPotentiometer::setPreviousLocation)
    .class_function("create", &ControlPotentiometer::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ControlPotentiometer& _) -> std::string {return "ControlPotentiometer";}))    
    .allow_subclass<wrapper<ControlPotentiometer>>("cc.ControlPotentiometer._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ControlSlider, base<Control>>("cc.ControlSlider")
    .constructor(&cc_bindings_constructor<ControlSlider>, allow_raw_pointers())
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
    .class_function("create", optional_override(
      [](const val& arg0, const val& arg1, const val& arg2){
      if (arg0.isString())
      {
        return ControlSlider::create(arg0.as<std::string>().c_str(), arg1.as<std::string>().c_str(), arg2.as<std::string>().c_str());
      } else 
      {
        return ControlSlider::create(arg0.as<cocos2d::Sprite*>(allow_raw_pointers()), arg1.as<cocos2d::Sprite*>(allow_raw_pointers()), arg2.as<cocos2d::Sprite*>(allow_raw_pointers()));
      }
      }), allow_raw_pointers())
    .class_function("create", optional_override(
      [](const val& arg0, const val& arg1, const val& arg2, const val& arg3){
      if (!arg0.isString())
      {
        return ControlSlider::create(arg0.as<cocos2d::Sprite*>(allow_raw_pointers()), arg1.as<cocos2d::Sprite*>(allow_raw_pointers()), arg2.as<cocos2d::Sprite*>(allow_raw_pointers()), arg3.as<cocos2d::Sprite*>(allow_raw_pointers()));
      } else 
      {
        return ControlSlider::create(arg0.as<std::string>().c_str(), arg1.as<std::string>().c_str(), arg2.as<std::string>().c_str(), arg3.as<std::string>().c_str());
      }
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const ControlSlider& _) -> std::string {return "ControlSlider";}))    
    .allow_subclass<wrapper<ControlSlider>>("cc.ControlSlider._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ControlStepper, base<Control>>("cc.ControlStepper")
    .constructor(&cc_bindings_constructor<ControlStepper>, allow_raw_pointers())
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
    .property("wraps", optional_override([](const ControlStepper& this_)
      {
        CCLOG("ControlStepper.wraps is write-only");
        return false;
      }), &ControlStepper::setWraps)
    .property("value", &ControlStepper::getValue, &ControlStepper::setValue)
    .property("minValue", optional_override([](const ControlStepper& this_) -> double
      {
        CCLOG("ControlStepper.minValue is write-only");
        return 0;
      }), &ControlStepper::setMinimumValue)
    .property("maxValue", optional_override([](const ControlStepper& this_) -> double
      {
        CCLOG("ControlStepper.maxValue is write-only");
        return 0;
      }), &ControlStepper::setMaximumValue)
    .property("stepValue", optional_override([](const ControlStepper& this_) -> double
      {
        CCLOG("ControlStepper.stepValue is write-only");
        return 0;
      }), &ControlStepper::setStepValue)
    .property("continuous", &ControlStepper::isContinuous)
    .property("minusSprite", &ControlStepper::getMinusSprite, &ControlStepper::setMinusSprite)
    .property("plusSprite", &ControlStepper::getPlusSprite, &ControlStepper::setPlusSprite)
    .property("minusLabel", &ControlStepper::getMinusLabel, &ControlStepper::setMinusLabel)
    .property("plusLabel", &ControlStepper::getPlusLabel, &ControlStepper::setPlusLabel)
    .class_function("create", &ControlStepper::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ControlStepper& _) -> std::string {return "ControlStepper";}))    
    .allow_subclass<wrapper<ControlStepper>>("cc.ControlStepper._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ControlSwitch, base<Control>>("cc.ControlSwitch")
    .constructor(&cc_bindings_constructor<ControlSwitch>, allow_raw_pointers())
    .function("setOn", select_overload<void(bool)>(&ControlSwitch::setOn))
    .function("setOn", select_overload<void(bool, bool)>(&ControlSwitch::setOn))
    .function("locationFromTouch", &ControlSwitch::locationFromTouch, allow_raw_pointers())
    .function("isOn", &ControlSwitch::isOn)
    .function("initWithMaskSprite", select_overload<bool(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Label*, cocos2d::Label*)>(&ControlSwitch::initWithMaskSprite), allow_raw_pointers())
    .function("initWithMaskSprite", select_overload<bool(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*)>(&ControlSwitch::initWithMaskSprite), allow_raw_pointers())
    .function("hasMoved", &ControlSwitch::hasMoved)
    .class_function("create", select_overload<cocos2d::extension::ControlSwitch*(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*)>(&ControlSwitch::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ControlSwitch*(cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Sprite*, cocos2d::Label*, cocos2d::Label*)>(&ControlSwitch::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ControlSwitch& _) -> std::string {return "ControlSwitch";}))    
    .allow_subclass<wrapper<ControlSwitch>>("cc.ControlSwitch._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ScrollView, base<Layer>>("cc.ScrollView")
    .constructor(&cc_bindings_constructor<ScrollView>, allow_raw_pointers())
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
    .function("pause", select_overload<void(Ref*)>(&ScrollView::pause), allow_raw_pointers())
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
    .function("resume", select_overload<void(Ref*)>(&ScrollView::resume), allow_raw_pointers())
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
    // from manual
    .function("setDelegate", optional_override(
        [](ScrollView& this_, const val& arg0){
          JSB_ScrollViewDelegate* nativeDelegate = new (std::nothrow) JSB_ScrollViewDelegate();
          nativeDelegate->setJSDelegate(arg0);
          this_.setDelegate(nativeDelegate);
          this_.setUserObject(nativeDelegate);
          nativeDelegate->release();
      }))
    // end of manual
    .property("direction", &ScrollView::getDirection, &ScrollView::setDirection)
    .class_function("create", select_overload<cocos2d::extension::ScrollView*()>(&ScrollView::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::extension::ScrollView*(cocos2d::Size, cocos2d::Node*)>(&ScrollView::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ScrollView& _) -> std::string {return "ScrollView";}))    
    .allow_subclass<wrapper<ScrollView>>("cc.ScrollView._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TableViewCell, base<Node>>("cc.TableViewCell")
    .constructor(&cc_bindings_constructor<TableViewCell>, allow_raw_pointers())
    .function("reset", &TableViewCell::reset)
    .function("getIdx", &TableViewCell::getIdx)
    .function("setIdx", &TableViewCell::setIdx)
    // cocos2d-js only
    // .property("objectId", &TableViewCell::getObjectID, &TableViewCell::setObjectID)
    .class_function("create", &TableViewCell::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TableViewCell& _) -> std::string {return "TableViewCell";}))    
    .allow_subclass<wrapper<TableViewCell>>("cc.TableViewCell._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TableView, base<ScrollView>>("cc.TableView")
    .constructor(&cc_bindings_constructor<TableView>, allow_raw_pointers())
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
    // from manual
    .function("setDelegate", optional_override(
        [](TableView& this_, const val& arg0) {
          this_.setDelegate(JSB_TableViewDelegate::create(arg0));
      }))
    .function("setDataSource", optional_override(
        [](TableView& this_, const val& arg0) {
          this_.setDataSource(JSB_TableViewDataSource::create(arg0));
      }))
    .function("_init", optional_override(
        [](TableView& this_, const val& arg0, const Size& arg1) {
          this_.setDelegate(JSB_TableViewDelegate::create(arg0));
          return this_.initWithViewSize(arg1);
      }))
    .function("_init", optional_override(
        [](TableView& this_, const val& arg0, const Size& arg1, Node* arg2) {
          this_.setDelegate(JSB_TableViewDelegate::create(arg0));
          return this_.initWithViewSize(arg1, arg2);
      }), allow_raw_pointers())
    .class_function("create", optional_override(
        [](const val& arg0, const Size& arg1) {
          return TableView::create(JSB_TableViewDataSource::create(arg0), arg1);
      }), allow_raw_pointers())
    .class_function("create", optional_override(
        [](const val& arg0, const Size& arg1, Node* arg2) {
          return TableView::create(JSB_TableViewDataSource::create(arg0), arg1, arg2);
      }), allow_raw_pointers())
    // end of manual
    .property("_className",  optional_override([](const TableView& _) -> std::string {return "TableView";}))    
    .allow_subclass<wrapper<TableView>>("cc.TableView._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EventAssetsManagerEx, base<EventCustom>>("cc.EventAssetsManager")
    .constructor(&cc_bindings_constructor<EventAssetsManagerEx, const std::string&, cocos2d::extension::AssetsManagerEx*, const cocos2d::extension::EventAssetsManagerEx::EventCode&, float, float, const std::string&, const std::string&, int, int>, allow_raw_pointers())
    .function("getAssetsManagerEx", &EventAssetsManagerEx::getAssetsManagerEx, allow_raw_pointers())
    .function("getAssetId", &EventAssetsManagerEx::getAssetId)
    .function("getCURLECode", &EventAssetsManagerEx::getCURLECode)
    .function("getMessage", &EventAssetsManagerEx::getMessage)
    .function("getCURLMCode", &EventAssetsManagerEx::getCURLMCode)
    .function("getPercentByFile", &EventAssetsManagerEx::getPercentByFile)
    .function("getEventCode", &EventAssetsManagerEx::getEventCode)
    .function("getPercent", &EventAssetsManagerEx::getPercent)
    // from manual
    .function("retain", &EventAssetsManagerEx::retain)
    .function("release", &EventAssetsManagerEx::release)
    // end of manual
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
    // from manual
    .function("retain", &Manifest::retain)
    .function("release", &Manifest::release)
    // end of manual
    .property("_className",  optional_override([](const Manifest& _) -> std::string {return "Manifest";}))    
    ;


  class_<AssetsManagerEx>("cc.AssetsManager")
    .constructor(&cc_bindings_constructor<AssetsManagerEx, const std::string&, const std::string&>, allow_raw_pointers())
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
    .constructor(&cc_bindings_constructor<EventListenerAssetsManagerEx>, allow_raw_pointers())
    // from manual 
    .function("init", optional_override(
      [](const val& thisv, AssetsManagerEx *arg0, const val& callback)
      {
        EventListenerAssetsManagerEx& this_ = thisv.as<EventListenerAssetsManagerEx&>();
        return this_.init(arg0, [callback, thisv](EventAssetsManagerEx* larg0) {
          callback.call<void>("call", thisv, val(larg0));
        });
      }
    ), allow_raw_pointers())
    .class_function("create", optional_override(
      [](AssetsManagerEx *arg0, const val& callback)
      {
        val thisv(val::global("cc")["EventListenerAssetsManager"]);
        return EventListenerAssetsManagerEx::create(arg0, [callback, thisv](EventAssetsManagerEx* larg0) {
          callback.call<void>("call", thisv, val(larg0));
        });
      }
    ), allow_raw_pointers())
    // end of manual
    .property("_className",  optional_override([](const EventListenerAssetsManagerEx& _) -> std::string {return "EventListenerAssetsManagerEx";}))
    .allow_subclass<wrapper<EventListenerAssetsManagerEx>>("cc.EventListenerAssetsManagerEx._extend")    
    ;

  cocos2d::bindings::function("__jsb_loadRemoteImg", optional_override(
    [](const std::string& url, const val& callback)
    {
      JSDownloaderDelegator* downloader = new JSDownloaderDelegator();
      downloader->autorelease();
      downloader->retain();
      downloader->_downloader->createDownloadDataTask(url);

      downloader->_downloader->onDataTaskSuccess = ([downloader, callback] (const network::DownloadTask& task, std::vector<unsigned char>& data) {
          Image* img = new (std::nothrow) Image();
          Texture2D *tex = nullptr;
          if (img->initWithImageData(data.data(), data.size()))
          {
            tex = Director::getInstance()->getTextureCache()->addImage(img, task.requestURL);
          }
          CC_SAFE_RELEASE(img);

          if (tex)
          {
              callback(val(true), val(tex));
          }
          else
          {
              callback(val(false));
          }

          downloader->release();
      });

      downloader->_downloader->onTaskError = ([downloader, callback] (const network::DownloadTask& task, int errorCode, int errorCodeInternal, const std::string& errorStr) {
          CCLOG("downloader task failed : %s, identifier(%s) error code(%d), internal error code(%d) desc(%s)"
              , task.requestURL.c_str()
              , task.identifier.c_str()
              , errorCode
              , errorCodeInternal
              , errorStr.c_str());
          callback(val(false));
          downloader->release();
      });    
    }
  ));
}