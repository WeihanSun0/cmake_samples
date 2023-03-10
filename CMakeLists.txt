cmake_minimum_required(VERSION 2.24)
project(samples)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/conf")

include(compiler_conf)
include(building_output)

set(USE_VCKPG 0)
set(CMAKE_BUILD_TYPE "Debug")

if(CMAKE_HOST_WIN32)
    message("win32")
    set(OPENCV_LIB "opencv-lib")
    if(USE_VCPKG)
        message("use VCPKG") 
        find_package(OpenCV)
    else() # use attached opencv
        message("not use VCPKG")
        include_directories("${CMAKE_CURRENT_SOURCE_DIR}/inc")
        link_directories("$CMAKE_CURRENT_SOURCE_DIR/lib")
        message("${CMAKE_BUILD_TYPE}")
        if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
            set(OpenCV_LIBS "${CMAKE_CURRENT_SOURCE_DIR}/lib/opencv_world412d.lib")
            if(EXISTS "${OUTPUT_DIRECTORY_DEBUG}/opencv_world412d.dll")
                message("found opencv dll")
            else()
                file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/lib/opencv_world412d.dll" 
                    DESTINATION "${OUTPUT_DIRECTORY_DEBUG}")
            endif()
        else()
            set(OpenCV_LIBS "${CMAKE_CURRENT_SOURCE_DIR}/lib/opencv_world412.lib")
            if(EXISTS "${OUTPUT_DIRECTORY_RELEASE}/opencv_world412.dll")
                message("found opencv dll")
            else()
                file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/lib/opencv_world412.dll" 
                    DESTINATION "${OUTPUT_DIRECTORY_RELEASE}")
            endif()
        endif()
    endif()

elseif(CMAKE_HOST_UNIX)
    message("linux")
    find_package(OpenCV)
    if(OpenCV_FOUND)
        message("+++++FOUND OPENCV")
    endif()
endif()


find_package(CUDA)
if(CUDA_FOUND)
    message("+++++FOUND CUDA")
endif(CUDA_FOUND)

add_subdirectory(src)