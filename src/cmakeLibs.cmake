#
# cmake commands for creating library targets
#

set(local_TARGET ${local_PREFIX})

add_library(${local_TARGET} STATIC ${${local_PREFIX}_SOURCES})
target_sources(${local_TARGET} PUBLIC ${${local_PREFIX}_INCLUDES})
target_include_directories(${local_TARGET} PUBLIC ../)

target_compile_features(${local_TARGET} PRIVATE cxx_std_11)

install(
	FILES ${${local_PREFIX}_INCLUDES}
	DESTINATION include/${CMAKE_PROJECT_NAME}/${local_NM}
	)
install(
	TARGETS ${local_TARGET}
	ARCHIVE
	DESTINATION lib
	)

target_include_directories(${local_TARGET} PUBLIC ${EIGEN3_INCLUDE_DIRS})

