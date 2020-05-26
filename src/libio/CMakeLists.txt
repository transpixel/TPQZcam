#

set(local_NM io)
set(local_PREFIX ${local_LIBTARGET}_${local_NM})

set(${local_PREFIX}_SOURCES

	binary.cpp
	file.cpp
	LinePrefixer.cpp
	stream.cpp
	string.cpp
	text.cpp

	)

set(${local_PREFIX}_INCLUDES

	binary.h
	file.h
	io.h
	LinePrefixer.h
	sprintf.h
	stream.h
	string.h
	text.h
	utf8.h

	binary.inl
	sprintf.inl
	stream.inl
	string.inl
	utf8.inl

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

