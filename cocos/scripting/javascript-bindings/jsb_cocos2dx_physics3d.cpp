#include "scripting/CCScriptBindings.h"
#include "scripting/javascript-bindings/jsb_cocos2dx_physics3d.hpp"
#if CC_USE_3D_PHYSICS && CC_ENABLE_BULLET_INTEGRATION
#include "physics3d/CCPhysics3D.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

CC_BINDINGS_ALLOW_RAW_POINTERS(Physics3DObject)
CC_BINDINGS_ALLOW_RAW_POINTERS(Physics3DShape)

COCOS_BINDINGS(jsb_cocos2dx_physics3d) {

  value_object<Physics3DRigidBodyDes>("_.Physics3DRigidBodyDes")
    .field("mass", &Physics3DRigidBodyDes::mass)
    .field("localInertia", &Physics3DRigidBodyDes::localInertia)
    .field("originalTransform", &Physics3DRigidBodyDes::originalTransform)
    .field("shape", &Physics3DRigidBodyDes::shape)
    .field("disableSleep", &Physics3DRigidBodyDes::disableSleep)
    ;

  value_object<Physics3DCollisionInfo::CollisionPoint>("_.CollisionPoint")
    .field("localPositionOnA", &Physics3DCollisionInfo::CollisionPoint::localPositionOnA)
    .field("worldPositionOnA", &Physics3DCollisionInfo::CollisionPoint::worldPositionOnA)
    .field("localPositionOnB", &Physics3DCollisionInfo::CollisionPoint::localPositionOnB)
    .field("worldPositionOnB", &Physics3DCollisionInfo::CollisionPoint::worldPositionOnB)
    .field("worldNormalOnB", &Physics3DCollisionInfo::CollisionPoint::worldNormalOnB)
    ;

  value_object<Physics3DCollisionInfo>("_.Physics3DCollisionInfo")
    .field("objA", &Physics3DCollisionInfo::objA)
    .field("objB", &Physics3DCollisionInfo::objB)
    .field("collisionPointList", &Physics3DCollisionInfo::collisionPointList)
    ;

  value_object<Physics3DWorld::HitResult>("_.HitResult")
    .field("hitPosition", &Physics3DWorld::HitResult::hitPosition)
    .field("hitNormal", &Physics3DWorld::HitResult::hitNormal)
    .field("hitObj", &Physics3DWorld::HitResult::hitObj)
    ;

  class_<Physics3DShape>("jsb.Physics3DShape")
    .constructor(&cc_bindings_constructor<Physics3DShape>, allow_raw_pointers())
    .function("initConvexHull", &Physics3DShape::initConvexHull, allow_raw_pointers())
    .function("getbtShape", &Physics3DShape::getbtShape, allow_raw_pointers())
    .function("initSphere", &Physics3DShape::initSphere)
    .function("initBox", &Physics3DShape::initBox)
    .function("initCapsule", &Physics3DShape::initCapsule)
    .function("initCylinder", &Physics3DShape::initCylinder)
    .function("getShapeType", &Physics3DShape::getShapeType)
    .class_function("createBox", &Physics3DShape::createBox, allow_raw_pointers())
    .class_function("createCylinder", &Physics3DShape::createCylinder, allow_raw_pointers())
    .class_function("createConvexHull", &Physics3DShape::createConvexHull, allow_raw_pointers())
    .class_function("createCapsule", &Physics3DShape::createCapsule, allow_raw_pointers())
    .class_function("createSphere", &Physics3DShape::createSphere, allow_raw_pointers())
    // from manual
    .class_function("createMesh", optional_override(
      [](const std::vector<Vec3>& triangles, int numTriangles)
      {
        return Physics3DShape::createMesh(&triangles[0], numTriangles);
      }
    ), allow_raw_pointers())
    .class_function("createHeightfield", optional_override(
      [](int arg0, int arg1, const std::vector<float>& arg2, float arg3, float arg4, float arg5, bool arg6, bool arg7, bool arg8)
      {
        return Physics3DShape::createHeightfield(arg0, arg1, &arg2[0], arg3, arg4, arg5, arg6, arg7, arg8);
      }
    ), allow_raw_pointers())
    .class_function("createHeightfield", optional_override(
      [](int arg0, int arg1, const std::vector<float>& arg2, float arg3, float arg4, float arg5, bool arg6, bool arg7)
      {
        return Physics3DShape::createHeightfield(arg0, arg1, &arg2[0], arg3, arg4, arg5, arg6, arg7);
      }
    ), allow_raw_pointers())
    .function("initMesh", optional_override(
      [](Physics3DShape& this_, const std::vector<Vec3>& triangles, int numTriangles)
      {
        return this_.initMesh(&triangles[0], numTriangles);
      }
    ), allow_raw_pointers())
    .function("initHeightfield", optional_override(
      [](Physics3DShape& this_, int arg0, int arg1, const std::vector<float>& arg2, float arg3, float arg4, float arg5, bool arg6, bool arg7, bool arg8)
      {
        return this_.initHeightfield(arg0, arg1, &arg2[0], arg3, arg4, arg5, arg6, arg7, arg8);
      }
    ))
    // end of manual
    .property("_className",  optional_override([](const Physics3DShape& _) -> std::string {return "Physics3DShape";}))
    .allow_subclass<wrapper<Physics3DShape>>("jsb.Physics3DShape._extend")    
    ;

  class_<Physics3DObject>("jsb.Physics3DObject")
    .function("setUserData", &Physics3DObject::setUserData, allow_raw_pointers())
    .function("getUserData", &Physics3DObject::getUserData, allow_raw_pointers())
    .function("getObjType", &Physics3DObject::getObjType)
    .function("setPhysicsWorld", &Physics3DObject::setPhysicsWorld, allow_raw_pointers())
    .function("getWorldTransform", &Physics3DObject::getWorldTransform)
    .function("getPhysicsWorld", &Physics3DObject::getPhysicsWorld, allow_raw_pointers())
    .function("setMask", &Physics3DObject::setMask)
    .function("getCollisionCallback", &Physics3DObject::getCollisionCallback)
    .function("getMask", &Physics3DObject::getMask)
    .function("needCollisionCallback", &Physics3DObject::needCollisionCallback)
    // from manual
    .function("setCollisionCallback", optional_override(
      [](Physics3DObject& this_, const val& callback, const val& thisv)
      {
        auto lambda = [callback, thisv](const Physics3DCollisionInfo &ci) {
          callback.call<void>("call", thisv, val(ci));
        };
        this_.setCollisionCallback(lambda);
      }
    ))
    // end of manuall
    .property("_className",  optional_override([](const Physics3DObject& _) -> std::string {return "Physics3DObject";}))    
    ;


  class_<Physics3DRigidBody, base<Physics3DObject>>("jsb.Physics3DRigidBody")
    .constructor(&cc_bindings_constructor<Physics3DRigidBody>, allow_raw_pointers())
    .function("setGravity", &Physics3DRigidBody::setGravity)
    .function("getFriction", &Physics3DRigidBody::getFriction)
    .function("setAngularFactor", optional_override(
      [](Physics3DRigidBody& this_, const val& arg0){
      if (!arg0.isNumber())
      {
        return this_.setAngularFactor(arg0.as<const cocos2d::Vec3&>());
      } else 
      {
        return this_.setAngularFactor(arg0.as<float>());
      }
    }))
    .function("addConstraint", &Physics3DRigidBody::addConstraint, allow_raw_pointers())
    .function("getRigidBody", &Physics3DRigidBody::getRigidBody, allow_raw_pointers())
    .function("getTotalForce", &Physics3DRigidBody::getTotalForce)
    .function("getConstraintCount", &Physics3DRigidBody::getConstraintCount)
    .function("applyCentralForce", &Physics3DRigidBody::applyCentralForce)
    .function("setMassProps", &Physics3DRigidBody::setMassProps)
    .function("setFriction", &Physics3DRigidBody::setFriction)
    .function("setKinematic", &Physics3DRigidBody::setKinematic)
    .function("setDamping", &Physics3DRigidBody::setDamping)
    .function("applyImpulse", &Physics3DRigidBody::applyImpulse)
    .function("isKinematic", &Physics3DRigidBody::isKinematic)
    .function("applyTorque", &Physics3DRigidBody::applyTorque)
    .function("setCcdMotionThreshold", &Physics3DRigidBody::setCcdMotionThreshold)
    .function("setRollingFriction", &Physics3DRigidBody::setRollingFriction)
    .function("getCcdMotionThreshold", &Physics3DRigidBody::getCcdMotionThreshold)
    .function("getLinearFactor", &Physics3DRigidBody::getLinearFactor)
    .function("applyDamping", &Physics3DRigidBody::applyDamping)
    .function("getAngularVelocity", &Physics3DRigidBody::getAngularVelocity)
    .function("init", &Physics3DRigidBody::init, allow_raw_pointers())
    .function("applyTorqueImpulse", &Physics3DRigidBody::applyTorqueImpulse)
    .function("setActive", &Physics3DRigidBody::setActive)
    .function("setLinearFactor", &Physics3DRigidBody::setLinearFactor)
    .function("setLinearVelocity", &Physics3DRigidBody::setLinearVelocity)
    .function("getLinearVelocity", &Physics3DRigidBody::getLinearVelocity)
    .function("setCcdSweptSphereRadius", &Physics3DRigidBody::setCcdSweptSphereRadius)
    .function("applyForce", &Physics3DRigidBody::applyForce)
    .function("setAngularVelocity", &Physics3DRigidBody::setAngularVelocity)
    .function("applyCentralImpulse", &Physics3DRigidBody::applyCentralImpulse)
    .function("getGravity", &Physics3DRigidBody::getGravity)
    .function("getRollingFriction", &Physics3DRigidBody::getRollingFriction)
    .function("setCenterOfMassTransform", &Physics3DRigidBody::setCenterOfMassTransform)
    .function("setInvInertiaDiagLocal", &Physics3DRigidBody::setInvInertiaDiagLocal)
    .function("removeConstraint", optional_override(
      [](Physics3DRigidBody& this_, const val& arg0){
      if (!arg0.isNumber())
      {
        return this_.removeConstraint(arg0.as<cocos2d::Physics3DConstraint*>(allow_raw_pointers()));
      } else 
      {
        return this_.removeConstraint(arg0.as<unsigned int>());
      }
    }), allow_raw_pointers())
    .function("getTotalTorque", &Physics3DRigidBody::getTotalTorque)
    .function("getInvMass", &Physics3DRigidBody::getInvMass)
    .function("getConstraint", &Physics3DRigidBody::getConstraint, allow_raw_pointers())
    .function("getRestitution", &Physics3DRigidBody::getRestitution)
    .function("getCcdSweptSphereRadius", &Physics3DRigidBody::getCcdSweptSphereRadius)
    .function("getHitFraction", &Physics3DRigidBody::getHitFraction)
    .function("getAngularDamping", &Physics3DRigidBody::getAngularDamping)
    .function("getInvInertiaDiagLocal", &Physics3DRigidBody::getInvInertiaDiagLocal)
    .function("getCenterOfMassTransform", &Physics3DRigidBody::getCenterOfMassTransform)
    .function("getAngularFactor", &Physics3DRigidBody::getAngularFactor)
    .function("setRestitution", &Physics3DRigidBody::setRestitution)
    .function("setHitFraction", &Physics3DRigidBody::setHitFraction)
    .function("getLinearDamping", &Physics3DRigidBody::getLinearDamping)
    // from manual
    .class_function("create", &Physics3DRigidBody::create, allow_raw_pointers())
    // end of manual
    .property("_className",  optional_override([](const Physics3DRigidBody& _) -> std::string {return "Physics3DRigidBody";}))
    .allow_subclass<wrapper<Physics3DRigidBody>>("jsb.Physics3DRigidBody._extend")    
    ;


  class_<Physics3DComponent, base<Component>>("jsb.Physics3DComponent")
    .constructor(&cc_bindings_constructor<Physics3DComponent>, allow_raw_pointers())
    .function("syncNodeToPhysics", &Physics3DComponent::syncNodeToPhysics)
    .function("addToPhysicsWorld", &Physics3DComponent::addToPhysicsWorld, allow_raw_pointers())
    .function("syncPhysicsToNode", &Physics3DComponent::syncPhysicsToNode)
    .function("getPhysics3DObject", &Physics3DComponent::getPhysics3DObject, allow_raw_pointers())
    .function("setPhysics3DObject", &Physics3DComponent::setPhysics3DObject, allow_raw_pointers())
    .function("setSyncFlag", &Physics3DComponent::setSyncFlag)
    .function("setTransformInPhysics", &Physics3DComponent::setTransformInPhysics)
    .class_function("create", select_overload<cocos2d::Physics3DComponent*(cocos2d::Physics3DObject*, const cocos2d::Vec3&, const cocos2d::Quaternion&)>(&Physics3DComponent::create), allow_raw_pointers())
    .class_function("create", optional_override(
        [](cocos2d::Physics3DObject* arg0){
            return Physics3DComponent::create(arg0);
        }), allow_raw_pointers())
    .class_function("create", optional_override(
        [](cocos2d::Physics3DObject* arg0, const cocos2d::Vec3& arg1){
            return Physics3DComponent::create(arg0, arg1);
        }), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Physics3DComponent*()>(&Physics3DComponent::create), allow_raw_pointers())
    .class_function("getPhysics3DComponentName", &Physics3DComponent::getPhysics3DComponentName)
    .property("_className",  optional_override([](const Physics3DComponent& _) -> std::string {return "Physics3DComponent";}))
    .allow_subclass<wrapper<Physics3DComponent>>("jsb.Physics3DComponent._extend")    
    ;


  class_<PhysicsSprite3D, base<Sprite3D>>("jsb.PhysicsSprite3D")
    .constructor(&cc_bindings_constructor<PhysicsSprite3D>, allow_raw_pointers())
    .function("syncNodeToPhysics", &PhysicsSprite3D::syncNodeToPhysics)
    .function("syncPhysicsToNode", &PhysicsSprite3D::syncPhysicsToNode)
    .function("getPhysicsObj", &PhysicsSprite3D::getPhysicsObj, allow_raw_pointers())
    .function("setSyncFlag", &PhysicsSprite3D::setSyncFlag)
    // from manual
    .class_function("create", PhysicsSprite3D::create, allow_raw_pointers())
    .class_function("create", optional_override(
        [](const std::string &modelPath, Physics3DRigidBodyDes* rigidDes, const cocos2d::Vec3& translateInPhysics){
            return PhysicsSprite3D::create(modelPath, rigidDes, translateInPhysics);
        }), allow_raw_pointers())
    .class_function("create", optional_override(
        [](const std::string &modelPath, Physics3DRigidBodyDes* rigidDes){
            return PhysicsSprite3D::create(modelPath, rigidDes);
        }), allow_raw_pointers())
    // end of manual
   
    .property("_className",  optional_override([](const PhysicsSprite3D& _) -> std::string {return "PhysicsSprite3D";}))
    ;


  class_<Physics3DWorld>("jsb.Physics3DWorld")
    .constructor(&cc_bindings_constructor<Physics3DWorld>, allow_raw_pointers())
    .function("setGravity", &Physics3DWorld::setGravity)
    .function("stepSimulate", &Physics3DWorld::stepSimulate)
    .function("needCollisionChecking", &Physics3DWorld::needCollisionChecking)
    .function("collisionChecking", &Physics3DWorld::collisionChecking)
    .function("setGhostPairCallback", &Physics3DWorld::setGhostPairCallback)
    .function("init", &Physics3DWorld::init, allow_raw_pointers())
    .function("removeAllPhysics3DObjects", &Physics3DWorld::removeAllPhysics3DObjects)
    .function("isDebugDrawEnabled", &Physics3DWorld::isDebugDrawEnabled)
    .function("removeAllPhysics3DConstraints", &Physics3DWorld::removeAllPhysics3DConstraints)
    .function("getGravity", &Physics3DWorld::getGravity)
    .function("removePhysics3DConstraint", &Physics3DWorld::removePhysics3DConstraint, allow_raw_pointers())
    .function("addPhysics3DObject", &Physics3DWorld::addPhysics3DObject, allow_raw_pointers())
    .function("setDebugDrawEnable", &Physics3DWorld::setDebugDrawEnable)
    .function("removePhysics3DObject", &Physics3DWorld::removePhysics3DObject, allow_raw_pointers())
    .function("getPhysicsObject", &Physics3DWorld::getPhysicsObject, allow_raw_pointers())
    .function("addPhysics3DConstraint", &Physics3DWorld::addPhysics3DConstraint, allow_raw_pointers())
    .function("addPhysics3DConstraint", optional_override(
        [](Physics3DWorld& this_, cocos2d::Physics3DConstraint* arg0){
        return this_.addPhysics3DConstraint(arg0);
      }), allow_raw_pointers())
    .function("debugDraw", &Physics3DWorld::debugDraw, allow_raw_pointers())
    .function("sweepShape", &Physics3DWorld::sweepShape, allow_raw_pointers())
    // from manual
    .function("rayCast", optional_override(
      [](Physics3DWorld& this_, const cocos2d::Vec3& startPos, const cocos2d::Vec3& endPos){
        cocos2d::Physics3DWorld::HitResult ret;
        this_.rayCast(startPos, endPos, &ret);
        return ret;
      }), allow_raw_pointers())
    // end of manual
    .class_function("create", &Physics3DWorld::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3DWorld& _) -> std::string {return "Physics3DWorld";}))
    .allow_subclass<wrapper<Physics3DWorld>>("jsb.Physics3DWorld._extend")    
    ;

  class_<Physics3DConstraint>("jsb.Physics3DConstraint")
    .function("setEnabled", &Physics3DConstraint::setEnabled)
    .function("setBreakingImpulse", &Physics3DConstraint::setBreakingImpulse)
    .function("getUserData", &Physics3DConstraint::getUserData, allow_raw_pointers())
    .function("getBreakingImpulse", &Physics3DConstraint::getBreakingImpulse)
    .function("getBodyA", &Physics3DConstraint::getBodyA, allow_raw_pointers())
    .function("isEnabled", &Physics3DConstraint::isEnabled)
    .function("getOverrideNumSolverIterations", &Physics3DConstraint::getOverrideNumSolverIterations)
    .function("getBodyB", &Physics3DConstraint::getBodyB, allow_raw_pointers())
    .function("setOverrideNumSolverIterations", &Physics3DConstraint::setOverrideNumSolverIterations)
    .function("getConstraintType", &Physics3DConstraint::getConstraintType)
    .function("setUserData", &Physics3DConstraint::setUserData, allow_raw_pointers())
    .function("getbtContraint", &Physics3DConstraint::getbtContraint, allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3DConstraint& _) -> std::string {return "Physics3DConstraint";}))    
    ;


  class_<Physics3DPointToPointConstraint, base<Physics3DConstraint>>("jsb.Physics3DPointToPointConstraint")
    .constructor(&cc_bindings_constructor<Physics3DPointToPointConstraint>, allow_raw_pointers())
    .function("getPivotPointInA", &Physics3DPointToPointConstraint::getPivotPointInA)
    .function("getPivotPointInB", &Physics3DPointToPointConstraint::getPivotPointInB)
    .function("init", select_overload<bool(cocos2d::Physics3DRigidBody*, cocos2d::Physics3DRigidBody*, const cocos2d::Vec3&, const cocos2d::Vec3&)>(&Physics3DPointToPointConstraint::init), allow_raw_pointers())
    .function("init", select_overload<bool(cocos2d::Physics3DRigidBody*, const cocos2d::Vec3&)>(&Physics3DPointToPointConstraint::init), allow_raw_pointers())
    .function("setPivotPointInA", &Physics3DPointToPointConstraint::setPivotPointInA)
    .function("setPivotPointInB", &Physics3DPointToPointConstraint::setPivotPointInB)
    .class_function("create", select_overload<cocos2d::Physics3DPointToPointConstraint*(cocos2d::Physics3DRigidBody*, cocos2d::Physics3DRigidBody*, const cocos2d::Vec3&, const cocos2d::Vec3&)>(&Physics3DPointToPointConstraint::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Physics3DPointToPointConstraint*(cocos2d::Physics3DRigidBody*, const cocos2d::Vec3&)>(&Physics3DPointToPointConstraint::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3DPointToPointConstraint& _) -> std::string {return "Physics3DPointToPointConstraint";}))
    .allow_subclass<wrapper<Physics3DPointToPointConstraint>>("jsb.Physics3DPointToPointConstraint._extend")    
    ;


  class_<Physics3DHingeConstraint, base<Physics3DConstraint>>("jsb.Physics3DHingeConstraint")
    .constructor(&cc_bindings_constructor<Physics3DHingeConstraint>, allow_raw_pointers())
    .function("getHingeAngle", select_overload<float(const cocos2d::Mat4&, const cocos2d::Mat4&)>(&Physics3DHingeConstraint::getHingeAngle))
    .function("getHingeAngle", select_overload<float() const>(&Physics3DHingeConstraint::getHingeAngle))
    .function("getMotorTargetVelosity", &Physics3DHingeConstraint::getMotorTargetVelosity)
    .function("getFrameOffsetA", &Physics3DHingeConstraint::getFrameOffsetA)
    .function("getFrameOffsetB", &Physics3DHingeConstraint::getFrameOffsetB)
    .function("setMaxMotorImpulse", &Physics3DHingeConstraint::setMaxMotorImpulse)
    .function("enableAngularMotor", &Physics3DHingeConstraint::enableAngularMotor)
    .function("getUpperLimit", &Physics3DHingeConstraint::getUpperLimit)
    .function("getMaxMotorImpulse", &Physics3DHingeConstraint::getMaxMotorImpulse)
    .function("getLowerLimit", &Physics3DHingeConstraint::getLowerLimit)
    .function("setUseFrameOffset", &Physics3DHingeConstraint::setUseFrameOffset)
    .function("getEnableAngularMotor", &Physics3DHingeConstraint::getEnableAngularMotor)
    .function("enableMotor", &Physics3DHingeConstraint::enableMotor)
    .function("getBFrame", &Physics3DHingeConstraint::getBFrame)
    .function("setFrames", &Physics3DHingeConstraint::setFrames)
    .function("getUseFrameOffset", &Physics3DHingeConstraint::getUseFrameOffset)
    .function("setAngularOnly", &Physics3DHingeConstraint::setAngularOnly)
    .function("setLimit", &Physics3DHingeConstraint::setLimit)
    .function("setLimit", optional_override(
        [](Physics3DHingeConstraint& this_, float arg0, float arg1){
        return this_.setLimit(arg0, arg1);
      }))
    .function("setLimit", optional_override(
        [](Physics3DHingeConstraint& this_, float arg0, float arg1, float arg2){
        return this_.setLimit(arg0, arg1, arg2);
      }))
    .function("setLimit", optional_override(
        [](Physics3DHingeConstraint& this_, float arg0, float arg1, float arg2, float arg3){
        return this_.setLimit(arg0, arg1, arg2, arg3);
      }))
    .function("setMotorTarget", optional_override(
      [](Physics3DHingeConstraint& this_, const val& arg0, float arg1){
      if (!arg0.isNumber())
      {
        return this_.setMotorTarget(arg0.as<const cocos2d::Quaternion&>(), arg1);
      } else 
      {
        return this_.setMotorTarget(arg0.as<float>(), arg1);
      }
    }))
    .function("getAngularOnly", &Physics3DHingeConstraint::getAngularOnly)
    .function("setAxis", &Physics3DHingeConstraint::setAxis)
    .function("getAFrame", &Physics3DHingeConstraint::getAFrame)
    .class_function("create", optional_override(
        [](cocos2d::Physics3DRigidBody* arg0, const cocos2d::Mat4& arg1){
            return Physics3DHingeConstraint::create(arg0, arg1);
        }), allow_raw_pointers())
	.class_function("create", optional_override(
	  [](cocos2d::Physics3DRigidBody* arg0, const val& arg1, const val& arg2){
	  if (arg2.isTrue() || arg2.isFalse())
	  {
		return Physics3DHingeConstraint::create(arg0, arg1.as<const cocos2d::Mat4&>(), arg2.as<bool>());
	  } else 
	  {
		return Physics3DHingeConstraint::create(arg0, arg1.as<const cocos2d::Vec3&>(), arg2.as<const cocos2d::Vec3&>());
	  }
	  }), allow_raw_pointers())
	.class_function("create", optional_override(
	  [](cocos2d::Physics3DRigidBody* arg0, const val& arg1, const val& arg2, const val& arg3){
	  if (arg3.isTrue() || arg3.isFalse())
	  {
	  	  return Physics3DHingeConstraint::create(arg0, arg1.as<const cocos2d::Vec3&>(), arg2.as<const cocos2d::Vec3&>(), arg3.as<bool>());
	  } else 
	  {
	  	  return Physics3DHingeConstraint::create(arg0, arg1.as<Physics3DRigidBody*>(allow_raw_pointers()), arg2.as<const cocos2d::Mat4&>(), arg3.as<const cocos2d::Mat4&>());
	  }
	  }), allow_raw_pointers())
	.class_function("create", select_overload<cocos2d::Physics3DHingeConstraint*(cocos2d::Physics3DRigidBody*, cocos2d::Physics3DRigidBody*, const cocos2d::Mat4&, const cocos2d::Mat4&, bool)>(&Physics3DHingeConstraint::create), allow_raw_pointers())
    .class_function("create", optional_override(
        [](cocos2d::Physics3DRigidBody* arg0, cocos2d::Physics3DRigidBody* arg1, const cocos2d::Vec3& arg2, const cocos2d::Vec3& arg3, cocos2d::Vec3& arg4, cocos2d::Vec3& arg5){
            return Physics3DHingeConstraint::create(arg0, arg1, arg2, arg3, arg4, arg5);
        }), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Physics3DHingeConstraint*(cocos2d::Physics3DRigidBody*, cocos2d::Physics3DRigidBody*, const cocos2d::Vec3&, const cocos2d::Vec3&, cocos2d::Vec3&, cocos2d::Vec3&, bool)>(&Physics3DHingeConstraint::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3DHingeConstraint& _) -> std::string {return "Physics3DHingeConstraint";}))    
    ;


  class_<Physics3DSliderConstraint, base<Physics3DConstraint>>("jsb.Physics3DSliderConstraint")
    .constructor(&cc_bindings_constructor<Physics3DSliderConstraint>, allow_raw_pointers())
    .function("setPoweredAngMotor", &Physics3DSliderConstraint::setPoweredAngMotor)
    .function("getDampingLimAng", &Physics3DSliderConstraint::getDampingLimAng)
    .function("setRestitutionOrthoLin", &Physics3DSliderConstraint::setRestitutionOrthoLin)
    .function("setRestitutionDirLin", &Physics3DSliderConstraint::setRestitutionDirLin)
    .function("getLinearPos", &Physics3DSliderConstraint::getLinearPos)
    .function("getFrameOffsetA", &Physics3DSliderConstraint::getFrameOffsetA)
    .function("getFrameOffsetB", &Physics3DSliderConstraint::getFrameOffsetB)
    .function("setPoweredLinMotor", &Physics3DSliderConstraint::setPoweredLinMotor)
    .function("getDampingDirAng", &Physics3DSliderConstraint::getDampingDirAng)
    .function("getRestitutionLimLin", &Physics3DSliderConstraint::getRestitutionLimLin)
    .function("getSoftnessOrthoAng", &Physics3DSliderConstraint::getSoftnessOrthoAng)
    .function("setSoftnessOrthoLin", &Physics3DSliderConstraint::setSoftnessOrthoLin)
    .function("setSoftnessLimLin", &Physics3DSliderConstraint::setSoftnessLimLin)
    .function("getAngularPos", &Physics3DSliderConstraint::getAngularPos)
    .function("setRestitutionLimAng", &Physics3DSliderConstraint::setRestitutionLimAng)
    .function("setUpperLinLimit", &Physics3DSliderConstraint::setUpperLinLimit)
    .function("setDampingDirLin", &Physics3DSliderConstraint::setDampingDirLin)
    .function("getUpperAngLimit", &Physics3DSliderConstraint::getUpperAngLimit)
    .function("getDampingDirLin", &Physics3DSliderConstraint::getDampingDirLin)
    .function("getSoftnessDirAng", &Physics3DSliderConstraint::getSoftnessDirAng)
    .function("getPoweredAngMotor", &Physics3DSliderConstraint::getPoweredAngMotor)
    .function("setLowerAngLimit", &Physics3DSliderConstraint::setLowerAngLimit)
    .function("setUpperAngLimit", &Physics3DSliderConstraint::setUpperAngLimit)
    .function("setTargetLinMotorVelocity", &Physics3DSliderConstraint::setTargetLinMotorVelocity)
    .function("setDampingLimAng", &Physics3DSliderConstraint::setDampingLimAng)
    .function("getRestitutionLimAng", &Physics3DSliderConstraint::getRestitutionLimAng)
    .function("getUseFrameOffset", &Physics3DSliderConstraint::getUseFrameOffset)
    .function("getSoftnessOrthoLin", &Physics3DSliderConstraint::getSoftnessOrthoLin)
    .function("getDampingOrthoAng", &Physics3DSliderConstraint::getDampingOrthoAng)
    .function("setUseFrameOffset", &Physics3DSliderConstraint::setUseFrameOffset)
    .function("setLowerLinLimit", &Physics3DSliderConstraint::setLowerLinLimit)
    .function("getRestitutionDirLin", &Physics3DSliderConstraint::getRestitutionDirLin)
    .function("getTargetLinMotorVelocity", &Physics3DSliderConstraint::getTargetLinMotorVelocity)
    .function("getLowerLinLimit", &Physics3DSliderConstraint::getLowerLinLimit)
    .function("getSoftnessLimLin", &Physics3DSliderConstraint::getSoftnessLimLin)
    .function("setDampingOrthoAng", &Physics3DSliderConstraint::setDampingOrthoAng)
    .function("setSoftnessDirAng", &Physics3DSliderConstraint::setSoftnessDirAng)
    .function("getPoweredLinMotor", &Physics3DSliderConstraint::getPoweredLinMotor)
    .function("setRestitutionOrthoAng", &Physics3DSliderConstraint::setRestitutionOrthoAng)
    .function("setDampingDirAng", &Physics3DSliderConstraint::setDampingDirAng)
    .function("setFrames", &Physics3DSliderConstraint::setFrames)
    .function("getRestitutionOrthoAng", &Physics3DSliderConstraint::getRestitutionOrthoAng)
    .function("getMaxAngMotorForce", &Physics3DSliderConstraint::getMaxAngMotorForce)
    .function("getDampingOrthoLin", &Physics3DSliderConstraint::getDampingOrthoLin)
    .function("getUpperLinLimit", &Physics3DSliderConstraint::getUpperLinLimit)
    .function("setMaxLinMotorForce", &Physics3DSliderConstraint::setMaxLinMotorForce)
    .function("getRestitutionOrthoLin", &Physics3DSliderConstraint::getRestitutionOrthoLin)
    .function("setTargetAngMotorVelocity", &Physics3DSliderConstraint::setTargetAngMotorVelocity)
    .function("getSoftnessLimAng", &Physics3DSliderConstraint::getSoftnessLimAng)
    .function("setRestitutionDirAng", &Physics3DSliderConstraint::setRestitutionDirAng)
    .function("getDampingLimLin", &Physics3DSliderConstraint::getDampingLimLin)
    .function("getLowerAngLimit", &Physics3DSliderConstraint::getLowerAngLimit)
    .function("getRestitutionDirAng", &Physics3DSliderConstraint::getRestitutionDirAng)
    .function("getTargetAngMotorVelocity", &Physics3DSliderConstraint::getTargetAngMotorVelocity)
    .function("setRestitutionLimLin", &Physics3DSliderConstraint::setRestitutionLimLin)
    .function("getMaxLinMotorForce", &Physics3DSliderConstraint::getMaxLinMotorForce)
    .function("setDampingOrthoLin", &Physics3DSliderConstraint::setDampingOrthoLin)
    .function("setSoftnessOrthoAng", &Physics3DSliderConstraint::setSoftnessOrthoAng)
    .function("setDampingLimLin", &Physics3DSliderConstraint::setDampingLimLin)
    .function("setSoftnessDirLin", &Physics3DSliderConstraint::setSoftnessDirLin)
    .function("setMaxAngMotorForce", &Physics3DSliderConstraint::setMaxAngMotorForce)
    .function("getSoftnessDirLin", &Physics3DSliderConstraint::getSoftnessDirLin)
    .function("setSoftnessLimAng", &Physics3DSliderConstraint::setSoftnessLimAng)
    .function("getUseLinearReferenceFrameA", &Physics3DSliderConstraint::getUseLinearReferenceFrameA)
    .class_function("create", &Physics3DSliderConstraint::create, allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3DSliderConstraint& _) -> std::string {return "Physics3DSliderConstraint";}))    
    ;


  class_<Physics3DConeTwistConstraint, base<Physics3DConstraint>>("jsb.Physics3DConeTwistConstraint")
    .constructor(&cc_bindings_constructor<Physics3DConeTwistConstraint>, allow_raw_pointers())
    .function("getBFrame", &Physics3DConeTwistConstraint::getBFrame)
    .function("setFixThresh", &Physics3DConeTwistConstraint::setFixThresh)
    .function("getFrameOffsetB", &Physics3DConeTwistConstraint::getFrameOffsetB)
    .function("getFrameOffsetA", &Physics3DConeTwistConstraint::getFrameOffsetA)
    .function("getFixThresh", &Physics3DConeTwistConstraint::getFixThresh)
    .function("getSwingSpan2", &Physics3DConeTwistConstraint::getSwingSpan2)
    .function("getSwingSpan1", &Physics3DConeTwistConstraint::getSwingSpan1)
    .function("setMaxMotorImpulse", &Physics3DConeTwistConstraint::setMaxMotorImpulse)
    .function("setFrames", &Physics3DConeTwistConstraint::setFrames)
    .function("getTwistAngle", &Physics3DConeTwistConstraint::getTwistAngle)
    .function("GetPointForAngle", &Physics3DConeTwistConstraint::GetPointForAngle)
    .function("setMaxMotorImpulseNormalized", &Physics3DConeTwistConstraint::setMaxMotorImpulseNormalized)
    .function("getTwistSpan", &Physics3DConeTwistConstraint::getTwistSpan)
    .function("setDamping", &Physics3DConeTwistConstraint::setDamping)
    .function("setLimit", &Physics3DConeTwistConstraint::setLimit)
    .function("setLimit", optional_override(
        [](Physics3DConeTwistConstraint& this_, float arg0, float arg1, float arg2){
        return this_.setLimit(arg0, arg1, arg2);
      }))
    .function("setLimit", optional_override(
        [](Physics3DConeTwistConstraint& this_, float arg0, float arg1, float arg2, float arg3){
        return this_.setLimit(arg0, arg1, arg2, arg3);
      }))
    .function("setLimit", optional_override(
        [](Physics3DConeTwistConstraint& this_, float arg0, float arg1, float arg2, float arg3, float arg4){
        return this_.setLimit(arg0, arg1, arg2, arg3, arg4);
      }))
    .function("getAFrame", &Physics3DConeTwistConstraint::getAFrame)
    .function("enableMotor", &Physics3DConeTwistConstraint::enableMotor)
    .class_function("create", select_overload<cocos2d::Physics3DConeTwistConstraint*(cocos2d::Physics3DRigidBody*, cocos2d::Physics3DRigidBody*, const cocos2d::Mat4&, const cocos2d::Mat4&)>(&Physics3DConeTwistConstraint::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Physics3DConeTwistConstraint*(cocos2d::Physics3DRigidBody*, const cocos2d::Mat4&)>(&Physics3DConeTwistConstraint::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3DConeTwistConstraint& _) -> std::string {return "Physics3DConeTwistConstraint";}))    
    ;


  class_<Physics3D6DofConstraint, base<Physics3DConstraint>>("jsb.Physics3D6DofConstraint")
    .constructor(&cc_bindings_constructor<Physics3D6DofConstraint>, allow_raw_pointers())
    .function("setLinearLowerLimit", &Physics3D6DofConstraint::setLinearLowerLimit)
    .function("getLinearLowerLimit", &Physics3D6DofConstraint::getLinearLowerLimit)
    .function("getAngularUpperLimit", &Physics3D6DofConstraint::getAngularUpperLimit)
    .function("getUseFrameOffset", &Physics3D6DofConstraint::getUseFrameOffset)
    .function("getLinearUpperLimit", &Physics3D6DofConstraint::getLinearUpperLimit)
    .function("setAngularLowerLimit", &Physics3D6DofConstraint::setAngularLowerLimit)
    .function("isLimited", &Physics3D6DofConstraint::isLimited)
    .function("setUseFrameOffset", &Physics3D6DofConstraint::setUseFrameOffset)
    .function("setLinearUpperLimit", &Physics3D6DofConstraint::setLinearUpperLimit)
    .function("getAngularLowerLimit", &Physics3D6DofConstraint::getAngularLowerLimit)
    .function("setAngularUpperLimit", &Physics3D6DofConstraint::setAngularUpperLimit)
    .class_function("create", select_overload<cocos2d::Physics3D6DofConstraint*(cocos2d::Physics3DRigidBody*, const cocos2d::Mat4&, bool)>(&Physics3D6DofConstraint::create), allow_raw_pointers())
    .class_function("create", select_overload<cocos2d::Physics3D6DofConstraint*(cocos2d::Physics3DRigidBody*, cocos2d::Physics3DRigidBody*, const cocos2d::Mat4&, const cocos2d::Mat4&, bool)>(&Physics3D6DofConstraint::create), allow_raw_pointers())
    .property("_className",  optional_override([](const Physics3D6DofConstraint& _) -> std::string {return "Physics3D6DofConstraint";}))    
    ;
}

#endif

CC_BINDINGS_BYPASS_DESTRUCTOR(Physics3DConstraint);
