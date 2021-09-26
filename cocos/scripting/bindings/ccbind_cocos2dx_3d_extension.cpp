#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_3d_extension.hpp"
#include "cocos-ext.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(ccbind_cocos2dx_3d_extension) {


  class_<ParticleSystem3D, base<Node>>("jsb.ParticleSystem3D")
    .constructor<>()
    .function("getParticleQuota", &ParticleSystem3D::getParticleQuota, allow_raw_pointers())
    .function("resumeParticleSystem", &ParticleSystem3D::resumeParticleSystem, allow_raw_pointers())
    .function("startParticleSystem", &ParticleSystem3D::startParticleSystem, allow_raw_pointers())
    .function("isEnabled", &ParticleSystem3D::isEnabled, allow_raw_pointers())
    .function("getRender", &ParticleSystem3D::getRender, allow_raw_pointers())
    .function("isKeepLocal", &ParticleSystem3D::isKeepLocal, allow_raw_pointers())
    .function("setEnabled", &ParticleSystem3D::setEnabled, allow_raw_pointers())
    .function("pauseParticleSystem", &ParticleSystem3D::pauseParticleSystem, allow_raw_pointers())
    .function("getState", &ParticleSystem3D::getState, allow_raw_pointers())
    .function("getAliveParticleCount", &ParticleSystem3D::getAliveParticleCount, allow_raw_pointers())
    .function("setParticleQuota", &ParticleSystem3D::setParticleQuota, allow_raw_pointers())
    .function("stopParticleSystem", &ParticleSystem3D::stopParticleSystem, allow_raw_pointers())
    .function("setKeepLocal", &ParticleSystem3D::setKeepLocal, allow_raw_pointers())
    .property("_className",  optional_override([](const ParticleSystem3D& _) -> std::string {return "ParticleSystem3D";}))    
    ;


  class_<PUParticleSystem3D, base<ParticleSystem3D>>("jsb.PUParticleSystem3D")
    .constructor<>()
    .function("initWithFilePath", &PUParticleSystem3D::initWithFilePath, allow_raw_pointers())
    .function("getParticleSystemScaleVelocity", &PUParticleSystem3D::getParticleSystemScaleVelocity, allow_raw_pointers())
    .function("setEmittedSystemQuota", &PUParticleSystem3D::setEmittedSystemQuota, allow_raw_pointers())
    .function("getDefaultDepth", &PUParticleSystem3D::getDefaultDepth, allow_raw_pointers())
    .function("getEmittedSystemQuota", &PUParticleSystem3D::getEmittedSystemQuota, allow_raw_pointers())
    .function("initWithFilePathAndMaterialPath", &PUParticleSystem3D::initWithFilePathAndMaterialPath, allow_raw_pointers())
    .function("clearAllParticles", &PUParticleSystem3D::clearAllParticles, allow_raw_pointers())
    .function("forceUpdate", &PUParticleSystem3D::forceUpdate, allow_raw_pointers())
    .function("calulateRotationOffset", &PUParticleSystem3D::calulateRotationOffset, allow_raw_pointers())
    .function("getMaxVelocity", &PUParticleSystem3D::getMaxVelocity, allow_raw_pointers())
    .function("getMaterialName", &PUParticleSystem3D::getMaterialName, allow_raw_pointers())
    .function("getTimeElapsedSinceStart", &PUParticleSystem3D::getTimeElapsedSinceStart, allow_raw_pointers())
    .function("getEmittedEmitterQuota", &PUParticleSystem3D::getEmittedEmitterQuota, allow_raw_pointers())
    .function("isMarkedForEmission", &PUParticleSystem3D::isMarkedForEmission, allow_raw_pointers())
    .function("getDefaultWidth", &PUParticleSystem3D::getDefaultWidth, allow_raw_pointers())
    .function("setEmittedEmitterQuota", &PUParticleSystem3D::setEmittedEmitterQuota, allow_raw_pointers())
    .function("setMarkedForEmission", &PUParticleSystem3D::setMarkedForEmission, allow_raw_pointers())
    .function("clone", &PUParticleSystem3D::clone, allow_raw_pointers())
    .function("setDefaultWidth", &PUParticleSystem3D::setDefaultWidth, allow_raw_pointers())
    .function("copyAttributesTo", &PUParticleSystem3D::copyAttributesTo, allow_raw_pointers())
    .function("setMaterialName", &PUParticleSystem3D::setMaterialName, allow_raw_pointers())
    .function("getParentParticleSystem", &PUParticleSystem3D::getParentParticleSystem, allow_raw_pointers())
    .function("setMaxVelocity", &PUParticleSystem3D::setMaxVelocity, allow_raw_pointers())
    .function("getDefaultHeight", &PUParticleSystem3D::getDefaultHeight, allow_raw_pointers())
    .function("getDerivedPosition", &PUParticleSystem3D::getDerivedPosition, allow_raw_pointers())
    .function("rotationOffset", &PUParticleSystem3D::rotationOffset, allow_raw_pointers())
    .function("getDerivedOrientation", &PUParticleSystem3D::getDerivedOrientation, allow_raw_pointers())
    .function("removeAllEmitter", &PUParticleSystem3D::removeAllEmitter, allow_raw_pointers())
    .function("setParticleSystemScaleVelocity", &PUParticleSystem3D::setParticleSystemScaleVelocity, allow_raw_pointers())
    .function("getDerivedScale", &PUParticleSystem3D::getDerivedScale, allow_raw_pointers())
    .function("setDefaultHeight", &PUParticleSystem3D::setDefaultHeight, allow_raw_pointers())
    .function("removeAllListener", &PUParticleSystem3D::removeAllListener, allow_raw_pointers())
    .function("initSystem", &PUParticleSystem3D::initSystem, allow_raw_pointers())
    .function("setDefaultDepth", &PUParticleSystem3D::setDefaultDepth, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::PUParticleSystem3D*(const std::string&)>(&PUParticleSystem3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::PUParticleSystem3D*()>(&PUParticleSystem3D::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::PUParticleSystem3D*(const std::string&, const std::string&)>(&PUParticleSystem3D::create), allow_raw_pointers())
    .property("_className",  optional_override([](const PUParticleSystem3D& _) -> std::string {return "PUParticleSystem3D";}))    
    ;}