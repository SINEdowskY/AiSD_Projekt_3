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
CMAKE_COMMAND = C:\Users\kub20\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.6461.46\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\kub20\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.6461.46\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\kub20\CLionProjects\algorytmy_lab_zad3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\kub20\CLionProjects\algorytmy_lab_zad3\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GrafAlgorytmyProjekt3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/GrafAlgorytmyProjekt3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/GrafAlgorytmyProjekt3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GrafAlgorytmyProjekt3.dir/flags.make

CMakeFiles/GrafAlgorytmyProjekt3.dir/main.cpp.obj: CMakeFiles/GrafAlgorytmyProjekt3.dir/flags.make
CMakeFiles/GrafAlgorytmyProjekt3.dir/main.cpp.obj: ../main.cpp
CMakeFiles/GrafAlgorytmyProjekt3.dir/main.cpp.obj: CMakeFiles/GrafAlgorytmyProjekt3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\kub20\CLionProjects\algorytmy_lab_zad3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GrafAlgorytmyProjekt3.dir/main.cpp.obj"
	C:\Users\kub20\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.6461.46\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/GrafAlgorytmyProjekt3.dir/main.cpp.obj -MF CMakeFiles\GrafAlgorytmyProjekt3.dir\main.cpp.obj.d -o CMakeFiles\GrafAlgorytmyProjekt3.dir\main.cpp.obj -c C:\Users\kub20\CLionProjects\algorytmy_lab_zad3\main.cpp

CMakeFiles/GrafAlgorytmyProjekt3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GrafAlgorytmyProjekt3.dir/main.cpp.i"
	C:\Users\kub20\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.6461.46\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\kub20\CLionProjects\algorytmy_lab_zad3\main.cpp > CMakeFiles\GrafAlgorytmyProjekt3.dir\main.cpp.i

CMakeFiles/GrafAlgorytmyProjekt3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GrafAlgorytmyProjekt3.dir/main.cpp.s"
	C:\Users\kub20\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.6461.46\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\kub20\CLionProjects\algorytmy_lab_zad3\main.cpp -o CMakeFiles\GrafAlgorytmyProjekt3.dir\main.cpp.s

# Object files for target GrafAlgorytmyProjekt3
GrafAlgorytmyProjekt3_OBJECTS = \
"CMakeFiles/GrafAlgorytmyProjekt3.dir/main.cpp.obj"

# External object files for target GrafAlgorytmyProjekt3
GrafAlgorytmyProjekt3_EXTERNAL_OBJECTS =

GrafAlgorytmyProjekt3.exe: CMakeFiles/GrafAlgorytmyProjekt3.dir/main.cpp.obj
GrafAlgorytmyProjekt3.exe: CMakeFiles/GrafAlgorytmyProjekt3.dir/build.make
GrafAlgorytmyProjekt3.exe: CMakeFiles/GrafAlgorytmyProjekt3.dir/linklibs.rsp
GrafAlgorytmyProjekt3.exe: CMakeFiles/GrafAlgorytmyProjekt3.dir/objects1.rsp
GrafAlgorytmyProjekt3.exe: CMakeFiles/GrafAlgorytmyProjekt3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\kub20\CLionProjects\algorytmy_lab_zad3\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GrafAlgorytmyProjekt3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GrafAlgorytmyProjekt3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GrafAlgorytmyProjekt3.dir/build: GrafAlgorytmyProjekt3.exe
.PHONY : CMakeFiles/GrafAlgorytmyProjekt3.dir/build

CMakeFiles/GrafAlgorytmyProjekt3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GrafAlgorytmyProjekt3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GrafAlgorytmyProjekt3.dir/clean

CMakeFiles/GrafAlgorytmyProjekt3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\kub20\CLionProjects\algorytmy_lab_zad3 C:\Users\kub20\CLionProjects\algorytmy_lab_zad3 C:\Users\kub20\CLionProjects\algorytmy_lab_zad3\cmake-build-debug C:\Users\kub20\CLionProjects\algorytmy_lab_zad3\cmake-build-debug C:\Users\kub20\CLionProjects\algorytmy_lab_zad3\cmake-build-debug\CMakeFiles\GrafAlgorytmyProjekt3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GrafAlgorytmyProjekt3.dir/depend

