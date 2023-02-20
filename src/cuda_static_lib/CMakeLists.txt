cuda_add_library(cuda_static_lib 
STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/cuda_static_lib.cu
    ${CMAKE_CURRENT_SOURCE_DIR}/cuda_static_lib.cuh
)

target_include_directories(cuda_static_lib
INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)