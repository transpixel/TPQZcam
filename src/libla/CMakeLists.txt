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

include(../cmakeLibs.cmake)

