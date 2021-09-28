#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_misc.hpp"
#include "cocos2d.h"

using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(cocos2dx_misc) {
  function("__getPlatform", optional_override([](){
    return (int)cocos2d::Application::getInstance()->getTargetPlatform();
  })); 

  function("__getOS", optional_override([]()-> std::string {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    return "iOS";
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    return "Android";
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
    return "Windows";
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
    return "Marmalade";
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
    return "Linux";
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_BADA)
    return "Bada";
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY)
    return "Blackberry";
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
    return "OS X";
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    return "WINRT";
#else
    return "Unknown";
#endif
  })); 


  
  // value objects
  value_object<Rect>("cc.Rect")
    .field("origin", &Rect::origin)
    .field("size", &Rect::size)
    ;
  value_object<Vec2>("cc.Vec2")
    .field("x", &Vec2::x)
    .field("y", &Vec2::y)
    ;
  value_object<Size>("cc.Size")
    .field("width", &Size::width)
    .field("height", &Size::height)
    ;
}
