# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/ray.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ray.dir/flags.make

CMakeFiles/ray.dir/Code/shapes/plane.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/plane.cpp.o: ../Code/shapes/plane.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/shapes/plane.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/shapes/plane.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/plane.cpp

CMakeFiles/ray.dir/Code/shapes/plane.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/plane.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/plane.cpp > CMakeFiles/ray.dir/Code/shapes/plane.cpp.i

CMakeFiles/ray.dir/Code/shapes/plane.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/plane.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/plane.cpp -o CMakeFiles/ray.dir/Code/shapes/plane.cpp.s

CMakeFiles/ray.dir/Code/shapes/plane.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/shapes/plane.cpp.o.requires

CMakeFiles/ray.dir/Code/shapes/plane.cpp.o.provides: CMakeFiles/ray.dir/Code/shapes/plane.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/shapes/plane.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/shapes/plane.cpp.o.provides

CMakeFiles/ray.dir/Code/shapes/plane.cpp.o.provides.build: CMakeFiles/ray.dir/Code/shapes/plane.cpp.o

CMakeFiles/ray.dir/Code/shapes/quad.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/quad.cpp.o: ../Code/shapes/quad.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/shapes/quad.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/shapes/quad.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/quad.cpp

CMakeFiles/ray.dir/Code/shapes/quad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/quad.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/quad.cpp > CMakeFiles/ray.dir/Code/shapes/quad.cpp.i

CMakeFiles/ray.dir/Code/shapes/quad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/quad.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/quad.cpp -o CMakeFiles/ray.dir/Code/shapes/quad.cpp.s

CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.requires

CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.provides: CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.provides

CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.provides.build: CMakeFiles/ray.dir/Code/shapes/quad.cpp.o

CMakeFiles/ray.dir/Code/shapes/example.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/example.cpp.o: ../Code/shapes/example.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/shapes/example.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/shapes/example.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/example.cpp

CMakeFiles/ray.dir/Code/shapes/example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/example.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/example.cpp > CMakeFiles/ray.dir/Code/shapes/example.cpp.i

CMakeFiles/ray.dir/Code/shapes/example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/example.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/example.cpp -o CMakeFiles/ray.dir/Code/shapes/example.cpp.s

CMakeFiles/ray.dir/Code/shapes/example.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/shapes/example.cpp.o.requires

CMakeFiles/ray.dir/Code/shapes/example.cpp.o.provides: CMakeFiles/ray.dir/Code/shapes/example.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/shapes/example.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/shapes/example.cpp.o.provides

CMakeFiles/ray.dir/Code/shapes/example.cpp.o.provides.build: CMakeFiles/ray.dir/Code/shapes/example.cpp.o

CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o: ../Code/shapes/mesh.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/mesh.cpp

CMakeFiles/ray.dir/Code/shapes/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/mesh.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/mesh.cpp > CMakeFiles/ray.dir/Code/shapes/mesh.cpp.i

CMakeFiles/ray.dir/Code/shapes/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/mesh.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/mesh.cpp -o CMakeFiles/ray.dir/Code/shapes/mesh.cpp.s

CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.requires

CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.provides: CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.provides

CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.provides.build: CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o

CMakeFiles/ray.dir/Code/shapes/torus.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/torus.cpp.o: ../Code/shapes/torus.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/shapes/torus.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/shapes/torus.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/torus.cpp

CMakeFiles/ray.dir/Code/shapes/torus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/torus.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/torus.cpp > CMakeFiles/ray.dir/Code/shapes/torus.cpp.i

CMakeFiles/ray.dir/Code/shapes/torus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/torus.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/torus.cpp -o CMakeFiles/ray.dir/Code/shapes/torus.cpp.s

CMakeFiles/ray.dir/Code/shapes/torus.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/shapes/torus.cpp.o.requires

CMakeFiles/ray.dir/Code/shapes/torus.cpp.o.provides: CMakeFiles/ray.dir/Code/shapes/torus.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/shapes/torus.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/shapes/torus.cpp.o.provides

CMakeFiles/ray.dir/Code/shapes/torus.cpp.o.provides.build: CMakeFiles/ray.dir/Code/shapes/torus.cpp.o

CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o: ../Code/shapes/triangle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/triangle.cpp

