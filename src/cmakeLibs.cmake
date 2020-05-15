#
# cmake commands for creating library targets
#

# # Individual libraries per namespace
# set(local_LIBTARGET ${local_PREFIX})
# add_library(${local_LIBTARGET} STATIC)

target_sources(${local_LIBTARGET} PRIVATE ${${local_PREFIX}_SOURCES})
target_sources(${local_LIBTARGET} PUBLIC ${${local_PREFIX}_INCLUDES})
target_include_directories(${local_LIBTARGET} PUBLIC ../)

target_compile_features(${local_LIBTARGET} PRIVATE cxx_std_11)

install(
	FILES ${${local_PREFIX}_INCLUDES}
	DESTINATION include/${tpqzcam_LIBVERSION}/lib${local_NM}
	)

