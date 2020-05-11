#

set(local_NM sys)
set(local_PREFIX litetpqz_${local_NM})

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

include(../cmakeLibs.cmake)

