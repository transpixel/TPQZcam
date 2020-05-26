#

set(local_NM math)
set(local_PREFIX ${local_LIBTARGET}_${local_NM})

set(${local_PREFIX}_SOURCES

	MapSizeArea.cpp
	Partition.cpp
	PolyFunc.cpp
	QuadEq.cpp

	)

set(${local_PREFIX}_INCLUDES

	angle.h
	CircleTab.h
	CosTable.h
	Extreme.h
	interp.h
	MapSizeArea.h
	math.h
	NumDeriv.h
	Partition.h
	PolyFunc.h
	QuadEq.h
	root.h
	smooth.h

	angle.inl
	CircleTab.inl
	CosTable.inl
	Extreme.inl
	interp.inl
	math.inl
	NumDeriv.inl
	Partition.inl
	PolyFunc.inl
	root.inl
	smooth.inl

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


