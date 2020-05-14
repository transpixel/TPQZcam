
# LiteTPQZ

Several library modules extracted from
 * https://github.com/transpixel/tpqz.git tag: tpqz_v00r17p00


## Install Structure

The install tree structure is

 * [CMAKE_INSTALL_PREFIX]
 * * include/
 * * * LiteTPQZ/
 * * * * libcam/
 * * * * libdat/
 * * * * libga/
 * * * * libgeo/
 * * * * libio/
 * * * * libmath/
 * * * * libprob/
 * * * * libsys/
 * * lib/
 * * * libLiteTPQZ.a/

## Example Use of Installed Library

Applications can be compiled and linked with command similar to:

 * g++ -o ${AppName} ${AppName}.cpp
	-I${instDir}/include/LiteTPQZ
	-L${instDir}/lib/
	-lLiteTPQZ

## Hardcoded Command Examples

There are several hardcoded scripts in exBuild directory illustrate build
and install of LiteTPQZ (c++ headers and static library).

 * exBuild/buildLib.sh -- build/install LiteTPQZ
 * exBuild/buildApp.sh -- build/run ./vnv/testBuild program linked to lib
 * exBuild/buildClean.sh -- remove local build/install dir trees



