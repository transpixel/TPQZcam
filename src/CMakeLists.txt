#

message("### local_LIBTARGET: " ${local_LIBTARGET})

# workaround for path issue (CMP0076 in cmake < 3.12)
include(cmakeFuncs.cmake)

# Project-wide library
add_library(
	${local_LIBTARGET}
	""
	)

target_include_directories(${local_LIBTARGET} PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(${local_LIBTARGET} PUBLIC Eigen3::Eigen)

# includes relative to this src/ directory
target_include_directories(${local_LIBTARGET} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

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

# Export info
set(EXPORT_LIB_NAME ${PROJECT_NAME}::${local_LIBTARGET})
set(EXPORT_TARGETS_NAME ${PROJECT_NAME}Targets)
set(EXPORT_FILENAME ${EXPORT_TARGETS_NAME}.cmake)
add_library(
	${EXPORT_LIB_NAME}
	ALIAS
	${local_LIBTARGET}
	)

#[[
install(
	TARGETS ${local_LIBTARGET}
	EXPORT ${EXPORT_TARGETS_NAME}
	ARCHIVE DESTINATION lib  # /${tpqzcam_LIBVERSION}
	LIBRARY DESTINATION lib  # /${tpqzcam_LIBVERSION}
	RUNTIME DESTINATION bin
	INCLUDES DESTINATION
	    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/${PROJECT_NAME}>
        $<INSTALL_INTERFACE:include>
	)

install(
	EXPORT ${EXPORT_TARGETS_NAME}
	FILE ${EXPORT_FILENAME}
	NAMESPACE ${PROJECT_NAME}::
	DESTINATION
		lib/cmake/${PROJECT_NAME}
	)
#]]


