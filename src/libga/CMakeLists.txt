#

set(local_NM ga)
set(local_PREFIX ${local_LIBTARGET}_${local_NM})

set(${local_PREFIX}_SOURCES

	Aligner.cpp
	Conform.cpp
	constructs.cpp
	groups.cpp
	io.cpp
	Pose.cpp
	quantities.cpp
	Rigid.cpp
	Spin1d.cpp
	spin.cpp

	)

set(${local_PREFIX}_INCLUDES

	Aligner.h
	comparisons.h
	Conform.h
	constructs.h
	derivative.h
	functions.h
	ga.h
	groups.h
	io.h
	multivector.h
	operators.h
	Pose.h
	quantities.h
	Rigid.h
	Spin1d.h
	spin.h

	Aligner.inl
	comparisons.inl
	Conform.inl
	constructs.inl
	derivative.inl
	functions.inl
	ga.inl
	operators.inl
	Pose.inl
	quantities.inl
	Rigid.inl

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