CMakeFiles/ray.dir/Code/shapes/triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/triangle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/triangle.cpp > CMakeFiles/ray.dir/Code/shapes/triangle.cpp.i

CMakeFiles/ray.dir/Code/shapes/triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/triangle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/triangle.cpp -o CMakeFiles/ray.dir/Code/shapes/triangle.cpp.s

CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.requires

CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.provides: CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.provides

CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.provides.build: CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o

CMakeFiles/ray.dir/Code/shapes/solvers.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/solvers.cpp.o: ../Code/shapes/solvers.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/shapes/solvers.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/shapes/solvers.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/solvers.cpp

CMakeFiles/ray.dir/Code/shapes/solvers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/solvers.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/solvers.cpp > CMakeFiles/ray.dir/Code/shapes/solvers.cpp.i

CMakeFiles/ray.dir/Code/shapes/solvers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/solvers.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/solvers.cpp -o CMakeFiles/ray.dir/Code/shapes/solvers.cpp.s

CMakeFiles/ray.dir/Code/shapes/solvers.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/shapes/solvers.cpp.o.requires

CMakeFiles/ray.dir/Code/shapes/solvers.cpp.o.provides: CMakeFiles/ray.dir/Code/shapes/solvers.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/shapes/solvers.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/shapes/solvers.cpp.o.provides

CMakeFiles/ray.dir/Code/shapes/solvers.cpp.o.provides.build: CMakeFiles/ray.dir/Code/shapes/solvers.cpp.o

CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o: ../Code/shapes/sphere.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/sphere.cpp

CMakeFiles/ray.dir/Code/shapes/sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/sphere.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/sphere.cpp > CMakeFiles/ray.dir/Code/shapes/sphere.cpp.i

CMakeFiles/ray.dir/Code/shapes/sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/sphere.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/sphere.cpp -o CMakeFiles/ray.dir/Code/shapes/sphere.cpp.s

CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.requires

CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.provides: CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.provides

CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.provides.build: CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o

CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o: ../Code/shapes/cylinder.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/cylinder.cpp

CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/cylinder.cpp > CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.i

CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/shapes/cylinder.cpp -o CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.s

CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.requires

CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.provides: CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.provides

CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.provides.build: CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o

CMakeFiles/ray.dir/Code/intersectLight.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/intersectLight.cpp.o: ../Code/intersectLight.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/intersectLight.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/intersectLight.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/intersectLight.cpp

CMakeFiles/ray.dir/Code/intersectLight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/intersectLight.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/intersectLight.cpp > CMakeFiles/ray.dir/Code/intersectLight.cpp.i

CMakeFiles/ray.dir/Code/intersectLight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/intersectLight.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/intersectLight.cpp -o CMakeFiles/ray.dir/Code/intersectLight.cpp.s

CMakeFiles/ray.dir/Code/intersectLight.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/intersectLight.cpp.o.requires

CMakeFiles/ray.dir/Code/intersectLight.cpp.o.provides: CMakeFiles/ray.dir/Code/intersectLight.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/intersectLight.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/intersectLight.cpp.o.provides

CMakeFiles/ray.dir/Code/intersectLight.cpp.o.provides.build: CMakeFiles/ray.dir/Code/intersectLight.cpp.o

CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o: ../Code/lode/lodepng.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/lode/lodepng.cpp

CMakeFiles/ray.dir/Code/lode/lodepng.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/lode/lodepng.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/lode/lodepng.cpp > CMakeFiles/ray.dir/Code/lode/lodepng.cpp.i

CMakeFiles/ray.dir/Code/lode/lodepng.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/lode/lodepng.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/lode/lodepng.cpp -o CMakeFiles/ray.dir/Code/lode/lodepng.cpp.s

CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.requires

CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.provides: CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.provides

CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.provides.build: CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o

CMakeFiles/ray.dir/Code/scene.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/scene.cpp.o: ../Code/scene.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/scene.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/scene.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/scene.cpp

CMakeFiles/ray.dir/Code/scene.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/scene.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/scene.cpp > CMakeFiles/ray.dir/Code/scene.cpp.i

CMakeFiles/ray.dir/Code/scene.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/scene.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/scene.cpp -o CMakeFiles/ray.dir/Code/scene.cpp.s

CMakeFiles/ray.dir/Code/scene.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/scene.cpp.o.requires

