# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/build

# Include any dependencies generated for this target.
include prj.codeforces/1619d/CMakeFiles/1619d.dir/depend.make

# Include the progress variables for this target.
include prj.codeforces/1619d/CMakeFiles/1619d.dir/progress.make

# Include the compile flags for this target's objects.
include prj.codeforces/1619d/CMakeFiles/1619d.dir/flags.make

prj.codeforces/1619d/CMakeFiles/1619d.dir/1619d.cpp.o: prj.codeforces/1619d/CMakeFiles/1619d.dir/flags.make
prj.codeforces/1619d/CMakeFiles/1619d.dir/1619d.cpp.o: ../prj.codeforces/1619d/1619d.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object prj.codeforces/1619d/CMakeFiles/1619d.dir/1619d.cpp.o"
	cd /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/build/prj.codeforces/1619d && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/1619d.dir/1619d.cpp.o -c /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/prj.codeforces/1619d/1619d.cpp

prj.codeforces/1619d/CMakeFiles/1619d.dir/1619d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1619d.dir/1619d.cpp.i"
	cd /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/build/prj.codeforces/1619d && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/prj.codeforces/1619d/1619d.cpp > CMakeFiles/1619d.dir/1619d.cpp.i

prj.codeforces/1619d/CMakeFiles/1619d.dir/1619d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1619d.dir/1619d.cpp.s"
	cd /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/build/prj.codeforces/1619d && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/prj.codeforces/1619d/1619d.cpp -o CMakeFiles/1619d.dir/1619d.cpp.s

# Object files for target 1619d
1619d_OBJECTS = \
"CMakeFiles/1619d.dir/1619d.cpp.o"

# External object files for target 1619d
1619d_EXTERNAL_OBJECTS =

prj.codeforces/1619d/1619d: prj.codeforces/1619d/CMakeFiles/1619d.dir/1619d.cpp.o
prj.codeforces/1619d/1619d: prj.codeforces/1619d/CMakeFiles/1619d.dir/build.make
prj.codeforces/1619d/1619d: prj.codeforces/1619d/CMakeFiles/1619d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1619d"
	cd /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/build/prj.codeforces/1619d && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1619d.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
prj.codeforces/1619d/CMakeFiles/1619d.dir/build: prj.codeforces/1619d/1619d

.PHONY : prj.codeforces/1619d/CMakeFiles/1619d.dir/build

prj.codeforces/1619d/CMakeFiles/1619d.dir/clean:
	cd /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/build/prj.codeforces/1619d && $(CMAKE_COMMAND) -P CMakeFiles/1619d.dir/cmake_clean.cmake
.PHONY : prj.codeforces/1619d/CMakeFiles/1619d.dir/clean

prj.codeforces/1619d/CMakeFiles/1619d.dir/depend:
	cd /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/prj.codeforces/1619d /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/build /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/build/prj.codeforces/1619d /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/build/prj.codeforces/1619d/CMakeFiles/1619d.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : prj.codeforces/1619d/CMakeFiles/1619d.dir/depend

