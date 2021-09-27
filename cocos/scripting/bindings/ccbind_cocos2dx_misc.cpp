#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_misc.hpp"
#include "cocos2d.h"

using namespace std::placeholders;
using namespace cocos2d::bindings;

COCOS_BINDINGS(cocos2dx_misc) {
  function("__getPlatform", optional_override([](){
    return (int)cocos2d::Application::getInstance()->getTargetPlatform();
  })); 
}
