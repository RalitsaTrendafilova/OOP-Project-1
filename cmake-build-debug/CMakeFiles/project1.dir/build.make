# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\User\Desktop\oop\new\OOP-Project-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\User\Desktop\oop\new\OOP-Project-1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/project1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project1.dir/flags.make

CMakeFiles/project1.dir/main.cpp.obj: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Desktop\oop\new\OOP-Project-1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project1.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\project1.dir\main.cpp.obj -c C:\Users\User\Desktop\oop\new\OOP-Project-1\main.cpp

CMakeFiles/project1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Desktop\oop\new\OOP-Project-1\main.cpp > CMakeFiles\project1.dir\main.cpp.i

CMakeFiles/project1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Desktop\oop\new\OOP-Project-1\main.cpp -o CMakeFiles\project1.dir\main.cpp.s

CMakeFiles/project1.dir/Diary.cpp.obj: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/Diary.cpp.obj: ../Diary.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Desktop\oop\new\OOP-Project-1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project1.dir/Diary.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\project1.dir\Diary.cpp.obj -c C:\Users\User\Desktop\oop\new\OOP-Project-1\Diary.cpp

CMakeFiles/project1.dir/Diary.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/Diary.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Desktop\oop\new\OOP-Project-1\Diary.cpp > CMakeFiles\project1.dir\Diary.cpp.i

CMakeFiles/project1.dir/Diary.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/Diary.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Desktop\oop\new\OOP-Project-1\Diary.cpp -o CMakeFiles\project1.dir\Diary.cpp.s

CMakeFiles/project1.dir/User.cpp.obj: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/User.cpp.obj: ../User.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Desktop\oop\new\OOP-Project-1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project1.dir/User.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\project1.dir\User.cpp.obj -c C:\Users\User\Desktop\oop\new\OOP-Project-1\User.cpp

CMakeFiles/project1.dir/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/User.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Desktop\oop\new\OOP-Project-1\User.cpp > CMakeFiles\project1.dir\User.cpp.i

CMakeFiles/project1.dir/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/User.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Desktop\oop\new\OOP-Project-1\User.cpp -o CMakeFiles\project1.dir\User.cpp.s

CMakeFiles/project1.dir/Trip.cpp.obj: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/Trip.cpp.obj: ../Trip.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Desktop\oop\new\OOP-Project-1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project1.dir/Trip.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\project1.dir\Trip.cpp.obj -c C:\Users\User\Desktop\oop\new\OOP-Project-1\Trip.cpp

CMakeFiles/project1.dir/Trip.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/Trip.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Desktop\oop\new\OOP-Project-1\Trip.cpp > CMakeFiles\project1.dir\Trip.cpp.i

CMakeFiles/project1.dir/Trip.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/Trip.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Desktop\oop\new\OOP-Project-1\Trip.cpp -o CMakeFiles\project1.dir\Trip.cpp.s

CMakeFiles/project1.dir/Program.cpp.obj: CMakeFiles/project1.dir/flags.make
CMakeFiles/project1.dir/Program.cpp.obj: ../Program.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\User\Desktop\oop\new\OOP-Project-1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/project1.dir/Program.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\project1.dir\Program.cpp.obj -c C:\Users\User\Desktop\oop\new\OOP-Project-1\Program.cpp

CMakeFiles/project1.dir/Program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project1.dir/Program.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\User\Desktop\oop\new\OOP-Project-1\Program.cpp > CMakeFiles\project1.dir\Program.cpp.i

CMakeFiles/project1.dir/Program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project1.dir/Program.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\User\Desktop\oop\new\OOP-Project-1\Program.cpp -o CMakeFiles\project1.dir\Program.cpp.s

# Object files for target project1
project1_OBJECTS = \
"CMakeFiles/project1.dir/main.cpp.obj" \
"CMakeFiles/project1.dir/Diary.cpp.obj" \
"CMakeFiles/project1.dir/User.cpp.obj" \
"CMakeFiles/project1.dir/Trip.cpp.obj" \
"CMakeFiles/project1.dir/Program.cpp.obj"

# External object files for target project1
project1_EXTERNAL_OBJECTS =

project1.exe: CMakeFiles/project1.dir/main.cpp.obj
project1.exe: CMakeFiles/project1.dir/Diary.cpp.obj
project1.exe: CMakeFiles/project1.dir/User.cpp.obj
project1.exe: CMakeFiles/project1.dir/Trip.cpp.obj
project1.exe: CMakeFiles/project1.dir/Program.cpp.obj
project1.exe: CMakeFiles/project1.dir/build.make
project1.exe: CMakeFiles/project1.dir/linklibs.rsp
project1.exe: CMakeFiles/project1.dir/objects1.rsp
project1.exe: CMakeFiles/project1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\User\Desktop\oop\new\OOP-Project-1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable project1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\project1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project1.dir/build: project1.exe
.PHONY : CMakeFiles/project1.dir/build

CMakeFiles/project1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\project1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/project1.dir/clean

CMakeFiles/project1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\User\Desktop\oop\new\OOP-Project-1 C:\Users\User\Desktop\oop\new\OOP-Project-1 C:\Users\User\Desktop\oop\new\OOP-Project-1\cmake-build-debug C:\Users\User\Desktop\oop\new\OOP-Project-1\cmake-build-debug C:\Users\User\Desktop\oop\new\OOP-Project-1\cmake-build-debug\CMakeFiles\project1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project1.dir/depend

