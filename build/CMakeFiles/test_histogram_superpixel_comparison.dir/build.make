# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/build"

# Include any dependencies generated for this target.
include CMakeFiles/test_histogram_superpixel_comparison.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_histogram_superpixel_comparison.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_histogram_superpixel_comparison.dir/flags.make

CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.o: CMakeFiles/test_histogram_superpixel_comparison.dir/flags.make
CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.o: ../test/test_histogram_superpixel_comparison.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.o"
	/usr/lib/ccache/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.o -c "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/test/test_histogram_superpixel_comparison.cpp"

CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.i"
	/usr/lib/ccache/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/test/test_histogram_superpixel_comparison.cpp" > CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.i

CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.s"
	/usr/lib/ccache/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/test/test_histogram_superpixel_comparison.cpp" -o CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.s

CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.o.requires:
.PHONY : CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.o.requires

CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.o.provides: CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_histogram_superpixel_comparison.dir/build.make CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.o.provides.build
.PHONY : CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.o.provides

CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.o.provides.build: CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.o

# Object files for target test_histogram_superpixel_comparison
test_histogram_superpixel_comparison_OBJECTS = \
"CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.o"

# External object files for target test_histogram_superpixel_comparison
test_histogram_superpixel_comparison_EXTERNAL_OBJECTS =

test_histogram_superpixel_comparison: CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.o
test_histogram_superpixel_comparison: CMakeFiles/test_histogram_superpixel_comparison.dir/build.make
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
test_histogram_superpixel_comparison: libslic.so
test_histogram_superpixel_comparison: libfh_egbis.so
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
test_histogram_superpixel_comparison: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
test_histogram_superpixel_comparison: liblibsuperpixel.so
test_histogram_superpixel_comparison: CMakeFiles/test_histogram_superpixel_comparison.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test_histogram_superpixel_comparison"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_histogram_superpixel_comparison.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_histogram_superpixel_comparison.dir/build: test_histogram_superpixel_comparison
.PHONY : CMakeFiles/test_histogram_superpixel_comparison.dir/build

CMakeFiles/test_histogram_superpixel_comparison.dir/requires: CMakeFiles/test_histogram_superpixel_comparison.dir/test/test_histogram_superpixel_comparison.cpp.o.requires
.PHONY : CMakeFiles/test_histogram_superpixel_comparison.dir/requires

CMakeFiles/test_histogram_superpixel_comparison.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_histogram_superpixel_comparison.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_histogram_superpixel_comparison.dir/clean

CMakeFiles/test_histogram_superpixel_comparison.dir/depend:
	cd "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation" "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation" "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/build" "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/build" "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/build/CMakeFiles/test_histogram_superpixel_comparison.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/test_histogram_superpixel_comparison.dir/depend
