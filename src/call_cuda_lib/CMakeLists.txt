project(call_cuda_app)


find_package(CUDA REQUIRED)

add_executable(call_cuda_lib 
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(call_cuda_lib
PRIVATE
    cuda_static_lib   
    cuda_share_lib
)
