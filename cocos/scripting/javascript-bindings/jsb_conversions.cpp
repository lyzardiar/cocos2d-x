#include "scripting/CCScriptBindings.h"
#include "scripting/javascript-bindings/jsb_conversions.h"
#include "3d/CCBundle3DData.h"
#include "3d/CCOBB.h"
#include "3d/CCRay.h"
#include "base/CCEventMouse.h"
#include "base/CCMap.h"
#include "base/CCValue.h"
#include "base/CCVector.h"
#include "base/ccTypes.h"
#include "deprecated/CCArray.h"
#include "math/CCAffineTransform.h"
#include "platform/CCPlatformMacros.h"
#include "renderer/CCGLProgram.h"
#include "assets-manager/Manifest.h"
#include "editor-support/cocostudio/CocosStudioExtension.h"

using namespace std;
using namespace std::placeholders;
using namespace cocos2d;
using namespace cocos2d::bindings;
using namespace cocos2d::extension;

COCOS_BINDINGS(jsb_conversions) {

  value_object<Point>("_.Point")
    .field("x", &Point::x)
    .field("y", &Point::y)
    ;
  value_object<Rect>("_.Rect")
    .field("origin", &Rect::origin)
    .field("size", &Rect::size)
    ;
  value_object<Size>("_.Size")
    .field("width", &Size::width)
    .field("height", &Size::height)
    ;
  value_object<Color4B>("_.Color4B")
    .field("r", &Color4B::r)
    .field("g", &Color4B::g)
    .field("b", &Color4B::b)
    .field("a", &Color4B::a)
    ;
  value_object<Color4F>("_.Color4F")
    .field("r", &Color4F::r)
    .field("g", &Color4F::g)
    .field("b", &Color4F::b)
    .field("a", &Color4F::a)
    ;
  value_object<Color3B>("_.Color3B")
    .field("r", &Color3B::r)
    .field("g", &Color3B::g)
    .field("b", &Color3B::b)
    ;
  
  value_object<Acceleration>("_.Acceleration")
    .field("x", &Acceleration::x)
    .field("y", &Acceleration::y)
    .field("z", &Acceleration::z)
    .field("timestamp", &Acceleration::timestamp)
    ;
  value_object<Quaternion>("_.Quaternion")
    .field("x", &Quaternion::x)
    .field("y", &Quaternion::y)
    .field("z", &Quaternion::z)
    .field("w", &Quaternion::w)
    ;
  value_object<OBB>("_.OBB")
    .field("center", &OBB::_center)
    .field("xAxis", &OBB::_xAxis)
    .field("yAxis", &OBB::_yAxis)
    .field("zAxis", &OBB::_zAxis)
    .field("extentX", &OBB::_extentX)
    .field("extentY", &OBB::_extentY)
    .field("extentZ", &OBB::_extentZ)
    .field("extents", &OBB::_extents)
    ;
  value_object<Ray>("_.Ray")
    .field("origin", &Ray::_origin)
    .field("direction", &Ray::_direction)
    ;
  value_object<AffineTransform>("_.AffineTransform")
    .field("a", &AffineTransform::a)
    .field("b", &AffineTransform::b)
    .field("c", &AffineTransform::c)
    .field("d", &AffineTransform::d)
    .field("tx", &AffineTransform::tx)
    .field("ty", &AffineTransform::ty)
    ;
  value_object<Vec3>("_.Vec3")
    .field("x", &Vec3::x)
    .field("y", &Vec3::y)
    .field("z", &Vec3::z)
    ;
  value_object<Vec4>("_.Vec4")
    .field("x", &Vec4::x)
    .field("y", &Vec4::y)
    .field("z", &Vec4::z)
    .field("w", &Vec4::w)
    ;
  value_object<BlendFunc>("_.BlendFunc")
    .field("src", &BlendFunc::src)
    .field("dst", &BlendFunc::dst)
    ;
  value_object<Tex2F>("_.Tex2F")
    .field("u", &Tex2F::u)
    .field("v", &Tex2F::v)
    ;
  value_object<Uniform>("_.Uniform")
    .field("location", &Uniform::location)
    .field("size", &Uniform::size)
    .field("type", &Uniform::type)
    .field("name", &Uniform::name)
    ;
  value_object<MeshVertexAttrib>("_.MeshVertexAttrib")
    .field("size", &MeshVertexAttrib::size)
    .field("type", &MeshVertexAttrib::type)
    .field("vertexAttrib", &MeshVertexAttrib::vertexAttrib)
    .field("attribSizeBytes", &MeshVertexAttrib::attribSizeBytes)
    ;
  value_object<ResourceData>("_.ResourceData")
    .field("type", &ResourceData::type)
    .field("file", &ResourceData::file)
    .field("plist", &ResourceData::plist)
    ;
  value_object<ManifestAsset>("_.ManifestAsset")
    .field("md5", &ManifestAsset::md5)
    .field("path", &ManifestAsset::path)
    .field("compressed", &ManifestAsset::compressed)
    .field("size", &ManifestAsset::size)
    .field("downloadState", &ManifestAsset::downloadState)
    ;
}
