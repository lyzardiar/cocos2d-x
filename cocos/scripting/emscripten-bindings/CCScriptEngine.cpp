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
#include "base/CCRef.h"
#include "2d/CCNode.h"


CC_BINDINGS_ALLOW_RAW_POINTERS(cocos2d::Ref);
CC_BINDINGS_ALLOW_RAW_POINTERS(cocos2d::Node);


NS_CC_BINDINGS_BEGIN

static std::string getTouchesFuncName(EventTouch::EventCode eventCode)
{
    std::string funcName;
    switch(eventCode)
    {
        case EventTouch::EventCode::BEGAN:
            funcName = "onTouchesBegan";
            break;
        case EventTouch::EventCode::ENDED:
            funcName = "onTouchesEnded";
            break;
        case EventTouch::EventCode::MOVED:
            funcName = "onTouchesMoved";
            break;
        case EventTouch::EventCode::CANCELLED:
            funcName = "onTouchesCancelled";
            break;
        default:
            CCASSERT(false, "Invalid event code!");
            break;
    }
    return funcName;
}

static std::string getTouchFuncName(EventTouch::EventCode eventCode)
{
    std::string funcName;
    switch(eventCode) {
        case EventTouch::EventCode::BEGAN:
            funcName = "onTouchBegan";
            break;
        case EventTouch::EventCode::ENDED:
            funcName = "onTouchEnded";
            break;
        case EventTouch::EventCode::MOVED:
            funcName = "onTouchMoved";
            break;
        case EventTouch::EventCode::CANCELLED:
            funcName = "onTouchCancelled";
            break;
        default:
            CCASSERT(false, "Invalid event code!");
    }

    return funcName;
}

static std::string getMouseFuncName(EventMouse::MouseEventType eventType)
{
    std::string funcName;
    switch(eventType) {
        case EventMouse::MouseEventType::MOUSE_DOWN:
            funcName = "onMouseDown";
            break;
        case EventMouse::MouseEventType::MOUSE_UP:
            funcName = "onMouseUp";
            break;
        case EventMouse::MouseEventType::MOUSE_MOVE:
            funcName = "onMouseMove";
            break;
        case EventMouse::MouseEventType::MOUSE_SCROLL:
            funcName = "onMouseScroll";
            break;
        default:
            CCASSERT(false, "Invalid event code!");
    }

    return funcName;
}

ScriptEngine::ScriptEngine()
:_callFromScript(false)
{
}
    
ScriptEngine* ScriptEngine::getInstance()
{
    static ScriptEngine* instance = nullptr;
    if (instance == nullptr)
    {
        instance = new (std::nothrow) ScriptEngine();
    }
    return instance;
}

int ScriptEngine::executeString(const char* codes)
{
    return 0;
}

int ScriptEngine::executeScriptFile(const char* filename)
{
    return 0;
}

int ScriptEngine::executeGlobalFunction(const char* functionName)
{
    return 0;
}

int ScriptEngine::sendEvent(ScriptEvent* evt)
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
            // Node bindings override event functions and call js functions accordingly
            break;
        case kScriptActionEvent:
            break;
        case kMenuClickedEvent:
            break;
        case kTouchEvent:
            {
                TouchScriptData* data = (TouchScriptData*)evt->data;
                return handleTouchEvent(data->nativeObject, data->actionType, data->touch, data->event);
            }
            break;
        case kTouchesEvent:
            {
                TouchesScriptData* data = (TouchesScriptData*)evt->data;
                return handleTouchesEvent(data->nativeObject, data->actionType, data->touches, data->event);
            }
            break;
        case kComponentEvent:
            break;
        default:
            CCASSERT(false, "Invalid script event.");
            break;
    }

    return 0;
}

bool ScriptEngine::handleTouchEvent(void* nativeObj, cocos2d::EventTouch::EventCode eventCode, cocos2d::Touch* touch, cocos2d::Event* event, bool& ret)
{
    std::string funcName = getTouchFuncName(eventCode);
    
    val& handler = *(static_cast<val*>(nativeObj));

    if (handler.isUndefined() || handler[funcName].isUndefined())
        return false;

    ret = handler.call<bool>(funcName.c_str(), val(touch), val(event));
    return true;
}

bool ScriptEngine::handleTouchEvent(void* nativeObj, cocos2d::EventTouch::EventCode eventCode, cocos2d::Touch* touch, cocos2d::Event* event)
{
    std::string funcName = getTouchFuncName(eventCode);
    
    val& handler = *(static_cast<val*>(nativeObj));

    if (handler.isUndefined() || handler[funcName].isUndefined())
        return false;

    handler.call<void>(funcName.c_str(), val(touch), val(event));
    return true;
}

bool ScriptEngine::handleTouchesEvent(void* nativeObj, cocos2d::EventTouch::EventCode eventCode, const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
    std::string funcName = getTouchesFuncName(eventCode);
    
    val& handler = *(static_cast<val*>(nativeObj));

    if (handler.isUndefined() || handler[funcName].isUndefined())
        return false;

    handler.call<void>(funcName.c_str(), val(touches), val(event));
    return true;
}

bool ScriptEngine::handleMouseEvent(void* nativeObj, cocos2d::EventMouse::MouseEventType eventType, cocos2d::Event* event)
{
    std::string funcName = getMouseFuncName(eventType);
    
    val& handler = *(static_cast<val*>(nativeObj));

    if (handler.isUndefined() || handler[funcName].isUndefined())
        return false;

    handler.call<void>(funcName.c_str(), val(event));
    return true;
}

bool ScriptEngine::handleKeyboardEvent(void* nativeObj, cocos2d::EventKeyboard::KeyCode keyCode, bool isPressed, cocos2d::Event* event)
{
    val& handler = *(static_cast<val*>(nativeObj));

    if (handler.isUndefined())
        return false;

    if (isPressed)
    {
        if(!handler["_onKeyPressed"].isUndefined())
        {
            handler.call<void>("_onKeyPressed", val(keyCode), val(event));
            return true;
        }
    }
    else
    {
        if(!handler["_onKeyReleased"].isUndefined())
        {
            handler.call<void>("_onKeyReleased", val(keyCode), val(event));
            return true;
        }
    }
    
    return false;
}


bool ScriptEngine::handleFocusEvent(void* nativeObj, cocos2d::ui::Widget* widgetLoseFocus, cocos2d::ui::Widget* widgetGetFocus)
{
    val& handler = *(static_cast<val*>(nativeObj));

    if (handler.isUndefined() || !!handler["onFocusChanged"].isUndefined())
        return false;

    handler.call<void>("onFocusChanged", val(widgetLoseFocus), val(widgetGetFocus));
    return true;
}

bool ScriptEngine::handleAssert(const char *msg)
{
    return false;
}

bool ScriptEngine::parseConfig(ConfigType type, const std::string& str)
{
    return false;
}

void ScriptEngine::removeScriptObjectByObject(Ref* pObj)
{
}

NS_CC_BINDINGS_END
