# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/emda/git/wee

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emda/git/wee/build

# Include any dependencies generated for this target.
include src/base/CMakeFiles/wee_base.dir/depend.make

# Include the progress variables for this target.
include src/base/CMakeFiles/wee_base.dir/progress.make

# Include the compile flags for this target's objects.
include src/base/CMakeFiles/wee_base.dir/flags.make

src/base/CMakeFiles/wee_base.dir/SDL_Application.c.o: src/base/CMakeFiles/wee_base.dir/flags.make
src/base/CMakeFiles/wee_base.dir/SDL_Application.c.o: ../src/base/SDL_Application.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emda/git/wee/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/base/CMakeFiles/wee_base.dir/SDL_Application.c.o"
	cd /home/emda/git/wee/build/src/base && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/wee_base.dir/SDL_Application.c.o   -c /home/emda/git/wee/src/base/SDL_Application.c

src/base/CMakeFiles/wee_base.dir/SDL_Application.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wee_base.dir/SDL_Application.c.i"
	cd /home/emda/git/wee/build/src/base && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/emda/git/wee/src/base/SDL_Application.c > CMakeFiles/wee_base.dir/SDL_Application.c.i

src/base/CMakeFiles/wee_base.dir/SDL_Application.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wee_base.dir/SDL_Application.c.s"
	cd /home/emda/git/wee/build/src/base && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/emda/git/wee/src/base/SDL_Application.c -o CMakeFiles/wee_base.dir/SDL_Application.c.s

# Object files for target wee_base
wee_base_OBJECTS = \
"CMakeFiles/wee_base.dir/SDL_Application.c.o"

# External object files for target wee_base
wee_base_EXTERNAL_OBJECTS =

lib/Debug/libwee_base.so: src/base/CMakeFiles/wee_base.dir/SDL_Application.c.o
lib/Debug/libwee_base.so: src/base/CMakeFiles/wee_base.dir/build.make
lib/Debug/libwee_base.so: lib/Debug/libwee_util.so
lib/Debug/libwee_base.so: lib/Debug/libfmtd.a
lib/Debug/libwee_base.so: src/base/CMakeFiles/wee_base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emda/git/wee/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../lib/Debug/libwee_base.so"
	cd /home/emda/git/wee/build/src/base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wee_base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/base/CMakeFiles/wee_base.dir/build: lib/Debug/libwee_base.so

.PHONY : src/base/CMakeFiles/wee_base.dir/build

src/base/CMakeFiles/wee_base.dir/clean:
	cd /home/emda/git/wee/build/src/base && $(CMAKE_COMMAND) -P CMakeFiles/wee_base.dir/cmake_clean.cmake
.PHONY : src/base/CMakeFiles/wee_base.dir/clean

src/base/CMakeFiles/wee_base.dir/depend:
	cd /home/emda/git/wee/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emda/git/wee /home/emda/git/wee/src/base /home/emda/git/wee/build /home/emda/git/wee/build/src/base /home/emda/git/wee/build/src/base/CMakeFiles/wee_base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/base/CMakeFiles/wee_base.dir/depend

