#ifndef __JSB_COCOS2DX_HPP__
#define __JSB_COCOS2DX_HPP__

#include "platform/CCSAXParser.h"

namespace cocos2d {
  namespace bindings {
    class __JSPlistDelegator: public cocos2d::SAXDelegator
    {
    public:
        static __JSPlistDelegator* getInstance() {
            static __JSPlistDelegator* pInstance = NULL;
            if (pInstance == NULL) {
                pInstance = new (std::nothrow) __JSPlistDelegator();
            }
            return pInstance;
        };

        ~__JSPlistDelegator();

        cocos2d::SAXParser* getParser();

        std::string parse(const std::string& path);
        std::string parseText(const std::string& text);

        // implement pure virtual methods of SAXDelegator
        void startElement(void *ctx, const char *name, const char **atts) override;
        void endElement(void *ctx, const char *name) override;
        void textHandler(void *ctx, const char *ch, size_t len) override;

    private:
        cocos2d::SAXParser _parser;
        std::string _result;
        bool _isStoringCharacters;
        std::string _currentValue;
    };

    
    class NodeWrapper : public wrapper<Node> {
    public:
        EMSCRIPTEN_WRAPPER(NodeWrapper);
        void onEnter() {
            return call<void>("onEnter");
        };

        void onEnterTransitionDidFinish() {
            return call<void>("onEnterTransitionDidFinish");
        };

        void onExit() {
            return call<void>("onExit");
        };

        void onExitTransitionDidStart() {
            return call<void>("onExitTransitionDidStart");
        };

        void cleanup() {
            return call<void>("cleanup");
        };
    };

    // ComponentJS for emscripten
    class ComponentJS : public Component {};

    class ComponentJSWrapper : public wrapper<ComponentJS>
    {
    public:
        EMSCRIPTEN_WRAPPER(ComponentJSWrapper);

        void onEnter() override
        {
            return call<void>("onEnter");
        };

        void onExit() override
        {
            return call<void>("onExit");
        };

        void update(float dt) override
        {
            return call<void>("update", val(dt));
        };
    };
    // end of ComponentJS
    
    
    enum ACTION_TAG {
        EASE_IN = 0,
        EASE_OUT,
        EASE_INOUT,
        EASE_EXPONENTIAL_IN,
        EASE_EXPONENTIAL_OUT,
        EASE_EXPONENTIAL_INOUT,
        EASE_SINE_IN,
        EASE_SINE_OUT,
        EASE_SINE_INOUT,
        EASE_ELASTIC_IN,
        EASE_ELASTIC_OUT,
        EASE_ELASTIC_INOUT,
        EASE_BOUNCE_IN,
        EASE_BOUNCE_OUT,
        EASE_BOUNCE_INOUT,
        EASE_BACK_IN,
        EASE_BACK_OUT,
        EASE_BACK_INOUT,

        EASE_BEZIER_ACTION,
        EASE_QUADRATIC_IN,
        EASE_QUADRATIC_OUT,
        EASE_QUADRATIC_INOUT,
        EASE_QUARTIC_IN,
        EASE_QUARTIC_OUT,
        EASE_QUARTIC_INOUT,
        EASE_QUINTIC_IN,
        EASE_QUINTIC_OUT,
        EASE_QUINTIC_INOUT,
        EASE_CIRCLE_IN,
        EASE_CIRCLE_OUT,
        EASE_CIRCLE_INOUT,
        EASE_CUBIC_IN,
        EASE_CUBIC_OUT,
        EASE_CUBIC_INOUT
    };
  }
}
#endif // end of __JSB_COCOS2DX_HPP__
