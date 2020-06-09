#

foreach(oneUnitTest ${allUnitTests})

	set(unitTestTarget ${tst_NM}_${oneUnitTest})
	# message("oneUnitTest: " ${oneUnitTest})
	# message("unitTestTarget: " ${unitTestTarget})
	add_executable(${unitTestTarget} ${oneUnitTest}.cpp)
	target_compile_options(
		${unitTestTarget}
		PRIVATE
			$<$<CXX_COMPILER_ID:Clang>:${BUILD_FLAGS_FOR_CLANG}>
			$<$<CXX_COMPILER_ID:GNU>:${BUILD_FLAGS_FOR_GCC}>
			$<$<CXX_COMPILER_ID:MSVC>:${BUILD_FLAGS_FOR_VISUAL}>
		)

	target_include_directories(
		${unitTestTarget}
		PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../src
		PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} # local test code includes
		)

	target_link_libraries(
		${unitTestTarget}
		${local_LIBTARGET} Threads::Threads
		)

	add_test(
		${unitTestTarget} # cmake target
		${unitTestTarget} # command to run (no arguments for unit tests)
		)

endforeach(oneUnitTest)

