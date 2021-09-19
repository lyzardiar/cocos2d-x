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

#ifndef __SCRIPT_BINDINGS_H__
#define __SCRIPT_BINDINGS_H__

#if CC_ENABLE_COCOS_BINDINGS

#include <functional>
#include <emscripten/bind.h>

namespace cocos2d{
  namespace bindings {

    // Type self-registration in compile phase.
    // See: https://stackoverflow.com/questions/4790721/c-type-registration-at-compile-time-trick/21626087
    template <int N>
    struct Rank : Rank<N - 1> {};

    template <>
    struct Rank<0> {};

    template <class... Ts>
    struct TypeList {
      static const int size = sizeof...(Ts);
    };

    template <class List, class T>
    struct Append;

    template <class... Ts, class T>
    struct Append<TypeList<Ts...>, T> {
      typedef TypeList<Ts..., T> type;
    };

    TypeList<> GetTypes(Rank<0>) { return {}; }

    // Expose all the binding classes
    template <typename ... Types>
    void exposeTypes(TypeList<Types...>)
    {
        int dummy[] = {
            (exposeType<Types>(), 0)...
        };
        (void)dummy;
    }

    template <typename T>
    void exposeType()
    {
      // This should never happen
    }

    // Rename types from emscripten
    using allow_raw_pointers = emscripten::allow_raw_pointers;

    template<typename ClassType, typename BaseSpecifier = emscripten::internal::NoBaseClass>
      using class_ = emscripten::class_<ClassType, BaseSpecifier>;

    template<typename LambdaType>
    emscripten::internal::LambdaSignature<LambdaType>* optional_override(const LambdaType& fp) {
        return emscripten::optional_override(fp);
    }

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
  }
}

EMSCRIPTEN_BINDINGS(default_module) {
  // Maximum 256 binding blocks
  decltype(cocos2d::bindings::GetTypes(cocos2d::bindings::Rank<256>())) types;
  cocos2d::bindings::exposeTypes(types);
}

#define COCOS_BINDINGS(name)                \
  struct CocosBindingInitializer_##name{}; \
  template<> void cocos2d::bindings::exposeType<CocosBindingInitializer_##name>()

#endif // CC_ENABLE_COCOS_BINDINGS
#endif // __SCRIPT_BINDINGS_H__
