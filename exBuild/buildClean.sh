echo "*** Implement for General Case ***"
exit

workDir=/repos/TPQZcam
srcDir=${workDir}
buildDir=${workDir}/tmpBuild
instDir=${workDir}/tmpLocalInstall

if ! cd ${workDir}; then
	echo "cd Failure to workDir = ${workDir}"
else
	rm -rf ${buildDir} ${instDir}
fi

