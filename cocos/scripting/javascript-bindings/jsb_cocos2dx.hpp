#ifndef __JSB_COCOS2DX_HPP__
#define __JSB_COCOS2DX_HPP__

#include "platform/CCSAXParser.h"

namespace cocos2d {
  namespace bindings {

    const char ASSOCIATED_OBJECT_KEY_SCHEDULE[] = "schedule";
    const char ASSOCIATED_OBJECT_KEY_SCHEDULE_UPDATE[] = "scheduleUpdate";

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

  }
}
#endif // end of __JSB_COCOS2DX_HPP__
