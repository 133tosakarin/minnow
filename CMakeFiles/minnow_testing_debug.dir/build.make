# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cs144/lab/minnow/tests

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cs144/lab/minnow

# Include any dependencies generated for this target.
include CMakeFiles/minnow_testing_debug.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/minnow_testing_debug.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/minnow_testing_debug.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minnow_testing_debug.dir/flags.make

CMakeFiles/minnow_testing_debug.dir/common.o: CMakeFiles/minnow_testing_debug.dir/flags.make
CMakeFiles/minnow_testing_debug.dir/common.o: /home/cs144/lab/minnow/tests/common.cc
CMakeFiles/minnow_testing_debug.dir/common.o: CMakeFiles/minnow_testing_debug.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cs144/lab/minnow/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/minnow_testing_debug.dir/common.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/minnow_testing_debug.dir/common.o -MF CMakeFiles/minnow_testing_debug.dir/common.o.d -o CMakeFiles/minnow_testing_debug.dir/common.o -c /home/cs144/lab/minnow/tests/common.cc

CMakeFiles/minnow_testing_debug.dir/common.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minnow_testing_debug.dir/common.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cs144/lab/minnow/tests/common.cc > CMakeFiles/minnow_testing_debug.dir/common.i

CMakeFiles/minnow_testing_debug.dir/common.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minnow_testing_debug.dir/common.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cs144/lab/minnow/tests/common.cc -o CMakeFiles/minnow_testing_debug.dir/common.s

# Object files for target minnow_testing_debug
minnow_testing_debug_OBJECTS = \
"CMakeFiles/minnow_testing_debug.dir/common.o"

# External object files for target minnow_testing_debug
minnow_testing_debug_EXTERNAL_OBJECTS =

libminnow_testing_debug.a: CMakeFiles/minnow_testing_debug.dir/common.o
libminnow_testing_debug.a: CMakeFiles/minnow_testing_debug.dir/build.make
libminnow_testing_debug.a: CMakeFiles/minnow_testing_debug.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cs144/lab/minnow/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libminnow_testing_debug.a"
	$(CMAKE_COMMAND) -P CMakeFiles/minnow_testing_debug.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minnow_testing_debug.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minnow_testing_debug.dir/build: libminnow_testing_debug.a
.PHONY : CMakeFiles/minnow_testing_debug.dir/build

CMakeFiles/minnow_testing_debug.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minnow_testing_debug.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minnow_testing_debug.dir/clean

CMakeFiles/minnow_testing_debug.dir/depend:
	cd /home/cs144/lab/minnow && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cs144/lab/minnow/tests /home/cs144/lab/minnow/tests /home/cs144/lab/minnow /home/cs144/lab/minnow /home/cs144/lab/minnow/CMakeFiles/minnow_testing_debug.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minnow_testing_debug.dir/depend

