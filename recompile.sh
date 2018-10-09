#!/bin/bash
bin='bin/bin'

lib_src='./src/flow'

compiler='./src/main.cpp'
linker='./main.o'

create_bin_dir() {
	if [ ! -d "bin" ]; then
		mkdir bin
	fi
}

if [ -z "$1" ]; then
	wcpp $lib_src flow >/dev/null
	mv flow.hpp src
	g++ -c $compiler -std=c++11
	if [ $? -eq 0 ]; then
		create_bin_dir
		g++ -o ./$bin $linker -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
	fi
else
	if [ "$1" = "-c" ]; then
		rm $linker
	elif [ "$1" = "-cx" ]; then
		rm $linker $bin
	else
		echo "recompile [-c] [-cx]"
		echo
		echo "Script for recompiling and cleaning the project."
		echo
		echo "When runned as recompile without any argument, script just recompiles the project."
		echo
		echo "-c 		Cleans compile files without executable."
		echo "-cx 		Cleans compile files with executable."
	fi
fi