CMakeFiles/ray.dir/Code/scene.cpp.o.provides: CMakeFiles/ray.dir/Code/scene.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/scene.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/scene.cpp.o.provides

CMakeFiles/ray.dir/Code/scene.cpp.o.provides.build: CMakeFiles/ray.dir/Code/scene.cpp.o

CMakeFiles/ray.dir/Code/objloader.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/objloader.cpp.o: ../Code/objloader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/objloader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/objloader.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/objloader.cpp

CMakeFiles/ray.dir/Code/objloader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/objloader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/objloader.cpp > CMakeFiles/ray.dir/Code/objloader.cpp.i

CMakeFiles/ray.dir/Code/objloader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/objloader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/objloader.cpp -o CMakeFiles/ray.dir/Code/objloader.cpp.s

CMakeFiles/ray.dir/Code/objloader.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/objloader.cpp.o.requires

CMakeFiles/ray.dir/Code/objloader.cpp.o.provides: CMakeFiles/ray.dir/Code/objloader.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/objloader.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/objloader.cpp.o.provides

CMakeFiles/ray.dir/Code/objloader.cpp.o.provides.build: CMakeFiles/ray.dir/Code/objloader.cpp.o

CMakeFiles/ray.dir/Code/image.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/image.cpp.o: ../Code/image.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_14)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/image.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/image.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/image.cpp

CMakeFiles/ray.dir/Code/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/image.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/image.cpp > CMakeFiles/ray.dir/Code/image.cpp.i

CMakeFiles/ray.dir/Code/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/image.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/image.cpp -o CMakeFiles/ray.dir/Code/image.cpp.s

CMakeFiles/ray.dir/Code/image.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/image.cpp.o.requires

CMakeFiles/ray.dir/Code/image.cpp.o.provides: CMakeFiles/ray.dir/Code/image.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/image.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/image.cpp.o.provides

CMakeFiles/ray.dir/Code/image.cpp.o.provides.build: CMakeFiles/ray.dir/Code/image.cpp.o

CMakeFiles/ray.dir/Code/triple.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/triple.cpp.o: ../Code/triple.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_15)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/triple.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/triple.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/triple.cpp

CMakeFiles/ray.dir/Code/triple.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/triple.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/triple.cpp > CMakeFiles/ray.dir/Code/triple.cpp.i

CMakeFiles/ray.dir/Code/triple.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/triple.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/triple.cpp -o CMakeFiles/ray.dir/Code/triple.cpp.s

CMakeFiles/ray.dir/Code/triple.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/triple.cpp.o.requires

CMakeFiles/ray.dir/Code/triple.cpp.o.provides: CMakeFiles/ray.dir/Code/triple.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/triple.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/triple.cpp.o.provides

CMakeFiles/ray.dir/Code/triple.cpp.o.provides.build: CMakeFiles/ray.dir/Code/triple.cpp.o

CMakeFiles/ray.dir/Code/main.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/main.cpp.o: ../Code/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_16)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/main.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/main.cpp

CMakeFiles/ray.dir/Code/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/main.cpp > CMakeFiles/ray.dir/Code/main.cpp.i

CMakeFiles/ray.dir/Code/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/main.cpp -o CMakeFiles/ray.dir/Code/main.cpp.s

CMakeFiles/ray.dir/Code/main.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/main.cpp.o.requires

CMakeFiles/ray.dir/Code/main.cpp.o.provides: CMakeFiles/ray.dir/Code/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/main.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/main.cpp.o.provides

CMakeFiles/ray.dir/Code/main.cpp.o.provides.build: CMakeFiles/ray.dir/Code/main.cpp.o

CMakeFiles/ray.dir/Code/reflect.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/reflect.cpp.o: ../Code/reflect.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_17)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/reflect.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/reflect.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/reflect.cpp

CMakeFiles/ray.dir/Code/reflect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/reflect.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/reflect.cpp > CMakeFiles/ray.dir/Code/reflect.cpp.i

CMakeFiles/ray.dir/Code/reflect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/reflect.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/reflect.cpp -o CMakeFiles/ray.dir/Code/reflect.cpp.s

CMakeFiles/ray.dir/Code/reflect.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/reflect.cpp.o.requires

CMakeFiles/ray.dir/Code/reflect.cpp.o.provides: CMakeFiles/ray.dir/Code/reflect.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/reflect.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/reflect.cpp.o.provides

