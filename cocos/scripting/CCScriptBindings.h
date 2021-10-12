/****************************************************************************
 Copyright (c) 2010-2012 cocos2d-x.org
 Copyright (c) 2013-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __CC_SCRIPT_BINDINGS_H__
#define __CC_SCRIPT_BINDINGS_H__

#include "base/ccConfig.h"
#include <functional>
#include <emscripten/bind.h>

namespace cocos2d {
  namespace bindings {
    // Rename types from emscripten
    using allow_raw_pointers = emscripten::allow_raw_pointers;

    template<typename ClassType, typename BaseSpecifier = emscripten::internal::NoBaseClass>
      using class_ = emscripten::class_<ClassType, BaseSpecifier>;
    
    template<typename ClassType>
      using value_object = emscripten::value_object<ClassType>;

    template<typename LambdaType>
    inline emscripten::internal::LambdaSignature<LambdaType>* optional_override(const LambdaType& fp) {
        return emscripten::optional_override(fp);
    }

    template<typename ReturnType, typename... Args, typename... Policies>
    inline void function(const char* name, ReturnType (*fn)(Args...), Policies... policies) {
        emscripten::function(name, fn, std::forward<Policies>(policies)...);
    }

    using val = emscripten::val;

    template<typename BaseClass>
      using base = emscripten::base<BaseClass>;

    template<typename T>
      using wrapper = emscripten::wrapper<T>;

    // Generic binding helpers:
    template<int Index>
    struct arg {
        static constexpr int index = Index + 1;
    };

    struct ret_val {
        static constexpr int index = 0;
    };

    template<typename Slot>
    struct allow_raw_pointer : public allow_raw_pointers {
    };

    template<typename Signature>
    Signature* select_overload(Signature* fn) {
        return fn;
    };

    template<typename Signature, typename ClassType>
    auto select_overload(Signature (ClassType::*fn)) -> decltype(fn) {
        return fn;
    };

    template<typename ClassType, typename ReturnType, typename... Args>
    auto select_const(ReturnType (ClassType::*method)(Args...) const) -> decltype(method) {
        return method;
    };

    // Embind helpers
    template<typename T, bool R>
    bool cc_bindings_getBool(const T& obj) {
      return R;
    }

    static bool cc_bindings_ctor(const emscripten::val& obj) {   
        int ptr = obj["$$"]["ptr"].as<int>();
        emscripten::val::global("_native_js_global_map").call<void>("set", val(ptr), obj);
        return true;
    }

    template<typename T, typename... Args>
    T* cc_bindings_constructor(Args&&... args) {
      T *obj = new (std::nothrow) T(std::forward<Args>(args)...);
      return obj;
    }
  }
}

#define COCOS_BINDINGS(name)                                       \
    static struct CocosBindingInitializer_##name {                 \
        CocosBindingInitializer_##name();                          \
    } CocosBindingInitializer_##name##_instance;                   \
    CocosBindingInitializer_##name::CocosBindingInitializer_##name()

// Cocos2d style namespace
#define NS_CC_BINDINGS_BEGIN  namespace cocos2d{namespace bindings{
#define NS_CC_BINDINGS_END    }}
#define USING_NS_CC_BINDINGS  using namespace cocos2d::bindings

// Walkaround for Classes has protected/private desctrctor
#define CC_BINDINGS_BYPASS_DESTRUCTOR(T)                          \
namespace emscripten {                                            \
    namespace internal {                                          \
        template<> void raw_destructor<T>(T* _) {}                \
    }                                                             \
}

// Custom marshal vector<T> to JSArray
namespace emscripten {
namespace internal {

template <typename T, typename Allocator>
struct BindingType<std::vector<T, Allocator>> {
    using ValBinding = BindingType<val>;
    using WireType = ValBinding::WireType;

    static WireType toWireType(const std::vector<T, Allocator> &vec) {
        return ValBinding::toWireType(val::array(vec));
    }

    static std::vector<T, Allocator> fromWireType(WireType value) {
        return vecFromJSArray<T>(ValBinding::fromWireType(value));
    }
};


template <typename T>
struct TypeID<T,
              typename std::enable_if<std::is_same<
                  typename Canonicalized<T>::type,
                  std::vector<typename Canonicalized<T>::type::value_type,
                              typename Canonicalized<T>::type::allocator_type>>::value>::type> {
    static constexpr TYPEID get() { return TypeID<val>::get(); }
};

}  // namespace internal
}  // namespace emscripten

#endif // __CC_SCRIPT_BINDINGS_H__
