#

set(local_NM cam)
set(local_PREFIX ${local_LIBTARGET}_${local_NM})

set(${local_PREFIX}_SOURCES

	Camera.cpp
	fit.cpp
	InnerVertex.cpp
	io.cpp
	# Loader.cpp
	PinHole.cpp
	ViewPyramid.cpp
	xref.cpp

	)

set(${local_PREFIX}_INCLUDES

	Camera.h
	cam.h
	fit.h
	InnerVertex.h
	io.h
	# Loader.h
	PinHole.h
	SpotMea.h
	ViewPyramid.h
	XRefBase.h
	XRefDists.h
	xref.h
	XRefPoints.h
	XRefRays.h
	XRefRowCols.h
	XRefSpots.h

	Camera.inl
	InnerVertex.inl
	PinHole.inl
	XRefBase.inl

	)

include(../cmakeLibs.cmake)

