# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "F:\Visual Studio Community 2017\IDE\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "F:\Visual Studio Community 2017\IDE\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mesom\Desktop\testmingw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mesom\Desktop\testmingw\build

# Utility rule file for ExperimentalConfigure.

# Include the progress variables for this target.
include CMakeFiles/ExperimentalConfigure.dir/progress.make

CMakeFiles/ExperimentalConfigure:
	cd /d C:\Users\mesom\Desktop\testmingw\build && "F:\Visual Studio Community 2017\IDE\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\ctest.exe" -D ExperimentalConfigure

ExperimentalConfigure: CMakeFiles/ExperimentalConfigure
ExperimentalConfigure: CMakeFiles/ExperimentalConfigure.dir/build.make

.PHONY : ExperimentalConfigure

# Rule to build all files generated by this target.
CMakeFiles/ExperimentalConfigure.dir/build: ExperimentalConfigure

.PHONY : CMakeFiles/ExperimentalConfigure.dir/build

CMakeFiles/ExperimentalConfigure.dir/clean:
	cd /d C:\Users\mesom\Desktop\testmingw\build && $(CMAKE_COMMAND) -P CMakeFiles\ExperimentalConfigure.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ExperimentalConfigure.dir/clean

CMakeFiles/ExperimentalConfigure.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\mesom\Desktop\testmingw C:\Users\mesom\Desktop\testmingw C:\Users\mesom\Desktop\testmingw\build C:\Users\mesom\Desktop\testmingw\build C:\Users\mesom\Desktop\testmingw\build\CMakeFiles\ExperimentalConfigure.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ExperimentalConfigure.dir/depend

