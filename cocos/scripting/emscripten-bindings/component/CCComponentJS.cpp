/****************************************************************************
 Copyright (c) 2015-2016 Chukong Technologies Inc.
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

#include "scripting/emscripten-bindings/component/CCComponentJS.h"
#include "base/CCScriptSupport.h"

NS_CC_BEGIN

const std::string ComponentJS::ON_ENTER = "onEnter";
const std::string ComponentJS::ON_EXIT = "onExit";
const std::string ComponentJS::UPDATE = "update";

ComponentJS* ComponentJS::create(const std::string& scriptFileName)
{
    CC_ASSERT(!scriptFileName.empty());
    
    auto componentJS = new(std::nothrow) ComponentJS(scriptFileName);
    if (componentJS)
    {
        componentJS->autorelease();
    }
    
    return componentJS;
}

ComponentJS::ComponentJS(const std::string& scriptFileName)
: _scriptFileName(scriptFileName)
, _jsObj(nullptr)
{
    
}

ComponentJS::~ComponentJS()
{
    
}

void* ComponentJS::getScriptObject() const
{
    return nullptr;
}

void ComponentJS::update(float delta)
{
    if (_succeedLoadingScript)
    {
        
    }
}

void ComponentJS::onEnter()
{
    if (_succeedLoadingScript)
    {
        
    }
}

void ComponentJS::onExit()
{
    if (_succeedLoadingScript)
    {
        
    }
}

NS_CC_END
