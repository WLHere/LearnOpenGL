# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2

# Include any dependencies generated for this target.
include tests/CMakeFiles/timeout.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/timeout.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/timeout.dir/flags.make

tests/CMakeFiles/timeout.dir/timeout.c.o: tests/CMakeFiles/timeout.dir/flags.make
tests/CMakeFiles/timeout.dir/timeout.c.o: tests/timeout.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/timeout.dir/timeout.c.o"
	cd /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/timeout.dir/timeout.c.o -c /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/tests/timeout.c

tests/CMakeFiles/timeout.dir/timeout.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/timeout.dir/timeout.c.i"
	cd /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/tests/timeout.c > CMakeFiles/timeout.dir/timeout.c.i

tests/CMakeFiles/timeout.dir/timeout.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/timeout.dir/timeout.c.s"
	cd /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/tests/timeout.c -o CMakeFiles/timeout.dir/timeout.c.s

tests/CMakeFiles/timeout.dir/__/deps/glad_gl.c.o: tests/CMakeFiles/timeout.dir/flags.make
tests/CMakeFiles/timeout.dir/__/deps/glad_gl.c.o: deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/timeout.dir/__/deps/glad_gl.c.o"
	cd /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/timeout.dir/__/deps/glad_gl.c.o -c /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/deps/glad_gl.c

tests/CMakeFiles/timeout.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/timeout.dir/__/deps/glad_gl.c.i"
	cd /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/deps/glad_gl.c > CMakeFiles/timeout.dir/__/deps/glad_gl.c.i

tests/CMakeFiles/timeout.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/timeout.dir/__/deps/glad_gl.c.s"
	cd /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/tests && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/deps/glad_gl.c -o CMakeFiles/timeout.dir/__/deps/glad_gl.c.s

# Object files for target timeout
timeout_OBJECTS = \
"CMakeFiles/timeout.dir/timeout.c.o" \
"CMakeFiles/timeout.dir/__/deps/glad_gl.c.o"

# External object files for target timeout
timeout_EXTERNAL_OBJECTS =

tests/timeout.app/Contents/MacOS/timeout: tests/CMakeFiles/timeout.dir/timeout.c.o
tests/timeout.app/Contents/MacOS/timeout: tests/CMakeFiles/timeout.dir/__/deps/glad_gl.c.o
tests/timeout.app/Contents/MacOS/timeout: tests/CMakeFiles/timeout.dir/build.make
tests/timeout.app/Contents/MacOS/timeout: src/libglfw3.a
tests/timeout.app/Contents/MacOS/timeout: tests/CMakeFiles/timeout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable timeout.app/Contents/MacOS/timeout"
	cd /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/timeout.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/timeout.dir/build: tests/timeout.app/Contents/MacOS/timeout

.PHONY : tests/CMakeFiles/timeout.dir/build

tests/CMakeFiles/timeout.dir/clean:
	cd /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/tests && $(CMAKE_COMMAND) -P CMakeFiles/timeout.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/timeout.dir/clean

tests/CMakeFiles/timeout.dir/depend:
	cd /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2 /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/tests /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2 /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/tests /Users/a58/dev/github/LearnOpenGL/glfw/glfw-3.3.2/tests/CMakeFiles/timeout.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/timeout.dir/depend

