#

set(local_NM la)
set(local_PREFIX ${local_LIBTARGET}_${local_NM})

set(${local_PREFIX}_SOURCES

	# x.cpp

	)

set(${local_PREFIX}_INCLUDES

	eigen.h
	la.h

	eigen.inl

	)

# CMake <= 3.12 hack

set(local_LIBDIR lib${local_NM})
foreach(local_SOURCE ${${local_PREFIX}_SOURCES})
	message("#### local_SOURCE: " ${local_SOURCE})
	target_sources(
		${local_LIBTARGET}
		PRIVATE
			${local_LIBDIR}/${local_SOURCE}
		)
endforeach()

foreach(local_INCLUDE ${${local_PREFIX}_INCLUDES})
	message("#### local_INCLUDE: " ${local_INCLUDE})
	target_sources(
		${local_LIBTARGET}
		PRIVATE
			${local_LIBDIR}/${local_INCLUDES}
		)
endforeach()

install(
	FILES ${${local_PREFIX}_INCLUDES}
	DESTINATION include/${tpqzcam_LIBVERSION}/lib${local_NM}
	)


