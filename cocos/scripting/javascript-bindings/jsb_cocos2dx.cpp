#include "scripting/CCScriptBindings.h"
#include "scripting/CCScriptEngine.h"
#include "scripting/javascript-bindings/jsb_cocos2dx.hpp"
#include "cocos2d.h"
#include "audio/include/SimpleAudioEngine.h"
#include "2d/CCProtectedNode.h"
#include "base/CCAsyncTaskPool.h"
#include "scripting/component/CCComponentJS.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace bindings;
using namespace CocosDenshion;

CC_BINDINGS_ALLOW_RAW_POINTERS(Node)
CC_BINDINGS_ALLOW_RAW_POINTERS(Texture2D)
CC_BINDINGS_ALLOW_RAW_POINTERS(TextureAtlas)
CC_BINDINGS_ALLOW_RAW_POINTERS(SpriteBatchNode)
CC_BINDINGS_ALLOW_RAW_POINTERS(ParticleBatchNode)
CC_BINDINGS_ALLOW_RAW_POINTERS(Sprite)
CC_BINDINGS_ALLOW_RAW_POINTERS(GridBase)
CC_BINDINGS_ALLOW_RAW_POINTERS(ActionManager)
CC_BINDINGS_ALLOW_RAW_POINTERS(Scheduler)
CC_BINDINGS_ALLOW_RAW_POINTERS(Ref)
CC_BINDINGS_ALLOW_RAW_POINTERS(GLProgram)

