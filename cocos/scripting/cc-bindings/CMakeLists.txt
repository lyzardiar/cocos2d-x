set(cocos_root ${COCOS2DX_ROOT_PATH})

set(ccbind_bindings_files
    modules/ccbind_cocos2dx.cpp
    modules/ccbind_cocos2dx_3d.cpp
    modules/ccbind_cocos2dx_3d_extension.cpp
    modules/ccbind_cocos2dx_audioengine.cpp
    modules/ccbind_cocos2dx_builder.cpp
    modules/ccbind_cocos2dx_experimental_video.cpp
    modules/ccbind_cocos2dx_experimental_webView.cpp
    modules/ccbind_cocos2dx_extension.cpp
    modules/ccbind_cocos2dx_navmesh.cpp
    modules/ccbind_cocos2dx_network.cpp
    modules/ccbind_cocos2dx_physics3d.cpp
    modules/ccbind_cocos2dx_spine.cpp
    modules/ccbind_cocos2dx_studio.cpp
    modules/ccbind_cocos2dx_ui.cpp
    embind/bind.cpp
    )
set(ccbind_bindings_headers
    modules/ccbind_cocos2dx.hpp
    modules/ccbind_cocos2dx_3d.hpp
    modules/ccbind_cocos2dx_3d_extension.hpp
    modules/ccbind_cocos2dx_audioengine.hpp
    modules/ccbind_cocos2dx_builder.hpp
    modules/ccbind_cocos2dx_experimental_video.hpp
    modules/ccbind_cocos2dx_experimental_webView.hpp
    modules/ccbind_cocos2dx_extension.hpp
    modules/ccbind_cocos2dx_navmesh.hpp
    modules/ccbind_cocos2dx_network.hpp
    modules/ccbind_cocos2dx_physics3d.hpp
    modules/ccbind_cocos2dx_spine.hpp
    modules/ccbind_cocos2dx_studio.hpp
    modules/ccbind_cocos2dx_ui.hpp
    embind/bind.h
    embind/wire.h
    embind/val.h
    CCScriptBindings.h
    )

list(APPEND ccbind_bindings_files ${ccbind_bindings_headers})

add_library(ccbindcocos2d ${ccbind_bindings_files})
target_link_libraries(ccbindcocos2d cocos2d)
add_dependencies(ccbindcocos2d cocos2d)

target_include_directories(ccbindcocos2d
    INTERFACE ${cocos_root}/cocos/scripting/bindings
)

set_target_properties(ccbindcocos2d
                      PROPERTIES
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      FOLDER "Internal"
                      )

