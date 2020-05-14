

# Build dox as option with default enable
option(BUILD_DOC "Build API documentation" ON)

# Use doxygen utility to generate documentation
find_package(Doxygen)
if (DOXYGEN_FOUND)

	# configure doxygen project specifications
	set(DoxyIn ${CMAKE_CURRENT_SOURCE_DIR}/../doc/Doxyfile.in)
	set(DoxyOut ${CMAKE_CURRENT_BINARY_DIR}/../doc/Doxyfile)

	message("####")
	message("#### DoxyIn: " ${DoxyIn})
	message("#### DoxyOut: " ${DoxyOut})
	message("#### CMAKE_BINARY_DIR: " ${CMAKE_BINARY_DIR})
	message("####")
	message("#### COMMAND: " "${DOXYGEN_EXECUTABLE} ${DoxyOut}")

	configure_file(${DoxyIn} ${DoxyOut} @ONLY)

	# command to invoke doxygen build
	add_custom_target(
		doc_doxygen ALL
		COMMAND ${DOXYGEN_EXECUTABLE} ${DoxyOut}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Generating API documentation"
		VERBATIM
		)


else (DOXYGEN_FOUND)

	message("Doxygen tool required for building library API documentation")

endif (DOXYGEN_FOUND)

