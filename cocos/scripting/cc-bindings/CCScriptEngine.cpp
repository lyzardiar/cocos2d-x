/****************************************************************************
 Copyright (c) 2012      cocos2d-x.org
 Copyright (c) 2013-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "CCScriptEngine.h"
#include "2d/CCNode.h"
#include "scripting/cc-bindings/embind/val.h"

NS_CC_BINDINGS_BEGIN

CCScriptEngine::CCScriptEngine()
:_callFromScript(false)
{
}
    
CCScriptEngine* CCScriptEngine::getInstance()
{
    static CCScriptEngine* instance = nullptr;
    if (instance == nullptr)
    {
        instance = new (std::nothrow) CCScriptEngine();
    }
    return instance;
}

int CCScriptEngine::executeString(const char* codes)
{
    return 0;
}

int CCScriptEngine::executeScriptFile(const char* filename)
{
    return 0;
}

int CCScriptEngine::executeGlobalFunction(const char* functionName)
{
    return 0;
}

int CCScriptEngine::sendEvent(ScriptEvent* evt)
{
    if (NULL == evt)
        return 0;

    if (evt->type == kRestartGame)
    {
        return 0;
    }

    switch (evt->type)
    {
        case kNodeEvent:
            {
                return handleNodeEvent(evt->data);
            }
            break;
        case kScriptActionEvent:
            break;
        case kMenuClickedEvent:
            break;
        case kTouchEvent:
            break;
        case kTouchesEvent:
            break;
        case kComponentEvent:
            break;
        default:
            CCASSERT(false, "Invalid script event.");
            break;
    }

    return 0;
}


int CCScriptEngine::handleNodeEvent(void* data)
{
    if (NULL == data)
        return 0;
    
    BasicScriptData* basicScriptData = (BasicScriptData*)data;
    if (NULL == basicScriptData->nativeObject || NULL == basicScriptData->value)
        return 0;
    
    val handler = emscripten::val::global("_native_js_global_map").call<val>("get", val((int)basicScriptData->nativeObject));
    
    if (handler.isUndefined())
        return 0;
    
    int action = *((int*)(basicScriptData->value));
    switch (action)
    {
        case cocos2d::kNodeOnEnter:
            handler.call<void>("onEnter");
            return 0;
            
        case kNodeOnExit:
            handler.call<void>("onExit");
            return 0;
            
        case kNodeOnEnterTransitionDidFinish:
            handler.call<void>("onEnterTransitionDidFinish");
            return 0;
            
        case kNodeOnExitTransitionDidStart:
            handler.call<void>("onExitTransitionDidStart");
            return 0;
            
        case kNodeOnCleanup:
            handler.call<void>("cleanup");
            return 0;
            
        default:
            return 0;
    }
}

bool CCScriptEngine::handleAssert(const char *msg)
{
    return false;
}

bool CCScriptEngine::parseConfig(ConfigType type, const std::string& str)
{
    return false;
}

NS_CC_BINDINGS_END
