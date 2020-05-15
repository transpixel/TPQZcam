
cmake_minimum_required(VERSION 3.13)

project(TPQZcamValidate)

message("hi")

# System install (e.g. "apt install ./TPQZcam...deb)
# set(TPQZcam_INSTALLDIR /tmp/include/TPQZcam-0.1.0/)
# set(TPQZcam_LIBRARY /tmp/lib/TPQZcam-0.1.0/libTPQZcam.a)

# Local test install (e.g. "make install")
set(TPQZcam_INSTALLDIR ../tmpLocalInstall/include/TPQZcam-0.1.0/)
set(TPQZcam_LIBRARY ../tmpLocalInstall/lib/TPQZcam-0.1.0/libTPQZcam.a)

set(vnvTarget "vnvProgram")
add_executable(${vnvTarget} testBuild.cpp)
# target_include_directories(${vnvTarget} PRIVATE /tmp/TPQZcam/include)
# target_link_libraries(${vnvTarget} /tmp/TPQZcam/lib/libTPQZcam.a)
target_include_directories(${vnvTarget} PRIVATE ${TPQZcamINSTALLDIR}/include)
target_link_libraries(${vnvTarget} ${TPQZcam_LIBRARY})

