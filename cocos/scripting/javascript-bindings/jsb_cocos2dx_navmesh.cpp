#include "scripting/CCScriptBindings.h"
#include "scripting/javascript-bindings/jsb_cocos2dx_navmesh.hpp"
#if CC_USE_NAVMESH
#include "navmesh/CCNavMesh.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;

COCOS_BINDINGS(jsb_cocos2dx_navmesh) {

  value_object<NavMeshAgentParam>("_.NavMeshAgentParam")
    .field("radius", &NavMeshAgentParam::radius)
    .field("height", &NavMeshAgentParam::height)
    .field("maxAcceleration", &NavMeshAgentParam::maxAcceleration)
    .field("maxSpeed", &NavMeshAgentParam::maxSpeed)
    .field("collisionQueryRange", &NavMeshAgentParam::collisionQueryRange)
    .field("pathOptimizationRange", &NavMeshAgentParam::pathOptimizationRange)
    .field("separationWeight", &NavMeshAgentParam::separationWeight)
    .field("updateFlags", &NavMeshAgentParam::updateFlags)
    .field("obstacleAvoidanceType", &NavMeshAgentParam::obstacleAvoidanceType)
    .field("queryFilterType", &NavMeshAgentParam::queryFilterType)
    ;

  value_object<OffMeshLinkData>("_.OffMeshLinkData")
    .field("startPosition", &OffMeshLinkData::startPosition)
    .field("endPosition", &OffMeshLinkData::endPosition)
    ;

  class_<NavMeshAgent, base<Component>>("jsb.NavMeshAgent")
    .constructor(&cc_bindings_constructor<NavMeshAgent>, allow_raw_pointers())
    .function("setMaxSpeed", &NavMeshAgent::setMaxSpeed)
    .function("syncToNode", &NavMeshAgent::syncToNode)
    .function("completeOffMeshLink", &NavMeshAgent::completeOffMeshLink)
    .function("getSeparationWeight", &NavMeshAgent::getSeparationWeight)
    .function("setAutoTraverseOffMeshLink", &NavMeshAgent::setAutoTraverseOffMeshLink)
    .function("getCurrentVelocity", &NavMeshAgent::getCurrentVelocity)
    .function("syncToAgent", &NavMeshAgent::syncToAgent)
    .function("isOnOffMeshLink", &NavMeshAgent::isOnOffMeshLink)
    .function("setSeparationWeight", &NavMeshAgent::setSeparationWeight)
    .function("pause", &NavMeshAgent::pause)
    .function("setAutoOrientation", &NavMeshAgent::setAutoOrientation)
    .function("getHeight", &NavMeshAgent::getHeight)
    .function("getMaxSpeed", &NavMeshAgent::getMaxSpeed)
    .function("getCurrentOffMeshLinkData", &NavMeshAgent::getCurrentOffMeshLinkData)
    .function("getRadius", &NavMeshAgent::getRadius)
    .function("setSyncFlag", &NavMeshAgent::setSyncFlag)
    .function("getSyncFlag", &NavMeshAgent::getSyncFlag)
    .function("resume", &NavMeshAgent::resume)
    .function("stop", &NavMeshAgent::stop)
    .function("setMaxAcceleration", &NavMeshAgent::setMaxAcceleration)
    .function("setOrientationRefAxes", &NavMeshAgent::setOrientationRefAxes)
    .function("getMaxAcceleration", &NavMeshAgent::getMaxAcceleration)
    .function("setHeight", &NavMeshAgent::setHeight)
    .function("getObstacleAvoidanceType", &NavMeshAgent::getObstacleAvoidanceType)
    .function("getVelocity", &NavMeshAgent::getVelocity)
    .function("setRadius", &NavMeshAgent::setRadius)
    .function("setObstacleAvoidanceType", &NavMeshAgent::setObstacleAvoidanceType)
    // from manual
    .function("move", optional_override(
      [](NavMeshAgent& this_, const Vec3 &destination)
      {
        this_.move(destination);
      }
    ))
    .function("move", optional_override(
      [](NavMeshAgent& this_, const Vec3 &destination, const val &callback)
      {
        this_.move(destination, [callback](cocos2d::NavMeshAgent *agent, float totalTimeAfterMove)->void{
            callback(val(agent), val(totalTimeAfterMove));
        });
      }
    ))
    // end of manual
    .class_function("getNavMeshAgentComponentName", &NavMeshAgent::getNavMeshAgentComponentName)
    .class_function("create", &NavMeshAgent::create, allow_raw_pointers())
    .property("_className",  optional_override([](const NavMeshAgent& _) -> std::string {return "NavMeshAgent";}))    
    ;


  class_<NavMeshObstacle, base<Component>>("jsb.NavMeshObstacle")
    .constructor(&cc_bindings_constructor<NavMeshObstacle>, allow_raw_pointers())
    .function("getSyncFlag", &NavMeshObstacle::getSyncFlag)
    .function("initWith", &NavMeshObstacle::initWith)
    .function("syncToObstacle", &NavMeshObstacle::syncToObstacle)
    .function("syncToNode", &NavMeshObstacle::syncToNode)
    .function("getHeight", &NavMeshObstacle::getHeight)
    .function("setSyncFlag", &NavMeshObstacle::setSyncFlag)
    .function("getRadius", &NavMeshObstacle::getRadius)
    .class_function("create", &NavMeshObstacle::create, allow_raw_pointers())
    .class_function("getNavMeshObstacleComponentName", &NavMeshObstacle::getNavMeshObstacleComponentName)
    .property("_className",  optional_override([](const NavMeshObstacle& _) -> std::string {return "NavMeshObstacle";}))    
    ;


  class_<NavMesh>("jsb.NavMesh")
    .constructor(&cc_bindings_constructor<NavMesh>, allow_raw_pointers())
    .function("removeNavMeshObstacle", &NavMesh::removeNavMeshObstacle, allow_raw_pointers())
    .function("removeNavMeshAgent", &NavMesh::removeNavMeshAgent, allow_raw_pointers())
    .function("update", &NavMesh::update)
    .function("isDebugDrawEnabled", &NavMesh::isDebugDrawEnabled)
    .function("addNavMeshAgent", &NavMesh::addNavMeshAgent, allow_raw_pointers())
    .function("addNavMeshObstacle", &NavMesh::addNavMeshObstacle, allow_raw_pointers())
    .function("setDebugDrawEnable", &NavMesh::setDebugDrawEnable)
    .function("debugDraw", &NavMesh::debugDraw, allow_raw_pointers())
    .class_function("create", &NavMesh::create, allow_raw_pointers())
    .property("_className",  optional_override([](const NavMesh& _) -> std::string {return "NavMesh";}))    
    ;
}

#endif
