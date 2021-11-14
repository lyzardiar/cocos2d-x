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
#include "base/CCVector.h"
#include "base/CCMap.h"
#include "base/CCScriptSupport.h"
#include "2d/CCNode.h"
#include "extensions/GUI/CCControlExtension/CCControl.h"
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
      
    template<typename ClassType>
      using value_array = emscripten::value_array<ClassType>;

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

    // NodeWrapper is used by class_::subclass so script can override onEnter, onExit, etc on script side
    template<typename T>
    class NodeWrapper : public T, public emscripten::internal::WrapperBase {
    public:
        typedef T class_type;

        template<typename... Args>
        explicit NodeWrapper(emscripten::val&& wrapped, Args&&... args)
            : T(std::forward<Args>(args)...)
            , wrapped(std::forward<emscripten::val>(wrapped))
        {}

        ~NodeWrapper() {
            if (notifyJSOnDestruction) {
                call<void>("__destruct");
            }
        }

        template<typename ReturnType, typename... Args>
        ReturnType call(const char* name, Args&&... args) const {
            return wrapped.call<ReturnType>(name, std::forward<Args>(args)...);
        }
        
        void onEnter() override
        {
            ScriptEngineProtocol* engine = ScriptEngineManager::getInstance()->getScriptEngine();
            if (engine->isCalledFromScript())
            {
                engine->setCalledFromScript(false);
                this->T::onEnter();
            }
            else
            {
                return call<void>("onEnter");
            }
        };

        void onEnterTransitionDidFinish() override
        {
            ScriptEngineProtocol* engine = ScriptEngineManager::getInstance()->getScriptEngine();
            if (engine->isCalledFromScript())
            {
                engine->setCalledFromScript(false);
                this->T::onEnterTransitionDidFinish();
            }
            else
            {
                return call<void>("onEnterTransitionDidFinish");
            }
        };

        void onExit() override
        {
            ScriptEngineProtocol* engine = ScriptEngineManager::getInstance()->getScriptEngine();
            if (engine->isCalledFromScript())
            {
                engine->setCalledFromScript(false);
                this->T::onExit();
            }
            else
            {
                return call<void>("onExit");
            }
        };

        void onExitTransitionDidStart() override
        {
            ScriptEngineProtocol* engine = ScriptEngineManager::getInstance()->getScriptEngine();
            if (engine->isCalledFromScript())
            {
                engine->setCalledFromScript(false);
                this->T::onExitTransitionDidStart();
            }
            else
            {
                return call<void>("onExitTransitionDidStart");
            }
        };

        void cleanup() override
        {
            ScriptEngineProtocol* engine = ScriptEngineManager::getInstance()->getScriptEngine();
            if (engine->isCalledFromScript())
            {
                engine->setCalledFromScript(false);
                this->T::cleanup();
            }
            else
            {
                return call<void>("cleanup");
            }
        };

    private:
        emscripten::val wrapped;
    };

    // Script subclasses NodeWrapper if it is a cocos::Node, otherwise wrapper<T>
    template<typename T>
      using wrapper = typename std::conditional<std::is_base_of<Node, T>::value, NodeWrapper<T>, emscripten::wrapper<T>>::type;
    
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
    inline bool cc_bindings_getTrue() {
      return true;
    }

    template<typename T, typename... Args>
    T* cc_bindings_constructor(Args&&... args) {
      T *obj = new (std::nothrow) T(std::forward<Args>(args)...);
      return obj;
    }

    inline unsigned int cc_bindings_uniqueID(val& v) 
    {
        static unsigned int u = 0; //No worry, this won't be inlined
        if (v["_uid"].isUndefined())
        {
            v.set("_uid", ++u);
            return u;
        }
        else
        {
            return v["_uid"].as<unsigned int>();
        }
    }

    class ValHolder 
    {
    public:
        ValHolder(const val& v): v_(v) {}
        val getVal() const { return v_; }
    private:
        val v_;
    };
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

#define CC_BINDINGS_ALLOW_RAW_POINTERS(T)                         \
namespace emscripten {                                            \
    namespace internal {                                          \
        template<>                                                \
        struct TypeID<T*> {                                       \
            static constexpr TYPEID get() {                       \
                return LightTypeID<T*>::get();                    \
            }                                                     \
        };                                                        \
    }                                                             \
}


// Custom marshal vector<T> to JSArray
namespace emscripten {
namespace internal {

template <typename T>
std::vector<T> stdvecFromJSArray(const val& v) {
    const size_t l = v["length"].as<size_t>();

    std::vector<T> rv;
    rv.reserve(l);
    for (size_t i = 0; i < l; ++i) {
        rv.push_back(v[i].as<T>(allow_raw_pointers()));
    }

    return rv;
};

template <typename T>
cocos2d::Vector<T> ccvecFromJSArray(const val& v) {
    const size_t l = v["length"].as<size_t>();

    cocos2d::Vector<T> rv;
    rv.reserve(l);
    for (size_t i = 0; i < l; ++i) {
        rv.pushBack(v[i].as<T>(allow_raw_pointers()));
    }

    return rv;
};

// custom marshal
// std::vector auto binding
template <typename T, typename Allocator>
struct BindingType<std::vector<T, Allocator>> {
    using ValBinding = BindingType<val>;
    using WireType = ValBinding::WireType;

