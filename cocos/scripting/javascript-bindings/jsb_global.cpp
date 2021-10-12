#include "scripting/CCScriptBindings.h"
#include "scripting/javascript-bindings/jsb_global.h"
#include "cocos2d.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

struct __jsc__{

};

COCOS_BINDINGS(jsb_core) {
  cocos2d::bindings::function("__getPlatform", optional_override([](){
    return (int)cocos2d::Application::getInstance()->getTargetPlatform();
  })); 

  cocos2d::bindings::function("__getOS", optional_override([]()-> std::string {
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

  cocos2d::bindings::function("__getVersion", optional_override([](){CCLOG("__getVersion not implemented");}));
  cocos2d::bindings::function("__restartVM", optional_override([](){CCLOG("__restartVM not implemented");}));
  cocos2d::bindings::function("__cleanScript", optional_override([](){CCLOG("__cleanScript not implemented");}));
  cocos2d::bindings::function("__isObjectValid", optional_override([](){CCLOG("__isObjectValid not implemented");}));
  cocos2d::bindings::function("close", optional_override([](){CCLOG("close not implemented");}));
}
