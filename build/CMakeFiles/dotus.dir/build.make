# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_SOURCE_DIR = /home/csmoulaison/repos/dotus/build

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/csmoulaison/repos/dotus/build

# Include any dependencies generated for this target.
include CMakeFiles/dotus.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/dotus.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/dotus.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dotus.dir/flags.make

CMakeFiles/dotus.dir/home/csmoulaison/repos/dotus/src/dotus.c.o: CMakeFiles/dotus.dir/flags.make
CMakeFiles/dotus.dir/home/csmoulaison/repos/dotus/src/dotus.c.o: /home/csmoulaison/repos/dotus/src/dotus.c
CMakeFiles/dotus.dir/home/csmoulaison/repos/dotus/src/dotus.c.o: CMakeFiles/dotus.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/csmoulaison/repos/dotus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/dotus.dir/home/csmoulaison/repos/dotus/src/dotus.c.o"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/dotus.dir/home/csmoulaison/repos/dotus/src/dotus.c.o -MF CMakeFiles/dotus.dir/home/csmoulaison/repos/dotus/src/dotus.c.o.d -o CMakeFiles/dotus.dir/home/csmoulaison/repos/dotus/src/dotus.c.o -c /home/csmoulaison/repos/dotus/src/dotus.c

CMakeFiles/dotus.dir/home/csmoulaison/repos/dotus/src/dotus.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/dotus.dir/home/csmoulaison/repos/dotus/src/dotus.c.i"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/csmoulaison/repos/dotus/src/dotus.c > CMakeFiles/dotus.dir/home/csmoulaison/repos/dotus/src/dotus.c.i

CMakeFiles/dotus.dir/home/csmoulaison/repos/dotus/src/dotus.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/dotus.dir/home/csmoulaison/repos/dotus/src/dotus.c.s"
	/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/csmoulaison/repos/dotus/src/dotus.c -o CMakeFiles/dotus.dir/home/csmoulaison/repos/dotus/src/dotus.c.s

# Object files for target dotus
dotus_OBJECTS = \
"CMakeFiles/dotus.dir/home/csmoulaison/repos/dotus/src/dotus.c.o"

# External object files for target dotus
dotus_EXTERNAL_OBJECTS =

/home/csmoulaison/repos/dotus/bin/dotus: CMakeFiles/dotus.dir/home/csmoulaison/repos/dotus/src/dotus.c.o
/home/csmoulaison/repos/dotus/bin/dotus: CMakeFiles/dotus.dir/build.make
/home/csmoulaison/repos/dotus/bin/dotus: CMakeFiles/dotus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/csmoulaison/repos/dotus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable /home/csmoulaison/repos/dotus/bin/dotus"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dotus.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dotus.dir/build: /home/csmoulaison/repos/dotus/bin/dotus
.PHONY : CMakeFiles/dotus.dir/build

CMakeFiles/dotus.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dotus.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dotus.dir/clean

CMakeFiles/dotus.dir/depend:
	cd /home/csmoulaison/repos/dotus/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/csmoulaison/repos/dotus/build /home/csmoulaison/repos/dotus/build /home/csmoulaison/repos/dotus/build /home/csmoulaison/repos/dotus/build /home/csmoulaison/repos/dotus/build/CMakeFiles/dotus.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/dotus.dir/depend

