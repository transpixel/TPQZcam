#
# === CMake info
#

cmake_minimum_required(VERSION 3.10)

set(TPQZcamVersion "0.1.4")
# using
set(EigenVersion "3.3")

project(
	TPQZcam
	VERSION ${TPQZcamVersion}
	LANGUAGES C CXX   # only C++ is used, but "C" for cmake to find pthreads
	)

# general configuration / dependencies
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# If any compile flags definitions - add here
add_definitions()


set(BUILD_FLAGS_FOR_CLANG
	""
	)
set(BUILD_FLAGS_FOR_GCC
	#
	# Disable
	#	https://gcc.gnu.org/bugzilla/show_bug.cgi?id=77728
	#	https://gcc.gnu.org/gcc-7/changes.html (ref "On ARM...")
	-Wno-psabi
	#
	-Wc++11-compat
	-pthread
	-fomit-frame-pointer
	-Wextra
	-Wuninitialized
	-Winit-self
	-fno-operator-names
	-fstrict-enums
	#
	-pedantic-errors
	-fno-nonansi-builtins
	-Wall
	)
set(BUILD_FLAGS_FOR_VISUAL
	""
	)


# target_link_libraries(... ${CMAKE_THREAD_LIBS_INIT})
#
# === Upstream CMake configurations
#

# External packages - {Eigen}
find_package(Eigen3 ${EigenVersion} REQUIRED NO_MODULE)

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

# === GNU standard paths
include(GNUInstallDirs)  # creates "CMAKE_INSTALL_<dir>"


# Project source code
add_subdirectory(src)

# Specify documentation generation
## message("@@@@ - re-enable document processing")
add_subdirectory(doc)


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
## set (DEB_PACKAGE_ROOT "/tmp/local/${PROJECT_NAME}")
# - default is "/usr" (e.g. for system packages)
# - specify explicitly as "/usr/local" as a developer local package
set (DEB_PACKAGE_ROOT "/usr/local/")
set(CPACK_PACKAGING_INSTALL_PREFIX "${DEB_PACKAGE_ROOT}")

# list of packages to create (e.g. "DEB;RPM;...") if all tools installed
set(CPACK_GENERATOR "DEB")
include("${CMAKE_SOURCE_DIR}/cmake/cmakePack.cmake")

# Must be included after the package variables are set
include(CPack)

message("###")
message("### CMAKE_INSTALL_LIBDIR: " ${CMAKE_INSTALL_LIBDIR})
message("### CMAKE_INSTALL_BINDIR: " ${CMAKE_INSTALL_BINDIR})
message("### CMAKE_INSTALL_INCLUDEDIR: " ${CMAKE_INSTALL_INCLUDEDIR})
message("### CMAKE_INSTALL_DOCDIR: " ${CMAKE_INSTALL_DOCDIR})
message("###")
message("### CMAKE_INSTALL_FULL_LIBDIR: " ${CMAKE_INSTALL_FULL_LIBDIR})
message("### CMAKE_INSTALL_FULL_BINDIR: " ${CMAKE_INSTALL_FULL_BINDIR})
message("### CMAKE_INSTALL_FULL_INCLUDEDIR: " ${CMAKE_INSTALL_FULL_INCLUDEDIR})
message("### CMAKE_INSTALL_FULL_DOCDIR: " ${CMAKE_INSTALL_FULL_DOCDIR})
message("###")
message("### DEB_PACKAGE_ROOT: " ${DEB_PACKAGE_ROOT})
message("###")