    static WireType toWireType(const std::vector<T, Allocator> &vec) {
        return ValBinding::toWireType(val::array(vec));
    }

    static std::vector<T, Allocator> fromWireType(WireType value) {
        return stdvecFromJSArray<T>(ValBinding::fromWireType(value));
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

// CCVector auto binding
template <typename T>
struct BindingType<cocos2d::Vector<T>> {
    using ValBinding = BindingType<val>;
    using WireType = ValBinding::WireType;

    static WireType toWireType(const cocos2d::Vector<T> &vec) {
        return ValBinding::toWireType(val::array(vec.begin(), vec.end()));
    }

    static cocos2d::Vector<T> fromWireType(WireType value) {
        return ccvecFromJSArray<T>(ValBinding::fromWireType(value));
    }
};


template <typename T>
struct TypeID<T,
              typename std::enable_if<std::is_same<
                  typename Canonicalized<T>::type,
                  cocos2d::Vector<typename Canonicalized<T>::type::value_type>>::value>::type> {
    static constexpr TYPEID get() { return TypeID<val>::get(); }
};

// unordered_map auto binding
template <typename K, typename V>
struct BindingType<std::unordered_map<K, V>> {
    using ValBinding = BindingType<val>;
    using WireType = ValBinding::WireType;

    static WireType toWireType(const std::unordered_map<K, V> &map) {
        val v(val::object());
        for( const auto& i : map ) {
            v[i.first] = val(i.second);
        }
        return ValBinding::toWireType(v);
    }

    static std::unordered_map<K, V> fromWireType(WireType value) {
        const val& v = ValBinding::fromWireType(value);
        const val& entries = val::global("Object").call<val>("entries", v);
        const size_t l = entries["length"].as<size_t>();

        std::unordered_map<K, V> map;
        map.reserve(l);

        for (size_t i = 0; i < l; ++i) {
            const K& key = entries[i].as<K>(allow_raw_pointers());
            map.insert({key, v[key].template as<V>(allow_raw_pointers())});
        }
        
        return map;
    }
};

// CCMap auto binding
template <typename K, typename V>
struct BindingType<cocos2d::Map<K, V>> {
    using ValBinding = BindingType<val>;
    using WireType = ValBinding::WireType;

    static WireType toWireType(const cocos2d::Map<K, V> &map) {
        val v(val::object());
        for( const auto& i : map ) {
            v[i.first] = val(i.second);
        }
        return ValBinding::toWireType(v);
    }

    static cocos2d::Map<K, V> fromWireType(WireType value) {
        const val& v = ValBinding::fromWireType(value);
        const val& entries = val::global("Object").call<val>("entries", v);
        const size_t l = entries["length"].as<size_t>();

        cocos2d::Map<K, V> map;
        map.reserve(l);

        for (size_t i = 0; i < l; ++i) {
            const K& key = entries[i].as<K>(allow_raw_pointers());
            map.insert(key, v[key].template as<V>(allow_raw_pointers()));
        }
        
        return map;
    }
};


template <typename T>
struct TypeID<T,
              typename std::enable_if<std::is_same<
                  typename Canonicalized<T>::type,
                  cocos2d::Map<typename Canonicalized<T>::type::key_type, typename Canonicalized<T>::type::value_type>>::value>::type> {
    static constexpr TYPEID get() { return TypeID<val>::get(); }
};


// enum to int32_t auto binding
// NOTE: For now we don't use embind's enum solution. That says it's compatable with latest cocos2d-x, 
// but we have to declare enum value somewhere in JS, which cocos2d-x already did
// (or we still can if we want for specific case? e.g. we don't have a proper js file to declare enum for some plugin)
template<typename T>
struct BindingType<T, typename std::enable_if<std::is_enum<T>::value>::type> {
  typedef typename BindingType<int32_t>::WireType WireType;

  constexpr static WireType toWireType(const T& v) {
    return BindingType<int32_t>::toWireType(static_cast<int32_t>(v));
  }
  constexpr static T fromWireType(WireType v) {
    return static_cast<T>(BindingType<int32_t>::fromWireType(v));
  }
};

template <typename T>
struct TypeID<T, typename std::enable_if<std::is_enum<T>::value>::type> {
    static constexpr TYPEID get() { return TypeID<int32_t>::get(); }
};

// end of custom marshal

}  // namespace internal
}  // namespace emscripten

#endif // __CC_SCRIPT_BINDINGS_H__
