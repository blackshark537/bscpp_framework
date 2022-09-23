# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.24.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.24.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/macbookpro/development/cpp_projects/window

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/macbookpro/development/cpp_projects/window

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.24.2/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.24.2/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/macbookpro/development/cpp_projects/window/CMakeFiles /Users/macbookpro/development/cpp_projects/window//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/macbookpro/development/cpp_projects/window/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named glad

# Build rule for target.
glad: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 glad
.PHONY : glad

# fast build rule for target.
glad/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/glad.dir/build.make CMakeFiles/glad.dir/build
.PHONY : glad/fast

#=============================================================================
# Target rules for targets named myAPP

# Build rule for target.
myAPP: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 myAPP
.PHONY : myAPP

# fast build rule for target.
myAPP/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/build
.PHONY : myAPP/fast

imgui/imgui.o: imgui/imgui.cpp.o
.PHONY : imgui/imgui.o

# target to build an object file
imgui/imgui.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui.cpp.o
.PHONY : imgui/imgui.cpp.o

imgui/imgui.i: imgui/imgui.cpp.i
.PHONY : imgui/imgui.i

# target to preprocess a source file
imgui/imgui.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui.cpp.i
.PHONY : imgui/imgui.cpp.i

imgui/imgui.s: imgui/imgui.cpp.s
.PHONY : imgui/imgui.s

# target to generate assembly for a file
imgui/imgui.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui.cpp.s
.PHONY : imgui/imgui.cpp.s

imgui/imgui_demo.o: imgui/imgui_demo.cpp.o
.PHONY : imgui/imgui_demo.o

# target to build an object file
imgui/imgui_demo.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui_demo.cpp.o
.PHONY : imgui/imgui_demo.cpp.o

imgui/imgui_demo.i: imgui/imgui_demo.cpp.i
.PHONY : imgui/imgui_demo.i

# target to preprocess a source file
imgui/imgui_demo.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui_demo.cpp.i
.PHONY : imgui/imgui_demo.cpp.i

imgui/imgui_demo.s: imgui/imgui_demo.cpp.s
.PHONY : imgui/imgui_demo.s

# target to generate assembly for a file
imgui/imgui_demo.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui_demo.cpp.s
.PHONY : imgui/imgui_demo.cpp.s

imgui/imgui_draw.o: imgui/imgui_draw.cpp.o
.PHONY : imgui/imgui_draw.o

# target to build an object file
imgui/imgui_draw.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui_draw.cpp.o
.PHONY : imgui/imgui_draw.cpp.o

imgui/imgui_draw.i: imgui/imgui_draw.cpp.i
.PHONY : imgui/imgui_draw.i

# target to preprocess a source file
imgui/imgui_draw.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui_draw.cpp.i
.PHONY : imgui/imgui_draw.cpp.i

imgui/imgui_draw.s: imgui/imgui_draw.cpp.s
.PHONY : imgui/imgui_draw.s

# target to generate assembly for a file
imgui/imgui_draw.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui_draw.cpp.s
.PHONY : imgui/imgui_draw.cpp.s

imgui/imgui_impl_opengl3.o: imgui/imgui_impl_opengl3.cpp.o
.PHONY : imgui/imgui_impl_opengl3.o

# target to build an object file
imgui/imgui_impl_opengl3.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui_impl_opengl3.cpp.o
.PHONY : imgui/imgui_impl_opengl3.cpp.o

imgui/imgui_impl_opengl3.i: imgui/imgui_impl_opengl3.cpp.i
.PHONY : imgui/imgui_impl_opengl3.i

# target to preprocess a source file
imgui/imgui_impl_opengl3.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui_impl_opengl3.cpp.i
.PHONY : imgui/imgui_impl_opengl3.cpp.i

imgui/imgui_impl_opengl3.s: imgui/imgui_impl_opengl3.cpp.s
.PHONY : imgui/imgui_impl_opengl3.s

# target to generate assembly for a file
imgui/imgui_impl_opengl3.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui_impl_opengl3.cpp.s
.PHONY : imgui/imgui_impl_opengl3.cpp.s

imgui/imgui_impl_sdl.o: imgui/imgui_impl_sdl.cpp.o
.PHONY : imgui/imgui_impl_sdl.o

# target to build an object file
imgui/imgui_impl_sdl.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui_impl_sdl.cpp.o
.PHONY : imgui/imgui_impl_sdl.cpp.o

