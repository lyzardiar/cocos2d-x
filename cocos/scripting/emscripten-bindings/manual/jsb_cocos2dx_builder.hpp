#ifndef __JSB_COCOS2DX_BUILDER_HPP__
#define __JSB_COCOS2DX_BUILDER_HPP__

#include "scripting/emscripten-bindings/CCScriptBindings.h"
#include "editor-support/cocosbuilder/CocosBuilder.h"

class CCBScriptCallbackProxy:  public cocos2d::Layer
, public cocosbuilder::CCBSelectorResolver
, public cocosbuilder::CCBMemberVariableAssigner {
    
    std::string callBackProp;
    cocos2d::bindings::val owner;

public:


    CCBScriptCallbackProxy (): owner(cocos2d::bindings::val::undefined()) {}
    virtual ~CCBScriptCallbackProxy() {}

    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(CCBScriptCallbackProxy, create);
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget,
                                                                    const char * pSelectorName);

    virtual cocos2d::extension::Control::Handler onResolveCCBCCControlSelector(cocos2d::Ref * pTarget,
                                                                                   const char * pSelectorName);
    virtual bool onAssignCCBMemberVariable(cocos2d::Ref * pTarget, const char * pMemberVariableName,
                                           cocos2d::Node * pNode);
    virtual void onNodeLoaded(cocos2d::Node * pNode,
                              cocosbuilder::NodeLoader * pNodeLoader);
        
    virtual CCBSelectorResolver * createNew();
    void menuItemCallback(Ref *pSender);
    void controlCallback(Ref *pSender, cocos2d::extension::Control::EventType event);
    void setCallbackProperty(const char *prop);
    void setJSOwner(cocos2d::bindings::val ownr);
    cocos2d::bindings::val getJSOwner();
};

class JSLayerLoader : public cocosbuilder::LayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(JSLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CCBScriptCallbackProxy);
};

class JSCCBAnimationWrapper: public cocos2d::Ref 
{
    cocos2d::bindings::val callback;
    cocos2d::bindings::val caller;
public:
    JSCCBAnimationWrapper (const cocos2d::bindings::val& pCaller, const cocos2d::bindings::val& pCallback) 
    :caller(pCaller),
    callback(pCallback)
    {
    }
    
    void animationCompleteCallback()
    {
        // NOTE: "call" is JS specific
        callback.call<void>("call", caller);
    }
};

#endif /* __JSB_COCOS2DX_BUILDER_HPP__ */