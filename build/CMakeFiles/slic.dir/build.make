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
include CMakeFiles/slic.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/slic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/slic.dir/flags.make

CMakeFiles/slic.dir/include/slic_modified/slic.cpp.o: CMakeFiles/slic.dir/flags.make
CMakeFiles/slic.dir/include/slic_modified/slic.cpp.o: ../include/slic_modified/slic.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/build/CMakeFiles" $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/slic.dir/include/slic_modified/slic.cpp.o"
	/usr/lib/ccache/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/slic.dir/include/slic_modified/slic.cpp.o -c "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/include/slic_modified/slic.cpp"

CMakeFiles/slic.dir/include/slic_modified/slic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/slic.dir/include/slic_modified/slic.cpp.i"
	/usr/lib/ccache/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/include/slic_modified/slic.cpp" > CMakeFiles/slic.dir/include/slic_modified/slic.cpp.i

CMakeFiles/slic.dir/include/slic_modified/slic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/slic.dir/include/slic_modified/slic.cpp.s"
	/usr/lib/ccache/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/include/slic_modified/slic.cpp" -o CMakeFiles/slic.dir/include/slic_modified/slic.cpp.s

CMakeFiles/slic.dir/include/slic_modified/slic.cpp.o.requires:
.PHONY : CMakeFiles/slic.dir/include/slic_modified/slic.cpp.o.requires

CMakeFiles/slic.dir/include/slic_modified/slic.cpp.o.provides: CMakeFiles/slic.dir/include/slic_modified/slic.cpp.o.requires
	$(MAKE) -f CMakeFiles/slic.dir/build.make CMakeFiles/slic.dir/include/slic_modified/slic.cpp.o.provides.build
.PHONY : CMakeFiles/slic.dir/include/slic_modified/slic.cpp.o.provides

CMakeFiles/slic.dir/include/slic_modified/slic.cpp.o.provides.build: CMakeFiles/slic.dir/include/slic_modified/slic.cpp.o

# Object files for target slic
slic_OBJECTS = \
"CMakeFiles/slic.dir/include/slic_modified/slic.cpp.o"

# External object files for target slic
slic_EXTERNAL_OBJECTS =

libslic.so: CMakeFiles/slic.dir/include/slic_modified/slic.cpp.o
libslic.so: CMakeFiles/slic.dir/build.make
libslic.so: liblibsuperpixel.so
libslic.so: CMakeFiles/slic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library libslic.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/slic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/slic.dir/build: libslic.so
.PHONY : CMakeFiles/slic.dir/build

CMakeFiles/slic.dir/requires: CMakeFiles/slic.dir/include/slic_modified/slic.cpp.o.requires
.PHONY : CMakeFiles/slic.dir/requires

CMakeFiles/slic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/slic.dir/cmake_clean.cmake
.PHONY : CMakeFiles/slic.dir/clean

CMakeFiles/slic.dir/depend:
	cd "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation" "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation" "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/build" "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/build" "/home/alfredoso/GitHub/OtrasCosas/Trabajos/Nomoko Camera/CodeSamples-YoshuaNava/C++/slic_egbis_segmentation/build/CMakeFiles/slic.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/slic.dir/depend

