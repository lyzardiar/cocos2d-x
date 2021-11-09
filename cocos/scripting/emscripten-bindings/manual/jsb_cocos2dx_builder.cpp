#include "scripting/emscripten-bindings/manual/jsb_cocos2dx_builder.hpp"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace cocos2d::extension;
using namespace cocosbuilder;

COCOS_BINDINGS(jsb_cocos2dx_builder) {


  class_<CCBAnimationManager>("cc.BuilderAnimationManager")
    .constructor(&cc_bindings_constructor<CCBAnimationManager>, allow_raw_pointers())
    .function("moveAnimationsFromNode", &CCBAnimationManager::moveAnimationsFromNode, allow_raw_pointers())
    .function("setAutoPlaySequenceId", &CCBAnimationManager::setAutoPlaySequenceId)
    .function("getDocumentCallbackNames", &CCBAnimationManager::getDocumentCallbackNames)
    .function("actionForSoundChannel", &CCBAnimationManager::actionForSoundChannel, allow_raw_pointers())
    .function("setBaseValue", &CCBAnimationManager::setBaseValue, allow_raw_pointers())
    .function("getDocumentOutletNodes", &CCBAnimationManager::getDocumentOutletNodes)
    .function("getLastCompletedSequenceName", &CCBAnimationManager::getLastCompletedSequenceName)
    .function("setRootNode", &CCBAnimationManager::setRootNode, allow_raw_pointers())
    .function("runAnimationsForSequenceNamedTweenDuration", &CCBAnimationManager::runAnimationsForSequenceNamedTweenDuration, allow_raw_pointers())
    .function("addDocumentOutletName", &CCBAnimationManager::addDocumentOutletName)
    .function("getRootContainerSize", &CCBAnimationManager::getRootContainerSize)
    .function("setDocumentControllerName", &CCBAnimationManager::setDocumentControllerName)
    .function("setObject", &CCBAnimationManager::setObject, allow_raw_pointers())
    .function("getContainerSize", &CCBAnimationManager::getContainerSize, allow_raw_pointers())
    .function("actionForCallbackChannel", &CCBAnimationManager::actionForCallbackChannel, allow_raw_pointers())
    .function("getDocumentOutletNames", &CCBAnimationManager::getDocumentOutletNames)
    .function("addDocumentCallbackControlEvents", &CCBAnimationManager::addDocumentCallbackControlEvents)
    .function("init", &CCBAnimationManager::init)
    .function("getKeyframeCallbacks", &CCBAnimationManager::getKeyframeCallbacks)
    .function("getDocumentCallbackControlEvents", &CCBAnimationManager::getDocumentCallbackControlEvents)
    .function("setRootContainerSize", &CCBAnimationManager::setRootContainerSize)
    .function("runAnimationsForSequenceIdTweenDuration", &CCBAnimationManager::runAnimationsForSequenceIdTweenDuration)
    .function("getRunningSequenceName", &CCBAnimationManager::getRunningSequenceName, allow_raw_pointers())
    .function("getAutoPlaySequenceId", &CCBAnimationManager::getAutoPlaySequenceId)
    .function("addDocumentCallbackName", &CCBAnimationManager::addDocumentCallbackName)
    .function("getRootNode", &CCBAnimationManager::getRootNode, allow_raw_pointers())
    .function("addDocumentOutletNode", &CCBAnimationManager::addDocumentOutletNode, allow_raw_pointers())
    .function("setDelegate", &CCBAnimationManager::setDelegate, allow_raw_pointers())
    .function("getSequenceDuration", &CCBAnimationManager::getSequenceDuration, allow_raw_pointers())
    .function("addDocumentCallbackNode", &CCBAnimationManager::addDocumentCallbackNode, allow_raw_pointers())
    .function("runAnimationsForSequenceNamed", &CCBAnimationManager::runAnimationsForSequenceNamed, allow_raw_pointers())
    .function("getSequenceId", &CCBAnimationManager::getSequenceId, allow_raw_pointers())
    .function("setCallFunc", &CCBAnimationManager::setCallFunc, allow_raw_pointers())
    .function("getDocumentCallbackNodes", &CCBAnimationManager::getDocumentCallbackNodes)
    .function("setSequences", &CCBAnimationManager::setSequences)
    .function("debug", &CCBAnimationManager::debug)
    .function("getDocumentControllerName", &CCBAnimationManager::getDocumentControllerName)
    .function("setCompletedAnimationCallback", optional_override([](CCBAnimationManager& this_, const val& caller, const val& callback)
      {
        JSCCBAnimationWrapper *tmpCobj = new (std::nothrow) JSCCBAnimationWrapper(caller, callback);
        tmpCobj->autorelease();
        this_.setAnimationCompletedCallback(tmpCobj, callfunc_selector(JSCCBAnimationWrapper::animationCompleteCallback));
      }))
    .property("_className",  optional_override([](const CCBAnimationManager& _) -> std::string {return "CCBAnimationManager";}))    
    ;


  class_<CCBReader>("cc._Reader")
    .constructor<>()
    .constructor<NodeLoaderLibrary *, CCBMemberVariableAssigner *, CCBSelectorResolver *, NodeLoaderListener *>()
    .constructor(optional_override([](NodeLoaderLibrary *pNodeLoaderLibrary, CCBMemberVariableAssigner *pCCBMemberVariableAssigner, CCBSelectorResolver *pCCBSelectorResolver) -> CCBReader*{
      return new CCBReader(pNodeLoaderLibrary, pCCBMemberVariableAssigner, pCCBSelectorResolver);
    }), allow_raw_pointers())
    .constructor(optional_override([](NodeLoaderLibrary *pNodeLoaderLibrary, CCBMemberVariableAssigner *pCCBMemberVariableAssigner) -> CCBReader*{
      return new CCBReader(pNodeLoaderLibrary, pCCBMemberVariableAssigner);
    }), allow_raw_pointers())
    .constructor(optional_override([](Ref * arg0) -> CCBReader*{
      if(dynamic_cast<NodeLoaderLibrary*>(arg0))
      {
        return new CCBReader(dynamic_cast<NodeLoaderLibrary*>(arg0));
      }
      else
      {
        return new CCBReader(dynamic_cast<CCBReader*>(arg0));
      }
    }), allow_raw_pointers())
    .function("getAnimationManager", &CCBReader::getAnimationManager, allow_raw_pointers())
    .function("setAnimationManager", &CCBReader::setAnimationManager, allow_raw_pointers())
    .function("addOwnerOutletName", &CCBReader::addOwnerOutletName)
    .function("getOwnerCallbackNames", &CCBReader::getOwnerCallbackNames)
    .function("addDocumentCallbackControlEvents", &CCBReader::addDocumentCallbackControlEvents)
    .function("setCCBRootPath", &CCBReader::setCCBRootPath, allow_raw_pointers())
    .function("addOwnerOutletNode", &CCBReader::addOwnerOutletNode, allow_raw_pointers())
    .function("getOwnerCallbackNodes", &CCBReader::getOwnerCallbackNodes)
    .function("readSoundKeyframesForSeq", &CCBReader::readSoundKeyframesForSeq, allow_raw_pointers())
    .function("getCCBRootPath", &CCBReader::getCCBRootPath)
    .function("getOwnerCallbackControlEvents", &CCBReader::getOwnerCallbackControlEvents)
    .function("getOwnerOutletNodes", &CCBReader::getOwnerOutletNodes)
    .function("readUTF8", &CCBReader::readUTF8)
    .function("addOwnerCallbackControlEvents", &CCBReader::addOwnerCallbackControlEvents)
    .function("getOwnerOutletNames", &CCBReader::getOwnerOutletNames)
    .function("readCallbackKeyframesForSeq", &CCBReader::readCallbackKeyframesForSeq, allow_raw_pointers())
    .function("getAnimationManagersForNodes", &CCBReader::getAnimationManagersForNodes)
    .function("getNodesWithAnimationManagers", &CCBReader::getNodesWithAnimationManagers)
    // from manual
    .function("load", select_overload<cocos2d::Node*(const char *)>(&CCBReader::readNodeGraphFromFile), allow_raw_pointers())
    .function("load", select_overload<cocos2d::Node*(const char *, cocos2d::Ref *)>(&CCBReader::readNodeGraphFromFile), allow_raw_pointers())
    .function("load", select_overload<cocos2d::Node*(const char *, cocos2d::Ref *, const cocos2d::Size &)>(&CCBReader::readNodeGraphFromFile), allow_raw_pointers())
    .function("loadScene", select_overload<cocos2d::Scene*(const char *)>(&CCBReader::createSceneWithNodeGraphFromFile), allow_raw_pointers())
    .function("loadScene", select_overload<cocos2d::Scene*(const char *, cocos2d::Ref *)>(&CCBReader::createSceneWithNodeGraphFromFile), allow_raw_pointers())
    .function("loadScene", select_overload<cocos2d::Scene*(const char *, cocos2d::Ref *, const cocos2d::Size &)>(&CCBReader::createSceneWithNodeGraphFromFile), allow_raw_pointers())
    .class_function("create", optional_override(
      [](){
        NodeLoaderLibrary * ccNodeLoaderLibrary = NodeLoaderLibrary::getInstance();
        ccNodeLoaderLibrary->registerNodeLoader("", JSLayerLoader::loader());
        CCBReader * ret = new (std::nothrow) CCBReader(ccNodeLoaderLibrary);
        ret->autorelease();
        return ret;
      }), allow_raw_pointers())
    // end of manual
    .class_function("setResolutionScale", &CCBReader::setResolutionScale)
    .property("_className",  optional_override([](const CCBReader& _) -> std::string {return "CCBReader";}))
    ;
}

