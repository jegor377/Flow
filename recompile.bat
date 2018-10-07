@echo off
:: Script created by Igor Santarek MIT 2018. Works only with cygwin or msys. Can be easly converted to pure batch script.

set bin_dir=./bin
set binary_name=bin

set main=./src/main.cpp
set main_o=main.o
set main_remove= 

set lib_src=./src/flow
set game_src=./src/sample

set compiler=%main%
set linker=%main_o%
set remove=%main_remove%

if [%1] == [] (
	goto :recompile
)
if [%1] == [-c] (
	goto :clean
)
if [%1] == [-cx] (
	goto :cleanx
)

echo recompile [-c] [-cx]
echo.
echo Script for recompiling and cleaning the project.
echo.
echo When runned as recompile without any argument, script just recompiles the project.
echo.
echo -c 		Cleans compile files without executable.
echo -cx 		Cleans compile files with executable.
exit /b

:recompile
wcpp %lib_src% flow
mv flow.hpp src
g++ -c %compiler% -std=c++11
if %errorlevel% EQU 0 (
	call :create_bin_dir
	g++ -o ./%bin_dir%/%binary_name% %linker% -lmingw32 -lSDL2main -lSDL2
)
exit /b

:clean
rm %remove% %linker%
exit /b

:cleanx
call :clean
rm ./%bin_dir%/%binary_name%.exe
exit /b

:create_bin_dir
if NOT EXIST %bin_dir% mkdir %bin_dir%
exit /b