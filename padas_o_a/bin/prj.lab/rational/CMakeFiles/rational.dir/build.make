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
CMAKE_BINARY_DIR = /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/bin

# Include any dependencies generated for this target.
include prj.lab/rational/CMakeFiles/rational.dir/depend.make

# Include the progress variables for this target.
include prj.lab/rational/CMakeFiles/rational.dir/progress.make

# Include the compile flags for this target's objects.
include prj.lab/rational/CMakeFiles/rational.dir/flags.make

prj.lab/rational/CMakeFiles/rational.dir/rational.cpp.o: prj.lab/rational/CMakeFiles/rational.dir/flags.make
prj.lab/rational/CMakeFiles/rational.dir/rational.cpp.o: ../prj.lab/rational/rational.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object prj.lab/rational/CMakeFiles/rational.dir/rational.cpp.o"
	cd /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/bin/prj.lab/rational && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rational.dir/rational.cpp.o -c /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/prj.lab/rational/rational.cpp

prj.lab/rational/CMakeFiles/rational.dir/rational.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rational.dir/rational.cpp.i"
	cd /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/bin/prj.lab/rational && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/prj.lab/rational/rational.cpp > CMakeFiles/rational.dir/rational.cpp.i

prj.lab/rational/CMakeFiles/rational.dir/rational.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rational.dir/rational.cpp.s"
	cd /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/bin/prj.lab/rational && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/prj.lab/rational/rational.cpp -o CMakeFiles/rational.dir/rational.cpp.s

# Object files for target rational
rational_OBJECTS = \
"CMakeFiles/rational.dir/rational.cpp.o"

# External object files for target rational
rational_EXTERNAL_OBJECTS =

prj.lab/rational/librational.a: prj.lab/rational/CMakeFiles/rational.dir/rational.cpp.o
prj.lab/rational/librational.a: prj.lab/rational/CMakeFiles/rational.dir/build.make
prj.lab/rational/librational.a: prj.lab/rational/CMakeFiles/rational.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library librational.a"
	cd /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/bin/prj.lab/rational && $(CMAKE_COMMAND) -P CMakeFiles/rational.dir/cmake_clean_target.cmake
	cd /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/bin/prj.lab/rational && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rational.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
prj.lab/rational/CMakeFiles/rational.dir/build: prj.lab/rational/librational.a

.PHONY : prj.lab/rational/CMakeFiles/rational.dir/build

prj.lab/rational/CMakeFiles/rational.dir/clean:
	cd /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/bin/prj.lab/rational && $(CMAKE_COMMAND) -P CMakeFiles/rational.dir/cmake_clean.cmake
.PHONY : prj.lab/rational/CMakeFiles/rational.dir/clean

prj.lab/rational/CMakeFiles/rational.dir/depend:
	cd /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/prj.lab/rational /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/bin /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/bin/prj.lab/rational /home/krolchonok/Documents/Study/3-course/SE_algo/SE_algo/padas_o_a/bin/prj.lab/rational/CMakeFiles/rational.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : prj.lab/rational/CMakeFiles/rational.dir/depend

