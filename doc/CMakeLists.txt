
# Build dox as option with default enable
option(BUILD_DOC "Build API documentation" ON)

# Use doxygen utility to generate documentation
find_package(Doxygen)
if (DOXYGEN_FOUND)

	# check into cmake command
	# doxygen_add_docs(...)

	# configure doxygen project specifications
	set(DoxyIn ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
	set(DoxyOut ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
	configure_file(${DoxyIn} ${DoxyOut} @ONLY)

	# command to invoke doxygen build
	add_custom_target(
		docs ALL
		COMMAND ${DOXYGEN_EXECUTABLE} ${DoxyOut}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		COMMENT "Generating API documentation"
		VERBATIM
		)

	install(
		DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html
		DESTINATION
			${CMAKE_INSTALL_DOCDIR}/${local_LIBTARGET}
		)

else (DOXYGEN_FOUND)

	message("Doxygen tool required for building library API documentation")

endif (DOXYGEN_FOUND)

