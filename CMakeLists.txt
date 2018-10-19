# cmake needs this line
cmake_minimum_required(VERSION 2.8)
set(OpenCV_DIR /home/marshall/opencv/build/)

# Define project name
project(ECE3110)

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
find_package(OpenCV REQUIRED)

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# Add OpenCV headers location to your include paths
include_directories(${OpenCV_INCLUDE_DIRS})

# Declare the executable target built from your sources
add_executable(opencv_example opencv_example.cpp)
# Link your application with OpenCV libraries
target_link_libraries(opencv_example ${OpenCV_LIBS})

add_executable(capture_rate captureRate.cpp)
target_link_libraries(capture_rate ${OpenCV_LIBS})

add_executable(save_image saveImage.cpp)
target_link_libraries(save_image ${OpenCV_LIBS})
add_executable(edge_detection edgeDetection.cpp)
target_link_libraries(edge_detection ${OpenCV_LIBS})
