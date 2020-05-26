#!/bin/bash

topDir=${HOME}
srcLibDir=${topDir}/repos/TPQZcam
buildLibDir=${topDir}/tmpBuild/tmpTPQZcam
instLibDir=${topDir}/tmpSys/tmplocal

echo "     topDir: ${topDir}"
echo "  srcLibDir: ${srcLibDir}"
echo "buildLibDir: ${buildLibDir}"
echo " instLibDir: ${instLibDir}"

echo

set -x

# ensure a clean build directory
if [ -d $buildLibDir ]; then
	echo rm -rf ${buildLibDir}
fi
mkdir ${buildLibDir}

echo "\n Generating Build System"
cmake \
	-DCMAKE_INSTALL_PREFIX=${instLibDir} \
	-B${buildLibDir} \
	-H${srcLibDir} \
	;

echo "\n Building with native system"
cmake \
	--build ${buildLibDir} \
	--config Release \
	--clean-first \
	-- -j `nproc` \
	;

echo "\n Installing"
cmake \
	--build ${buildLibDir} \
	--config Release \
	--target install \
	;

tree ${instLibDir}

echo "\n Running Tests"
cmake \
	--build ${buildLibDir} \
	--target test \
	;

