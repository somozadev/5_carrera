# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mesom\CARRERA_2021\5_carrera

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mesom\CARRERA_2021\5_carrera\build

# Include any dependencies generated for this target.
include CMakeFiles/minmax.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/minmax.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/minmax.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minmax.dir/flags.make

CMakeFiles/minmax.dir/main.cpp.obj: CMakeFiles/minmax.dir/flags.make
CMakeFiles/minmax.dir/main.cpp.obj: ../main.cpp
CMakeFiles/minmax.dir/main.cpp.obj: CMakeFiles/minmax.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mesom\CARRERA_2021\5_carrera\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/minmax.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/minmax.dir/main.cpp.obj -MF CMakeFiles\minmax.dir\main.cpp.obj.d -o CMakeFiles\minmax.dir\main.cpp.obj -c C:\Users\mesom\CARRERA_2021\5_carrera\main.cpp

CMakeFiles/minmax.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/minmax.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mesom\CARRERA_2021\5_carrera\main.cpp > CMakeFiles\minmax.dir\main.cpp.i

CMakeFiles/minmax.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/minmax.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\mesom\CARRERA_2021\5_carrera\main.cpp -o CMakeFiles\minmax.dir\main.cpp.s

# Object files for target minmax
minmax_OBJECTS = \
"CMakeFiles/minmax.dir/main.cpp.obj"

# External object files for target minmax
minmax_EXTERNAL_OBJECTS =

minmax.exe: CMakeFiles/minmax.dir/main.cpp.obj
minmax.exe: CMakeFiles/minmax.dir/build.make
minmax.exe: CMakeFiles/minmax.dir/linklibs.rsp
minmax.exe: CMakeFiles/minmax.dir/objects1.rsp
minmax.exe: CMakeFiles/minmax.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mesom\CARRERA_2021\5_carrera\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable minmax.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\minmax.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minmax.dir/build: minmax.exe
.PHONY : CMakeFiles/minmax.dir/build

CMakeFiles/minmax.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\minmax.dir\cmake_clean.cmake
.PHONY : CMakeFiles/minmax.dir/clean

CMakeFiles/minmax.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mesom\CARRERA_2021\5_carrera C:\Users\mesom\CARRERA_2021\5_carrera C:\Users\mesom\CARRERA_2021\5_carrera\build C:\Users\mesom\CARRERA_2021\5_carrera\build C:\Users\mesom\CARRERA_2021\5_carrera\build\CMakeFiles\minmax.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minmax.dir/depend

