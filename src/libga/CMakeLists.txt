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

include(../cmakeLibs.cmake)

