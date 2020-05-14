
workDir=/repos/camtpqz
srcDir=${workDir}/src
buildDir=${workDir}/tmpBuild
instDir=${workDir}/tmpLocalInstall

if ! cd ${workDir}; then
	echo "cd Failure to workDir = ${workDir}"
else
	rm -rf ${buildDir} ${instDir}
fi

