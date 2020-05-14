#

cmake_minimum_required(VERSION 3.13)

project(LiteTPQZ)

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

