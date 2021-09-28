#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx.hpp"
#include "cocos2d.h"
#include "audio/include/SimpleAudioEngine.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "scripting/js-bindings/manual/component/CCComponentJS.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace CocosDenshion;

COCOS_BINDINGS(ccbind_cocos2dx) {


  class_<Texture2D>("cc.Texture2D")
    .constructor<>()
    .function("getShaderProgram", &Texture2D::getGLProgram, allow_raw_pointers())
    .function("getMaxT", &Texture2D::getMaxT)
    .function("setAlphaTexture", &Texture2D::setAlphaTexture, allow_raw_pointers())
    .function("getStringForFormat", &Texture2D::getStringForFormat, allow_raw_pointers())
    .function("initWithImage", select_overload<bool(cocos2d::Image*, cocos2d::Texture2D::PixelFormat)>(&Texture2D::initWithImage), allow_raw_pointers())
    .function("initWithImage", select_overload<bool(cocos2d::Image*)>(&Texture2D::initWithImage), allow_raw_pointers())
    .function("setShaderProgram", &Texture2D::setGLProgram, allow_raw_pointers())
    .function("getMaxS", &Texture2D::getMaxS)
    .function("hasPremultipliedAlpha", &Texture2D::hasPremultipliedAlpha)
    .function("getPixelsHigh", &Texture2D::getPixelsHigh)
    .function("initWithMipmaps", &Texture2D::initWithMipmaps, allow_raw_pointers())
    .function("initWithMipmaps", optional_override(
        [](Texture2D& this_, cocos2d::_MipmapInfo* arg0, int arg1, cocos2d::Texture2D::PixelFormat arg2, int arg3, int arg4){
        return this_.initWithMipmaps(arg0, arg1, arg2, arg3, arg4);
      }), allow_raw_pointers())
    .function("getAlphaTextureName", &Texture2D::getAlphaTextureName)
    .function("getBitsPerPixelForFormat", select_overload<unsigned int(cocos2d::Texture2D::PixelFormat) const>(&Texture2D::getBitsPerPixelForFormat))
    .function("getBitsPerPixelForFormat", select_overload<unsigned int() const>(&Texture2D::getBitsPerPixelForFormat))
    .function("getName", &Texture2D::getName)
    .function("initWithString", select_overload<bool(const char*, const cocos2d::FontDefinition&)>(&Texture2D::initWithString), allow_raw_pointers())
    .function("initWithString", select_overload<bool(const char*, const std::string&, float, const cocos2d::Size&, cocos2d::TextHAlignment, cocos2d::TextVAlignment, bool, int)>(&Texture2D::initWithString), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .function("setMaxT", &Texture2D::setMaxT)
    .function("getPath", &Texture2D::getPath)
    .function("drawInRect", &Texture2D::drawInRect)
    .function("getContentSize", &Texture2D::getContentSize)
    .function("setAliasTexParameters", &Texture2D::setAliasTexParameters)
    .function("setAntiAliasTexParameters", &Texture2D::setAntiAliasTexParameters)
    .function("generateMipmap", &Texture2D::generateMipmap)
    .function("getAlphaTexture", &Texture2D::getAlphaTexture, allow_raw_pointers())
    .function("getDescription", &Texture2D::getDescription)
    .function("getPixelFormat", &Texture2D::getPixelFormat)
    .function("getContentSizeInPixels", &Texture2D::getContentSizeInPixels)
    .function("releaseTexture", &Texture2D::releaseGLTexture)
    .function("getPixelsWide", &Texture2D::getPixelsWide)
    .function("drawAtPoint", &Texture2D::drawAtPoint)
    .function("hasMipmaps", &Texture2D::hasMipmaps)
    .function("setMaxS", &Texture2D::setMaxS)
    .class_function("setDefaultAlphaPixelFormat", &Texture2D::setDefaultAlphaPixelFormat, allow_raw_pointers())
    .class_function("getDefaultAlphaPixelFormat", &Texture2D::getDefaultAlphaPixelFormat, allow_raw_pointers())
    .property("_className",  optional_override([](const Texture2D& _) -> std::string {return "Texture2D";}))    
    ;


  class_<Touch>("cc.Touch")
    .constructor<>()
    .function("getPreviousLocationInView", &Touch::getPreviousLocationInView)
    .function("getLocation", &Touch::getLocation)
    .function("getDelta", &Touch::getDelta)
    .function("getStartLocationInView", &Touch::getStartLocationInView)
    .function("getCurrentForce", &Touch::getCurrentForce)
    .function("getStartLocation", &Touch::getStartLocation)
    .function("getID", &Touch::getID)
    .function("setTouchInfo", select_overload<void(int, float, float, float, float)>(&Touch::setTouchInfo))
    .function("setTouchInfo", select_overload<void(int, float, float)>(&Touch::setTouchInfo))
    .function("getMaxForce", &Touch::getMaxForce)
    .function("getLocationInView", &Touch::getLocationInView)
    .function("getPreviousLocation", &Touch::getPreviousLocation)
    .property("_className",  optional_override([](const Touch& _) -> std::string {return "Touch";}))    
    ;


  class_<Event>("cc.Event")
    .constructor<cocos2d::Event::Type>()
    .function("isStopped", &Event::isStopped)
    .function("getType", &Event::getType)
    .function("getCurrentTarget", &Event::getCurrentTarget, allow_raw_pointers())
    .function("stopPropagation", &Event::stopPropagation)
    .property("_className",  optional_override([](const Event& _) -> std::string {return "Event";}))    
    ;


  class_<EventTouch, base<Event>>("cc.EventTouch")
    .constructor<>()
    .function("getEventCode", &EventTouch::getEventCode)
    .function("setEventCode", &EventTouch::setEventCode)
    .property("_className",  optional_override([](const EventTouch& _) -> std::string {return "EventTouch";}))    
    ;

  class_<ComponentContainer>("cc.ComponentContainer")
    .function("visit", &ComponentContainer::visit)
    .function("remove", select_overload<bool(cocos2d::Component*)>(&ComponentContainer::remove), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("removeAll", &ComponentContainer::removeAll)
    .function("add", &ComponentContainer::add, allow_raw_pointers())
    .function("isEmpty", &ComponentContainer::isEmpty)
    .function("getComponent", &ComponentContainer::get, allow_raw_pointers())
    .property("_className",  optional_override([](const ComponentContainer& _) -> std::string {return "ComponentContainer";}))    
    ;


  class_<Component>("cc.Component")
    .constructor<>()
    .function("setEnabled", &Component::setEnabled)
    .function("setName", &Component::setName)
    .function("isEnabled", &Component::isEnabled)
    .function("getOwner", &Component::getOwner, allow_raw_pointers())
    .function("init", &Component::init)
    .function("setOwner", &Component::setOwner, allow_raw_pointers())
    .function("getName", &Component::getName)
    .function("ctor", &cc_bindings_ctor<Component>, allow_raw_pointers())
    .class_function("create", &Component::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Component& _) -> std::string {return "Component";}))    
    // TODO: assign cc.Class.extend to cc.Component.extend
    ;


  class_<Node>("cc.Node")
    .constructor<>()
    .function("addChild", select_overload<void(cocos2d::Node*, int)>(&Node::addChild), allow_raw_pointers())
    .function("addChild", select_overload<void(cocos2d::Node*)>(&Node::addChild), allow_raw_pointers())
    .function("addChild", select_overload<void(cocos2d::Node*, int, int)>(&Node::addChild), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("removeComponent", select_overload<bool(cocos2d::Component*)>(&Node::removeComponent), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setPhysicsBody", &Node::setPhysicsBody, allow_raw_pointers())
    .function("getDescription", &Node::getDescription)
    .function("setOpacityModifyRGB", &Node::setOpacityModifyRGB)
    .function("setCascadeOpacityEnabled", &Node::setCascadeOpacityEnabled)
    .function("getChildren", select_overload<const cocos2d::Vector<cocos2d::Node *>&() const>(&Node::getChildren))
    // TODO: Only support function overloading with different number of parameters
    .function("setOnExitCallback", &Node::setOnExitCallback)
    .function("setActionManager", &Node::setActionManager, allow_raw_pointers())
    .function("isIgnoreAnchorPointForPosition", &Node::isIgnoreAnchorPointForPosition)
    .function("getChildByName", optional_override([](Node& this_, const std::string& name) {
        return this_.getChildByName(name);
    }), allow_raw_pointers())
    .function("updateDisplayedOpacity", &Node::updateDisplayedOpacity)
    .function("init", &Node::init)
    .function("getCameraMask", &Node::getCameraMask)
    .function("setRotation", &Node::setRotation)
    .function("setScaleZ", &Node::setScaleZ)
    .function("setScaleY", &Node::setScaleY)
    .function("setScaleX", &Node::setScaleX)
    .function("getColor", &Node::getColor)
    .function("setonEnterTransitionDidFinishCallback", &Node::setonEnterTransitionDidFinishCallback)
    .function("removeAllComponents", &Node::removeAllComponents)
    .function("_setLocalZOrder", &Node::_setLocalZOrder)
    .function("setCameraMask", &Node::setCameraMask)
    .function("setCameraMask", optional_override(
        [](Node& this_, unsigned short arg0){
        return this_.setCameraMask(arg0);
      }))
    .function("getTag", &Node::getTag)
    .function("getonEnterTransitionDidFinishCallback", &Node::getonEnterTransitionDidFinishCallback)
    .function("getNodeToWorldTransform", &Node::getNodeToWorldAffineTransform)
    .function("getPosition3D", &Node::getPosition3D)
    .function("removeChild", &Node::removeChild, allow_raw_pointers())
    .function("removeChild", optional_override(
        [](Node& this_, cocos2d::Node* arg0){
        return this_.removeChild(arg0);
      }), allow_raw_pointers())
    .function("getScene", &Node::getScene, allow_raw_pointers())
    .function("getEventDispatcher", &Node::getEventDispatcher, allow_raw_pointers())
    .function("setSkewX", &Node::setSkewX)
    .function("setGLProgramState", &Node::setGLProgramState, allow_raw_pointers())
    .function("setOnEnterCallback", &Node::setOnEnterCallback)
    .function("stopActionsByFlags", &Node::stopActionsByFlags)
    .function("setNormalizedPosition", &Node::setNormalizedPosition)
    .function("setonExitTransitionDidStartCallback", &Node::setonExitTransitionDidStartCallback)
    .function("convertTouchToNodeSpace", &Node::convertTouchToNodeSpace, allow_raw_pointers())
    .function("removeAllChildren", select_overload<void(bool)>(&Node::removeAllChildrenWithCleanup))
    .function("removeAllChildren", select_overload<void()>(&Node::removeAllChildren))
    .function("getNodeToWorldTransform3D", &Node::getNodeToWorldTransform)
    .function("isCascadeOpacityEnabled", &Node::isCascadeOpacityEnabled)
    .function("setParent", &Node::setParent, allow_raw_pointers())
    .function("getName", &Node::getName)
    .function("getRotation3D", &Node::getRotation3D)
    .function("getNodeToParentTransform", select_overload<cocos2d::AffineTransform(cocos2d::Node*) const>(&Node::getNodeToParentAffineTransform), allow_raw_pointers())
    .function("getNodeToParentTransform", select_overload<cocos2d::AffineTransform() const>(&Node::getNodeToParentAffineTransform))
    .function("convertTouchToNodeSpaceAR", &Node::convertTouchToNodeSpaceAR, allow_raw_pointers())
    .function("getOnEnterCallback", &Node::getOnEnterCallback)
    .function("setPositionNormalized", &Node::setPositionNormalized)
    .function("isOpacityModifyRGB", &Node::isOpacityModifyRGB)
    .function("stopActionByTag", &Node::stopActionByTag)
    .function("reorderChild", &Node::reorderChild, allow_raw_pointers())
    .function("setSkewY", &Node::setSkewY)
    .function("setRotation3D", &Node::setRotation3D)
    .function("setPositionX", &Node::setPositionX)
    .function("setNodeToParentTransform", &Node::setNodeToParentTransform)
    .function("getAnchorPoint", &Node::getAnchorPoint)
    .function("getNumberOfRunningActions", &Node::getNumberOfRunningActions)
    .function("updateTransform", &Node::updateTransform)
    .function("isVisible", &Node::isVisible)
    .function("getChildrenCount", &Node::getChildrenCount)
    .function("getNodeToParentTransform3D", select_overload<cocos2d::Mat4(cocos2d::Node*) const>(&Node::getNodeToParentTransform), allow_raw_pointers())
    .function("getNodeToParentTransform3D", select_overload<const cocos2d::Mat4&() const>(&Node::getNodeToParentTransform))
    .function("convertToNodeSpaceAR", &Node::convertToNodeSpaceAR)
    .function("addComponent", &Node::addComponent, allow_raw_pointers())
    .function("runAction", &Node::runAction, allow_raw_pointers())
    .function("visit", select_overload<void()>(&Node::visit))
    .function("visit", select_overload<void(cocos2d::Renderer*, const cocos2d::Mat4&, unsigned int)>(&Node::visit), allow_raw_pointers())
    .function("getRotation", &Node::getRotation)
    .function("getPhysicsBody", &Node::getPhysicsBody, allow_raw_pointers())
    .function("getAnchorPointInPoints", &Node::getAnchorPointInPoints)
    .function("getRotationQuat", &Node::getRotationQuat)
    .function("removeChildByName", &Node::removeChildByName)
    .function("removeChildByName", optional_override(
        [](Node& this_, const std::string& arg0){
        return this_.removeChildByName(arg0);
      }))
    .function("getGLProgramState", &Node::getGLProgramState, allow_raw_pointers())
    .function("setScheduler", &Node::setScheduler, allow_raw_pointers())
    .function("stopAllActions", &Node::stopAllActions)
    .function("getSkewX", &Node::getSkewX)
    .function("getSkewY", &Node::getSkewY)
    .function("getDisplayedColor", &Node::getDisplayedColor)
    .function("getActionByTag", &Node::getActionByTag, allow_raw_pointers())
    .function("setName", &Node::setName)
    .function("update", &Node::update)
    .function("getDisplayedOpacity", &Node::getDisplayedOpacity)
    .function("getLocalZOrder", &Node::getLocalZOrder)
    .function("getScheduler", select_overload<const cocos2d::Scheduler*() const>(&Node::getScheduler), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getPositionNormalized", &Node::getPositionNormalized)
    .function("getPosition", select_overload<void(float*, float*) const>(&Node::getPosition), allow_raw_pointers())
    .function("getPosition", select_overload<const cocos2d::Vec2&() const>(&Node::getPosition))
    .function("isRunning", &Node::isRunning)
    .function("getParent", select_overload<const cocos2d::Node*() const>(&Node::getParent), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getWorldToNodeTransform3D", &Node::getWorldToNodeTransform)
    .function("getPositionY", &Node::getPositionY)
    .function("getPositionX", &Node::getPositionX)
    .function("removeChildByTag", &Node::removeChildByTag)
    .function("removeChildByTag", optional_override(
        [](Node& this_, int arg0){
        return this_.removeChildByTag(arg0);
      }))
    .function("setPositionY", &Node::setPositionY)
    .function("updateDisplayedColor", &Node::updateDisplayedColor)
    .function("setVisible", &Node::setVisible)
    .function("getParentToNodeTransform", &Node::getParentToNodeAffineTransform)
    .function("setGlobalZOrder", &Node::setGlobalZOrder)
    .function("setScale", select_overload<void(float, float)>(&Node::setScale))
    .function("setScale", select_overload<void(float)>(&Node::setScale))
    .function("getOnExitCallback", &Node::getOnExitCallback)
    .function("getChildByTag", optional_override([](Node& this_, int tag) {
        return this_.getChildByTag(tag);
    }), allow_raw_pointers())
    .function("getScaleZ", &Node::getScaleZ)
    .function("getScaleY", &Node::getScaleY)
    .function("getScaleX", &Node::getScaleX)
    .function("setLocalZOrder", &Node::setLocalZOrder)
    .function("setCascadeColorEnabled", &Node::setCascadeColorEnabled)
    .function("setOpacity", &Node::setOpacity)
    .function("getComponent", &Node::getComponent, allow_raw_pointers())
    .function("getContentSize", &Node::getContentSize)
    .function("stopAllActionsByTag", &Node::stopAllActionsByTag)
    .function("getBoundingBox", &Node::getBoundingBox)
    .function("setIgnoreAnchorPointForPosition", &Node::setIgnoreAnchorPointForPosition)
    .function("setEventDispatcher", &Node::setEventDispatcher, allow_raw_pointers())
    .function("getGlobalZOrder", &Node::getGlobalZOrder)
    .function("draw", select_overload<void()>(&Node::draw))
    .function("draw", select_overload<void(cocos2d::Renderer*, const cocos2d::Mat4&, unsigned int)>(&Node::draw), allow_raw_pointers())
    .function("setUserObject", &Node::setUserObject, allow_raw_pointers())
    .function("enumerateChildren", &Node::enumerateChildren)
    .function("getonExitTransitionDidStartCallback", &Node::getonExitTransitionDidStartCallback)
    .function("removeFromParent", select_overload<void(bool)>(&Node::removeFromParentAndCleanup))
    .function("removeFromParent", select_overload<void()>(&Node::removeFromParent))
    .function("setPosition3D", &Node::setPosition3D)
    .function("getNumberOfRunningActionsByTag", &Node::getNumberOfRunningActionsByTag)
    .function("sortAllChildren", &Node::sortAllChildren)
    .function("getWorldToNodeTransform", &Node::getWorldToNodeAffineTransform)
    .function("getScale", &Node::getScale)
    .function("getOpacity", &Node::getOpacity)
    .function("updateOrderOfArrival", &Node::updateOrderOfArrival)
    .function("getNormalizedPosition", &Node::getNormalizedPosition)
    .function("getParentToNodeTransform3D", &Node::getParentToNodeTransform)
    .function("convertToNodeSpace", &Node::convertToNodeSpace)
    .function("setTag", &Node::setTag)
    .function("isCascadeColorEnabled", &Node::isCascadeColorEnabled)
    .function("setRotationQuat", &Node::setRotationQuat)
    .function("stopAction", &Node::stopAction, allow_raw_pointers())
    .function("getActionManager", select_overload<const cocos2d::ActionManager*() const>(&Node::getActionManager), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("ctor", &cc_bindings_ctor<Node>, allow_raw_pointers())
    .class_function("create", &Node::create, allow_raw_pointers())
    .class_function("getAttachedNodeCount", &Node::getAttachedNodeCount, allow_raw_pointers())
    .property("_className",  optional_override([](const Node& _) -> std::string {return "Node";}))    
    // TODO: assign cc.Class.extend to cc.Node.extend
    ;


  class_<__NodeRGBA, base<Node>>("cc.__NodeRGBA")
    .constructor<>()
    .property("_className",  optional_override([](const __NodeRGBA& _) -> std::string {return "__NodeRGBA";}))    
    ;


  class_<Scene, base<Node>>("cc.Scene")
    .constructor<>()
    .function("setCameraOrderDirty", &Scene::setCameraOrderDirty)
    .function("render", select_overload<void(cocos2d::Renderer*, const cocos2d::Mat4*, const cocos2d::Mat4*, unsigned int)>(&Scene::render), allow_raw_pointers())
    .function("render", select_overload<void(cocos2d::Renderer*, const cocos2d::Mat4&, const cocos2d::Mat4*)>(&Scene::render), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("stepPhysicsAndNavigation", &Scene::stepPhysicsAndNavigation)
    .function("onProjectionChanged", &Scene::onProjectionChanged, allow_raw_pointers())
    .function("initWithSize", &Scene::initWithSize)
    .function("getDefaultCamera", &Scene::getDefaultCamera, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Scene>, allow_raw_pointers())
    .class_function("createWithSize", &Scene::createWithSize, allow_raw_pointers())
    .class_function("create", &Scene::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Scene& _) -> std::string {return "Scene";}))    
    // TODO: assign cc.Class.extend to cc.Scene.extend
    ;

  class_<GLView>("cc.GLView")
    .function("setFrameSize", &GLView::setFrameSize)
    .function("getViewPortRect", &GLView::getViewPortRect)
    .function("getScaleY", &GLView::getScaleY)
    .function("setContentScaleFactor", &GLView::setContentScaleFactor)
    .function("getVR", &GLView::getVR, allow_raw_pointers())
    .function("getContentScaleFactor", &GLView::getContentScaleFactor)
    .function("setIMEKeyboardState", &GLView::setIMEKeyboardState)
    .function("getSafeAreaRect", &GLView::getSafeAreaRect)
    .function("setViewPortInPoints", &GLView::setViewPortInPoints)
    .function("setScissorInPoints", &GLView::setScissorInPoints)
    .function("getViewName", &GLView::getViewName)
    .function("isOpenGLReady", &GLView::isOpenGLReady)
    .function("setCursorVisible", &GLView::setCursorVisible)
    .function("setDefaultIcon", &GLView::setDefaultIcon)
    .function("getScaleX", &GLView::getScaleX)
    .function("getVisibleOrigin", &GLView::getVisibleOrigin)
    .function("setFrameZoomFactor", &GLView::setFrameZoomFactor)
    .function("getFrameZoomFactor", &GLView::getFrameZoomFactor)
    .function("getDesignResolutionSize", &GLView::getDesignResolutionSize)
    .function("setIcon", select_overload<void(const std::vector<std::string>&) const>(&GLView::setIcon))
    // TODO: Only support function overloading with different number of parameters
    .function("setDefaultCursor", &GLView::setDefaultCursor)
    .function("windowShouldClose", &GLView::windowShouldClose)
    .function("setDesignResolutionSize", &GLView::setDesignResolutionSize)
    .function("getResolutionPolicy", &GLView::getResolutionPolicy)
    .function("isRetinaDisplay", &GLView::isRetinaDisplay)
    .function("renderScene", &GLView::renderScene, allow_raw_pointers())
    .function("setVR", &GLView::setVR, allow_raw_pointers())
    .function("getFrameSize", &GLView::getFrameSize)
    .function("getScissorRect", &GLView::getScissorRect)
    .function("setCursor", &GLView::setCursor)
    .function("setCursor", optional_override(
        [](GLView& this_, const std::string& arg0){
        return this_.setCursor(arg0);
      }))
    .function("getRetinaFactor", &GLView::getRetinaFactor)
    .function("setViewName", &GLView::setViewName)
    .function("getVisibleRect", &GLView::getVisibleRect)
    .function("getVisibleSize", &GLView::getVisibleSize)
    .function("isScissorEnabled", &GLView::isScissorEnabled)
    .function("pollEvents", &GLView::pollEvents)
    .class_function("setGLContextAttrs", &GLView::setGLContextAttrs, allow_raw_pointers())
    .class_function("getGLContextAttrs", &GLView::getGLContextAttrs, allow_raw_pointers())
    .property("_className",  optional_override([](const GLView& _) -> std::string {return "GLView";}))    
    ;

  class_<Director>("cc.Director")
    .function("pause", &Director::pause)
    .function("pushProjectionMatrix", &Director::pushProjectionMatrix)
    .function("popProjectionMatrix", &Director::popProjectionMatrix)
    .function("setEventDispatcher", &Director::setEventDispatcher, allow_raw_pointers())
    .function("loadProjectionIdentityMatrix", &Director::loadProjectionIdentityMatrix)
    .function("setContentScaleFactor", &Director::setContentScaleFactor)
    .function("getDeltaTime", &Director::getDeltaTime)
    .function("getContentScaleFactor", &Director::getContentScaleFactor)
    .function("getWinSizeInPixels", &Director::getWinSizeInPixels)
    .function("getSafeAreaRect", &Director::getSafeAreaRect)
    .function("setGLDefaultValues", &Director::setGLDefaultValues)
    .function("setActionManager", &Director::setActionManager, allow_raw_pointers())
    .function("setAlphaBlending", &Director::setAlphaBlending)
    .function("popToRootScene", &Director::popToRootScene)
    .function("loadMatrix", &Director::loadMatrix)
    .function("getNotificationNode", &Director::getNotificationNode, allow_raw_pointers())
    .function("getWinSize", &Director::getWinSize)
    .function("end", &Director::end)
    .function("getTextureCache", &Director::getTextureCache, allow_raw_pointers())
    .function("isSendCleanupToScene", &Director::isSendCleanupToScene)
    .function("getVisibleOrigin", &Director::getVisibleOrigin)
    .function("mainLoop", select_overload<void(float)>(&Director::mainLoop))
    .function("mainLoop", select_overload<void()>(&Director::mainLoop))
    .function("setDepthTest", &Director::setDepthTest)
    .function("getFrameRate", &Director::getFrameRate)
    .function("getSecondsPerFrame", &Director::getSecondsPerFrame)
    .function("resetMatrixStack", &Director::resetMatrixStack)
    .function("convertToUI", &Director::convertToUI)
    .function("pushMatrix", &Director::pushMatrix)
    .function("setDefaultValues", &Director::setDefaultValues)
    .function("init", &Director::init)
    .function("setScheduler", &Director::setScheduler, allow_raw_pointers())
    .function("multiplyProjectionMatrix", &Director::multiplyProjectionMatrix)
    .function("getMatrix", &Director::getMatrix)
    .function("isValid", &Director::isValid)
    .function("startAnimation", &Director::startAnimation)
    .function("getOpenGLView", &Director::getOpenGLView, allow_raw_pointers())
    .function("getRunningScene", &Director::getRunningScene, allow_raw_pointers())
    .function("setViewport", &Director::setViewport)
    .function("stopAnimation", &Director::stopAnimation)
    .function("popToSceneStackLevel", &Director::popToSceneStackLevel)
    .function("resume", &Director::resume)
    .function("isNextDeltaTimeZero", &Director::isNextDeltaTimeZero)
    .function("setClearColor", &Director::setClearColor)
    .function("setOpenGLView", &Director::setOpenGLView, allow_raw_pointers())
    .function("convertToGL", &Director::convertToGL)
    .function("purgeCachedData", &Director::purgeCachedData)
    .function("getTotalFrames", &Director::getTotalFrames)
    .function("runWithScene", &Director::runWithScene, allow_raw_pointers())
    .function("setNotificationNode", &Director::setNotificationNode, allow_raw_pointers())
    .function("drawScene", &Director::drawScene)
    .function("restart", &Director::restart)
    .function("popScene", &Director::popScene)
    .function("loadIdentityMatrix", &Director::loadIdentityMatrix)
    .function("isDisplayStats", &Director::isDisplayStats)
    .function("setProjection", &Director::setProjection)
    .function("multiplyMatrix", &Director::multiplyMatrix)
    .function("getZEye", &Director::getZEye)
    .function("setNextDeltaTimeZero", &Director::setNextDeltaTimeZero)
    .function("popMatrix", &Director::popMatrix)
    .function("getVisibleSize", &Director::getVisibleSize)
    .function("loadProjectionMatrix", &Director::loadProjectionMatrix)
    .function("initProjectionMatrixStack", &Director::initProjectionMatrixStack)
    .function("getScheduler", &Director::getScheduler, allow_raw_pointers())
    .function("pushScene", &Director::pushScene, allow_raw_pointers())
    .function("getAnimationInterval", &Director::getAnimationInterval)
    .function("getClearColor", &Director::getClearColor)
    .function("isPaused", &Director::isPaused)
    .function("setDisplayStats", &Director::setDisplayStats)
    .function("getEventDispatcher", &Director::getEventDispatcher, allow_raw_pointers())
    .function("replaceScene", &Director::replaceScene, allow_raw_pointers())
    .function("setAnimationInterval", &Director::setAnimationInterval)
    .function("getActionManager", &Director::getActionManager, allow_raw_pointers())
    .class_function("getInstance", &Director::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const Director& _) -> std::string {return "Director";}))    
    ;


  class_<Scheduler>("cc.Scheduler")
    .constructor<>()
    .function("setTimeScale", &Scheduler::setTimeScale)
    .function("unscheduleAllWithMinPriority", &Scheduler::unscheduleAllWithMinPriority)
    .function("update", &Scheduler::update)
    .function("unscheduleScriptEntry", &Scheduler::unscheduleScriptEntry)
    .function("performFunctionInCocosThread", &Scheduler::performFunctionInCocosThread)
    .function("removeAllFunctionsToBePerformedInCocosThread", &Scheduler::removeAllFunctionsToBePerformedInCocosThread)
    .function("unscheduleAll", &Scheduler::unscheduleAll)
    .function("getTimeScale", &Scheduler::getTimeScale)
    .property("_className",  optional_override([](const Scheduler& _) -> std::string {return "Scheduler";}))    
    ;

  class_<AsyncTaskPool>("cc.AsyncTaskPool")
    .function("stopTasks", &AsyncTaskPool::stopTasks)
    .class_function("destroyInstance", &AsyncTaskPool::destroyInstance, allow_raw_pointers())
    .class_function("getInstance", &AsyncTaskPool::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const AsyncTaskPool& _) -> std::string {return "AsyncTaskPool";}))    
    ;

  class_<Action>("cc.Action")
    .function("startWithTarget", &Action::startWithTarget, allow_raw_pointers())
    .function("setOriginalTarget", &Action::setOriginalTarget, allow_raw_pointers())
    .function("clone", &Action::clone, allow_raw_pointers())
    .function("getOriginalTarget", &Action::getOriginalTarget, allow_raw_pointers())
    .function("stop", &Action::stop)
    .function("update", &Action::update)
    .function("getTarget", &Action::getTarget, allow_raw_pointers())
    .function("getFlags", &Action::getFlags)
    .function("step", &Action::step)
    .function("setTag", &Action::setTag)
    .function("setFlags", &Action::setFlags)
    .function("getTag", &Action::getTag)
    .function("setTarget", &Action::setTarget, allow_raw_pointers())
    .function("isDone", &Action::isDone)
    .function("reverse", &Action::reverse, allow_raw_pointers())
    .property("_className",  optional_override([](const Action& _) -> std::string {return "Action";}))    
    ;

  class_<FiniteTimeAction, base<Action>>("cc.FiniteTimeAction")
    .function("setDuration", &FiniteTimeAction::setDuration)
    .function("getDuration", &FiniteTimeAction::getDuration)
    .property("_className",  optional_override([](const FiniteTimeAction& _) -> std::string {return "FiniteTimeAction";}))    
    ;


  class_<Speed, base<Action>>("cc.Speed")
    .constructor<>()
    .function("setInnerAction", &Speed::setInnerAction, allow_raw_pointers())
    .function("_getSpeed", &Speed::getSpeed)
    .function("_setSpeed", &Speed::setSpeed)
    .function("initWithAction", &Speed::initWithAction, allow_raw_pointers())
    .function("getInnerAction", &Speed::getInnerAction, allow_raw_pointers())
    .class_function("create", &Speed::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Speed& _) -> std::string {return "Speed";}))    
    ;


  class_<Follow, base<Action>>("cc.Follow")
    .constructor<>()
    .function("setBoundarySet", &Follow::setBoundarySet)
    .function("initWithTarget", &Follow::initWithTarget, allow_raw_pointers())
    .function("initWithTarget", optional_override(
        [](Follow& this_, cocos2d::Node* arg0){
        return this_.initWithTarget(arg0);
      }), allow_raw_pointers())
    .function("initWithTargetAndOffset", &Follow::initWithTargetAndOffset, allow_raw_pointers())
    .function("initWithTargetAndOffset", optional_override(
        [](Follow& this_, cocos2d::Node* arg0, float arg1, float arg2){
        return this_.initWithTargetAndOffset(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("isBoundarySet", &Follow::isBoundarySet)
    .function("ctor", &cc_bindings_ctor<Follow>, allow_raw_pointers())
    .class_function("create", &Follow::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](cocos2d::Node* arg0){
        return Follow::create(arg0);
      }), allow_raw_pointers())
    .class_function("createWithOffset", &Follow::createWithOffset, allow_raw_pointers())
    .class_function("createWithOffset", optional_override(
      [](cocos2d::Node* arg0, float arg1, float arg2){
        return Follow::createWithOffset(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const Follow& _) -> std::string {return "Follow";}))    
    // TODO: assign cc.Class.extend to cc.Follow.extend
    ;


  class_<Image>("cc.Image")
    .constructor<>()
    .function("hasPremultipliedAlpha", &Image::hasPremultipliedAlpha)
    .function("reversePremultipliedAlpha", &Image::reversePremultipliedAlpha)
    .function("getDataLen", &Image::getDataLen)
    .function("saveToFile", &Image::saveToFile)
    .function("saveToFile", optional_override(
        [](Image& this_, const std::string& arg0){
        return this_.saveToFile(arg0);
      }))
    .function("hasAlpha", &Image::hasAlpha)
    .function("isCompressed", &Image::isCompressed)
    .function("getHeight", &Image::getHeight)
    .function("premultiplyAlpha", &Image::premultiplyAlpha)
    .function("initWithImageFile", &Image::initWithImageFile)
    .function("getWidth", &Image::getWidth)
    .function("getBitPerPixel", &Image::getBitPerPixel)
    .function("getFileType", &Image::getFileType)
    .function("getFilePath", &Image::getFilePath)
    .function("getNumberOfMipmaps", &Image::getNumberOfMipmaps)
    .function("getRenderFormat", &Image::getRenderFormat)
    .function("getData", &Image::getData, allow_raw_pointers())
    .function("getMipmaps", &Image::getMipmaps, allow_raw_pointers())
    .function("initWithRawData", &Image::initWithRawData, allow_raw_pointers())
    .function("initWithRawData", optional_override(
        [](Image& this_, const unsigned char* arg0, int arg1, int arg2, int arg3, int arg4){
        return this_.initWithRawData(arg0, arg1, arg2, arg3, arg4);
      }), allow_raw_pointers())
    .class_function("setPVRImagesHavePremultipliedAlpha", &Image::setPVRImagesHavePremultipliedAlpha, allow_raw_pointers())
    .class_function("setPNGPremultipliedAlphaEnabled", &Image::setPNGPremultipliedAlphaEnabled, allow_raw_pointers())
    .property("_className",  optional_override([](const Image& _) -> std::string {return "Image";}))    
    ;


  class_<GLProgramState>("cc.GLProgramState")
    .constructor<>()
    .function("setUniformCallback", select_overload<void(int, const std::function<void (cocos2d::GLProgram *, cocos2d::Uniform *)>&)>(&GLProgramState::setUniformCallback))
    // TODO: Only support function overloading with different number of parameters
    .function("getVertexAttribsFlags", &GLProgramState::getVertexAttribsFlags)
    .function("applyAutoBinding", &GLProgramState::applyAutoBinding)
    .function("setUniformVec2", select_overload<void(int, const cocos2d::Vec2&)>(&GLProgramState::setUniformVec2))
    // TODO: Only support function overloading with different number of parameters
    .function("setUniformVec3", select_overload<void(int, const cocos2d::Vec3&)>(&GLProgramState::setUniformVec3))
    // TODO: Only support function overloading with different number of parameters
    .function("setVertexAttribCallback", &GLProgramState::setVertexAttribCallback)
    .function("apply", &GLProgramState::apply)
    .function("getNodeBinding", &GLProgramState::getNodeBinding, allow_raw_pointers())
    .function("applyGLProgram", &GLProgramState::applyGLProgram)
    .function("setNodeBinding", &GLProgramState::setNodeBinding, allow_raw_pointers())
    .function("setUniformInt", select_overload<void(int, int)>(&GLProgramState::setUniformInt))
    // TODO: Only support function overloading with different number of parameters
    .function("setParameterAutoBinding", &GLProgramState::setParameterAutoBinding)
    // TODO: .function("setUniformVec2v", select_overload<void(int, int, const cocos2d::Vec2*)>(&GLProgramState::setUniformVec2v), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getUniformCount", &GLProgramState::getUniformCount)
    .function("applyAttributes", &GLProgramState::applyAttributes)
    .function("applyAttributes", optional_override(
        [](GLProgramState& this_){
        return this_.applyAttributes();
      }))
    .function("clone", &GLProgramState::clone, allow_raw_pointers())
    .function("setGLProgram", &GLProgramState::setGLProgram, allow_raw_pointers())
    // TODO: .function("setUniformFloatv", select_overload<void(int, int, const float*)>(&GLProgramState::setUniformFloatv), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getGLProgram", &GLProgramState::getGLProgram, allow_raw_pointers())
    .function("setUniformTexture", select_overload<void(int, cocos2d::Texture2D*)>(&GLProgramState::setUniformTexture), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("applyUniforms", &GLProgramState::applyUniforms)
    .function("setUniformFloat", select_overload<void(int, float)>(&GLProgramState::setUniformFloat))
    // TODO: Only support function overloading with different number of parameters
    .function("setUniformMat4", select_overload<void(int, const cocos2d::Mat4&)>(&GLProgramState::setUniformMat4))
    // TODO: Only support function overloading with different number of parameters
    // TODO: .function("setUniformVec3v", select_overload<void(int, int, const cocos2d::Vec3*)>(&GLProgramState::setUniformVec3v), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getVertexAttribCount", &GLProgramState::getVertexAttribCount)
    .class_function("create", &GLProgramState::create, allow_raw_pointers())
    .class_function("getOrCreateWithGLProgramName", select_overload<cocos2d::GLProgramState*(const std::string&, cocos2d::Texture2D*)>(&GLProgramState::getOrCreateWithGLProgramName), allow_raw_pointers())
    .class_function("getOrCreateWithGLProgramName", select_overload<cocos2d::GLProgramState*(const std::string&)>(&GLProgramState::getOrCreateWithGLProgramName), allow_raw_pointers())
    .class_function("getOrCreateWithGLProgram", &GLProgramState::getOrCreateWithGLProgram, allow_raw_pointers())
    .class_function("getOrCreateWithShaders", &GLProgramState::getOrCreateWithShaders, allow_raw_pointers())
    .property("_className",  optional_override([](const GLProgramState& _) -> std::string {return "GLProgramState";}))    
    ;


  class_<SpriteFrame>("cc.SpriteFrame")
    .constructor<>()
    .function("setAnchorPoint", &SpriteFrame::setAnchorPoint)
    .function("setTexture", &SpriteFrame::setTexture, allow_raw_pointers())
    .function("getTexture", &SpriteFrame::getTexture, allow_raw_pointers())
    .function("setOffsetInPixels", &SpriteFrame::setOffsetInPixels)
    .function("getOriginalSizeInPixels", &SpriteFrame::getOriginalSizeInPixels)
    .function("setOriginalSize", &SpriteFrame::setOriginalSize)
    .function("getCenterRect", &SpriteFrame::getCenterRect)
    .function("setRectInPixels", &SpriteFrame::setRectInPixels)
    .function("getRect", &SpriteFrame::getRect)
    .function("setCenterRectInPixels", &SpriteFrame::setCenterRectInPixels)
    .function("setOffset", &SpriteFrame::setOffset)
    .function("initWithTextureFilename", select_overload<bool(const std::string&, const cocos2d::Rect&, bool, const cocos2d::Vec2&, const cocos2d::Size&)>(&SpriteFrame::initWithTextureFilename))
    .function("initWithTextureFilename", select_overload<bool(const std::string&, const cocos2d::Rect&)>(&SpriteFrame::initWithTextureFilename))
    .function("setRect", &SpriteFrame::setRect)
    .function("initWithTexture", select_overload<bool(cocos2d::Texture2D*, const cocos2d::Rect&, bool, const cocos2d::Vec2&, const cocos2d::Size&)>(&SpriteFrame::initWithTexture), allow_raw_pointers())
    .function("initWithTexture", select_overload<bool(cocos2d::Texture2D*, const cocos2d::Rect&)>(&SpriteFrame::initWithTexture), allow_raw_pointers())
    .function("getOriginalSize", &SpriteFrame::getOriginalSize)
    .function("clone", &SpriteFrame::clone, allow_raw_pointers())
    .function("getRectInPixels", &SpriteFrame::getRectInPixels)
    .function("isRotated", &SpriteFrame::isRotated)
    .function("hasCenterRect", &SpriteFrame::hasCenterRect)
    .function("setRotated", &SpriteFrame::setRotated)
    .function("getOffset", &SpriteFrame::getOffset)
    .function("setOriginalSizeInPixels", &SpriteFrame::setOriginalSizeInPixels)
    .function("getAnchorPoint", &SpriteFrame::getAnchorPoint)
    .function("hasAnchorPoint", &SpriteFrame::hasAnchorPoint)
    .function("getOffsetInPixels", &SpriteFrame::getOffsetInPixels)
    .function("ctor", &cc_bindings_ctor<SpriteFrame>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::SpriteFrame*(const std::string&, const cocos2d::Rect&, bool, const cocos2d::Vec2&, const cocos2d::Size&)>(&SpriteFrame::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::SpriteFrame*(const std::string&, const cocos2d::Rect&)>(&SpriteFrame::create), allow_raw_pointers())
    .class_function("createWithTexture", select_overload<cocos2d::SpriteFrame*(cocos2d::Texture2D*, const cocos2d::Rect&, bool, const cocos2d::Vec2&, const cocos2d::Size&)>(&SpriteFrame::createWithTexture), allow_raw_pointers())
    .class_function("createWithTexture", select_overload<cocos2d::SpriteFrame*(cocos2d::Texture2D*, const cocos2d::Rect&)>(&SpriteFrame::createWithTexture), allow_raw_pointers())
    .property("_className",  optional_override([](const SpriteFrame& _) -> std::string {return "SpriteFrame";}))    
    // TODO: assign cc.Class.extend to cc.SpriteFrame.extend
    ;


  class_<AnimationFrame>("cc.AnimationFrame")
    .constructor<>()
    .function("setSpriteFrame", &AnimationFrame::setSpriteFrame, allow_raw_pointers())
    .function("getUserInfo", select_overload<std::unordered_map<std::string, cocos2d::Value>&()>(&AnimationFrame::getUserInfo))
    // TODO: Only support function overloading with different number of parameters
    .function("setDelayUnits", &AnimationFrame::setDelayUnits)
    .function("clone", &AnimationFrame::clone, allow_raw_pointers())
    .function("getSpriteFrame", &AnimationFrame::getSpriteFrame, allow_raw_pointers())
    .function("getDelayUnits", &AnimationFrame::getDelayUnits)
    .function("setUserInfo", &AnimationFrame::setUserInfo)
    .function("initWithSpriteFrame", &AnimationFrame::initWithSpriteFrame, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<AnimationFrame>, allow_raw_pointers())
    .class_function("create", &AnimationFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AnimationFrame& _) -> std::string {return "AnimationFrame";}))    
    // TODO: assign cc.Class.extend to cc.AnimationFrame.extend
    ;


  class_<Animation>("cc.Animation")
    .constructor<>()
    .function("getLoops", &Animation::getLoops)
    .function("addSpriteFrame", &Animation::addSpriteFrame, allow_raw_pointers())
    .function("setRestoreOriginalFrame", &Animation::setRestoreOriginalFrame)
    .function("clone", &Animation::clone, allow_raw_pointers())
    .function("getDuration", &Animation::getDuration)
    .function("initWithAnimationFrames", &Animation::initWithAnimationFrames)
    .function("init", &Animation::init)
    .function("setFrames", &Animation::setFrames)
    .function("getFrames", &Animation::getFrames)
    .function("setLoops", &Animation::setLoops)
    .function("setDelayPerUnit", &Animation::setDelayPerUnit)
    .function("addSpriteFrameWithFile", &Animation::addSpriteFrameWithFile)
    .function("getTotalDelayUnits", &Animation::getTotalDelayUnits)
    .function("getDelayPerUnit", &Animation::getDelayPerUnit)
    .function("initWithSpriteFrames", &Animation::initWithSpriteFrames)
    .function("initWithSpriteFrames", optional_override(
        [](Animation& this_, const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0){
        return this_.initWithSpriteFrames(arg0);
      }))
    .function("initWithSpriteFrames", optional_override(
        [](Animation& this_, const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0, float arg1){
        return this_.initWithSpriteFrames(arg0, arg1);
      }))
    .function("getRestoreOriginalFrame", &Animation::getRestoreOriginalFrame)
    .function("addSpriteFrameWithTexture", &Animation::addSpriteFrameWithTexture, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Animation>, allow_raw_pointers())
    .class_function("createWithAnimationFrames", select_overload<cocos2d::Animation*(const cocos2d::Vector<cocos2d::AnimationFrame *>&, float, unsigned int)>(&Animation::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithAnimationFrames", select_overload<cocos2d::Animation*()>(&Animation::create), allow_raw_pointers())
    .class_function("createWithSpriteFrames", &Animation::createWithSpriteFrames, allow_raw_pointers())
    .class_function("createWithSpriteFrames", optional_override(
      [](const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0){
        return Animation::createWithSpriteFrames(arg0);
      }), allow_raw_pointers())
    .class_function("createWithSpriteFrames", optional_override(
      [](const cocos2d::Vector<cocos2d::SpriteFrame *>& arg0, float arg1){
        return Animation::createWithSpriteFrames(arg0, arg1);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const Animation& _) -> std::string {return "Animation";}))    
    // TODO: assign cc.Class.extend to cc.Animation.extend
    ;

  class_<ActionInterval, base<FiniteTimeAction>>("cc.ActionInterval")
    .function("getAmplitudeRate", &ActionInterval::getAmplitudeRate)
    .function("initWithDuration", &ActionInterval::initWithDuration)
    .function("setAmplitudeRate", &ActionInterval::setAmplitudeRate)
    .function("getElapsed", &ActionInterval::getElapsed)
    .property("_className",  optional_override([](const ActionInterval& _) -> std::string {return "ActionInterval";}))    
    ;


  class_<Sequence, base<ActionInterval>>("cc.Sequence")
    .constructor<>()
    .function("init", &Sequence::init)
    .function("initWithTwoActions", &Sequence::initWithTwoActions, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Sequence>, allow_raw_pointers())
    .property("_className",  optional_override([](const Sequence& _) -> std::string {return "Sequence";}))    
    // TODO: assign cc.Class.extend to cc.Sequence.extend
    ;


  class_<Repeat, base<ActionInterval>>("cc.Repeat")
    .constructor<>()
    .function("setInnerAction", &Repeat::setInnerAction, allow_raw_pointers())
    .function("initWithAction", &Repeat::initWithAction, allow_raw_pointers())
    .function("getInnerAction", &Repeat::getInnerAction, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Repeat>, allow_raw_pointers())
    .class_function("create", &Repeat::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Repeat& _) -> std::string {return "Repeat";}))    
    // TODO: assign cc.Class.extend to cc.Repeat.extend
    ;


  class_<RepeatForever, base<ActionInterval>>("cc.RepeatForever")
    .constructor<>()
    .function("setInnerAction", &RepeatForever::setInnerAction, allow_raw_pointers())
    .function("initWithAction", &RepeatForever::initWithAction, allow_raw_pointers())
    .function("getInnerAction", &RepeatForever::getInnerAction, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<RepeatForever>, allow_raw_pointers())
    .class_function("create", &RepeatForever::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RepeatForever& _) -> std::string {return "RepeatForever";}))    
    // TODO: assign cc.Class.extend to cc.RepeatForever.extend
    ;


  class_<Spawn, base<ActionInterval>>("cc.Spawn")
    .constructor<>()
    .function("init", &Spawn::init)
    .function("initWithTwoActions", &Spawn::initWithTwoActions, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Spawn>, allow_raw_pointers())
    .property("_className",  optional_override([](const Spawn& _) -> std::string {return "Spawn";}))    
    // TODO: assign cc.Class.extend to cc.Spawn.extend
    ;


  class_<RotateTo, base<ActionInterval>>("cc.RotateTo")
    .constructor<>()
    .function("initWithDuration", select_overload<bool(float, const cocos2d::Vec3&)>(&RotateTo::initWithDuration))
    .function("initWithDuration", select_overload<bool(float, float, float)>(&RotateTo::initWithDuration))
    .function("ctor", &cc_bindings_ctor<RotateTo>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::RotateTo*(float, float)>(&RotateTo::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::RotateTo*(float, float, float)>(&RotateTo::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const RotateTo& _) -> std::string {return "RotateTo";}))    
    // TODO: assign cc.Class.extend to cc.RotateTo.extend
    ;


  class_<RotateBy, base<ActionInterval>>("cc.RotateBy")
    .constructor<>()
    .function("initWithDuration", select_overload<bool(float, float, float)>(&RotateBy::initWithDuration))
    .function("initWithDuration", select_overload<bool(float, float)>(&RotateBy::initWithDuration))
    // TODO: Only support function overloading with different number of parameters
    .function("ctor", &cc_bindings_ctor<RotateBy>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::RotateBy*(float, float, float)>(&RotateBy::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::RotateBy*(float, float)>(&RotateBy::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const RotateBy& _) -> std::string {return "RotateBy";}))    
    // TODO: assign cc.Class.extend to cc.RotateBy.extend
    ;


  class_<MoveBy, base<ActionInterval>>("cc.MoveBy")
    .constructor<>()
    .function("initWithDuration", select_overload<bool(float, const cocos2d::Vec3&)>(&MoveBy::initWithDuration))
    // TODO: Only support function overloading with different number of parameters
    .function("ctor", &cc_bindings_ctor<MoveBy>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::MoveBy*(float, const cocos2d::Vec3&)>(&MoveBy::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const MoveBy& _) -> std::string {return "MoveBy";}))    
    // TODO: assign cc.Class.extend to cc.MoveBy.extend
    ;


  class_<MoveTo, base<MoveBy>>("cc.MoveTo")
    .constructor<>()
    .function("initWithDuration", select_overload<bool(float, const cocos2d::Vec3&)>(&MoveTo::initWithDuration))
    // TODO: Only support function overloading with different number of parameters
    .function("ctor", &cc_bindings_ctor<MoveTo>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::MoveTo*(float, const cocos2d::Vec3&)>(&MoveTo::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const MoveTo& _) -> std::string {return "MoveTo";}))    
    // TODO: assign cc.Class.extend to cc.MoveTo.extend
    ;


  class_<SkewTo, base<ActionInterval>>("cc.SkewTo")
    .constructor<>()
    .function("initWithDuration", &SkewTo::initWithDuration)
    .function("ctor", &cc_bindings_ctor<SkewTo>, allow_raw_pointers())
    .class_function("create", &SkewTo::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SkewTo& _) -> std::string {return "SkewTo";}))    
    // TODO: assign cc.Class.extend to cc.SkewTo.extend
    ;


  class_<SkewBy, base<SkewTo>>("cc.SkewBy")
    .constructor<>()
    .function("initWithDuration", &SkewBy::initWithDuration)
    .function("ctor", &cc_bindings_ctor<SkewBy>, allow_raw_pointers())
    .class_function("create", &SkewBy::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SkewBy& _) -> std::string {return "SkewBy";}))    
    // TODO: assign cc.Class.extend to cc.SkewBy.extend
    ;


  class_<JumpBy, base<ActionInterval>>("cc.JumpBy")
    .constructor<>()
    .function("initWithDuration", &JumpBy::initWithDuration)
    .function("ctor", &cc_bindings_ctor<JumpBy>, allow_raw_pointers())
    .class_function("create", &JumpBy::create, allow_raw_pointers())
    .property("_className",  optional_override([](const JumpBy& _) -> std::string {return "JumpBy";}))    
    // TODO: assign cc.Class.extend to cc.JumpBy.extend
    ;


  class_<JumpTo, base<JumpBy>>("cc.JumpTo")
    .constructor<>()
    .function("initWithDuration", &JumpTo::initWithDuration)
    .function("ctor", &cc_bindings_ctor<JumpTo>, allow_raw_pointers())
    .class_function("create", &JumpTo::create, allow_raw_pointers())
    .property("_className",  optional_override([](const JumpTo& _) -> std::string {return "JumpTo";}))    
    // TODO: assign cc.Class.extend to cc.JumpTo.extend
    ;


  class_<BezierBy, base<ActionInterval>>("cc.BezierBy")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<BezierBy>, allow_raw_pointers())
    .property("_className",  optional_override([](const BezierBy& _) -> std::string {return "BezierBy";}))    
    // TODO: assign cc.Class.extend to cc.BezierBy.extend
    ;


  class_<BezierTo, base<BezierBy>>("cc.BezierTo")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<BezierTo>, allow_raw_pointers())
    .property("_className",  optional_override([](const BezierTo& _) -> std::string {return "BezierTo";}))    
    // TODO: assign cc.Class.extend to cc.BezierTo.extend
    ;


  class_<ScaleTo, base<ActionInterval>>("cc.ScaleTo")
    .constructor<>()
    .function("initWithDuration", select_overload<bool(float, float, float)>(&ScaleTo::initWithDuration))
    .function("initWithDuration", select_overload<bool(float, float)>(&ScaleTo::initWithDuration))
    .function("initWithDuration", select_overload<bool(float, float, float, float)>(&ScaleTo::initWithDuration))
    .function("ctor", &cc_bindings_ctor<ScaleTo>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ScaleTo*(float, float, float)>(&ScaleTo::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ScaleTo*(float, float)>(&ScaleTo::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ScaleTo*(float, float, float, float)>(&ScaleTo::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ScaleTo& _) -> std::string {return "ScaleTo";}))    
    // TODO: assign cc.Class.extend to cc.ScaleTo.extend
    ;


  class_<ScaleBy, base<ScaleTo>>("cc.ScaleBy")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<ScaleBy>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ScaleBy*(float, float, float)>(&ScaleBy::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ScaleBy*(float, float)>(&ScaleBy::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ScaleBy*(float, float, float, float)>(&ScaleBy::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ScaleBy& _) -> std::string {return "ScaleBy";}))    
    // TODO: assign cc.Class.extend to cc.ScaleBy.extend
    ;


  class_<Blink, base<ActionInterval>>("cc.Blink")
    .constructor<>()
    .function("initWithDuration", &Blink::initWithDuration)
    .function("ctor", &cc_bindings_ctor<Blink>, allow_raw_pointers())
    .class_function("create", &Blink::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Blink& _) -> std::string {return "Blink";}))    
    // TODO: assign cc.Class.extend to cc.Blink.extend
    ;


  class_<FadeTo, base<ActionInterval>>("cc.FadeTo")
    .constructor<>()
    .function("initWithDuration", &FadeTo::initWithDuration)
    .function("ctor", &cc_bindings_ctor<FadeTo>, allow_raw_pointers())
    .class_function("create", &FadeTo::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeTo& _) -> std::string {return "FadeTo";}))    
    // TODO: assign cc.Class.extend to cc.FadeTo.extend
    ;


  class_<FadeIn, base<FadeTo>>("cc.FadeIn")
    .constructor<>()
    .function("setReverseAction", &FadeIn::setReverseAction, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<FadeIn>, allow_raw_pointers())
    .class_function("create", &FadeIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeIn& _) -> std::string {return "FadeIn";}))    
    // TODO: assign cc.Class.extend to cc.FadeIn.extend
    ;


  class_<FadeOut, base<FadeTo>>("cc.FadeOut")
    .constructor<>()
    .function("setReverseAction", &FadeOut::setReverseAction, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<FadeOut>, allow_raw_pointers())
    .class_function("create", &FadeOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeOut& _) -> std::string {return "FadeOut";}))    
    // TODO: assign cc.Class.extend to cc.FadeOut.extend
    ;


  class_<TintTo, base<ActionInterval>>("cc.TintTo")
    .constructor<>()
    .function("initWithDuration", &TintTo::initWithDuration)
    .function("ctor", &cc_bindings_ctor<TintTo>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TintTo*(float, const cocos2d::Color3B&)>(&TintTo::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TintTo*(float, unsigned char, unsigned char, unsigned char)>(&TintTo::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TintTo& _) -> std::string {return "TintTo";}))    
    // TODO: assign cc.Class.extend to cc.TintTo.extend
    ;


  class_<TintBy, base<ActionInterval>>("cc.TintBy")
    .constructor<>()
    .function("initWithDuration", &TintBy::initWithDuration)
    .function("ctor", &cc_bindings_ctor<TintBy>, allow_raw_pointers())
    .class_function("create", &TintBy::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TintBy& _) -> std::string {return "TintBy";}))    
    // TODO: assign cc.Class.extend to cc.TintBy.extend
    ;


  class_<DelayTime, base<ActionInterval>>("cc.DelayTime")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<DelayTime>, allow_raw_pointers())
    .class_function("create", &DelayTime::create, allow_raw_pointers())
    .property("_className",  optional_override([](const DelayTime& _) -> std::string {return "DelayTime";}))    
    // TODO: assign cc.Class.extend to cc.DelayTime.extend
    ;


  class_<ReverseTime, base<ActionInterval>>("cc.ReverseTime")
    .constructor<>()
    .function("initWithAction", &ReverseTime::initWithAction, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ReverseTime>, allow_raw_pointers())
    .class_function("create", &ReverseTime::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ReverseTime& _) -> std::string {return "ReverseTime";}))    
    // TODO: assign cc.Class.extend to cc.ReverseTime.extend
    ;


  class_<Animate, base<ActionInterval>>("cc.Animate")
    .constructor<>()
    .function("initWithAnimation", &Animate::initWithAnimation, allow_raw_pointers())
    .function("getAnimation", select_overload<const cocos2d::Animation*() const>(&Animate::getAnimation), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getCurrentFrameIndex", &Animate::getCurrentFrameIndex)
    .function("setAnimation", &Animate::setAnimation, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<Animate>, allow_raw_pointers())
    .class_function("create", &Animate::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Animate& _) -> std::string {return "Animate";}))    
    // TODO: assign cc.Class.extend to cc.Animate.extend
    ;


  class_<TargetedAction, base<ActionInterval>>("cc.TargetedAction")
    .constructor<>()
    .function("getForcedTarget", select_overload<const cocos2d::Node*() const>(&TargetedAction::getForcedTarget), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("initWithTarget", &TargetedAction::initWithTarget, allow_raw_pointers())
    .function("setForcedTarget", &TargetedAction::setForcedTarget, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TargetedAction>, allow_raw_pointers())
    .class_function("create", &TargetedAction::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TargetedAction& _) -> std::string {return "TargetedAction";}))    
    // TODO: assign cc.Class.extend to cc.TargetedAction.extend
    ;


  class_<ActionFloat, base<ActionInterval>>("cc.ActionFloat")
    .constructor<>()
    .function("initWithDuration", &ActionFloat::initWithDuration)
    .function("ctor", &cc_bindings_ctor<ActionFloat>, allow_raw_pointers())
    .class_function("create", &ActionFloat::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionFloat& _) -> std::string {return "ActionFloat";}))    
    // TODO: assign cc.Class.extend to cc.ActionFloat.extend
    ;

  class_<Configuration>("cc.Configuration")
    .function("supportsPVRTC", &Configuration::supportsPVRTC)
    .function("supportsOESDepth24", &Configuration::supportsOESDepth24)
    .function("getMaxModelviewStackDepth", &Configuration::getMaxModelviewStackDepth)
    .function("supportsShareableVAO", &Configuration::supportsShareableVAO)
    .function("supportsBGRA8888", &Configuration::supportsBGRA8888)
    .function("checkForGLExtension", &Configuration::checkForGLExtension)
    .function("supportsETC2", &Configuration::supportsETC2)
    .function("supportsETC1", &Configuration::supportsETC1)
    .function("supportsATITC", &Configuration::supportsATITC)
    .function("supportsNPOT", &Configuration::supportsNPOT)
    .function("init", &Configuration::init)
    .function("getAnimate3DQuality", &Configuration::getAnimate3DQuality)
    .function("getMaxSupportPointLightInShader", &Configuration::getMaxSupportPointLightInShader)
    .function("getMaxTextureSize", &Configuration::getMaxTextureSize)
    .function("setValue", &Configuration::setValue)
    .function("getMaxSupportSpotLightInShader", &Configuration::getMaxSupportSpotLightInShader)
    .function("supportsETC", &Configuration::supportsETC)
    .function("getMaxSupportDirLightInShader", &Configuration::getMaxSupportDirLightInShader)
    .function("loadConfigFile", &Configuration::loadConfigFile)
    .function("supportsDiscardFramebuffer", &Configuration::supportsDiscardFramebuffer)
    .function("supportsOESPackedDepthStencil", &Configuration::supportsOESPackedDepthStencil)
    .function("supportsS3TC", &Configuration::supportsS3TC)
    .function("dumpInfo", &Configuration::getInfo)
    .function("getMaxTextureUnits", &Configuration::getMaxTextureUnits)
    .function("getValue", &Configuration::getValue)
    .function("getValue", optional_override(
        [](Configuration& this_, const std::string& arg0){
        return this_.getValue(arg0);
      }))
    .function("gatherGPUInfo", &Configuration::gatherGPUInfo)
    .function("supportsMapBuffer", &Configuration::supportsMapBuffer)
    .function("getInfoAsMap", &Configuration::getInfoAsMap)
    .class_function("destroyInstance", &Configuration::destroyInstance, allow_raw_pointers())
    .class_function("getInstance", &Configuration::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const Configuration& _) -> std::string {return "Configuration";}))    
    ;

  class_<Properties>("cc.Properties")
    .function("getVariable", &Properties::getVariable, allow_raw_pointers())
    .function("getVariable", optional_override(
        [](Properties& this_, const char* arg0){
        return this_.getVariable(arg0);
      }), allow_raw_pointers())
    .function("getString", &Properties::getString, allow_raw_pointers())
    .function("getString", optional_override(
        [](Properties& this_){
        return this_.getString();
      }), allow_raw_pointers())
    .function("getString", optional_override(
        [](Properties& this_, const char* arg0){
        return this_.getString(arg0);
      }), allow_raw_pointers())
    .function("getLong", &Properties::getLong, allow_raw_pointers())
    .function("getLong", optional_override(
        [](Properties& this_){
        return this_.getLong();
      }))
    .function("getNamespace", select_overload<const char*() const>(&Properties::getNamespace), allow_raw_pointers())
    .function("getNamespace", select_overload<cocos2d::Properties*(const char*, bool, bool) const>(&Properties::getNamespace), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .function("getPath", &Properties::getPath, allow_raw_pointers())
    .function("getMat4", &Properties::getMat4, allow_raw_pointers())
    .function("exists", &Properties::exists, allow_raw_pointers())
    .function("setString", &Properties::setString, allow_raw_pointers())
    .function("getId", &Properties::getId, allow_raw_pointers())
    .function("rewind", &Properties::rewind)
    .function("setVariable", &Properties::setVariable, allow_raw_pointers())
    .function("getBool", &Properties::getBool, allow_raw_pointers())
    .function("getBool", optional_override(
        [](Properties& this_){
        return this_.getBool();
      }))
    .function("getBool", optional_override(
        [](Properties& this_, const char* arg0){
        return this_.getBool(arg0);
      }), allow_raw_pointers())
    .function("getColor", select_overload<bool(const char*, cocos2d::Vec4*) const>(&Properties::getColor), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getType", &Properties::getType, allow_raw_pointers())
    .function("getType", optional_override(
        [](Properties& this_){
        return this_.getType();
      }))
    .function("getNextNamespace", &Properties::getNextNamespace, allow_raw_pointers())
    .function("getInt", &Properties::getInt, allow_raw_pointers())
    .function("getInt", optional_override(
        [](Properties& this_){
        return this_.getInt();
      }))
    .function("getVec3", &Properties::getVec3, allow_raw_pointers())
    .function("getVec2", &Properties::getVec2, allow_raw_pointers())
    .function("getVec4", &Properties::getVec4, allow_raw_pointers())
    .function("getNextProperty", &Properties::getNextProperty, allow_raw_pointers())
    .function("getFloat", &Properties::getFloat, allow_raw_pointers())
    .function("getFloat", optional_override(
        [](Properties& this_){
        return this_.getFloat();
      }))
    .function("getQuaternionFromAxisAngle", &Properties::getQuaternionFromAxisAngle, allow_raw_pointers())
    .class_function("parseColor", select_overload<bool(const char*, cocos2d::Vec4*)>(&Properties::parseColor), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("parseVec3", &Properties::parseVec3, allow_raw_pointers())
    .class_function("parseAxisAngle", &Properties::parseAxisAngle, allow_raw_pointers())
    .class_function("parseVec2", &Properties::parseVec2, allow_raw_pointers())
    .class_function("createNonRefCounted", &Properties::createNonRefCounted, allow_raw_pointers())
    .class_function("parseVec4", &Properties::parseVec4, allow_raw_pointers())
    .property("_className",  optional_override([](const Properties& _) -> std::string {return "Properties";}))    
    ;

  class_<FileUtils>("cc.FileUtils")
    .function("fullPathForFilename", &FileUtils::fullPathForFilename)
    .function("getStringFromFile", select_overload<void(const std::string&, std::function<void (std::string)>) const>(&FileUtils::getStringFromFile))
    .function("getStringFromFile", select_overload<std::string(const std::string&) const>(&FileUtils::getStringFromFile))
    .function("removeFile", select_overload<void(const std::string&, std::function<void (bool)>) const>(&FileUtils::removeFile))
    .function("removeFile", select_overload<bool(const std::string&) const>(&FileUtils::removeFile))
    .function("isAbsolutePath", &FileUtils::isAbsolutePath)
    .function("renameFile", select_overload<void(const std::string&, const std::string&, const std::string&, std::function<void (bool)>) const>(&FileUtils::renameFile))
    .function("renameFile", select_overload<bool(const std::string&, const std::string&, const std::string&) const>(&FileUtils::renameFile))
    .function("renameFile", select_overload<bool(const std::string&, const std::string&) const>(&FileUtils::renameFile))
    // TODO: Only support function overloading with different number of parameters
    .function("getDefaultResourceRootPath", &FileUtils::getDefaultResourceRootPath)
    .function("loadFilenameLookup", &FileUtils::loadFilenameLookupDictionaryFromFile)
    .function("isPopupNotify", &FileUtils::isPopupNotify)
    .function("getValueVectorFromFile", &FileUtils::getValueVectorFromFile)
    .function("getSearchPaths", &FileUtils::getSearchPaths)
    .function("writeToFile", &FileUtils::writeToFile)
    .function("getOriginalSearchPaths", &FileUtils::getOriginalSearchPaths)
    .function("getNewFilename", &FileUtils::getNewFilename)
    .function("listFiles", &FileUtils::listFiles)
    .function("getValueMapFromFile", &FileUtils::getValueMapFromFile)
    .function("getFileSize", select_overload<void(const std::string&, std::function<void (long)>) const>(&FileUtils::getFileSize))
    .function("getFileSize", select_overload<long(const std::string&) const>(&FileUtils::getFileSize))
    .function("getValueMapFromData", &FileUtils::getValueMapFromData, allow_raw_pointers())
    .function("removeDirectory", select_overload<void(const std::string&, std::function<void (bool)>) const>(&FileUtils::removeDirectory))
    .function("removeDirectory", select_overload<bool(const std::string&) const>(&FileUtils::removeDirectory))
    .function("setSearchPaths", &FileUtils::setSearchPaths)
    .function("writeStringToFile", select_overload<void(std::string, const std::string&, std::function<void (bool)>) const>(&FileUtils::writeStringToFile))
    .function("writeStringToFile", select_overload<bool(const std::string&, const std::string&) const>(&FileUtils::writeStringToFile))
    .function("setSearchResolutionsOrder", &FileUtils::setSearchResolutionsOrder)
    .function("addSearchResolutionsOrder", &FileUtils::addSearchResolutionsOrder)
    .function("addSearchResolutionsOrder", optional_override(
        [](FileUtils& this_, const std::string& arg0){
        return this_.addSearchResolutionsOrder(arg0);
      }))
    .function("addSearchPath", &FileUtils::addSearchPath)
    .function("addSearchPath", optional_override(
        [](FileUtils& this_, const std::string& arg0){
        return this_.addSearchPath(arg0);
      }))
    .function("writeValueVectorToFile", select_overload<void(std::vector<cocos2d::Value>, const std::string&, std::function<void (bool)>) const>(&FileUtils::writeValueVectorToFile))
    .function("writeValueVectorToFile", select_overload<bool(const std::vector<cocos2d::Value>&, const std::string&) const>(&FileUtils::writeValueVectorToFile))
    .function("isFileExist", select_overload<void(const std::string&, std::function<void (bool)>) const>(&FileUtils::isFileExist))
    .function("isFileExist", select_overload<bool(const std::string&) const>(&FileUtils::isFileExist))
    .function("purgeCachedEntries", &FileUtils::purgeCachedEntries)
    .function("fullPathFromRelativeFile", &FileUtils::fullPathFromRelativeFile)
    .function("getSuitableFOpen", &FileUtils::getSuitableFOpen)
    .function("writeValueMapToFile", select_overload<void(std::unordered_map<std::string, cocos2d::Value>, const std::string&, std::function<void (bool)>) const>(&FileUtils::writeValueMapToFile))
    .function("writeValueMapToFile", select_overload<bool(const std::unordered_map<std::string, cocos2d::Value>&, const std::string&) const>(&FileUtils::writeValueMapToFile))
    .function("getFileExtension", &FileUtils::getFileExtension)
    .function("setWritablePath", &FileUtils::setWritablePath)
    .function("setPopupNotify", &FileUtils::setPopupNotify)
    .function("isDirectoryExist", select_overload<void(const std::string&, std::function<void (bool)>) const>(&FileUtils::isDirectoryExist))
    .function("isDirectoryExist", select_overload<bool(const std::string&) const>(&FileUtils::isDirectoryExist))
    .function("setDefaultResourceRootPath", &FileUtils::setDefaultResourceRootPath)
    .function("getSearchResolutionsOrder", &FileUtils::getSearchResolutionsOrder)
    .function("createDirectory", select_overload<void(const std::string&, std::function<void (bool)>) const>(&FileUtils::createDirectory))
    .function("createDirectory", select_overload<bool(const std::string&) const>(&FileUtils::createDirectory))
    .function("getWritablePath", &FileUtils::getWritablePath)
    .function("listFilesRecursively", &FileUtils::listFilesRecursively, allow_raw_pointers())
    .class_function("setDelegate", &FileUtils::setDelegate, allow_raw_pointers())
    .class_function("getInstance", &FileUtils::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const FileUtils& _) -> std::string {return "FileUtils";}))    
    ;


  class_<EventAcceleration, base<Event>>("cc.EventAcceleration")
    .constructor<const cocos2d::Acceleration&>()
    .property("_className",  optional_override([](const EventAcceleration& _) -> std::string {return "EventAcceleration";}))    
    ;


  class_<EventCustom, base<Event>>("cc.EventCustom")
    .constructor<const std::string&>()
    .function("getEventName", &EventCustom::getEventName)
    .property("_className",  optional_override([](const EventCustom& _) -> std::string {return "EventCustom";}))    
    ;

  class_<EventListener>("cc.EventListener")
    .function("setEnabled", &EventListener::setEnabled)
    .function("isEnabled", &EventListener::isEnabled)
    .function("clone", &EventListener::clone, allow_raw_pointers())
    .function("checkAvailable", &EventListener::checkAvailable)
    .property("_className",  optional_override([](const EventListener& _) -> std::string {return "EventListener";}))    
    ;


  class_<EventDispatcher>("cc.EventDispatcher")
    .constructor<>()
    .function("setEnabled", &EventDispatcher::setEnabled)
    .function("removeAllListeners", &EventDispatcher::removeAllEventListeners)
    .function("addEventListenerWithSceneGraphPriority", &EventDispatcher::addEventListenerWithSceneGraphPriority, allow_raw_pointers())
    .function("addEventListenerWithFixedPriority", &EventDispatcher::addEventListenerWithFixedPriority, allow_raw_pointers())
    .function("removeListeners", select_overload<void(cocos2d::Node*, bool)>(&EventDispatcher::removeEventListenersForTarget), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("removeListeners", select_overload<void(cocos2d::EventListener::Type)>(&EventDispatcher::removeEventListenersForType))
    .function("resumeTarget", &EventDispatcher::resumeEventListenersForTarget, allow_raw_pointers())
    .function("resumeTarget", optional_override(
        [](EventDispatcher& this_, cocos2d::Node* arg0){
        return this_.resumeEventListenersForTarget(arg0);
      }), allow_raw_pointers())
    .function("setPriority", &EventDispatcher::setPriority, allow_raw_pointers())
    .function("dispatchEvent", &EventDispatcher::dispatchEvent, allow_raw_pointers())
    .function("hasEventListener", &EventDispatcher::hasEventListener)
    .function("pauseTarget", &EventDispatcher::pauseEventListenersForTarget, allow_raw_pointers())
    .function("pauseTarget", optional_override(
        [](EventDispatcher& this_, cocos2d::Node* arg0){
        return this_.pauseEventListenersForTarget(arg0);
      }), allow_raw_pointers())
    .function("removeCustomListeners", &EventDispatcher::removeCustomEventListeners)
    .function("removeListener", &EventDispatcher::removeEventListener, allow_raw_pointers())
    .function("isEnabled", &EventDispatcher::isEnabled)
    .property("_className",  optional_override([](const EventDispatcher& _) -> std::string {return "EventDispatcher";}))    
    ;


  class_<EventFocus, base<Event>>("cc.EventFocus")
    .constructor<cocos2d::ui::Widget*, cocos2d::ui::Widget*>()
    .property("_className",  optional_override([](const EventFocus& _) -> std::string {return "EventFocus";}))    
    ;


  class_<EventListenerAcceleration, base<EventListener>>("cc.EventListenerAcceleration")
    .constructor<>()
    .function("init", &EventListenerAcceleration::init)
    .property("_className",  optional_override([](const EventListenerAcceleration& _) -> std::string {return "EventListenerAcceleration";}))    
    ;


  class_<EventListenerCustom, base<EventListener>>("cc.EventListenerCustom")
    .constructor<>()
    .property("_className",  optional_override([](const EventListenerCustom& _) -> std::string {return "EventListenerCustom";}))    
    ;


  class_<EventListenerFocus, base<EventListener>>("cc.EventListenerFocus")
    .constructor<>()
    .function("init", &EventListenerFocus::init)
    .property("_className",  optional_override([](const EventListenerFocus& _) -> std::string {return "EventListenerFocus";}))    
    ;


  class_<EventListenerKeyboard, base<EventListener>>("cc.EventListenerKeyboard")
    .constructor<>()
    .function("init", &EventListenerKeyboard::init)
    .property("_className",  optional_override([](const EventListenerKeyboard& _) -> std::string {return "EventListenerKeyboard";}))    
    ;


  class_<EventMouse, base<Event>>("cc.EventMouse")
    .constructor<cocos2d::EventMouse::MouseEventType>()
    .function("getButton", &EventMouse::getMouseButton)
    .function("getLocation", &EventMouse::getLocation)
    .function("setButton", &EventMouse::setMouseButton)
    .function("setScrollData", &EventMouse::setScrollData)
    .function("getPreviousLocationInView", &EventMouse::getPreviousLocationInView)
    .function("getDelta", &EventMouse::getDelta)
    .function("getStartLocation", &EventMouse::getStartLocation)
    .function("getLocationY", &EventMouse::getCursorY)
    .function("getLocationX", &EventMouse::getCursorX)
    .function("getLocationInView", &EventMouse::getLocationInView)
    .function("getScrollY", &EventMouse::getScrollY)
    .function("setLocation", &EventMouse::setCursorPosition)
    .function("getScrollX", &EventMouse::getScrollX)
    .function("getPreviousLocation", &EventMouse::getPreviousLocation)
    .function("getStartLocationInView", &EventMouse::getStartLocationInView)
    .property("_className",  optional_override([](const EventMouse& _) -> std::string {return "EventMouse";}))    
    ;


  class_<EventListenerMouse, base<EventListener>>("cc.EventListenerMouse")
    .constructor<>()
    .function("init", &EventListenerMouse::init)
    .property("_className",  optional_override([](const EventListenerMouse& _) -> std::string {return "EventListenerMouse";}))    
    ;

  class_<EventListenerController, base<EventListener>>("cc.EventListenerController")
    .class_function("create", &EventListenerController::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EventListenerController& _) -> std::string {return "EventListenerController";}))    
    ;


  class_<EventListenerTouchOneByOne, base<EventListener>>("cc.EventListenerTouchOneByOne")
    .constructor<>()
    .function("isSwallowTouches", &EventListenerTouchOneByOne::isSwallowTouches)
    .function("setSwallowTouches", &EventListenerTouchOneByOne::setSwallowTouches)
    .function("init", &EventListenerTouchOneByOne::init)
    .property("_className",  optional_override([](const EventListenerTouchOneByOne& _) -> std::string {return "EventListenerTouchOneByOne";}))    
    ;


  class_<EventListenerTouchAllAtOnce, base<EventListener>>("cc.EventListenerTouchAllAtOnce")
    .constructor<>()
    .function("init", &EventListenerTouchAllAtOnce::init)
    .property("_className",  optional_override([](const EventListenerTouchAllAtOnce& _) -> std::string {return "EventListenerTouchAllAtOnce";}))    
    ;


  class_<EventController, base<Event>>("cc.EventController")
        // TODO: overloaded constructor
    .function("getControllerEventType", &EventController::getControllerEventType)
    .function("setConnectStatus", &EventController::setConnectStatus)
    .function("isConnected", &EventController::isConnected)
    .function("setKeyCode", &EventController::setKeyCode)
    .function("getController", &EventController::getController, allow_raw_pointers())
    .function("getKeyCode", &EventController::getKeyCode)
    .property("_className",  optional_override([](const EventController& _) -> std::string {return "EventController";}))    
    ;


  class_<ActionCamera, base<ActionInterval>>("cc.ActionCamera")
    .constructor<>()
    .function("setEye", select_overload<void(float, float, float)>(&ActionCamera::setEye))
    .function("setEye", select_overload<void(const cocos2d::Vec3&)>(&ActionCamera::setEye))
    .function("getEye", &ActionCamera::getEye)
    .function("setUp", &ActionCamera::setUp)
    .function("getCenter", &ActionCamera::getCenter)
    .function("setCenter", &ActionCamera::setCenter)
    .function("getUp", &ActionCamera::getUp)
    .function("ctor", &cc_bindings_ctor<ActionCamera>, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionCamera& _) -> std::string {return "ActionCamera";}))    
    // TODO: assign cc.Class.extend to cc.ActionCamera.extend
    ;


  class_<OrbitCamera, base<ActionCamera>>("cc.OrbitCamera")
    .constructor<>()
    .function("sphericalRadius", &OrbitCamera::sphericalRadius, allow_raw_pointers())
    .function("initWithDuration", &OrbitCamera::initWithDuration)
    .function("ctor", &cc_bindings_ctor<OrbitCamera>, allow_raw_pointers())
    .class_function("create", &OrbitCamera::create, allow_raw_pointers())
    .property("_className",  optional_override([](const OrbitCamera& _) -> std::string {return "OrbitCamera";}))    
    // TODO: assign cc.Class.extend to cc.OrbitCamera.extend
    ;


  class_<CardinalSplineTo, base<ActionInterval>>("cc.CardinalSplineTo")
    .constructor<>()
    .function("getPoints", &CardinalSplineTo::getPoints, allow_raw_pointers())
    .function("updatePosition", &CardinalSplineTo::updatePosition)
    .property("_className",  optional_override([](const CardinalSplineTo& _) -> std::string {return "CardinalSplineTo";}))    
    ;


  class_<CardinalSplineBy, base<CardinalSplineTo>>("cc.CardinalSplineBy")
    .constructor<>()
    .property("_className",  optional_override([](const CardinalSplineBy& _) -> std::string {return "CardinalSplineBy";}))    
    ;

  class_<CatmullRomTo, base<CardinalSplineTo>>("cc.CatmullRomTo")
    .property("_className",  optional_override([](const CatmullRomTo& _) -> std::string {return "CatmullRomTo";}))    
    ;

  class_<CatmullRomBy, base<CardinalSplineBy>>("cc.CatmullRomBy")
    .property("_className",  optional_override([](const CatmullRomBy& _) -> std::string {return "CatmullRomBy";}))    
    ;

  class_<ActionEase, base<ActionInterval>>("cc.ActionEase")
    .function("initWithAction", &ActionEase::initWithAction, allow_raw_pointers())
    .function("getInnerAction", &ActionEase::getInnerAction, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionEase& _) -> std::string {return "ActionEase";}))    
    ;

  class_<EaseRateAction, base<ActionEase>>("cc.EaseRateAction")
    .function("setRate", &EaseRateAction::setRate)
    .function("initWithAction", &EaseRateAction::initWithAction, allow_raw_pointers())
    .function("getRate", &EaseRateAction::getRate)
    .class_function("create", &EaseRateAction::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseRateAction& _) -> std::string {return "EaseRateAction";}))    
    ;


  class_<EaseExponentialIn, base<ActionEase>>("cc.EaseExponentialIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseExponentialIn>, allow_raw_pointers())
    .class_function("create", &EaseExponentialIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseExponentialIn& _) -> std::string {return "EaseExponentialIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseExponentialIn.extend
    ;


  class_<EaseExponentialOut, base<ActionEase>>("cc.EaseExponentialOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseExponentialOut>, allow_raw_pointers())
    .class_function("create", &EaseExponentialOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseExponentialOut& _) -> std::string {return "EaseExponentialOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseExponentialOut.extend
    ;


  class_<EaseExponentialInOut, base<ActionEase>>("cc.EaseExponentialInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseExponentialInOut>, allow_raw_pointers())
    .class_function("create", &EaseExponentialInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseExponentialInOut& _) -> std::string {return "EaseExponentialInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseExponentialInOut.extend
    ;


  class_<EaseSineIn, base<ActionEase>>("cc.EaseSineIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseSineIn>, allow_raw_pointers())
    .class_function("create", &EaseSineIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseSineIn& _) -> std::string {return "EaseSineIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseSineIn.extend
    ;


  class_<EaseSineOut, base<ActionEase>>("cc.EaseSineOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseSineOut>, allow_raw_pointers())
    .class_function("create", &EaseSineOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseSineOut& _) -> std::string {return "EaseSineOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseSineOut.extend
    ;


  class_<EaseSineInOut, base<ActionEase>>("cc.EaseSineInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseSineInOut>, allow_raw_pointers())
    .class_function("create", &EaseSineInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseSineInOut& _) -> std::string {return "EaseSineInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseSineInOut.extend
    ;

  class_<EaseBounce, base<ActionEase>>("cc.EaseBounce")
    .property("_className",  optional_override([](const EaseBounce& _) -> std::string {return "EaseBounce";}))    
    ;


  class_<EaseBounceIn, base<ActionEase>>("cc.EaseBounceIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseBounceIn>, allow_raw_pointers())
    .class_function("create", &EaseBounceIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBounceIn& _) -> std::string {return "EaseBounceIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseBounceIn.extend
    ;


  class_<EaseBounceOut, base<ActionEase>>("cc.EaseBounceOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseBounceOut>, allow_raw_pointers())
    .class_function("create", &EaseBounceOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBounceOut& _) -> std::string {return "EaseBounceOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseBounceOut.extend
    ;


  class_<EaseBounceInOut, base<ActionEase>>("cc.EaseBounceInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseBounceInOut>, allow_raw_pointers())
    .class_function("create", &EaseBounceInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBounceInOut& _) -> std::string {return "EaseBounceInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseBounceInOut.extend
    ;


  class_<EaseBackIn, base<ActionEase>>("cc.EaseBackIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseBackIn>, allow_raw_pointers())
    .class_function("create", &EaseBackIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBackIn& _) -> std::string {return "EaseBackIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseBackIn.extend
    ;


  class_<EaseBackOut, base<ActionEase>>("cc.EaseBackOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseBackOut>, allow_raw_pointers())
    .class_function("create", &EaseBackOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBackOut& _) -> std::string {return "EaseBackOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseBackOut.extend
    ;


  class_<EaseBackInOut, base<ActionEase>>("cc.EaseBackInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseBackInOut>, allow_raw_pointers())
    .class_function("create", &EaseBackInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBackInOut& _) -> std::string {return "EaseBackInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseBackInOut.extend
    ;


  class_<EaseQuadraticActionIn, base<ActionEase>>("cc.EaseQuadraticActionIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuadraticActionIn>, allow_raw_pointers())
    .class_function("create", &EaseQuadraticActionIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuadraticActionIn& _) -> std::string {return "EaseQuadraticActionIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuadraticActionIn.extend
    ;


  class_<EaseQuadraticActionOut, base<ActionEase>>("cc.EaseQuadraticActionOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuadraticActionOut>, allow_raw_pointers())
    .class_function("create", &EaseQuadraticActionOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuadraticActionOut& _) -> std::string {return "EaseQuadraticActionOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuadraticActionOut.extend
    ;


  class_<EaseQuadraticActionInOut, base<ActionEase>>("cc.EaseQuadraticActionInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuadraticActionInOut>, allow_raw_pointers())
    .class_function("create", &EaseQuadraticActionInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuadraticActionInOut& _) -> std::string {return "EaseQuadraticActionInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuadraticActionInOut.extend
    ;


  class_<EaseQuarticActionIn, base<ActionEase>>("cc.EaseQuarticActionIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuarticActionIn>, allow_raw_pointers())
    .class_function("create", &EaseQuarticActionIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuarticActionIn& _) -> std::string {return "EaseQuarticActionIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuarticActionIn.extend
    ;


  class_<EaseQuarticActionOut, base<ActionEase>>("cc.EaseQuarticActionOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuarticActionOut>, allow_raw_pointers())
    .class_function("create", &EaseQuarticActionOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuarticActionOut& _) -> std::string {return "EaseQuarticActionOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuarticActionOut.extend
    ;


  class_<EaseQuarticActionInOut, base<ActionEase>>("cc.EaseQuarticActionInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuarticActionInOut>, allow_raw_pointers())
    .class_function("create", &EaseQuarticActionInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuarticActionInOut& _) -> std::string {return "EaseQuarticActionInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuarticActionInOut.extend
    ;


  class_<EaseQuinticActionIn, base<ActionEase>>("cc.EaseQuinticActionIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuinticActionIn>, allow_raw_pointers())
    .class_function("create", &EaseQuinticActionIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuinticActionIn& _) -> std::string {return "EaseQuinticActionIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuinticActionIn.extend
    ;


  class_<EaseQuinticActionOut, base<ActionEase>>("cc.EaseQuinticActionOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuinticActionOut>, allow_raw_pointers())
    .class_function("create", &EaseQuinticActionOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuinticActionOut& _) -> std::string {return "EaseQuinticActionOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuinticActionOut.extend
    ;


  class_<EaseQuinticActionInOut, base<ActionEase>>("cc.EaseQuinticActionInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseQuinticActionInOut>, allow_raw_pointers())
    .class_function("create", &EaseQuinticActionInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuinticActionInOut& _) -> std::string {return "EaseQuinticActionInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseQuinticActionInOut.extend
    ;


  class_<EaseCircleActionIn, base<ActionEase>>("cc.EaseCircleActionIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseCircleActionIn>, allow_raw_pointers())
    .class_function("create", &EaseCircleActionIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCircleActionIn& _) -> std::string {return "EaseCircleActionIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseCircleActionIn.extend
    ;


  class_<EaseCircleActionOut, base<ActionEase>>("cc.EaseCircleActionOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseCircleActionOut>, allow_raw_pointers())
    .class_function("create", &EaseCircleActionOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCircleActionOut& _) -> std::string {return "EaseCircleActionOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseCircleActionOut.extend
    ;


  class_<EaseCircleActionInOut, base<ActionEase>>("cc.EaseCircleActionInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseCircleActionInOut>, allow_raw_pointers())
    .class_function("create", &EaseCircleActionInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCircleActionInOut& _) -> std::string {return "EaseCircleActionInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseCircleActionInOut.extend
    ;


  class_<EaseCubicActionIn, base<ActionEase>>("cc.EaseCubicActionIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseCubicActionIn>, allow_raw_pointers())
    .class_function("create", &EaseCubicActionIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCubicActionIn& _) -> std::string {return "EaseCubicActionIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseCubicActionIn.extend
    ;


  class_<EaseCubicActionOut, base<ActionEase>>("cc.EaseCubicActionOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseCubicActionOut>, allow_raw_pointers())
    .class_function("create", &EaseCubicActionOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCubicActionOut& _) -> std::string {return "EaseCubicActionOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseCubicActionOut.extend
    ;


  class_<EaseCubicActionInOut, base<ActionEase>>("cc.EaseCubicActionInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseCubicActionInOut>, allow_raw_pointers())
    .class_function("create", &EaseCubicActionInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCubicActionInOut& _) -> std::string {return "EaseCubicActionInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseCubicActionInOut.extend
    ;


  class_<EaseIn, base<EaseRateAction>>("cc.EaseIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseIn>, allow_raw_pointers())
    .class_function("create", &EaseIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseIn& _) -> std::string {return "EaseIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseIn.extend
    ;


  class_<EaseOut, base<EaseRateAction>>("cc.EaseOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseOut>, allow_raw_pointers())
    .class_function("create", &EaseOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseOut& _) -> std::string {return "EaseOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseOut.extend
    ;


  class_<EaseInOut, base<EaseRateAction>>("cc.EaseInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseInOut>, allow_raw_pointers())
    .class_function("create", &EaseInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseInOut& _) -> std::string {return "EaseInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseInOut.extend
    ;

  class_<EaseElastic, base<ActionEase>>("cc.EaseElastic")
    .function("setPeriod", &EaseElastic::setPeriod)
    .function("initWithAction", &EaseElastic::initWithAction, allow_raw_pointers())
    .function("initWithAction", optional_override(
        [](EaseElastic& this_, cocos2d::ActionInterval* arg0){
        return this_.initWithAction(arg0);
      }), allow_raw_pointers())
    .function("getPeriod", &EaseElastic::getPeriod)
    .property("_className",  optional_override([](const EaseElastic& _) -> std::string {return "EaseElastic";}))    
    ;


  class_<EaseElasticIn, base<EaseElastic>>("cc.EaseElasticIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseElasticIn>, allow_raw_pointers())
    .class_function("create", &EaseElasticIn::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](cocos2d::ActionInterval* arg0){
        return EaseElasticIn::create(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const EaseElasticIn& _) -> std::string {return "EaseElasticIn";}))    
    // TODO: assign cc.Class.extend to cc.EaseElasticIn.extend
    ;


  class_<EaseElasticOut, base<EaseElastic>>("cc.EaseElasticOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseElasticOut>, allow_raw_pointers())
    .class_function("create", &EaseElasticOut::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](cocos2d::ActionInterval* arg0){
        return EaseElasticOut::create(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const EaseElasticOut& _) -> std::string {return "EaseElasticOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseElasticOut.extend
    ;


  class_<EaseElasticInOut, base<EaseElastic>>("cc.EaseElasticInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<EaseElasticInOut>, allow_raw_pointers())
    .class_function("create", &EaseElasticInOut::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](cocos2d::ActionInterval* arg0){
        return EaseElasticInOut::create(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const EaseElasticInOut& _) -> std::string {return "EaseElasticInOut";}))    
    // TODO: assign cc.Class.extend to cc.EaseElasticInOut.extend
    ;


  class_<EaseBezierAction, base<ActionEase>>("cc.EaseBezierAction")
    .constructor<>()
    .function("setBezierParamer", &EaseBezierAction::setBezierParamer)
    .function("ctor", &cc_bindings_ctor<EaseBezierAction>, allow_raw_pointers())
    .class_function("create", &EaseBezierAction::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBezierAction& _) -> std::string {return "EaseBezierAction";}))    
    // TODO: assign cc.Class.extend to cc.EaseBezierAction.extend
    ;

  class_<ActionInstant, base<FiniteTimeAction>>("cc.ActionInstant")
    .property("_className",  optional_override([](const ActionInstant& _) -> std::string {return "ActionInstant";}))    
    ;


  class_<Show, base<ActionInstant>>("cc.Show")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<Show>, allow_raw_pointers())
    .class_function("create", &Show::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Show& _) -> std::string {return "Show";}))    
    // TODO: assign cc.Class.extend to cc.Show.extend
    ;


  class_<Hide, base<ActionInstant>>("cc.Hide")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<Hide>, allow_raw_pointers())
    .class_function("create", &Hide::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Hide& _) -> std::string {return "Hide";}))    
    // TODO: assign cc.Class.extend to cc.Hide.extend
    ;


  class_<ToggleVisibility, base<ActionInstant>>("cc.ToggleVisibility")
    .constructor<>()
    .class_function("create", &ToggleVisibility::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ToggleVisibility& _) -> std::string {return "ToggleVisibility";}))    
    ;


  class_<RemoveSelf, base<ActionInstant>>("cc.RemoveSelf")
    .constructor<>()
    .function("init", &RemoveSelf::init)
    .class_function("create", &RemoveSelf::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](){
        return RemoveSelf::create();
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const RemoveSelf& _) -> std::string {return "RemoveSelf";}))    
    ;


  class_<FlipX, base<ActionInstant>>("cc.FlipX")
    .constructor<>()
    .function("initWithFlipX", &FlipX::initWithFlipX)
    .function("ctor", &cc_bindings_ctor<FlipX>, allow_raw_pointers())
    .class_function("create", &FlipX::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FlipX& _) -> std::string {return "FlipX";}))    
    // TODO: assign cc.Class.extend to cc.FlipX.extend
    ;


  class_<FlipY, base<ActionInstant>>("cc.FlipY")
    .constructor<>()
    .function("initWithFlipY", &FlipY::initWithFlipY)
    .function("ctor", &cc_bindings_ctor<FlipY>, allow_raw_pointers())
    .class_function("create", &FlipY::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FlipY& _) -> std::string {return "FlipY";}))    
    // TODO: assign cc.Class.extend to cc.FlipY.extend
    ;


  class_<Place, base<ActionInstant>>("cc.Place")
    .constructor<>()
    .function("initWithPosition", &Place::initWithPosition)
    .function("ctor", &cc_bindings_ctor<Place>, allow_raw_pointers())
    .class_function("create", &Place::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Place& _) -> std::string {return "Place";}))    
    // TODO: assign cc.Class.extend to cc.Place.extend
    ;


  class_<CallFunc, base<ActionInstant>>("cc._CallFunc")
    .constructor<>()
    .function("execute", &CallFunc::execute)
    .function("ctor", &cc_bindings_ctor<CallFunc>, allow_raw_pointers())
    .property("_className",  optional_override([](const CallFunc& _) -> std::string {return "CallFunc";}))    
    // TODO: assign cc.Class.extend to cc._CallFunc.extend
    ;


  class_<CallFuncN, base<CallFunc>>("cc.CallFunc")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<CallFuncN>, allow_raw_pointers())
    .property("_className",  optional_override([](const CallFuncN& _) -> std::string {return "CallFuncN";}))    
    // TODO: assign cc.Class.extend to cc.CallFunc.extend
    ;

  class_<GridAction, base<ActionInterval>>("cc.GridAction")
    .function("getGrid", &GridAction::getGrid, allow_raw_pointers())
    .function("initWithDuration", &GridAction::initWithDuration)
    .property("_className",  optional_override([](const GridAction& _) -> std::string {return "GridAction";}))    
    ;

  class_<Grid3DAction, base<GridAction>>("cc.Grid3DAction")
    .function("getGridRect", &Grid3DAction::getGridRect)
    .property("_className",  optional_override([](const Grid3DAction& _) -> std::string {return "Grid3DAction";}))    
    ;

  class_<TiledGrid3DAction, base<GridAction>>("cc.TiledGrid3DAction")
    .property("_className",  optional_override([](const TiledGrid3DAction& _) -> std::string {return "TiledGrid3DAction";}))    
    ;


  class_<StopGrid, base<ActionInstant>>("cc.StopGrid")
    .constructor<>()
    .class_function("create", &StopGrid::create, allow_raw_pointers())
    .property("_className",  optional_override([](const StopGrid& _) -> std::string {return "StopGrid";}))    
    ;


  class_<ReuseGrid, base<ActionInstant>>("cc.ReuseGrid")
    .constructor<>()
    .function("initWithTimes", &ReuseGrid::initWithTimes)
    .class_function("create", &ReuseGrid::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ReuseGrid& _) -> std::string {return "ReuseGrid";}))    
    ;


  class_<Waves3D, base<Grid3DAction>>("cc.Waves3D")
    .constructor<>()
    .function("setAmplitudeRate", &Waves3D::setAmplitudeRate)
    .function("initWithDuration", &Waves3D::initWithDuration)
    .function("getAmplitude", &Waves3D::getAmplitude)
    .function("getAmplitudeRate", &Waves3D::getAmplitudeRate)
    .function("setAmplitude", &Waves3D::setAmplitude)
    .class_function("create", &Waves3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Waves3D& _) -> std::string {return "Waves3D";}))    
    ;


  class_<FlipX3D, base<Grid3DAction>>("cc.FlipX3D")
    .constructor<>()
    .function("initWithSize", &FlipX3D::initWithSize)
    .function("initWithDuration", &FlipX3D::initWithDuration)
    .function("ctor", &cc_bindings_ctor<FlipX3D>, allow_raw_pointers())
    .class_function("create", &FlipX3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FlipX3D& _) -> std::string {return "FlipX3D";}))    
    // TODO: assign cc.Class.extend to cc.FlipX3D.extend
    ;


  class_<FlipY3D, base<FlipX3D>>("cc.FlipY3D")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<FlipY3D>, allow_raw_pointers())
    .class_function("create", &FlipY3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FlipY3D& _) -> std::string {return "FlipY3D";}))    
    // TODO: assign cc.Class.extend to cc.FlipY3D.extend
    ;


  class_<Lens3D, base<Grid3DAction>>("cc.Lens3D")
    .constructor<>()
    .function("setConcave", &Lens3D::setConcave)
    .function("initWithDuration", &Lens3D::initWithDuration)
    .function("setLensEffect", &Lens3D::setLensEffect)
    .function("getLensEffect", &Lens3D::getLensEffect)
    .function("setPosition", &Lens3D::setPosition)
    .function("getPosition", &Lens3D::getPosition)
    .class_function("create", &Lens3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Lens3D& _) -> std::string {return "Lens3D";}))    
    ;


  class_<Ripple3D, base<Grid3DAction>>("cc.Ripple3D")
    .constructor<>()
    .function("setAmplitudeRate", &Ripple3D::setAmplitudeRate)
    .function("initWithDuration", &Ripple3D::initWithDuration)
    .function("getAmplitudeRate", &Ripple3D::getAmplitudeRate)
    .function("setAmplitude", &Ripple3D::setAmplitude)
    .function("getAmplitude", &Ripple3D::getAmplitude)
    .function("setPosition", &Ripple3D::setPosition)
    .function("getPosition", &Ripple3D::getPosition)
    .class_function("create", &Ripple3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Ripple3D& _) -> std::string {return "Ripple3D";}))    
    ;


  class_<Shaky3D, base<Grid3DAction>>("cc.Shaky3D")
    .constructor<>()
    .function("initWithDuration", &Shaky3D::initWithDuration)
    .class_function("create", &Shaky3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Shaky3D& _) -> std::string {return "Shaky3D";}))    
    ;


  class_<Liquid, base<Grid3DAction>>("cc.Liquid")
    .constructor<>()
    .function("setAmplitudeRate", &Liquid::setAmplitudeRate)
    .function("initWithDuration", &Liquid::initWithDuration)
    .function("getAmplitude", &Liquid::getAmplitude)
    .function("getAmplitudeRate", &Liquid::getAmplitudeRate)
    .function("setAmplitude", &Liquid::setAmplitude)
    .class_function("create", &Liquid::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Liquid& _) -> std::string {return "Liquid";}))    
    ;


  class_<Waves, base<Grid3DAction>>("cc.Waves")
    .constructor<>()
    .function("setAmplitudeRate", &Waves::setAmplitudeRate)
    .function("initWithDuration", &Waves::initWithDuration)
    .function("getAmplitude", &Waves::getAmplitude)
    .function("getAmplitudeRate", &Waves::getAmplitudeRate)
    .function("setAmplitude", &Waves::setAmplitude)
    .class_function("create", &Waves::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Waves& _) -> std::string {return "Waves";}))    
    ;


  class_<Twirl, base<Grid3DAction>>("cc.Twirl")
    .constructor<>()
    .function("setAmplitudeRate", &Twirl::setAmplitudeRate)
    .function("initWithDuration", &Twirl::initWithDuration)
    .function("getAmplitudeRate", &Twirl::getAmplitudeRate)
    .function("setAmplitude", &Twirl::setAmplitude)
    .function("getAmplitude", &Twirl::getAmplitude)
    .function("setPosition", &Twirl::setPosition)
    .function("getPosition", &Twirl::getPosition)
    .class_function("create", &Twirl::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Twirl& _) -> std::string {return "Twirl";}))    
    ;


  class_<ActionManager>("cc.ActionManager")
    .constructor<>()
    .function("getActionByTag", &ActionManager::getActionByTag, allow_raw_pointers())
    .function("removeActionByTag", &ActionManager::removeActionByTag, allow_raw_pointers())
    .function("removeActionsByFlags", &ActionManager::removeActionsByFlags, allow_raw_pointers())
    .function("removeAllActions", &ActionManager::removeAllActions)
    .function("addAction", &ActionManager::addAction, allow_raw_pointers())
    .function("resumeTarget", &ActionManager::resumeTarget, allow_raw_pointers())
    .function("getNumberOfRunningActions", &ActionManager::getNumberOfRunningActions)
    .function("pauseTarget", &ActionManager::pauseTarget, allow_raw_pointers())
    .function("getNumberOfRunningActionsInTarget", &ActionManager::getNumberOfRunningActionsInTarget, allow_raw_pointers())
    .function("removeAllActionsFromTarget", &ActionManager::removeAllActionsFromTarget, allow_raw_pointers())
    .function("resumeTargets", &ActionManager::resumeTargets)
    .function("removeAction", &ActionManager::removeAction, allow_raw_pointers())
    .function("pauseAllRunningActions", &ActionManager::pauseAllRunningActions)
    .function("update", &ActionManager::update)
    .function("removeAllActionsByTag", &ActionManager::removeAllActionsByTag, allow_raw_pointers())
    .function("getNumberOfRunningActionsInTargetByTag", &ActionManager::getNumberOfRunningActionsInTargetByTag, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ActionManager>, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionManager& _) -> std::string {return "ActionManager";}))    
    // TODO: assign cc.Class.extend to cc.ActionManager.extend
    ;

  class_<PageTurn3D, base<Grid3DAction>>("cc.PageTurn3D")
    .class_function("create", &PageTurn3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const PageTurn3D& _) -> std::string {return "PageTurn3D";}))    
    ;


  class_<ProgressTo, base<ActionInterval>>("cc.ProgressTo")
    .constructor<>()
    .function("initWithDuration", &ProgressTo::initWithDuration)
    .function("ctor", &cc_bindings_ctor<ProgressTo>, allow_raw_pointers())
    .class_function("create", &ProgressTo::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ProgressTo& _) -> std::string {return "ProgressTo";}))    
    // TODO: assign cc.Class.extend to cc.ProgressTo.extend
    ;


  class_<ProgressFromTo, base<ActionInterval>>("cc.ProgressFromTo")
    .constructor<>()
    .function("initWithDuration", &ProgressFromTo::initWithDuration)
    .function("ctor", &cc_bindings_ctor<ProgressFromTo>, allow_raw_pointers())
    .class_function("create", &ProgressFromTo::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ProgressFromTo& _) -> std::string {return "ProgressFromTo";}))    
    // TODO: assign cc.Class.extend to cc.ProgressFromTo.extend
    ;


  class_<ShakyTiles3D, base<TiledGrid3DAction>>("cc.ShakyTiles3D")
    .constructor<>()
    .function("initWithDuration", &ShakyTiles3D::initWithDuration)
    .class_function("create", &ShakyTiles3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ShakyTiles3D& _) -> std::string {return "ShakyTiles3D";}))    
    ;


  class_<ShatteredTiles3D, base<TiledGrid3DAction>>("cc.ShatteredTiles3D")
    .constructor<>()
    .function("initWithDuration", &ShatteredTiles3D::initWithDuration)
    .class_function("create", &ShatteredTiles3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ShatteredTiles3D& _) -> std::string {return "ShatteredTiles3D";}))    
    ;


  class_<ShuffleTiles, base<TiledGrid3DAction>>("cc.ShuffleTiles")
    .constructor<>()
    .function("placeTile", &ShuffleTiles::placeTile, allow_raw_pointers())
    .function("shuffle", &ShuffleTiles::shuffle, allow_raw_pointers())
    .function("initWithDuration", &ShuffleTiles::initWithDuration)
    .function("getDelta", &ShuffleTiles::getDelta)
    .class_function("create", &ShuffleTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ShuffleTiles& _) -> std::string {return "ShuffleTiles";}))    
    ;


  class_<FadeOutTRTiles, base<TiledGrid3DAction>>("cc.FadeOutTRTiles")
    .constructor<>()
    .function("turnOnTile", &FadeOutTRTiles::turnOnTile)
    .function("turnOffTile", &FadeOutTRTiles::turnOffTile)
    .function("transformTile", &FadeOutTRTiles::transformTile)
    .function("testFunc", &FadeOutTRTiles::testFunc)
    .function("ctor", &cc_bindings_ctor<FadeOutTRTiles>, allow_raw_pointers())
    .class_function("create", &FadeOutTRTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeOutTRTiles& _) -> std::string {return "FadeOutTRTiles";}))    
    // TODO: assign cc.Class.extend to cc.FadeOutTRTiles.extend
    ;


  class_<FadeOutBLTiles, base<FadeOutTRTiles>>("cc.FadeOutBLTiles")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<FadeOutBLTiles>, allow_raw_pointers())
    .class_function("create", &FadeOutBLTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeOutBLTiles& _) -> std::string {return "FadeOutBLTiles";}))    
    // TODO: assign cc.Class.extend to cc.FadeOutBLTiles.extend
    ;


  class_<FadeOutUpTiles, base<FadeOutTRTiles>>("cc.FadeOutUpTiles")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<FadeOutUpTiles>, allow_raw_pointers())
    .class_function("create", &FadeOutUpTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeOutUpTiles& _) -> std::string {return "FadeOutUpTiles";}))    
    // TODO: assign cc.Class.extend to cc.FadeOutUpTiles.extend
    ;


  class_<FadeOutDownTiles, base<FadeOutUpTiles>>("cc.FadeOutDownTiles")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<FadeOutDownTiles>, allow_raw_pointers())
    .class_function("create", &FadeOutDownTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeOutDownTiles& _) -> std::string {return "FadeOutDownTiles";}))    
    // TODO: assign cc.Class.extend to cc.FadeOutDownTiles.extend
    ;


  class_<TurnOffTiles, base<TiledGrid3DAction>>("cc.TurnOffTiles")
    .constructor<>()
    .function("turnOnTile", &TurnOffTiles::turnOnTile)
    .function("turnOffTile", &TurnOffTiles::turnOffTile)
    .function("shuffle", &TurnOffTiles::shuffle, allow_raw_pointers())
    .function("initWithDuration", &TurnOffTiles::initWithDuration)
    .class_function("create", select_overload<cocos2d::TurnOffTiles*(float, const cocos2d::Size&, unsigned int)>(&TurnOffTiles::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TurnOffTiles*(float, const cocos2d::Size&)>(&TurnOffTiles::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TurnOffTiles& _) -> std::string {return "TurnOffTiles";}))    
    ;


  class_<WavesTiles3D, base<TiledGrid3DAction>>("cc.WavesTiles3D")
    .constructor<>()
    .function("setAmplitudeRate", &WavesTiles3D::setAmplitudeRate)
    .function("initWithDuration", &WavesTiles3D::initWithDuration)
    .function("getAmplitude", &WavesTiles3D::getAmplitude)
    .function("getAmplitudeRate", &WavesTiles3D::getAmplitudeRate)
    .function("setAmplitude", &WavesTiles3D::setAmplitude)
    .class_function("create", &WavesTiles3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const WavesTiles3D& _) -> std::string {return "WavesTiles3D";}))    
    ;


  class_<JumpTiles3D, base<TiledGrid3DAction>>("cc.JumpTiles3D")
    .constructor<>()
    .function("setAmplitudeRate", &JumpTiles3D::setAmplitudeRate)
    .function("initWithDuration", &JumpTiles3D::initWithDuration)
    .function("getAmplitude", &JumpTiles3D::getAmplitude)
    .function("getAmplitudeRate", &JumpTiles3D::getAmplitudeRate)
    .function("setAmplitude", &JumpTiles3D::setAmplitude)
    .function("ctor", &cc_bindings_ctor<JumpTiles3D>, allow_raw_pointers())
    .class_function("create", &JumpTiles3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const JumpTiles3D& _) -> std::string {return "JumpTiles3D";}))    
    // TODO: assign cc.Class.extend to cc.JumpTiles3D.extend
    ;


  class_<SplitRows, base<TiledGrid3DAction>>("cc.SplitRows")
    .constructor<>()
    .function("initWithDuration", &SplitRows::initWithDuration)
    .class_function("create", &SplitRows::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SplitRows& _) -> std::string {return "SplitRows";}))    
    ;


  class_<SplitCols, base<TiledGrid3DAction>>("cc.SplitCols")
    .constructor<>()
    .function("initWithDuration", &SplitCols::initWithDuration)
    .class_function("create", &SplitCols::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SplitCols& _) -> std::string {return "SplitCols";}))    
    ;

  class_<ActionTween, base<ActionInterval>>("cc.ActionTween")
    .function("initWithDuration", &ActionTween::initWithDuration)
    .class_function("create", &ActionTween::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionTween& _) -> std::string {return "ActionTween";}))    
    // TODO: assign cc.Class.extend to cc.ActionTween.extend
    ;


  class_<AtlasNode, base<Node>>("cc.AtlasNode")
    .constructor<>()
    .function("updateAtlasValues", &AtlasNode::updateAtlasValues)
    .function("initWithTileFile", &AtlasNode::initWithTileFile)
    .function("getTexture", &AtlasNode::getTexture, allow_raw_pointers())
    .function("setTextureAtlas", &AtlasNode::setTextureAtlas, allow_raw_pointers())
    .function("setBlendFunc", &AtlasNode::setBlendFunc)
    .function("getTextureAtlas", &AtlasNode::getTextureAtlas, allow_raw_pointers())
    .function("getBlendFunc", &AtlasNode::getBlendFunc)
    .function("getQuadsToDraw", &AtlasNode::getQuadsToDraw)
    .function("setTexture", &AtlasNode::setTexture, allow_raw_pointers())
    .function("initWithTexture", &AtlasNode::initWithTexture, allow_raw_pointers())
    .function("setQuadsToDraw", &AtlasNode::setQuadsToDraw)
    .class_function("create", &AtlasNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AtlasNode& _) -> std::string {return "AtlasNode";}))    
    ;


  class_<ClippingNode, base<Node>>("cc.ClippingNode")
    .constructor<>()
    .function("hasContent", &ClippingNode::hasContent)
    .function("setInverted", &ClippingNode::setInverted)
    .function("setStencil", &ClippingNode::setStencil, allow_raw_pointers())
    .function("getAlphaThreshold", &ClippingNode::getAlphaThreshold)
    .function("getStencil", &ClippingNode::getStencil, allow_raw_pointers())
    .function("setAlphaThreshold", &ClippingNode::setAlphaThreshold)
    .function("isInverted", &ClippingNode::isInverted)
    .class_function("create", select_overload<cocos2d::ClippingNode*(cocos2d::Node*)>(&ClippingNode::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ClippingNode*()>(&ClippingNode::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ClippingNode& _) -> std::string {return "ClippingNode";}))    
    ;


  class_<DrawNode, base<Node>>("cc.DrawNode")
    .constructor<float>()
    .function("drawLine", &DrawNode::drawLine)
    .function("drawPoints", select_overload<void(const cocos2d::Vec2*, unsigned int, const float, const cocos2d::Color4F&)>(&DrawNode::drawPoints), allow_raw_pointers())
    .function("drawPoints", select_overload<void(const cocos2d::Vec2*, unsigned int, const cocos2d::Color4F&)>(&DrawNode::drawPoints), allow_raw_pointers())
    .function("setIsolated", &DrawNode::setIsolated)
    .function("drawRect", select_overload<void(const cocos2d::Vec2&, const cocos2d::Vec2&, const cocos2d::Vec2&, const cocos2d::Vec2&, const cocos2d::Color4F&)>(&DrawNode::drawRect))
    .function("drawRect", select_overload<void(const cocos2d::Vec2&, const cocos2d::Vec2&, const cocos2d::Color4F&)>(&DrawNode::drawRect))
    .function("drawSolidCircle", select_overload<void(const cocos2d::Vec2&, float, float, unsigned int, const cocos2d::Color4F&)>(&DrawNode::drawSolidCircle))
    .function("drawSolidCircle", select_overload<void(const cocos2d::Vec2&, float, float, unsigned int, float, float, const cocos2d::Color4F&)>(&DrawNode::drawSolidCircle))
    .function("setLineWidth", &DrawNode::setLineWidth)
    .function("onDrawGLPoint", &DrawNode::onDrawGLPoint)
    .function("drawPolygon", &DrawNode::drawPolygon, allow_raw_pointers())
    .function("drawDot", &DrawNode::drawDot)
    .function("drawCatmullRom", &DrawNode::drawCatmullRom, allow_raw_pointers())
    .function("drawSegment", &DrawNode::drawSegment)
    .function("getBlendFunc", &DrawNode::getBlendFunc)
    .function("onDraw", &DrawNode::onDraw)
    .function("drawCircle", select_overload<void(const cocos2d::Vec2&, float, float, unsigned int, bool, const cocos2d::Color4F&)>(&DrawNode::drawCircle))
    .function("drawCircle", select_overload<void(const cocos2d::Vec2&, float, float, unsigned int, bool, float, float, const cocos2d::Color4F&)>(&DrawNode::drawCircle))
    .function("onDrawGLLine", &DrawNode::onDrawGLLine)
    .function("drawSolidPoly", &DrawNode::drawSolidPoly, allow_raw_pointers())
    .function("drawTriangle", &DrawNode::drawTriangle)
    .function("setBlendFunc", &DrawNode::setBlendFunc)
    .function("clear", &DrawNode::clear)
    .function("drawCardinalSpline", &DrawNode::drawCardinalSpline, allow_raw_pointers())
    .function("drawSolidRect", &DrawNode::drawSolidRect)
    .function("getLineWidth", &DrawNode::getLineWidth)
    .function("drawPoint", &DrawNode::drawPoint)
    .function("isIsolated", &DrawNode::isIsolated)
    .function("drawCubicBezier", &DrawNode::drawCubicBezier)
    .function("ctor", &cc_bindings_ctor<DrawNode>, allow_raw_pointers())
    .class_function("create", &DrawNode::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](){
        return DrawNode::create();
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const DrawNode& _) -> std::string {return "DrawNode";}))    
    // TODO: assign cc.Class.extend to cc.DrawNode.extend
    ;


  class_<Label, base<Node>>("cc.Label")
    .constructor<cocos2d::TextHAlignment, cocos2d::TextVAlignment>()
    .function("isClipMarginEnabled", &Label::isClipMarginEnabled)
    .function("enableShadow", &Label::enableShadow)
    .function("enableShadow", optional_override(
        [](Label& this_){
        return this_.enableShadow();
      }))
    .function("enableShadow", optional_override(
        [](Label& this_, const cocos2d::Color4B& arg0){
        return this_.enableShadow(arg0);
      }))
    .function("enableShadow", optional_override(
        [](Label& this_, const cocos2d::Color4B& arg0, const cocos2d::Size& arg1){
        return this_.enableShadow(arg0, arg1);
      }))
    .function("setDimensions", &Label::setDimensions)
    .function("getWidth", &Label::getWidth)
    .function("getString", &Label::getString)
    .function("getHeight", &Label::getHeight)
    .function("disableEffect", select_overload<void(cocos2d::LabelEffect)>(&Label::disableEffect))
    .function("disableEffect", select_overload<void()>(&Label::disableEffect))
    .function("getLabelType", &Label::getLabelType)
    .function("getTextColor", &Label::getTextColor)
    .function("getBlendFunc", &Label::getBlendFunc)
    .function("enableWrap", &Label::enableWrap)
    .function("setWidth", &Label::setWidth)
    .function("getAdditionalKerning", &Label::getAdditionalKerning)
    .function("getBMFontSize", &Label::getBMFontSize)
    .function("getMaxLineWidth", &Label::getMaxLineWidth)
    .function("getHorizontalAlignment", &Label::getHorizontalAlignment)
    .function("getShadowOffset", &Label::getShadowOffset)
    .function("getLineSpacing", &Label::getLineSpacing)
    .function("setClipMarginEnabled", &Label::setClipMarginEnabled)
    .function("setString", &Label::setString)
    .function("setSystemFontName", &Label::setSystemFontName)
    .function("isWrapEnabled", &Label::isWrapEnabled)
    .function("getOutlineSize", &Label::getOutlineSize)
    .function("setBMFontFilePath", select_overload<bool(const std::string&, const cocos2d::Rect&, bool, float)>(&Label::setBMFontFilePath))
    // TODO: Only support function overloading with different number of parameters
    .function("setBMFontFilePath", select_overload<bool(const std::string&, float)>(&Label::setBMFontFilePath))
    // TODO: Only support function overloading with different number of parameters
    .function("setBMFontFilePath", select_overload<bool(const std::string&, const std::string&, float)>(&Label::setBMFontFilePath))
    // TODO: Only support function overloading with different number of parameters
    .function("initWithTTF", select_overload<bool(const cocos2d::_ttfConfig&, const std::string&, cocos2d::TextHAlignment, int)>(&Label::initWithTTF))
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .function("initWithTTF", select_overload<bool(const std::string&, const std::string&, float, const cocos2d::Size&, cocos2d::TextHAlignment, cocos2d::TextVAlignment)>(&Label::initWithTTF))
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .function("setLineHeight", &Label::setLineHeight)
    .function("setSystemFontSize", &Label::setSystemFontSize)
    .function("setOverflow", &Label::setOverflow)
    .function("enableStrikethrough", &Label::enableStrikethrough)
    .function("updateContent", &Label::updateContent)
    .function("getStringLength", &Label::getStringLength)
    .function("setLineBreakWithoutSpace", &Label::setLineBreakWithoutSpace)
    .function("getStringNumLines", &Label::getStringNumLines)
    .function("enableOutline", &Label::enableOutline)
    .function("enableOutline", optional_override(
        [](Label& this_, const cocos2d::Color4B& arg0){
        return this_.enableOutline(arg0);
      }))
    .function("getShadowBlurRadius", &Label::getShadowBlurRadius)
    .function("getEffectColor", &Label::getEffectColor)
    .function("removeAllChildrenWithCleanup", &Label::removeAllChildrenWithCleanup)
    .function("setCharMap", select_overload<bool(cocos2d::Texture2D*, int, int, int)>(&Label::setCharMap), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setCharMap", select_overload<bool(const std::string&)>(&Label::setCharMap))
    .function("getDimensions", &Label::getDimensions)
    .function("setMaxLineWidth", &Label::setMaxLineWidth)
    .function("getSystemFontName", &Label::getSystemFontName)
    .function("setVerticalAlignment", &Label::setVerticalAlignment)
    .function("setLineSpacing", &Label::setLineSpacing)
    .function("getRenderingFontSize", &Label::getRenderingFontSize)
    .function("getLineHeight", &Label::getLineHeight)
    .function("getShadowColor", &Label::getShadowColor)
    .function("getTTFConfig", &Label::getTTFConfig)
    .function("enableItalics", &Label::enableItalics)
    .function("setTextColor", &Label::setTextColor)
    .function("getLetter", &Label::getLetter, allow_raw_pointers())
    .function("setHeight", &Label::setHeight)
    .function("isShadowEnabled", &Label::isShadowEnabled)
    .function("enableGlow", &Label::enableGlow)
    .function("getOverflow", &Label::getOverflow)
    .function("getVerticalAlignment", &Label::getVerticalAlignment)
    .function("setAdditionalKerning", &Label::setAdditionalKerning)
    .function("getSystemFontSize", &Label::getSystemFontSize)
    .function("setBlendFunc", &Label::setBlendFunc)
    .function("getTextAlignment", &Label::getTextAlignment)
    .function("getBMFontFilePath", &Label::getBMFontFilePath)
    .function("setHorizontalAlignment", &Label::setHorizontalAlignment)
    .function("enableBold", &Label::enableBold)
    .function("enableUnderline", &Label::enableUnderline)
    .function("getLabelEffectType", &Label::getLabelEffectType)
    .function("setAlignment", select_overload<void(cocos2d::TextHAlignment, cocos2d::TextVAlignment)>(&Label::setAlignment))
    .function("setAlignment", select_overload<void(cocos2d::TextHAlignment)>(&Label::setAlignment))
    .function("requestSystemFontRefresh", &Label::requestSystemFontRefresh)
    .function("setBMFontSize", &Label::setBMFontSize)
    .function("ctor", &cc_bindings_ctor<Label>, allow_raw_pointers())
    .class_function("createWithBMFont", select_overload<cocos2d::Label*(const std::string&, const std::string&, const cocos2d::TextHAlignment&, int, const cocos2d::Rect&, bool)>(&Label::createWithBMFont), allow_raw_pointers())
    .class_function("createWithBMFont", select_overload<cocos2d::Label*(const std::string&, const std::string&, const cocos2d::TextHAlignment&, int)>(&Label::createWithBMFont), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithBMFont", select_overload<cocos2d::Label*(const std::string&, const std::string&, const cocos2d::TextHAlignment&, int, const std::string&)>(&Label::createWithBMFont), allow_raw_pointers())
    .class_function("createWithCharMap", select_overload<cocos2d::Label*(cocos2d::Texture2D*, int, int, int)>(&Label::createWithCharMap), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithCharMap", select_overload<cocos2d::Label*(const std::string&)>(&Label::createWithCharMap), allow_raw_pointers())
    .class_function("createWithSystemFont", &Label::createWithSystemFont, allow_raw_pointers())
    .class_function("createWithSystemFont", optional_override(
      [](const std::string& arg0, const std::string& arg1, float arg2){
        return Label::createWithSystemFont(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .class_function("createWithSystemFont", optional_override(
      [](const std::string& arg0, const std::string& arg1, float arg2, const cocos2d::Size& arg3){
        return Label::createWithSystemFont(arg0, arg1, arg2, arg3);
      }), allow_raw_pointers())
    .class_function("createWithSystemFont", optional_override(
      [](const std::string& arg0, const std::string& arg1, float arg2, const cocos2d::Size& arg3, cocos2d::TextHAlignment arg4){
        return Label::createWithSystemFont(arg0, arg1, arg2, arg3, arg4);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const Label& _) -> std::string {return "Label";}))    
    // TODO: assign cc.Class.extend to cc.Label.extend
    ;


  class_<LabelAtlas, base<AtlasNode>>("cc.LabelAtlas")
    .constructor<>()
    .function("setString", &LabelAtlas::setString)
    .function("initWithString", select_overload<bool(const std::string&, const std::string&)>(&LabelAtlas::initWithString))
    .function("initWithString", select_overload<bool(const std::string&, const std::string&, int, int, int)>(&LabelAtlas::initWithString))
    // TODO: Only support function overloading with different number of parameters
    .function("getString", &LabelAtlas::getString)
    .function("ctor", &cc_bindings_ctor<LabelAtlas>, allow_raw_pointers())
    .class_function("_create", select_overload<cocos2d::LabelAtlas*(const std::string&, const std::string&, int, int, int)>(&LabelAtlas::create), allow_raw_pointers())
    .class_function("_create", select_overload<cocos2d::LabelAtlas*()>(&LabelAtlas::create), allow_raw_pointers())
    .class_function("_create", select_overload<cocos2d::LabelAtlas*(const std::string&, const std::string&)>(&LabelAtlas::create), allow_raw_pointers())
    .property("_className",  optional_override([](const LabelAtlas& _) -> std::string {return "LabelAtlas";}))    
    // TODO: assign cc.Class.extend to cc.LabelAtlas.extend
    ;


  class_<LabelBMFont, base<Node>>("cc.LabelBMFont")
    .constructor<>()
    .function("setLineBreakWithoutSpace", &LabelBMFont::setLineBreakWithoutSpace)
    .function("getBlendFunc", &LabelBMFont::getBlendFunc)
    .function("getLetter", &LabelBMFont::getLetter, allow_raw_pointers())
    .function("getString", &LabelBMFont::getString)
    .function("setBlendFunc", &LabelBMFont::setBlendFunc)
    .function("setString", &LabelBMFont::setString)
    .function("initWithString", &LabelBMFont::initWithString)
    .function("initWithString", optional_override(
        [](LabelBMFont& this_, const std::string& arg0, const std::string& arg1){
        return this_.initWithString(arg0, arg1);
      }))
    .function("initWithString", optional_override(
        [](LabelBMFont& this_, const std::string& arg0, const std::string& arg1, float arg2){
        return this_.initWithString(arg0, arg1, arg2);
      }))
    .function("initWithString", optional_override(
        [](LabelBMFont& this_, const std::string& arg0, const std::string& arg1, float arg2, cocos2d::TextHAlignment arg3){
        return this_.initWithString(arg0, arg1, arg2, arg3);
      }))
    .function("getFntFile", &LabelBMFont::getFntFile)
    .function("setFntFile", select_overload<void(const std::string&, const cocos2d::Rect&, bool)>(&LabelBMFont::setFntFile))
    .function("setFntFile", select_overload<void(const std::string&, const cocos2d::Vec2&)>(&LabelBMFont::setFntFile))
    // TODO: Only support function overloading with different number of parameters
    .function("setAlignment", &LabelBMFont::setAlignment)
    .function("setWidth", &LabelBMFont::setWidth)
    .function("ctor", &cc_bindings_ctor<LabelBMFont>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LabelBMFont*()>(&LabelBMFont::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LabelBMFont*(const std::string&, const std::string&, float, cocos2d::TextHAlignment, const cocos2d::Vec2&)>(&LabelBMFont::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const LabelBMFont& _) -> std::string {return "LabelBMFont";}))    
    // TODO: assign cc.Class.extend to cc.LabelBMFont.extend
    ;


  class_<LabelTTF, base<Node>>("cc.LabelTTF")
    .constructor<>()
    .function("enableShadow", &LabelTTF::enableShadow)
    .function("enableShadow", optional_override(
        [](LabelTTF& this_, const cocos2d::Size& arg0, float arg1, float arg2){
        return this_.enableShadow(arg0, arg1, arg2);
      }))
    .function("setDimensions", &LabelTTF::setDimensions)
    .function("getFontSize", &LabelTTF::getFontSize)
    .function("getString", &LabelTTF::getString)
    .function("setFlippedY", &LabelTTF::setFlippedY)
    .function("setFlippedX", &LabelTTF::setFlippedX)
    .function("setTextDefinition", &LabelTTF::setTextDefinition)
    .function("setFontName", &LabelTTF::setFontName)
    .function("getHorizontalAlignment", &LabelTTF::getHorizontalAlignment)
    .function("initWithStringAndTextDefinition", &LabelTTF::initWithStringAndTextDefinition)
    .function("setString", &LabelTTF::setString)
    .function("initWithString", &LabelTTF::initWithString)
    .function("initWithString", optional_override(
        [](LabelTTF& this_, const std::string& arg0, const std::string& arg1, float arg2){
        return this_.initWithString(arg0, arg1, arg2);
      }))
    .function("initWithString", optional_override(
        [](LabelTTF& this_, const std::string& arg0, const std::string& arg1, float arg2, const cocos2d::Size& arg3){
        return this_.initWithString(arg0, arg1, arg2, arg3);
      }))
    .function("initWithString", optional_override(
        [](LabelTTF& this_, const std::string& arg0, const std::string& arg1, float arg2, const cocos2d::Size& arg3, cocos2d::TextHAlignment arg4){
        return this_.initWithString(arg0, arg1, arg2, arg3, arg4);
      }))
    .function("setFontFillColor", &LabelTTF::setFontFillColor)
    .function("setFontFillColor", optional_override(
        [](LabelTTF& this_, const cocos2d::Color3B& arg0){
        return this_.setFontFillColor(arg0);
      }))
    .function("getBlendFunc", &LabelTTF::getBlendFunc)
    .function("enableStroke", &LabelTTF::enableStroke)
    .function("enableStroke", optional_override(
        [](LabelTTF& this_, const cocos2d::Color3B& arg0, float arg1){
        return this_.enableStroke(arg0, arg1);
      }))
    .function("getDimensions", &LabelTTF::getDimensions)
    .function("setVerticalAlignment", &LabelTTF::setVerticalAlignment)
    .function("setFontSize", &LabelTTF::setFontSize)
    .function("getVerticalAlignment", &LabelTTF::getVerticalAlignment)
    .function("getTextDefinition", &LabelTTF::getTextDefinition)
    .function("setBlendFunc", &LabelTTF::setBlendFunc)
    .function("getFontName", &LabelTTF::getFontName)
    .function("setHorizontalAlignment", &LabelTTF::setHorizontalAlignment)
    .function("disableShadow", &LabelTTF::disableShadow)
    .function("disableShadow", optional_override(
        [](LabelTTF& this_){
        return this_.disableShadow();
      }))
    .function("disableStroke", &LabelTTF::disableStroke)
    .function("disableStroke", optional_override(
        [](LabelTTF& this_){
        return this_.disableStroke();
      }))
    .function("ctor", &cc_bindings_ctor<LabelTTF>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LabelTTF*()>(&LabelTTF::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LabelTTF*(const std::string&, const std::string&, float, const cocos2d::Size&, cocos2d::TextHAlignment, cocos2d::TextVAlignment)>(&LabelTTF::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithFontDefinition", &LabelTTF::createWithFontDefinition, allow_raw_pointers())
    .property("_className",  optional_override([](const LabelTTF& _) -> std::string {return "LabelTTF";}))    
    // TODO: assign cc.Class.extend to cc.LabelTTF.extend
    ;


  class_<Layer, base<Node>>("cc.Layer")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<Layer>, allow_raw_pointers())
    .class_function("create", &Layer::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Layer& _) -> std::string {return "Layer";}))    
    // TODO: assign cc.Class.extend to cc.Layer.extend
    ;


  class_<__LayerRGBA, base<Layer>>("cc.__LayerRGBA")
    .constructor<>()
    .class_function("create", &__LayerRGBA::create, allow_raw_pointers())
    .property("_className",  optional_override([](const __LayerRGBA& _) -> std::string {return "__LayerRGBA";}))    
    ;


  class_<LayerColor, base<Layer>>("cc.LayerColor")
    .constructor<>()
    .function("changeWidthAndHeight", &LayerColor::changeWidthAndHeight)
    .function("getBlendFunc", &LayerColor::getBlendFunc)
    .function("setBlendFunc", &LayerColor::setBlendFunc)
    .function("changeWidth", &LayerColor::changeWidth)
    .function("init", select_overload<bool(const cocos2d::Color4B&)>(&LayerColor::initWithColor))
    .function("init", select_overload<bool(const cocos2d::Color4B&, float, float)>(&LayerColor::initWithColor))
    .function("changeHeight", &LayerColor::changeHeight)
    .function("ctor", &cc_bindings_ctor<LayerColor>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerColor*(const cocos2d::Color4B&, float, float)>(&LayerColor::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerColor*()>(&LayerColor::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerColor*(const cocos2d::Color4B&)>(&LayerColor::create), allow_raw_pointers())
    .property("_className",  optional_override([](const LayerColor& _) -> std::string {return "LayerColor";}))    
    // TODO: assign cc.Class.extend to cc.LayerColor.extend
    ;


  class_<LayerGradient, base<LayerColor>>("cc.LayerGradient")
    .constructor<>()
    .function("getStartColor", &LayerGradient::getStartColor)
    .function("isCompressedInterpolation", &LayerGradient::isCompressedInterpolation)
    .function("getStartOpacity", &LayerGradient::getStartOpacity)
    .function("setVector", &LayerGradient::setVector)
    .function("setStartOpacity", &LayerGradient::setStartOpacity)
    .function("setCompressedInterpolation", &LayerGradient::setCompressedInterpolation)
    .function("setEndOpacity", &LayerGradient::setEndOpacity)
    .function("getVector", &LayerGradient::getVector)
    .function("setEndColor", &LayerGradient::setEndColor)
    .function("initWithColor", select_overload<bool(const cocos2d::Color4B&, const cocos2d::Color4B&, const cocos2d::Vec2&)>(&LayerGradient::initWithColor))
    .function("initWithColor", select_overload<bool(const cocos2d::Color4B&, const cocos2d::Color4B&)>(&LayerGradient::initWithColor))
    .function("getEndColor", &LayerGradient::getEndColor)
    .function("getEndOpacity", &LayerGradient::getEndOpacity)
    .function("setStartColor", &LayerGradient::setStartColor)
    .function("ctor", &cc_bindings_ctor<LayerGradient>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerGradient*(const cocos2d::Color4B&, const cocos2d::Color4B&)>(&LayerGradient::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerGradient*()>(&LayerGradient::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerGradient*(const cocos2d::Color4B&, const cocos2d::Color4B&, const cocos2d::Vec2&)>(&LayerGradient::create), allow_raw_pointers())
    .property("_className",  optional_override([](const LayerGradient& _) -> std::string {return "LayerGradient";}))    
    // TODO: assign cc.Class.extend to cc.LayerGradient.extend
    ;


  class_<LayerRadialGradient, base<Layer>>("cc.LayerRadialGradient")
    .constructor<>()
    .function("getStartColor", &LayerRadialGradient::getStartColor)
    .function("getBlendFunc", &LayerRadialGradient::getBlendFunc)
    .function("getStartColor3B", &LayerRadialGradient::getStartColor3B)
    .function("getStartOpacity", &LayerRadialGradient::getStartOpacity)
    .function("setCenter", &LayerRadialGradient::setCenter)
    .function("getEndColor", &LayerRadialGradient::getEndColor)
    .function("setStartOpacity", &LayerRadialGradient::setStartOpacity)
    .function("getCenter", &LayerRadialGradient::getCenter)
    .function("setEndOpacity", &LayerRadialGradient::setEndOpacity)
    .function("setExpand", &LayerRadialGradient::setExpand)
    .function("getEndOpacity", &LayerRadialGradient::getEndOpacity)
    .function("initWithColor", &LayerRadialGradient::initWithColor)
    .function("setEndColor", select_overload<void(const cocos2d::Color4B&)>(&LayerRadialGradient::setEndColor))
    // TODO: Only support function overloading with different number of parameters
    .function("getEndColor3B", &LayerRadialGradient::getEndColor3B)
    .function("setRadius", &LayerRadialGradient::setRadius)
    .function("setStartColor", select_overload<void(const cocos2d::Color4B&)>(&LayerRadialGradient::setStartColor))
    // TODO: Only support function overloading with different number of parameters
    .function("getExpand", &LayerRadialGradient::getExpand)
    .function("setBlendFunc", &LayerRadialGradient::setBlendFunc)
    .function("getRadius", &LayerRadialGradient::getRadius)
    .function("ctor", &cc_bindings_ctor<LayerRadialGradient>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerRadialGradient*()>(&LayerRadialGradient::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::LayerRadialGradient*(const cocos2d::Color4B&, const cocos2d::Color4B&, float, const cocos2d::Vec2&, float)>(&LayerRadialGradient::create), allow_raw_pointers())
    .property("_className",  optional_override([](const LayerRadialGradient& _) -> std::string {return "LayerRadialGradient";}))    
    // TODO: assign cc.Class.extend to cc.LayerRadialGradient.extend
    ;


  class_<LayerMultiplex, base<Layer>>("cc.LayerMultiplex")
    .constructor<>()
    .function("initWithArray", &LayerMultiplex::initWithArray)
    .function("switchToAndReleaseMe", &LayerMultiplex::switchToAndReleaseMe)
    .function("addLayer", &LayerMultiplex::addLayer, allow_raw_pointers())
    .function("switchTo", select_overload<void(int, bool)>(&LayerMultiplex::switchTo))
    .function("switchTo", select_overload<void(int)>(&LayerMultiplex::switchTo))
    .function("ctor", &cc_bindings_ctor<LayerMultiplex>, allow_raw_pointers())
    .property("_className",  optional_override([](const LayerMultiplex& _) -> std::string {return "LayerMultiplex";}))    
    // TODO: assign cc.Class.extend to cc.LayerMultiplex.extend
    ;


  class_<MenuItem, base<Node>>("cc.MenuItem")
    .constructor<>()
    .function("setEnabled", &MenuItem::setEnabled)
    .function("activate", &MenuItem::activate)
    .function("initWithCallback", &MenuItem::initWithCallback)
    .function("isEnabled", &MenuItem::isEnabled)
    .function("selected", &MenuItem::selected)
    .function("isSelected", &MenuItem::isSelected)
    .function("setCallback", &MenuItem::setCallback)
    .function("unselected", &MenuItem::unselected)
    .function("rect", &MenuItem::rect)
    .function("ctor", &cc_bindings_ctor<MenuItem>, allow_raw_pointers())
    .property("_className",  optional_override([](const MenuItem& _) -> std::string {return "MenuItem";}))    
    // TODO: assign cc.Class.extend to cc.MenuItem.extend
    ;


  class_<MenuItemLabel, base<MenuItem>>("cc.MenuItemLabel")
    .constructor<>()
    .function("setLabel", &MenuItemLabel::setLabel, allow_raw_pointers())
    .function("getString", &MenuItemLabel::getString)
    .function("getDisabledColor", &MenuItemLabel::getDisabledColor)
    .function("setString", &MenuItemLabel::setString)
    .function("setDisabledColor", &MenuItemLabel::setDisabledColor)
    .function("getLabel", &MenuItemLabel::getLabel, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<MenuItemLabel>, allow_raw_pointers())
    .property("_className",  optional_override([](const MenuItemLabel& _) -> std::string {return "MenuItemLabel";}))    
    // TODO: assign cc.Class.extend to cc.MenuItemLabel.extend
    ;


  class_<MenuItemAtlasFont, base<MenuItemLabel>>("cc.MenuItemAtlasFont")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<MenuItemAtlasFont>, allow_raw_pointers())
    .property("_className",  optional_override([](const MenuItemAtlasFont& _) -> std::string {return "MenuItemAtlasFont";}))    
    // TODO: assign cc.Class.extend to cc.MenuItemAtlasFont.extend
    ;


  class_<MenuItemFont, base<MenuItemLabel>>("cc.MenuItemFont")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<MenuItemFont>, allow_raw_pointers())
    .property("_className",  optional_override([](const MenuItemFont& _) -> std::string {return "MenuItemFont";}))    
    // TODO: assign cc.Class.extend to cc.MenuItemFont.extend
    ;


  class_<MenuItemSprite, base<MenuItem>>("cc.MenuItemSprite")
    .constructor<>()
    .function("setEnabled", &MenuItemSprite::setEnabled)
    .function("selected", &MenuItemSprite::selected)
    .function("setNormalImage", &MenuItemSprite::setNormalImage, allow_raw_pointers())
    .function("setDisabledImage", &MenuItemSprite::setDisabledImage, allow_raw_pointers())
    .function("setSelectedImage", &MenuItemSprite::setSelectedImage, allow_raw_pointers())
    .function("getDisabledImage", &MenuItemSprite::getDisabledImage, allow_raw_pointers())
    .function("getSelectedImage", &MenuItemSprite::getSelectedImage, allow_raw_pointers())
    .function("getNormalImage", &MenuItemSprite::getNormalImage, allow_raw_pointers())
    .function("unselected", &MenuItemSprite::unselected)
    .function("ctor", &cc_bindings_ctor<MenuItemSprite>, allow_raw_pointers())
    .property("_className",  optional_override([](const MenuItemSprite& _) -> std::string {return "MenuItemSprite";}))    
    // TODO: assign cc.Class.extend to cc.MenuItemSprite.extend
    ;


  class_<MenuItemImage, base<MenuItemSprite>>("cc.MenuItemImage")
    .constructor<>()
    .function("setDisabledSpriteFrame", &MenuItemImage::setDisabledSpriteFrame, allow_raw_pointers())
    .function("setSelectedSpriteFrame", &MenuItemImage::setSelectedSpriteFrame, allow_raw_pointers())
    .function("setNormalSpriteFrame", &MenuItemImage::setNormalSpriteFrame, allow_raw_pointers())
    .function("init", &MenuItemImage::init)
    .function("ctor", &cc_bindings_ctor<MenuItemImage>, allow_raw_pointers())
    .property("_className",  optional_override([](const MenuItemImage& _) -> std::string {return "MenuItemImage";}))    
    // TODO: assign cc.Class.extend to cc.MenuItemImage.extend
    ;


  class_<MenuItemToggle, base<MenuItem>>("cc.MenuItemToggle")
    .constructor<>()
    .function("setSubItems", &MenuItemToggle::setSubItems)
    .function("initWithItem", &MenuItemToggle::initWithItem, allow_raw_pointers())
    .function("getSelectedIndex", &MenuItemToggle::getSelectedIndex)
    .function("addSubItem", &MenuItemToggle::addSubItem, allow_raw_pointers())
    .function("getSelectedItem", &MenuItemToggle::getSelectedItem, allow_raw_pointers())
    .function("setSelectedIndex", &MenuItemToggle::setSelectedIndex)
    .function("ctor", &cc_bindings_ctor<MenuItemToggle>, allow_raw_pointers())
    .property("_className",  optional_override([](const MenuItemToggle& _) -> std::string {return "MenuItemToggle";}))    
    // TODO: assign cc.Class.extend to cc.MenuItemToggle.extend
    ;


  class_<Menu, base<Layer>>("cc.Menu")
    .constructor<>()
    .function("initWithArray", &Menu::initWithArray)
    .function("setEnabled", &Menu::setEnabled)
    .function("alignItemsVertically", &Menu::alignItemsVertically)
    .function("isEnabled", &Menu::isEnabled)
    .function("alignItemsHorizontally", &Menu::alignItemsHorizontally)
    .function("alignItemsHorizontallyWithPadding", &Menu::alignItemsHorizontallyWithPadding)
    .function("alignItemsVerticallyWithPadding", &Menu::alignItemsVerticallyWithPadding)
    .function("ctor", &cc_bindings_ctor<Menu>, allow_raw_pointers())
    .property("_className",  optional_override([](const Menu& _) -> std::string {return "Menu";}))    
    // TODO: assign cc.Class.extend to cc.Menu.extend
    ;


  class_<MotionStreak, base<Node>>("cc.MotionStreak")
    .constructor<>()
    .function("reset", &MotionStreak::reset)
    .function("setTexture", &MotionStreak::setTexture, allow_raw_pointers())
    .function("getTexture", &MotionStreak::getTexture, allow_raw_pointers())
    .function("tintWithColor", &MotionStreak::tintWithColor)
    .function("setBlendFunc", &MotionStreak::setBlendFunc)
    .function("setStartingPositionInitialized", &MotionStreak::setStartingPositionInitialized)
    .function("getBlendFunc", &MotionStreak::getBlendFunc)
    .function("isStartingPositionInitialized", &MotionStreak::isStartingPositionInitialized)
    .function("isFastMode", &MotionStreak::isFastMode)
    .function("getStroke", &MotionStreak::getStroke)
    .function("initWithFade", select_overload<bool(float, float, float, const cocos2d::Color3B&, cocos2d::Texture2D*)>(&MotionStreak::initWithFade), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setFastMode", &MotionStreak::setFastMode)
    .function("setStroke", &MotionStreak::setStroke)
    .function("ctor", &cc_bindings_ctor<MotionStreak>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::MotionStreak*(float, float, float, const cocos2d::Color3B&, cocos2d::Texture2D*)>(&MotionStreak::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const MotionStreak& _) -> std::string {return "MotionStreak";}))    
    // TODO: assign cc.Class.extend to cc.MotionStreak.extend
    ;


  class_<NodeGrid, base<Node>>("cc.NodeGrid")
    .constructor<>()
    .function("setTarget", &NodeGrid::setTarget, allow_raw_pointers())
    .function("getGrid", select_overload<const cocos2d::GridBase*() const>(&NodeGrid::getGrid), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getGridRect", &NodeGrid::getGridRect)
    .class_function("create", select_overload<cocos2d::NodeGrid*(const cocos2d::Rect&)>(&NodeGrid::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::NodeGrid*()>(&NodeGrid::create), allow_raw_pointers())
    .property("_className",  optional_override([](const NodeGrid& _) -> std::string {return "NodeGrid";}))    
    ;


  class_<ParticleBatchNode, base<Node>>("cc.ParticleBatchNode")
    .constructor<>()
    .function("setTexture", &ParticleBatchNode::setTexture, allow_raw_pointers())
    .function("initWithTexture", &ParticleBatchNode::initWithTexture, allow_raw_pointers())
    .function("disableParticle", &ParticleBatchNode::disableParticle)
    .function("getTexture", &ParticleBatchNode::getTexture, allow_raw_pointers())
    .function("setTextureAtlas", &ParticleBatchNode::setTextureAtlas, allow_raw_pointers())
    .function("initWithFile", &ParticleBatchNode::initWithFile)
    .function("setBlendFunc", &ParticleBatchNode::setBlendFunc)
    .function("removeAllChildrenWithCleanup", &ParticleBatchNode::removeAllChildrenWithCleanup)
    .function("getTextureAtlas", &ParticleBatchNode::getTextureAtlas, allow_raw_pointers())
    .function("getBlendFunc", &ParticleBatchNode::getBlendFunc)
    .function("insertChild", &ParticleBatchNode::insertChild, allow_raw_pointers())
    .function("removeChildAtIndex", &ParticleBatchNode::removeChildAtIndex)
    .function("ctor", &cc_bindings_ctor<ParticleBatchNode>, allow_raw_pointers())
    .class_function("create", &ParticleBatchNode::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](const std::string& arg0){
        return ParticleBatchNode::create(arg0);
      }), allow_raw_pointers())
    .class_function("createWithTexture", &ParticleBatchNode::createWithTexture, allow_raw_pointers())
    .class_function("createWithTexture", optional_override(
      [](cocos2d::Texture2D* arg0){
        return ParticleBatchNode::createWithTexture(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleBatchNode& _) -> std::string {return "ParticleBatchNode";}))    
    // TODO: assign cc.Class.extend to cc.ParticleBatchNode.extend
    ;


  class_<ParticleData>("cc.ParticleData")
    .constructor<>()
    // TODO: Emscripten cannot automatically call destructor.
    .function("release", &ParticleData::release)
    .function("getMaxCount", &ParticleData::getMaxCount)
    .function("init", &ParticleData::init)
    .function("copyParticle", &ParticleData::copyParticle)
    .property("_className",  optional_override([](const ParticleData& _) -> std::string {return "ParticleData";}))    
    ;


  class_<ParticleSystem, base<Node>>("cc.ParticleSystem")
    .constructor<>()
    .function("getStartSizeVar", &ParticleSystem::getStartSizeVar)
    .function("getTexture", &ParticleSystem::getTexture, allow_raw_pointers())
    .function("isFull", &ParticleSystem::isFull)
    .function("getBatchNode", &ParticleSystem::getBatchNode, allow_raw_pointers())
    .function("getStartColor", &ParticleSystem::getStartColor)
    .function("getPositionType", &ParticleSystem::getPositionType)
    .function("setPosVar", &ParticleSystem::setPosVar)
    .function("getEndSpin", &ParticleSystem::getEndSpin)
    .function("setRotatePerSecondVar", &ParticleSystem::setRotatePerSecondVar)
    .function("setSourcePositionCompatible", &ParticleSystem::setSourcePositionCompatible)
    .function("getStartSpinVar", &ParticleSystem::getStartSpinVar)
    .function("getRadialAccelVar", &ParticleSystem::getRadialAccelVar)
    .function("getEndSizeVar", &ParticleSystem::getEndSizeVar)
    .function("setTangentialAccel", &ParticleSystem::setTangentialAccel)
    .function("getRadialAccel", &ParticleSystem::getRadialAccel)
    .function("setStartRadius", &ParticleSystem::setStartRadius)
    .function("setRotatePerSecond", &ParticleSystem::setRotatePerSecond)
    .function("setEndSize", &ParticleSystem::setEndSize)
    .function("getGravity", &ParticleSystem::getGravity)
    .function("resumeEmissions", &ParticleSystem::resumeEmissions)
    .function("getTangentialAccel", &ParticleSystem::getTangentialAccel)
    .function("setEndRadius", &ParticleSystem::setEndRadius)
    .function("getSpeed", &ParticleSystem::getSpeed)
    .function("pauseEmissions", &ParticleSystem::pauseEmissions)
    .function("getAngle", &ParticleSystem::getAngle)
    .function("setEndColor", &ParticleSystem::setEndColor)
    .function("setStartSpin", &ParticleSystem::setStartSpin)
    .function("setDuration", &ParticleSystem::setDuration)
    .function("initWithTotalParticles", &ParticleSystem::initWithTotalParticles)
    .function("addParticles", &ParticleSystem::addParticles)
    .function("setTexture", &ParticleSystem::setTexture, allow_raw_pointers())
    .function("getPosVar", &ParticleSystem::getPosVar)
    .function("updateWithNoTime", &ParticleSystem::updateWithNoTime)
    .function("isBlendAdditive", &ParticleSystem::isBlendAdditive)
    .function("getSpeedVar", &ParticleSystem::getSpeedVar)
    .function("setPositionType", &ParticleSystem::setPositionType)
    .function("stopSystem", &ParticleSystem::stopSystem)
    .function("getSourcePosition", &ParticleSystem::getSourcePosition)
    .function("setLifeVar", &ParticleSystem::setLifeVar)
    .function("setTotalParticles", &ParticleSystem::setTotalParticles)
    .function("setEndColorVar", &ParticleSystem::setEndColorVar)
    .function("getAtlasIndex", &ParticleSystem::getAtlasIndex)
    .function("getStartSize", &ParticleSystem::getStartSize)
    .function("setStartSpinVar", &ParticleSystem::setStartSpinVar)
    .function("resetSystem", &ParticleSystem::resetSystem)
    .function("setAtlasIndex", &ParticleSystem::setAtlasIndex)
    .function("setTangentialAccelVar", &ParticleSystem::setTangentialAccelVar)
    .function("setEndRadiusVar", &ParticleSystem::setEndRadiusVar)
    .function("getEndRadius", &ParticleSystem::getEndRadius)
    .function("isActive", &ParticleSystem::isActive)
    .function("setRadialAccelVar", &ParticleSystem::setRadialAccelVar)
    .function("setStartSize", &ParticleSystem::setStartSize)
    .function("setSpeed", &ParticleSystem::setSpeed)
    .function("getStartSpin", &ParticleSystem::getStartSpin)
    .function("getResourceFile", &ParticleSystem::getResourceFile)
    .function("getRotatePerSecond", &ParticleSystem::getRotatePerSecond)
    .function("setEmitterMode", &ParticleSystem::setEmitterMode)
    .function("getDuration", &ParticleSystem::getDuration)
    .function("setSourcePosition", &ParticleSystem::setSourcePosition)
    .function("stop", &ParticleSystem::stop)
    .function("updateParticleQuads", &ParticleSystem::updateParticleQuads)
    .function("getEndSpinVar", &ParticleSystem::getEndSpinVar)
    .function("setBlendAdditive", &ParticleSystem::setBlendAdditive)
    .function("setLife", &ParticleSystem::setLife)
    .function("setAngleVar", &ParticleSystem::setAngleVar)
    .function("setRotationIsDir", &ParticleSystem::setRotationIsDir)
    .function("start", &ParticleSystem::start)
    .function("setEndSizeVar", &ParticleSystem::setEndSizeVar)
    .function("setAngle", &ParticleSystem::setAngle)
    .function("setBatchNode", &ParticleSystem::setBatchNode, allow_raw_pointers())
    .function("getTangentialAccelVar", &ParticleSystem::getTangentialAccelVar)
    .function("getEmitterMode", &ParticleSystem::getEmitterMode)
    .function("setEndSpinVar", &ParticleSystem::setEndSpinVar)
    .function("initWithFile", &ParticleSystem::initWithFile)
    .function("getAngleVar", &ParticleSystem::getAngleVar)
    .function("setStartColor", &ParticleSystem::setStartColor)
    .function("getRotatePerSecondVar", &ParticleSystem::getRotatePerSecondVar)
    .function("getEndSize", &ParticleSystem::getEndSize)
    .function("getLife", &ParticleSystem::getLife)
    .function("isPaused", &ParticleSystem::isPaused)
    .function("setSpeedVar", &ParticleSystem::setSpeedVar)
    .function("setAutoRemoveOnFinish", &ParticleSystem::setAutoRemoveOnFinish)
    .function("setGravity", &ParticleSystem::setGravity)
    .function("postStep", &ParticleSystem::postStep)
    .function("setEmissionRate", &ParticleSystem::setEmissionRate)
    .function("getEndColorVar", &ParticleSystem::getEndColorVar)
    .function("getRotationIsDir", &ParticleSystem::getRotationIsDir)
    .function("getEmissionRate", &ParticleSystem::getEmissionRate)
    .function("getEndColor", &ParticleSystem::getEndColor)
    .function("getLifeVar", &ParticleSystem::getLifeVar)
    .function("setStartSizeVar", &ParticleSystem::setStartSizeVar)
    .function("getStartRadius", &ParticleSystem::getStartRadius)
    .function("getParticleCount", &ParticleSystem::getParticleCount)
    .function("getStartRadiusVar", &ParticleSystem::getStartRadiusVar)
    .function("getBlendFunc", &ParticleSystem::getBlendFunc)
    .function("setStartColorVar", &ParticleSystem::setStartColorVar)
    .function("setEndSpin", &ParticleSystem::setEndSpin)
    .function("setRadialAccel", &ParticleSystem::setRadialAccel)
    .function("initWithDictionary", select_overload<bool(std::unordered_map<std::string, cocos2d::Value>&, const std::string&)>(&ParticleSystem::initWithDictionary))
    .function("initWithDictionary", select_overload<bool(std::unordered_map<std::string, cocos2d::Value>&)>(&ParticleSystem::initWithDictionary))
    .function("isAutoRemoveOnFinish", &ParticleSystem::isAutoRemoveOnFinish)
    .function("isSourcePositionCompatible", &ParticleSystem::isSourcePositionCompatible)
    .function("getTotalParticles", &ParticleSystem::getTotalParticles)
    .function("setStartRadiusVar", &ParticleSystem::setStartRadiusVar)
    .function("setBlendFunc", &ParticleSystem::setBlendFunc)
    .function("getEndRadiusVar", &ParticleSystem::getEndRadiusVar)
    .function("getStartColorVar", &ParticleSystem::getStartColorVar)
    .function("ctor", &cc_bindings_ctor<ParticleSystem>, allow_raw_pointers())
    .class_function("create", &ParticleSystem::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleSystem::createWithTotalParticles, allow_raw_pointers())
    .class_function("getAllParticleSystems", &ParticleSystem::getAllParticleSystems, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSystem& _) -> std::string {return "ParticleSystem";}))    
    // TODO: assign cc.Class.extend to cc.ParticleSystem.extend
    ;


  class_<ParticleSystemQuad, base<ParticleSystem>>("cc.ParticleSystem")
    .constructor<>()
    .function("setDisplayFrame", &ParticleSystemQuad::setDisplayFrame, allow_raw_pointers())
    .function("setTextureWithRect", &ParticleSystemQuad::setTextureWithRect, allow_raw_pointers())
    .function("listenRendererRecreated", &ParticleSystemQuad::listenRendererRecreated, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ParticleSystemQuad*(const std::string&)>(&ParticleSystemQuad::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::ParticleSystemQuad*()>(&ParticleSystemQuad::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithTotalParticles", &ParticleSystemQuad::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSystemQuad& _) -> std::string {return "ParticleSystemQuad";}))    
    ;


  class_<ParticleFire, base<ParticleSystemQuad>>("cc.ParticleFire")
    .constructor<>()
    .class_function("create", &ParticleFire::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleFire::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleFire& _) -> std::string {return "ParticleFire";}))    
    ;


  class_<ParticleFireworks, base<ParticleSystemQuad>>("cc.ParticleFireworks")
    .constructor<>()
    .function("init", &ParticleFireworks::init)
    .function("initWithTotalParticles", &ParticleFireworks::initWithTotalParticles)
    .class_function("create", &ParticleFireworks::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleFireworks::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleFireworks& _) -> std::string {return "ParticleFireworks";}))    
    ;


  class_<ParticleSun, base<ParticleSystemQuad>>("cc.ParticleSun")
    .constructor<>()
    .function("init", &ParticleSun::init)
    .function("initWithTotalParticles", &ParticleSun::initWithTotalParticles)
    .class_function("create", &ParticleSun::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleSun::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSun& _) -> std::string {return "ParticleSun";}))    
    ;


  class_<ParticleGalaxy, base<ParticleSystemQuad>>("cc.ParticleGalaxy")
    .constructor<>()
    .function("init", &ParticleGalaxy::init)
    .function("initWithTotalParticles", &ParticleGalaxy::initWithTotalParticles)
    .class_function("create", &ParticleGalaxy::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleGalaxy::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleGalaxy& _) -> std::string {return "ParticleGalaxy";}))    
    ;


  class_<ParticleFlower, base<ParticleSystemQuad>>("cc.ParticleFlower")
    .constructor<>()
    .function("init", &ParticleFlower::init)
    .function("initWithTotalParticles", &ParticleFlower::initWithTotalParticles)
    .class_function("create", &ParticleFlower::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleFlower::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleFlower& _) -> std::string {return "ParticleFlower";}))    
    ;


  class_<ParticleMeteor, base<ParticleSystemQuad>>("cc.ParticleMeteor")
    .constructor<>()
    .function("init", &ParticleMeteor::init)
    .function("initWithTotalParticles", &ParticleMeteor::initWithTotalParticles)
    .class_function("create", &ParticleMeteor::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleMeteor::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleMeteor& _) -> std::string {return "ParticleMeteor";}))    
    ;


  class_<ParticleSpiral, base<ParticleSystemQuad>>("cc.ParticleSpiral")
    .constructor<>()
    .function("init", &ParticleSpiral::init)
    .function("initWithTotalParticles", &ParticleSpiral::initWithTotalParticles)
    .class_function("create", &ParticleSpiral::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleSpiral::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSpiral& _) -> std::string {return "ParticleSpiral";}))    
    ;


  class_<ParticleExplosion, base<ParticleSystemQuad>>("cc.ParticleExplosion")
    .constructor<>()
    .function("init", &ParticleExplosion::init)
    .function("initWithTotalParticles", &ParticleExplosion::initWithTotalParticles)
    .class_function("create", &ParticleExplosion::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleExplosion::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleExplosion& _) -> std::string {return "ParticleExplosion";}))    
    ;


  class_<ParticleSmoke, base<ParticleSystemQuad>>("cc.ParticleSmoke")
    .constructor<>()
    .function("init", &ParticleSmoke::init)
    .function("initWithTotalParticles", &ParticleSmoke::initWithTotalParticles)
    .class_function("create", &ParticleSmoke::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleSmoke::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSmoke& _) -> std::string {return "ParticleSmoke";}))    
    ;


  class_<ParticleSnow, base<ParticleSystemQuad>>("cc.ParticleSnow")
    .constructor<>()
    .function("init", &ParticleSnow::init)
    .function("initWithTotalParticles", &ParticleSnow::initWithTotalParticles)
    .class_function("create", &ParticleSnow::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleSnow::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSnow& _) -> std::string {return "ParticleSnow";}))    
    ;


  class_<ParticleRain, base<ParticleSystemQuad>>("cc.ParticleRain")
    .constructor<>()
    .function("init", &ParticleRain::init)
    .function("initWithTotalParticles", &ParticleRain::initWithTotalParticles)
    .class_function("create", &ParticleRain::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleRain::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleRain& _) -> std::string {return "ParticleRain";}))    
    ;


  class_<ProgressTimer, base<Node>>("cc.ProgressTimer")
    .constructor<>()
    .function("initWithSprite", &ProgressTimer::initWithSprite, allow_raw_pointers())
    .function("isReverseDirection", &ProgressTimer::isReverseDirection)
    .function("setBarChangeRate", &ProgressTimer::setBarChangeRate)
    .function("getPercentage", &ProgressTimer::getPercentage)
    .function("setSprite", &ProgressTimer::setSprite, allow_raw_pointers())
    .function("getType", &ProgressTimer::getType)
    .function("getSprite", &ProgressTimer::getSprite, allow_raw_pointers())
    .function("setMidpoint", &ProgressTimer::setMidpoint)
    .function("getBarChangeRate", &ProgressTimer::getBarChangeRate)
    .function("getMidpoint", &ProgressTimer::getMidpoint)
    .function("setPercentage", &ProgressTimer::setPercentage)
    .function("setType", &ProgressTimer::setType)
    .function("ctor", &cc_bindings_ctor<ProgressTimer>, allow_raw_pointers())
    .class_function("create", &ProgressTimer::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ProgressTimer& _) -> std::string {return "ProgressTimer";}))    
    // TODO: assign cc.Class.extend to cc.ProgressTimer.extend
    ;


  class_<ProtectedNode, base<Node>>("cc.ProtectedNode")
    .constructor<>()
    .function("addProtectedChild", select_overload<void(cocos2d::Node*, int)>(&ProtectedNode::addProtectedChild), allow_raw_pointers())
    .function("addProtectedChild", select_overload<void(cocos2d::Node*)>(&ProtectedNode::addProtectedChild), allow_raw_pointers())
    .function("addProtectedChild", select_overload<void(cocos2d::Node*, int, int)>(&ProtectedNode::addProtectedChild), allow_raw_pointers())
    .function("disableCascadeColor", &ProtectedNode::disableCascadeColor)
    .function("removeProtectedChildByTag", &ProtectedNode::removeProtectedChildByTag)
    .function("removeProtectedChildByTag", optional_override(
        [](ProtectedNode& this_, int arg0){
        return this_.removeProtectedChildByTag(arg0);
      }))
    .function("reorderProtectedChild", &ProtectedNode::reorderProtectedChild, allow_raw_pointers())
    .function("removeAllProtectedChildrenWithCleanup", &ProtectedNode::removeAllProtectedChildrenWithCleanup)
    .function("disableCascadeOpacity", &ProtectedNode::disableCascadeOpacity)
    .function("sortAllProtectedChildren", &ProtectedNode::sortAllProtectedChildren)
    .function("getProtectedChildByTag", &ProtectedNode::getProtectedChildByTag, allow_raw_pointers())
    .function("removeProtectedChild", &ProtectedNode::removeProtectedChild, allow_raw_pointers())
    .function("removeProtectedChild", optional_override(
        [](ProtectedNode& this_, cocos2d::Node* arg0){
        return this_.removeProtectedChild(arg0);
      }), allow_raw_pointers())
    .function("removeAllProtectedChildren", &ProtectedNode::removeAllProtectedChildren)
    .class_function("create", &ProtectedNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ProtectedNode& _) -> std::string {return "ProtectedNode";}))    
    ;


  class_<Sprite, base<Node>>("cc.Sprite")
    .constructor<>()
    .function("setSpriteFrame", select_overload<void(cocos2d::SpriteFrame*)>(&Sprite::setSpriteFrame), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setTexture", select_overload<void(cocos2d::Texture2D*)>(&Sprite::setTexture), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getTexture", &Sprite::getTexture, allow_raw_pointers())
    .function("setFlippedY", &Sprite::setFlippedY)
    .function("setFlippedX", &Sprite::setFlippedX)
    .function("setRotationSkewX", &Sprite::setRotationSkewX)
    .function("setRotationSkewY", &Sprite::setRotationSkewY)
    .function("getResourceType", &Sprite::getResourceType)
    .function("setDisplayFrameWithAnimationName", &Sprite::setDisplayFrameWithAnimationName)
    .function("getBatchNode", &Sprite::getBatchNode, allow_raw_pointers())
    .function("getOffsetPosition", &Sprite::getOffsetPosition)
    .function("getCenterRect", &Sprite::getCenterRect)
    .function("removeAllChildrenWithCleanup", &Sprite::removeAllChildrenWithCleanup)
    .function("setCenterRectNormalized", &Sprite::setCenterRectNormalized)
    .function("isStretchEnabled", &Sprite::isStretchEnabled)
    .function("setTextureRect", select_overload<void(const cocos2d::Rect&, bool, const cocos2d::Size&)>(&Sprite::setTextureRect))
    .function("setTextureRect", select_overload<void(const cocos2d::Rect&)>(&Sprite::setTextureRect))
    .function("initWithSpriteFrameName", &Sprite::initWithSpriteFrameName)
    .function("setStretchEnabled", &Sprite::setStretchEnabled)
    .function("isFrameDisplayed", &Sprite::isFrameDisplayed, allow_raw_pointers())
    .function("getAtlasIndex", &Sprite::getAtlasIndex)
    .function("setBatchNode", &Sprite::setBatchNode, allow_raw_pointers())
    .function("getBlendFunc", &Sprite::getBlendFunc)
    .function("setCenterRect", &Sprite::setCenterRect)
    .function("setTextureAtlas", &Sprite::setTextureAtlas, allow_raw_pointers())
    .function("getSpriteFrame", &Sprite::getSpriteFrame, allow_raw_pointers())
    .function("getResourceName", &Sprite::getResourceName)
    .function("isDirty", &Sprite::isDirty)
    .function("getCenterRectNormalized", &Sprite::getCenterRectNormalized)
    .function("setAtlasIndex", &Sprite::setAtlasIndex)
    .function("initWithTexture", select_overload<bool(cocos2d::Texture2D*, const cocos2d::Rect&)>(&Sprite::initWithTexture), allow_raw_pointers())
    .function("initWithTexture", select_overload<bool(cocos2d::Texture2D*)>(&Sprite::initWithTexture), allow_raw_pointers())
    .function("initWithTexture", select_overload<bool(cocos2d::Texture2D*, const cocos2d::Rect&, bool)>(&Sprite::initWithTexture), allow_raw_pointers())
    .function("setDirty", &Sprite::setDirty)
    .function("isTextureRectRotated", &Sprite::isTextureRectRotated)
    .function("getTextureRect", &Sprite::getTextureRect)
    .function("initWithFile", select_overload<bool(const std::string&, const cocos2d::Rect&)>(&Sprite::initWithFile))
    .function("initWithFile", select_overload<bool(const std::string&)>(&Sprite::initWithFile))
    .function("setBlendFunc", &Sprite::setBlendFunc)
    .function("getTextureAtlas", &Sprite::getTextureAtlas, allow_raw_pointers())
    .function("initWithSpriteFrame", &Sprite::initWithSpriteFrame, allow_raw_pointers())
    .function("isFlippedX", &Sprite::isFlippedX)
    .function("isFlippedY", &Sprite::isFlippedY)
    .function("setVertexRect", &Sprite::setVertexRect)
    .function("ctor", &cc_bindings_ctor<Sprite>, allow_raw_pointers())
    .property("_className",  optional_override([](const Sprite& _) -> std::string {return "Sprite";}))    
    // TODO: assign cc.Class.extend to cc.Sprite.extend
    ;


  class_<RenderTexture, base<Node>>("cc.RenderTexture")
    .constructor<>()
    .function("setVirtualViewport", &RenderTexture::setVirtualViewport)
    .function("clearStencil", &RenderTexture::clearStencil)
    .function("getClearDepth", &RenderTexture::getClearDepth)
    .function("getClearStencil", &RenderTexture::getClearStencil)
    .function("end", &RenderTexture::end)
    .function("setClearStencil", &RenderTexture::setClearStencil)
    .function("setSprite", &RenderTexture::setSprite, allow_raw_pointers())
    .function("getSprite", &RenderTexture::getSprite, allow_raw_pointers())
    .function("isAutoDraw", &RenderTexture::isAutoDraw)
    .function("setKeepMatrix", &RenderTexture::setKeepMatrix)
    .function("setClearFlags", &RenderTexture::setClearFlags)
    .function("begin", &RenderTexture::begin)
    .function("setAutoDraw", &RenderTexture::setAutoDraw)
    .function("setClearColor", &RenderTexture::setClearColor)
    .function("beginWithClear", select_overload<void(float, float, float, float, float)>(&RenderTexture::beginWithClear))
    .function("beginWithClear", select_overload<void(float, float, float, float)>(&RenderTexture::beginWithClear))
    .function("beginWithClear", select_overload<void(float, float, float, float, float, int)>(&RenderTexture::beginWithClear))
    .function("clearDepth", &RenderTexture::clearDepth)
    .function("getClearColor", &RenderTexture::getClearColor)
    .function("clear", &RenderTexture::clear)
    .function("getClearFlags", &RenderTexture::getClearFlags)
    .function("newImage", &RenderTexture::newImage, allow_raw_pointers())
    .function("newImage", optional_override(
        [](RenderTexture& this_){
        return this_.newImage();
      }), allow_raw_pointers())
    .function("setClearDepth", &RenderTexture::setClearDepth)
    .function("initWithWidthAndHeight", select_overload<bool(int, int, cocos2d::Texture2D::PixelFormat, unsigned int)>(&RenderTexture::initWithWidthAndHeight))
    .function("initWithWidthAndHeight", select_overload<bool(int, int, cocos2d::Texture2D::PixelFormat)>(&RenderTexture::initWithWidthAndHeight))
    .function("ctor", &cc_bindings_ctor<RenderTexture>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::RenderTexture*(int, int, cocos2d::Texture2D::PixelFormat)>(&RenderTexture::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::RenderTexture*(int, int, cocos2d::Texture2D::PixelFormat, unsigned int)>(&RenderTexture::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::RenderTexture*(int, int)>(&RenderTexture::create), allow_raw_pointers())
    .property("_className",  optional_override([](const RenderTexture& _) -> std::string {return "RenderTexture";}))    
    // TODO: assign cc.Class.extend to cc.RenderTexture.extend
    ;

  class_<TransitionEaseScene>("cc.TransitionEaseScene")
    .function("easeActionWithAction", &TransitionEaseScene::easeActionWithAction, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionEaseScene& _) -> std::string {return "TransitionEaseScene";}))    
    ;


  class_<TransitionScene, base<Scene>>("cc.TransitionScene")
    .constructor<>()
    .function("getInScene", &TransitionScene::getInScene, allow_raw_pointers())
    .function("finish", &TransitionScene::finish)
    .function("initWithDuration", &TransitionScene::initWithDuration, allow_raw_pointers())
    .function("getDuration", &TransitionScene::getDuration)
    .function("hideOutShowIn", &TransitionScene::hideOutShowIn)
    .function("ctor", &cc_bindings_ctor<TransitionScene>, allow_raw_pointers())
    .class_function("create", &TransitionScene::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionScene& _) -> std::string {return "TransitionScene";}))    
    // TODO: assign cc.Class.extend to cc.TransitionScene.extend
    ;


  class_<TransitionSceneOriented, base<TransitionScene>>("cc.TransitionSceneOriented")
    .constructor<>()
    .function("initWithDuration", &TransitionSceneOriented::initWithDuration, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionSceneOriented>, allow_raw_pointers())
    .class_function("create", &TransitionSceneOriented::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSceneOriented& _) -> std::string {return "TransitionSceneOriented";}))    
    // TODO: assign cc.Class.extend to cc.TransitionSceneOriented.extend
    ;


  class_<TransitionRotoZoom, base<TransitionScene>>("cc.TransitionRotoZoom")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionRotoZoom>, allow_raw_pointers())
    .class_function("create", &TransitionRotoZoom::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionRotoZoom& _) -> std::string {return "TransitionRotoZoom";}))    
    // TODO: assign cc.Class.extend to cc.TransitionRotoZoom.extend
    ;


  class_<TransitionJumpZoom, base<TransitionScene>>("cc.TransitionJumpZoom")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionJumpZoom>, allow_raw_pointers())
    .class_function("create", &TransitionJumpZoom::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionJumpZoom& _) -> std::string {return "TransitionJumpZoom";}))    
    // TODO: assign cc.Class.extend to cc.TransitionJumpZoom.extend
    ;


  class_<TransitionMoveInL, base<TransitionScene>>("cc.TransitionMoveInL")
    .constructor<>()
    .function("action", &TransitionMoveInL::action, allow_raw_pointers())
    .function("easeActionWithAction", &TransitionMoveInL::easeActionWithAction, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionMoveInL>, allow_raw_pointers())
    .class_function("create", &TransitionMoveInL::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionMoveInL& _) -> std::string {return "TransitionMoveInL";}))    
    // TODO: assign cc.Class.extend to cc.TransitionMoveInL.extend
    ;


  class_<TransitionMoveInR, base<TransitionMoveInL>>("cc.TransitionMoveInR")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionMoveInR>, allow_raw_pointers())
    .class_function("create", &TransitionMoveInR::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionMoveInR& _) -> std::string {return "TransitionMoveInR";}))    
    // TODO: assign cc.Class.extend to cc.TransitionMoveInR.extend
    ;


  class_<TransitionMoveInT, base<TransitionMoveInL>>("cc.TransitionMoveInT")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionMoveInT>, allow_raw_pointers())
    .class_function("create", &TransitionMoveInT::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionMoveInT& _) -> std::string {return "TransitionMoveInT";}))    
    // TODO: assign cc.Class.extend to cc.TransitionMoveInT.extend
    ;


  class_<TransitionMoveInB, base<TransitionMoveInL>>("cc.TransitionMoveInB")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionMoveInB>, allow_raw_pointers())
    .class_function("create", &TransitionMoveInB::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionMoveInB& _) -> std::string {return "TransitionMoveInB";}))    
    // TODO: assign cc.Class.extend to cc.TransitionMoveInB.extend
    ;


  class_<TransitionSlideInL, base<TransitionScene>>("cc.TransitionSlideInL")
    .constructor<>()
    .function("action", &TransitionSlideInL::action, allow_raw_pointers())
    .function("easeActionWithAction", &TransitionSlideInL::easeActionWithAction, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionSlideInL>, allow_raw_pointers())
    .class_function("create", &TransitionSlideInL::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSlideInL& _) -> std::string {return "TransitionSlideInL";}))    
    // TODO: assign cc.Class.extend to cc.TransitionSlideInL.extend
    ;


  class_<TransitionSlideInR, base<TransitionSlideInL>>("cc.TransitionSlideInR")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionSlideInR>, allow_raw_pointers())
    .class_function("create", &TransitionSlideInR::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSlideInR& _) -> std::string {return "TransitionSlideInR";}))    
    // TODO: assign cc.Class.extend to cc.TransitionSlideInR.extend
    ;


  class_<TransitionSlideInB, base<TransitionSlideInL>>("cc.TransitionSlideInB")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionSlideInB>, allow_raw_pointers())
    .class_function("create", &TransitionSlideInB::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSlideInB& _) -> std::string {return "TransitionSlideInB";}))    
    // TODO: assign cc.Class.extend to cc.TransitionSlideInB.extend
    ;


  class_<TransitionSlideInT, base<TransitionSlideInL>>("cc.TransitionSlideInT")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionSlideInT>, allow_raw_pointers())
    .class_function("create", &TransitionSlideInT::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSlideInT& _) -> std::string {return "TransitionSlideInT";}))    
    // TODO: assign cc.Class.extend to cc.TransitionSlideInT.extend
    ;


  class_<TransitionShrinkGrow, base<TransitionScene>>("cc.TransitionShrinkGrow")
    .constructor<>()
    .function("easeActionWithAction", &TransitionShrinkGrow::easeActionWithAction, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionShrinkGrow>, allow_raw_pointers())
    .class_function("create", &TransitionShrinkGrow::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionShrinkGrow& _) -> std::string {return "TransitionShrinkGrow";}))    
    // TODO: assign cc.Class.extend to cc.TransitionShrinkGrow.extend
    ;


  class_<TransitionFlipX, base<TransitionSceneOriented>>("cc.TransitionFlipX")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionFlipX>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFlipX*(float, cocos2d::Scene*)>(&TransitionFlipX::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFlipX*(float, cocos2d::Scene*, cocos2d::TransitionScene::Orientation)>(&TransitionFlipX::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFlipX& _) -> std::string {return "TransitionFlipX";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFlipX.extend
    ;


  class_<TransitionFlipY, base<TransitionSceneOriented>>("cc.TransitionFlipY")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionFlipY>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFlipY*(float, cocos2d::Scene*)>(&TransitionFlipY::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFlipY*(float, cocos2d::Scene*, cocos2d::TransitionScene::Orientation)>(&TransitionFlipY::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFlipY& _) -> std::string {return "TransitionFlipY";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFlipY.extend
    ;


  class_<TransitionFlipAngular, base<TransitionSceneOriented>>("cc.TransitionFlipAngular")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionFlipAngular>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFlipAngular*(float, cocos2d::Scene*)>(&TransitionFlipAngular::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFlipAngular*(float, cocos2d::Scene*, cocos2d::TransitionScene::Orientation)>(&TransitionFlipAngular::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFlipAngular& _) -> std::string {return "TransitionFlipAngular";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFlipAngular.extend
    ;


  class_<TransitionZoomFlipX, base<TransitionSceneOriented>>("cc.TransitionZoomFlipX")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionZoomFlipX>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionZoomFlipX*(float, cocos2d::Scene*)>(&TransitionZoomFlipX::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionZoomFlipX*(float, cocos2d::Scene*, cocos2d::TransitionScene::Orientation)>(&TransitionZoomFlipX::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionZoomFlipX& _) -> std::string {return "TransitionZoomFlipX";}))    
    // TODO: assign cc.Class.extend to cc.TransitionZoomFlipX.extend
    ;


  class_<TransitionZoomFlipY, base<TransitionSceneOriented>>("cc.TransitionZoomFlipY")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionZoomFlipY>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionZoomFlipY*(float, cocos2d::Scene*)>(&TransitionZoomFlipY::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionZoomFlipY*(float, cocos2d::Scene*, cocos2d::TransitionScene::Orientation)>(&TransitionZoomFlipY::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionZoomFlipY& _) -> std::string {return "TransitionZoomFlipY";}))    
    // TODO: assign cc.Class.extend to cc.TransitionZoomFlipY.extend
    ;


  class_<TransitionZoomFlipAngular, base<TransitionSceneOriented>>("cc.TransitionZoomFlipAngular")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionZoomFlipAngular>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionZoomFlipAngular*(float, cocos2d::Scene*)>(&TransitionZoomFlipAngular::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionZoomFlipAngular*(float, cocos2d::Scene*, cocos2d::TransitionScene::Orientation)>(&TransitionZoomFlipAngular::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionZoomFlipAngular& _) -> std::string {return "TransitionZoomFlipAngular";}))    
    // TODO: assign cc.Class.extend to cc.TransitionZoomFlipAngular.extend
    ;


  class_<TransitionFade, base<TransitionScene>>("cc.TransitionFade")
    .constructor<>()
    .function("initWithDuration", select_overload<bool(float, cocos2d::Scene*)>(&TransitionFade::initWithDuration), allow_raw_pointers())
    .function("initWithDuration", select_overload<bool(float, cocos2d::Scene*, const cocos2d::Color3B&)>(&TransitionFade::initWithDuration), allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionFade>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFade*(float, cocos2d::Scene*)>(&TransitionFade::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TransitionFade*(float, cocos2d::Scene*, const cocos2d::Color3B&)>(&TransitionFade::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFade& _) -> std::string {return "TransitionFade";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFade.extend
    ;


  class_<TransitionCrossFade, base<TransitionScene>>("cc.TransitionCrossFade")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionCrossFade>, allow_raw_pointers())
    .class_function("create", &TransitionCrossFade::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionCrossFade& _) -> std::string {return "TransitionCrossFade";}))    
    // TODO: assign cc.Class.extend to cc.TransitionCrossFade.extend
    ;


  class_<TransitionTurnOffTiles, base<TransitionScene>>("cc.TransitionTurnOffTiles")
    .constructor<>()
    .function("easeActionWithAction", &TransitionTurnOffTiles::easeActionWithAction, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionTurnOffTiles>, allow_raw_pointers())
    .class_function("create", &TransitionTurnOffTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionTurnOffTiles& _) -> std::string {return "TransitionTurnOffTiles";}))    
    // TODO: assign cc.Class.extend to cc.TransitionTurnOffTiles.extend
    ;


  class_<TransitionSplitCols, base<TransitionScene>>("cc.TransitionSplitCols")
    .constructor<>()
    .function("action", &TransitionSplitCols::action, allow_raw_pointers())
    .function("easeActionWithAction", &TransitionSplitCols::easeActionWithAction, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionSplitCols>, allow_raw_pointers())
    .class_function("create", &TransitionSplitCols::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSplitCols& _) -> std::string {return "TransitionSplitCols";}))    
    // TODO: assign cc.Class.extend to cc.TransitionSplitCols.extend
    ;


  class_<TransitionSplitRows, base<TransitionSplitCols>>("cc.TransitionSplitRows")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionSplitRows>, allow_raw_pointers())
    .class_function("create", &TransitionSplitRows::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSplitRows& _) -> std::string {return "TransitionSplitRows";}))    
    // TODO: assign cc.Class.extend to cc.TransitionSplitRows.extend
    ;


  class_<TransitionFadeTR, base<TransitionScene>>("cc.TransitionFadeTR")
    .constructor<>()
    .function("easeActionWithAction", &TransitionFadeTR::easeActionWithAction, allow_raw_pointers())
    .function("actionWithSize", &TransitionFadeTR::actionWithSize, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionFadeTR>, allow_raw_pointers())
    .class_function("create", &TransitionFadeTR::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFadeTR& _) -> std::string {return "TransitionFadeTR";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFadeTR.extend
    ;


  class_<TransitionFadeBL, base<TransitionFadeTR>>("cc.TransitionFadeBL")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionFadeBL>, allow_raw_pointers())
    .class_function("create", &TransitionFadeBL::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFadeBL& _) -> std::string {return "TransitionFadeBL";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFadeBL.extend
    ;


  class_<TransitionFadeUp, base<TransitionFadeTR>>("cc.TransitionFadeUp")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionFadeUp>, allow_raw_pointers())
    .class_function("create", &TransitionFadeUp::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFadeUp& _) -> std::string {return "TransitionFadeUp";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFadeUp.extend
    ;


  class_<TransitionFadeDown, base<TransitionFadeTR>>("cc.TransitionFadeDown")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionFadeDown>, allow_raw_pointers())
    .class_function("create", &TransitionFadeDown::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFadeDown& _) -> std::string {return "TransitionFadeDown";}))    
    // TODO: assign cc.Class.extend to cc.TransitionFadeDown.extend
    ;


  class_<TransitionPageTurn, base<TransitionScene>>("cc.TransitionPageTurn")
    .constructor<>()
    .function("actionWithSize", &TransitionPageTurn::actionWithSize, allow_raw_pointers())
    .function("initWithDuration", &TransitionPageTurn::initWithDuration, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TransitionPageTurn>, allow_raw_pointers())
    .class_function("create", &TransitionPageTurn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionPageTurn& _) -> std::string {return "TransitionPageTurn";}))    
    // TODO: assign cc.Class.extend to cc.TransitionPageTurn.extend
    ;


  class_<TransitionProgress, base<TransitionScene>>("cc.TransitionProgress")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionProgress>, allow_raw_pointers())
    .class_function("create", &TransitionProgress::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgress& _) -> std::string {return "TransitionProgress";}))    
    // TODO: assign cc.Class.extend to cc.TransitionProgress.extend
    ;


  class_<TransitionProgressRadialCCW, base<TransitionProgress>>("cc.TransitionProgressRadialCCW")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionProgressRadialCCW>, allow_raw_pointers())
    .class_function("create", &TransitionProgressRadialCCW::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressRadialCCW& _) -> std::string {return "TransitionProgressRadialCCW";}))    
    // TODO: assign cc.Class.extend to cc.TransitionProgressRadialCCW.extend
    ;


  class_<TransitionProgressRadialCW, base<TransitionProgress>>("cc.TransitionProgressRadialCW")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionProgressRadialCW>, allow_raw_pointers())
    .class_function("create", &TransitionProgressRadialCW::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressRadialCW& _) -> std::string {return "TransitionProgressRadialCW";}))    
    // TODO: assign cc.Class.extend to cc.TransitionProgressRadialCW.extend
    ;


  class_<TransitionProgressHorizontal, base<TransitionProgress>>("cc.TransitionProgressHorizontal")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionProgressHorizontal>, allow_raw_pointers())
    .class_function("create", &TransitionProgressHorizontal::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressHorizontal& _) -> std::string {return "TransitionProgressHorizontal";}))    
    // TODO: assign cc.Class.extend to cc.TransitionProgressHorizontal.extend
    ;


  class_<TransitionProgressVertical, base<TransitionProgress>>("cc.TransitionProgressVertical")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionProgressVertical>, allow_raw_pointers())
    .class_function("create", &TransitionProgressVertical::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressVertical& _) -> std::string {return "TransitionProgressVertical";}))    
    // TODO: assign cc.Class.extend to cc.TransitionProgressVertical.extend
    ;


  class_<TransitionProgressInOut, base<TransitionProgress>>("cc.TransitionProgressInOut")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionProgressInOut>, allow_raw_pointers())
    .class_function("create", &TransitionProgressInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressInOut& _) -> std::string {return "TransitionProgressInOut";}))    
    // TODO: assign cc.Class.extend to cc.TransitionProgressInOut.extend
    ;


  class_<TransitionProgressOutIn, base<TransitionProgress>>("cc.TransitionProgressOutIn")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TransitionProgressOutIn>, allow_raw_pointers())
    .class_function("create", &TransitionProgressOutIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressOutIn& _) -> std::string {return "TransitionProgressOutIn";}))    
    // TODO: assign cc.Class.extend to cc.TransitionProgressOutIn.extend
    ;


  class_<Camera, base<Node>>("cc.Camera")
    .constructor<>()
    .function("restore", &Camera::restore)
    .function("getDepth", &Camera::getDepth)
    .function("getViewProjectionMatrix", &Camera::getViewProjectionMatrix)
    .function("applyViewport", &Camera::applyViewport)
    .function("setBackgroundBrush", &Camera::setBackgroundBrush, allow_raw_pointers())
    .function("lookAt", &Camera::lookAt)
    .function("lookAt", optional_override(
        [](Camera& this_, const cocos2d::Vec3& arg0){
        return this_.lookAt(arg0);
      }))
    .function("apply", &Camera::apply)
    .function("getBackgroundBrush", &Camera::getBackgroundBrush, allow_raw_pointers())
    .function("getProjectionMatrix", &Camera::getProjectionMatrix)
    .function("isBrushValid", &Camera::isBrushValid)
    .function("getDepthInView", &Camera::getDepthInView)
    .function("restoreViewport", &Camera::restoreViewport)
    .function("clearBackground", &Camera::clearBackground)
    .function("setAdditionalProjection", &Camera::setAdditionalProjection)
    .function("setViewport", &Camera::setViewport)
    .function("initDefault", &Camera::initDefault)
    .function("getCameraFlag", &Camera::getCameraFlag)
    .function("getType", &Camera::getType)
    .function("initOrthographic", &Camera::initOrthographic)
    .function("getRenderOrder", &Camera::getRenderOrder)
    .function("setDepth", &Camera::setDepth)
    .function("setScene", &Camera::setScene, allow_raw_pointers())
    .function("projectGL", &Camera::projectGL)
    .function("restoreFrameBufferObject", &Camera::restoreFrameBufferObject)
    .function("getViewMatrix", &Camera::getViewMatrix)
    .function("getNearPlane", &Camera::getNearPlane)
    .function("project", &Camera::project)
    .function("setCameraFlag", &Camera::setCameraFlag)
    .function("getFarPlane", &Camera::getFarPlane)
    .function("applyFrameBufferObject", &Camera::applyFrameBufferObject)
    .function("setFrameBufferObject", &Camera::setFrameBufferObject, allow_raw_pointers())
    .function("isViewProjectionUpdated", &Camera::isViewProjectionUpdated)
    .function("initPerspective", &Camera::initPerspective)
    .class_function("createOrthographic", &Camera::createOrthographic, allow_raw_pointers())
    .class_function("getVisitingCamera", &Camera::getVisitingCamera, allow_raw_pointers())
    .class_function("create", &Camera::create, allow_raw_pointers())
    .class_function("createPerspective", &Camera::createPerspective, allow_raw_pointers())
    .class_function("getDefaultViewport", &Camera::getDefaultViewport, allow_raw_pointers())
    .class_function("setDefaultViewport", &Camera::setDefaultViewport, allow_raw_pointers())
    .class_function("getDefaultCamera", &Camera::getDefaultCamera, allow_raw_pointers())
    .property("_className",  optional_override([](const Camera& _) -> std::string {return "Camera";}))    
    ;


  class_<CameraBackgroundBrush>("cc.CameraBackgroundBrush")
    .constructor<>()
    .function("getBrushType", &CameraBackgroundBrush::getBrushType)
    .function("drawBackground", &CameraBackgroundBrush::drawBackground, allow_raw_pointers())
    .function("init", &CameraBackgroundBrush::init)
    .function("isValid", &CameraBackgroundBrush::isValid)
    .class_function("createSkyboxBrush", &CameraBackgroundBrush::createSkyboxBrush, allow_raw_pointers())
    .class_function("createColorBrush", &CameraBackgroundBrush::createColorBrush, allow_raw_pointers())
    .class_function("createNoneBrush", &CameraBackgroundBrush::createNoneBrush, allow_raw_pointers())
    .class_function("createDepthBrush", &CameraBackgroundBrush::createDepthBrush, allow_raw_pointers())
    .class_function("createDepthBrush", optional_override(
      [](){
        return CameraBackgroundBrush::createDepthBrush();
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const CameraBackgroundBrush& _) -> std::string {return "CameraBackgroundBrush";}))    
    ;


  class_<CameraBackgroundDepthBrush, base<CameraBackgroundBrush>>("cc.CameraBackgroundDepthBrush")
    .constructor<>()
    .function("setDepth", &CameraBackgroundDepthBrush::setDepth)
    .class_function("create", &CameraBackgroundDepthBrush::create, allow_raw_pointers())
    .property("_className",  optional_override([](const CameraBackgroundDepthBrush& _) -> std::string {return "CameraBackgroundDepthBrush";}))    
    ;


  class_<CameraBackgroundColorBrush, base<CameraBackgroundDepthBrush>>("cc.CameraBackgroundColorBrush")
    .constructor<>()
    .function("setColor", &CameraBackgroundColorBrush::setColor)
    .class_function("create", &CameraBackgroundColorBrush::create, allow_raw_pointers())
    .property("_className",  optional_override([](const CameraBackgroundColorBrush& _) -> std::string {return "CameraBackgroundColorBrush";}))    
    ;


  class_<CameraBackgroundSkyBoxBrush, base<CameraBackgroundBrush>>("cc.CameraBackgroundSkyBoxBrush")
    .constructor<>()
    .function("setTextureValid", &CameraBackgroundSkyBoxBrush::setTextureValid)
    .function("setTexture", &CameraBackgroundSkyBoxBrush::setTexture, allow_raw_pointers())
    .function("setActived", &CameraBackgroundSkyBoxBrush::setActived)
    .function("isActived", &CameraBackgroundSkyBoxBrush::isActived)
    .class_function("create", select_overload<cocos2d::CameraBackgroundSkyBoxBrush*()>(&CameraBackgroundSkyBoxBrush::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::CameraBackgroundSkyBoxBrush*(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&)>(&CameraBackgroundSkyBoxBrush::create), allow_raw_pointers())
    .property("_className",  optional_override([](const CameraBackgroundSkyBoxBrush& _) -> std::string {return "CameraBackgroundSkyBoxBrush";}))    
    ;

  class_<GridBase>("cc.GridBase")
    .function("setGridSize", &GridBase::setGridSize)
    .function("setGridRect", &GridBase::setGridRect)
    .function("afterBlit", &GridBase::afterBlit)
    .function("getGridRect", &GridBase::getGridRect)
    .function("afterDraw", &GridBase::afterDraw, allow_raw_pointers())
    .function("beforeDraw", &GridBase::beforeDraw)
    .function("calculateVertexPoints", &GridBase::calculateVertexPoints)
    .function("isTextureFlipped", &GridBase::isTextureFlipped)
    .function("getGridSize", &GridBase::getGridSize)
    .function("getStep", &GridBase::getStep)
    .function("set2DProjection", &GridBase::set2DProjection)
    .function("setStep", &GridBase::setStep)
    .function("setTextureFlipped", &GridBase::setTextureFlipped)
    .function("blit", &GridBase::blit)
    .function("setActive", &GridBase::setActive)
    .function("getReuseGrid", &GridBase::getReuseGrid)
    .function("initWithSize", select_overload<bool(const cocos2d::Size&, const cocos2d::Rect&)>(&GridBase::initWithSize))
    .function("initWithSize", select_overload<bool(const cocos2d::Size&)>(&GridBase::initWithSize))
    .function("initWithSize", select_overload<bool(const cocos2d::Size&, cocos2d::Texture2D*, bool)>(&GridBase::initWithSize), allow_raw_pointers())
    .function("initWithSize", select_overload<bool(const cocos2d::Size&, cocos2d::Texture2D*, bool, const cocos2d::Rect&)>(&GridBase::initWithSize), allow_raw_pointers())
    .function("beforeBlit", &GridBase::beforeBlit)
    .function("setReuseGrid", &GridBase::setReuseGrid)
    .function("isActive", &GridBase::isActive)
    .function("reuse", &GridBase::reuse)
    .class_function("create", select_overload<cocos2d::GridBase*(const cocos2d::Size&)>(&GridBase::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::GridBase*(const cocos2d::Size&, cocos2d::Texture2D*, bool)>(&GridBase::create), allow_raw_pointers())
    .property("_className",  optional_override([](const GridBase& _) -> std::string {return "GridBase";}))    
    // TODO: assign cc.Class.extend to cc.GridBase.extend
    ;


  class_<Grid3D, base<GridBase>>("cc.Grid3D")
    .constructor<>()
    .function("getNeedDepthTestForBlit", &Grid3D::getNeedDepthTestForBlit)
    .function("setNeedDepthTestForBlit", &Grid3D::setNeedDepthTestForBlit)
    .function("ctor", &cc_bindings_ctor<Grid3D>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Grid3D*(const cocos2d::Size&, const cocos2d::Rect&)>(&Grid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Grid3D*(const cocos2d::Size&)>(&Grid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Grid3D*(const cocos2d::Size&, cocos2d::Texture2D*, bool)>(&Grid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Grid3D*(const cocos2d::Size&, cocos2d::Texture2D*, bool, const cocos2d::Rect&)>(&Grid3D::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Grid3D& _) -> std::string {return "Grid3D";}))    
    // TODO: assign cc.Class.extend to cc.Grid3D.extend
    ;


  class_<TiledGrid3D, base<GridBase>>("cc.TiledGrid3D")
    .constructor<>()
    .function("ctor", &cc_bindings_ctor<TiledGrid3D>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TiledGrid3D*(const cocos2d::Size&, const cocos2d::Rect&)>(&TiledGrid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TiledGrid3D*(const cocos2d::Size&)>(&TiledGrid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TiledGrid3D*(const cocos2d::Size&, cocos2d::Texture2D*, bool)>(&TiledGrid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TiledGrid3D*(const cocos2d::Size&, cocos2d::Texture2D*, bool, const cocos2d::Rect&)>(&TiledGrid3D::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TiledGrid3D& _) -> std::string {return "TiledGrid3D";}))    
    // TODO: assign cc.Class.extend to cc.TiledGrid3D.extend
    ;

  class_<BaseLight, base<Node>>("cc.BaseLight")
    .function("setEnabled", &BaseLight::setEnabled)
    .function("getIntensity", &BaseLight::getIntensity)
    .function("isEnabled", &BaseLight::isEnabled)
    .function("getLightType", &BaseLight::getLightType)
    .function("setLightFlag", &BaseLight::setLightFlag)
    .function("setIntensity", &BaseLight::setIntensity)
    .function("getLightFlag", &BaseLight::getLightFlag)
    .property("_className",  optional_override([](const BaseLight& _) -> std::string {return "BaseLight";}))    
    ;


  class_<DirectionLight, base<BaseLight>>("cc.DirectionLight")
    .constructor<>()
    .function("getDirection", &DirectionLight::getDirection)
    .function("getDirectionInWorld", &DirectionLight::getDirectionInWorld)
    .function("setDirection", &DirectionLight::setDirection)
    .class_function("create", &DirectionLight::create, allow_raw_pointers())
    .property("_className",  optional_override([](const DirectionLight& _) -> std::string {return "DirectionLight";}))    
    ;


  class_<PointLight, base<BaseLight>>("cc.PointLight")
    .constructor<>()
    .function("getRange", &PointLight::getRange)
    .function("setRange", &PointLight::setRange)
    .class_function("create", &PointLight::create, allow_raw_pointers())
    .property("_className",  optional_override([](const PointLight& _) -> std::string {return "PointLight";}))    
    ;


  class_<SpotLight, base<BaseLight>>("cc.SpotLight")
    .constructor<>()
    .function("getRange", &SpotLight::getRange)
    .function("setDirection", &SpotLight::setDirection)
    .function("getCosInnerAngle", &SpotLight::getCosInnerAngle)
    .function("getOuterAngle", &SpotLight::getOuterAngle)
    .function("getInnerAngle", &SpotLight::getInnerAngle)
    .function("getDirection", &SpotLight::getDirection)
    .function("getCosOuterAngle", &SpotLight::getCosOuterAngle)
    .function("setOuterAngle", &SpotLight::setOuterAngle)
    .function("setInnerAngle", &SpotLight::setInnerAngle)
    .function("getDirectionInWorld", &SpotLight::getDirectionInWorld)
    .function("setRange", &SpotLight::setRange)
    .class_function("create", &SpotLight::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SpotLight& _) -> std::string {return "SpotLight";}))    
    ;


  class_<AmbientLight, base<BaseLight>>("cc.AmbientLight")
    .constructor<>()
    .class_function("create", &AmbientLight::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AmbientLight& _) -> std::string {return "AmbientLight";}))    
    ;


  class_<GLProgram>("cc.GLProgram")
    .constructor<>()
    .function("getFragmentShaderLog", &GLProgram::getFragmentShaderLog)
    .function("getUniformFlags", &GLProgram::getUniformFlags)
    .function("getUniformLocationForName", &GLProgram::getUniformLocationForName, allow_raw_pointers())
    .function("use", &GLProgram::use)
    .function("getVertexShaderLog", &GLProgram::getVertexShaderLog)
    .function("getUniform", &GLProgram::getUniform, allow_raw_pointers())
    .function("initWithString", select_overload<bool(const char*, const char*, const std::string&)>(&GLProgram::initWithByteArrays), allow_raw_pointers())
    .function("initWithString", select_overload<bool(const char*, const char*)>(&GLProgram::initWithByteArrays), allow_raw_pointers())
    .function("initWithString", select_overload<bool(const char*, const char*, const std::string&, const std::string&)>(&GLProgram::initWithByteArrays), allow_raw_pointers())
    .function("setUniformLocationWith1f", &GLProgram::setUniformLocationWith1f)
    .function("init", select_overload<bool(const std::string&, const std::string&, const std::string&)>(&GLProgram::initWithFilenames))
    .function("init", select_overload<bool(const std::string&, const std::string&)>(&GLProgram::initWithFilenames))
    .function("init", select_overload<bool(const std::string&, const std::string&, const std::string&, const std::string&)>(&GLProgram::initWithFilenames))
    .function("setUniformLocationWith3f", &GLProgram::setUniformLocationWith3f)
    .function("setUniformsForBuiltins", select_overload<void()>(&GLProgram::setUniformsForBuiltins))
    .function("setUniformsForBuiltins", select_overload<void(const cocos2d::Mat4&)>(&GLProgram::setUniformsForBuiltins))
    .function("setUniformLocationWith3i", &GLProgram::setUniformLocationWith3i)
    .function("setUniformLocationWith4f", &GLProgram::setUniformLocationWith4f)
    .function("updateUniforms", &GLProgram::updateUniforms)
    .function("getUniformLocation", &GLProgram::getUniformLocation)
    .function("link", &GLProgram::link)
    .function("reset", &GLProgram::reset)
    .function("getAttribLocation", &GLProgram::getAttribLocation)
    .function("getVertexAttrib", &GLProgram::getVertexAttrib, allow_raw_pointers())
    .function("setUniformLocationWith2f", &GLProgram::setUniformLocationWith2f)
    .function("setUniformLocationWith4i", &GLProgram::setUniformLocationWith4i)
    .function("setUniformLocationI32", &GLProgram::setUniformLocationWith1i)
    .function("setUniformLocationWith2i", &GLProgram::setUniformLocationWith2i)
    .function("ctor", &cc_bindings_ctor<GLProgram>, allow_raw_pointers())
    .class_function("createWithByteArrays", select_overload<cocos2d::GLProgram*(const char*, const char*, const std::string&)>(&GLProgram::createWithByteArrays), allow_raw_pointers())
    .class_function("createWithByteArrays", select_overload<cocos2d::GLProgram*(const char*, const char*)>(&GLProgram::createWithByteArrays), allow_raw_pointers())
    .class_function("createWithByteArrays", select_overload<cocos2d::GLProgram*(const char*, const char*, const std::string&, const std::string&)>(&GLProgram::createWithByteArrays), allow_raw_pointers())
    .class_function("createWithFilenames", select_overload<cocos2d::GLProgram*(const std::string&, const std::string&, const std::string&)>(&GLProgram::createWithFilenames), allow_raw_pointers())
    .class_function("createWithFilenames", select_overload<cocos2d::GLProgram*(const std::string&, const std::string&)>(&GLProgram::createWithFilenames), allow_raw_pointers())
    .class_function("createWithFilenames", select_overload<cocos2d::GLProgram*(const std::string&, const std::string&, const std::string&, const std::string&)>(&GLProgram::createWithFilenames), allow_raw_pointers())
    .property("_className",  optional_override([](const GLProgram& _) -> std::string {return "GLProgram";}))    
    // TODO: assign cc.Class.extend to cc.GLProgram.extend
    ;


  class_<GLProgramCache>("cc.ShaderCache")
    .constructor<>()
    .function("reloadDefaultGLProgramsRelativeToLights", &GLProgramCache::reloadDefaultGLProgramsRelativeToLights)
    .class_function("destroyInstance", &GLProgramCache::destroyInstance, allow_raw_pointers())
    .class_function("getInstance", &GLProgramCache::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const GLProgramCache& _) -> std::string {return "GLProgramCache";}))    
    ;


  class_<RenderState>("cc.RenderState")
    .constructor<>()
    .function("setTexture", &RenderState::setTexture, allow_raw_pointers())
    .function("getTopmost", &RenderState::getTopmost, allow_raw_pointers())
    .function("getTexture", &RenderState::getTexture, allow_raw_pointers())
    .function("bind", &RenderState::bind, allow_raw_pointers())
    .function("getName", &RenderState::getName)
    .function("getStateBlock", &RenderState::getStateBlock, allow_raw_pointers())
    .function("setParent", &RenderState::setParent, allow_raw_pointers())
    .class_function("initialize", &RenderState::initialize, allow_raw_pointers())
    .class_function("finalize", &RenderState::finalize, allow_raw_pointers())
    .property("_className",  optional_override([](const RenderState& _) -> std::string {return "RenderState";}))    
    ;


  class_<Pass, base<RenderState>>("cc.Pass")
    .constructor<>()
    .function("unbind", &Pass::unbind)
    .function("bind", select_overload<void(const cocos2d::Mat4&, bool)>(&Pass::bind))
    .function("bind", select_overload<void(const cocos2d::Mat4&)>(&Pass::bind))
    .function("clone", &Pass::clone, allow_raw_pointers())
    .function("getGLProgramState", &Pass::getGLProgramState, allow_raw_pointers())
    .function("getVertexAttributeBinding", &Pass::getVertexAttributeBinding, allow_raw_pointers())
    .function("getHash", &Pass::getHash)
    .function("setVertexAttribBinding", &Pass::setVertexAttribBinding, allow_raw_pointers())
    .class_function("create", &Pass::create, allow_raw_pointers())
    .class_function("createWithGLProgramState", &Pass::createWithGLProgramState, allow_raw_pointers())
    .property("_className",  optional_override([](const Pass& _) -> std::string {return "Pass";}))    
    ;


  class_<Technique, base<RenderState>>("cc.Technique")
    .constructor<>()
    .function("getPassCount", &Technique::getPassCount)
    .function("clone", &Technique::clone, allow_raw_pointers())
    .function("addPass", &Technique::addPass, allow_raw_pointers())
    .function("getPasses", &Technique::getPasses)
    .function("getName", &Technique::getName)
    .function("getPassByIndex", &Technique::getPassByIndex, allow_raw_pointers())
    .class_function("create", &Technique::create, allow_raw_pointers())
    .class_function("createWithGLProgramState", &Technique::createWithGLProgramState, allow_raw_pointers())
    .property("_className",  optional_override([](const Technique& _) -> std::string {return "Technique";}))    
    ;


  class_<Material, base<RenderState>>("cc.Material")
    .constructor<>()
    .function("clone", &Material::clone, allow_raw_pointers())
    .function("getTechniqueCount", &Material::getTechniqueCount)
    .function("setName", &Material::setName)
    .function("getTechniqueByIndex", &Material::getTechniqueByIndex, allow_raw_pointers())
    .function("getName", &Material::getName)
    .function("getTechniques", &Material::getTechniques)
    .function("setTechnique", &Material::setTechnique)
    .function("getTechniqueByName", &Material::getTechniqueByName, allow_raw_pointers())
    .function("addTechnique", &Material::addTechnique, allow_raw_pointers())
    .function("getTechnique", &Material::getTechnique, allow_raw_pointers())
    .class_function("createWithFilename", &Material::createWithFilename, allow_raw_pointers())
    .class_function("createWithGLStateProgram", &Material::createWithGLStateProgram, allow_raw_pointers())
    .class_function("createWithProperties", &Material::createWithProperties, allow_raw_pointers())
    .property("_className",  optional_override([](const Material& _) -> std::string {return "Material";}))    
    ;


  class_<TextureCache>("cc.TextureCache")
    .constructor<>()
    .function("reloadTexture", &TextureCache::reloadTexture)
    .function("unbindAllImageAsync", &TextureCache::unbindAllImageAsync)
    .function("removeTextureForKey", &TextureCache::removeTextureForKey)
    .function("removeAllTextures", &TextureCache::removeAllTextures)
    .function("addImageAsync", select_overload<void(const std::string&, const std::function<void (cocos2d::Texture2D *)>&, const std::string&)>(&TextureCache::addImageAsync))
    .function("addImageAsync", select_overload<void(const std::string&, const std::function<void (cocos2d::Texture2D *)>&)>(&TextureCache::addImageAsync))
    .function("getDescription", &TextureCache::getDescription)
    .function("getCachedTextureInfo", &TextureCache::getCachedTextureInfo)
    .function("addImage", select_overload<cocos2d::Texture2D*(cocos2d::Image*, const std::string&)>(&TextureCache::addImage), allow_raw_pointers())
    .function("addImage", select_overload<cocos2d::Texture2D*(const std::string&)>(&TextureCache::addImage), allow_raw_pointers())
    .function("unbindImageAsync", &TextureCache::unbindImageAsync)
    .function("getTextureForKey", &TextureCache::getTextureForKey, allow_raw_pointers())
    .function("getTextureFilePath", &TextureCache::getTextureFilePath, allow_raw_pointers())
    .function("renameTextureWithKey", &TextureCache::renameTextureWithKey)
    .function("removeUnusedTextures", &TextureCache::removeUnusedTextures)
    .function("removeTexture", &TextureCache::removeTexture, allow_raw_pointers())
    .function("waitForQuit", &TextureCache::waitForQuit)
    .class_function("setETC1AlphaFileSuffix", &TextureCache::setETC1AlphaFileSuffix, allow_raw_pointers())
    .class_function("getETC1AlphaFileSuffix", &TextureCache::getETC1AlphaFileSuffix, allow_raw_pointers())
    .property("_className",  optional_override([](const TextureCache& _) -> std::string {return "TextureCache";}))    
    ;

  class_<Device>("cc.Device")
    .class_function("setAccelerometerEnabled", &Device::setAccelerometerEnabled, allow_raw_pointers())
    .class_function("setAccelerometerInterval", &Device::setAccelerometerInterval, allow_raw_pointers())
    .class_function("setKeepScreenOn", &Device::setKeepScreenOn, allow_raw_pointers())
    .class_function("vibrate", &Device::vibrate, allow_raw_pointers())
    .class_function("getDPI", &Device::getDPI, allow_raw_pointers())
    .property("_className",  optional_override([](const Device& _) -> std::string {return "Device";}))    
    ;

  class_<SAXParser>("cc.PlistParser")
    .function("init", &SAXParser::init, allow_raw_pointers())
    .property("_className",  optional_override([](const SAXParser& _) -> std::string {return "SAXParser";}))    
    ;

  class_<Application>("cc.Application")
    .function("getTargetPlatform", &Application::getTargetPlatform)
    .function("getCurrentLanguage", &Application::getCurrentLanguage)
    .function("openURL", &Application::openURL)
    .function("getVersion", &Application::getVersion)
    .class_function("getInstance", &Application::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const Application& _) -> std::string {return "Application";}))    
    ;


  class_<AnimationCache>("cc.AnimationCache")
    .constructor<>()
    .function("getAnimation", &AnimationCache::getAnimation, allow_raw_pointers())
    .function("addAnimation", &AnimationCache::addAnimation, allow_raw_pointers())
    .function("init", &AnimationCache::init)
    .function("addAnimationsWithDictionary", &AnimationCache::addAnimationsWithDictionary)
    .function("removeAnimation", &AnimationCache::removeAnimation)
    .function("addAnimations", &AnimationCache::addAnimationsWithFile)
    .function("ctor", &cc_bindings_ctor<AnimationCache>, allow_raw_pointers())
    .class_function("destroyInstance", &AnimationCache::destroyInstance, allow_raw_pointers())
    .class_function("getInstance", &AnimationCache::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const AnimationCache& _) -> std::string {return "AnimationCache";}))    
    // TODO: assign cc.Class.extend to cc.AnimationCache.extend
    ;


  class_<SpriteBatchNode, base<Node>>("cc.SpriteBatchNode")
    .constructor<>()
    .function("appendChild", &SpriteBatchNode::appendChild, allow_raw_pointers())
    .function("reorderBatch", &SpriteBatchNode::reorderBatch)
    .function("getTexture", &SpriteBatchNode::getTexture, allow_raw_pointers())
    .function("setTexture", &SpriteBatchNode::setTexture, allow_raw_pointers())
    .function("removeChildAtIndex", &SpriteBatchNode::removeChildAtIndex)
    .function("removeSpriteFromAtlas", &SpriteBatchNode::removeSpriteFromAtlas, allow_raw_pointers())
    .function("addSpriteWithoutQuad", &SpriteBatchNode::addSpriteWithoutQuad, allow_raw_pointers())
    .function("atlasIndexForChild", &SpriteBatchNode::atlasIndexForChild, allow_raw_pointers())
    .function("increaseAtlasCapacity", &SpriteBatchNode::increaseAtlasCapacity)
    .function("lowestAtlasIndexInChild", &SpriteBatchNode::lowestAtlasIndexInChild, allow_raw_pointers())
    .function("getBlendFunc", &SpriteBatchNode::getBlendFunc)
    .function("initWithTexture", &SpriteBatchNode::initWithTexture, allow_raw_pointers())
    .function("initWithTexture", optional_override(
        [](SpriteBatchNode& this_, cocos2d::Texture2D* arg0){
        return this_.initWithTexture(arg0);
      }), allow_raw_pointers())
    .function("setTextureAtlas", &SpriteBatchNode::setTextureAtlas, allow_raw_pointers())
    .function("reserveCapacity", &SpriteBatchNode::reserveCapacity)
    .function("insertQuadFromSprite", &SpriteBatchNode::insertQuadFromSprite, allow_raw_pointers())
    .function("initWithFile", &SpriteBatchNode::initWithFile)
    .function("initWithFile", optional_override(
        [](SpriteBatchNode& this_, const std::string& arg0){
        return this_.initWithFile(arg0);
      }))
    .function("setBlendFunc", &SpriteBatchNode::setBlendFunc)
    .function("rebuildIndexInOrder", &SpriteBatchNode::rebuildIndexInOrder, allow_raw_pointers())
    .function("getTextureAtlas", &SpriteBatchNode::getTextureAtlas, allow_raw_pointers())
    .function("highestAtlasIndexInChild", &SpriteBatchNode::highestAtlasIndexInChild, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<SpriteBatchNode>, allow_raw_pointers())
    .class_function("create", &SpriteBatchNode::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](const std::string& arg0){
        return SpriteBatchNode::create(arg0);
      }), allow_raw_pointers())
    .class_function("createWithTexture", &SpriteBatchNode::createWithTexture, allow_raw_pointers())
    .class_function("createWithTexture", optional_override(
      [](cocos2d::Texture2D* arg0){
        return SpriteBatchNode::createWithTexture(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const SpriteBatchNode& _) -> std::string {return "SpriteBatchNode";}))    
    // TODO: assign cc.Class.extend to cc.SpriteBatchNode.extend
    ;

  class_<SpriteFrameCache>("cc.SpriteFrameCache")
    .function("reloadTexture", &SpriteFrameCache::reloadTexture)
    .function("addSpriteFramesWithFileContent", &SpriteFrameCache::addSpriteFramesWithFileContent, allow_raw_pointers())
    .function("addSpriteFrame", &SpriteFrameCache::addSpriteFrame, allow_raw_pointers())
    .function("addSpriteFrames", select_overload<void(const std::string&, const std::string&)>(&SpriteFrameCache::addSpriteFramesWithFile))
    .function("addSpriteFrames", select_overload<void(const std::string&)>(&SpriteFrameCache::addSpriteFramesWithFile))
    // TODO: Only support function overloading with different number of parameters
    .function("getSpriteFrame", &SpriteFrameCache::getSpriteFrameByName, allow_raw_pointers())
    .function("removeSpriteFramesFromFile", &SpriteFrameCache::removeSpriteFramesFromFile)
    .function("init", &SpriteFrameCache::init)
    .function("removeSpriteFrames", &SpriteFrameCache::removeSpriteFrames)
    .function("removeUnusedSpriteFrames", &SpriteFrameCache::removeUnusedSpriteFrames)
    .function("removeSpriteFramesFromFileContent", &SpriteFrameCache::removeSpriteFramesFromFileContent)
    .function("removeSpriteFrameByName", &SpriteFrameCache::removeSpriteFrameByName)
    .function("isSpriteFramesWithFileLoaded", &SpriteFrameCache::isSpriteFramesWithFileLoaded)
    .function("removeSpriteFramesFromTexture", &SpriteFrameCache::removeSpriteFramesFromTexture, allow_raw_pointers())
    .class_function("destroyInstance", &SpriteFrameCache::destroyInstance, allow_raw_pointers())
    .class_function("getInstance", &SpriteFrameCache::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const SpriteFrameCache& _) -> std::string {return "SpriteFrameCache";}))    
    ;


  class_<TextFieldTTF, base<Label>>("cc.TextFieldTTF")
    .constructor<>()
    .function("getCharCount", &TextFieldTTF::getCharCount)
    .function("setCursorChar", &TextFieldTTF::setCursorChar)
    .function("setSecureTextEntry", &TextFieldTTF::setSecureTextEntry)
    .function("setCursorEnabled", &TextFieldTTF::setCursorEnabled)
    .function("getColorSpaceHolder", &TextFieldTTF::getColorSpaceHolder)
    .function("initWithPlaceHolder", select_overload<bool(const std::string&, const std::string&, float)>(&TextFieldTTF::initWithPlaceHolder))
    .function("initWithPlaceHolder", select_overload<bool(const std::string&, const cocos2d::Size&, cocos2d::TextHAlignment, const std::string&, float)>(&TextFieldTTF::initWithPlaceHolder))
    .function("appendString", &TextFieldTTF::appendString)
    .function("getPasswordTextStyle", &TextFieldTTF::getPasswordTextStyle)
    .function("setPasswordTextStyle", &TextFieldTTF::setPasswordTextStyle)
    .function("setColorSpaceHolder", select_overload<void(const cocos2d::Color4B&)>(&TextFieldTTF::setColorSpaceHolder))
    // TODO: Only support function overloading with different number of parameters
    .function("detachWithIME", &TextFieldTTF::detachWithIME)
    .function("setPlaceHolder", &TextFieldTTF::setPlaceHolder)
    .function("setCursorFromPoint", &TextFieldTTF::setCursorFromPoint, allow_raw_pointers())
    .function("isSecureTextEntry", &TextFieldTTF::isSecureTextEntry)
    .function("getPlaceHolder", &TextFieldTTF::getPlaceHolder)
    .function("setCursorPosition", &TextFieldTTF::setCursorPosition)
    .function("attachWithIME", &TextFieldTTF::attachWithIME)
    .function("ctor", &cc_bindings_ctor<TextFieldTTF>, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TextFieldTTF*(const std::string&, const std::string&, float)>(&TextFieldTTF::textFieldWithPlaceHolder), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::TextFieldTTF*(const std::string&, const cocos2d::Size&, cocos2d::TextHAlignment, const std::string&, float)>(&TextFieldTTF::textFieldWithPlaceHolder), allow_raw_pointers())
    .property("_className",  optional_override([](const TextFieldTTF& _) -> std::string {return "TextFieldTTF";}))    
    // TODO: assign cc.Class.extend to cc.TextFieldTTF.extend
    ;


  class_<ParallaxNode, base<Node>>("cc.ParallaxNode")
    .constructor<>()
    .function("getParallaxArray", select_overload<const cocos2d::_ccArray*() const>(&ParallaxNode::getParallaxArray), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("removeAllChildrenWithCleanup", &ParallaxNode::removeAllChildrenWithCleanup)
    .function("setParallaxArray", &ParallaxNode::setParallaxArray, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<ParallaxNode>, allow_raw_pointers())
    .class_function("create", &ParallaxNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ParallaxNode& _) -> std::string {return "ParallaxNode";}))    
    // TODO: assign cc.Class.extend to cc.ParallaxNode.extend
    ;


  class_<TMXObjectGroup>("cc.TMXObjectGroup")
    .constructor<>()
    .function("setPositionOffset", &TMXObjectGroup::setPositionOffset)
    .function("getProperty", &TMXObjectGroup::getProperty)
    .function("getPositionOffset", &TMXObjectGroup::getPositionOffset)
    .function("getObject", &TMXObjectGroup::getObject)
    .function("getObjects", select_overload<std::vector<cocos2d::Value>&()>(&TMXObjectGroup::getObjects))
    // TODO: Only support function overloading with different number of parameters
    .function("setGroupName", &TMXObjectGroup::setGroupName)
    .function("getProperties", select_overload<std::unordered_map<std::string, cocos2d::Value>&()>(&TMXObjectGroup::getProperties))
    // TODO: Only support function overloading with different number of parameters
    .function("getGroupName", &TMXObjectGroup::getGroupName)
    .function("setProperties", &TMXObjectGroup::setProperties)
    .function("setObjects", &TMXObjectGroup::setObjects)
    .property("_className",  optional_override([](const TMXObjectGroup& _) -> std::string {return "TMXObjectGroup";}))    
    ;


  class_<TMXLayerInfo>("cc.TMXLayerInfo")
    .constructor<>()
    .function("setProperties", &TMXLayerInfo::setProperties)
    .function("getProperties", &TMXLayerInfo::getProperties)
    .property("_className",  optional_override([](const TMXLayerInfo& _) -> std::string {return "TMXLayerInfo";}))    
    ;


  class_<TMXTilesetInfo>("cc.TMXTilesetInfo")
    .constructor<>()
    .function("getRectForGID", &TMXTilesetInfo::getRectForGID)
    .property("_className",  optional_override([](const TMXTilesetInfo& _) -> std::string {return "TMXTilesetInfo";}))    
    ;


  class_<TMXMapInfo>("cc.TMXMapInfo")
    .constructor<>()
    .function("setCurrentString", &TMXMapInfo::setCurrentString)
    .function("getHexSideLength", &TMXMapInfo::getHexSideLength)
    .function("setTileSize", &TMXMapInfo::setTileSize)
    .function("initWithTMXFile", &TMXMapInfo::initWithTMXFile)
    .function("getOrientation", &TMXMapInfo::getOrientation)
    .function("setObjectGroups", &TMXMapInfo::setObjectGroups)
    .function("setLayers", &TMXMapInfo::setLayers)
    .function("parseXMLFile", &TMXMapInfo::parseXMLFile)
    .function("getParentElement", &TMXMapInfo::getParentElement)
    .function("setTMXFileName", &TMXMapInfo::setTMXFileName)
    .function("parseXMLString", &TMXMapInfo::parseXMLString)
    .function("getLayers", select_overload<cocos2d::Vector<cocos2d::TMXLayerInfo *>&()>(&TMXMapInfo::getLayers))
    // TODO: Only support function overloading with different number of parameters
    .function("getStaggerAxis", &TMXMapInfo::getStaggerAxis)
    .function("setHexSideLength", &TMXMapInfo::setHexSideLength)
    .function("getTilesets", select_overload<cocos2d::Vector<cocos2d::TMXTilesetInfo *>&()>(&TMXMapInfo::getTilesets))
    // TODO: Only support function overloading with different number of parameters
    .function("getParentGID", &TMXMapInfo::getParentGID)
    .function("setParentElement", &TMXMapInfo::setParentElement)
    .function("initWithXML", &TMXMapInfo::initWithXML)
    .function("setParentGID", &TMXMapInfo::setParentGID)
    .function("getLayerAttribs", &TMXMapInfo::getLayerAttribs)
    .function("getTileSize", &TMXMapInfo::getTileSize)
    .function("getTileProperties", &TMXMapInfo::getTileProperties)
    .function("isStoringCharacters", &TMXMapInfo::isStoringCharacters)
    .function("getExternalTilesetFileName", &TMXMapInfo::getExternalTilesetFileName)
    .function("getObjectGroups", select_overload<cocos2d::Vector<cocos2d::TMXObjectGroup *>&()>(&TMXMapInfo::getObjectGroups))
    // TODO: Only support function overloading with different number of parameters
    .function("getTMXFileName", &TMXMapInfo::getTMXFileName)
    .function("setStaggerIndex", &TMXMapInfo::setStaggerIndex)
    .function("setProperties", &TMXMapInfo::setProperties)
    .function("setOrientation", &TMXMapInfo::setOrientation)
    .function("setTileProperties", &TMXMapInfo::setTileProperties)
    .function("setMapSize", &TMXMapInfo::setMapSize)
    .function("getCurrentString", &TMXMapInfo::getCurrentString)
    .function("setStoringCharacters", &TMXMapInfo::setStoringCharacters)
    .function("setStaggerAxis", &TMXMapInfo::setStaggerAxis)
    .function("getMapSize", &TMXMapInfo::getMapSize)
    .function("setTilesets", &TMXMapInfo::setTilesets)
    .function("getProperties", select_overload<std::unordered_map<std::string, cocos2d::Value>&()>(&TMXMapInfo::getProperties))
    // TODO: Only support function overloading with different number of parameters
    .function("getStaggerIndex", &TMXMapInfo::getStaggerIndex)
    .function("setLayerAttribs", &TMXMapInfo::setLayerAttribs)
    .function("ctor", &cc_bindings_ctor<TMXMapInfo>, allow_raw_pointers())
    .class_function("create", &TMXMapInfo::create, allow_raw_pointers())
    .class_function("createWithXML", &TMXMapInfo::createWithXML, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXMapInfo& _) -> std::string {return "TMXMapInfo";}))    
    // TODO: assign cc.Class.extend to cc.TMXMapInfo.extend
    ;


  class_<TMXLayer, base<SpriteBatchNode>>("cc.TMXLayer")
    .constructor<>()
    .function("getTileGIDAt", &TMXLayer::getTileGIDAt, allow_raw_pointers())
    .function("getTileGIDAt", optional_override(
        [](TMXLayer& this_, const cocos2d::Vec2& arg0){
        return this_.getTileGIDAt(arg0);
      }))
    .function("getAnimTileCoord", &TMXLayer::getAnimTileCoord, allow_raw_pointers())
    .function("getPositionAt", &TMXLayer::getPositionAt)
    .function("setLayerOrientation", &TMXLayer::setLayerOrientation)
    .function("releaseMap", &TMXLayer::releaseMap)
    .function("hasTileAnimation", &TMXLayer::hasTileAnimation)
    .function("setTiles", &TMXLayer::setTiles, allow_raw_pointers())
    .function("getLayerSize", &TMXLayer::getLayerSize)
    .function("setMapTileSize", &TMXLayer::setMapTileSize)
    .function("getLayerOrientation", &TMXLayer::getLayerOrientation)
    .function("setProperties", &TMXLayer::setProperties)
    .function("setLayerName", &TMXLayer::setLayerName)
    .function("removeTileAt", &TMXLayer::removeTileAt)
    .function("initWithTilesetInfo", &TMXLayer::initWithTilesetInfo, allow_raw_pointers())
    .function("setupTiles", &TMXLayer::setupTiles)
    .function("setTileGID", select_overload<void(unsigned int, const cocos2d::Vec2&, cocos2d::TMXTileFlags_)>(&TMXLayer::setTileGID))
    .function("setTileGID", select_overload<void(unsigned int, const cocos2d::Vec2&)>(&TMXLayer::setTileGID))
    .function("getMapTileSize", &TMXLayer::getMapTileSize)
    .function("getProperty", &TMXLayer::getProperty)
    .function("setLayerSize", &TMXLayer::setLayerSize)
    .function("getLayerName", &TMXLayer::getLayerName)
    .function("setTileSet", &TMXLayer::setTileSet, allow_raw_pointers())
    .function("getTileSet", &TMXLayer::getTileSet, allow_raw_pointers())
    .function("getProperties", select_overload<std::unordered_map<std::string, cocos2d::Value>&()>(&TMXLayer::getProperties))
    // TODO: Only support function overloading with different number of parameters
    .function("getTileAt", &TMXLayer::getTileAt, allow_raw_pointers())
    .function("getTileAnimManager", &TMXLayer::getTileAnimManager, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TMXLayer>, allow_raw_pointers())
    .class_function("create", &TMXLayer::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXLayer& _) -> std::string {return "TMXLayer";}))    
    // TODO: assign cc.Class.extend to cc.TMXLayer.extend
    ;


  class_<TMXTileAnimTask>("cc.TMXTileAnimTask")
    .constructor<cocos2d::TMXLayer*, cocos2d::TMXTileAnimInfo*, const cocos2d::Vec2&>()
    .function("start", &TMXTileAnimTask::start)
    .function("stop", &TMXTileAnimTask::stop)
    .function("isRunning", &TMXTileAnimTask::isRunning)
    .class_function("create", &TMXTileAnimTask::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXTileAnimTask& _) -> std::string {return "TMXTileAnimTask";}))    
    ;


  class_<TMXTileAnimManager>("cc.TMXTileAnimManager")
    .constructor<cocos2d::TMXLayer*>()
    .function("getTasks", &TMXTileAnimManager::getTasks)
    .function("startAll", &TMXTileAnimManager::startAll)
    .function("stopAll", &TMXTileAnimManager::stopAll)
    .class_function("create", &TMXTileAnimManager::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXTileAnimManager& _) -> std::string {return "TMXTileAnimManager";}))    
    ;


  class_<TMXTiledMap, base<Node>>("cc.TMXTiledMap")
    .constructor<>()
    .function("setObjectGroups", &TMXTiledMap::setObjectGroups)
    .function("getProperty", &TMXTiledMap::getProperty)
    .function("getLayerNum", &TMXTiledMap::getLayerNum)
    .function("setMapSize", &TMXTiledMap::setMapSize)
    .function("getObjectGroup", &TMXTiledMap::getObjectGroup, allow_raw_pointers())
    .function("getObjectGroups", select_overload<cocos2d::Vector<cocos2d::TMXObjectGroup *>&()>(&TMXTiledMap::getObjectGroups))
    // TODO: Only support function overloading with different number of parameters
    .function("getResourceFile", &TMXTiledMap::getResourceFile)
    .function("initWithTMXFile", &TMXTiledMap::initWithTMXFile)
    .function("getTileSize", &TMXTiledMap::getTileSize)
    .function("getMapSize", &TMXTiledMap::getMapSize)
    .function("setTileAnimEnabled", &TMXTiledMap::setTileAnimEnabled)
    .function("initWithXML", &TMXTiledMap::initWithXML)
    .function("getProperties", &TMXTiledMap::getProperties)
    .function("getPropertiesForGID", select_overload<bool(int, cocos2d::Value**)>(&TMXTiledMap::getPropertiesForGID), allow_raw_pointers())
    .function("getPropertiesForGID", select_overload<cocos2d::Value(int) const>(&TMXTiledMap::getPropertiesForGID))
    .function("setTileSize", &TMXTiledMap::setTileSize)
    .function("setProperties", &TMXTiledMap::setProperties)
    .function("getLayer", &TMXTiledMap::getLayer, allow_raw_pointers())
    .function("getMapOrientation", &TMXTiledMap::getMapOrientation)
    .function("setMapOrientation", &TMXTiledMap::setMapOrientation)
    .function("ctor", &cc_bindings_ctor<TMXTiledMap>, allow_raw_pointers())
    .class_function("create", &TMXTiledMap::create, allow_raw_pointers())
    .class_function("createWithXML", &TMXTiledMap::createWithXML, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXTiledMap& _) -> std::string {return "TMXTiledMap";}))    
    // TODO: assign cc.Class.extend to cc.TMXTiledMap.extend
    ;


  class_<TileMapAtlas, base<AtlasNode>>("cc.TileMapAtlas")
    .constructor<>()
    .function("initWithTileFile", &TileMapAtlas::initWithTileFile)
    .function("releaseMap", &TileMapAtlas::releaseMap)
    .function("getTGAInfo", &TileMapAtlas::getTGAInfo, allow_raw_pointers())
    .function("getTileAt", &TileMapAtlas::getTileAt)
    .function("setTile", &TileMapAtlas::setTile)
    .function("setTGAInfo", &TileMapAtlas::setTGAInfo, allow_raw_pointers())
    .function("ctor", &cc_bindings_ctor<TileMapAtlas>, allow_raw_pointers())
    .class_function("create", &TileMapAtlas::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TileMapAtlas& _) -> std::string {return "TileMapAtlas";}))    
    // TODO: assign cc.Class.extend to cc.TileMapAtlas.extend
    ;

  class_<SimpleAudioEngine>("cc.AudioEngine")
    .function("preloadMusic", &SimpleAudioEngine::preloadBackgroundMusic, allow_raw_pointers())
    .function("stopMusic", &SimpleAudioEngine::stopBackgroundMusic)
    .function("stopMusic", optional_override(
        [](SimpleAudioEngine& this_){
        return this_.stopBackgroundMusic();
      }))
    .function("stopAllEffects", &SimpleAudioEngine::stopAllEffects)
    .function("getMusicVolume", &SimpleAudioEngine::getBackgroundMusicVolume)
    .function("resumeMusic", &SimpleAudioEngine::resumeBackgroundMusic)
    .function("setMusicVolume", &SimpleAudioEngine::setBackgroundMusicVolume)
    .function("preloadEffect", &SimpleAudioEngine::preloadEffect, allow_raw_pointers())
    .function("isMusicPlaying", &SimpleAudioEngine::isBackgroundMusicPlaying)
    .function("getEffectsVolume", &SimpleAudioEngine::getEffectsVolume)
    .function("willPlayMusic", &SimpleAudioEngine::willPlayBackgroundMusic)
    .function("pauseEffect", &SimpleAudioEngine::pauseEffect)
    .function("playEffect", &SimpleAudioEngine::playEffect, allow_raw_pointers())
    .function("playEffect", optional_override(
        [](SimpleAudioEngine& this_, const char* arg0){
        return this_.playEffect(arg0);
      }), allow_raw_pointers())
    .function("playEffect", optional_override(
        [](SimpleAudioEngine& this_, const char* arg0, bool arg1){
        return this_.playEffect(arg0, arg1);
      }), allow_raw_pointers())
    .function("playEffect", optional_override(
        [](SimpleAudioEngine& this_, const char* arg0, bool arg1, float arg2){
        return this_.playEffect(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("playEffect", optional_override(
        [](SimpleAudioEngine& this_, const char* arg0, bool arg1, float arg2, float arg3){
        return this_.playEffect(arg0, arg1, arg2, arg3);
      }), allow_raw_pointers())
    .function("rewindMusic", &SimpleAudioEngine::rewindBackgroundMusic)
    .function("playMusic", &SimpleAudioEngine::playBackgroundMusic, allow_raw_pointers())
    .function("playMusic", optional_override(
        [](SimpleAudioEngine& this_, const char* arg0){
        return this_.playBackgroundMusic(arg0);
      }), allow_raw_pointers())
    .function("resumeAllEffects", &SimpleAudioEngine::resumeAllEffects)
    .function("setEffectsVolume", &SimpleAudioEngine::setEffectsVolume)
    .function("stopEffect", &SimpleAudioEngine::stopEffect)
    .function("pauseMusic", &SimpleAudioEngine::pauseBackgroundMusic)
    .function("pauseAllEffects", &SimpleAudioEngine::pauseAllEffects)
    .function("unloadEffect", &SimpleAudioEngine::unloadEffect, allow_raw_pointers())
    .function("resumeEffect", &SimpleAudioEngine::resumeEffect)
    .class_function("end", &SimpleAudioEngine::end, allow_raw_pointers())
    .class_function("getInstance", &SimpleAudioEngine::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const SimpleAudioEngine& _) -> std::string {return "SimpleAudioEngine";}))    
    ;

  class_<ComponentJS, base<Component>>("cc.ComponentJS")
    .property("_className",  optional_override([](const ComponentJS& _) -> std::string {return "ComponentJS";}))    
    ;
}
