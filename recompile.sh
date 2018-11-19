#!/bin/bash
bin='bin/bin'

lib_src='./src/flow'

compiler='./src/sample game/main.cpp'
linker='./main.o'

create_bin_dir() {
	if [ ! -d "bin" ]; then
		mkdir bin
	fi
}

if [ -z "$1" ]; then
	wcpp $lib_src flow >/dev/null
	cp flow.hpp "src/sample game"
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
	elif [ "$1" = "-t" ]; then
		test_bin='bin\tests'
		test_compiler='./src/tests/t_main.cpp'
		test_linker='./t_main.o'

		wcpp $lib_src flow >/dev/null
		cp flow.hpp "src/tests"
		mv flow.hpp src
		wcpp ./src/tests/cases test_specifications >/dev/null
		mv cases.hpp src/tests/test_cases.hpp
		g++ -c $test_compiler -std=c++11
		if [ $? -eq 0 ]; then
			create_bin_dir
			g++ -o ./$test_bin $test_linker -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
			./$test_bin
		fi
		rm $test_linker
	elif [ "$1" = "-ho" ]; then
		wcpp $lib_src flow >/dev/null
		mv flow.hpp src
	else
		echo "recompile [-c] [-cx]"
		echo
		echo "Script for recompiling and cleaning the project."
		echo
		echo "When runned without any argument, script just recompiles the project."
		echo
		echo "-c 		Cleans compile files without executable."
		echo "-cx 		Cleans compile files with executable."
		echo "-t 		Creates unit tests compiled executable and runs it."
		echo "-ho 		Creates only header in src directory."
	fi
fi
