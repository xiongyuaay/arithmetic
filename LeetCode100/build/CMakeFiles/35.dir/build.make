# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yuaay/Code/arithmetic/LeetCode100

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yuaay/Code/arithmetic/LeetCode100/build

# Include any dependencies generated for this target.
include CMakeFiles/35.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/35.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/35.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/35.dir/flags.make

CMakeFiles/35.dir/codegen:
.PHONY : CMakeFiles/35.dir/codegen

CMakeFiles/35.dir/35.cpp.o: CMakeFiles/35.dir/flags.make
CMakeFiles/35.dir/35.cpp.o: /Users/yuaay/Code/arithmetic/LeetCode100/35.cpp
CMakeFiles/35.dir/35.cpp.o: CMakeFiles/35.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/yuaay/Code/arithmetic/LeetCode100/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/35.dir/35.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/35.dir/35.cpp.o -MF CMakeFiles/35.dir/35.cpp.o.d -o CMakeFiles/35.dir/35.cpp.o -c /Users/yuaay/Code/arithmetic/LeetCode100/35.cpp

CMakeFiles/35.dir/35.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/35.dir/35.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yuaay/Code/arithmetic/LeetCode100/35.cpp > CMakeFiles/35.dir/35.cpp.i

CMakeFiles/35.dir/35.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/35.dir/35.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yuaay/Code/arithmetic/LeetCode100/35.cpp -o CMakeFiles/35.dir/35.cpp.s

# Object files for target 35
35_OBJECTS = \
"CMakeFiles/35.dir/35.cpp.o"

# External object files for target 35
35_EXTERNAL_OBJECTS =

35: CMakeFiles/35.dir/35.cpp.o
35: CMakeFiles/35.dir/build.make
35: CMakeFiles/35.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/yuaay/Code/arithmetic/LeetCode100/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 35"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/35.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/35.dir/build: 35
.PHONY : CMakeFiles/35.dir/build

CMakeFiles/35.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/35.dir/cmake_clean.cmake
.PHONY : CMakeFiles/35.dir/clean

CMakeFiles/35.dir/depend:
	cd /Users/yuaay/Code/arithmetic/LeetCode100/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yuaay/Code/arithmetic/LeetCode100 /Users/yuaay/Code/arithmetic/LeetCode100 /Users/yuaay/Code/arithmetic/LeetCode100/build /Users/yuaay/Code/arithmetic/LeetCode100/build /Users/yuaay/Code/arithmetic/LeetCode100/build/CMakeFiles/35.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/35.dir/depend

