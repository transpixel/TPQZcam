#

set(local_PREFIX litetpqz_math) # keep cmake target names unique

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

include(../cmakeLibs.cmake)