imgui/imgui_impl_sdl.i: imgui/imgui_impl_sdl.cpp.i
.PHONY : imgui/imgui_impl_sdl.i

# target to preprocess a source file
imgui/imgui_impl_sdl.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui_impl_sdl.cpp.i
.PHONY : imgui/imgui_impl_sdl.cpp.i

imgui/imgui_impl_sdl.s: imgui/imgui_impl_sdl.cpp.s
.PHONY : imgui/imgui_impl_sdl.s

# target to generate assembly for a file
imgui/imgui_impl_sdl.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui_impl_sdl.cpp.s
.PHONY : imgui/imgui_impl_sdl.cpp.s

imgui/imgui_widgets.o: imgui/imgui_widgets.cpp.o
.PHONY : imgui/imgui_widgets.o

# target to build an object file
imgui/imgui_widgets.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui_widgets.cpp.o
.PHONY : imgui/imgui_widgets.cpp.o

imgui/imgui_widgets.i: imgui/imgui_widgets.cpp.i
.PHONY : imgui/imgui_widgets.i

# target to preprocess a source file
imgui/imgui_widgets.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui_widgets.cpp.i
.PHONY : imgui/imgui_widgets.cpp.i

imgui/imgui_widgets.s: imgui/imgui_widgets.cpp.s
.PHONY : imgui/imgui_widgets.s

# target to generate assembly for a file
imgui/imgui_widgets.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/imgui/imgui_widgets.cpp.s
.PHONY : imgui/imgui_widgets.cpp.s

include/bsc/main_app.o: include/bsc/main_app.cpp.o
.PHONY : include/bsc/main_app.o

# target to build an object file
include/bsc/main_app.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/include/bsc/main_app.cpp.o
.PHONY : include/bsc/main_app.cpp.o

include/bsc/main_app.i: include/bsc/main_app.cpp.i
.PHONY : include/bsc/main_app.i

# target to preprocess a source file
include/bsc/main_app.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/include/bsc/main_app.cpp.i
.PHONY : include/bsc/main_app.cpp.i

include/bsc/main_app.s: include/bsc/main_app.cpp.s
.PHONY : include/bsc/main_app.s

# target to generate assembly for a file
include/bsc/main_app.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/include/bsc/main_app.cpp.s
.PHONY : include/bsc/main_app.cpp.s

include/glad/glad.o: include/glad/glad.c.o
.PHONY : include/glad/glad.o

# target to build an object file
include/glad/glad.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/glad.dir/build.make CMakeFiles/glad.dir/include/glad/glad.c.o
.PHONY : include/glad/glad.c.o

include/glad/glad.i: include/glad/glad.c.i
.PHONY : include/glad/glad.i

# target to preprocess a source file
include/glad/glad.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/glad.dir/build.make CMakeFiles/glad.dir/include/glad/glad.c.i
.PHONY : include/glad/glad.c.i

include/glad/glad.s: include/glad/glad.c.s
.PHONY : include/glad/glad.s

# target to generate assembly for a file
include/glad/glad.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/glad.dir/build.make CMakeFiles/glad.dir/include/glad/glad.c.s
.PHONY : include/glad/glad.c.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/myAPP.dir/build.make CMakeFiles/myAPP.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... glad"
	@echo "... myAPP"
	@echo "... imgui/imgui.o"
	@echo "... imgui/imgui.i"
	@echo "... imgui/imgui.s"
	@echo "... imgui/imgui_demo.o"
	@echo "... imgui/imgui_demo.i"
	@echo "... imgui/imgui_demo.s"
	@echo "... imgui/imgui_draw.o"
	@echo "... imgui/imgui_draw.i"
	@echo "... imgui/imgui_draw.s"
	@echo "... imgui/imgui_impl_opengl3.o"
	@echo "... imgui/imgui_impl_opengl3.i"
	@echo "... imgui/imgui_impl_opengl3.s"
	@echo "... imgui/imgui_impl_sdl.o"
	@echo "... imgui/imgui_impl_sdl.i"
	@echo "... imgui/imgui_impl_sdl.s"
	@echo "... imgui/imgui_widgets.o"
	@echo "... imgui/imgui_widgets.i"
	@echo "... imgui/imgui_widgets.s"
	@echo "... include/bsc/main_app.o"
	@echo "... include/bsc/main_app.i"
	@echo "... include/bsc/main_app.s"
	@echo "... include/glad/glad.o"
	@echo "... include/glad/glad.i"
	@echo "... include/glad/glad.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

