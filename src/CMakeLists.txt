project(samples)

# NOTE normal cpp
add_subdirectory(share_lib)
add_subdirectory(static_lib)
add_subdirectory(call_lib)

# NOTE c with cuda
add_subdirectory(hello_cuda)

# NOTE call cuda lib
add_subdirectory(cuda_share_lib)
add_subdirectory(cuda_static_lib)
add_subdirectory(call_cuda_lib)