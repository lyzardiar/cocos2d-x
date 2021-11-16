set(cocos_root ${COCOS2DX_ROOT_PATH})

set(bindings_files
    manual/jsb_cocos2dx.cpp
    manual/jsb_cocos2dx_3d.cpp
    manual/jsb_cocos2dx_3d_extension.cpp
    manual/jsb_cocos2dx_audioengine.cpp
    manual/jsb_cocos2dx_builder.cpp
    manual/jsb_cocos2dx_experimental_video.cpp
    manual/jsb_cocos2dx_experimental_webView.cpp
    manual/jsb_cocos2dx_extension.cpp
    manual/jsb_cocos2dx_navmesh.cpp
    manual/jsb_cocos2dx_network.cpp
    manual/jsb_cocos2dx_physics3d.cpp
    manual/jsb_cocos2dx_spine.cpp
    manual/jsb_cocos2dx_studio.cpp
    manual/jsb_cocos2dx_ui.cpp
    manual/jsb_conversions.cpp
    manual/jsb_global.cpp
    CCScriptEngine.cpp
    )
set(bindings_headers
    CCScriptBindings.h
    CCScriptEngine.h
    )

list(APPEND bindings_files ${bindings_headers})

add_library(cocos2d_scripting ${bindings_files})
target_link_libraries(cocos2d_scripting cocos2d)
add_dependencies(cocos2d_scripting cocos2d)

target_include_directories(cocos2d_scripting
    INTERFACE ${cocos_root}/cocos/scripting/emscripten-bindings/bindings
)

set_target_properties(cocos2d_scripting
                      PROPERTIES
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      FOLDER "Internal"
                      )

