#

set(local_PREFIX litetpqz_io) # keep cmake target names unique

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

include(../cmakeLibs.cmake)

