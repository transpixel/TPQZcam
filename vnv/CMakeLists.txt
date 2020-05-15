
cmake_minimum_required(VERSION 3.13)

project(TPQZcamValidate)

message("hi")

set(vnvTarget "vnvProgram")
add_executable(${vnvTarget} testBuild.cpp)
target_include_directories(${vnvTarget} PRIVATE /tmp/TPQZcam/include)
target_link_libraries(${vnvTarget} /tmp/TPQZcam/lib/libTPQZcam.a)

