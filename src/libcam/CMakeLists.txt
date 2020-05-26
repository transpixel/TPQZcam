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


