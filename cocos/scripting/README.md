The naming/structure here is a bit confusing, here are some explanations:

1. embind comes from emscripten: https://emscripten.org/docs/porting/connecting_cpp_and_javascript/embind.html
2. Eventually we will use embind for both js and Lua
3. javascript-bindings are actually js bindings currently in use on emscripten. It is, or will be compatible with js-bindings
4. js-bindings are actually spidermonkey bindings currently in use on native platform. We will ditch it once we can use embind and javascript-bindings with spidermonkey.
5. lua-bindings will be rewritten in embind once we get embind work with lua. It will remain compatible with orginal lua API. (Which is different from the js API)

The benefit of this new structure is that we can write binding code fairly easily if you look in the javascript-bindings. Lua bindings and js bindings can share same binding code. (They will not as they have different API, but new features might). We don't need bindings-generator anymore at that point of time as well as the tolua and tojs folders under tools.