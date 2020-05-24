
cmake_minimum_required(VERSION 3.10)
project(TPQZcamValidate)

find_package(Eigen3 REQUIRED)
find_package(TPQZcam 0.0 REQUIRED)
message("### TPQZcam_FOUND: " ${TPQZcam_FOUND})
message("### TPQZcam_VERSION: " ${TPQZcam_VERSION})

add_executable(testBuild testBuild.cpp)
target_link_libraries(testBuild PRIVATE TPQZcam::TPQZcam-0.1.0)

