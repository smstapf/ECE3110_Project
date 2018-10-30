cmake_minimum_required(VERSION 2.8)
set(OpenCV_DIR /home/pi/opencv/build/)

find_package(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(${ECE3110_SOURCE_DIR}/LibProject/inc)
add_library(LibProject accelerometer.cpp camera.cpp motor.cpp imageprocessor.cpp)
