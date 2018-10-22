cmake_minimum_required(VERSION 2.8)
set(OpenCV_DIR /home/marshall/opencv/build/)

find_package(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

include_directories(${ECE3110_SOURCE_DIR}/MainProject/inc)
include_directories(${ECE3110_SOURCE_DIR}/LibProject/inc)
link_directories(${ECE3110_SOURCE_DIR}/LibProject/src)

# Add OpenCV headers location to your include paths
include_directories(${OpenCV_INCLUDE_DIRS})

# Declare the executable target built from your sources
add_executable(opencv_example opencv_example.cpp)
# Link your application with OpenCV libraries
target_link_libraries(opencv_example ${OpenCV_LIBS})


#Our files from here
add_executable(capture_rate captureRate.cpp)
target_link_libraries(capture_rate ${OpenCV_LIBS})
add_executable(save_image saveImage.cpp)
target_link_libraries(save_image ${OpenCV_LIBS})
add_executable(edge_detection edgeDetection.cpp)
target_link_libraries(edge_detection ${OpenCV_LIBS})
