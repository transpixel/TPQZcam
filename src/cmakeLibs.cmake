#


set(local_TARGET ${local_PREFIX})

add_library(${local_TARGET} STATIC ${${local_PREFIX}_SOURCES})
target_sources(${local_TARGET} PUBLIC ${${local_PREFIX}_INCLUDES})
target_include_directories(${local_TARGET} PUBLIC ../)

target_compile_features(${local_TARGET} PRIVATE cxx_std_11)

install(FILES ${${local_PREFIX}_INCLUDES} DESTINATION include/litetpqz)
install(TARGETS ${local_TARGET} ARCHIVE DESTINATION lib)

