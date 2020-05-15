#

cmake_minimum_required(VERSION 3.13)

project(TPQZcam VERSION 0.1.0)
set(tpqzcam_LIBVERSION ${PROJECT_NAME}-${PROJECT_VERSION})

# External packages - {Eigen}
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# Project source code
add_subdirectory(src)

# Specify documentation generation
add_subdirectory(doc)

# Override default install location for testing this package
# In general default (no command here) will install to /usr/{lib,bin,...}
# - but here, set package to isolated location for easier/safer testing
set(CPACK_PACKAGING_INSTALL_PREFIX "/tmp/${PROJECT_NAME}")

# list of packages to create (e.g. "DEB;RPM;...") if all tools installed
set(CPACK_GENERATOR "DEB")
include(cmakePack.cmake)

# Must be included after the package variables are set
include(CPack)


