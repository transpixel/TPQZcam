#

message("##### Constructing local_LIBTARGET: " ${local_LIBTARGET})

set(local_NSs

	sys
	io
	dat

	math
	ga
	la
	geo
	prob

	cam

	)

# Accumulate sources/includes to add to library all at once (for cmake <=3.12)
set(local_SOURCES)
set(local_INCLUDES)
foreach(local_NS ${local_NSs})

	set(local_NSDIR lib${local_NS})

	message("=== ")
	message("=== local_NS: " ${local_NS})
	message("=== local_NSDIR: " ${local_NSDIR})

	# get list of source files (to be compiled into library)
	# and list of include headers (to be installed in namespace locations)
	set(local_NS_SOURCES)
	set(local_NS_INCLUDES)
	include(${local_NSDIR}/FileList.cmake)

	# accumulate sources relative to current directory
	foreach(local_NS_SOURCE ${local_NS_SOURCES})
		#		message("--- local_NS_Source: " ${local_NS_SOURCE})
		list(APPEND local_SOURCES ${local_NSDIR}/${local_NS_SOURCE})
	endforeach()

	# accumulate include files relative to current directory
	foreach(local_NS_INCLUDE ${local_NS_INCLUDES})
		#		message("... local_NS_Include: " ${local_NS_INCLUDE})
		list(APPEND local_INCLUDES ${local_NSDIR}/${local_NS_INCLUDE})
	endforeach()

	# install include files for this namespace/lib
	install(
		FILES ${local_INCLUDES}
		DESTINATION
			${CMAKE_INSTALL_INCLUDEDIR}/${local_LIBTARGET}/${local_NSDIR}
		)

endforeach()



# Create library (dependent on sources and headers)
add_library(${local_LIBTARGET}
	${local_SOURCES}
	${local_INCLUDES}
	)
target_compile_options(
	${local_LIBTARGET}
	PRIVATE
		$<$<CXX_COMPILER_ID:Clang>:${BUILD_FLAGS_FOR_CLANG}>
		$<$<CXX_COMPILER_ID:GNU>:${BUILD_FLAGS_FOR_GCC}>
		$<$<CXX_COMPILER_ID:MSVC>:${BUILD_FLAGS_FOR_VISUAL}>
	)

# path to headers for building library
target_include_directories(${local_LIBTARGET}
	PRIVATE
		${CMAKE_CURRENT_LIST_DIR}
		$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
		$<INSTALL_INTERFACE:include/${local_LIBTARGET}>
	)

# target_link_libraries(${local_LIBTARGET} PUBLIC Eigen3::Eigen)


target_include_directories(${local_LIBTARGET} PUBLIC ${EIGEN3_INCLUDE_DIRS})
target_link_libraries(${local_LIBTARGET} PUBLIC Eigen3::Eigen)


# Export info
set(EXPORT_ALIAS_NAME ${PROJECT_NAME}::${local_LIBTARGET})
set(EXPORT_TARGETS_NAME ${PROJECT_NAME}Targets)
set(EXPORT_FILENAME ${EXPORT_TARGETS_NAME}.cmake)
add_library(
	${EXPORT_ALIAS_NAME}
	ALIAS
	${local_LIBTARGET}
	)

message("### CMAKE_MAJOR_VERSION: " ${CMAKE_MAJOR_VERSION})
message("### CMAKE_MINOR_VERSION: " ${CMAKE_MINOR_VERSION})
message("### CMAKE_PATCH_VERSION: " ${CMAKE_PATCH_VERSION})
message("### CMAKE_TWEAK_VERSION: " ${CMAKE_TWEAK_VERSION})
message("### PROJECT: " ${PROJECT})
message("### PROJECT_VERSION: " ${PROJECT_VERSION})
message("### local_LIBTARGET: " ${local_LIBTARGET})
message("### EXPORT_TARGETS_NAME: " ${EXPORT_TARGETS_NAME})
message("### EXPORT_FILENAME: " ${EXPORT_FILENAME})


set(local_INCDIR include/${local_LIBTARGET})
install(
	TARGETS ${local_LIBTARGET}
	EXPORT ${EXPORT_TARGETS_NAME}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	INCLUDES DESTINATION
		$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/${local_INCDIR}>
		$<INSTALL_INTERFACE:${local_INCDIR}>
	)

install(
	EXPORT ${EXPORT_TARGETS_NAME}
	FILE ${EXPORT_FILENAME}
	NAMESPACE ${PROJECT_NAME}::
	DESTINATION
		${CMAKE_INSTALL_LIBDIR}/cmake/${local_LIBTARGET}
	)


##
## Creates Config.cmake and ConfigVersion.cmake files (that use install export)
##

include(CMakePackageConfigHelpers)

configure_package_config_file(
	${CMAKE_SOURCE_DIR}/cmake/xConfig.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
	INSTALL_DESTINATION
		${CMAKE_INSTALL_LIBDIR}/cmake/${local_LIBTARGET}
	)

write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY SameMajorVersion
)

install(
	FILES
		${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
		${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
	DESTINATION
		${CMAKE_INSTALL_LIBDIR}/cmake/${local_LIBTARGET}
)


