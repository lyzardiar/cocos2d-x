set(cocos_root ${COCOS2DX_ROOT_PATH})

set(bindings_files
    javascript-bindings/jsb_cocos2dx.cpp
    javascript-bindings/jsb_cocos2dx_3d.cpp
    javascript-bindings/jsb_cocos2dx_3d_extension.cpp
    javascript-bindings/jsb_cocos2dx_audioengine.cpp
    javascript-bindings/jsb_cocos2dx_builder.cpp
    javascript-bindings/jsb_cocos2dx_experimental_video.cpp
    javascript-bindings/jsb_cocos2dx_experimental_webView.cpp
    javascript-bindings/jsb_cocos2dx_extension.cpp
    javascript-bindings/jsb_cocos2dx_navmesh.cpp
    javascript-bindings/jsb_cocos2dx_network.cpp
    javascript-bindings/jsb_cocos2dx_physics3d.cpp
    javascript-bindings/jsb_cocos2dx_spine.cpp
    javascript-bindings/jsb_cocos2dx_studio.cpp
    javascript-bindings/jsb_cocos2dx_ui.cpp
    javascript-bindings/jsb_conversions.cpp
    javascript-bindings/jsb_global.cpp
    component/CCComponentJS.cpp
    CCScriptEngine.cpp
    )
set(bindings_headers
    javascript-bindings/jsb_cocos2dx.hpp
    javascript-bindings/jsb_cocos2dx_3d.hpp
    javascript-bindings/jsb_cocos2dx_3d_extension.hpp
    javascript-bindings/jsb_cocos2dx_audioengine.hpp
    javascript-bindings/jsb_cocos2dx_builder.hpp
    javascript-bindings/jsb_cocos2dx_experimental_video.hpp
    javascript-bindings/jsb_cocos2dx_experimental_webView.hpp
    javascript-bindings/jsb_cocos2dx_extension.hpp
    javascript-bindings/jsb_cocos2dx_navmesh.hpp
    javascript-bindings/jsb_cocos2dx_network.hpp
    javascript-bindings/jsb_cocos2dx_physics3d.hpp
    javascript-bindings/jsb_cocos2dx_spine.hpp
    javascript-bindings/jsb_cocos2dx_studio.hpp
    javascript-bindings/jsb_cocos2dx_ui.hpp
    javascript-bindings/jsb_conversions.h
    javascript-bindings/jsb_global.h
    component/CCComponentJS.h
    CCScriptBindings.h
    CCScriptEngine.h
    )

list(APPEND bindings_files ${bindings_headers})

add_library(cocos2d_scripting ${bindings_files})
target_link_libraries(cocos2d_scripting cocos2d)
add_dependencies(cocos2d_scripting cocos2d)

target_include_directories(cocos2d_scripting
    INTERFACE ${cocos_root}/cocos/scripting/bindings
)

set_target_properties(cocos2d_scripting
                      PROPERTIES
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      FOLDER "Internal"
                      )

