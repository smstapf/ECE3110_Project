# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marshall/Documents/ECE3110_Project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marshall/Documents/ECE3110_Project

# Include any dependencies generated for this target.
include CMakeFiles/save_image.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/save_image.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/save_image.dir/flags.make

CMakeFiles/save_image.dir/saveImage.cpp.o: CMakeFiles/save_image.dir/flags.make
CMakeFiles/save_image.dir/saveImage.cpp.o: saveImage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marshall/Documents/ECE3110_Project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/save_image.dir/saveImage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/save_image.dir/saveImage.cpp.o -c /home/marshall/Documents/ECE3110_Project/saveImage.cpp

CMakeFiles/save_image.dir/saveImage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/save_image.dir/saveImage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marshall/Documents/ECE3110_Project/saveImage.cpp > CMakeFiles/save_image.dir/saveImage.cpp.i

CMakeFiles/save_image.dir/saveImage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/save_image.dir/saveImage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marshall/Documents/ECE3110_Project/saveImage.cpp -o CMakeFiles/save_image.dir/saveImage.cpp.s

CMakeFiles/save_image.dir/saveImage.cpp.o.requires:

.PHONY : CMakeFiles/save_image.dir/saveImage.cpp.o.requires

CMakeFiles/save_image.dir/saveImage.cpp.o.provides: CMakeFiles/save_image.dir/saveImage.cpp.o.requires
	$(MAKE) -f CMakeFiles/save_image.dir/build.make CMakeFiles/save_image.dir/saveImage.cpp.o.provides.build
.PHONY : CMakeFiles/save_image.dir/saveImage.cpp.o.provides

CMakeFiles/save_image.dir/saveImage.cpp.o.provides.build: CMakeFiles/save_image.dir/saveImage.cpp.o


# Object files for target save_image
save_image_OBJECTS = \
"CMakeFiles/save_image.dir/saveImage.cpp.o"

# External object files for target save_image
save_image_EXTERNAL_OBJECTS =

save_image: CMakeFiles/save_image.dir/saveImage.cpp.o
save_image: CMakeFiles/save_image.dir/build.make
save_image: /home/marshall/opencv/build/lib/libopencv_stitching.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_superres.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_videostab.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_aruco.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_bgsegm.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_bioinspired.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_ccalib.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_cvv.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_dnn_objdetect.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_dpm.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_face.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_freetype.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_fuzzy.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_hdf.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_hfs.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_img_hash.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_line_descriptor.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_optflow.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_reg.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_rgbd.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_saliency.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_sfm.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_stereo.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_structured_light.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_surface_matching.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_tracking.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_xfeatures2d.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_ximgproc.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_xobjdetect.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_xphoto.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_photo.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_datasets.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_plot.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_text.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_dnn.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_ml.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_shape.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_video.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_calib3d.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_features2d.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_highgui.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_videoio.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_viz.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_phase_unwrapping.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_flann.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_imgcodecs.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_objdetect.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_imgproc.so.3.4.1
save_image: /home/marshall/opencv/build/lib/libopencv_core.so.3.4.1
save_image: CMakeFiles/save_image.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marshall/Documents/ECE3110_Project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable save_image"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/save_image.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/save_image.dir/build: save_image

.PHONY : CMakeFiles/save_image.dir/build

CMakeFiles/save_image.dir/requires: CMakeFiles/save_image.dir/saveImage.cpp.o.requires

.PHONY : CMakeFiles/save_image.dir/requires

CMakeFiles/save_image.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/save_image.dir/cmake_clean.cmake
.PHONY : CMakeFiles/save_image.dir/clean

CMakeFiles/save_image.dir/depend:
	cd /home/marshall/Documents/ECE3110_Project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marshall/Documents/ECE3110_Project /home/marshall/Documents/ECE3110_Project /home/marshall/Documents/ECE3110_Project /home/marshall/Documents/ECE3110_Project /home/marshall/Documents/ECE3110_Project/CMakeFiles/save_image.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/save_image.dir/depend
