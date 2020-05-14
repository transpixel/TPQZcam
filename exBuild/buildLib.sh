
workDir=/repos/litetpqz
srcDir=${workDir}/src
buildDir=${workDir}/tmpBuild
instDir=${workDir}/tmpLocalInstall

if ! cd ${workDir}; then
	echo "cd Failure to workDir = ${workDir}"
else
	rm -rf ${buildDir} ${instDir}
	mkdir ${buildDir} ${instDir}

	cd ${buildDir}
	cmake -DCMAKE_INSTALL_PREFIX=${instDir} ${srcDir}

	cmake --build . -j 16 --clean-first
	cmake --build . --target install
fi

