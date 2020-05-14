
if ! cd /repos/litetpqz/src; then
	echo "cd Failure"
else
	rm -rf tmpBuild/ tmpLocalInstall/
	mkdir tmpBuild/ tmpLocalInstall/

	cd tmpBuild
	cmake -DCMAKE_INSTALL_PREFIX=../tmpLocalInstall/ ..

	cmake --build . -j 16 --clean-first
	cmake --build . --target install
fi

