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
CMAKE_COMMAND = C:\msys64\mingw64\bin\cmake.exe

# The command to remove a file.
RM = C:\msys64\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = X:\CARRERA\5_CARRERA\PEL\EntregaCasaU3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = X:\CARRERA\5_CARRERA\PEL\EntregaCasaU3\build

# Include any dependencies generated for this target.
include CMakeFiles/Ejercicio.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Ejercicio.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Ejercicio.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ejercicio.dir/flags.make

CMakeFiles/Ejercicio.dir/main.cpp.obj: CMakeFiles/Ejercicio.dir/flags.make
CMakeFiles/Ejercicio.dir/main.cpp.obj: ../main.cpp
CMakeFiles/Ejercicio.dir/main.cpp.obj: CMakeFiles/Ejercicio.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=X:\CARRERA\5_CARRERA\PEL\EntregaCasaU3\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ejercicio.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Ejercicio.dir/main.cpp.obj -MF CMakeFiles\Ejercicio.dir\main.cpp.obj.d -o CMakeFiles\Ejercicio.dir\main.cpp.obj -c X:\CARRERA\5_CARRERA\PEL\EntregaCasaU3\main.cpp

CMakeFiles/Ejercicio.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ejercicio.dir/main.cpp.i"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E X:\CARRERA\5_CARRERA\PEL\EntregaCasaU3\main.cpp > CMakeFiles\Ejercicio.dir\main.cpp.i

CMakeFiles/Ejercicio.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ejercicio.dir/main.cpp.s"
	C:\msys64\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S X:\CARRERA\5_CARRERA\PEL\EntregaCasaU3\main.cpp -o CMakeFiles\Ejercicio.dir\main.cpp.s

# Object files for target Ejercicio
Ejercicio_OBJECTS = \
"CMakeFiles/Ejercicio.dir/main.cpp.obj"

# External object files for target Ejercicio
Ejercicio_EXTERNAL_OBJECTS =

Ejercicio.exe: CMakeFiles/Ejercicio.dir/main.cpp.obj
Ejercicio.exe: CMakeFiles/Ejercicio.dir/build.make
Ejercicio.exe: CMakeFiles/Ejercicio.dir/linklibs.rsp
Ejercicio.exe: CMakeFiles/Ejercicio.dir/objects1.rsp
Ejercicio.exe: CMakeFiles/Ejercicio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=X:\CARRERA\5_CARRERA\PEL\EntregaCasaU3\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Ejercicio.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Ejercicio.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ejercicio.dir/build: Ejercicio.exe
.PHONY : CMakeFiles/Ejercicio.dir/build

CMakeFiles/Ejercicio.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ejercicio.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Ejercicio.dir/clean

CMakeFiles/Ejercicio.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" X:\CARRERA\5_CARRERA\PEL\EntregaCasaU3 X:\CARRERA\5_CARRERA\PEL\EntregaCasaU3 X:\CARRERA\5_CARRERA\PEL\EntregaCasaU3\build X:\CARRERA\5_CARRERA\PEL\EntregaCasaU3\build X:\CARRERA\5_CARRERA\PEL\EntregaCasaU3\build\CMakeFiles\Ejercicio.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Ejercicio.dir/depend
