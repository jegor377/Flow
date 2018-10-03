#!/bin/bash
bin='bin/bin'

compile_cpp=$(find ./ -type f -name "*.cpp" | xargs)
compile_hpp=$(find ./ -type f -name "*.hpp" | xargs)

remove_o=$(find ./ -type f -name "*.o" | xargs)
remove_gch=$(find ./ -type f -name "*.gch" | xargs)

if [ -z "$1" ]; then
	g++ -c $compile_cpp $compile_hpp -std=c++11
	if [ $? -eq 0 ]; then
		compile_o=$(find ./ -type f -name "*.o" | xargs)
		g++ -o ./$bin $compile_o -lSDL2main -lSDL2
	fi
else
	if [ "$1" = "-c" ]; then
		rm $remove_o $remove_gch
	elif [ "$1" = "-cx" ]; then
		rm $remove_o $remove_gch $bin
	else
		echo ./recompile [-c]
		echo \n
		echo Script for recompiling and cleaning the project.
		echo \n
		echo When runned as recompile without any argument, script just recompiles the project.
		echo \n
		echo -c 		Cleans compile files without executable.
		echo -cx 		Cleans compile files with executable.
	fi
fi
