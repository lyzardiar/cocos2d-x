set(cocos_root ${COCOS2DX_ROOT_PATH})

set(js_embind_bindings_manual_headers
    manual/js_embind_cocos2dx_manual.hpp
    manual/CCScriptBindings.h
    )

set(js_embind_bindings_manual_files
    manual/js_embind_cocos2dx_manual.cpp
    manual/CCScriptBindings.cpp
    )

set(js_embind_bindings_auto_headers)

set(js_embind_bindings_auto_files)

set(js_embind_bindings_files
    ${js_embind_bindings_manual_files}
    ${js_embind_bindings_auto_files}
    )
set(js_embind_bindings_headers
    ${js_embind_bindings_manual_headers}
    ${js_embind_bindings_auto_headers}
    )

list(APPEND js_embind_bindings_files ${js_embind_bindings_headers})

add_library(jsembindcocos2d ${js_embind_bindings_files})
target_link_libraries(jsembindcocos2d cocos2d)
add_dependencies(jsembindcocos2d cocos2d)

target_include_directories(jsembindcocos2d
    INTERFACE ${cocos_root}/cocos/scripting/js-embind-bindings/auto
    INTERFACE ${cocos_root}/cocos/scripting/js-embind-bindings/manual
)

set_target_properties(jsembindcocos2d
                      PROPERTIES
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      FOLDER "Internal"
                      )

