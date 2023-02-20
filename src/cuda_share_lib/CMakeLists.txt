cuda_add_library(cuda_share_lib 
SHARED 
    ${CMAKE_CURRENT_SOURCE_DIR}/cuda_share_lib.cu
    ${CMAKE_CURRENT_SOURCE_DIR}/cuda_share_lib.cuh
) 

target_include_directories(cuda_share_lib
INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)