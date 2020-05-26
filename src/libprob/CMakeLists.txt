#

set(local_NM prob)
set(local_PREFIX ${local_LIBTARGET}_${local_NM})

set(${local_PREFIX}_SOURCES

	CdfForward.cpp
	CdfInverse.cpp
	Frac9.cpp
	Gauss.cpp
	Histogram.cpp
	pdf.cpp
	Remapper.cpp
	SampleEntropy.cpp
	SampleGen.cpp
	SampleStats.cpp
	Stats.cpp

	)

set(${local_PREFIX}_INCLUDES

	CdfForward.h
	CdfInverse.h
	distro.h
	Frac9.h
	Gauss.h
	Histogram.h
	histo.h
	io.h
	mean.h
	median.h
	pdf.h
	prob.h
	Remapper.h
	SampleEntropy.h
	SampleGen.h
	SampleStats.h
	Stats.h

	CdfForward.inl
	CdfInverse.inl
	distro.inl
	Frac9.inl
	Histogram.inl
	histo.inl
	io.inl
	mean.inl
	median.inl
	pdf.inl
	Remapper.inl
	SampleEntropy.inl
	SampleGen.inl
	SampleStats.inl
	Stats.inl

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


