#

set(local_NM dat)
set(local_PREFIX ${local_LIBTARGET}_${local_NM})

set(${local_PREFIX}_SOURCES

	Extents.cpp
	ExtentsIterator.cpp
	IndexIterator.cpp
	iter.cpp
	Jump.cpp
	KeyedValues.cpp
	layout.cpp
	NdxBegEnd.cpp
	QuantumFrac.cpp
	SpotX.cpp
	SubExtents.cpp

	)

set(${local_PREFIX}_INCLUDES

	algorithm.h
	Area.h
	array.h
	BestOf.h
	bit.h
	cast.h
	compare.h
	dat.h
	discrete.h
	docIterExample.h
	Extents.h
	ExtentsIterator.h
	grid.h
	IndexIterator.h
	info.h
	io.h
	iter.h
	Jump.h
	KeyedValues.h
	Latice.h
	layout.h
	limits.h
	MinMax.h
	NdxBegEnd.h
	Offset2D.h
	ops.h
	QuantumFrac.h
	quantum.h
	random.h
	Range.h
	Region.h
	RowCol.h
	Spot.h
	SpotX.h
	SubExtents.h
	template.h
	types.h
	validity.h
	Volume.h
	xform.h

	algorithm.inl
	array.inl
	BestOf.inl
	compare.inl
	discrete.inl
	Extents.inl
	ExtentsIterator.inl
	grid.inl
	IndexIterator.inl
	info.inl
	io.inl
	iter.inl
	Jump.inl
	Latice.inl
	MinMax.inl
	ops.inl
	QuantumFrac.inl
	quantum.inl
	random.inl
	Range.inl
	Region.inl
	RowCol.inl
	SpotX.inl
	SubExtents.inl
	validity.inl

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

