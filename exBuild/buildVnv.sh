echo "*** Implement for General Case ***"
exit

workDir=/repos/TPQZcam
instDir=${workDir}/tmpLocalInstall
vnvDir=${workDir}/vnv
buildDir=${workDir}/tmpVnv

if ! cd ${vnvDir} ; then
	echo "cd Failure to ${vnvDir}"
else
	# cleanup vnv application build directory
	rm -rf ${buildDir}
	mkdir ${buildDir}

	# build vnv application
	cd ${buildDir}
	cmake \
		-DCMAKE_PREFIX_PATH=${instDir}/ \
		${vnvDir} \
		&& cmake --build . \
		;

	if \
		./testBuild;
	then
		echo "Success"
	else
		echo "FAILED build"
	fi

fi

