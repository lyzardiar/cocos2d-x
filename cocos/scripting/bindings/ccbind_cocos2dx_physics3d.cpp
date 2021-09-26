#include "scripting/bindings/CCScriptBindings.h"
#include "scripting/bindings/ccbind_cocos2dx_physics3d.hpp"
#if CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION
#include "physics3d/CCPhysics3D.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(ccbind_cocos2dx_physics3d) {


  class_<Physics3DShape>("jsb.Physics3DShape")
    .constructor<>()
    .function("initConvexHull", &Physics3DShape::initConvexHull, allow_raw_pointers())
    .function("getbtShape", &Physics3DShape::getbtShape, allow_raw_pointers())
    .function("initSphere", &Physics3DShape::initSphere, allow_raw_pointers())
    .function("initBox", &Physics3DShape::initBox, allow_raw_pointers())
    .function("initCapsule", &Physics3DShape::initCapsule, allow_raw_pointers())
    .function("initCylinder", &Physics3DShape::initCylinder, allow_raw_pointers())
    .function("getShapeType", &Physics3DShape::getShapeType, allow_raw_pointers())
    .class_function("createBox", &Physics3DShape::createBox, allow_raw_pointers())
    .class_function("createCylinder", &Physics3DShape::createCylinder, allow_raw_pointers())
    .class_function("createConvexHull", &Physics3DShape::createConvexHull, allow_raw_pointers())
    .class_function("createCapsule", &Physics3DShape::createCapsule, allow_raw_pointers())
    .class_function("createSphere", &Physics3DShape::createSphere, allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3DShape& _) -> std::string {return "Physics3DShape";}))    
    ;

  class_<Physics3DObject>("jsb.Physics3DObject")
    .function("setUserData", &Physics3DObject::setUserData, allow_raw_pointers())
    .function("getUserData", &Physics3DObject::getUserData, allow_raw_pointers())
    .function("getObjType", &Physics3DObject::getObjType, allow_raw_pointers())
    .function("setPhysicsWorld", &Physics3DObject::setPhysicsWorld, allow_raw_pointers())
    .function("getWorldTransform", &Physics3DObject::getWorldTransform, allow_raw_pointers())
    .function("getPhysicsWorld", &Physics3DObject::getPhysicsWorld, allow_raw_pointers())
    .function("setMask", &Physics3DObject::setMask, allow_raw_pointers())
    .function("getCollisionCallback", &Physics3DObject::getCollisionCallback, allow_raw_pointers())
    .function("getMask", &Physics3DObject::getMask, allow_raw_pointers())
    .function("needCollisionCallback", &Physics3DObject::needCollisionCallback, allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3DObject& _) -> std::string {return "Physics3DObject";}))    
    ;


  class_<Physics3DRigidBody, base<Physics3DObject>>("jsb.Physics3DRigidBody")
    .constructor<>()
    .function("setGravity", &Physics3DRigidBody::setGravity, allow_raw_pointers())
    .function("getFriction", &Physics3DRigidBody::getFriction, allow_raw_pointers())
    .function("setAngularFactor", select_overload<void(float)>(&Physics3DRigidBody::setAngularFactor), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("addConstraint", &Physics3DRigidBody::addConstraint, allow_raw_pointers())
    .function("getRigidBody", &Physics3DRigidBody::getRigidBody, allow_raw_pointers())
    .function("getTotalForce", &Physics3DRigidBody::getTotalForce, allow_raw_pointers())
    .function("getConstraintCount", &Physics3DRigidBody::getConstraintCount, allow_raw_pointers())
    .function("applyCentralForce", &Physics3DRigidBody::applyCentralForce, allow_raw_pointers())
    .function("setMassProps", &Physics3DRigidBody::setMassProps, allow_raw_pointers())
    .function("setFriction", &Physics3DRigidBody::setFriction, allow_raw_pointers())
    .function("setKinematic", &Physics3DRigidBody::setKinematic, allow_raw_pointers())
    .function("setDamping", &Physics3DRigidBody::setDamping, allow_raw_pointers())
    .function("applyImpulse", &Physics3DRigidBody::applyImpulse, allow_raw_pointers())
    .function("isKinematic", &Physics3DRigidBody::isKinematic, allow_raw_pointers())
    .function("applyTorque", &Physics3DRigidBody::applyTorque, allow_raw_pointers())
    .function("setCcdMotionThreshold", &Physics3DRigidBody::setCcdMotionThreshold, allow_raw_pointers())
    .function("setRollingFriction", &Physics3DRigidBody::setRollingFriction, allow_raw_pointers())
    .function("getCcdMotionThreshold", &Physics3DRigidBody::getCcdMotionThreshold, allow_raw_pointers())
    .function("getLinearFactor", &Physics3DRigidBody::getLinearFactor, allow_raw_pointers())
    .function("applyDamping", &Physics3DRigidBody::applyDamping, allow_raw_pointers())
    .function("getAngularVelocity", &Physics3DRigidBody::getAngularVelocity, allow_raw_pointers())
    .function("init", &Physics3DRigidBody::init, allow_raw_pointers())
    .function("applyTorqueImpulse", &Physics3DRigidBody::applyTorqueImpulse, allow_raw_pointers())
    .function("setActive", &Physics3DRigidBody::setActive, allow_raw_pointers())
    .function("setLinearFactor", &Physics3DRigidBody::setLinearFactor, allow_raw_pointers())
    .function("setLinearVelocity", &Physics3DRigidBody::setLinearVelocity, allow_raw_pointers())
    .function("getLinearVelocity", &Physics3DRigidBody::getLinearVelocity, allow_raw_pointers())
    .function("setCcdSweptSphereRadius", &Physics3DRigidBody::setCcdSweptSphereRadius, allow_raw_pointers())
    .function("applyForce", &Physics3DRigidBody::applyForce, allow_raw_pointers())
    .function("setAngularVelocity", &Physics3DRigidBody::setAngularVelocity, allow_raw_pointers())
    .function("applyCentralImpulse", &Physics3DRigidBody::applyCentralImpulse, allow_raw_pointers())
    .function("getGravity", &Physics3DRigidBody::getGravity, allow_raw_pointers())
    .function("getRollingFriction", &Physics3DRigidBody::getRollingFriction, allow_raw_pointers())
    .function("setCenterOfMassTransform", &Physics3DRigidBody::setCenterOfMassTransform, allow_raw_pointers())
    .function("setInvInertiaDiagLocal", &Physics3DRigidBody::setInvInertiaDiagLocal, allow_raw_pointers())
    .function("removeConstraint", select_overload<void(unsigned int)>(&Physics3DRigidBody::removeConstraint), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getTotalTorque", &Physics3DRigidBody::getTotalTorque, allow_raw_pointers())
    .function("getInvMass", &Physics3DRigidBody::getInvMass, allow_raw_pointers())
    .function("getConstraint", &Physics3DRigidBody::getConstraint, allow_raw_pointers())
    .function("getRestitution", &Physics3DRigidBody::getRestitution, allow_raw_pointers())
    .function("getCcdSweptSphereRadius", &Physics3DRigidBody::getCcdSweptSphereRadius, allow_raw_pointers())
    .function("getHitFraction", &Physics3DRigidBody::getHitFraction, allow_raw_pointers())
    .function("getAngularDamping", &Physics3DRigidBody::getAngularDamping, allow_raw_pointers())
    .function("getInvInertiaDiagLocal", &Physics3DRigidBody::getInvInertiaDiagLocal, allow_raw_pointers())
    .function("getCenterOfMassTransform", &Physics3DRigidBody::getCenterOfMassTransform, allow_raw_pointers())
    .function("getAngularFactor", &Physics3DRigidBody::getAngularFactor, allow_raw_pointers())
    .function("setRestitution", &Physics3DRigidBody::setRestitution, allow_raw_pointers())
    .function("setHitFraction", &Physics3DRigidBody::setHitFraction, allow_raw_pointers())
    .function("getLinearDamping", &Physics3DRigidBody::getLinearDamping, allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3DRigidBody& _) -> std::string {return "Physics3DRigidBody";}))    
    ;


  class_<Physics3DComponent, base<Component>>("jsb.Physics3DComponent")
    .constructor<>()
    .function("addToPhysicsWorld", &Physics3DComponent::addToPhysicsWorld, allow_raw_pointers())
    .function("syncPhysicsToNode", &Physics3DComponent::syncPhysicsToNode, allow_raw_pointers())
    .function("getPhysics3DObject", &Physics3DComponent::getPhysics3DObject, allow_raw_pointers())
    .function("setPhysics3DObject", &Physics3DComponent::setPhysics3DObject, allow_raw_pointers())
    .function("syncNodeToPhysics", &Physics3DComponent::syncNodeToPhysics, allow_raw_pointers())
    .function("setSyncFlag", &Physics3DComponent::setSyncFlag, allow_raw_pointers())
    .function("setTransformInPhysics", &Physics3DComponent::setTransformInPhysics, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Physics3DComponent*(cocos2d::Physics3DObject*, const cocos2d::Vec3&, const cocos2d::Quaternion&)>(&Physics3DComponent::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::Physics3DComponent*()>(&Physics3DComponent::create), allow_raw_pointers())
    .class_function("getPhysics3DComponentName", &Physics3DComponent::getPhysics3DComponentName, allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3DComponent& _) -> std::string {return "Physics3DComponent";}))    
    ;


  class_<PhysicsSprite3D, base<Sprite3D>>("jsb.PhysicsSprite3D")
    .constructor<>()
    .function("syncNodeToPhysics", &PhysicsSprite3D::syncNodeToPhysics, allow_raw_pointers())
    .function("syncPhysicsToNode", &PhysicsSprite3D::syncPhysicsToNode, allow_raw_pointers())
    .function("getPhysicsObj", &PhysicsSprite3D::getPhysicsObj, allow_raw_pointers())
    .function("setSyncFlag", &PhysicsSprite3D::setSyncFlag, allow_raw_pointers())
    .property("_className",  optional_override([](const PhysicsSprite3D& _) -> std::string {return "PhysicsSprite3D";}))    
    ;


  class_<Physics3DWorld>("jsb.Physics3DWorld")
    .constructor<>()
    .function("setGravity", &Physics3DWorld::setGravity, allow_raw_pointers())
    .function("stepSimulate", &Physics3DWorld::stepSimulate, allow_raw_pointers())
    .function("needCollisionChecking", &Physics3DWorld::needCollisionChecking, allow_raw_pointers())
    .function("collisionChecking", &Physics3DWorld::collisionChecking, allow_raw_pointers())
    .function("setGhostPairCallback", &Physics3DWorld::setGhostPairCallback, allow_raw_pointers())
    .function("init", &Physics3DWorld::init, allow_raw_pointers())
    .function("removeAllPhysics3DObjects", &Physics3DWorld::removeAllPhysics3DObjects, allow_raw_pointers())
    .function("isDebugDrawEnabled", &Physics3DWorld::isDebugDrawEnabled, allow_raw_pointers())
    .function("removeAllPhysics3DConstraints", &Physics3DWorld::removeAllPhysics3DConstraints, allow_raw_pointers())
    .function("getGravity", &Physics3DWorld::getGravity, allow_raw_pointers())
    .function("removePhysics3DConstraint", &Physics3DWorld::removePhysics3DConstraint, allow_raw_pointers())
    .function("addPhysics3DObject", &Physics3DWorld::addPhysics3DObject, allow_raw_pointers())
    .function("setDebugDrawEnable", &Physics3DWorld::setDebugDrawEnable, allow_raw_pointers())
    .function("removePhysics3DObject", &Physics3DWorld::removePhysics3DObject, allow_raw_pointers())
    .function("getPhysicsObject", &Physics3DWorld::getPhysicsObject, allow_raw_pointers())
    .function("addPhysics3DConstraint", &Physics3DWorld::addPhysics3DConstraint, allow_raw_pointers())
    .function("addPhysics3DConstraint", optional_override(
        [](Physics3DWorld& this_, cocos2d::Physics3DConstraint* arg0){
        return this_.addPhysics3DConstraint(arg0);
      }), allow_raw_pointers())
    .function("debugDraw", &Physics3DWorld::debugDraw, allow_raw_pointers())
    .function("sweepShape", &Physics3DWorld::sweepShape, allow_raw_pointers())
    .class_function("create", &Physics3DWorld::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3DWorld& _) -> std::string {return "Physics3DWorld";}))    
    ;

  class_<Physics3DConstraint>("jsb.Physics3DConstraint")
    .function("setEnabled", &Physics3DConstraint::setEnabled, allow_raw_pointers())
    .function("setBreakingImpulse", &Physics3DConstraint::setBreakingImpulse, allow_raw_pointers())
    .function("getUserData", &Physics3DConstraint::getUserData, allow_raw_pointers())
    .function("getBreakingImpulse", &Physics3DConstraint::getBreakingImpulse, allow_raw_pointers())
    .function("getBodyA", &Physics3DConstraint::getBodyA, allow_raw_pointers())
    .function("isEnabled", &Physics3DConstraint::isEnabled, allow_raw_pointers())
    .function("getOverrideNumSolverIterations", &Physics3DConstraint::getOverrideNumSolverIterations, allow_raw_pointers())
    .function("getBodyB", &Physics3DConstraint::getBodyB, allow_raw_pointers())
    .function("setOverrideNumSolverIterations", &Physics3DConstraint::setOverrideNumSolverIterations, allow_raw_pointers())
    .function("getConstraintType", &Physics3DConstraint::getConstraintType, allow_raw_pointers())
    .function("setUserData", &Physics3DConstraint::setUserData, allow_raw_pointers())
    .function("getbtContraint", &Physics3DConstraint::getbtContraint, allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3DConstraint& _) -> std::string {return "Physics3DConstraint";}))    
    ;


  class_<Physics3DPointToPointConstraint, base<Physics3DConstraint>>("jsb.Physics3DPointToPointConstraint")
    .constructor<>()
    .function("getPivotPointInA", &Physics3DPointToPointConstraint::getPivotPointInA, allow_raw_pointers())
    .function("getPivotPointInB", &Physics3DPointToPointConstraint::getPivotPointInB, allow_raw_pointers())
    .function("init", select_overload<bool(cocos2d::Physics3DRigidBody*, cocos2d::Physics3DRigidBody*, const cocos2d::Vec3&, const cocos2d::Vec3&)>(&Physics3DPointToPointConstraint::init), allow_raw_pointers())
    .function("init", select_overload<bool(cocos2d::Physics3DRigidBody*, const cocos2d::Vec3&)>(&Physics3DPointToPointConstraint::init), allow_raw_pointers())
    .function("setPivotPointInA", &Physics3DPointToPointConstraint::setPivotPointInA, allow_raw_pointers())
    .function("setPivotPointInB", &Physics3DPointToPointConstraint::setPivotPointInB, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Physics3DPointToPointConstraint*(cocos2d::Physics3DRigidBody*, cocos2d::Physics3DRigidBody*, const cocos2d::Vec3&, const cocos2d::Vec3&)>(&Physics3DPointToPointConstraint::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Physics3DPointToPointConstraint*(cocos2d::Physics3DRigidBody*, const cocos2d::Vec3&)>(&Physics3DPointToPointConstraint::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3DPointToPointConstraint& _) -> std::string {return "Physics3DPointToPointConstraint";}))    
    ;


  class_<Physics3DHingeConstraint, base<Physics3DConstraint>>("jsb.Physics3DHingeConstraint")
    .constructor<>()
    .function("getHingeAngle", select_overload<float(const cocos2d::Mat4&, const cocos2d::Mat4&)>(&Physics3DHingeConstraint::getHingeAngle), allow_raw_pointers())
    .function("getHingeAngle", select_overload<float() const>(&Physics3DHingeConstraint::getHingeAngle), allow_raw_pointers())
    .function("getMotorTargetVelosity", &Physics3DHingeConstraint::getMotorTargetVelosity, allow_raw_pointers())
    .function("getFrameOffsetA", &Physics3DHingeConstraint::getFrameOffsetA, allow_raw_pointers())
    .function("getFrameOffsetB", &Physics3DHingeConstraint::getFrameOffsetB, allow_raw_pointers())
    .function("setMaxMotorImpulse", &Physics3DHingeConstraint::setMaxMotorImpulse, allow_raw_pointers())
    .function("enableAngularMotor", &Physics3DHingeConstraint::enableAngularMotor, allow_raw_pointers())
    .function("getUpperLimit", &Physics3DHingeConstraint::getUpperLimit, allow_raw_pointers())
    .function("getMaxMotorImpulse", &Physics3DHingeConstraint::getMaxMotorImpulse, allow_raw_pointers())
    .function("getLowerLimit", &Physics3DHingeConstraint::getLowerLimit, allow_raw_pointers())
    .function("setUseFrameOffset", &Physics3DHingeConstraint::setUseFrameOffset, allow_raw_pointers())
    .function("getEnableAngularMotor", &Physics3DHingeConstraint::getEnableAngularMotor, allow_raw_pointers())
    .function("enableMotor", &Physics3DHingeConstraint::enableMotor, allow_raw_pointers())
    .function("getBFrame", &Physics3DHingeConstraint::getBFrame, allow_raw_pointers())
    .function("setFrames", &Physics3DHingeConstraint::setFrames, allow_raw_pointers())
    .function("getUseFrameOffset", &Physics3DHingeConstraint::getUseFrameOffset, allow_raw_pointers())
    .function("setAngularOnly", &Physics3DHingeConstraint::setAngularOnly, allow_raw_pointers())
    .function("setLimit", &Physics3DHingeConstraint::setLimit, allow_raw_pointers())
    .function("setLimit", optional_override(
        [](Physics3DHingeConstraint& this_, float arg0, float arg1){
        return this_.setLimit(arg0, arg1);
      }), allow_raw_pointers())
    .function("setLimit", optional_override(
        [](Physics3DHingeConstraint& this_, float arg0, float arg1, float arg2){
        return this_.setLimit(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("setLimit", optional_override(
        [](Physics3DHingeConstraint& this_, float arg0, float arg1, float arg2, float arg3){
        return this_.setLimit(arg0, arg1, arg2, arg3);
      }), allow_raw_pointers())
    .function("setMotorTarget", select_overload<void(float, float)>(&Physics3DHingeConstraint::setMotorTarget), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .function("getAngularOnly", &Physics3DHingeConstraint::getAngularOnly, allow_raw_pointers())
    .function("setAxis", &Physics3DHingeConstraint::setAxis, allow_raw_pointers())
    .function("getAFrame", &Physics3DHingeConstraint::getAFrame, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Physics3DHingeConstraint*(cocos2d::Physics3DRigidBody*, const cocos2d::Vec3&, const cocos2d::Vec3&, bool)>(&Physics3DHingeConstraint::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::Physics3DHingeConstraint*(cocos2d::Physics3DRigidBody*, const cocos2d::Mat4&, bool)>(&Physics3DHingeConstraint::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::Physics3DHingeConstraint*(cocos2d::Physics3DRigidBody*, cocos2d::Physics3DRigidBody*, const cocos2d::Vec3&, const cocos2d::Vec3&, cocos2d::Vec3&, cocos2d::Vec3&, bool)>(&Physics3DHingeConstraint::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .class_function("create", select_overload<cocos2d::Physics3DHingeConstraint*(cocos2d::Physics3DRigidBody*, cocos2d::Physics3DRigidBody*, const cocos2d::Mat4&, const cocos2d::Mat4&, bool)>(&Physics3DHingeConstraint::create), allow_raw_pointers())
    // TODO: Only support function overloading with different number of parameters
    .property("_className",  optional_override([](const Physics3DHingeConstraint& _) -> std::string {return "Physics3DHingeConstraint";}))    
    ;


  class_<Physics3DSliderConstraint, base<Physics3DConstraint>>("jsb.Physics3DSliderConstraint")
    .constructor<>()
    .function("setPoweredAngMotor", &Physics3DSliderConstraint::setPoweredAngMotor, allow_raw_pointers())
    .function("getDampingLimAng", &Physics3DSliderConstraint::getDampingLimAng, allow_raw_pointers())
    .function("setRestitutionOrthoLin", &Physics3DSliderConstraint::setRestitutionOrthoLin, allow_raw_pointers())
    .function("setRestitutionDirLin", &Physics3DSliderConstraint::setRestitutionDirLin, allow_raw_pointers())
    .function("getLinearPos", &Physics3DSliderConstraint::getLinearPos, allow_raw_pointers())
    .function("getFrameOffsetA", &Physics3DSliderConstraint::getFrameOffsetA, allow_raw_pointers())
    .function("getFrameOffsetB", &Physics3DSliderConstraint::getFrameOffsetB, allow_raw_pointers())
    .function("setPoweredLinMotor", &Physics3DSliderConstraint::setPoweredLinMotor, allow_raw_pointers())
    .function("getDampingDirAng", &Physics3DSliderConstraint::getDampingDirAng, allow_raw_pointers())
    .function("getRestitutionLimLin", &Physics3DSliderConstraint::getRestitutionLimLin, allow_raw_pointers())
    .function("getSoftnessOrthoAng", &Physics3DSliderConstraint::getSoftnessOrthoAng, allow_raw_pointers())
    .function("setSoftnessOrthoLin", &Physics3DSliderConstraint::setSoftnessOrthoLin, allow_raw_pointers())
    .function("setSoftnessLimLin", &Physics3DSliderConstraint::setSoftnessLimLin, allow_raw_pointers())
    .function("getAngularPos", &Physics3DSliderConstraint::getAngularPos, allow_raw_pointers())
    .function("setRestitutionLimAng", &Physics3DSliderConstraint::setRestitutionLimAng, allow_raw_pointers())
    .function("setUpperLinLimit", &Physics3DSliderConstraint::setUpperLinLimit, allow_raw_pointers())
    .function("setDampingDirLin", &Physics3DSliderConstraint::setDampingDirLin, allow_raw_pointers())
    .function("getUpperAngLimit", &Physics3DSliderConstraint::getUpperAngLimit, allow_raw_pointers())
    .function("getDampingDirLin", &Physics3DSliderConstraint::getDampingDirLin, allow_raw_pointers())
    .function("getSoftnessDirAng", &Physics3DSliderConstraint::getSoftnessDirAng, allow_raw_pointers())
    .function("getPoweredAngMotor", &Physics3DSliderConstraint::getPoweredAngMotor, allow_raw_pointers())
    .function("setLowerAngLimit", &Physics3DSliderConstraint::setLowerAngLimit, allow_raw_pointers())
    .function("setUpperAngLimit", &Physics3DSliderConstraint::setUpperAngLimit, allow_raw_pointers())
    .function("setTargetLinMotorVelocity", &Physics3DSliderConstraint::setTargetLinMotorVelocity, allow_raw_pointers())
    .function("setDampingLimAng", &Physics3DSliderConstraint::setDampingLimAng, allow_raw_pointers())
    .function("getRestitutionLimAng", &Physics3DSliderConstraint::getRestitutionLimAng, allow_raw_pointers())
    .function("getUseFrameOffset", &Physics3DSliderConstraint::getUseFrameOffset, allow_raw_pointers())
    .function("getSoftnessOrthoLin", &Physics3DSliderConstraint::getSoftnessOrthoLin, allow_raw_pointers())
    .function("getDampingOrthoAng", &Physics3DSliderConstraint::getDampingOrthoAng, allow_raw_pointers())
    .function("setUseFrameOffset", &Physics3DSliderConstraint::setUseFrameOffset, allow_raw_pointers())
    .function("setLowerLinLimit", &Physics3DSliderConstraint::setLowerLinLimit, allow_raw_pointers())
    .function("getRestitutionDirLin", &Physics3DSliderConstraint::getRestitutionDirLin, allow_raw_pointers())
    .function("getTargetLinMotorVelocity", &Physics3DSliderConstraint::getTargetLinMotorVelocity, allow_raw_pointers())
    .function("getLowerLinLimit", &Physics3DSliderConstraint::getLowerLinLimit, allow_raw_pointers())
    .function("getSoftnessLimLin", &Physics3DSliderConstraint::getSoftnessLimLin, allow_raw_pointers())
    .function("setDampingOrthoAng", &Physics3DSliderConstraint::setDampingOrthoAng, allow_raw_pointers())
    .function("setSoftnessDirAng", &Physics3DSliderConstraint::setSoftnessDirAng, allow_raw_pointers())
    .function("getPoweredLinMotor", &Physics3DSliderConstraint::getPoweredLinMotor, allow_raw_pointers())
    .function("setRestitutionOrthoAng", &Physics3DSliderConstraint::setRestitutionOrthoAng, allow_raw_pointers())
    .function("setDampingDirAng", &Physics3DSliderConstraint::setDampingDirAng, allow_raw_pointers())
    .function("setFrames", &Physics3DSliderConstraint::setFrames, allow_raw_pointers())
    .function("getRestitutionOrthoAng", &Physics3DSliderConstraint::getRestitutionOrthoAng, allow_raw_pointers())
    .function("getMaxAngMotorForce", &Physics3DSliderConstraint::getMaxAngMotorForce, allow_raw_pointers())
    .function("getDampingOrthoLin", &Physics3DSliderConstraint::getDampingOrthoLin, allow_raw_pointers())
    .function("getUpperLinLimit", &Physics3DSliderConstraint::getUpperLinLimit, allow_raw_pointers())
    .function("setMaxLinMotorForce", &Physics3DSliderConstraint::setMaxLinMotorForce, allow_raw_pointers())
    .function("getRestitutionOrthoLin", &Physics3DSliderConstraint::getRestitutionOrthoLin, allow_raw_pointers())
    .function("setTargetAngMotorVelocity", &Physics3DSliderConstraint::setTargetAngMotorVelocity, allow_raw_pointers())
    .function("getSoftnessLimAng", &Physics3DSliderConstraint::getSoftnessLimAng, allow_raw_pointers())
    .function("setRestitutionDirAng", &Physics3DSliderConstraint::setRestitutionDirAng, allow_raw_pointers())
    .function("getDampingLimLin", &Physics3DSliderConstraint::getDampingLimLin, allow_raw_pointers())
    .function("getLowerAngLimit", &Physics3DSliderConstraint::getLowerAngLimit, allow_raw_pointers())
    .function("getRestitutionDirAng", &Physics3DSliderConstraint::getRestitutionDirAng, allow_raw_pointers())
    .function("getTargetAngMotorVelocity", &Physics3DSliderConstraint::getTargetAngMotorVelocity, allow_raw_pointers())
    .function("setRestitutionLimLin", &Physics3DSliderConstraint::setRestitutionLimLin, allow_raw_pointers())
    .function("getMaxLinMotorForce", &Physics3DSliderConstraint::getMaxLinMotorForce, allow_raw_pointers())
    .function("setDampingOrthoLin", &Physics3DSliderConstraint::setDampingOrthoLin, allow_raw_pointers())
    .function("setSoftnessOrthoAng", &Physics3DSliderConstraint::setSoftnessOrthoAng, allow_raw_pointers())
    .function("setDampingLimLin", &Physics3DSliderConstraint::setDampingLimLin, allow_raw_pointers())
    .function("setSoftnessDirLin", &Physics3DSliderConstraint::setSoftnessDirLin, allow_raw_pointers())
    .function("setMaxAngMotorForce", &Physics3DSliderConstraint::setMaxAngMotorForce, allow_raw_pointers())
    .function("getSoftnessDirLin", &Physics3DSliderConstraint::getSoftnessDirLin, allow_raw_pointers())
    .function("setSoftnessLimAng", &Physics3DSliderConstraint::setSoftnessLimAng, allow_raw_pointers())
    .function("getUseLinearReferenceFrameA", &Physics3DSliderConstraint::getUseLinearReferenceFrameA, allow_raw_pointers())
    .class_function("create", &Physics3DSliderConstraint::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3DSliderConstraint& _) -> std::string {return "Physics3DSliderConstraint";}))    
    ;


  class_<Physics3DConeTwistConstraint, base<Physics3DConstraint>>("jsb.Physics3DConeTwistConstraint")
    .constructor<>()
    .function("getBFrame", &Physics3DConeTwistConstraint::getBFrame, allow_raw_pointers())
    .function("setFixThresh", &Physics3DConeTwistConstraint::setFixThresh, allow_raw_pointers())
    .function("getFrameOffsetB", &Physics3DConeTwistConstraint::getFrameOffsetB, allow_raw_pointers())
    .function("getFrameOffsetA", &Physics3DConeTwistConstraint::getFrameOffsetA, allow_raw_pointers())
    .function("getFixThresh", &Physics3DConeTwistConstraint::getFixThresh, allow_raw_pointers())
    .function("getSwingSpan2", &Physics3DConeTwistConstraint::getSwingSpan2, allow_raw_pointers())
    .function("getSwingSpan1", &Physics3DConeTwistConstraint::getSwingSpan1, allow_raw_pointers())
    .function("setMaxMotorImpulse", &Physics3DConeTwistConstraint::setMaxMotorImpulse, allow_raw_pointers())
    .function("setFrames", &Physics3DConeTwistConstraint::setFrames, allow_raw_pointers())
    .function("getTwistAngle", &Physics3DConeTwistConstraint::getTwistAngle, allow_raw_pointers())
    .function("GetPointForAngle", &Physics3DConeTwistConstraint::GetPointForAngle, allow_raw_pointers())
    .function("setMaxMotorImpulseNormalized", &Physics3DConeTwistConstraint::setMaxMotorImpulseNormalized, allow_raw_pointers())
    .function("getTwistSpan", &Physics3DConeTwistConstraint::getTwistSpan, allow_raw_pointers())
    .function("setDamping", &Physics3DConeTwistConstraint::setDamping, allow_raw_pointers())
    .function("setLimit", &Physics3DConeTwistConstraint::setLimit, allow_raw_pointers())
    .function("setLimit", optional_override(
        [](Physics3DConeTwistConstraint& this_, float arg0, float arg1, float arg2){
        return this_.setLimit(arg0, arg1, arg2);
      }), allow_raw_pointers())
    .function("setLimit", optional_override(
        [](Physics3DConeTwistConstraint& this_, float arg0, float arg1, float arg2, float arg3){
        return this_.setLimit(arg0, arg1, arg2, arg3);
      }), allow_raw_pointers())
    .function("setLimit", optional_override(
        [](Physics3DConeTwistConstraint& this_, float arg0, float arg1, float arg2, float arg3, float arg4){
        return this_.setLimit(arg0, arg1, arg2, arg3, arg4);
      }), allow_raw_pointers())
    .function("getAFrame", &Physics3DConeTwistConstraint::getAFrame, allow_raw_pointers())
    .function("enableMotor", &Physics3DConeTwistConstraint::enableMotor, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Physics3DConeTwistConstraint*(cocos2d::Physics3DRigidBody*, cocos2d::Physics3DRigidBody*, const cocos2d::Mat4&, const cocos2d::Mat4&)>(&Physics3DConeTwistConstraint::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Physics3DConeTwistConstraint*(cocos2d::Physics3DRigidBody*, const cocos2d::Mat4&)>(&Physics3DConeTwistConstraint::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3DConeTwistConstraint& _) -> std::string {return "Physics3DConeTwistConstraint";}))    
    ;


  class_<Physics3D6DofConstraint, base<Physics3DConstraint>>("jsb.Physics3D6DofConstraint")
    .constructor<>()
    .function("setLinearLowerLimit", &Physics3D6DofConstraint::setLinearLowerLimit, allow_raw_pointers())
    .function("getLinearLowerLimit", &Physics3D6DofConstraint::getLinearLowerLimit, allow_raw_pointers())
    .function("getAngularUpperLimit", &Physics3D6DofConstraint::getAngularUpperLimit, allow_raw_pointers())
    .function("getUseFrameOffset", &Physics3D6DofConstraint::getUseFrameOffset, allow_raw_pointers())
    .function("getLinearUpperLimit", &Physics3D6DofConstraint::getLinearUpperLimit, allow_raw_pointers())
    .function("setAngularLowerLimit", &Physics3D6DofConstraint::setAngularLowerLimit, allow_raw_pointers())
    .function("isLimited", &Physics3D6DofConstraint::isLimited, allow_raw_pointers())
    .function("setUseFrameOffset", &Physics3D6DofConstraint::setUseFrameOffset, allow_raw_pointers())
    .function("setLinearUpperLimit", &Physics3D6DofConstraint::setLinearUpperLimit, allow_raw_pointers())
    .function("getAngularLowerLimit", &Physics3D6DofConstraint::getAngularLowerLimit, allow_raw_pointers())
    .function("setAngularUpperLimit", &Physics3D6DofConstraint::setAngularUpperLimit, allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Physics3D6DofConstraint*(cocos2d::Physics3DRigidBody*, const cocos2d::Mat4&, bool)>(&Physics3D6DofConstraint::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Physics3D6DofConstraint*(cocos2d::Physics3DRigidBody*, cocos2d::Physics3DRigidBody*, const cocos2d::Mat4&, const cocos2d::Mat4&, bool)>(&Physics3D6DofConstraint::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3D6DofConstraint& _) -> std::string {return "Physics3D6DofConstraint";}))    
    ;}