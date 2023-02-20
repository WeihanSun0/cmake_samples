add_library(share_lib SHARED)

target_sources(share_lib
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/share_lib.cpp
)

target_include_directories(share_lib
INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)