COCOS_BINDINGS(jsb_cocos2dx) {

  class_<Ref>("cc.Ref");
  
  class_<Texture2D>("cc.Texture2D")
    .constructor(&cc_bindings_constructor<Texture2D>, allow_raw_pointers())
    .function("getShaderProgram", &Texture2D::getGLProgram, allow_raw_pointers())
    .function("getMaxT", &Texture2D::getMaxT)
    .function("setAlphaTexture", &Texture2D::setAlphaTexture, allow_raw_pointers())
    .function("getStringForFormat", &Texture2D::getStringForFormat, allow_raw_pointers())
    .function("initWithImage", select_overload<bool(cocos2d::Image*, cocos2d::Texture2D::PixelFormat)>(&Texture2D::initWithImage), allow_raw_pointers())
    .function("initWithImage", select_overload<bool(Image*)>(&Texture2D::initWithImage), allow_raw_pointers())
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
    .function("initWithString", select_overload<bool(const char*, const FontDefinition&)>(&Texture2D::initWithString), allow_raw_pointers())
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
    .property("name", &Texture2D::getName)
    .property("pixelFormat", &Texture2D::getPixelFormat)
    .property("pixelsWidth", &Texture2D::getPixelsWide)
    .property("pixelsHeight", &Texture2D::getPixelsHigh)
    .property("maxS", &Texture2D::getMaxS, &Texture2D::setMaxS)
    .property("maxT", &Texture2D::getMaxT, &Texture2D::setMaxT)
    .class_function("setDefaultAlphaPixelFormat", &Texture2D::setDefaultAlphaPixelFormat)
    .class_function("getDefaultAlphaPixelFormat", &Texture2D::getDefaultAlphaPixelFormat)
    .property("_className",  optional_override([](const Texture2D& _) -> std::string {return "Texture2D";}))    
    ;


  class_<Touch>("cc.Touch")
    .constructor(&cc_bindings_constructor<Touch>, allow_raw_pointers())
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
    .allow_subclass<wrapper<Touch>>("cc.Touch._extend")    
    ;


  class_<Event>("cc.Event")
    .constructor(&cc_bindings_constructor<Event, Event::Type>, allow_raw_pointers())
    .function("isStopped", &Event::isStopped)
    .function("getType", &Event::getType)
    .function("getCurrentTarget", &Event::getCurrentTarget, allow_raw_pointers())
    .function("stopPropagation", &Event::stopPropagation)
    .property("_className",  optional_override([](const Event& _) -> std::string {return "Event";}))    
    ;


  class_<EventTouch, base<Event>>("cc.EventTouch")
    .constructor(&cc_bindings_constructor<EventTouch>, allow_raw_pointers())
    .function("getEventCode", &EventTouch::getEventCode)
    .function("setEventCode", &EventTouch::setEventCode)
    .property("_className",  optional_override([](const EventTouch& _) -> std::string {return "EventTouch";}))
    .allow_subclass<wrapper<EventTouch>>("cc.EventTouch._extend")    
    ;

  class_<ComponentContainer>("cc.ComponentContainer")
    .function("visit", &ComponentContainer::visit)
    .function("remove", select_overload<bool(Component*)>(&ComponentContainer::remove), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("removeAll", &ComponentContainer::removeAll)
    .function("add", &ComponentContainer::add, allow_raw_pointers())
    .function("isEmpty", &ComponentContainer::isEmpty)
    .function("getComponent", &ComponentContainer::get, allow_raw_pointers())
    .property("_className",  optional_override([](const ComponentContainer& _) -> std::string {return "ComponentContainer";}))    
    ;


  class_<Component>("cc.Component")
    .constructor(&cc_bindings_constructor<Component>, allow_raw_pointers())
    .function("setEnabled", &Component::setEnabled)
    .function("setName", &Component::setName)
    .function("isEnabled", &Component::isEnabled)
    .function("getOwner", &Component::getOwner, allow_raw_pointers())
    .function("init", &Component::init)
    .function("setOwner", &Component::setOwner, allow_raw_pointers())
    .function("getName", &Component::getName)
    .class_function("create", &Component::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Component& _) -> std::string {return "Component";}))    
    .allow_subclass<wrapper<Component>>("cc.Component._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<Node>("cc.Node")
    .constructor(&cc_bindings_constructor<Node>, allow_raw_pointers())
    .function("addChild", select_overload<void(Node*, int)>(&Node::addChild), allow_raw_pointers())
    .function("addChild", select_overload<void(Node*)>(&Node::addChild), allow_raw_pointers())
    .function("addChild", select_overload<void(Node*, int, int)>(&Node::addChild), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("removeComponent", select_overload<bool(Component*)>(&Node::removeComponent), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setPhysicsBody", &Node::setPhysicsBody, allow_raw_pointers())
    .function("getDescription", &Node::getDescription)
    .function("setOpacityModifyRGB", &Node::setOpacityModifyRGB)
    .function("setCascadeOpacityEnabled", &Node::setCascadeOpacityEnabled)
    .function("getChildren", select_overload<const Vector<Node *>&() const>(&Node::getChildren))
    // TODO: Only support function overloading with different number of parameters
    .function("setOnExitCallback", &Node::setOnExitCallback)
    .function("setActionManager", &Node::setActionManager, allow_raw_pointers())
    .function("isIgnoreAnchorPointForPosition", &Node::isIgnoreAnchorPointForPosition)
    .function("getChildByName", optional_override(
        [](Node& this_, const std::string& arg0){
        return this_.getChildByName(arg0);
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
        [](Node& this_, Node* arg0){
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
    .function("getNodeToParentTransform", select_overload<AffineTransform(Node*) const>(&Node::getNodeToParentAffineTransform), allow_raw_pointers())
    .function("getNodeToParentTransform", select_overload<AffineTransform() const>(&Node::getNodeToParentAffineTransform))
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
    .function("getNodeToParentTransform3D", select_overload<Mat4(Node*) const>(&Node::getNodeToParentTransform), allow_raw_pointers())
    .function("getNodeToParentTransform3D", select_overload<const Mat4&() const>(&Node::getNodeToParentTransform))
    .function("convertToNodeSpaceAR", &Node::convertToNodeSpaceAR)
    .function("addComponent", &Node::addComponent, allow_raw_pointers())
    .function("runAction", &Node::runAction, allow_raw_pointers())
    .function("visit", select_overload<void()>(&Node::visit))
    .function("visit", select_overload<void(Renderer*, const Mat4&, unsigned int)>(&Node::visit), allow_raw_pointers())
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
    .function("getScheduler", select_overload<const Scheduler*() const>(&Node::getScheduler), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getPositionNormalized", &Node::getPositionNormalized)
    .function("getPosition", select_overload<void(float*, float*) const>(&Node::getPosition), allow_raw_pointers())
    .function("getPosition", select_overload<const Vec2&() const>(&Node::getPosition))
    .function("isRunning", &Node::isRunning)
    .function("getParent", select_overload<const Node*() const>(&Node::getParent), allow_raw_pointers())
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
    .function("getChildByTag", optional_override(
        [](Node& this_, int arg0){
        return this_.getChildByTag(arg0);
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
    .function("draw", select_overload<void(Renderer*, const Mat4&, unsigned int)>(&Node::draw), allow_raw_pointers())
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
    .function("getActionManager", select_overload<const ActionManager*() const>(&Node::getActionManager), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters

    // TODO: incomplete bindings come from cocos2d_specifics.cpp
    .function("onEnter", optional_override([](Node& this_) {
        CCScriptEngine::getInstance()->setCalledFromScript(true);
        this_.onEnter();
    }))
    .function("onEnterTransitionDidFinish", optional_override([](Node& this_) {
        CCScriptEngine::getInstance()->setCalledFromScript(true);
        this_.onEnterTransitionDidFinish();
    }))
    .property("x", &Node::getPositionX, &Node::setPositionX)
    .property("y", &Node::getPositionY, &Node::setPositionY)
    .property("width", 
      optional_override([](const Node& this_){return this_.getContentSize().width;}), 
      optional_override([](Node& this_, float width){this_.setContentSize(Size(width, this_.getContentSize().height));}))
    .property("height", 
      optional_override([](const Node& this_){return this_.getContentSize().height;}), 
      optional_override([](Node& this_, float height){this_.setContentSize(Size(this_.getContentSize().width, height));}))
    .property("anchorX", 
      optional_override([](const Node& this_){return this_.getAnchorPoint().x;}), 
      optional_override([](Node& this_, float x){this_.setAnchorPoint(Vec2(x, this_.getAnchorPoint().y));}))
    .property("anchorY", 
      optional_override([](const Node& this_){return this_.getAnchorPoint().y;}), 
      optional_override([](Node& this_, float y){this_.setAnchorPoint(Vec2(this_.getAnchorPoint().x, y));}))
    .property("skewX", &Node::getSkewX, &Node::setSkewX)
    .property("skewY", &Node::getSkewY, &Node::setSkewY)
    .property("zIndex", &Node::getLocalZOrder, &Node::setLocalZOrder)
    .property("vertexZ", &Node::getVertexZ, &Node::setVertexZ)
    .property("rotation", &Node::getRotation, &Node::setRotation)
    .property("rotationX", &Node::getRotationX, &Node::setRotationX)
    .property("rotationY", &Node::getRotationY, &Node::setRotationY)
    .property("scale", &Node::getScale, select_overload<void(float)>(&Node::setScale))
    .property("scaleX", &Node::getScaleX, &Node::setScaleX)
    .property("scaleY", &Node::getScaleY, &Node::setScaleY)
    .property("children", optional_override([](const Node& this_)
      {
        return const_cast<Vector<Node*>&>(this_.getChildren());
      }))
    .property("childrenCount", &Node::getChildrenCount)
    .property("parent", optional_override([](const Node& this_)
      {
        return const_cast<Node*>(this_.getParent());
      }), &Node::setParent)
    .property("visible", &Node::isVisible, &Node::setVisible)
    .property("running", &Node::isRunning)
    .property("ignoreAnchor", &Node::isIgnoreAnchorPointForPosition, &Node::ignoreAnchorPointForPosition)
    .property("actionManager", optional_override([](const Node& this_)
      {
        return const_cast<ActionManager*>(this_.getActionManager());
      }), &Node::setActionManager)
    .property("scheduler", optional_override([](const Node& this_)
      {
        return const_cast<Scheduler*>(this_.getScheduler());
      }), &Node::setScheduler)
    .property("shaderProgram", optional_override([](const Node& this_)
      {
        return const_cast<GLProgram*>(this_.getShaderProgram());
      }), &Node::setShaderProgram)
    .property("glServerState", &Node::getGLServerState, &Node::setGLServerState)
    .property("tag", &Node::getTag, &Node::setTag)
    .property("userObject", optional_override([](const Node& this_)
      {
        return const_cast<Ref*>(this_.getUserObject());
      }), &Node::setUserObject)
    // cocos2d-x js only
    // .property("arrivalOrder", &Node::getOrderOfArrival, &Node::setOrderOfArrival)
    .property("opacity", &Node::getOpacity, &Node::setOpacity)
    .property("opacityModifyRGB", &Node::isOpacityModifyRGB, &Node::setOpacityModifyRGB)
    .property("cascadeOpacity", &Node::isCascadeOpacityEnabled, &Node::setCascadeOpacityEnabled)
    .property("color", &Node::getColor, &Node::setColor)
    .property("cascadeColor", &Node::isCascadeColorEnabled, &Node::setCascadeColorEnabled)
    .class_function("create", &Node::create, allow_raw_pointers())
    .class_function("getAttachedNodeCount", &Node::getAttachedNodeCount)
    .property("_className",  optional_override([](const Node& _) -> std::string {return "Node";}))    
    .allow_subclass<wrapper<Node>>("cc.Node._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<__NodeRGBA, base<Node>>("cc.__NodeRGBA")
    .constructor(&cc_bindings_constructor<__NodeRGBA>, allow_raw_pointers())
    .property("_className",  optional_override([](const __NodeRGBA& _) -> std::string {return "__NodeRGBA";}))    
    ;


  class_<Scene, base<Node>>("cc.Scene")
    .constructor(&cc_bindings_constructor<Scene>, allow_raw_pointers())
    .function("setCameraOrderDirty", &Scene::setCameraOrderDirty)
    .function("render", select_overload<void(Renderer*, const Mat4*, const Mat4*, unsigned int)>(&Scene::render), allow_raw_pointers())
    .function("render", select_overload<void(Renderer*, const Mat4&, const Mat4*)>(&Scene::render), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("stepPhysicsAndNavigation", &Scene::stepPhysicsAndNavigation)
    .function("onProjectionChanged", &Scene::onProjectionChanged, allow_raw_pointers())
    .function("initWithSize", &Scene::initWithSize)
    .function("getDefaultCamera", &Scene::getDefaultCamera, allow_raw_pointers())
    .class_function("createWithSize", &Scene::createWithSize, allow_raw_pointers())
    .class_function("create", &Scene::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Scene& _) -> std::string {return "Scene";}))    
    .allow_subclass<wrapper<Scene>>("cc.Scene._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
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
    .class_function("setGLContextAttrs", &GLView::setGLContextAttrs)
    .class_function("getGLContextAttrs", &GLView::getGLContextAttrs)
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
    .constructor(&cc_bindings_constructor<Scheduler>, allow_raw_pointers())
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
    .class_function("destroyInstance", &AsyncTaskPool::destroyInstance)
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
    .property("tag",  &Action::getTag, &Action::setTag)
    .property("_className",  optional_override([](const Action& _) -> std::string {return "Action";}))    
    ;

  class_<FiniteTimeAction, base<Action>>("cc.FiniteTimeAction")
    .function("setDuration", &FiniteTimeAction::setDuration)
    .function("getDuration", &FiniteTimeAction::getDuration)
    .property("_className",  optional_override([](const FiniteTimeAction& _) -> std::string {return "FiniteTimeAction";}))    
    ;


  class_<Speed, base<Action>>("cc.Speed")
    .constructor(&cc_bindings_constructor<Speed>, allow_raw_pointers())
    .function("setInnerAction", &Speed::setInnerAction, allow_raw_pointers())
    .function("_getSpeed", &Speed::getSpeed)
    .function("_setSpeed", &Speed::setSpeed)
    .function("initWithAction", &Speed::initWithAction, allow_raw_pointers())
    .function("getInnerAction", &Speed::getInnerAction, allow_raw_pointers())
    .class_function("create", &Speed::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Speed& _) -> std::string {return "Speed";}))
    .allow_subclass<wrapper<Speed>>("cc.Speed._extend")    
    ;


  class_<Follow, base<Action>>("cc.Follow")
    .constructor(&cc_bindings_constructor<Follow>, allow_raw_pointers())
    .function("setBoundarySet", &Follow::setBoundarySet)
    .function("initWithTarget", &Follow::initWithTarget, allow_raw_pointers())
    .function("initWithTarget", optional_override(
        [](Follow& this_, Node* arg0){
        return this_.initWithTarget(arg0);
      }), allow_raw_pointers())
    .function("initWithTargetAndOffset", &Follow::initWithTargetAndOffset, allow_raw_pointers())
    .function("initWithTargetAndOffset", optional_override(
        [](Follow& this_, Node* arg0, float arg1, float arg2){
        return this_.initWithTargetAndOffset(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("isBoundarySet", &Follow::isBoundarySet)
    .class_function("create", &Follow::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](Node* arg0){
        return Follow::create(arg0);
      }), allow_raw_pointers())
    .class_function("createWithOffset", &Follow::createWithOffset, allow_raw_pointers())
    .class_function("createWithOffset", optional_override(
      [](Node* arg0, float arg1, float arg2){
        return Follow::createWithOffset(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const Follow& _) -> std::string {return "Follow";}))    
    .allow_subclass<wrapper<Follow>>("cc.Follow._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<Image>("cc.Image")
    .constructor(&cc_bindings_constructor<Image>, allow_raw_pointers())
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
    .class_function("setPVRImagesHavePremultipliedAlpha", &Image::setPVRImagesHavePremultipliedAlpha)
    .class_function("setPNGPremultipliedAlphaEnabled", &Image::setPNGPremultipliedAlphaEnabled)
    .property("_className",  optional_override([](const Image& _) -> std::string {return "Image";}))    
    ;

  class_<GLProgramState>("cc.GLProgramState")
    .function("setUniformCallback", select_overload<void(int, const std::function<void (GLProgram *, Uniform *)>&)>(&GLProgramState::setUniformCallback))
    // TODO: Only support function overloading with different number of parameters
    .function("getVertexAttribsFlags", &GLProgramState::getVertexAttribsFlags)
    .function("applyAutoBinding", &GLProgramState::applyAutoBinding)
    .function("setUniformVec2", select_overload<void(int, const Vec2&)>(&GLProgramState::setUniformVec2))
    // TODO: Only support function overloading with different number of parameters
    .function("setUniformVec3", select_overload<void(int, const Vec3&)>(&GLProgramState::setUniformVec3))
    // TODO: Only support function overloading with different number of parameters
    .function("setVertexAttribCallback", &GLProgramState::setVertexAttribCallback)
    .function("apply", &GLProgramState::apply)
    .function("getNodeBinding", &GLProgramState::getNodeBinding, allow_raw_pointers())
    .function("applyGLProgram", &GLProgramState::applyGLProgram)
    .function("setNodeBinding", &GLProgramState::setNodeBinding, allow_raw_pointers())
    .function("setUniformInt", select_overload<void(int, int)>(&GLProgramState::setUniformInt))
    // TODO: Only support function overloading with different number of parameters
    .function("setParameterAutoBinding", &GLProgramState::setParameterAutoBinding)
    .function("setUniformVec2v", select_overload<void(int, ssize_t, const Vec2*)>(&GLProgramState::setUniformVec2v), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getUniformCount", &GLProgramState::getUniformCount)
    .function("applyAttributes", &GLProgramState::applyAttributes)
    .function("applyAttributes", optional_override(
        [](GLProgramState& this_){
        return this_.applyAttributes();
      }))
    .function("clone", &GLProgramState::clone, allow_raw_pointers())
    .function("setGLProgram", &GLProgramState::setGLProgram, allow_raw_pointers())
    .function("setUniformFloatv", select_overload<void(int, ssize_t, const float*)>(&GLProgramState::setUniformFloatv), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getGLProgram", &GLProgramState::getGLProgram, allow_raw_pointers())
    .function("setUniformTexture", select_overload<void(int, Texture2D*)>(&GLProgramState::setUniformTexture), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("applyUniforms", &GLProgramState::applyUniforms)
    .function("setUniformFloat", select_overload<void(int, float)>(&GLProgramState::setUniformFloat))
    // TODO: Only support function overloading with different number of parameters
    .function("setUniformMat4", select_overload<void(int, const Mat4&)>(&GLProgramState::setUniformMat4))
    // TODO: Only support function overloading with different number of parameters
    .function("setUniformVec3v", select_overload<void(int, ssize_t, const Vec3*)>(&GLProgramState::setUniformVec3v), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getVertexAttribCount", &GLProgramState::getVertexAttribCount)
    .class_function("create", &GLProgramState::create, allow_raw_pointers())
    .class_function("getOrCreateWithGLProgramName", select_overload<GLProgramState*(const std::string&, Texture2D*)>(&GLProgramState::getOrCreateWithGLProgramName), allow_raw_pointers())
    .class_function("getOrCreateWithGLProgramName", select_overload<GLProgramState*(const std::string&)>(&GLProgramState::getOrCreateWithGLProgramName), allow_raw_pointers())
    .class_function("getOrCreateWithGLProgram", &GLProgramState::getOrCreateWithGLProgram, allow_raw_pointers())
    .class_function("getOrCreateWithShaders", &GLProgramState::getOrCreateWithShaders, allow_raw_pointers())
    .property("_className",  optional_override([](const GLProgramState& _) -> std::string {return "GLProgramState";}))    
    ;


  class_<SpriteFrame>("cc.SpriteFrame")
    .constructor(&cc_bindings_constructor<SpriteFrame>, allow_raw_pointers())
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
    .function("initWithTextureFilename", select_overload<bool(const std::string&, const Rect&, bool, const Vec2&, const Size&)>(&SpriteFrame::initWithTextureFilename))
    .function("initWithTextureFilename", select_overload<bool(const std::string&, const Rect&)>(&SpriteFrame::initWithTextureFilename))
    .function("setRect", &SpriteFrame::setRect)
    .function("initWithTexture", select_overload<bool(Texture2D*, const Rect&, bool, const Vec2&, const Size&)>(&SpriteFrame::initWithTexture), allow_raw_pointers())
    .function("initWithTexture", select_overload<bool(Texture2D*, const Rect&)>(&SpriteFrame::initWithTexture), allow_raw_pointers())
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
    .class_function("create", select_overload<SpriteFrame*(const std::string&, const Rect&, bool, const Vec2&, const Size&)>(&SpriteFrame::create), allow_raw_pointers())
    .class_function("create", select_overload<SpriteFrame*(const std::string&, const Rect&)>(&SpriteFrame::create), allow_raw_pointers())
    .class_function("createWithTexture", select_overload<SpriteFrame*(Texture2D*, const Rect&, bool, const Vec2&, const Size&)>(&SpriteFrame::createWithTexture), allow_raw_pointers())
    .class_function("createWithTexture", select_overload<SpriteFrame*(Texture2D*, const Rect&)>(&SpriteFrame::createWithTexture), allow_raw_pointers())
    .property("_className",  optional_override([](const SpriteFrame& _) -> std::string {return "SpriteFrame";}))    
    .allow_subclass<wrapper<SpriteFrame>>("cc.SpriteFrame._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<AnimationFrame>("cc.AnimationFrame")
    .constructor(&cc_bindings_constructor<AnimationFrame>, allow_raw_pointers())
    .function("setSpriteFrame", &AnimationFrame::setSpriteFrame, allow_raw_pointers())
    .function("getUserInfo", select_overload<std::unordered_map<std::string, Value>&()>(&AnimationFrame::getUserInfo))
    // TODO: Only support function overloading with different number of parameters
    .function("setDelayUnits", &AnimationFrame::setDelayUnits)
    .function("clone", &AnimationFrame::clone, allow_raw_pointers())
    .function("getSpriteFrame", &AnimationFrame::getSpriteFrame, allow_raw_pointers())
    .function("getDelayUnits", &AnimationFrame::getDelayUnits)
    .function("setUserInfo", &AnimationFrame::setUserInfo)
    .function("initWithSpriteFrame", &AnimationFrame::initWithSpriteFrame, allow_raw_pointers())
    .class_function("create", &AnimationFrame::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AnimationFrame& _) -> std::string {return "AnimationFrame";}))    
    .allow_subclass<wrapper<AnimationFrame>>("cc.AnimationFrame._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<Animation>("cc.Animation")
    .constructor(&cc_bindings_constructor<Animation>, allow_raw_pointers())
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
        [](Animation& this_, const Vector<SpriteFrame *>& arg0){
        return this_.initWithSpriteFrames(arg0);
      }))
    .function("initWithSpriteFrames", optional_override(
        [](Animation& this_, const Vector<SpriteFrame *>& arg0, float arg1){
        return this_.initWithSpriteFrames(arg0, arg1);
      }))
    .function("getRestoreOriginalFrame", &Animation::getRestoreOriginalFrame)
    .function("addSpriteFrameWithTexture", &Animation::addSpriteFrameWithTexture, allow_raw_pointers())
    .class_function("createWithAnimationFrames", select_overload<Animation*(const Vector<AnimationFrame *>&, float, unsigned int)>(&Animation::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithAnimationFrames", select_overload<Animation*()>(&Animation::create), allow_raw_pointers())
    .class_function("createWithSpriteFrames", &Animation::createWithSpriteFrames, allow_raw_pointers())
    .class_function("createWithSpriteFrames", optional_override(
      [](const Vector<SpriteFrame *>& arg0){
        return Animation::createWithSpriteFrames(arg0);
      }), allow_raw_pointers())
    .class_function("createWithSpriteFrames", optional_override(
      [](const Vector<SpriteFrame *>& arg0, float arg1){
        return Animation::createWithSpriteFrames(arg0, arg1);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const Animation& _) -> std::string {return "Animation";}))    
    .allow_subclass<wrapper<Animation>>("cc.Animation._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;

  class_<ActionInterval, base<FiniteTimeAction>>("cc.ActionInterval")
    .function("getAmplitudeRate", &ActionInterval::getAmplitudeRate)
    .function("initWithDuration", &ActionInterval::initWithDuration)
    .function("setAmplitudeRate", &ActionInterval::setAmplitudeRate)
    .function("getElapsed", &ActionInterval::getElapsed)
    .property("_className",  optional_override([](const ActionInterval& _) -> std::string {return "ActionInterval";}))
    .allow_subclass<wrapper<ActionInterval>>("cc.ActionInterval._extend")    
    ;


  class_<Sequence, base<ActionInterval>>("cc.Sequence")
    .constructor(&cc_bindings_constructor<Sequence>, allow_raw_pointers())
    .function("init", &Sequence::init)
    .function("initWithTwoActions", &Sequence::initWithTwoActions, allow_raw_pointers())
    .property("_className",  optional_override([](const Sequence& _) -> std::string {return "Sequence";}))    
    .allow_subclass<wrapper<Sequence>>("cc.Sequence._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<Repeat, base<ActionInterval>>("cc.Repeat")
    .constructor(&cc_bindings_constructor<Repeat>, allow_raw_pointers())
    .function("setInnerAction", &Repeat::setInnerAction, allow_raw_pointers())
    .function("initWithAction", &Repeat::initWithAction, allow_raw_pointers())
    .function("getInnerAction", &Repeat::getInnerAction, allow_raw_pointers())
    .class_function("create", &Repeat::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Repeat& _) -> std::string {return "Repeat";}))    
    .allow_subclass<wrapper<Repeat>>("cc.Repeat._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<RepeatForever, base<ActionInterval>>("cc.RepeatForever")
    .constructor(&cc_bindings_constructor<RepeatForever>, allow_raw_pointers())
    .function("setInnerAction", &RepeatForever::setInnerAction, allow_raw_pointers())
    .function("initWithAction", &RepeatForever::initWithAction, allow_raw_pointers())
    .function("getInnerAction", &RepeatForever::getInnerAction, allow_raw_pointers())
    .class_function("create", &RepeatForever::create, allow_raw_pointers())
    .property("_className",  optional_override([](const RepeatForever& _) -> std::string {return "RepeatForever";}))    
    .allow_subclass<wrapper<RepeatForever>>("cc.RepeatForever._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<Spawn, base<ActionInterval>>("cc.Spawn")
    .constructor(&cc_bindings_constructor<Spawn>, allow_raw_pointers())
    .function("init", &Spawn::init)
    .function("initWithTwoActions", &Spawn::initWithTwoActions, allow_raw_pointers())
    .property("_className",  optional_override([](const Spawn& _) -> std::string {return "Spawn";}))    
    .allow_subclass<wrapper<Spawn>>("cc.Spawn._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<RotateTo, base<ActionInterval>>("cc.RotateTo")
    .constructor(&cc_bindings_constructor<RotateTo>, allow_raw_pointers())
    .function("initWithDuration", select_overload<bool(float, const Vec3&)>(&RotateTo::initWithDuration))
    .function("initWithDuration", select_overload<bool(float, float, float)>(&RotateTo::initWithDuration))
    .class_function("create", select_overload<RotateTo*(float, float)>(&RotateTo::create), allow_raw_pointers())
    .class_function("create", select_overload<RotateTo*(float, float, float)>(&RotateTo::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const RotateTo& _) -> std::string {return "RotateTo";}))    
    .allow_subclass<wrapper<RotateTo>>("cc.RotateTo._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<RotateBy, base<ActionInterval>>("cc.RotateBy")
    .constructor(&cc_bindings_constructor<RotateBy>, allow_raw_pointers())
    .function("initWithDuration", select_overload<bool(float, float, float)>(&RotateBy::initWithDuration))
    .function("initWithDuration", select_overload<bool(float, float)>(&RotateBy::initWithDuration))
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<RotateBy*(float, float, float)>(&RotateBy::create), allow_raw_pointers())
    .class_function("create", select_overload<RotateBy*(float, float)>(&RotateBy::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const RotateBy& _) -> std::string {return "RotateBy";}))    
    .allow_subclass<wrapper<RotateBy>>("cc.RotateBy._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<MoveBy, base<ActionInterval>>("cc.MoveBy")
    .constructor(&cc_bindings_constructor<MoveBy>, allow_raw_pointers())
    .function("initWithDuration", select_overload<bool(float, const Vec3&)>(&MoveBy::initWithDuration))
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<MoveBy*(float, const Vec3&)>(&MoveBy::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const MoveBy& _) -> std::string {return "MoveBy";}))    
    .allow_subclass<wrapper<MoveBy>>("cc.MoveBy._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<MoveTo, base<MoveBy>>("cc.MoveTo")
    .constructor(&cc_bindings_constructor<MoveTo>, allow_raw_pointers())
    .function("initWithDuration", select_overload<bool(float, const Vec3&)>(&MoveTo::initWithDuration))
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<MoveTo*(float, const Vec3&)>(&MoveTo::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const MoveTo& _) -> std::string {return "MoveTo";}))    
    .allow_subclass<wrapper<MoveTo>>("cc.MoveTo._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<SkewTo, base<ActionInterval>>("cc.SkewTo")
    .constructor(&cc_bindings_constructor<SkewTo>, allow_raw_pointers())
    .function("initWithDuration", &SkewTo::initWithDuration)
    .class_function("create", &SkewTo::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SkewTo& _) -> std::string {return "SkewTo";}))    
    .allow_subclass<wrapper<SkewTo>>("cc.SkewTo._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<SkewBy, base<SkewTo>>("cc.SkewBy")
    .constructor(&cc_bindings_constructor<SkewBy>, allow_raw_pointers())
    .function("initWithDuration", &SkewBy::initWithDuration)
    .class_function("create", &SkewBy::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SkewBy& _) -> std::string {return "SkewBy";}))    
    .allow_subclass<wrapper<SkewBy>>("cc.SkewBy._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<JumpBy, base<ActionInterval>>("cc.JumpBy")
    .constructor(&cc_bindings_constructor<JumpBy>, allow_raw_pointers())
    .function("initWithDuration", &JumpBy::initWithDuration)
    .class_function("create", &JumpBy::create, allow_raw_pointers())
    .property("_className",  optional_override([](const JumpBy& _) -> std::string {return "JumpBy";}))    
    .allow_subclass<wrapper<JumpBy>>("cc.JumpBy._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<JumpTo, base<JumpBy>>("cc.JumpTo")
    .constructor(&cc_bindings_constructor<JumpTo>, allow_raw_pointers())
    .function("initWithDuration", &JumpTo::initWithDuration)
    .class_function("create", &JumpTo::create, allow_raw_pointers())
    .property("_className",  optional_override([](const JumpTo& _) -> std::string {return "JumpTo";}))    
    .allow_subclass<wrapper<JumpTo>>("cc.JumpTo._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<BezierBy, base<ActionInterval>>("cc.BezierBy")
    .constructor(&cc_bindings_constructor<BezierBy>, allow_raw_pointers())
    .property("_className",  optional_override([](const BezierBy& _) -> std::string {return "BezierBy";}))    
    .allow_subclass<wrapper<BezierBy>>("cc.BezierBy._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<BezierTo, base<BezierBy>>("cc.BezierTo")
    .constructor(&cc_bindings_constructor<BezierTo>, allow_raw_pointers())
    .property("_className",  optional_override([](const BezierTo& _) -> std::string {return "BezierTo";}))    
    .allow_subclass<wrapper<BezierTo>>("cc.BezierTo._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ScaleTo, base<ActionInterval>>("cc.ScaleTo")
    .constructor(&cc_bindings_constructor<ScaleTo>, allow_raw_pointers())
    .function("initWithDuration", select_overload<bool(float, float, float)>(&ScaleTo::initWithDuration))
    .function("initWithDuration", select_overload<bool(float, float)>(&ScaleTo::initWithDuration))
    .function("initWithDuration", select_overload<bool(float, float, float, float)>(&ScaleTo::initWithDuration))
    .class_function("create", select_overload<ScaleTo*(float, float, float)>(&ScaleTo::create), allow_raw_pointers())
    .class_function("create", select_overload<ScaleTo*(float, float)>(&ScaleTo::create), allow_raw_pointers())
    .class_function("create", select_overload<ScaleTo*(float, float, float, float)>(&ScaleTo::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ScaleTo& _) -> std::string {return "ScaleTo";}))    
    .allow_subclass<wrapper<ScaleTo>>("cc.ScaleTo._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ScaleBy, base<ScaleTo>>("cc.ScaleBy")
    .constructor(&cc_bindings_constructor<ScaleBy>, allow_raw_pointers())
    .class_function("create", select_overload<ScaleBy*(float, float, float)>(&ScaleBy::create), allow_raw_pointers())
    .class_function("create", select_overload<ScaleBy*(float, float)>(&ScaleBy::create), allow_raw_pointers())
    .class_function("create", select_overload<ScaleBy*(float, float, float, float)>(&ScaleBy::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ScaleBy& _) -> std::string {return "ScaleBy";}))    
    .allow_subclass<wrapper<ScaleBy>>("cc.ScaleBy._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<Blink, base<ActionInterval>>("cc.Blink")
    .constructor(&cc_bindings_constructor<Blink>, allow_raw_pointers())
    .function("initWithDuration", &Blink::initWithDuration)
    .class_function("create", &Blink::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Blink& _) -> std::string {return "Blink";}))    
    .allow_subclass<wrapper<Blink>>("cc.Blink._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<FadeTo, base<ActionInterval>>("cc.FadeTo")
    .constructor(&cc_bindings_constructor<FadeTo>, allow_raw_pointers())
    .function("initWithDuration", &FadeTo::initWithDuration)
    .class_function("create", &FadeTo::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeTo& _) -> std::string {return "FadeTo";}))    
    .allow_subclass<wrapper<FadeTo>>("cc.FadeTo._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<FadeIn, base<FadeTo>>("cc.FadeIn")
    .constructor(&cc_bindings_constructor<FadeIn>, allow_raw_pointers())
    .function("setReverseAction", &FadeIn::setReverseAction, allow_raw_pointers())
    .class_function("create", &FadeIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeIn& _) -> std::string {return "FadeIn";}))    
    .allow_subclass<wrapper<FadeIn>>("cc.FadeIn._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<FadeOut, base<FadeTo>>("cc.FadeOut")
    .constructor(&cc_bindings_constructor<FadeOut>, allow_raw_pointers())
    .function("setReverseAction", &FadeOut::setReverseAction, allow_raw_pointers())
    .class_function("create", &FadeOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeOut& _) -> std::string {return "FadeOut";}))    
    .allow_subclass<wrapper<FadeOut>>("cc.FadeOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TintTo, base<ActionInterval>>("cc.TintTo")
    .constructor(&cc_bindings_constructor<TintTo>, allow_raw_pointers())
    .function("initWithDuration", &TintTo::initWithDuration)
    .class_function("create", select_overload<TintTo*(float, const Color3B&)>(&TintTo::create), allow_raw_pointers())
    .class_function("create", select_overload<TintTo*(float, unsigned char, unsigned char, unsigned char)>(&TintTo::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TintTo& _) -> std::string {return "TintTo";}))    
    .allow_subclass<wrapper<TintTo>>("cc.TintTo._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TintBy, base<ActionInterval>>("cc.TintBy")
    .constructor(&cc_bindings_constructor<TintBy>, allow_raw_pointers())
    .function("initWithDuration", &TintBy::initWithDuration)
    .class_function("create", &TintBy::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TintBy& _) -> std::string {return "TintBy";}))    
    .allow_subclass<wrapper<TintBy>>("cc.TintBy._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<DelayTime, base<ActionInterval>>("cc.DelayTime")
    .constructor(&cc_bindings_constructor<DelayTime>, allow_raw_pointers())
    .class_function("create", &DelayTime::create, allow_raw_pointers())
    .property("_className",  optional_override([](const DelayTime& _) -> std::string {return "DelayTime";}))    
    .allow_subclass<wrapper<DelayTime>>("cc.DelayTime._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ReverseTime, base<ActionInterval>>("cc.ReverseTime")
    .constructor(&cc_bindings_constructor<ReverseTime>, allow_raw_pointers())
    .function("initWithAction", &ReverseTime::initWithAction, allow_raw_pointers())
    .class_function("create", &ReverseTime::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ReverseTime& _) -> std::string {return "ReverseTime";}))    
    .allow_subclass<wrapper<ReverseTime>>("cc.ReverseTime._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<Animate, base<ActionInterval>>("cc.Animate")
    .constructor(&cc_bindings_constructor<Animate>, allow_raw_pointers())
    .function("initWithAnimation", &Animate::initWithAnimation, allow_raw_pointers())
    .function("getAnimation", select_overload<const Animation*() const>(&Animate::getAnimation), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getCurrentFrameIndex", &Animate::getCurrentFrameIndex)
    .function("setAnimation", &Animate::setAnimation, allow_raw_pointers())
    .class_function("create", &Animate::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Animate& _) -> std::string {return "Animate";}))    
    .allow_subclass<wrapper<Animate>>("cc.Animate._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TargetedAction, base<ActionInterval>>("cc.TargetedAction")
    .constructor(&cc_bindings_constructor<TargetedAction>, allow_raw_pointers())
    .function("getForcedTarget", select_overload<const Node*() const>(&TargetedAction::getForcedTarget), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("initWithTarget", &TargetedAction::initWithTarget, allow_raw_pointers())
    .function("setForcedTarget", &TargetedAction::setForcedTarget, allow_raw_pointers())
    .class_function("create", &TargetedAction::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TargetedAction& _) -> std::string {return "TargetedAction";}))    
    .allow_subclass<wrapper<TargetedAction>>("cc.TargetedAction._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ActionFloat, base<ActionInterval>>("cc.ActionFloat")
    .constructor(&cc_bindings_constructor<ActionFloat>, allow_raw_pointers())
    .function("initWithDuration", &ActionFloat::initWithDuration)
    .class_function("create", &ActionFloat::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionFloat& _) -> std::string {return "ActionFloat";}))    
    .allow_subclass<wrapper<ActionFloat>>("cc.ActionFloat._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
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
    .class_function("destroyInstance", &Configuration::destroyInstance)
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
    .function("getNamespace", select_overload<Properties*(const char*, bool, bool) const>(&Properties::getNamespace), allow_raw_pointers())
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
    .function("getColor", select_overload<bool(const char*, Vec4*) const>(&Properties::getColor), allow_raw_pointers())
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
    .class_function("parseColor", select_overload<bool(const char*, Vec4*)>(&Properties::parseColor), allow_raw_pointers())
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
    .function("writeValueVectorToFile", select_overload<void(std::vector<Value>, const std::string&, std::function<void (bool)>) const>(&FileUtils::writeValueVectorToFile))
    .function("writeValueVectorToFile", select_overload<bool(const std::vector<Value>&, const std::string&) const>(&FileUtils::writeValueVectorToFile))
    .function("isFileExist", select_overload<void(const std::string&, std::function<void (bool)>) const>(&FileUtils::isFileExist))
    .function("isFileExist", select_overload<bool(const std::string&) const>(&FileUtils::isFileExist))
    .function("purgeCachedEntries", &FileUtils::purgeCachedEntries)
    .function("fullPathFromRelativeFile", &FileUtils::fullPathFromRelativeFile)
    .function("getSuitableFOpen", &FileUtils::getSuitableFOpen)
    .function("writeValueMapToFile", select_overload<void(std::unordered_map<std::string, Value>, const std::string&, std::function<void (bool)>) const>(&FileUtils::writeValueMapToFile))
    .function("writeValueMapToFile", select_overload<bool(const std::unordered_map<std::string, Value>&, const std::string&) const>(&FileUtils::writeValueMapToFile))
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
    .constructor(&cc_bindings_constructor<EventAcceleration, const Acceleration&>, allow_raw_pointers())
    .property("_className",  optional_override([](const EventAcceleration& _) -> std::string {return "EventAcceleration";}))    
    ;


  class_<EventCustom, base<Event>>("cc.EventCustom")
    .constructor(&cc_bindings_constructor<EventCustom, const std::string&>, allow_raw_pointers())
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
    .constructor(&cc_bindings_constructor<EventDispatcher>, allow_raw_pointers())
    .function("setEnabled", &EventDispatcher::setEnabled)
    .function("removeAllListeners", &EventDispatcher::removeAllEventListeners)
    .function("addEventListenerWithSceneGraphPriority", &EventDispatcher::addEventListenerWithSceneGraphPriority, allow_raw_pointers())
    .function("addEventListenerWithFixedPriority", &EventDispatcher::addEventListenerWithFixedPriority, allow_raw_pointers())
    .function("removeListeners", select_overload<void(Node*, bool)>(&EventDispatcher::removeEventListenersForTarget), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("removeListeners", select_overload<void(EventListener::Type)>(&EventDispatcher::removeEventListenersForType))
    .function("resumeTarget", &EventDispatcher::resumeEventListenersForTarget, allow_raw_pointers())
    .function("resumeTarget", optional_override(
        [](EventDispatcher& this_, Node* arg0){
        return this_.resumeEventListenersForTarget(arg0);
      }), allow_raw_pointers())
    .function("setPriority", &EventDispatcher::setPriority, allow_raw_pointers())
    .function("dispatchEvent", &EventDispatcher::dispatchEvent, allow_raw_pointers())
    .function("hasEventListener", &EventDispatcher::hasEventListener)
    .function("pauseTarget", &EventDispatcher::pauseEventListenersForTarget, allow_raw_pointers())
    .function("pauseTarget", optional_override(
        [](EventDispatcher& this_, Node* arg0){
        return this_.pauseEventListenersForTarget(arg0);
      }), allow_raw_pointers())
    .function("removeCustomListeners", &EventDispatcher::removeCustomEventListeners)
    .function("removeListener", &EventDispatcher::removeEventListener, allow_raw_pointers())
    .function("isEnabled", &EventDispatcher::isEnabled)
    .property("_className",  optional_override([](const EventDispatcher& _) -> std::string {return "EventDispatcher";}))    
    ;


  class_<EventFocus, base<Event>>("cc.EventFocus")
    .constructor(&cc_bindings_constructor<EventFocus, ui::Widget*, ui::Widget*>, allow_raw_pointers())
    .property("_className",  optional_override([](const EventFocus& _) -> std::string {return "EventFocus";}))    
    ;


  class_<EventListenerAcceleration, base<EventListener>>("cc.EventListenerAcceleration")
    .constructor(&cc_bindings_constructor<EventListenerAcceleration>, allow_raw_pointers())
    .function("init", &EventListenerAcceleration::init)
    .property("_className",  optional_override([](const EventListenerAcceleration& _) -> std::string {return "EventListenerAcceleration";}))    
    ;


  class_<EventListenerCustom, base<EventListener>>("cc.EventListenerCustom")
    .constructor(&cc_bindings_constructor<EventListenerCustom>, allow_raw_pointers())
    .property("_className",  optional_override([](const EventListenerCustom& _) -> std::string {return "EventListenerCustom";}))    
    ;


  class_<EventListenerFocus, base<EventListener>>("cc.EventListenerFocus")
    .constructor(&cc_bindings_constructor<EventListenerFocus>, allow_raw_pointers())
    .function("init", &EventListenerFocus::init)
    .property("_className",  optional_override([](const EventListenerFocus& _) -> std::string {return "EventListenerFocus";}))    
    ;


  class_<EventListenerKeyboard, base<EventListener>>("cc.EventListenerKeyboard")
    .constructor(&cc_bindings_constructor<EventListenerKeyboard>, allow_raw_pointers())
    .function("init", &EventListenerKeyboard::init)
    .property("_className",  optional_override([](const EventListenerKeyboard& _) -> std::string {return "EventListenerKeyboard";}))    
    ;


  class_<EventMouse, base<Event>>("cc.EventMouse")
    .constructor(&cc_bindings_constructor<EventMouse, EventMouse::MouseEventType>, allow_raw_pointers())
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
    .constructor(&cc_bindings_constructor<EventListenerMouse>, allow_raw_pointers())
    .function("init", &EventListenerMouse::init)
    .class_function("create", optional_override(
    [](){
      auto ret = val::global("cc")["EventListenerMouse"].new_();
      auto listener = ret.as<EventListenerMouse*>(allow_raw_pointers());
      listener->onMouseDown = [ret](Event* event) {
        ret["onMouseDown"](val(event));
      };

      listener->onMouseUp = [ret](Event* event) {
        ret["onMouseUp"](val(event));
      };

      listener->onMouseMove = [ret](Event* event) {
        ret["onMouseMove"](val(event));
      };

      listener->onMouseScroll = [ret](Event* event) {
        ret["onMouseScroll"](val(event));
      };

      return ret;
    }), allow_raw_pointers())
    .property("_className",  optional_override([](const EventListenerMouse& _) -> std::string {return "EventListenerMouse";}))    
    ;

  class_<EventListenerController, base<EventListener>>("cc.EventListenerController")
    .class_function("create", &EventListenerController::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EventListenerController& _) -> std::string {return "EventListenerController";}))    
    ;


  class_<EventListenerTouchOneByOne, base<EventListener>>("cc.EventListenerTouchOneByOne")
    .constructor(&cc_bindings_constructor<EventListenerTouchOneByOne>, allow_raw_pointers())
    .function("isSwallowTouches", &EventListenerTouchOneByOne::isSwallowTouches)
    .function("setSwallowTouches", &EventListenerTouchOneByOne::setSwallowTouches)
    .function("init", &EventListenerTouchOneByOne::init)
    .property("_className",  optional_override([](const EventListenerTouchOneByOne& _) -> std::string {return "EventListenerTouchOneByOne";}))    
    ;


  class_<EventListenerTouchAllAtOnce, base<EventListener>>("cc.EventListenerTouchAllAtOnce")
    .constructor(&cc_bindings_constructor<EventListenerTouchAllAtOnce>, allow_raw_pointers())
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
    .constructor(&cc_bindings_constructor<ActionCamera>, allow_raw_pointers())
    .function("setEye", select_overload<void(float, float, float)>(&ActionCamera::setEye))
    .function("setEye", select_overload<void(const Vec3&)>(&ActionCamera::setEye))
    .function("getEye", &ActionCamera::getEye)
    .function("setUp", &ActionCamera::setUp)
    .function("getCenter", &ActionCamera::getCenter)
    .function("setCenter", &ActionCamera::setCenter)
    .function("getUp", &ActionCamera::getUp)
    .property("_className",  optional_override([](const ActionCamera& _) -> std::string {return "ActionCamera";}))    
    .allow_subclass<wrapper<ActionCamera>>("cc.ActionCamera._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<OrbitCamera, base<ActionCamera>>("cc.OrbitCamera")
    .constructor(&cc_bindings_constructor<OrbitCamera>, allow_raw_pointers())
    .function("sphericalRadius", &OrbitCamera::sphericalRadius, allow_raw_pointers())
    .function("initWithDuration", &OrbitCamera::initWithDuration)
    .class_function("create", &OrbitCamera::create, allow_raw_pointers())
    .property("_className",  optional_override([](const OrbitCamera& _) -> std::string {return "OrbitCamera";}))    
    .allow_subclass<wrapper<OrbitCamera>>("cc.OrbitCamera._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<CardinalSplineTo, base<ActionInterval>>("cc.CardinalSplineTo")
    .constructor(&cc_bindings_constructor<CardinalSplineTo>, allow_raw_pointers())
    .function("getPoints", &CardinalSplineTo::getPoints, allow_raw_pointers())
    .function("updatePosition", &CardinalSplineTo::updatePosition)
    .property("_className",  optional_override([](const CardinalSplineTo& _) -> std::string {return "CardinalSplineTo";}))
    .allow_subclass<wrapper<CardinalSplineTo>>("cc.CardinalSplineTo._extend")    
    ;


  class_<CardinalSplineBy, base<CardinalSplineTo>>("cc.CardinalSplineBy")
    .constructor(&cc_bindings_constructor<CardinalSplineBy>, allow_raw_pointers())
    .property("_className",  optional_override([](const CardinalSplineBy& _) -> std::string {return "CardinalSplineBy";}))
    .allow_subclass<wrapper<CardinalSplineBy>>("cc.CardinalSplineBy._extend")    
    ;

  class_<CatmullRomTo, base<CardinalSplineTo>>("cc.CatmullRomTo")
    .property("_className",  optional_override([](const CatmullRomTo& _) -> std::string {return "CatmullRomTo";}))
    .allow_subclass<wrapper<CatmullRomTo>>("cc.CatmullRomTo._extend")    
    ;

  class_<CatmullRomBy, base<CardinalSplineBy>>("cc.CatmullRomBy")
    .property("_className",  optional_override([](const CatmullRomBy& _) -> std::string {return "CatmullRomBy";}))
    .allow_subclass<wrapper<CatmullRomBy>>("cc.CatmullRomBy._extend")    
    ;

  class_<ActionEase, base<ActionInterval>>("cc.ActionEase")
    .function("initWithAction", &ActionEase::initWithAction, allow_raw_pointers())
    .function("getInnerAction", &ActionEase::getInnerAction, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionEase& _) -> std::string {return "ActionEase";}))
    .allow_subclass<wrapper<ActionEase>>("cc.ActionEase._extend")    
    ;

  class_<EaseRateAction, base<ActionEase>>("cc.EaseRateAction")
    .function("setRate", &EaseRateAction::setRate)
    .function("initWithAction", &EaseRateAction::initWithAction, allow_raw_pointers())
    .function("getRate", &EaseRateAction::getRate)
    .class_function("create", &EaseRateAction::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseRateAction& _) -> std::string {return "EaseRateAction";}))
    .allow_subclass<wrapper<EaseRateAction>>("cc.EaseRateAction._extend")    
    ;


  class_<EaseExponentialIn, base<ActionEase>>("cc.EaseExponentialIn")
    .constructor(&cc_bindings_constructor<EaseExponentialIn>, allow_raw_pointers())
    .class_function("create", &EaseExponentialIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseExponentialIn& _) -> std::string {return "EaseExponentialIn";}))    
    .allow_subclass<wrapper<EaseExponentialIn>>("cc.EaseExponentialIn._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseExponentialOut, base<ActionEase>>("cc.EaseExponentialOut")
    .constructor(&cc_bindings_constructor<EaseExponentialOut>, allow_raw_pointers())
    .class_function("create", &EaseExponentialOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseExponentialOut& _) -> std::string {return "EaseExponentialOut";}))    
    .allow_subclass<wrapper<EaseExponentialOut>>("cc.EaseExponentialOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseExponentialInOut, base<ActionEase>>("cc.EaseExponentialInOut")
    .constructor(&cc_bindings_constructor<EaseExponentialInOut>, allow_raw_pointers())
    .class_function("create", &EaseExponentialInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseExponentialInOut& _) -> std::string {return "EaseExponentialInOut";}))    
    .allow_subclass<wrapper<EaseExponentialInOut>>("cc.EaseExponentialInOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseSineIn, base<ActionEase>>("cc.EaseSineIn")
    .constructor(&cc_bindings_constructor<EaseSineIn>, allow_raw_pointers())
    .class_function("create", &EaseSineIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseSineIn& _) -> std::string {return "EaseSineIn";}))    
    .allow_subclass<wrapper<EaseSineIn>>("cc.EaseSineIn._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseSineOut, base<ActionEase>>("cc.EaseSineOut")
    .constructor(&cc_bindings_constructor<EaseSineOut>, allow_raw_pointers())
    .class_function("create", &EaseSineOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseSineOut& _) -> std::string {return "EaseSineOut";}))    
    .allow_subclass<wrapper<EaseSineOut>>("cc.EaseSineOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseSineInOut, base<ActionEase>>("cc.EaseSineInOut")
    .constructor(&cc_bindings_constructor<EaseSineInOut>, allow_raw_pointers())
    .class_function("create", &EaseSineInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseSineInOut& _) -> std::string {return "EaseSineInOut";}))    
    .allow_subclass<wrapper<EaseSineInOut>>("cc.EaseSineInOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;

  class_<EaseBounce, base<ActionEase>>("cc.EaseBounce")
    .property("_className",  optional_override([](const EaseBounce& _) -> std::string {return "EaseBounce";}))
    .allow_subclass<wrapper<EaseBounce>>("cc.EaseBounce._extend")    
    ;


  class_<EaseBounceIn, base<ActionEase>>("cc.EaseBounceIn")
    .constructor(&cc_bindings_constructor<EaseBounceIn>, allow_raw_pointers())
    .class_function("create", &EaseBounceIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBounceIn& _) -> std::string {return "EaseBounceIn";}))    
    .allow_subclass<wrapper<EaseBounceIn>>("cc.EaseBounceIn._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseBounceOut, base<ActionEase>>("cc.EaseBounceOut")
    .constructor(&cc_bindings_constructor<EaseBounceOut>, allow_raw_pointers())
    .class_function("create", &EaseBounceOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBounceOut& _) -> std::string {return "EaseBounceOut";}))    
    .allow_subclass<wrapper<EaseBounceOut>>("cc.EaseBounceOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseBounceInOut, base<ActionEase>>("cc.EaseBounceInOut")
    .constructor(&cc_bindings_constructor<EaseBounceInOut>, allow_raw_pointers())
    .class_function("create", &EaseBounceInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBounceInOut& _) -> std::string {return "EaseBounceInOut";}))    
    .allow_subclass<wrapper<EaseBounceInOut>>("cc.EaseBounceInOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseBackIn, base<ActionEase>>("cc.EaseBackIn")
    .constructor(&cc_bindings_constructor<EaseBackIn>, allow_raw_pointers())
    .class_function("create", &EaseBackIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBackIn& _) -> std::string {return "EaseBackIn";}))    
    .allow_subclass<wrapper<EaseBackIn>>("cc.EaseBackIn._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseBackOut, base<ActionEase>>("cc.EaseBackOut")
    .constructor(&cc_bindings_constructor<EaseBackOut>, allow_raw_pointers())
    .class_function("create", &EaseBackOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBackOut& _) -> std::string {return "EaseBackOut";}))    
    .allow_subclass<wrapper<EaseBackOut>>("cc.EaseBackOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseBackInOut, base<ActionEase>>("cc.EaseBackInOut")
    .constructor(&cc_bindings_constructor<EaseBackInOut>, allow_raw_pointers())
    .class_function("create", &EaseBackInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBackInOut& _) -> std::string {return "EaseBackInOut";}))    
    .allow_subclass<wrapper<EaseBackInOut>>("cc.EaseBackInOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseQuadraticActionIn, base<ActionEase>>("cc.EaseQuadraticActionIn")
    .constructor(&cc_bindings_constructor<EaseQuadraticActionIn>, allow_raw_pointers())
    .class_function("create", &EaseQuadraticActionIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuadraticActionIn& _) -> std::string {return "EaseQuadraticActionIn";}))    
    .allow_subclass<wrapper<EaseQuadraticActionIn>>("cc.EaseQuadraticActionIn._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseQuadraticActionOut, base<ActionEase>>("cc.EaseQuadraticActionOut")
    .constructor(&cc_bindings_constructor<EaseQuadraticActionOut>, allow_raw_pointers())
    .class_function("create", &EaseQuadraticActionOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuadraticActionOut& _) -> std::string {return "EaseQuadraticActionOut";}))    
    .allow_subclass<wrapper<EaseQuadraticActionOut>>("cc.EaseQuadraticActionOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseQuadraticActionInOut, base<ActionEase>>("cc.EaseQuadraticActionInOut")
    .constructor(&cc_bindings_constructor<EaseQuadraticActionInOut>, allow_raw_pointers())
    .class_function("create", &EaseQuadraticActionInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuadraticActionInOut& _) -> std::string {return "EaseQuadraticActionInOut";}))    
    .allow_subclass<wrapper<EaseQuadraticActionInOut>>("cc.EaseQuadraticActionInOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseQuarticActionIn, base<ActionEase>>("cc.EaseQuarticActionIn")
    .constructor(&cc_bindings_constructor<EaseQuarticActionIn>, allow_raw_pointers())
    .class_function("create", &EaseQuarticActionIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuarticActionIn& _) -> std::string {return "EaseQuarticActionIn";}))    
    .allow_subclass<wrapper<EaseQuarticActionIn>>("cc.EaseQuarticActionIn._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseQuarticActionOut, base<ActionEase>>("cc.EaseQuarticActionOut")
    .constructor(&cc_bindings_constructor<EaseQuarticActionOut>, allow_raw_pointers())
    .class_function("create", &EaseQuarticActionOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuarticActionOut& _) -> std::string {return "EaseQuarticActionOut";}))    
    .allow_subclass<wrapper<EaseQuarticActionOut>>("cc.EaseQuarticActionOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseQuarticActionInOut, base<ActionEase>>("cc.EaseQuarticActionInOut")
    .constructor(&cc_bindings_constructor<EaseQuarticActionInOut>, allow_raw_pointers())
    .class_function("create", &EaseQuarticActionInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuarticActionInOut& _) -> std::string {return "EaseQuarticActionInOut";}))    
    .allow_subclass<wrapper<EaseQuarticActionInOut>>("cc.EaseQuarticActionInOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseQuinticActionIn, base<ActionEase>>("cc.EaseQuinticActionIn")
    .constructor(&cc_bindings_constructor<EaseQuinticActionIn>, allow_raw_pointers())
    .class_function("create", &EaseQuinticActionIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuinticActionIn& _) -> std::string {return "EaseQuinticActionIn";}))    
    .allow_subclass<wrapper<EaseQuinticActionIn>>("cc.EaseQuinticActionIn._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseQuinticActionOut, base<ActionEase>>("cc.EaseQuinticActionOut")
    .constructor(&cc_bindings_constructor<EaseQuinticActionOut>, allow_raw_pointers())
    .class_function("create", &EaseQuinticActionOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuinticActionOut& _) -> std::string {return "EaseQuinticActionOut";}))    
    .allow_subclass<wrapper<EaseQuinticActionOut>>("cc.EaseQuinticActionOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseQuinticActionInOut, base<ActionEase>>("cc.EaseQuinticActionInOut")
    .constructor(&cc_bindings_constructor<EaseQuinticActionInOut>, allow_raw_pointers())
    .class_function("create", &EaseQuinticActionInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseQuinticActionInOut& _) -> std::string {return "EaseQuinticActionInOut";}))    
    .allow_subclass<wrapper<EaseQuinticActionInOut>>("cc.EaseQuinticActionInOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseCircleActionIn, base<ActionEase>>("cc.EaseCircleActionIn")
    .constructor(&cc_bindings_constructor<EaseCircleActionIn>, allow_raw_pointers())
    .class_function("create", &EaseCircleActionIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCircleActionIn& _) -> std::string {return "EaseCircleActionIn";}))    
    .allow_subclass<wrapper<EaseCircleActionIn>>("cc.EaseCircleActionIn._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseCircleActionOut, base<ActionEase>>("cc.EaseCircleActionOut")
    .constructor(&cc_bindings_constructor<EaseCircleActionOut>, allow_raw_pointers())
    .class_function("create", &EaseCircleActionOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCircleActionOut& _) -> std::string {return "EaseCircleActionOut";}))    
    .allow_subclass<wrapper<EaseCircleActionOut>>("cc.EaseCircleActionOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseCircleActionInOut, base<ActionEase>>("cc.EaseCircleActionInOut")
    .constructor(&cc_bindings_constructor<EaseCircleActionInOut>, allow_raw_pointers())
    .class_function("create", &EaseCircleActionInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCircleActionInOut& _) -> std::string {return "EaseCircleActionInOut";}))    
    .allow_subclass<wrapper<EaseCircleActionInOut>>("cc.EaseCircleActionInOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseCubicActionIn, base<ActionEase>>("cc.EaseCubicActionIn")
    .constructor(&cc_bindings_constructor<EaseCubicActionIn>, allow_raw_pointers())
    .class_function("create", &EaseCubicActionIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCubicActionIn& _) -> std::string {return "EaseCubicActionIn";}))    
    .allow_subclass<wrapper<EaseCubicActionIn>>("cc.EaseCubicActionIn._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseCubicActionOut, base<ActionEase>>("cc.EaseCubicActionOut")
    .constructor(&cc_bindings_constructor<EaseCubicActionOut>, allow_raw_pointers())
    .class_function("create", &EaseCubicActionOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCubicActionOut& _) -> std::string {return "EaseCubicActionOut";}))    
    .allow_subclass<wrapper<EaseCubicActionOut>>("cc.EaseCubicActionOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseCubicActionInOut, base<ActionEase>>("cc.EaseCubicActionInOut")
    .constructor(&cc_bindings_constructor<EaseCubicActionInOut>, allow_raw_pointers())
    .class_function("create", &EaseCubicActionInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseCubicActionInOut& _) -> std::string {return "EaseCubicActionInOut";}))    
    .allow_subclass<wrapper<EaseCubicActionInOut>>("cc.EaseCubicActionInOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseIn, base<EaseRateAction>>("cc.EaseIn")
    .constructor(&cc_bindings_constructor<EaseIn>, allow_raw_pointers())
    .class_function("create", &EaseIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseIn& _) -> std::string {return "EaseIn";}))    
    .allow_subclass<wrapper<EaseIn>>("cc.EaseIn._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseOut, base<EaseRateAction>>("cc.EaseOut")
    .constructor(&cc_bindings_constructor<EaseOut>, allow_raw_pointers())
    .class_function("create", &EaseOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseOut& _) -> std::string {return "EaseOut";}))    
    .allow_subclass<wrapper<EaseOut>>("cc.EaseOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseInOut, base<EaseRateAction>>("cc.EaseInOut")
    .constructor(&cc_bindings_constructor<EaseInOut>, allow_raw_pointers())
    .class_function("create", &EaseInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseInOut& _) -> std::string {return "EaseInOut";}))    
    .allow_subclass<wrapper<EaseInOut>>("cc.EaseInOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;

  class_<EaseElastic, base<ActionEase>>("cc.EaseElastic")
    .function("setPeriod", &EaseElastic::setPeriod)
    .function("initWithAction", &EaseElastic::initWithAction, allow_raw_pointers())
    .function("initWithAction", optional_override(
        [](EaseElastic& this_, ActionInterval* arg0){
        return this_.initWithAction(arg0);
      }), allow_raw_pointers())
    .function("getPeriod", &EaseElastic::getPeriod)
    .property("_className",  optional_override([](const EaseElastic& _) -> std::string {return "EaseElastic";}))
    .allow_subclass<wrapper<EaseElastic>>("cc.EaseElastic._extend")    
    ;


  class_<EaseElasticIn, base<EaseElastic>>("cc.EaseElasticIn")
    .constructor(&cc_bindings_constructor<EaseElasticIn>, allow_raw_pointers())
    .class_function("create", &EaseElasticIn::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](ActionInterval* arg0){
        return EaseElasticIn::create(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const EaseElasticIn& _) -> std::string {return "EaseElasticIn";}))    
    .allow_subclass<wrapper<EaseElasticIn>>("cc.EaseElasticIn._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseElasticOut, base<EaseElastic>>("cc.EaseElasticOut")
    .constructor(&cc_bindings_constructor<EaseElasticOut>, allow_raw_pointers())
    .class_function("create", &EaseElasticOut::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](ActionInterval* arg0){
        return EaseElasticOut::create(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const EaseElasticOut& _) -> std::string {return "EaseElasticOut";}))    
    .allow_subclass<wrapper<EaseElasticOut>>("cc.EaseElasticOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseElasticInOut, base<EaseElastic>>("cc.EaseElasticInOut")
    .constructor(&cc_bindings_constructor<EaseElasticInOut>, allow_raw_pointers())
    .class_function("create", &EaseElasticInOut::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](ActionInterval* arg0){
        return EaseElasticInOut::create(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const EaseElasticInOut& _) -> std::string {return "EaseElasticInOut";}))    
    .allow_subclass<wrapper<EaseElasticInOut>>("cc.EaseElasticInOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<EaseBezierAction, base<ActionEase>>("cc.EaseBezierAction")
    .constructor(&cc_bindings_constructor<EaseBezierAction>, allow_raw_pointers())
    .function("setBezierParamer", &EaseBezierAction::setBezierParamer)
    .class_function("create", &EaseBezierAction::create, allow_raw_pointers())
    .property("_className",  optional_override([](const EaseBezierAction& _) -> std::string {return "EaseBezierAction";}))    
    .allow_subclass<wrapper<EaseBezierAction>>("cc.EaseBezierAction._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;

  class_<ActionInstant, base<FiniteTimeAction>>("cc.ActionInstant")
    .property("_className",  optional_override([](const ActionInstant& _) -> std::string {return "ActionInstant";}))    
    ;


  class_<Show, base<ActionInstant>>("cc.Show")
    .constructor(&cc_bindings_constructor<Show>, allow_raw_pointers())
    .class_function("create", &Show::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Show& _) -> std::string {return "Show";}))    
    .allow_subclass<wrapper<Show>>("cc.Show._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<Hide, base<ActionInstant>>("cc.Hide")
    .constructor(&cc_bindings_constructor<Hide>, allow_raw_pointers())
    .class_function("create", &Hide::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Hide& _) -> std::string {return "Hide";}))    
    .allow_subclass<wrapper<Hide>>("cc.Hide._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ToggleVisibility, base<ActionInstant>>("cc.ToggleVisibility")
    .constructor(&cc_bindings_constructor<ToggleVisibility>, allow_raw_pointers())
    .class_function("create", &ToggleVisibility::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ToggleVisibility& _) -> std::string {return "ToggleVisibility";}))    
    ;


  class_<RemoveSelf, base<ActionInstant>>("cc.RemoveSelf")
    .constructor(&cc_bindings_constructor<RemoveSelf>, allow_raw_pointers())
    .function("init", &RemoveSelf::init)
    .class_function("create", &RemoveSelf::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](){
        return RemoveSelf::create();
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const RemoveSelf& _) -> std::string {return "RemoveSelf";}))
    .allow_subclass<wrapper<RemoveSelf>>("cc.RemoveSelf._extend")    
    ;


  class_<FlipX, base<ActionInstant>>("cc.FlipX")
    .constructor(&cc_bindings_constructor<FlipX>, allow_raw_pointers())
    .function("initWithFlipX", &FlipX::initWithFlipX)
    .class_function("create", &FlipX::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FlipX& _) -> std::string {return "FlipX";}))    
    .allow_subclass<wrapper<FlipX>>("cc.FlipX._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<FlipY, base<ActionInstant>>("cc.FlipY")
    .constructor(&cc_bindings_constructor<FlipY>, allow_raw_pointers())
    .function("initWithFlipY", &FlipY::initWithFlipY)
    .class_function("create", &FlipY::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FlipY& _) -> std::string {return "FlipY";}))    
    .allow_subclass<wrapper<FlipY>>("cc.FlipY._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<Place, base<ActionInstant>>("cc.Place")
    .constructor(&cc_bindings_constructor<Place>, allow_raw_pointers())
    .function("initWithPosition", &Place::initWithPosition)
    .class_function("create", &Place::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Place& _) -> std::string {return "Place";}))    
    .allow_subclass<wrapper<Place>>("cc.Place._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<CallFunc, base<ActionInstant>>("cc._CallFunc")
    .constructor(&cc_bindings_constructor<CallFunc>, allow_raw_pointers())
    .function("execute", &CallFunc::execute)
    .property("_className",  optional_override([](const CallFunc& _) -> std::string {return "CallFunc";}))    
    .allow_subclass<wrapper<CallFunc>>("cc._CallFunc._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<CallFuncN, base<CallFunc>>("cc.CallFunc")
    .constructor(&cc_bindings_constructor<CallFuncN>, allow_raw_pointers())
    .property("_className",  optional_override([](const CallFuncN& _) -> std::string {return "CallFuncN";}))    
    .allow_subclass<wrapper<CallFuncN>>("cc.CallFunc._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;

  class_<GridAction, base<ActionInterval>>("cc.GridAction")
    .function("getGrid", &GridAction::getGrid, allow_raw_pointers())
    .function("initWithDuration", &GridAction::initWithDuration)
    .property("_className",  optional_override([](const GridAction& _) -> std::string {return "GridAction";}))
    .allow_subclass<wrapper<GridAction>>("cc.GridAction._extend")    
    ;

  class_<Grid3DAction, base<GridAction>>("cc.Grid3DAction")
    .function("getGridRect", &Grid3DAction::getGridRect)
    .property("_className",  optional_override([](const Grid3DAction& _) -> std::string {return "Grid3DAction";}))
    .allow_subclass<wrapper<Grid3DAction>>("cc.Grid3DAction._extend")    
    ;

  class_<TiledGrid3DAction, base<GridAction>>("cc.TiledGrid3DAction")
    .property("_className",  optional_override([](const TiledGrid3DAction& _) -> std::string {return "TiledGrid3DAction";}))
    .allow_subclass<wrapper<TiledGrid3DAction>>("cc.TiledGrid3DAction._extend")    
    ;


  class_<StopGrid, base<ActionInstant>>("cc.StopGrid")
    .constructor(&cc_bindings_constructor<StopGrid>, allow_raw_pointers())
    .class_function("create", &StopGrid::create, allow_raw_pointers())
    .property("_className",  optional_override([](const StopGrid& _) -> std::string {return "StopGrid";}))    
    ;


  class_<ReuseGrid, base<ActionInstant>>("cc.ReuseGrid")
    .constructor(&cc_bindings_constructor<ReuseGrid>, allow_raw_pointers())
    .function("initWithTimes", &ReuseGrid::initWithTimes)
    .class_function("create", &ReuseGrid::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ReuseGrid& _) -> std::string {return "ReuseGrid";}))
    .allow_subclass<wrapper<ReuseGrid>>("cc.ReuseGrid._extend")    
    ;


  class_<Waves3D, base<Grid3DAction>>("cc.Waves3D")
    .constructor(&cc_bindings_constructor<Waves3D>, allow_raw_pointers())
    .function("setAmplitudeRate", &Waves3D::setAmplitudeRate)
    .function("initWithDuration", &Waves3D::initWithDuration)
    .function("getAmplitude", &Waves3D::getAmplitude)
    .function("getAmplitudeRate", &Waves3D::getAmplitudeRate)
    .function("setAmplitude", &Waves3D::setAmplitude)
    .class_function("create", &Waves3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Waves3D& _) -> std::string {return "Waves3D";}))
    .allow_subclass<wrapper<Waves3D>>("cc.Waves3D._extend")    
    ;


  class_<FlipX3D, base<Grid3DAction>>("cc.FlipX3D")
    .constructor(&cc_bindings_constructor<FlipX3D>, allow_raw_pointers())
    .function("initWithSize", &FlipX3D::initWithSize)
    .function("initWithDuration", &FlipX3D::initWithDuration)
    .class_function("create", &FlipX3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FlipX3D& _) -> std::string {return "FlipX3D";}))    
    .allow_subclass<wrapper<FlipX3D>>("cc.FlipX3D._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<FlipY3D, base<FlipX3D>>("cc.FlipY3D")
    .constructor(&cc_bindings_constructor<FlipY3D>, allow_raw_pointers())
    .class_function("create", &FlipY3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FlipY3D& _) -> std::string {return "FlipY3D";}))    
    .allow_subclass<wrapper<FlipY3D>>("cc.FlipY3D._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<Lens3D, base<Grid3DAction>>("cc.Lens3D")
    .constructor(&cc_bindings_constructor<Lens3D>, allow_raw_pointers())
    .function("setConcave", &Lens3D::setConcave)
    .function("initWithDuration", &Lens3D::initWithDuration)
    .function("setLensEffect", &Lens3D::setLensEffect)
    .function("getLensEffect", &Lens3D::getLensEffect)
    .function("setPosition", &Lens3D::setPosition)
    .function("getPosition", &Lens3D::getPosition)
    .class_function("create", &Lens3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Lens3D& _) -> std::string {return "Lens3D";}))
    .allow_subclass<wrapper<Lens3D>>("cc.Lens3D._extend")    
    ;


  class_<Ripple3D, base<Grid3DAction>>("cc.Ripple3D")
    .constructor(&cc_bindings_constructor<Ripple3D>, allow_raw_pointers())
    .function("setAmplitudeRate", &Ripple3D::setAmplitudeRate)
    .function("initWithDuration", &Ripple3D::initWithDuration)
    .function("getAmplitudeRate", &Ripple3D::getAmplitudeRate)
    .function("setAmplitude", &Ripple3D::setAmplitude)
    .function("getAmplitude", &Ripple3D::getAmplitude)
    .function("setPosition", &Ripple3D::setPosition)
    .function("getPosition", &Ripple3D::getPosition)
    .class_function("create", &Ripple3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Ripple3D& _) -> std::string {return "Ripple3D";}))
    .allow_subclass<wrapper<Ripple3D>>("cc.Ripple3D._extend")    
    ;


  class_<Shaky3D, base<Grid3DAction>>("cc.Shaky3D")
    .constructor(&cc_bindings_constructor<Shaky3D>, allow_raw_pointers())
    .function("initWithDuration", &Shaky3D::initWithDuration)
    .class_function("create", &Shaky3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Shaky3D& _) -> std::string {return "Shaky3D";}))
    .allow_subclass<wrapper<Shaky3D>>("cc.Shaky3D._extend")    
    ;


  class_<Liquid, base<Grid3DAction>>("cc.Liquid")
    .constructor(&cc_bindings_constructor<Liquid>, allow_raw_pointers())
    .function("setAmplitudeRate", &Liquid::setAmplitudeRate)
    .function("initWithDuration", &Liquid::initWithDuration)
    .function("getAmplitude", &Liquid::getAmplitude)
    .function("getAmplitudeRate", &Liquid::getAmplitudeRate)
    .function("setAmplitude", &Liquid::setAmplitude)
    .class_function("create", &Liquid::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Liquid& _) -> std::string {return "Liquid";}))
    .allow_subclass<wrapper<Liquid>>("cc.Liquid._extend")    
    ;


  class_<Waves, base<Grid3DAction>>("cc.Waves")
    .constructor(&cc_bindings_constructor<Waves>, allow_raw_pointers())
    .function("setAmplitudeRate", &Waves::setAmplitudeRate)
    .function("initWithDuration", &Waves::initWithDuration)
    .function("getAmplitude", &Waves::getAmplitude)
    .function("getAmplitudeRate", &Waves::getAmplitudeRate)
    .function("setAmplitude", &Waves::setAmplitude)
    .class_function("create", &Waves::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Waves& _) -> std::string {return "Waves";}))
    .allow_subclass<wrapper<Waves>>("cc.Waves._extend")    
    ;


  class_<Twirl, base<Grid3DAction>>("cc.Twirl")
    .constructor(&cc_bindings_constructor<Twirl>, allow_raw_pointers())
    .function("setAmplitudeRate", &Twirl::setAmplitudeRate)
    .function("initWithDuration", &Twirl::initWithDuration)
    .function("getAmplitudeRate", &Twirl::getAmplitudeRate)
    .function("setAmplitude", &Twirl::setAmplitude)
    .function("getAmplitude", &Twirl::getAmplitude)
    .function("setPosition", &Twirl::setPosition)
    .function("getPosition", &Twirl::getPosition)
    .class_function("create", &Twirl::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Twirl& _) -> std::string {return "Twirl";}))
    .allow_subclass<wrapper<Twirl>>("cc.Twirl._extend")    
    ;


  class_<ActionManager>("cc.ActionManager")
    .constructor(&cc_bindings_constructor<ActionManager>, allow_raw_pointers())
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
    .property("_className",  optional_override([](const ActionManager& _) -> std::string {return "ActionManager";}))    
    .allow_subclass<wrapper<ActionManager>>("cc.ActionManager._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;

  class_<PageTurn3D, base<Grid3DAction>>("cc.PageTurn3D")
    .class_function("create", &PageTurn3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const PageTurn3D& _) -> std::string {return "PageTurn3D";}))
    .allow_subclass<wrapper<PageTurn3D>>("cc.PageTurn3D._extend")    
    ;


  class_<ProgressTo, base<ActionInterval>>("cc.ProgressTo")
    .constructor(&cc_bindings_constructor<ProgressTo>, allow_raw_pointers())
    .function("initWithDuration", &ProgressTo::initWithDuration)
    .class_function("create", &ProgressTo::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ProgressTo& _) -> std::string {return "ProgressTo";}))    
    .allow_subclass<wrapper<ProgressTo>>("cc.ProgressTo._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ProgressFromTo, base<ActionInterval>>("cc.ProgressFromTo")
    .constructor(&cc_bindings_constructor<ProgressFromTo>, allow_raw_pointers())
    .function("initWithDuration", &ProgressFromTo::initWithDuration)
    .class_function("create", &ProgressFromTo::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ProgressFromTo& _) -> std::string {return "ProgressFromTo";}))    
    .allow_subclass<wrapper<ProgressFromTo>>("cc.ProgressFromTo._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ShakyTiles3D, base<TiledGrid3DAction>>("cc.ShakyTiles3D")
    .constructor(&cc_bindings_constructor<ShakyTiles3D>, allow_raw_pointers())
    .function("initWithDuration", &ShakyTiles3D::initWithDuration)
    .class_function("create", &ShakyTiles3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ShakyTiles3D& _) -> std::string {return "ShakyTiles3D";}))
    .allow_subclass<wrapper<ShakyTiles3D>>("cc.ShakyTiles3D._extend")    
    ;


  class_<ShatteredTiles3D, base<TiledGrid3DAction>>("cc.ShatteredTiles3D")
    .constructor(&cc_bindings_constructor<ShatteredTiles3D>, allow_raw_pointers())
    .function("initWithDuration", &ShatteredTiles3D::initWithDuration)
    .class_function("create", &ShatteredTiles3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ShatteredTiles3D& _) -> std::string {return "ShatteredTiles3D";}))
    .allow_subclass<wrapper<ShatteredTiles3D>>("cc.ShatteredTiles3D._extend")    
    ;


  class_<ShuffleTiles, base<TiledGrid3DAction>>("cc.ShuffleTiles")
    .constructor(&cc_bindings_constructor<ShuffleTiles>, allow_raw_pointers())
    .function("placeTile", &ShuffleTiles::placeTile, allow_raw_pointers())
    .function("shuffle", &ShuffleTiles::shuffle, allow_raw_pointers())
    .function("initWithDuration", &ShuffleTiles::initWithDuration)
    .function("getDelta", &ShuffleTiles::getDelta)
    .class_function("create", &ShuffleTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ShuffleTiles& _) -> std::string {return "ShuffleTiles";}))
    .allow_subclass<wrapper<ShuffleTiles>>("cc.ShuffleTiles._extend")    
    ;


  class_<FadeOutTRTiles, base<TiledGrid3DAction>>("cc.FadeOutTRTiles")
    .constructor(&cc_bindings_constructor<FadeOutTRTiles>, allow_raw_pointers())
    .function("turnOnTile", &FadeOutTRTiles::turnOnTile)
    .function("turnOffTile", &FadeOutTRTiles::turnOffTile)
    .function("transformTile", &FadeOutTRTiles::transformTile)
    .function("testFunc", &FadeOutTRTiles::testFunc)
    .class_function("create", &FadeOutTRTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeOutTRTiles& _) -> std::string {return "FadeOutTRTiles";}))    
    .allow_subclass<wrapper<FadeOutTRTiles>>("cc.FadeOutTRTiles._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<FadeOutBLTiles, base<FadeOutTRTiles>>("cc.FadeOutBLTiles")
    .constructor(&cc_bindings_constructor<FadeOutBLTiles>, allow_raw_pointers())
    .class_function("create", &FadeOutBLTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeOutBLTiles& _) -> std::string {return "FadeOutBLTiles";}))    
    .allow_subclass<wrapper<FadeOutBLTiles>>("cc.FadeOutBLTiles._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<FadeOutUpTiles, base<FadeOutTRTiles>>("cc.FadeOutUpTiles")
    .constructor(&cc_bindings_constructor<FadeOutUpTiles>, allow_raw_pointers())
    .class_function("create", &FadeOutUpTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeOutUpTiles& _) -> std::string {return "FadeOutUpTiles";}))    
    .allow_subclass<wrapper<FadeOutUpTiles>>("cc.FadeOutUpTiles._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<FadeOutDownTiles, base<FadeOutUpTiles>>("cc.FadeOutDownTiles")
    .constructor(&cc_bindings_constructor<FadeOutDownTiles>, allow_raw_pointers())
    .class_function("create", &FadeOutDownTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const FadeOutDownTiles& _) -> std::string {return "FadeOutDownTiles";}))    
    .allow_subclass<wrapper<FadeOutDownTiles>>("cc.FadeOutDownTiles._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TurnOffTiles, base<TiledGrid3DAction>>("cc.TurnOffTiles")
    .constructor(&cc_bindings_constructor<TurnOffTiles>, allow_raw_pointers())
    .function("turnOnTile", &TurnOffTiles::turnOnTile)
    .function("turnOffTile", &TurnOffTiles::turnOffTile)
    .function("shuffle", &TurnOffTiles::shuffle, allow_raw_pointers())
    .function("initWithDuration", &TurnOffTiles::initWithDuration)
    .class_function("create", select_overload<TurnOffTiles*(float, const Size&, unsigned int)>(&TurnOffTiles::create), allow_raw_pointers())
    .class_function("create", select_overload<TurnOffTiles*(float, const Size&)>(&TurnOffTiles::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TurnOffTiles& _) -> std::string {return "TurnOffTiles";}))
    .allow_subclass<wrapper<TurnOffTiles>>("cc.TurnOffTiles._extend")    
    ;


  class_<WavesTiles3D, base<TiledGrid3DAction>>("cc.WavesTiles3D")
    .constructor(&cc_bindings_constructor<WavesTiles3D>, allow_raw_pointers())
    .function("setAmplitudeRate", &WavesTiles3D::setAmplitudeRate)
    .function("initWithDuration", &WavesTiles3D::initWithDuration)
    .function("getAmplitude", &WavesTiles3D::getAmplitude)
    .function("getAmplitudeRate", &WavesTiles3D::getAmplitudeRate)
    .function("setAmplitude", &WavesTiles3D::setAmplitude)
    .class_function("create", &WavesTiles3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const WavesTiles3D& _) -> std::string {return "WavesTiles3D";}))
    .allow_subclass<wrapper<WavesTiles3D>>("cc.WavesTiles3D._extend")    
    ;


  class_<JumpTiles3D, base<TiledGrid3DAction>>("cc.JumpTiles3D")
    .constructor(&cc_bindings_constructor<JumpTiles3D>, allow_raw_pointers())
    .function("setAmplitudeRate", &JumpTiles3D::setAmplitudeRate)
    .function("initWithDuration", &JumpTiles3D::initWithDuration)
    .function("getAmplitude", &JumpTiles3D::getAmplitude)
    .function("getAmplitudeRate", &JumpTiles3D::getAmplitudeRate)
    .function("setAmplitude", &JumpTiles3D::setAmplitude)
    .class_function("create", &JumpTiles3D::create, allow_raw_pointers())
    .property("_className",  optional_override([](const JumpTiles3D& _) -> std::string {return "JumpTiles3D";}))    
    .allow_subclass<wrapper<JumpTiles3D>>("cc.JumpTiles3D._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<SplitRows, base<TiledGrid3DAction>>("cc.SplitRows")
    .constructor(&cc_bindings_constructor<SplitRows>, allow_raw_pointers())
    .function("initWithDuration", &SplitRows::initWithDuration)
    .class_function("create", &SplitRows::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SplitRows& _) -> std::string {return "SplitRows";}))
    .allow_subclass<wrapper<SplitRows>>("cc.SplitRows._extend")    
    ;


  class_<SplitCols, base<TiledGrid3DAction>>("cc.SplitCols")
    .constructor(&cc_bindings_constructor<SplitCols>, allow_raw_pointers())
    .function("initWithDuration", &SplitCols::initWithDuration)
    .class_function("create", &SplitCols::create, allow_raw_pointers())
    .property("_className",  optional_override([](const SplitCols& _) -> std::string {return "SplitCols";}))
    .allow_subclass<wrapper<SplitCols>>("cc.SplitCols._extend")    
    ;

  class_<ActionTween, base<ActionInterval>>("cc.ActionTween")
    .constructor(&cc_bindings_constructor<ActionTween>, allow_raw_pointers())
    .function("initWithDuration", &ActionTween::initWithDuration)
    .class_function("create", &ActionTween::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ActionTween& _) -> std::string {return "ActionTween";}))    
    .allow_subclass<wrapper<ActionTween>>("cc.ActionTween._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<AtlasNode, base<Node>>("cc.AtlasNode")
    .constructor(&cc_bindings_constructor<AtlasNode>, allow_raw_pointers())
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
    .property("texture", &AtlasNode::getTexture, &AtlasNode::setTexture)
    .property("textureAtlas", &AtlasNode::getTextureAtlas, &AtlasNode::setTextureAtlas)
    .property("quadsToDraw", &AtlasNode::getQuadsToDraw, &AtlasNode::setQuadsToDraw)
    .class_function("create", &AtlasNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AtlasNode& _) -> std::string {return "AtlasNode";}))
    .allow_subclass<wrapper<AtlasNode>>("cc.AtlasNode._extend")    
    ;


  class_<ClippingNode, base<Node>>("cc.ClippingNode")
    .constructor(&cc_bindings_constructor<ClippingNode>, allow_raw_pointers())
    .function("hasContent", &ClippingNode::hasContent)
    .function("setInverted", &ClippingNode::setInverted)
    .function("setStencil", &ClippingNode::setStencil, allow_raw_pointers())
    .function("getAlphaThreshold", &ClippingNode::getAlphaThreshold)
    .function("getStencil", &ClippingNode::getStencil, allow_raw_pointers())
    .function("setAlphaThreshold", &ClippingNode::setAlphaThreshold)
    .function("isInverted", &ClippingNode::isInverted)
    .property("alphaThreshold", &ClippingNode::getAlphaThreshold, &ClippingNode::setAlphaThreshold)
    .property("inverted", &ClippingNode::isInverted, &ClippingNode::setInverted)
    .property("stencil", &ClippingNode::getStencil, &ClippingNode::setStencil)
    .class_function("create", select_overload<ClippingNode*(Node*)>(&ClippingNode::create), allow_raw_pointers())
    .class_function("create", select_overload<ClippingNode*()>(&ClippingNode::create), allow_raw_pointers())
    .property("_className",  optional_override([](const ClippingNode& _) -> std::string {return "ClippingNode";}))
    .allow_subclass<wrapper<ClippingNode>>("cc.ClippingNode._extend")    
    ;


  class_<DrawNode, base<Node>>("cc.DrawNode")
    .constructor(&cc_bindings_constructor<DrawNode>, allow_raw_pointers())
    .function("drawLine", &DrawNode::drawLine)
    .function("drawPoints", select_overload<void(const Vec2*, unsigned int, const float, const Color4F&)>(&DrawNode::drawPoints), allow_raw_pointers())
    .function("drawPoints", select_overload<void(const Vec2*, unsigned int, const Color4F&)>(&DrawNode::drawPoints), allow_raw_pointers())
    .function("setIsolated", &DrawNode::setIsolated)
    .function("drawRect", select_overload<void(const Vec2&, const Vec2&, const Vec2&, const Vec2&, const Color4F&)>(&DrawNode::drawRect))
    .function("drawRect", select_overload<void(const Vec2&, const Vec2&, const Color4F&)>(&DrawNode::drawRect))
    .function("drawSolidCircle", select_overload<void(const Vec2&, float, float, unsigned int, const Color4F&)>(&DrawNode::drawSolidCircle))
    .function("drawSolidCircle", select_overload<void(const Vec2&, float, float, unsigned int, float, float, const Color4F&)>(&DrawNode::drawSolidCircle))
    .function("setLineWidth", &DrawNode::setLineWidth)
    .function("onDrawGLPoint", &DrawNode::onDrawGLPoint)
    .function("drawPolygon", &DrawNode::drawPolygon, allow_raw_pointers())
    .function("drawDot", &DrawNode::drawDot)
    .function("drawCatmullRom", &DrawNode::drawCatmullRom, allow_raw_pointers())
    .function("drawSegment", &DrawNode::drawSegment)
    .function("getBlendFunc", &DrawNode::getBlendFunc)
    .function("onDraw", &DrawNode::onDraw)
    .function("drawCircle", select_overload<void(const Vec2&, float, float, unsigned int, bool, const Color4F&)>(&DrawNode::drawCircle))
    .function("drawCircle", select_overload<void(const Vec2&, float, float, unsigned int, bool, float, float, const Color4F&)>(&DrawNode::drawCircle))
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
    .class_function("create", &DrawNode::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](){
        return DrawNode::create();
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const DrawNode& _) -> std::string {return "DrawNode";}))    
    .allow_subclass<wrapper<DrawNode>>("cc.DrawNode._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<Label, base<Node>>("cc.Label")
    .constructor(&cc_bindings_constructor<Label>, allow_raw_pointers())
    .function("isClipMarginEnabled", &Label::isClipMarginEnabled)
    .function("enableShadow", &Label::enableShadow)
    .function("enableShadow", optional_override(
        [](Label& this_){
        return this_.enableShadow();
      }))
    .function("enableShadow", optional_override(
        [](Label& this_, const Color4B& arg0){
        return this_.enableShadow(arg0);
      }))
    .function("enableShadow", optional_override(
        [](Label& this_, const Color4B& arg0, const Size& arg1){
        return this_.enableShadow(arg0, arg1);
      }))
    .function("setDimensions", &Label::setDimensions)
    .function("getWidth", &Label::getWidth)
    .function("getString", &Label::getString)
    .function("getHeight", &Label::getHeight)
    .function("disableEffect", select_overload<void(LabelEffect)>(&Label::disableEffect))
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
    .function("setBMFontFilePath", select_overload<bool(const std::string&, const Rect&, bool, float)>(&Label::setBMFontFilePath))
    // TODO: Only support function overloading with different number of parameters
    .function("setBMFontFilePath", select_overload<bool(const std::string&, float)>(&Label::setBMFontFilePath))
    // TODO: Only support function overloading with different number of parameters
    .function("setBMFontFilePath", select_overload<bool(const std::string&, const std::string&, float)>(&Label::setBMFontFilePath))
    // TODO: Only support function overloading with different number of parameters
    .function("initWithTTF", select_overload<bool(const _ttfConfig&, const std::string&, TextHAlignment, int)>(&Label::initWithTTF))
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .function("initWithTTF", select_overload<bool(const std::string&, const std::string&, float, const Size&, TextHAlignment, TextVAlignment)>(&Label::initWithTTF))
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
        [](Label& this_, const Color4B& arg0){
        return this_.enableOutline(arg0);
      }))
    .function("getShadowBlurRadius", &Label::getShadowBlurRadius)
    .function("getEffectColor", &Label::getEffectColor)
    .function("removeAllChildrenWithCleanup", &Label::removeAllChildrenWithCleanup)
    .function("setCharMap", select_overload<bool(Texture2D*, int, int, int)>(&Label::setCharMap), allow_raw_pointers())
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
    .function("setAlignment", select_overload<void(TextHAlignment, TextVAlignment)>(&Label::setAlignment))
    .function("setAlignment", select_overload<void(TextHAlignment)>(&Label::setAlignment))
    .function("requestSystemFontRefresh", &Label::requestSystemFontRefresh)
    .function("setBMFontSize", &Label::setBMFontSize)
    .property("size", &Label::getContentSize, &Label::setContentSize)
    .property("boundingWidth", &Label::getWidth, &Label::setWidth)
    .property("boundingHeight", &Label::getHeight, &Label::setHeight)
    .class_function("createWithBMFont", select_overload<Label*(const std::string&, const std::string&, const TextHAlignment&, int, const Rect&, bool)>(&Label::createWithBMFont), allow_raw_pointers())
    .class_function("createWithBMFont", select_overload<Label*(const std::string&, const std::string&, const TextHAlignment&, int)>(&Label::createWithBMFont), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithBMFont", select_overload<Label*(const std::string&, const std::string&, const TextHAlignment&, int, const std::string&)>(&Label::createWithBMFont), allow_raw_pointers())
    .class_function("createWithCharMap", select_overload<Label*(Texture2D*, int, int, int)>(&Label::createWithCharMap), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithCharMap", select_overload<Label*(const std::string&)>(&Label::createWithCharMap), allow_raw_pointers())
    .class_function("createWithSystemFont", &Label::createWithSystemFont, allow_raw_pointers())
    .class_function("createWithSystemFont", optional_override(
      [](const std::string& arg0, const std::string& arg1, float arg2){
        return Label::createWithSystemFont(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .class_function("createWithSystemFont", optional_override(
      [](const std::string& arg0, const std::string& arg1, float arg2, const Size& arg3){
        return Label::createWithSystemFont(arg0, arg1, arg2, arg3);
      }), allow_raw_pointers())
    .class_function("createWithSystemFont", optional_override(
      [](const std::string& arg0, const std::string& arg1, float arg2, const Size& arg3, TextHAlignment arg4){
        return Label::createWithSystemFont(arg0, arg1, arg2, arg3, arg4);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const Label& _) -> std::string {return "Label";}))    
    .allow_subclass<wrapper<Label>>("cc.Label._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<LabelAtlas, base<AtlasNode>>("cc.LabelAtlas")
    .constructor(&cc_bindings_constructor<LabelAtlas>, allow_raw_pointers())
    .function("setString", &LabelAtlas::setString)
    .function("initWithString", select_overload<bool(const std::string&, const std::string&)>(&LabelAtlas::initWithString))
    .function("initWithString", select_overload<bool(const std::string&, const std::string&, int, int, int)>(&LabelAtlas::initWithString))
    // TODO: Only support function overloading with different number of parameters
    .function("getString", &LabelAtlas::getString)
    .property("string", &LabelAtlas::getString, &LabelAtlas::setString)
    .class_function("_create", select_overload<LabelAtlas*(const std::string&, const std::string&, int, int, int)>(&LabelAtlas::create), allow_raw_pointers())
    .class_function("_create", select_overload<LabelAtlas*()>(&LabelAtlas::create), allow_raw_pointers())
    .class_function("_create", select_overload<LabelAtlas*(const std::string&, const std::string&)>(&LabelAtlas::create), allow_raw_pointers())
    .property("_className",  optional_override([](const LabelAtlas& _) -> std::string {return "LabelAtlas";}))    
    .allow_subclass<wrapper<LabelAtlas>>("cc.LabelAtlas._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<LabelBMFont, base<Node>>("cc.LabelBMFont")
    .constructor(&cc_bindings_constructor<LabelBMFont>, allow_raw_pointers())
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
        [](LabelBMFont& this_, const std::string& arg0, const std::string& arg1, float arg2, TextHAlignment arg3){
        return this_.initWithString(arg0, arg1, arg2, arg3);
      }))
    .function("getFntFile", &LabelBMFont::getFntFile)
    .function("setFntFile", select_overload<void(const std::string&, const Rect&, bool)>(&LabelBMFont::setFntFile))
    .function("setFntFile", select_overload<void(const std::string&, const Vec2&)>(&LabelBMFont::setFntFile))
    // TODO: Only support function overloading with different number of parameters
    .function("setAlignment", &LabelBMFont::setAlignment)
    .function("setWidth", &LabelBMFont::setWidth)
    .property("string", &LabelBMFont::getString, &LabelBMFont::setString)
    .property("textAlign",
      optional_override([](const LabelBMFont& this_)
      {
        CCLOG("LabelBMFont.textAlign is write-only");
        return TextHAlignment::LEFT;
      }), 
      optional_override([](LabelBMFont& this_, TextHAlignment alignment)
      {
        this_.setAlignment(alignment);
      }))
    .property("boundingWidth", 
      optional_override([](const LabelBMFont& this_) -> float
      {
        CCLOG("LabelBMFont.boundingWidth is write-only");
        return 0;
      }), 
      optional_override([](LabelBMFont& this_, float width)
      {
        return this_.setWidth(width);
      }))
    // .property("boundingHeight", &LabelBMFont::_getBoundingHeight, &LabelBMFont::setBoundingHeight)
    .class_function("create", select_overload<LabelBMFont*()>(&LabelBMFont::create), allow_raw_pointers())
    .class_function("create", select_overload<LabelBMFont*(const std::string&, const std::string&, float, TextHAlignment, const Vec2&)>(&LabelBMFont::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const LabelBMFont& _) -> std::string {return "LabelBMFont";}))    
    .allow_subclass<wrapper<LabelBMFont>>("cc.LabelBMFont._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<LabelTTF, base<Node>>("cc.LabelTTF")
    .constructor(&cc_bindings_constructor<LabelTTF>, allow_raw_pointers())
    .function("enableShadow", &LabelTTF::enableShadow)
    .function("enableShadow", optional_override(
        [](LabelTTF& this_, const Size& arg0, float arg1, float arg2){
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
        [](LabelTTF& this_, const std::string& arg0, const std::string& arg1, float arg2, const Size& arg3){
        return this_.initWithString(arg0, arg1, arg2, arg3);
      }))
    .function("initWithString", optional_override(
        [](LabelTTF& this_, const std::string& arg0, const std::string& arg1, float arg2, const Size& arg3, TextHAlignment arg4){
        return this_.initWithString(arg0, arg1, arg2, arg3, arg4);
      }))
    .function("setFontFillColor", &LabelTTF::setFontFillColor)
    .function("setFontFillColor", optional_override(
        [](LabelTTF& this_, const Color3B& arg0){
        return this_.setFontFillColor(arg0);
      }))
    .function("getBlendFunc", &LabelTTF::getBlendFunc)
    .function("enableStroke", &LabelTTF::enableStroke)
    .function("enableStroke", optional_override(
        [](LabelTTF& this_, const Color3B& arg0, float arg1){
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
    .property("string", &LabelTTF::getString, &LabelTTF::setString)
    .property("textAlign", &LabelTTF::getHorizontalAlignment, &LabelTTF::setHorizontalAlignment)
    .property("verticalAlign", &LabelTTF::getVerticalAlignment, &LabelTTF::setVerticalAlignment)
    .property("fontSize", &LabelTTF::getFontSize, &LabelTTF::setFontSize)
    .property("fontName", &LabelTTF::getFontName, &LabelTTF::setFontName)
    .property("font", optional_override(
        [](const LabelTTF& this_) -> std::string {
        float size = this_.getFontSize();
        const std::string& name = this_.getFontName();
        return std::to_string(size) + "px '" + name + "'";
      })
      , optional_override(
        [](LabelTTF& this_, const std::string& font) { 
        size_t found = font.find("px ");
        if (found != std::string::npos)
        {
          this_.setFontSize(stoi(font.substr(0, found)));
          this_.setFontName(font.substr(found + 4, font.size() - found - 5));  
        } else 
        {
          CCLOG("Failed to parse font '%s'", font.c_str());
        }
      })
      )
    .property("boundingWidth", 
      optional_override([](const LabelTTF& this_){return this_.getDimensions().width;}), 
      optional_override([](LabelTTF& this_, float width){this_.setDimensions(Size(width, this_.getDimensions().height));}))
    .property("boundingHeight", 
      optional_override([](const LabelTTF& this_){return this_.getDimensions().height;}), 
      optional_override([](LabelTTF& this_, float height){this_.setDimensions(Size(this_.getDimensions().width, height));}))
    .property("fillStyle", optional_override(
        [](const LabelTTF& this_) {
        CCLOG("LabelTTF.fillStyle is write-only");
        return Color3B::BLACK;
      }), optional_override(
        [](LabelTTF& this_, const Color3B &tintColor) { 
        this_.setFontFillColor(tintColor);
      }))
    // .property("strokeStyle", &LabelTTF::_getStrokeStyle, &LabelTTF::_setStrokeStyle)
    // .property("lineWidth", &LabelTTF::_getLineWidth, &LabelTTF::_setLineWidth)
    // .property("shadowOffsetX", &LabelTTF::_getShadowOffsetX, &LabelTTF::_setShadowOffsetX)
    // .property("shadowOffsetY", &LabelTTF::_getShadowOffsetY, &LabelTTF::_setShadowOffsetY)
    // .property("shadowOpacity", &LabelTTF::_getShadowOpacity, &LabelTTF::_setShadowOpacity)
    // .property("shadowBlur", &LabelTTF::_getShadowBlur, &LabelTTF::_setShadowBlur)
    .class_function("create", select_overload<LabelTTF*()>(&LabelTTF::create), allow_raw_pointers())
    .class_function("create", select_overload<LabelTTF*(const std::string&, const std::string&, float, const Size&, TextHAlignment, TextVAlignment)>(&LabelTTF::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithFontDefinition", &LabelTTF::createWithFontDefinition, allow_raw_pointers())
    .property("_className",  optional_override([](const LabelTTF& _) -> std::string {return "LabelTTF";}))    
    .allow_subclass<wrapper<LabelTTF>>("cc.LabelTTF._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<Layer, base<Node>>("cc.Layer")
    .constructor(&cc_bindings_constructor<Layer>, allow_raw_pointers())
    .class_function("create", &Layer::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Layer& _) -> std::string {return "Layer";}))    
    .allow_subclass<wrapper<Layer>>("cc.Layer._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<__LayerRGBA, base<Layer>>("cc.__LayerRGBA")
    .constructor(&cc_bindings_constructor<__LayerRGBA>, allow_raw_pointers())
    .class_function("create", &__LayerRGBA::create, allow_raw_pointers())
    .property("_className",  optional_override([](const __LayerRGBA& _) -> std::string {return "__LayerRGBA";}))
    ;


  class_<LayerColor, base<Layer>>("cc.LayerColor")
    .constructor(&cc_bindings_constructor<LayerColor>, allow_raw_pointers())
    .function("changeWidthAndHeight", &LayerColor::changeWidthAndHeight)
    .function("getBlendFunc", &LayerColor::getBlendFunc)
    .function("setBlendFunc", &LayerColor::setBlendFunc)
    .function("changeWidth", &LayerColor::changeWidth)
    .function("init", select_overload<bool(const Color4B&)>(&LayerColor::initWithColor))
    .function("init", select_overload<bool(const Color4B&, float, float)>(&LayerColor::initWithColor))
    .function("changeHeight", &LayerColor::changeHeight)
    .class_function("create", select_overload<LayerColor*(const Color4B&, float, float)>(&LayerColor::create), allow_raw_pointers())
    .class_function("create", select_overload<LayerColor*()>(&LayerColor::create), allow_raw_pointers())
    .class_function("create", select_overload<LayerColor*(const Color4B&)>(&LayerColor::create), allow_raw_pointers())
    .property("_className",  optional_override([](const LayerColor& _) -> std::string {return "LayerColor";}))    
    .allow_subclass<wrapper<LayerColor>>("cc.LayerColor._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<LayerGradient, base<LayerColor>>("cc.LayerGradient")
    .constructor(&cc_bindings_constructor<LayerGradient>, allow_raw_pointers())
    .function("getStartColor", &LayerGradient::getStartColor)
    .function("isCompressedInterpolation", &LayerGradient::isCompressedInterpolation)
    .function("getStartOpacity", &LayerGradient::getStartOpacity)
    .function("setVector", &LayerGradient::setVector)
    .function("setStartOpacity", &LayerGradient::setStartOpacity)
    .function("setCompressedInterpolation", &LayerGradient::setCompressedInterpolation)
    .function("setEndOpacity", &LayerGradient::setEndOpacity)
    .function("getVector", &LayerGradient::getVector)
    .function("setEndColor", &LayerGradient::setEndColor)
    .function("initWithColor", select_overload<bool(const Color4B&, const Color4B&, const Vec2&)>(&LayerGradient::initWithColor))
    .function("initWithColor", select_overload<bool(const Color4B&, const Color4B&)>(&LayerGradient::initWithColor))
    .function("getEndColor", &LayerGradient::getEndColor)
    .function("getEndOpacity", &LayerGradient::getEndOpacity)
    .function("setStartColor", &LayerGradient::setStartColor)
    .property("size", &LayerGradient::getContentSize, &LayerGradient::setContentSize)
    .property("startColor", &LayerGradient::getStartColor, &LayerGradient::setStartColor)
    .property("endColor", &LayerGradient::getEndColor, &LayerGradient::setEndColor)
    .property("startOpacity", &LayerGradient::getStartOpacity, &LayerGradient::setStartOpacity)
    .property("endOpacity", &LayerGradient::getEndOpacity, &LayerGradient::setEndOpacity)
    .property("vector", &LayerGradient::getVector, &LayerGradient::setVector)
    .property("compresseInterpolation", &LayerGradient::isCompressedInterpolation, &LayerGradient::setCompressedInterpolation)
    .class_function("create", select_overload<LayerGradient*(const Color4B&, const Color4B&)>(&LayerGradient::create), allow_raw_pointers())
    .class_function("create", select_overload<LayerGradient*()>(&LayerGradient::create), allow_raw_pointers())
    .class_function("create", select_overload<LayerGradient*(const Color4B&, const Color4B&, const Vec2&)>(&LayerGradient::create), allow_raw_pointers())
    .property("_className",  optional_override([](const LayerGradient& _) -> std::string {return "LayerGradient";}))    
    .allow_subclass<wrapper<LayerGradient>>("cc.LayerGradient._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<LayerRadialGradient, base<Layer>>("cc.LayerRadialGradient")
    .constructor(&cc_bindings_constructor<LayerRadialGradient>, allow_raw_pointers())
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
    .function("setEndColor", select_overload<void(const Color4B&)>(&LayerRadialGradient::setEndColor))
    // TODO: Only support function overloading with different number of parameters
    .function("getEndColor3B", &LayerRadialGradient::getEndColor3B)
    .function("setRadius", &LayerRadialGradient::setRadius)
    .function("setStartColor", select_overload<void(const Color4B&)>(&LayerRadialGradient::setStartColor))
    // TODO: Only support function overloading with different number of parameters
    .function("getExpand", &LayerRadialGradient::getExpand)
    .function("setBlendFunc", &LayerRadialGradient::setBlendFunc)
    .function("getRadius", &LayerRadialGradient::getRadius)
    .class_function("create", select_overload<LayerRadialGradient*()>(&LayerRadialGradient::create), allow_raw_pointers())
    .class_function("create", select_overload<LayerRadialGradient*(const Color4B&, const Color4B&, float, const Vec2&, float)>(&LayerRadialGradient::create), allow_raw_pointers())
    .property("_className",  optional_override([](const LayerRadialGradient& _) -> std::string {return "LayerRadialGradient";}))    
    .allow_subclass<wrapper<LayerRadialGradient>>("cc.LayerRadialGradient._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<LayerMultiplex, base<Layer>>("cc.LayerMultiplex")
    .constructor(&cc_bindings_constructor<LayerMultiplex>, allow_raw_pointers())
    .function("initWithArray", &LayerMultiplex::initWithArray)
    .function("switchToAndReleaseMe", &LayerMultiplex::switchToAndReleaseMe)
    .function("addLayer", &LayerMultiplex::addLayer, allow_raw_pointers())
    .function("switchTo", select_overload<void(int, bool)>(&LayerMultiplex::switchTo))
    .function("switchTo", select_overload<void(int)>(&LayerMultiplex::switchTo))
    .property("_className",  optional_override([](const LayerMultiplex& _) -> std::string {return "LayerMultiplex";}))    
    .allow_subclass<wrapper<LayerMultiplex>>("cc.LayerMultiplex._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<MenuItem, base<Node>>("cc.MenuItem")
    .constructor(&cc_bindings_constructor<MenuItem>, allow_raw_pointers())
    .function("setEnabled", &MenuItem::setEnabled)
    .function("activate", &MenuItem::activate)
    .function("initWithCallback", &MenuItem::initWithCallback)
    .function("isEnabled", &MenuItem::isEnabled)
    .function("selected", &MenuItem::selected)
    .function("isSelected", &MenuItem::isSelected)
    .function("setCallback", optional_override([](MenuItem& this_, const val& callback) {
      return this_.setCallback([callback](Ref* ref) -> void {
        callback(val(ref));
      });
    }))
    .function("unselected", &MenuItem::unselected)
    .function("rect", &MenuItem::rect)
    .property("enabled", &MenuItem::isEnabled, &MenuItem::setEnabled)
    .property("_className",  optional_override([](const MenuItem& _) -> std::string {return "MenuItem";}))    
    .allow_subclass<wrapper<MenuItem>>("cc.MenuItem._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<MenuItemLabel, base<MenuItem>>("cc.MenuItemLabel")
    .constructor(&cc_bindings_constructor<MenuItemLabel>, allow_raw_pointers())
    .function("initWithLabel", optional_override([](MenuItemLabel& this_, Node* label, const val& callback) {
      return this_.initWithLabel(label, [callback](Ref* ref) -> void {
        callback(val(ref));
      });
    }), allow_raw_pointers())
    .function("setLabel", &MenuItemLabel::setLabel, allow_raw_pointers())
    .function("getString", &MenuItemLabel::getString)
    .function("getDisabledColor", &MenuItemLabel::getDisabledColor)
    .function("setString", &MenuItemLabel::setString)
    .function("setDisabledColor", &MenuItemLabel::setDisabledColor)
    .function("getLabel", &MenuItemLabel::getLabel, allow_raw_pointers())
    .property("string", &MenuItemLabel::getString, &MenuItemLabel::setString)
    .property("label", &MenuItemLabel::getLabel, &MenuItemLabel::setLabel)
    .property("disabledColor", &MenuItemLabel::getDisabledColor, &MenuItemLabel::setDisabledColor)
    .property("_className",  optional_override([](const MenuItemLabel& _) -> std::string {return "MenuItemLabel";}))    
    .allow_subclass<wrapper<MenuItemLabel>>("cc.MenuItemLabel._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<MenuItemAtlasFont, base<MenuItemLabel>>("cc.MenuItemAtlasFont")
    .constructor(&cc_bindings_constructor<MenuItemAtlasFont>, allow_raw_pointers())
    .property("_className",  optional_override([](const MenuItemAtlasFont& _) -> std::string {return "MenuItemAtlasFont";}))    
    .allow_subclass<wrapper<MenuItemAtlasFont>>("cc.MenuItemAtlasFont._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<MenuItemFont, base<MenuItemLabel>>("cc.MenuItemFont")
    .constructor(&cc_bindings_constructor<MenuItemFont>, allow_raw_pointers())
    .property("fontSize", &MenuItemFont::getFontSizeObj, &MenuItemFont::setFontSizeObj)
    .property("fontName", &MenuItemFont::getFontNameObj, &MenuItemFont::setFontNameObj)
    .property("_className",  optional_override([](const MenuItemFont& _) -> std::string {return "MenuItemFont";}))
    .function("initWithString", optional_override([](MenuItemFont& this_, std::string value, const val& callback) {
      return this_.initWithString(value, [callback](Ref* ref) -> void {
        callback(val(ref));
      });
    }))
    .allow_subclass<wrapper<MenuItemFont>>("cc.MenuItemFont._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<MenuItemSprite, base<MenuItem>>("cc.MenuItemSprite")
    .constructor(&cc_bindings_constructor<MenuItemSprite>, allow_raw_pointers())
    .function("setEnabled", &MenuItemSprite::setEnabled)
    .function("selected", &MenuItemSprite::selected)
    .function("setNormalImage", &MenuItemSprite::setNormalImage, allow_raw_pointers())
    .function("setDisabledImage", &MenuItemSprite::setDisabledImage, allow_raw_pointers())
    // Don't understand why it is missing in auto-binding
    .function("initWithNormalSprite", optional_override([](MenuItemSprite& this_, Node* normalSprite, Node* selectedSprite, Node* disabledSprite, const val& callback) {
      return this_.initWithNormalSprite(normalSprite, selectedSprite, disabledSprite, [callback](Ref* ref) -> void {
        callback(val(ref));
      });
    }), allow_raw_pointers())
    .function("setSelectedImage", &MenuItemSprite::setSelectedImage, allow_raw_pointers())
    .function("getDisabledImage", &MenuItemSprite::getDisabledImage, allow_raw_pointers())
    .function("getSelectedImage", &MenuItemSprite::getSelectedImage, allow_raw_pointers())
    .function("getNormalImage", &MenuItemSprite::getNormalImage, allow_raw_pointers())
    .function("unselected", &MenuItemSprite::unselected)
    .property("normalImage", &MenuItemSprite::getNormalImage, &MenuItemSprite::setNormalImage)
    .property("selectedImage", &MenuItemSprite::getSelectedImage, &MenuItemSprite::setSelectedImage)
    .property("disabledImage", &MenuItemSprite::getDisabledImage, &MenuItemSprite::setDisabledImage)
    .property("_className",  optional_override([](const MenuItemSprite& _) -> std::string {return "MenuItemSprite";}))    
    .allow_subclass<wrapper<MenuItemSprite>>("cc.MenuItemSprite._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<MenuItemImage, base<MenuItemSprite>>("cc.MenuItemImage")
    .constructor(&cc_bindings_constructor<MenuItemImage>, allow_raw_pointers())
    .function("setDisabledSpriteFrame", &MenuItemImage::setDisabledSpriteFrame, allow_raw_pointers())
    .function("setSelectedSpriteFrame", &MenuItemImage::setSelectedSpriteFrame, allow_raw_pointers())
    .function("setNormalSpriteFrame", &MenuItemImage::setNormalSpriteFrame, allow_raw_pointers())
    .function("init", &MenuItemImage::init)
    .property("_className",  optional_override([](const MenuItemImage& _) -> std::string {return "MenuItemImage";}))    
    .allow_subclass<wrapper<MenuItemImage>>("cc.MenuItemImage._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<MenuItemToggle, base<MenuItem>>("cc.MenuItemToggle")
    .constructor(&cc_bindings_constructor<MenuItemToggle>, allow_raw_pointers())
    .function("setSubItems", &MenuItemToggle::setSubItems)
    .function("initWithItem", &MenuItemToggle::initWithItem, allow_raw_pointers())
    .function("getSelectedIndex", &MenuItemToggle::getSelectedIndex)
    .function("addSubItem", &MenuItemToggle::addSubItem, allow_raw_pointers())
    .function("getSelectedItem", &MenuItemToggle::getSelectedItem, allow_raw_pointers())
    .function("setSelectedIndex", &MenuItemToggle::setSelectedIndex)
    .property("_className",  optional_override([](const MenuItemToggle& _) -> std::string {return "MenuItemToggle";}))    
    .allow_subclass<wrapper<MenuItemToggle>>("cc.MenuItemToggle._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<Menu, base<Layer>>("cc.Menu")
    .constructor(&cc_bindings_constructor<Menu>, allow_raw_pointers())
    .function("initWithArray", &Menu::initWithArray)
    .function("setEnabled", &Menu::setEnabled)
    .function("alignItemsVertically", &Menu::alignItemsVertically)
    .function("isEnabled", &Menu::isEnabled)
    .function("alignItemsHorizontally", &Menu::alignItemsHorizontally)
    .function("alignItemsHorizontallyWithPadding", &Menu::alignItemsHorizontallyWithPadding)
    .function("alignItemsVerticallyWithPadding", &Menu::alignItemsVerticallyWithPadding)
    .property("enabled", &Menu::isEnabled, &Menu::setEnabled)
    .property("_className",  optional_override([](const Menu& _) -> std::string {return "Menu";}))    
    .allow_subclass<wrapper<Menu>>("cc.Menu._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<MotionStreak, base<Node>>("cc.MotionStreak")
    .constructor(&cc_bindings_constructor<MotionStreak>, allow_raw_pointers())
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
    .function("initWithFade", select_overload<bool(float, float, float, const Color3B&, Texture2D*)>(&MotionStreak::initWithFade), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setFastMode", &MotionStreak::setFastMode)
    .function("setStroke", &MotionStreak::setStroke)
    .class_function("create", select_overload<MotionStreak*(float, float, float, const Color3B&, Texture2D*)>(&MotionStreak::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const MotionStreak& _) -> std::string {return "MotionStreak";}))    
    .allow_subclass<wrapper<MotionStreak>>("cc.MotionStreak._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<NodeGrid, base<Node>>("cc.NodeGrid")
    .constructor(&cc_bindings_constructor<NodeGrid>, allow_raw_pointers())
    .function("setTarget", &NodeGrid::setTarget, allow_raw_pointers())
    .function("getGrid", select_overload<GridBase*()>(&NodeGrid::getGrid), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getGridRect", &NodeGrid::getGridRect)
    .property("grid", optional_override([](const NodeGrid& this_)
      {
        return const_cast<GridBase*>(this_.getGrid());
      }), &NodeGrid::setGrid)
    .property("target", optional_override([](const NodeGrid& this_)
      {
        CCLOG("NodeGrid.target is write-only");
        return nullptr;
      }), &NodeGrid::setTarget)
    .class_function("create", select_overload<NodeGrid*(const Rect&)>(&NodeGrid::create), allow_raw_pointers())
    .class_function("create", select_overload<NodeGrid*()>(&NodeGrid::create), allow_raw_pointers())
    .property("_className",  optional_override([](const NodeGrid& _) -> std::string {return "NodeGrid";}))    
    ;


  class_<ParticleBatchNode, base<Node>>("cc.ParticleBatchNode")
    .constructor(&cc_bindings_constructor<ParticleBatchNode>, allow_raw_pointers())
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
    .property("textureAtlas", &ParticleBatchNode::getTextureAtlas, &ParticleBatchNode::setTextureAtlas)
    .property("texture", &ParticleBatchNode::getTexture, &ParticleBatchNode::setTexture)
    .class_function("create", &ParticleBatchNode::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](const std::string& arg0){
        return ParticleBatchNode::create(arg0);
      }), allow_raw_pointers())
    .class_function("createWithTexture", &ParticleBatchNode::createWithTexture, allow_raw_pointers())
    .class_function("createWithTexture", optional_override(
      [](Texture2D* arg0){
        return ParticleBatchNode::createWithTexture(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleBatchNode& _) -> std::string {return "ParticleBatchNode";}))    
    .allow_subclass<wrapper<ParticleBatchNode>>("cc.ParticleBatchNode._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ParticleData>("cc.ParticleData")
    .constructor(&cc_bindings_constructor<ParticleData>, allow_raw_pointers())
    // TODO: Emscripten cannot automatically call destructor.
    .function("release", &ParticleData::release)
    .function("getMaxCount", &ParticleData::getMaxCount)
    .function("init", &ParticleData::init)
    .function("copyParticle", &ParticleData::copyParticle)
    .property("_className",  optional_override([](const ParticleData& _) -> std::string {return "ParticleData";}))    
    ;


  class_<ParticleSystem, base<Node>>("cc._ParticleSystem")
    .constructor(&cc_bindings_constructor<ParticleSystem>, allow_raw_pointers())
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
    .function("initWithDictionary", select_overload<bool(std::unordered_map<std::string, Value>&, const std::string&)>(&ParticleSystem::initWithDictionary))
    .function("initWithDictionary", select_overload<bool(std::unordered_map<std::string, Value>&)>(&ParticleSystem::initWithDictionary))
    .function("isAutoRemoveOnFinish", &ParticleSystem::isAutoRemoveOnFinish)
    .function("isSourcePositionCompatible", &ParticleSystem::isSourcePositionCompatible)
    .function("getTotalParticles", &ParticleSystem::getTotalParticles)
    .function("setStartRadiusVar", &ParticleSystem::setStartRadiusVar)
    .function("setBlendFunc", &ParticleSystem::setBlendFunc)
    .function("getEndRadiusVar", &ParticleSystem::getEndRadiusVar)
    .function("getStartColorVar", &ParticleSystem::getStartColorVar)
    .property("batchNode", &ParticleSystem::getBatchNode, &ParticleSystem::setBatchNode)
    .property("active", &ParticleSystem::isActive)
    // cocos2d-x js only
    // .property("shapeType", &ParticleSystem::getShapeType, &ParticleSystem::setShapeType)
    .property("atlasIndex", &ParticleSystem::getAtlasIndex, &ParticleSystem::setAtlasIndex)
    .property("particleCount", &ParticleSystem::getParticleCount)
    .property("duration", &ParticleSystem::getDuration, &ParticleSystem::setDuration)
    .property("sourcePos", &ParticleSystem::getSourcePosition, &ParticleSystem::setSourcePosition)
    .property("posVar", &ParticleSystem::getPosVar, &ParticleSystem::setPosVar)
    .property("life", &ParticleSystem::getLife, &ParticleSystem::setLife)
    .property("lifeVar", &ParticleSystem::getLifeVar, &ParticleSystem::setLifeVar)
    .property("angle", &ParticleSystem::getAngle, &ParticleSystem::setAngle)
    .property("angleVar", &ParticleSystem::getAngleVar, &ParticleSystem::setAngleVar)
    .property("startSize", &ParticleSystem::getStartSize, &ParticleSystem::setStartSize)
    .property("startSizeVar", &ParticleSystem::getStartSizeVar, &ParticleSystem::setStartSizeVar)
    .property("endSize", &ParticleSystem::getEndSize, &ParticleSystem::setEndSize)
    .property("endSizeVar", &ParticleSystem::getEndSizeVar, &ParticleSystem::setEndSizeVar)
    .property("startSpin", &ParticleSystem::getStartSpin, &ParticleSystem::setStartSpin)
    .property("startSpinVar", &ParticleSystem::getStartSpinVar, &ParticleSystem::setStartSpinVar)
    .property("endSpin", &ParticleSystem::getEndSpin, &ParticleSystem::setEndSpin)
    .property("endSpinVar", &ParticleSystem::getEndSpinVar, &ParticleSystem::setEndSpinVar)
    .property("gravity", optional_override([](const ParticleSystem& this_)
      {
        return const_cast<ParticleSystem&>(this_).getGravity();
      }), &ParticleSystem::setGravity)
    .property("speed", &ParticleSystem::getSpeed, &ParticleSystem::setSpeed)
    .property("speedVar", &ParticleSystem::getSpeedVar, &ParticleSystem::setSpeedVar)
    .property("tangentialAccel", &ParticleSystem::getTangentialAccel, &ParticleSystem::setTangentialAccel)
    .property("tangentialAccelVar", &ParticleSystem::getTangentialAccelVar, &ParticleSystem::setTangentialAccelVar)
    .property("tangentialAccel", &ParticleSystem::getTangentialAccel, &ParticleSystem::setTangentialAccel)
    .property("tangentialAccelVar", &ParticleSystem::getTangentialAccelVar, &ParticleSystem::setTangentialAccelVar)
    .property("rotationIsDir", &ParticleSystem::getRotationIsDir, &ParticleSystem::setRotationIsDir)
    .property("startRadius", &ParticleSystem::getStartRadius, &ParticleSystem::setStartRadius)
    .property("startRadiusVar", &ParticleSystem::getStartRadiusVar, &ParticleSystem::setStartRadiusVar)
    .property("endRadius", &ParticleSystem::getEndRadius, &ParticleSystem::setEndRadius)
    .property("endRadiusVar", &ParticleSystem::getEndRadiusVar, &ParticleSystem::setEndRadiusVar)
    .property("rotatePerS", &ParticleSystem::getRotatePerSecond, &ParticleSystem::setRotatePerSecond)
    .property("rotatePerSVar", &ParticleSystem::getRotatePerSecondVar, &ParticleSystem::setRotatePerSecondVar)
    .property("startColor", &ParticleSystem::getStartColor, &ParticleSystem::setStartColor)
    .property("startColorVar", &ParticleSystem::getStartColorVar, &ParticleSystem::setStartColorVar)
    .property("endColor", &ParticleSystem::getEndColor, &ParticleSystem::setEndColor)
    .property("endColorVar", &ParticleSystem::getEndColorVar, &ParticleSystem::setEndColorVar)
    .property("emissionRate", &ParticleSystem::getEmissionRate, &ParticleSystem::setEmissionRate)
    .property("emitterMode", &ParticleSystem::getEmitterMode, &ParticleSystem::setEmitterMode)
    .property("positionType", &ParticleSystem::getPositionType, &ParticleSystem::setPositionType)
    .property("totalParticles", &ParticleSystem::getTotalParticles, &ParticleSystem::setTotalParticles)
    .property("autoRemoveOnFinish", &ParticleSystem::isAutoRemoveOnFinish, &ParticleSystem::setAutoRemoveOnFinish)
    .property("texture", &ParticleSystem::getTexture, &ParticleSystem::setTexture)
    .class_function("create", &ParticleSystem::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleSystem::createWithTotalParticles, allow_raw_pointers())
    .class_function("getAllParticleSystems", &ParticleSystem::getAllParticleSystems)
    .property("_className",  optional_override([](const ParticleSystem& _) -> std::string {return "ParticleSystem";}))
    .allow_subclass<wrapper<ParticleSystem>>("cc.ParticleSystem._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ParticleSystemQuad, base<ParticleSystem>>("cc.ParticleSystem")
    .constructor(&cc_bindings_constructor<ParticleSystemQuad>, allow_raw_pointers())
    .function("setDisplayFrame", &ParticleSystemQuad::setDisplayFrame, allow_raw_pointers())
    .function("setTextureWithRect", &ParticleSystemQuad::setTextureWithRect, allow_raw_pointers())
    .function("listenRendererRecreated", &ParticleSystemQuad::listenRendererRecreated, allow_raw_pointers())
    .class_function("create", select_overload<ParticleSystemQuad*(const std::string&)>(&ParticleSystemQuad::create), allow_raw_pointers())
    .class_function("create", select_overload<ParticleSystemQuad*()>(&ParticleSystemQuad::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("createWithTotalParticles", &ParticleSystemQuad::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSystemQuad& _) -> std::string {return "ParticleSystemQuad";}))    
    ;


  class_<ParticleFire, base<ParticleSystemQuad>>("cc.ParticleFire")
    .constructor(&cc_bindings_constructor<ParticleFire>, allow_raw_pointers())
    .class_function("create", &ParticleFire::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleFire::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleFire& _) -> std::string {return "ParticleFire";}))
    .allow_subclass<wrapper<ParticleFire>>("cc.ParticleFire._extend")    
    ;


  class_<ParticleFireworks, base<ParticleSystemQuad>>("cc.ParticleFireworks")
    .constructor(&cc_bindings_constructor<ParticleFireworks>, allow_raw_pointers())
    .function("init", &ParticleFireworks::init)
    .function("initWithTotalParticles", &ParticleFireworks::initWithTotalParticles)
    .class_function("create", &ParticleFireworks::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleFireworks::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleFireworks& _) -> std::string {return "ParticleFireworks";}))
    .allow_subclass<wrapper<ParticleFireworks>>("cc.ParticleFireworks._extend")    
    ;


  class_<ParticleSun, base<ParticleSystemQuad>>("cc.ParticleSun")
    .constructor(&cc_bindings_constructor<ParticleSun>, allow_raw_pointers())
    .function("init", &ParticleSun::init)
    .function("initWithTotalParticles", &ParticleSun::initWithTotalParticles)
    .class_function("create", &ParticleSun::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleSun::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSun& _) -> std::string {return "ParticleSun";}))
    .allow_subclass<wrapper<ParticleSun>>("cc.ParticleSun._extend")    
    ;


  class_<ParticleGalaxy, base<ParticleSystemQuad>>("cc.ParticleGalaxy")
    .constructor(&cc_bindings_constructor<ParticleGalaxy>, allow_raw_pointers())
    .function("init", &ParticleGalaxy::init)
    .function("initWithTotalParticles", &ParticleGalaxy::initWithTotalParticles)
    .class_function("create", &ParticleGalaxy::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleGalaxy::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleGalaxy& _) -> std::string {return "ParticleGalaxy";}))
    .allow_subclass<wrapper<ParticleGalaxy>>("cc.ParticleGalaxy._extend")    
    ;


  class_<ParticleFlower, base<ParticleSystemQuad>>("cc.ParticleFlower")
    .constructor(&cc_bindings_constructor<ParticleFlower>, allow_raw_pointers())
    .function("init", &ParticleFlower::init)
    .function("initWithTotalParticles", &ParticleFlower::initWithTotalParticles)
    .class_function("create", &ParticleFlower::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleFlower::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleFlower& _) -> std::string {return "ParticleFlower";}))
    .allow_subclass<wrapper<ParticleFlower>>("cc.ParticleFlower._extend")    
    ;


  class_<ParticleMeteor, base<ParticleSystemQuad>>("cc.ParticleMeteor")
    .constructor(&cc_bindings_constructor<ParticleMeteor>, allow_raw_pointers())
    .function("init", &ParticleMeteor::init)
    .function("initWithTotalParticles", &ParticleMeteor::initWithTotalParticles)
    .class_function("create", &ParticleMeteor::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleMeteor::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleMeteor& _) -> std::string {return "ParticleMeteor";}))
    .allow_subclass<wrapper<ParticleMeteor>>("cc.ParticleMeteor._extend")    
    ;


  class_<ParticleSpiral, base<ParticleSystemQuad>>("cc.ParticleSpiral")
    .constructor(&cc_bindings_constructor<ParticleSpiral>, allow_raw_pointers())
    .function("init", &ParticleSpiral::init)
    .function("initWithTotalParticles", &ParticleSpiral::initWithTotalParticles)
    .class_function("create", &ParticleSpiral::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleSpiral::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSpiral& _) -> std::string {return "ParticleSpiral";}))
    .allow_subclass<wrapper<ParticleSpiral>>("cc.ParticleSpiral._extend")    
    ;


  class_<ParticleExplosion, base<ParticleSystemQuad>>("cc.ParticleExplosion")
    .constructor(&cc_bindings_constructor<ParticleExplosion>, allow_raw_pointers())
    .function("init", &ParticleExplosion::init)
    .function("initWithTotalParticles", &ParticleExplosion::initWithTotalParticles)
    .class_function("create", &ParticleExplosion::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleExplosion::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleExplosion& _) -> std::string {return "ParticleExplosion";}))
    .allow_subclass<wrapper<ParticleExplosion>>("cc.ParticleExplosion._extend")    
    ;


  class_<ParticleSmoke, base<ParticleSystemQuad>>("cc.ParticleSmoke")
    .constructor(&cc_bindings_constructor<ParticleSmoke>, allow_raw_pointers())
    .function("init", &ParticleSmoke::init)
    .function("initWithTotalParticles", &ParticleSmoke::initWithTotalParticles)
    .class_function("create", &ParticleSmoke::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleSmoke::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSmoke& _) -> std::string {return "ParticleSmoke";}))
    .allow_subclass<wrapper<ParticleSmoke>>("cc.ParticleSmoke._extend")    
    ;


  class_<ParticleSnow, base<ParticleSystemQuad>>("cc.ParticleSnow")
    .constructor(&cc_bindings_constructor<ParticleSnow>, allow_raw_pointers())
    .function("init", &ParticleSnow::init)
    .function("initWithTotalParticles", &ParticleSnow::initWithTotalParticles)
    .class_function("create", &ParticleSnow::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleSnow::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSnow& _) -> std::string {return "ParticleSnow";}))
    .allow_subclass<wrapper<ParticleSnow>>("cc.ParticleSnow._extend")    
    ;


  class_<ParticleRain, base<ParticleSystemQuad>>("cc.ParticleRain")
    .constructor(&cc_bindings_constructor<ParticleRain>, allow_raw_pointers())
    .function("init", &ParticleRain::init)
    .function("initWithTotalParticles", &ParticleRain::initWithTotalParticles)
    .class_function("create", &ParticleRain::create, allow_raw_pointers())
    .class_function("createWithTotalParticles", &ParticleRain::createWithTotalParticles, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleRain& _) -> std::string {return "ParticleRain";}))
    .allow_subclass<wrapper<ParticleRain>>("cc.ParticleRain._extend")    
    ;


  class_<ProgressTimer, base<Node>>("cc.ProgressTimer")
    .constructor(&cc_bindings_constructor<ProgressTimer>, allow_raw_pointers())
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
    .property("midPoint", &ProgressTimer::getMidpoint, &ProgressTimer::setMidpoint)
    .property("barChangeRate", &ProgressTimer::getBarChangeRate, &ProgressTimer::setBarChangeRate)
    .property("type", &ProgressTimer::getType, &ProgressTimer::setType)
    .property("percentage", &ProgressTimer::getPercentage, &ProgressTimer::setPercentage)
    .property("sprite", &ProgressTimer::getSprite, &ProgressTimer::setSprite)
    .property("reverseDir", optional_override([](const ProgressTimer& this_)
      {
        return const_cast<ProgressTimer&>(this_).isReverseDirection();
      }), &ProgressTimer::setReverseDirection)
    .class_function("create", &ProgressTimer::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ProgressTimer& _) -> std::string {return "ProgressTimer";}))    
    .allow_subclass<wrapper<ProgressTimer>>("cc.ProgressTimer._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ProtectedNode, base<Node>>("cc.ProtectedNode")
    .constructor(&cc_bindings_constructor<ProtectedNode>, allow_raw_pointers())
    .function("addProtectedChild", select_overload<void(Node*, int)>(&ProtectedNode::addProtectedChild), allow_raw_pointers())
    .function("addProtectedChild", select_overload<void(Node*)>(&ProtectedNode::addProtectedChild), allow_raw_pointers())
    .function("addProtectedChild", select_overload<void(Node*, int, int)>(&ProtectedNode::addProtectedChild), allow_raw_pointers())
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
        [](ProtectedNode& this_, Node* arg0){
        return this_.removeProtectedChild(arg0);
      }), allow_raw_pointers())
    .function("removeAllProtectedChildren", &ProtectedNode::removeAllProtectedChildren)
    .class_function("create", &ProtectedNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ProtectedNode& _) -> std::string {return "ProtectedNode";}))    
    ;


  class_<Sprite, base<Node>>("cc.Sprite")
    .constructor(&cc_bindings_constructor<Sprite>, allow_raw_pointers())
    .function("setSpriteFrame", select_overload<void(SpriteFrame*)>(&Sprite::setSpriteFrame), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("setTexture", select_overload<void(Texture2D*)>(&Sprite::setTexture), allow_raw_pointers())
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
    .function("setTextureRect", select_overload<void(const Rect&, bool, const Size&)>(&Sprite::setTextureRect))
    .function("setTextureRect", select_overload<void(const Rect&)>(&Sprite::setTextureRect))
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
    .function("initWithTexture", select_overload<bool(Texture2D*, const Rect&)>(&Sprite::initWithTexture), allow_raw_pointers())
    .function("initWithTexture", select_overload<bool(Texture2D*)>(&Sprite::initWithTexture), allow_raw_pointers())
    .function("initWithTexture", select_overload<bool(Texture2D*, const Rect&, bool)>(&Sprite::initWithTexture), allow_raw_pointers())
    .function("setDirty", &Sprite::setDirty)
    .function("isTextureRectRotated", &Sprite::isTextureRectRotated)
    .function("getTextureRect", &Sprite::getTextureRect)
    .function("initWithFile", select_overload<bool(const std::string&, const Rect&)>(&Sprite::initWithFile))
    .function("initWithFile", select_overload<bool(const std::string&)>(&Sprite::initWithFile))
    .function("setBlendFunc", &Sprite::setBlendFunc)
    .function("getTextureAtlas", &Sprite::getTextureAtlas, allow_raw_pointers())
    .function("initWithSpriteFrame", &Sprite::initWithSpriteFrame, allow_raw_pointers())
    .function("isFlippedX", &Sprite::isFlippedX)
    .function("isFlippedY", &Sprite::isFlippedY)
    .function("setVertexRect", &Sprite::setVertexRect)
    .property("dirty", &Sprite::isDirty, &Sprite::setDirty)
    .property("flippedX", &Sprite::isFlippedX, &Sprite::setFlippedX)
    .property("flippedY", &Sprite::isFlippedY, &Sprite::setFlippedY)
    .property("offsetX", optional_override(
        [](const Sprite& this_){
        return this_.getOffsetPosition().x;
      }))
    .property("offsetY", optional_override(
        [](const Sprite& this_){
        return this_.getOffsetPosition().y;
      }))
    .property("atlasIndex", &Sprite::getAtlasIndex, &Sprite::setAtlasIndex)
    .property("texture", &Sprite::getTexture, select_overload<void(Texture2D*)>(&Sprite::setTexture))
    .property("textureRectRotated", &Sprite::isTextureRectRotated)
    .property("textureAtlas", &Sprite::getTextureAtlas, &Sprite::setTextureAtlas)
    .property("batchNode", &Sprite::getBatchNode, &Sprite::setBatchNode)
    .property("quad", &Sprite::getQuad)
    .property("_className",  optional_override([](const Sprite& _) -> std::string {return "Sprite";}))    
    .allow_subclass<wrapper<Sprite>>("cc.Sprite._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<RenderTexture, base<Node>>("cc.RenderTexture")
    .constructor(&cc_bindings_constructor<RenderTexture>, allow_raw_pointers())
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
    .function("initWithWidthAndHeight", select_overload<bool(int, int, Texture2D::PixelFormat, unsigned int)>(&RenderTexture::initWithWidthAndHeight))
    .function("initWithWidthAndHeight", select_overload<bool(int, int, Texture2D::PixelFormat)>(&RenderTexture::initWithWidthAndHeight))
    .class_function("create", select_overload<RenderTexture*(int, int, Texture2D::PixelFormat)>(&RenderTexture::create), allow_raw_pointers())
    .class_function("create", select_overload<RenderTexture*(int, int, Texture2D::PixelFormat, unsigned int)>(&RenderTexture::create), allow_raw_pointers())
    .class_function("create", select_overload<RenderTexture*(int, int)>(&RenderTexture::create), allow_raw_pointers())
    .property("_className",  optional_override([](const RenderTexture& _) -> std::string {return "RenderTexture";}))    
    .allow_subclass<wrapper<RenderTexture>>("cc.RenderTexture._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;

  class_<Camera, base<Node>>("cc.Camera")
    .constructor(&cc_bindings_constructor<Camera>, allow_raw_pointers())
    .function("restore", &Camera::restore)
    .function("getDepth", &Camera::getDepth)
    .function("getViewProjectionMatrix", &Camera::getViewProjectionMatrix)
    .function("applyViewport", &Camera::applyViewport)
    .function("setBackgroundBrush", &Camera::setBackgroundBrush, allow_raw_pointers())
    .function("lookAt", &Camera::lookAt)
    .function("lookAt", optional_override(
        [](Camera& this_, const Vec3& arg0){
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
    .class_function("getDefaultViewport", &Camera::getDefaultViewport)
    .class_function("setDefaultViewport", &Camera::setDefaultViewport)
    .class_function("getDefaultCamera", &Camera::getDefaultCamera, allow_raw_pointers())
    .property("_className",  optional_override([](const Camera& _) -> std::string {return "Camera";}))
    .allow_subclass<wrapper<Camera>>("cc.Camera._extend")    
    ;


  class_<CameraBackgroundBrush>("cc.CameraBackgroundBrush")
    .constructor(&cc_bindings_constructor<CameraBackgroundBrush>, allow_raw_pointers())
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
    .allow_subclass<wrapper<CameraBackgroundBrush>>("cc.CameraBackgroundBrush._extend")    
    ;


  class_<CameraBackgroundDepthBrush, base<CameraBackgroundBrush>>("cc.CameraBackgroundDepthBrush")
    .constructor(&cc_bindings_constructor<CameraBackgroundDepthBrush>, allow_raw_pointers())
    .function("setDepth", &CameraBackgroundDepthBrush::setDepth)
    .class_function("create", &CameraBackgroundDepthBrush::create, allow_raw_pointers())
    .property("_className",  optional_override([](const CameraBackgroundDepthBrush& _) -> std::string {return "CameraBackgroundDepthBrush";}))
    .allow_subclass<wrapper<CameraBackgroundDepthBrush>>("cc.CameraBackgroundDepthBrush._extend")    
    ;


  class_<CameraBackgroundColorBrush, base<CameraBackgroundDepthBrush>>("cc.CameraBackgroundColorBrush")
    .constructor(&cc_bindings_constructor<CameraBackgroundColorBrush>, allow_raw_pointers())
    .function("setColor", &CameraBackgroundColorBrush::setColor)
    .class_function("create", &CameraBackgroundColorBrush::create, allow_raw_pointers())
    .property("_className",  optional_override([](const CameraBackgroundColorBrush& _) -> std::string {return "CameraBackgroundColorBrush";}))
    .allow_subclass<wrapper<CameraBackgroundColorBrush>>("cc.CameraBackgroundColorBrush._extend")    
    ;


  class_<CameraBackgroundSkyBoxBrush, base<CameraBackgroundBrush>>("cc.CameraBackgroundSkyBoxBrush")
    .constructor(&cc_bindings_constructor<CameraBackgroundSkyBoxBrush>, allow_raw_pointers())
    .function("setTextureValid", &CameraBackgroundSkyBoxBrush::setTextureValid)
    .function("setTexture", &CameraBackgroundSkyBoxBrush::setTexture, allow_raw_pointers())
    .function("setActived", &CameraBackgroundSkyBoxBrush::setActived)
    .function("isActived", &CameraBackgroundSkyBoxBrush::isActived)
    .class_function("create", select_overload<CameraBackgroundSkyBoxBrush*()>(&CameraBackgroundSkyBoxBrush::create), allow_raw_pointers())
    .class_function("create", select_overload<CameraBackgroundSkyBoxBrush*(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&)>(&CameraBackgroundSkyBoxBrush::create), allow_raw_pointers())
    .property("_className",  optional_override([](const CameraBackgroundSkyBoxBrush& _) -> std::string {return "CameraBackgroundSkyBoxBrush";}))
    .allow_subclass<wrapper<CameraBackgroundSkyBoxBrush>>("cc.CameraBackgroundSkyBoxBrush._extend")    
    ;

  class_<GridBase>("cc.GridBase")
    .constructor(&cc_bindings_constructor<GridBase>, allow_raw_pointers())
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
    .function("initWithSize", select_overload<bool(const Size&, const Rect&)>(&GridBase::initWithSize))
    .function("initWithSize", select_overload<bool(const Size&)>(&GridBase::initWithSize))
    .function("initWithSize", select_overload<bool(const Size&, Texture2D*, bool)>(&GridBase::initWithSize), allow_raw_pointers())
    .function("initWithSize", select_overload<bool(const Size&, Texture2D*, bool, const Rect&)>(&GridBase::initWithSize), allow_raw_pointers())
    .function("beforeBlit", &GridBase::beforeBlit)
    .function("setReuseGrid", &GridBase::setReuseGrid)
    .function("isActive", &GridBase::isActive)
    .function("reuse", &GridBase::reuse)
    .class_function("create", select_overload<GridBase*(const Size&)>(&GridBase::create), allow_raw_pointers())
    .class_function("create", select_overload<GridBase*(const Size&, Texture2D*, bool)>(&GridBase::create), allow_raw_pointers())
    .property("_className",  optional_override([](const GridBase& _) -> std::string {return "GridBase";}))    
    .allow_subclass<wrapper<GridBase>>("cc.GridBase._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<Grid3D, base<GridBase>>("cc.Grid3D")
    .constructor(&cc_bindings_constructor<Grid3D>, allow_raw_pointers())
    .function("getNeedDepthTestForBlit", &Grid3D::getNeedDepthTestForBlit)
    .function("setNeedDepthTestForBlit", &Grid3D::setNeedDepthTestForBlit)
    .class_function("create", select_overload<Grid3D*(const Size&, const Rect&)>(&Grid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<Grid3D*(const Size&)>(&Grid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<Grid3D*(const Size&, Texture2D*, bool)>(&Grid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<Grid3D*(const Size&, Texture2D*, bool, const Rect&)>(&Grid3D::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Grid3D& _) -> std::string {return "Grid3D";}))    
    .allow_subclass<wrapper<Grid3D>>("cc.Grid3D._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TiledGrid3D, base<GridBase>>("cc.TiledGrid3D")
    .constructor(&cc_bindings_constructor<TiledGrid3D>, allow_raw_pointers())
    .class_function("create", select_overload<TiledGrid3D*(const Size&, const Rect&)>(&TiledGrid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<TiledGrid3D*(const Size&)>(&TiledGrid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<TiledGrid3D*(const Size&, Texture2D*, bool)>(&TiledGrid3D::create), allow_raw_pointers())
    .class_function("create", select_overload<TiledGrid3D*(const Size&, Texture2D*, bool, const Rect&)>(&TiledGrid3D::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TiledGrid3D& _) -> std::string {return "TiledGrid3D";}))    
    .allow_subclass<wrapper<TiledGrid3D>>("cc.TiledGrid3D._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
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
    .constructor(&cc_bindings_constructor<DirectionLight>, allow_raw_pointers())
    .function("getDirection", &DirectionLight::getDirection)
    .function("getDirectionInWorld", &DirectionLight::getDirectionInWorld)
    .function("setDirection", &DirectionLight::setDirection)
    .class_function("create", &DirectionLight::create, allow_raw_pointers())
    .property("_className",  optional_override([](const DirectionLight& _) -> std::string {return "DirectionLight";}))
    .allow_subclass<wrapper<DirectionLight>>("cc.DirectionLight._extend")    
    ;


  class_<PointLight, base<BaseLight>>("cc.PointLight")
    .constructor(&cc_bindings_constructor<PointLight>, allow_raw_pointers())
    .function("getRange", &PointLight::getRange)
    .function("setRange", &PointLight::setRange)
    .class_function("create", &PointLight::create, allow_raw_pointers())
    .property("_className",  optional_override([](const PointLight& _) -> std::string {return "PointLight";}))
    .allow_subclass<wrapper<PointLight>>("cc.PointLight._extend")    
    ;


  class_<SpotLight, base<BaseLight>>("cc.SpotLight")
    .constructor(&cc_bindings_constructor<SpotLight>, allow_raw_pointers())
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
    .allow_subclass<wrapper<SpotLight>>("cc.SpotLight._extend")    
    ;


  class_<AmbientLight, base<BaseLight>>("cc.AmbientLight")
    .constructor(&cc_bindings_constructor<AmbientLight>, allow_raw_pointers())
    .class_function("create", &AmbientLight::create, allow_raw_pointers())
    .property("_className",  optional_override([](const AmbientLight& _) -> std::string {return "AmbientLight";}))
    .allow_subclass<wrapper<AmbientLight>>("cc.AmbientLight._extend")    
    ;


  class_<GLProgram>("cc.GLProgram")
    .constructor(&cc_bindings_constructor<GLProgram>, allow_raw_pointers())
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
    .function("setUniformsForBuiltins", select_overload<void(const Mat4&)>(&GLProgram::setUniformsForBuiltins))
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
    .class_function("createWithByteArrays", select_overload<GLProgram*(const char*, const char*, const std::string&)>(&GLProgram::createWithByteArrays), allow_raw_pointers())
    .class_function("createWithByteArrays", select_overload<GLProgram*(const char*, const char*)>(&GLProgram::createWithByteArrays), allow_raw_pointers())
    .class_function("createWithByteArrays", select_overload<GLProgram*(const char*, const char*, const std::string&, const std::string&)>(&GLProgram::createWithByteArrays), allow_raw_pointers())
    .class_function("createWithFilenames", select_overload<GLProgram*(const std::string&, const std::string&, const std::string&)>(&GLProgram::createWithFilenames), allow_raw_pointers())
    .class_function("createWithFilenames", select_overload<GLProgram*(const std::string&, const std::string&)>(&GLProgram::createWithFilenames), allow_raw_pointers())
    .class_function("createWithFilenames", select_overload<GLProgram*(const std::string&, const std::string&, const std::string&, const std::string&)>(&GLProgram::createWithFilenames), allow_raw_pointers())
    .property("_className",  optional_override([](const GLProgram& _) -> std::string {return "GLProgram";}))    
    .allow_subclass<wrapper<GLProgram>>("cc.GLProgram._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<GLProgramCache>("cc.ShaderCache")
    .constructor(&cc_bindings_constructor<GLProgramCache>, allow_raw_pointers())
    .function("reloadDefaultGLProgramsRelativeToLights", &GLProgramCache::reloadDefaultGLProgramsRelativeToLights)
    .class_function("destroyInstance", &GLProgramCache::destroyInstance)
    .class_function("getInstance", &GLProgramCache::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const GLProgramCache& _) -> std::string {return "GLProgramCache";}))    
    ;

  class_<RenderState>("cc.RenderState")
    .function("setTexture", &RenderState::setTexture, allow_raw_pointers())
    .function("getTopmost", &RenderState::getTopmost, allow_raw_pointers())
    .function("getTexture", &RenderState::getTexture, allow_raw_pointers())
    .function("bind", &RenderState::bind, allow_raw_pointers())
    .function("getName", &RenderState::getName)
    .function("getStateBlock", &RenderState::getStateBlock, allow_raw_pointers())
    .function("setParent", &RenderState::setParent, allow_raw_pointers())
    .class_function("initialize", &RenderState::initialize)
    .class_function("finalize", &RenderState::finalize)
    .property("_className",  optional_override([](const RenderState& _) -> std::string {return "RenderState";}))    
    ;

  class_<Pass, base<RenderState>>("cc.Pass")
    .function("unbind", &Pass::unbind)
    .function("bind", select_overload<void(const Mat4&, bool)>(&Pass::bind))
    .function("bind", select_overload<void(const Mat4&)>(&Pass::bind))
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
    .constructor(&cc_bindings_constructor<TextureCache>, allow_raw_pointers())
    .function("reloadTexture", &TextureCache::reloadTexture)
    .function("unbindAllImageAsync", &TextureCache::unbindAllImageAsync)
    .function("removeTextureForKey", &TextureCache::removeTextureForKey)
    .function("removeAllTextures", &TextureCache::removeAllTextures)
    .function("addImageAsync", select_overload<void(const std::string&, const std::function<void (Texture2D *)>&, const std::string&)>(&TextureCache::addImageAsync))
    .function("addImageAsync", select_overload<void(const std::string&, const std::function<void (Texture2D *)>&)>(&TextureCache::addImageAsync))
    .function("getDescription", &TextureCache::getDescription)
    .function("getCachedTextureInfo", &TextureCache::getCachedTextureInfo)
    .function("addImage", select_overload<Texture2D*(Image*, const std::string&)>(&TextureCache::addImage), allow_raw_pointers())
    .function("addImage", select_overload<Texture2D*(const std::string&)>(&TextureCache::addImage), allow_raw_pointers())
    .function("unbindImageAsync", &TextureCache::unbindImageAsync)
    .function("getTextureForKey", &TextureCache::getTextureForKey, allow_raw_pointers())
    .function("getTextureFilePath", &TextureCache::getTextureFilePath, allow_raw_pointers())
    .function("renameTextureWithKey", &TextureCache::renameTextureWithKey)
    .function("removeUnusedTextures", &TextureCache::removeUnusedTextures)
    .function("removeTexture", &TextureCache::removeTexture, allow_raw_pointers())
    .function("waitForQuit", &TextureCache::waitForQuit)
    .class_function("setETC1AlphaFileSuffix", &TextureCache::setETC1AlphaFileSuffix)
    .class_function("getETC1AlphaFileSuffix", &TextureCache::getETC1AlphaFileSuffix)
    .property("_className",  optional_override([](const TextureCache& _) -> std::string {return "TextureCache";}))    
    ;

  class_<Device>("cc.Device")
    .class_function("setAccelerometerEnabled", &Device::setAccelerometerEnabled)
    .class_function("setAccelerometerInterval", &Device::setAccelerometerInterval)
    .class_function("setKeepScreenOn", &Device::setKeepScreenOn)
    .class_function("vibrate", &Device::vibrate)
    .class_function("getDPI", &Device::getDPI)
    .property("_className",  optional_override([](const Device& _) -> std::string {return "Device";}))    
    ;

  class_<SAXParser>("cc.PlistParser")
    .function("init", &SAXParser::init, allow_raw_pointers())
    // TODO: look at __JSPlistDelegator
    // .function("parse", &SAXParser::parse, allow_raw_pointers())
    .class_function("getInstance", optional_override(
      [](){
        static auto instance = new (std::nothrow)SAXParser();
        return instance;
      }), allow_raw_pointers())
    // end of TODO
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
    .constructor(&cc_bindings_constructor<AnimationCache>, allow_raw_pointers())
    .function("getAnimation", &AnimationCache::getAnimation, allow_raw_pointers())
    .function("addAnimation", &AnimationCache::addAnimation, allow_raw_pointers())
    .function("init", &AnimationCache::init)
    .function("addAnimationsWithDictionary", &AnimationCache::addAnimationsWithDictionary)
    .function("removeAnimation", &AnimationCache::removeAnimation)
    .function("addAnimations", &AnimationCache::addAnimationsWithFile)
    .class_function("destroyInstance", &AnimationCache::destroyInstance)
    .class_function("getInstance", &AnimationCache::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const AnimationCache& _) -> std::string {return "AnimationCache";}))    
    .allow_subclass<wrapper<AnimationCache>>("cc.AnimationCache._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<SpriteBatchNode, base<Node>>("cc.SpriteBatchNode")
    .constructor(&cc_bindings_constructor<SpriteBatchNode>, allow_raw_pointers())
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
        [](SpriteBatchNode& this_, Texture2D* arg0){
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
    .property("textureAtlas", optional_override([](const SpriteBatchNode& this_)
      {
        return const_cast<SpriteBatchNode&>(this_).getTextureAtlas();
      }), &SpriteBatchNode::setTextureAtlas)
    .property("descendants", &SpriteBatchNode::getDescendants)
    .property("texture", &SpriteBatchNode::getTexture, &SpriteBatchNode::setTexture)
    .class_function("create", &SpriteBatchNode::create, allow_raw_pointers())
    .class_function("create", optional_override(
      [](const std::string& arg0){
        return SpriteBatchNode::create(arg0);
      }), allow_raw_pointers())
    .class_function("createWithTexture", &SpriteBatchNode::createWithTexture, allow_raw_pointers())
    .class_function("createWithTexture", optional_override(
      [](Texture2D* arg0){
        return SpriteBatchNode::createWithTexture(arg0);
      }), allow_raw_pointers())
    .property("_className",  optional_override([](const SpriteBatchNode& _) -> std::string {return "SpriteBatchNode";}))    
    .allow_subclass<wrapper<SpriteBatchNode>>("cc.SpriteBatchNode._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
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
    .class_function("destroyInstance", &SpriteFrameCache::destroyInstance)
    .class_function("getInstance", &SpriteFrameCache::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const SpriteFrameCache& _) -> std::string {return "SpriteFrameCache";}))    
    ;


  class_<TextFieldTTF, base<Label>>("cc.TextFieldTTF")
    .constructor(&cc_bindings_constructor<TextFieldTTF>, allow_raw_pointers())
    .function("getCharCount", &TextFieldTTF::getCharCount)
    .function("setCursorChar", &TextFieldTTF::setCursorChar)
    .function("setSecureTextEntry", &TextFieldTTF::setSecureTextEntry)
    .function("setCursorEnabled", &TextFieldTTF::setCursorEnabled)
    .function("getColorSpaceHolder", &TextFieldTTF::getColorSpaceHolder)
    .function("initWithPlaceHolder", select_overload<bool(const std::string&, const std::string&, float)>(&TextFieldTTF::initWithPlaceHolder))
    .function("initWithPlaceHolder", select_overload<bool(const std::string&, const Size&, TextHAlignment, const std::string&, float)>(&TextFieldTTF::initWithPlaceHolder))
    .function("appendString", &TextFieldTTF::appendString)
    .function("getPasswordTextStyle", &TextFieldTTF::getPasswordTextStyle)
    .function("setPasswordTextStyle", &TextFieldTTF::setPasswordTextStyle)
    .function("setColorSpaceHolder", select_overload<void(const Color4B&)>(&TextFieldTTF::setColorSpaceHolder))
    // TODO: Only support function overloading with different number of parameters
    .function("detachWithIME", &TextFieldTTF::detachWithIME)
    .function("setPlaceHolder", &TextFieldTTF::setPlaceHolder)
    .function("setCursorFromPoint", &TextFieldTTF::setCursorFromPoint, allow_raw_pointers())
    .function("isSecureTextEntry", &TextFieldTTF::isSecureTextEntry)
    .function("getPlaceHolder", &TextFieldTTF::getPlaceHolder)
    .function("setCursorPosition", &TextFieldTTF::setCursorPosition)
    .function("attachWithIME", &TextFieldTTF::attachWithIME)
    .property("string", &TextFieldTTF::getString, &TextFieldTTF::setString)
    .class_function("create", select_overload<TextFieldTTF*(const std::string&, const std::string&, float)>(&TextFieldTTF::textFieldWithPlaceHolder), allow_raw_pointers())
    .class_function("create", select_overload<TextFieldTTF*(const std::string&, const Size&, TextHAlignment, const std::string&, float)>(&TextFieldTTF::textFieldWithPlaceHolder), allow_raw_pointers())
    .property("_className",  optional_override([](const TextFieldTTF& _) -> std::string {return "TextFieldTTF";}))    
    .allow_subclass<wrapper<TextFieldTTF>>("cc.TextFieldTTF._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<ParallaxNode, base<Node>>("cc.ParallaxNode")
    .constructor(&cc_bindings_constructor<ParallaxNode>, allow_raw_pointers())
    .function("getParallaxArray", select_overload<const _ccArray*() const>(&ParallaxNode::getParallaxArray), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("removeAllChildrenWithCleanup", &ParallaxNode::removeAllChildrenWithCleanup)
    .function("setParallaxArray", &ParallaxNode::setParallaxArray, allow_raw_pointers())
    .class_function("create", &ParallaxNode::create, allow_raw_pointers())
    .property("_className",  optional_override([](const ParallaxNode& _) -> std::string {return "ParallaxNode";}))    
    .allow_subclass<wrapper<ParallaxNode>>("cc.ParallaxNode._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
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
    .class_function("end", &SimpleAudioEngine::end)
    .class_function("getInstance", &SimpleAudioEngine::getInstance, allow_raw_pointers())
    .property("_className",  optional_override([](const SimpleAudioEngine& _) -> std::string {return "SimpleAudioEngine";}))    
    ;

  class_<ComponentJS, base<Component>>("cc.ComponentJS")
    .property("_className",  optional_override([](const ComponentJS& _) -> std::string {return "ComponentJS";}))    
    ;
}

CC_BINDINGS_ALLOW_RAW_POINTERS(TMXTilesetInfo)

COCOS_BINDINGS(jsb_cocos2dx_tmx) {
  class_<TMXObjectGroup>("cc.TMXObjectGroup")
    .constructor(&cc_bindings_constructor<TMXObjectGroup>, allow_raw_pointers())
    .function("setPositionOffset", &TMXObjectGroup::setPositionOffset)
    .function("getProperty", &TMXObjectGroup::getProperty)
    .function("getPositionOffset", &TMXObjectGroup::getPositionOffset)
    .function("getObject", &TMXObjectGroup::getObject)
    .function("getObjects", select_overload<std::vector<Value>&()>(&TMXObjectGroup::getObjects))
    // TODO: Only support function overloading with different number of parameters
    .function("setGroupName", &TMXObjectGroup::setGroupName)
    .function("getProperties", select_overload<std::unordered_map<std::string, Value>&()>(&TMXObjectGroup::getProperties))
    // TODO: Only support function overloading with different number of parameters
    .function("getGroupName", &TMXObjectGroup::getGroupName)
    .function("setProperties", &TMXObjectGroup::setProperties)
    .function("setObjects", &TMXObjectGroup::setObjects)
    .property("_className",  optional_override([](const TMXObjectGroup& _) -> std::string {return "TMXObjectGroup";}))    
    ;


  class_<TMXLayerInfo>("cc.TMXLayerInfo")
    .constructor(&cc_bindings_constructor<TMXLayerInfo>, allow_raw_pointers())
    .function("setProperties", &TMXLayerInfo::setProperties)
    .function("getProperties", &TMXLayerInfo::getProperties)
    .property("_className",  optional_override([](const TMXLayerInfo& _) -> std::string {return "TMXLayerInfo";}))    
    ;


  class_<TMXTilesetInfo>("cc.TMXTilesetInfo")
    .constructor(&cc_bindings_constructor<TMXTilesetInfo>, allow_raw_pointers())
    .function("getRectForGID", &TMXTilesetInfo::getRectForGID)
    .property("_className",  optional_override([](const TMXTilesetInfo& _) -> std::string {return "TMXTilesetInfo";}))    
    ;


  class_<TMXMapInfo>("cc.TMXMapInfo")
    .constructor(&cc_bindings_constructor<TMXMapInfo>, allow_raw_pointers())
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
    .function("getLayers", select_overload<Vector<TMXLayerInfo *>&()>(&TMXMapInfo::getLayers))
    // TODO: Only support function overloading with different number of parameters
    .function("getStaggerAxis", &TMXMapInfo::getStaggerAxis)
    .function("setHexSideLength", &TMXMapInfo::setHexSideLength)
    .function("getTilesets", select_overload<Vector<TMXTilesetInfo *>&()>(&TMXMapInfo::getTilesets))
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
    .function("getObjectGroups", select_overload<Vector<TMXObjectGroup *>&()>(&TMXMapInfo::getObjectGroups))
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
    .function("getProperties", select_overload<std::unordered_map<std::string, Value>&()>(&TMXMapInfo::getProperties))
    // TODO: Only support function overloading with different number of parameters
    .function("getStaggerIndex", &TMXMapInfo::getStaggerIndex)
    .function("setLayerAttribs", &TMXMapInfo::setLayerAttribs)
    .class_function("create", &TMXMapInfo::create, allow_raw_pointers())
    .class_function("createWithXML", &TMXMapInfo::createWithXML, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXMapInfo& _) -> std::string {return "TMXMapInfo";}))    
    .allow_subclass<wrapper<TMXMapInfo>>("cc.TMXMapInfo._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TMXLayer, base<SpriteBatchNode>>("cc.TMXLayer")
    .constructor(&cc_bindings_constructor<TMXLayer>, allow_raw_pointers())
    .function("getTileGIDAt", &TMXLayer::getTileGIDAt, allow_raw_pointers())
    .function("getTileGIDAt", optional_override(
        [](TMXLayer& this_, const Vec2& arg0){
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
    .function("setTileGID", select_overload<void(unsigned int, const Vec2&, TMXTileFlags_)>(&TMXLayer::setTileGID))
    .function("setTileGID", select_overload<void(unsigned int, const Vec2&)>(&TMXLayer::setTileGID))
    .function("getMapTileSize", &TMXLayer::getMapTileSize)
    .function("getProperty", &TMXLayer::getProperty)
    .function("setLayerSize", &TMXLayer::setLayerSize)
    .function("getLayerName", &TMXLayer::getLayerName)
    .function("setTileSet", &TMXLayer::setTileSet, allow_raw_pointers())
    .function("getTileSet", &TMXLayer::getTileSet, allow_raw_pointers())
    .function("getProperties", select_overload<std::unordered_map<std::string, Value>&()>(&TMXLayer::getProperties))
    // TODO: Only support function overloading with different number of parameters
    .function("getTileAt", &TMXLayer::getTileAt, allow_raw_pointers())
    .function("getTileAnimManager", &TMXLayer::getTileAnimManager, allow_raw_pointers())
    .property("tileset", &TMXLayer::getTileSet, &TMXLayer::setTileSet)
    .property("layerOrientation", &TMXLayer::getLayerOrientation, &TMXLayer::setLayerOrientation)
    .property("properties", optional_override([](const TMXLayer& this_)
      {
        return const_cast<ValueMap&>(this_.getProperties());
      }), &TMXLayer::setProperties)
    .property("layerName", optional_override([](const TMXLayer& this_)
      {
        return const_cast<TMXLayer&>(this_).getLayerName();
      }), &TMXLayer::setLayerName)
    .property("layerWidth", 
      optional_override([](const TMXLayer& this_){return this_.getLayerSize().width;}), 
      optional_override([](TMXLayer& this_, float width){this_.setLayerSize(Size(width, this_.getLayerSize().height));}))
    .property("layerHeight", 
      optional_override([](const TMXLayer& this_){return this_.getLayerSize().height;}), 
      optional_override([](TMXLayer& this_, float height){this_.setLayerSize(Size(this_.getLayerSize().width, height));}))
    .property("tileWidth", 
      optional_override([](const TMXLayer& this_){return this_.getMapTileSize().width;}), 
      optional_override([](TMXLayer& this_, float width){this_.setMapTileSize(Size(width, this_.getMapTileSize().height));}))
    .property("tileHeight", 
      optional_override([](const TMXLayer& this_){return this_.getMapTileSize().height;}), 
      optional_override([](TMXLayer& this_, float height){this_.setMapTileSize(Size(this_.getMapTileSize().width, height));}))
    .property("texture", &TMXLayer::getTexture, &TMXLayer::setTexture)
    .class_function("create", &TMXLayer::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXLayer& _) -> std::string {return "TMXLayer";}))    
    .allow_subclass<wrapper<TMXLayer>>("cc.TMXLayer._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TMXTileAnimTask>("cc.TMXTileAnimTask")
    .constructor(&cc_bindings_constructor<TMXTileAnimTask, TMXLayer*, TMXTileAnimInfo*, const Vec2&>, allow_raw_pointers())
    .function("start", &TMXTileAnimTask::start)
    .function("stop", &TMXTileAnimTask::stop)
    .function("isRunning", &TMXTileAnimTask::isRunning)
    .class_function("create", &TMXTileAnimTask::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXTileAnimTask& _) -> std::string {return "TMXTileAnimTask";}))    
    ;


  class_<TMXTileAnimManager>("cc.TMXTileAnimManager")
    .constructor(&cc_bindings_constructor<TMXTileAnimManager, TMXLayer*>, allow_raw_pointers())
    .function("getTasks", &TMXTileAnimManager::getTasks)
    .function("startAll", &TMXTileAnimManager::startAll)
    .function("stopAll", &TMXTileAnimManager::stopAll)
    .class_function("create", &TMXTileAnimManager::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXTileAnimManager& _) -> std::string {return "TMXTileAnimManager";}))    
    ;


  class_<TMXTiledMap, base<Node>>("cc.TMXTiledMap")
    .constructor(&cc_bindings_constructor<TMXTiledMap>, allow_raw_pointers())
    .function("setObjectGroups", &TMXTiledMap::setObjectGroups)
    .function("getProperty", &TMXTiledMap::getProperty)
    .function("getLayerNum", &TMXTiledMap::getLayerNum)
    .function("setMapSize", &TMXTiledMap::setMapSize)
    .function("getObjectGroup", &TMXTiledMap::getObjectGroup, allow_raw_pointers())
    .function("getObjectGroups", select_overload<Vector<TMXObjectGroup *>&()>(&TMXTiledMap::getObjectGroups))
    // TODO: Only support function overloading with different number of parameters
    .function("getResourceFile", &TMXTiledMap::getResourceFile)
    .function("initWithTMXFile", &TMXTiledMap::initWithTMXFile)
    .function("getTileSize", &TMXTiledMap::getTileSize)
    .function("getMapSize", &TMXTiledMap::getMapSize)
    .function("setTileAnimEnabled", &TMXTiledMap::setTileAnimEnabled)
    .function("initWithXML", &TMXTiledMap::initWithXML)
    .function("getProperties", &TMXTiledMap::getProperties)
    .function("getPropertiesForGID", select_overload<bool(int, Value**)>(&TMXTiledMap::getPropertiesForGID), allow_raw_pointers())
    .function("getPropertiesForGID", select_overload<Value(int) const>(&TMXTiledMap::getPropertiesForGID))
    .function("setTileSize", &TMXTiledMap::setTileSize)
    .function("setProperties", &TMXTiledMap::setProperties)
    .function("getLayer", &TMXTiledMap::getLayer, allow_raw_pointers())
    .function("getMapOrientation", &TMXTiledMap::getMapOrientation)
    .function("setMapOrientation", &TMXTiledMap::setMapOrientation)
    .property("properties", optional_override([](const TMXTiledMap& this_)
      {
        return const_cast<TMXTiledMap&>(this_).getProperties();
      }), &TMXTiledMap::setProperties)
    .property("mapOrientation", &TMXTiledMap::getMapOrientation, &TMXTiledMap::setMapOrientation)
    .property("objectGroups", optional_override([](const TMXTiledMap& this_)
      {
        return const_cast<Vector<TMXObjectGroup*>&>(this_.getObjectGroups());
      }), &TMXTiledMap::setObjectGroups)
    .property("mapWidth", 
      optional_override([](const TMXTiledMap& this_){return this_.getMapSize().width;}), 
      optional_override([](TMXTiledMap& this_, float width){this_.setMapSize(Size(width, this_.getMapSize().height));}))
    .property("mapHeight", 
      optional_override([](const TMXTiledMap& this_){return this_.getMapSize().height;}), 
      optional_override([](TMXTiledMap& this_, float height){this_.setMapSize(Size(this_.getMapSize().width, height));}))
    .property("tileWidth", 
      optional_override([](const TMXTiledMap& this_){return this_.getTileSize().width;}), 
      optional_override([](TMXTiledMap& this_, float width){this_.setTileSize(Size(width, this_.getTileSize().height));}))
    .property("tileHeight", 
      optional_override([](const TMXTiledMap& this_){return this_.getTileSize().height;}), 
      optional_override([](TMXTiledMap& this_, float height){this_.setTileSize(Size(this_.getTileSize().width, height));}))
    .class_function("create", &TMXTiledMap::create, allow_raw_pointers())
    .class_function("createWithXML", &TMXTiledMap::createWithXML, allow_raw_pointers())
    .property("_className",  optional_override([](const TMXTiledMap& _) -> std::string {return "TMXTiledMap";}))    
    .allow_subclass<wrapper<TMXTiledMap>>("cc.TMXTiledMap._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TileMapAtlas, base<AtlasNode>>("cc.TileMapAtlas")
    .constructor(&cc_bindings_constructor<TileMapAtlas>, allow_raw_pointers())
    .function("initWithTileFile", &TileMapAtlas::initWithTileFile)
    .function("releaseMap", &TileMapAtlas::releaseMap)
    .function("getTGAInfo", &TileMapAtlas::getTGAInfo, allow_raw_pointers())
    .function("getTileAt", &TileMapAtlas::getTileAt)
    .function("setTile", &TileMapAtlas::setTile)
    .function("setTGAInfo", &TileMapAtlas::setTGAInfo, allow_raw_pointers())
    .class_function("create", &TileMapAtlas::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TileMapAtlas& _) -> std::string {return "TileMapAtlas";}))    
    .allow_subclass<wrapper<TileMapAtlas>>("cc.TileMapAtlas._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;
}

COCOS_BINDINGS(jsb_cocos2dx_transition) {

  class_<TransitionEaseScene>("cc.TransitionEaseScene")
    .function("easeActionWithAction", &TransitionEaseScene::easeActionWithAction, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionEaseScene& _) -> std::string {return "TransitionEaseScene";}))    
    ;


  class_<TransitionScene, base<Scene>>("cc.TransitionScene")
    .constructor(&cc_bindings_constructor<TransitionScene>, allow_raw_pointers())
    .function("getInScene", &TransitionScene::getInScene, allow_raw_pointers())
    .function("finish", &TransitionScene::finish)
    .function("initWithDuration", &TransitionScene::initWithDuration, allow_raw_pointers())
    .function("getDuration", &TransitionScene::getDuration)
    .function("hideOutShowIn", &TransitionScene::hideOutShowIn)
    .class_function("create", &TransitionScene::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionScene& _) -> std::string {return "TransitionScene";}))    
    .allow_subclass<wrapper<TransitionScene>>("cc.TransitionScene._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionSceneOriented, base<TransitionScene>>("cc.TransitionSceneOriented")
    .constructor(&cc_bindings_constructor<TransitionSceneOriented>, allow_raw_pointers())
    .function("initWithDuration", &TransitionSceneOriented::initWithDuration, allow_raw_pointers())
    .class_function("create", &TransitionSceneOriented::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSceneOriented& _) -> std::string {return "TransitionSceneOriented";}))    
    .allow_subclass<wrapper<TransitionSceneOriented>>("cc.TransitionSceneOriented._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionRotoZoom, base<TransitionScene>>("cc.TransitionRotoZoom")
    .constructor(&cc_bindings_constructor<TransitionRotoZoom>, allow_raw_pointers())
    .class_function("create", &TransitionRotoZoom::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionRotoZoom& _) -> std::string {return "TransitionRotoZoom";}))    
    .allow_subclass<wrapper<TransitionRotoZoom>>("cc.TransitionRotoZoom._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionJumpZoom, base<TransitionScene>>("cc.TransitionJumpZoom")
    .constructor(&cc_bindings_constructor<TransitionJumpZoom>, allow_raw_pointers())
    .class_function("create", &TransitionJumpZoom::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionJumpZoom& _) -> std::string {return "TransitionJumpZoom";}))    
    .allow_subclass<wrapper<TransitionJumpZoom>>("cc.TransitionJumpZoom._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionMoveInL, base<TransitionScene>>("cc.TransitionMoveInL")
    .constructor(&cc_bindings_constructor<TransitionMoveInL>, allow_raw_pointers())
    .function("action", &TransitionMoveInL::action, allow_raw_pointers())
    .function("easeActionWithAction", &TransitionMoveInL::easeActionWithAction, allow_raw_pointers())
    .class_function("create", &TransitionMoveInL::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionMoveInL& _) -> std::string {return "TransitionMoveInL";}))    
    .allow_subclass<wrapper<TransitionMoveInL>>("cc.TransitionMoveInL._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionMoveInR, base<TransitionMoveInL>>("cc.TransitionMoveInR")
    .constructor(&cc_bindings_constructor<TransitionMoveInR>, allow_raw_pointers())
    .class_function("create", &TransitionMoveInR::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionMoveInR& _) -> std::string {return "TransitionMoveInR";}))    
    .allow_subclass<wrapper<TransitionMoveInR>>("cc.TransitionMoveInR._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionMoveInT, base<TransitionMoveInL>>("cc.TransitionMoveInT")
    .constructor(&cc_bindings_constructor<TransitionMoveInT>, allow_raw_pointers())
    .class_function("create", &TransitionMoveInT::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionMoveInT& _) -> std::string {return "TransitionMoveInT";}))    
    .allow_subclass<wrapper<TransitionMoveInT>>("cc.TransitionMoveInT._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionMoveInB, base<TransitionMoveInL>>("cc.TransitionMoveInB")
    .constructor(&cc_bindings_constructor<TransitionMoveInB>, allow_raw_pointers())
    .class_function("create", &TransitionMoveInB::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionMoveInB& _) -> std::string {return "TransitionMoveInB";}))    
    .allow_subclass<wrapper<TransitionMoveInB>>("cc.TransitionMoveInB._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionSlideInL, base<TransitionScene>>("cc.TransitionSlideInL")
    .constructor(&cc_bindings_constructor<TransitionSlideInL>, allow_raw_pointers())
    .function("action", &TransitionSlideInL::action, allow_raw_pointers())
    .function("easeActionWithAction", &TransitionSlideInL::easeActionWithAction, allow_raw_pointers())
    .class_function("create", &TransitionSlideInL::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSlideInL& _) -> std::string {return "TransitionSlideInL";}))    
    .allow_subclass<wrapper<TransitionSlideInL>>("cc.TransitionSlideInL._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionSlideInR, base<TransitionSlideInL>>("cc.TransitionSlideInR")
    .constructor(&cc_bindings_constructor<TransitionSlideInR>, allow_raw_pointers())
    .class_function("create", &TransitionSlideInR::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSlideInR& _) -> std::string {return "TransitionSlideInR";}))    
    .allow_subclass<wrapper<TransitionSlideInR>>("cc.TransitionSlideInR._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionSlideInB, base<TransitionSlideInL>>("cc.TransitionSlideInB")
    .constructor(&cc_bindings_constructor<TransitionSlideInB>, allow_raw_pointers())
    .class_function("create", &TransitionSlideInB::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSlideInB& _) -> std::string {return "TransitionSlideInB";}))    
    .allow_subclass<wrapper<TransitionSlideInB>>("cc.TransitionSlideInB._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionSlideInT, base<TransitionSlideInL>>("cc.TransitionSlideInT")
    .constructor(&cc_bindings_constructor<TransitionSlideInT>, allow_raw_pointers())
    .class_function("create", &TransitionSlideInT::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSlideInT& _) -> std::string {return "TransitionSlideInT";}))    
    .allow_subclass<wrapper<TransitionSlideInT>>("cc.TransitionSlideInT._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionShrinkGrow, base<TransitionScene>>("cc.TransitionShrinkGrow")
    .constructor(&cc_bindings_constructor<TransitionShrinkGrow>, allow_raw_pointers())
    .function("easeActionWithAction", &TransitionShrinkGrow::easeActionWithAction, allow_raw_pointers())
    .class_function("create", &TransitionShrinkGrow::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionShrinkGrow& _) -> std::string {return "TransitionShrinkGrow";}))    
    .allow_subclass<wrapper<TransitionShrinkGrow>>("cc.TransitionShrinkGrow._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionFlipX, base<TransitionSceneOriented>>("cc.TransitionFlipX")
    .constructor(&cc_bindings_constructor<TransitionFlipX>, allow_raw_pointers())
    .class_function("create", select_overload<TransitionFlipX*(float, Scene*)>(&TransitionFlipX::create), allow_raw_pointers())
    .class_function("create", select_overload<TransitionFlipX*(float, Scene*, TransitionScene::Orientation)>(&TransitionFlipX::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFlipX& _) -> std::string {return "TransitionFlipX";}))    
    .allow_subclass<wrapper<TransitionFlipX>>("cc.TransitionFlipX._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionFlipY, base<TransitionSceneOriented>>("cc.TransitionFlipY")
    .constructor(&cc_bindings_constructor<TransitionFlipY>, allow_raw_pointers())
    .class_function("create", select_overload<TransitionFlipY*(float, Scene*)>(&TransitionFlipY::create), allow_raw_pointers())
    .class_function("create", select_overload<TransitionFlipY*(float, Scene*, TransitionScene::Orientation)>(&TransitionFlipY::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFlipY& _) -> std::string {return "TransitionFlipY";}))    
    .allow_subclass<wrapper<TransitionFlipY>>("cc.TransitionFlipY._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionFlipAngular, base<TransitionSceneOriented>>("cc.TransitionFlipAngular")
    .constructor(&cc_bindings_constructor<TransitionFlipAngular>, allow_raw_pointers())
    .class_function("create", select_overload<TransitionFlipAngular*(float, Scene*)>(&TransitionFlipAngular::create), allow_raw_pointers())
    .class_function("create", select_overload<TransitionFlipAngular*(float, Scene*, TransitionScene::Orientation)>(&TransitionFlipAngular::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFlipAngular& _) -> std::string {return "TransitionFlipAngular";}))    
    .allow_subclass<wrapper<TransitionFlipAngular>>("cc.TransitionFlipAngular._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionZoomFlipX, base<TransitionSceneOriented>>("cc.TransitionZoomFlipX")
    .constructor(&cc_bindings_constructor<TransitionZoomFlipX>, allow_raw_pointers())
    .class_function("create", select_overload<TransitionZoomFlipX*(float, Scene*)>(&TransitionZoomFlipX::create), allow_raw_pointers())
    .class_function("create", select_overload<TransitionZoomFlipX*(float, Scene*, TransitionScene::Orientation)>(&TransitionZoomFlipX::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionZoomFlipX& _) -> std::string {return "TransitionZoomFlipX";}))    
    .allow_subclass<wrapper<TransitionZoomFlipX>>("cc.TransitionZoomFlipX._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionZoomFlipY, base<TransitionSceneOriented>>("cc.TransitionZoomFlipY")
    .constructor(&cc_bindings_constructor<TransitionZoomFlipY>, allow_raw_pointers())
    .class_function("create", select_overload<TransitionZoomFlipY*(float, Scene*)>(&TransitionZoomFlipY::create), allow_raw_pointers())
    .class_function("create", select_overload<TransitionZoomFlipY*(float, Scene*, TransitionScene::Orientation)>(&TransitionZoomFlipY::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionZoomFlipY& _) -> std::string {return "TransitionZoomFlipY";}))    
    .allow_subclass<wrapper<TransitionZoomFlipY>>("cc.TransitionZoomFlipY._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionZoomFlipAngular, base<TransitionSceneOriented>>("cc.TransitionZoomFlipAngular")
    .constructor(&cc_bindings_constructor<TransitionZoomFlipAngular>, allow_raw_pointers())
    .class_function("create", select_overload<TransitionZoomFlipAngular*(float, Scene*)>(&TransitionZoomFlipAngular::create), allow_raw_pointers())
    .class_function("create", select_overload<TransitionZoomFlipAngular*(float, Scene*, TransitionScene::Orientation)>(&TransitionZoomFlipAngular::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionZoomFlipAngular& _) -> std::string {return "TransitionZoomFlipAngular";}))    
    .allow_subclass<wrapper<TransitionZoomFlipAngular>>("cc.TransitionZoomFlipAngular._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionFade, base<TransitionScene>>("cc.TransitionFade")
    .constructor(&cc_bindings_constructor<TransitionFade>, allow_raw_pointers())
    .function("initWithDuration", select_overload<bool(float, Scene*)>(&TransitionFade::initWithDuration), allow_raw_pointers())
    .function("initWithDuration", select_overload<bool(float, Scene*, const Color3B&)>(&TransitionFade::initWithDuration), allow_raw_pointers())
    .class_function("create", select_overload<TransitionFade*(float, Scene*)>(&TransitionFade::create), allow_raw_pointers())
    .class_function("create", select_overload<TransitionFade*(float, Scene*, const Color3B&)>(&TransitionFade::create), allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFade& _) -> std::string {return "TransitionFade";}))    
    .allow_subclass<wrapper<TransitionFade>>("cc.TransitionFade._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionCrossFade, base<TransitionScene>>("cc.TransitionCrossFade")
    .constructor(&cc_bindings_constructor<TransitionCrossFade>, allow_raw_pointers())
    .class_function("create", &TransitionCrossFade::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionCrossFade& _) -> std::string {return "TransitionCrossFade";}))    
    .allow_subclass<wrapper<TransitionCrossFade>>("cc.TransitionCrossFade._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionTurnOffTiles, base<TransitionScene>>("cc.TransitionTurnOffTiles")
    .constructor(&cc_bindings_constructor<TransitionTurnOffTiles>, allow_raw_pointers())
    .function("easeActionWithAction", &TransitionTurnOffTiles::easeActionWithAction, allow_raw_pointers())
    .class_function("create", &TransitionTurnOffTiles::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionTurnOffTiles& _) -> std::string {return "TransitionTurnOffTiles";}))    
    .allow_subclass<wrapper<TransitionTurnOffTiles>>("cc.TransitionTurnOffTiles._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionSplitCols, base<TransitionScene>>("cc.TransitionSplitCols")
    .constructor(&cc_bindings_constructor<TransitionSplitCols>, allow_raw_pointers())
    .function("action", &TransitionSplitCols::action, allow_raw_pointers())
    .function("easeActionWithAction", &TransitionSplitCols::easeActionWithAction, allow_raw_pointers())
    .class_function("create", &TransitionSplitCols::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSplitCols& _) -> std::string {return "TransitionSplitCols";}))    
    .allow_subclass<wrapper<TransitionSplitCols>>("cc.TransitionSplitCols._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionSplitRows, base<TransitionSplitCols>>("cc.TransitionSplitRows")
    .constructor(&cc_bindings_constructor<TransitionSplitRows>, allow_raw_pointers())
    .class_function("create", &TransitionSplitRows::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionSplitRows& _) -> std::string {return "TransitionSplitRows";}))    
    .allow_subclass<wrapper<TransitionSplitRows>>("cc.TransitionSplitRows._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionFadeTR, base<TransitionScene>>("cc.TransitionFadeTR")
    .constructor(&cc_bindings_constructor<TransitionFadeTR>, allow_raw_pointers())
    .function("easeActionWithAction", &TransitionFadeTR::easeActionWithAction, allow_raw_pointers())
    .function("actionWithSize", &TransitionFadeTR::actionWithSize, allow_raw_pointers())
    .class_function("create", &TransitionFadeTR::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFadeTR& _) -> std::string {return "TransitionFadeTR";}))    
    .allow_subclass<wrapper<TransitionFadeTR>>("cc.TransitionFadeTR._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionFadeBL, base<TransitionFadeTR>>("cc.TransitionFadeBL")
    .constructor(&cc_bindings_constructor<TransitionFadeBL>, allow_raw_pointers())
    .class_function("create", &TransitionFadeBL::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFadeBL& _) -> std::string {return "TransitionFadeBL";}))    
    .allow_subclass<wrapper<TransitionFadeBL>>("cc.TransitionFadeBL._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionFadeUp, base<TransitionFadeTR>>("cc.TransitionFadeUp")
    .constructor(&cc_bindings_constructor<TransitionFadeUp>, allow_raw_pointers())
    .class_function("create", &TransitionFadeUp::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFadeUp& _) -> std::string {return "TransitionFadeUp";}))    
    .allow_subclass<wrapper<TransitionFadeUp>>("cc.TransitionFadeUp._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionFadeDown, base<TransitionFadeTR>>("cc.TransitionFadeDown")
    .constructor(&cc_bindings_constructor<TransitionFadeDown>, allow_raw_pointers())
    .class_function("create", &TransitionFadeDown::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionFadeDown& _) -> std::string {return "TransitionFadeDown";}))    
    .allow_subclass<wrapper<TransitionFadeDown>>("cc.TransitionFadeDown._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionPageTurn, base<TransitionScene>>("cc.TransitionPageTurn")
    .constructor(&cc_bindings_constructor<TransitionPageTurn>, allow_raw_pointers())
    .function("actionWithSize", &TransitionPageTurn::actionWithSize, allow_raw_pointers())
    .function("initWithDuration", &TransitionPageTurn::initWithDuration, allow_raw_pointers())
    .class_function("create", &TransitionPageTurn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionPageTurn& _) -> std::string {return "TransitionPageTurn";}))    
    .allow_subclass<wrapper<TransitionPageTurn>>("cc.TransitionPageTurn._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionProgress, base<TransitionScene>>("cc.TransitionProgress")
    .constructor(&cc_bindings_constructor<TransitionProgress>, allow_raw_pointers())
    .class_function("create", &TransitionProgress::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgress& _) -> std::string {return "TransitionProgress";}))    
    .allow_subclass<wrapper<TransitionProgress>>("cc.TransitionProgress._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionProgressRadialCCW, base<TransitionProgress>>("cc.TransitionProgressRadialCCW")
    .constructor(&cc_bindings_constructor<TransitionProgressRadialCCW>, allow_raw_pointers())
    .class_function("create", &TransitionProgressRadialCCW::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressRadialCCW& _) -> std::string {return "TransitionProgressRadialCCW";}))    
    .allow_subclass<wrapper<TransitionProgressRadialCCW>>("cc.TransitionProgressRadialCCW._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionProgressRadialCW, base<TransitionProgress>>("cc.TransitionProgressRadialCW")
    .constructor(&cc_bindings_constructor<TransitionProgressRadialCW>, allow_raw_pointers())
    .class_function("create", &TransitionProgressRadialCW::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressRadialCW& _) -> std::string {return "TransitionProgressRadialCW";}))    
    .allow_subclass<wrapper<TransitionProgressRadialCW>>("cc.TransitionProgressRadialCW._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionProgressHorizontal, base<TransitionProgress>>("cc.TransitionProgressHorizontal")
    .constructor(&cc_bindings_constructor<TransitionProgressHorizontal>, allow_raw_pointers())
    .class_function("create", &TransitionProgressHorizontal::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressHorizontal& _) -> std::string {return "TransitionProgressHorizontal";}))    
    .allow_subclass<wrapper<TransitionProgressHorizontal>>("cc.TransitionProgressHorizontal._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionProgressVertical, base<TransitionProgress>>("cc.TransitionProgressVertical")
    .constructor(&cc_bindings_constructor<TransitionProgressVertical>, allow_raw_pointers())
    .class_function("create", &TransitionProgressVertical::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressVertical& _) -> std::string {return "TransitionProgressVertical";}))    
    .allow_subclass<wrapper<TransitionProgressVertical>>("cc.TransitionProgressVertical._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionProgressInOut, base<TransitionProgress>>("cc.TransitionProgressInOut")
    .constructor(&cc_bindings_constructor<TransitionProgressInOut>, allow_raw_pointers())
    .class_function("create", &TransitionProgressInOut::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressInOut& _) -> std::string {return "TransitionProgressInOut";}))    
    .allow_subclass<wrapper<TransitionProgressInOut>>("cc.TransitionProgressInOut._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;


  class_<TransitionProgressOutIn, base<TransitionProgress>>("cc.TransitionProgressOutIn")
    .constructor(&cc_bindings_constructor<TransitionProgressOutIn>, allow_raw_pointers())
    .class_function("create", &TransitionProgressOutIn::create, allow_raw_pointers())
    .property("_className",  optional_override([](const TransitionProgressOutIn& _) -> std::string {return "TransitionProgressOutIn";}))    
    .allow_subclass<wrapper<TransitionProgressOutIn>>("cc.TransitionProgressOutIn._extend")
    .class_function("_allowJSSubclass", &cc_bindings_getTrue)
    ;
}

CC_BINDINGS_BYPASS_DESTRUCTOR(GLProgramState);
CC_BINDINGS_BYPASS_DESTRUCTOR(RenderState);
CC_BINDINGS_BYPASS_DESTRUCTOR(Pass);
CC_BINDINGS_BYPASS_DESTRUCTOR(Technique);
CC_BINDINGS_BYPASS_DESTRUCTOR(Material);
CC_BINDINGS_BYPASS_DESTRUCTOR(SimpleAudioEngine);
