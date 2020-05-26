#

set(local_NM sys)
set(local_PREFIX ${local_LIBTARGET}_${local_NM})

set(${local_PREFIX}_SOURCES

	jobCapacity.cpp
	jobFactory.cpp
	Timer.cpp
	Utilization.cpp

	)

set(${local_PREFIX}_INCLUDES

	JobBase.h
	jobCapacity.h
	jobFactory.h
	job.h
	jobNotification.h
	sys.h
	time.h
	Timer.h
	Utilization.h

	jobCapacity.inl
	jobFactory.inl
	jobNotification.inl
	time.inl
	Timer.inl
	Utilization.inl

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

