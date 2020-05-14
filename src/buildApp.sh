
cd vnv/
# set -x

AppName=testBuild

if \
	g++ -o ${AppName} ${AppName}.cpp \
	-I /repos/litetpqz/src/tmpLocalInstall/include/LiteTPQZ \
	-L/repos/litetpqz/src/tmpLocalInstall/lib/ \
	-lLiteTPQZ \
	;
then
	./${AppName}
else
	echo "FAILED build"
fi

