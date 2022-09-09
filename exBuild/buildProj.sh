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
	-DCMAKE_INSTALL_MESSAGE=NEVER \
	-DBUILD_SHARED_LIBS=NO \
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

tree -d ${instLibDir}

echo "\n Running Tests"
cmake \
	--build ${buildLibDir} \
	--target test \
	;


echo "\n Making Package"
cmake \
	--build ${buildLibDir} \
	--target package \
	;


echo "\n Package Info"
ls -l ${buildLibDir}/*.deb
dpkg -f ${buildLibDir}/TPQZcam*.deb

