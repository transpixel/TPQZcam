#
# cmake commands for creating library targets
#

# # Individual libraries per namespace
# set(local_LIBTARGET ${local_PREFIX})
# add_library(${local_LIBTARGET} STATIC)

message("local_NM: " ${local_NM})
message("local_PREFIX: " ${local_PREFIX})
message("local_LIBTARGET: " ${local_LIBTARGET})

target_sources(${local_LIBTARGET} PRIVATE ${${local_PREFIX}_SOURCES})
target_sources(${local_LIBTARGET} PUBLIC ${${local_PREFIX}_INCLUDES})
target_include_directories(${local_LIBTARGET} PUBLIC ../)

target_compile_features(${local_LIBTARGET} PRIVATE cxx_std_11)

install(
	FILES ${${local_PREFIX}_INCLUDES}
	DESTINATION include/${tpqzcam_LIBVERSION}/lib${local_NM}
	)
install(
	TARGETS ${local_LIBTARGET}
	ARCHIVE
	DESTINATION lib/${tpqzcam_LIBVERSION}
	)

target_include_directories(${local_LIBTARGET} PUBLIC ${EIGEN3_INCLUDE_DIRS})

