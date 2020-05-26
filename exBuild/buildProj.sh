
workDir=${HOME}/repos/TPQZcam
srcDir=${workDir}
buildDir=${workDir}/tmpBuild
instDir=${workDir}/tmpLocalInstall

echo " workDir: ${workDir}"
echo "  srcDir: ${srcDir}"
echo "buildDir: ${buildDir}"
echo " instDir: ${instDir}"

echo

set -x
if ! cd ${workDir}; then
	echo "cd Failure to workDir = ${workDir}"
else
	rm -rf ${buildDir} ${instDir}
	mkdir ${buildDir} ${instDir}

	cd ${buildDir}
	cmake \
		-DCMAKE_INSTALL_PREFIX=${instDir} \
		${srcDir} \
		;

	cmake \
		--build ${buildDir} \
		--config Release \
		--clean-first \
		-- -j 16 \
		;

	cmake --build . --target install
	tree ${instDir}

	ctest
fi

