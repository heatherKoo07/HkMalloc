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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hyunkyungkoo/Dropbox/Hyunkyung/DeAnza/Winter2019/CIS26B_AdvC/HKMalloc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hyunkyungkoo/Dropbox/Hyunkyung/DeAnza/Winter2019/CIS26B_AdvC/HKMalloc/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HKMalloc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HKMalloc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HKMalloc.dir/flags.make

CMakeFiles/HKMalloc.dir/test2.cc.o: CMakeFiles/HKMalloc.dir/flags.make
CMakeFiles/HKMalloc.dir/test2.cc.o: ../test2.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hyunkyungkoo/Dropbox/Hyunkyung/DeAnza/Winter2019/CIS26B_AdvC/HKMalloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HKMalloc.dir/test2.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HKMalloc.dir/test2.cc.o -c /Users/hyunkyungkoo/Dropbox/Hyunkyung/DeAnza/Winter2019/CIS26B_AdvC/HKMalloc/test2.cc

CMakeFiles/HKMalloc.dir/test2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HKMalloc.dir/test2.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hyunkyungkoo/Dropbox/Hyunkyung/DeAnza/Winter2019/CIS26B_AdvC/HKMalloc/test2.cc > CMakeFiles/HKMalloc.dir/test2.cc.i

CMakeFiles/HKMalloc.dir/test2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HKMalloc.dir/test2.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hyunkyungkoo/Dropbox/Hyunkyung/DeAnza/Winter2019/CIS26B_AdvC/HKMalloc/test2.cc -o CMakeFiles/HKMalloc.dir/test2.cc.s

# Object files for target HKMalloc
HKMalloc_OBJECTS = \
"CMakeFiles/HKMalloc.dir/test2.cc.o"

# External object files for target HKMalloc
HKMalloc_EXTERNAL_OBJECTS =

HKMalloc: CMakeFiles/HKMalloc.dir/test2.cc.o
HKMalloc: CMakeFiles/HKMalloc.dir/build.make
HKMalloc: CMakeFiles/HKMalloc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hyunkyungkoo/Dropbox/Hyunkyung/DeAnza/Winter2019/CIS26B_AdvC/HKMalloc/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HKMalloc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HKMalloc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HKMalloc.dir/build: HKMalloc

.PHONY : CMakeFiles/HKMalloc.dir/build

CMakeFiles/HKMalloc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HKMalloc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HKMalloc.dir/clean

CMakeFiles/HKMalloc.dir/depend:
	cd /Users/hyunkyungkoo/Dropbox/Hyunkyung/DeAnza/Winter2019/CIS26B_AdvC/HKMalloc/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hyunkyungkoo/Dropbox/Hyunkyung/DeAnza/Winter2019/CIS26B_AdvC/HKMalloc /Users/hyunkyungkoo/Dropbox/Hyunkyung/DeAnza/Winter2019/CIS26B_AdvC/HKMalloc /Users/hyunkyungkoo/Dropbox/Hyunkyung/DeAnza/Winter2019/CIS26B_AdvC/HKMalloc/cmake-build-debug /Users/hyunkyungkoo/Dropbox/Hyunkyung/DeAnza/Winter2019/CIS26B_AdvC/HKMalloc/cmake-build-debug /Users/hyunkyungkoo/Dropbox/Hyunkyung/DeAnza/Winter2019/CIS26B_AdvC/HKMalloc/cmake-build-debug/CMakeFiles/HKMalloc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HKMalloc.dir/depend