CMakeFiles/ray.dir/Code/reflect.cpp.o.provides.build: CMakeFiles/ray.dir/Code/reflect.cpp.o

CMakeFiles/ray.dir/Code/raytracer.cpp.o: CMakeFiles/ray.dir/flags.make
CMakeFiles/ray.dir/Code/raytracer.cpp.o: ../Code/raytracer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles $(CMAKE_PROGRESS_18)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ray.dir/Code/raytracer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ray.dir/Code/raytracer.cpp.o -c /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/raytracer.cpp

CMakeFiles/ray.dir/Code/raytracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray.dir/Code/raytracer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/raytracer.cpp > CMakeFiles/ray.dir/Code/raytracer.cpp.i

CMakeFiles/ray.dir/Code/raytracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray.dir/Code/raytracer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/Code/raytracer.cpp -o CMakeFiles/ray.dir/Code/raytracer.cpp.s

CMakeFiles/ray.dir/Code/raytracer.cpp.o.requires:
.PHONY : CMakeFiles/ray.dir/Code/raytracer.cpp.o.requires

CMakeFiles/ray.dir/Code/raytracer.cpp.o.provides: CMakeFiles/ray.dir/Code/raytracer.cpp.o.requires
	$(MAKE) -f CMakeFiles/ray.dir/build.make CMakeFiles/ray.dir/Code/raytracer.cpp.o.provides.build
.PHONY : CMakeFiles/ray.dir/Code/raytracer.cpp.o.provides

CMakeFiles/ray.dir/Code/raytracer.cpp.o.provides.build: CMakeFiles/ray.dir/Code/raytracer.cpp.o

# Object files for target ray
ray_OBJECTS = \
"CMakeFiles/ray.dir/Code/shapes/plane.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/quad.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/example.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/torus.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/solvers.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o" \
"CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o" \
"CMakeFiles/ray.dir/Code/intersectLight.cpp.o" \
"CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o" \
"CMakeFiles/ray.dir/Code/scene.cpp.o" \
"CMakeFiles/ray.dir/Code/objloader.cpp.o" \
"CMakeFiles/ray.dir/Code/image.cpp.o" \
"CMakeFiles/ray.dir/Code/triple.cpp.o" \
"CMakeFiles/ray.dir/Code/main.cpp.o" \
"CMakeFiles/ray.dir/Code/reflect.cpp.o" \
"CMakeFiles/ray.dir/Code/raytracer.cpp.o"

# External object files for target ray
ray_EXTERNAL_OBJECTS =

ray: CMakeFiles/ray.dir/Code/shapes/plane.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/quad.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/example.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/torus.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/solvers.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o
ray: CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o
ray: CMakeFiles/ray.dir/Code/intersectLight.cpp.o
ray: CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o
ray: CMakeFiles/ray.dir/Code/scene.cpp.o
ray: CMakeFiles/ray.dir/Code/objloader.cpp.o
ray: CMakeFiles/ray.dir/Code/image.cpp.o
ray: CMakeFiles/ray.dir/Code/triple.cpp.o
ray: CMakeFiles/ray.dir/Code/main.cpp.o
ray: CMakeFiles/ray.dir/Code/reflect.cpp.o
ray: CMakeFiles/ray.dir/Code/raytracer.cpp.o
ray: CMakeFiles/ray.dir/build.make
ray: CMakeFiles/ray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ray.dir/build: ray
.PHONY : CMakeFiles/ray.dir/build

CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/shapes/plane.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/shapes/quad.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/shapes/example.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/shapes/mesh.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/shapes/torus.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/shapes/triangle.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/shapes/solvers.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/shapes/sphere.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/shapes/cylinder.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/intersectLight.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/lode/lodepng.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/scene.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/objloader.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/image.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/triple.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/main.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/reflect.cpp.o.requires
CMakeFiles/ray.dir/requires: CMakeFiles/ray.dir/Code/raytracer.cpp.o.requires
.PHONY : CMakeFiles/ray.dir/requires

CMakeFiles/ray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ray.dir/clean

CMakeFiles/ray.dir/depend:
	cd /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build /home/gebruiker/Progammas/School/CG/gitOpengl/raytracer/raytracerframework_cpp/build/CMakeFiles/ray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ray.dir/depend

