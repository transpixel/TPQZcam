#
# cmake commands for creating library targets
#

target_sources_local(
	${local_LIBTARGET}
	PRIVATE
		${${local_PREFIX}_SOURCES}
	)

target_sources_local(
	${local_LIBTARGET}
	PRIVATE
		${${local_PREFIX}_INCLUDES}
	)

install(
	FILES ${${local_PREFIX}_INCLUDES}
	DESTINATION include/${tpqzcam_LIBVERSION}/lib${local_NM}
	)

