#include "scripting/cc-bindings/CCScriptBindings.h"
#include "scripting/cc-bindings/modules/ccbind_cocos2dx_3d_extension.hpp"
#include "cocos-ext.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(ccbind_cocos2dx_3d_extension) {


  class_<ParticleSystem3D, base<Node>>("jsb.ParticleSystem3D")
    .constructor(&cc_bindings_constructor<ParticleSystem3D>, allow_raw_pointers())
    .function("resumeParticleSystem", &ParticleSystem3D::resumeParticleSystem)
    .function("startParticleSystem", &ParticleSystem3D::startParticleSystem)
    .function("isEnabled", &ParticleSystem3D::isEnabled)
    .function("getRender", &ParticleSystem3D::getRender, allow_raw_pointers())
    .function("isKeepLocal", &ParticleSystem3D::isKeepLocal)
    .function("setEnabled", &ParticleSystem3D::setEnabled)
    .function("getParticleQuota", &ParticleSystem3D::getParticleQuota)
    .function("getBlendFunc", &ParticleSystem3D::getBlendFunc)
    .function("pauseParticleSystem", &ParticleSystem3D::pauseParticleSystem)
    .function("getState", optional_override(
        [](ParticleSystem3D& this_){
        return (int32_t)this_.getState();
      }))
    .function("getAliveParticleCount", &ParticleSystem3D::getAliveParticleCount)
    .function("setParticleQuota", &ParticleSystem3D::setParticleQuota)
    .function("setBlendFunc", &ParticleSystem3D::setBlendFunc)
    .function("stopParticleSystem", &ParticleSystem3D::stopParticleSystem)
    .function("setKeepLocal", &ParticleSystem3D::setKeepLocal)
    .property("_className",  optional_override([](const ParticleSystem3D& _) -> std::string {return "ParticleSystem3D";}))    
    ;


  class_<PUParticleSystem3D, base<ParticleSystem3D>>("jsb.PUParticleSystem3D")
    .constructor(&cc_bindings_constructor<PUParticleSystem3D>, allow_raw_pointers())
    .function("initWithFilePath", &PUParticleSystem3D::initWithFilePath)
    .function("getParticleSystemScaleVelocity", &PUParticleSystem3D::getParticleSystemScaleVelocity)
    .function("setEmittedSystemQuota", &PUParticleSystem3D::setEmittedSystemQuota)
    .function("getDefaultDepth", &PUParticleSystem3D::getDefaultDepth)
    .function("getEmittedSystemQuota", &PUParticleSystem3D::getEmittedSystemQuota)
    .function("initWithFilePathAndMaterialPath", &PUParticleSystem3D::initWithFilePathAndMaterialPath)
    .function("clearAllParticles", &PUParticleSystem3D::clearAllParticles)
    .function("getMaterialName", &PUParticleSystem3D::getMaterialName)
    .function("calulateRotationOffset", &PUParticleSystem3D::calulateRotationOffset)
    .function("getMaxVelocity", &PUParticleSystem3D::getMaxVelocity)
    .function("forceUpdate", &PUParticleSystem3D::forceUpdate)
    .function("getTimeElapsedSinceStart", &PUParticleSystem3D::getTimeElapsedSinceStart)
    .function("getEmittedEmitterQuota", &PUParticleSystem3D::getEmittedEmitterQuota)
    .function("isMarkedForEmission", &PUParticleSystem3D::isMarkedForEmission)
    .function("getDefaultWidth", &PUParticleSystem3D::getDefaultWidth)
    .function("setEmittedEmitterQuota", &PUParticleSystem3D::setEmittedEmitterQuota)
    .function("setMarkedForEmission", &PUParticleSystem3D::setMarkedForEmission)
    .function("clone", &PUParticleSystem3D::clone, allow_raw_pointers())
    .function("setDefaultWidth", &PUParticleSystem3D::setDefaultWidth)
    .function("copyAttributesTo", &PUParticleSystem3D::copyAttributesTo, allow_raw_pointers())
    .function("setMaterialName", &PUParticleSystem3D::setMaterialName)
    .function("getParentParticleSystem", &PUParticleSystem3D::getParentParticleSystem, allow_raw_pointers())
    .function("setMaxVelocity", &PUParticleSystem3D::setMaxVelocity)
    .function("getDefaultHeight", &PUParticleSystem3D::getDefaultHeight)
    .function("getDerivedPosition", &PUParticleSystem3D::getDerivedPosition)
    .function("rotationOffset", &PUParticleSystem3D::rotationOffset)
    .function("getDerivedOrientation", &PUParticleSystem3D::getDerivedOrientation)
    .function("removeAllEmitter", &PUParticleSystem3D::removeAllEmitter)
    .function("setParticleSystemScaleVelocity", &PUParticleSystem3D::setParticleSystemScaleVelocity)
    .function("getDerivedScale", &PUParticleSystem3D::getDerivedScale)
    .function("setDefaultHeight", &PUParticleSystem3D::setDefaultHeight)
    .function("removeAllListener", &PUParticleSystem3D::removeAllListener)
    .function("initSystem", &PUParticleSystem3D::initSystem)
    .function("setDefaultDepth", &PUParticleSystem3D::setDefaultDepth)
    .class_function("create", select_overload<cocos2d::PUParticleSystem3D*(const std::string&)>(&PUParticleSystem3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::PUParticleSystem3D*()>(&PUParticleSystem3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::PUParticleSystem3D*(const std::string&, const std::string&)>(&PUParticleSystem3D::create), allow_raw_pointers())
    .property("_className",  optional_override([](const PUParticleSystem3D& _) -> std::string {return "PUParticleSystem3D";}))    
    ;
}