Here are some plans:

1. We are using embind to bind js and c++ on emscripten: https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html
2. Eventually we will use embind for both spidermonkey and Lua, and also cpp for serialization and editor support.
3. emscripten-bindings contains js bindings which are currently used in emscripten. It is, as much as possible, compatible with spidermonkey bindings.
4. We will ditch spidermonkey js-bindings once we can use embind with spidermonkey. (THIS WILL NOT HAPPEN VERY SOON)
5. lua-bindings will be rewritten in embind once we get embind work with lua. It will remain compatible with orginal lua API.(THIS WILL NOT HAPPEN VERY SOON)

The benefit of this approach is that we can write binding code fairly easily if you look in the emscripten-bindings. Lua bindings and js bindings can share same binding code. (They are not as they have different exposed API, but new features might). We don't need bindings-generator anymore at that point of time as well as the tolua and tojs folders under tools.