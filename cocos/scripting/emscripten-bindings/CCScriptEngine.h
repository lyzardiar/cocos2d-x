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

#ifndef __CC_SCRIPT_ENGINE_H__
#define __CC_SCRIPT_ENGINE_H__

#include "base/CCScriptSupport.h"
#include "base/CCEventMouse.h"
#include "ui/UIWidget.h"
#include "CCScriptBindings.h"

NS_CC_BINDINGS_BEGIN

class CC_DLL ScriptEngine : public ScriptEngineProtocol
{
protected:
    /** 
    * Constructor of ScriptEngine.
    *
    * @lua NA
    * @js NA
    */
    ScriptEngine();
    
    /**
    * Destructor of ScriptEngine.
    *
    * @lua NA
    * @js NA
    */
    virtual ~ScriptEngine() {}
    
public:
    static ScriptEngine* getInstance();

    /**
     * Gets the script type, for ScriptingCore
     *
     * @return `the script type`
     */
    virtual ccScriptType getScriptType() override { return kScriptTypeJavascript; };

    /**
    * Execute script code contained in the given string.
    *
    * @param codes holding the valid script code that should be executed.
    * @return 0 if the string is executed correctly.
    * @return other if the string is executed wrongly.
    * @lua NA
    * @js NA
    */
    virtual int executeString(const char* codes) override;
    
    /**
    * Execute a script file.
    * 
    * @param filename String object holding the filename of the script file that is to be executed.
    * @return 0 if it happen the error or it hasn't return value, otherwise it return the value by calling the lua function.
    * @lua NA
    * @js NA
    */
    virtual int executeScriptFile(const char* filename) override;
    
    /**
    * Execute a scripted global function.
    * The function should not take any parameters and should return an integer.
    *
    * @param functionName String object holding the name of the function, in the global script environment, that is to be executed.
    * @return The integer value returned from the script function.
    * @lua NA
    * @js NA
    */
    virtual int executeGlobalFunction(const char* functionName) override;
    
    /**
    * When trigger a script event ,call this func,add params needed into ScriptEvent object.nativeObject is object triggering the event, can be nullptr in Lua.
    *
    *
    * @lua NA
    * @js NA
    */
    virtual int sendEvent(ScriptEvent* evt) override;
    
    /** 
    * Handle the assert message.
    *
    * @return true if the assert was handled by the script engine, false otherwise.
    *
    * @lua NA
    * @js NA
    */
    virtual bool handleAssert(const char *msg) override;
    
    /** 
    * Parse configuration file.
    * 
    * @param type the specific type value.
    * @param str the information data.
    *
    * @lua NA
    * @js NA
    */
    virtual bool parseConfig(ConfigType type, const std::string& str) override;

    virtual void removeScriptObjectByObject(Ref* pObj) override;

    virtual void setCalledFromScript(bool callFromScript) override { _callFromScript = callFromScript; };
    virtual bool isCalledFromScript() override { return _callFromScript; };

    int handleNodeEvent(void* data);
    bool handleTouchEvent(void* nativeObj, cocos2d::EventTouch::EventCode eventCode, cocos2d::Touch* touch, cocos2d::Event* event, bool& jsvalRet);
    bool handleTouchEvent(void* nativeObj, cocos2d::EventTouch::EventCode eventCode, cocos2d::Touch* touch, cocos2d::Event* event);
    bool handleTouchesEvent(void* nativeObj, cocos2d::EventTouch::EventCode eventCode, const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
    bool handleMouseEvent(void* nativeObj, cocos2d::EventMouse::MouseEventType eventType, cocos2d::Event* event);
    bool handleKeyboardEvent(void* nativeObj, cocos2d::EventKeyboard::KeyCode keyCode, bool isPressed, cocos2d::Event* event);
    bool handleFocusEvent(void* nativeObj, cocos2d::ui::Widget* widgetLoseFocus, cocos2d::ui::Widget* widgetGetFocus);
private:
    bool _callFromScript;
};

NS_CC_BINDINGS_END

#endif // __CC_SCRIPT_ENGINE_H__
