
vnvDir=/repos/litetpqz/vnv
instDir=/repos/litetpqz/tmpLocalInstall

if ! cd ${vnvDir} ; then
	echo "cd Failure to ${vnvDir}"
else

	AppName=testBuild
	# set -x
	if \
		g++ -o ${AppName} ${AppName}.cpp \
		-I${instDir}/include/LiteTPQZ \
		-L${instDir}/lib/ \
		-lLiteTPQZ \
		;
	then
		./${AppName}
	else
		echo "FAILED build"
	fi

fi

