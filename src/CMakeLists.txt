#

# Project-wide library
add_library(${local_LIBTARGET} STATIC)
target_include_directories(${local_LIBTARGET} PUBLIC ${EIGEN3_INCLUDE_DIRS})
install(
	TARGETS ${local_LIBTARGET}
	ARCHIVE
	DESTINATION lib/${tpqzcam_LIBVERSION}
	)

# TPQZ basic libraries
add_subdirectory(libsys)
add_subdirectory(libio)
add_subdirectory(libdat)

# TPQZ math related libs
add_subdirectory(libmath)
add_subdirectory(libprob)
add_subdirectory(libga)
add_subdirectory(libla)
add_subdirectory(libgeo)

# TPQZ photogrammetry
add_subdirectory(libcam)



