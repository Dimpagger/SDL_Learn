# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/debug

# Include any dependencies generated for this target.
include CMakeFiles/SDL_DEMO.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SDL_DEMO.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SDL_DEMO.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDL_DEMO.dir/flags.make

CMakeFiles/SDL_DEMO.dir/sources/Game.cpp.o: CMakeFiles/SDL_DEMO.dir/flags.make
CMakeFiles/SDL_DEMO.dir/sources/Game.cpp.o: /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/sources/Game.cpp
CMakeFiles/SDL_DEMO.dir/sources/Game.cpp.o: CMakeFiles/SDL_DEMO.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SDL_DEMO.dir/sources/Game.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL_DEMO.dir/sources/Game.cpp.o -MF CMakeFiles/SDL_DEMO.dir/sources/Game.cpp.o.d -o CMakeFiles/SDL_DEMO.dir/sources/Game.cpp.o -c /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/sources/Game.cpp

CMakeFiles/SDL_DEMO.dir/sources/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SDL_DEMO.dir/sources/Game.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/sources/Game.cpp > CMakeFiles/SDL_DEMO.dir/sources/Game.cpp.i

CMakeFiles/SDL_DEMO.dir/sources/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SDL_DEMO.dir/sources/Game.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/sources/Game.cpp -o CMakeFiles/SDL_DEMO.dir/sources/Game.cpp.s

CMakeFiles/SDL_DEMO.dir/sources/Main.cpp.o: CMakeFiles/SDL_DEMO.dir/flags.make
CMakeFiles/SDL_DEMO.dir/sources/Main.cpp.o: /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/sources/Main.cpp
CMakeFiles/SDL_DEMO.dir/sources/Main.cpp.o: CMakeFiles/SDL_DEMO.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SDL_DEMO.dir/sources/Main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SDL_DEMO.dir/sources/Main.cpp.o -MF CMakeFiles/SDL_DEMO.dir/sources/Main.cpp.o.d -o CMakeFiles/SDL_DEMO.dir/sources/Main.cpp.o -c /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/sources/Main.cpp

CMakeFiles/SDL_DEMO.dir/sources/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SDL_DEMO.dir/sources/Main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/sources/Main.cpp > CMakeFiles/SDL_DEMO.dir/sources/Main.cpp.i

CMakeFiles/SDL_DEMO.dir/sources/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SDL_DEMO.dir/sources/Main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/sources/Main.cpp -o CMakeFiles/SDL_DEMO.dir/sources/Main.cpp.s

# Object files for target SDL_DEMO
SDL_DEMO_OBJECTS = \
"CMakeFiles/SDL_DEMO.dir/sources/Game.cpp.o" \
"CMakeFiles/SDL_DEMO.dir/sources/Main.cpp.o"

# External object files for target SDL_DEMO
SDL_DEMO_EXTERNAL_OBJECTS =

SDL_DEMO: CMakeFiles/SDL_DEMO.dir/sources/Game.cpp.o
SDL_DEMO: CMakeFiles/SDL_DEMO.dir/sources/Main.cpp.o
SDL_DEMO: CMakeFiles/SDL_DEMO.dir/build.make
SDL_DEMO: /opt/homebrew/lib/libSDL2main.a
SDL_DEMO: /opt/homebrew/lib/libSDL2.dylib
SDL_DEMO: /opt/homebrew/lib/libSDL2_image.dylib
SDL_DEMO: /opt/homebrew/lib/libSDL2_ttf.dylib
SDL_DEMO: CMakeFiles/SDL_DEMO.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SDL_DEMO"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL_DEMO.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SDL_DEMO.dir/build: SDL_DEMO
.PHONY : CMakeFiles/SDL_DEMO.dir/build

CMakeFiles/SDL_DEMO.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SDL_DEMO.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SDL_DEMO.dir/clean

CMakeFiles/SDL_DEMO.dir/depend:
	cd /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01 /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01 /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/debug /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/debug /Users/dingpeng/Documents/Projects/SDL_CPP/Chapter01/debug/CMakeFiles/SDL_DEMO.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SDL_DEMO.dir/depend

