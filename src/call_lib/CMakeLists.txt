# call opencv lib 
# call share_lib static_lib

add_executable(call_lib)

target_sources(call_lib
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/helloworld.cpp
)

target_link_libraries(call_lib
PRIVATE
    share_lib # NOTE include share_lib
    static_lib # NOTE include static_lib
    ${OpenCV_LIBS}
)