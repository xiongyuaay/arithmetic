# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\AlgoPro\LeetCode100

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\AlgoPro\LeetCode100\build

# Include any dependencies generated for this target.
include CMakeFiles/32.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/32.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/32.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/32.dir/flags.make

CMakeFiles/32.dir/32.cpp.obj: CMakeFiles/32.dir/flags.make
CMakeFiles/32.dir/32.cpp.obj: E:/AlgoPro/LeetCode100/32.cpp
CMakeFiles/32.dir/32.cpp.obj: CMakeFiles/32.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=E:\AlgoPro\LeetCode100\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/32.dir/32.cpp.obj"
	D:\LLVM\bin\clang++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/32.dir/32.cpp.obj -MF CMakeFiles\32.dir\32.cpp.obj.d -o CMakeFiles\32.dir\32.cpp.obj -c E:\AlgoPro\LeetCode100\32.cpp

CMakeFiles/32.dir/32.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/32.dir/32.cpp.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_PREPROCESSED_SOURCE

CMakeFiles/32.dir/32.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/32.dir/32.cpp.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_ASSEMBLY_SOURCE

# Object files for target 32
32_OBJECTS = \
"CMakeFiles/32.dir/32.cpp.obj"

# External object files for target 32
32_EXTERNAL_OBJECTS =

32.exe: CMakeFiles/32.dir/32.cpp.obj
32.exe: CMakeFiles/32.dir/build.make
32.exe: CMakeFiles/32.dir/linkLibs.rsp
32.exe: CMakeFiles/32.dir/objects1.rsp
32.exe: CMakeFiles/32.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=E:\AlgoPro\LeetCode100\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 32.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\32.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/32.dir/build: 32.exe
.PHONY : CMakeFiles/32.dir/build

CMakeFiles/32.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\32.dir\cmake_clean.cmake
.PHONY : CMakeFiles/32.dir/clean

CMakeFiles/32.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\AlgoPro\LeetCode100 E:\AlgoPro\LeetCode100 E:\AlgoPro\LeetCode100\build E:\AlgoPro\LeetCode100\build E:\AlgoPro\LeetCode100\build\CMakeFiles\32.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/32.dir/depend

