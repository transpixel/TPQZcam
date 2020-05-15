
# TPQZcam

Basic camera modeling and photogrammetry support via
several library component models extracted from:
 * https://github.com/transpixel/tpqz.git tag: tpqz_v00r17p00


## Install Structure

The install tree structure is

 * [CMAKE_INSTALL_PREFIX]
 	* include/
 		* libcam/
 		* libdat/
 		* libga/
 		* libgeo/
 		* libio/
 		* libmath/
 		* libprob/
 		* libsys/
 	* lib/
 		* libTPQZcam.a

## Example Use of Installed Library

Applications can be compiled and linked with command similar to:

 * g++ -o ${AppName} ${AppName}.cpp
	-I${InstDir}/include/TPQZcam
	-L${InstDir}/lib/
	-lTPQZcam

Where "InstDir" is the path to install location (e.g. CMAKE_INSTALL_PREFIX
above).

## Hardcoded Command Examples

There are several hardcoded scripts in exBuild directory illustrate build
and install of TPQZcam (c++ headers and static library).

 * exBuild/buildLib.sh -- build/install TPQZcam
 * exBuild/buildApp.sh -- build/run ./vnv/testBuild program linked to lib
 * exBuild/buildClean.sh -- remove local build/install dir trees



