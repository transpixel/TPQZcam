#

set(local_NM geo)
set(local_PREFIX ${local_LIBTARGET}_${local_NM})

set(${local_PREFIX}_SOURCES

	cube.cpp
	intersect.cpp
	io.cpp
	LineSeg.cpp
	mesh.cpp
	Plane.cpp
	ProbRay.cpp
	Ray.cpp
	si.cpp
	Triangle.cpp
	VertGangle.cpp
	Wedge.cpp

	)

set(${local_PREFIX}_INCLUDES

	cube.h
	geo.h
	intersect.h
	io.h
	LineSeg.h
	mesh.h
	Plane.h
	ProbRay.h
	Ray.h
	si.h
	sphere.h
	stats.h
	Triangle.h
	Tube.h
	VertGangle.h
	Wedge.h
	xform.h

	cube.inl
	LineSeg.inl
	mesh.inl
	ProbRay.inl
	Ray.inl
	si.inl
	sphere.inl
	stats.inl
	VertGangle.inl
	Wedge.inl
	xform.inl

	)

include(../cmakeLibs.cmake)