static void removeSelector(std::string &str) {
    size_t found;
    found = str.find(':');
    while (found!=std::string::npos){
        str.replace(found, found+1, "");
        found = str.find(':');
    }
}

SEL_MenuHandler CCBScriptCallbackProxy::onResolveCCBCCMenuItemSelector(cocos2d::Ref * pTarget,
                                                                       const char * pSelectorName) {
    this->callBackProp = pSelectorName;
    removeSelector(this->callBackProp);
    return menu_selector(CCBScriptCallbackProxy::menuItemCallback);
}

Control::Handler CCBScriptCallbackProxy::onResolveCCBCCControlSelector(Ref * pTarget,
                                                                           const char * pSelectorName) {
    
    this->callBackProp = pSelectorName;
    removeSelector(this->callBackProp);
    return cccontrol_selector(CCBScriptCallbackProxy::controlCallback);
}

bool CCBScriptCallbackProxy::onAssignCCBMemberVariable(Ref * pTarget,
                                                       const char * pMemberVariableName,
                                                       Node * pNode) {
    return true;
}

void CCBScriptCallbackProxy::onNodeLoaded(Node * pNode,
                                          NodeLoader * pNodeLoader) {}

CCBSelectorResolver * CCBScriptCallbackProxy::createNew() {
    CCBScriptCallbackProxy * ret = new (std::nothrow) CCBScriptCallbackProxy();
    ret->setJSOwner(this->owner);
    return dynamic_cast<CCBSelectorResolver *>(ret);
}

void CCBScriptCallbackProxy::menuItemCallback(Ref *pSender) {
    owner.call<void>(callBackProp.c_str());
}

void CCBScriptCallbackProxy::controlCallback(Ref *pSender, Control::EventType event) {
    owner.call<void>(callBackProp.c_str());
}

void CCBScriptCallbackProxy::setCallbackProperty(const char *prop) {
    callBackProp = prop;
}

void CCBScriptCallbackProxy::setJSOwner(val ownr) {
    owner = ownr;
}

val CCBScriptCallbackProxy::getJSOwner() {
    return owner;
}
