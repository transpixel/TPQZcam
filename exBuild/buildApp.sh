echo "*** Implement for General Case ***"
exit

workDir=/repos/TPQZcam
vnvDir=${workDir}/vnv
instDir=${workDir}/tmpLocalInstall

if ! cd ${vnvDir} ; then
	echo "cd Failure to ${vnvDir}"
else

	AppName=testBuild
	set -x
	if \
		g++ -o ${AppName} ${AppName}.cpp \
		-I${instDir}/include/TPQZcam-0.1.0 \
		-L${instDir}/lib/ \
		-lTPQZcam-0.1.0 \
		;
	then
		./${AppName}
	else
		echo "FAILED build"
	fi

fi

