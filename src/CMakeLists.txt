#

cmake_minimum_required(VERSION 3.13)

project(LiteTPQZ VERSION 0.1.0)

# External packages - {Eigen}
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# Project-wide library
set(local_LIBTARGET "LiteTPQZ")
add_library(${local_LIBTARGET} STATIC)

# TPQZ basic libraries
add_subdirectory(libsys)
add_subdirectory(libio)
add_subdirectory(libdat)

# TPQZ math related libs
add_subdirectory(libmath)
add_subdirectory(libprob)
add_subdirectory(libga)
# add_subdirectory(libla)
add_subdirectory(libgeo)

# TPQZ photogrammetry
add_subdirectory(libcam)


# Specify documentation generation
include(cmakeDox.cmake)


# Override default install location for testing this package
# In general default (no command here) will install to /usr/{lib,bin,...}
# - but here, set package to isolated location for easier/safer testing
set(CPACK_PACKAGING_INSTALL_PREFIX "/tmp/${PROJECT_NAME}")

# list of packages to create (e.g. "DEB;RPM;...") if all tools installed
set(CPACK_GENERATOR "DEB")
include(cmakePack.cmake)

# Must be included after the package variables are set
include(CPack)


