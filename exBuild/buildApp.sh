
vnvDir=/repos/camtpqz/vnv
instDir=/repos/camtpqz/tmpLocalInstall

if ! cd ${vnvDir} ; then
	echo "cd Failure to ${vnvDir}"
else

	AppName=testBuild
	# set -x
	if \
		g++ -o ${AppName} ${AppName}.cpp \
		-I${instDir}/include/TPQZcam \
		-L${instDir}/lib/ \
		-lTPQZcam \
		;
	then
		./${AppName}
	else
		echo "FAILED build"
	fi

fi

