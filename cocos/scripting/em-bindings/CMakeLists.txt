set(cocos_root ${COCOS2DX_ROOT_PATH})

set(em_bindings_manual_headers
    manual/em_cocos2dx_manual.hpp
    )

set(em_bindings_manual_files
    manual/em_cocos2dx_manual.cpp
    )

set(em_bindings_auto_headers)

set(em_bindings_auto_files)

set(em_bindings_files
    ${em_bindings_manual_files}
    ${em_bindings_auto_files}
    )
set(em_bindings_headers
    ${em_bindings_manual_headers}
    ${em_bindings_auto_headers}
    )

list(APPEND em_bindings_files ${em_bindings_headers})

add_library(emcocos2d ${em_bindings_files})
target_link_libraries(emcocos2d cocos2d)
add_dependencies(emcocos2d cocos2d)

target_include_directories(emcocos2d
    INTERFACE ${cocos_root}/cocos/scripting/em-bindings/auto
    INTERFACE ${cocos_root}/cocos/scripting/em-bindings/manual
)

set_target_properties(emcocos2d
                      PROPERTIES
                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
                      FOLDER "Internal"
                      )


