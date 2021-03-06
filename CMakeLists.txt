#
# === CMake info
#

cmake_minimum_required(VERSION 3.10)

project(
	TPQZcam
	VERSION 0.1.0
	LANGUAGES C CXX   # only C++ is used, but "C" for cmake to find pthreads
	)

# general configuration / dependencies
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# target_link_libraries(... ${CMAKE_THREAD_LIBS_INIT})
#
# === Upstream CMake configurations
#

# External packages - {Eigen}
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

find_package(Threads REQUIRED)


#
# === Enable unit testing
#

include(CTest)
enable_testing()

#
# === Configure project library
#

set(tpqzcam_LIBVERSION ${PROJECT_NAME}-${PROJECT_VERSION})
set(local_LIBTARGET "TPQZcam-${PROJECT_VERSION}")

# Project source code
add_subdirectory(src)

# Specify documentation generation
message("### Restore documentation")
## add_subdirectory(doc)


#
# === Configure project unit tests
#

add_subdirectory(tst)


#
# === CMake configuration for downstream builds
#


#
# === Distribution packages
#

# Override default install location for testing this package
# In general default (no command here) will install to /usr/{lib,bin,...}
# - but here, set package to isolated location for easier/safer testing
set(CPACK_PACKAGING_INSTALL_PREFIX "/tmp/${PROJECT_NAME}")

# list of packages to create (e.g. "DEB;RPM;...") if all tools installed
set(CPACK_GENERATOR "DEB")
include(cmakePack.cmake)

# Must be included after the package variables are set
include(CPack)


