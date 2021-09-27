set(cocos_root ${COCOS2DX_ROOT_PATH})

set(ccbind_bindings_files
    ccbind_cocos2dx.cpp
    ccbind_cocos2dx_3d.cpp
    ccbind_cocos2dx_3d_extension.cpp
    ccbind_cocos2dx_audioengine.cpp
    ccbind_cocos2dx_builder.cpp
    ccbind_cocos2dx_experimental_video.cpp
    ccbind_cocos2dx_experimental_webView.cpp
    ccbind_cocos2dx_extension.cpp
    ccbind_cocos2dx_navmesh.cpp
    ccbind_cocos2dx_network.cpp
    ccbind_cocos2dx_physics3d.cpp
    ccbind_cocos2dx_spine.cpp
    ccbind_cocos2dx_studio.cpp
    # ccbind_cocos2dx_ui.cpp
    CCScriptBindings.cpp
    )
set(ccbind_bindings_headers
    ccbind_cocos2dx.hpp
    ccbind_cocos2dx_3d.hpp
    ccbind_cocos2dx_3d_extension.hpp
    ccbind_cocos2dx_audioengine.hpp
    ccbind_cocos2dx_builder.hpp
    ccbind_cocos2dx_experimental_video.hpp
    ccbind_cocos2dx_experimental_webView.hpp
    ccbind_cocos2dx_extension.hpp
    ccbind_cocos2dx_navmesh.hpp
    ccbind_cocos2dx_network.hpp
    ccbind_cocos2dx_physics3d.hpp
    ccbind_cocos2dx_spine.hpp
    ccbind_cocos2dx_studio.hpp
    ccbind_cocos2dx_ui.hpp
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

