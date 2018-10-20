@echo off
:: Script created by Igor Santarek MIT 2018. Works only with cygwin or msys. Can be easly converted to pure batch script.

set bin_dir=./bin
set binary_name=bin

set main="./src/sample game/main.cpp"
set main_o=main.o
set main_remove= 

set lib_src=./src/flow

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
if [%1] == [-t] (
	goto :c_tests
)
if [%1] == [-ho] (
	goto :c_header_only
)

echo recompile [-c] [-cx]
echo.
echo Script for recompiling and cleaning the project.
echo.
echo When runned without any argument, script just recompiles the project.
echo.
echo -c 		Cleans compile files without executable.
echo -cx 		Cleans compile files with executable.
echo -t 		Creates unit tests compiled executable and runs it.
echo -ho 		Creates only header in src directory.
exit /b

:recompile
wcpp %lib_src% flow >nul
cp flow.hpp "src/sample game"
mv flow.hpp src
g++ -c %compiler% -std=c++11
if %errorlevel% EQU 0 (
	call :create_bin_dir
	g++ -o ./%bin_dir%/%binary_name% %linker% -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
)
exit /b

:clean
rm %remove% %linker%
exit /b

:cleanx
call :clean
rm ./%bin_dir%/%binary_name%.exe
exit /b

:c_tests
set test_binary_name=tests
set test_compiler="./src/tests/t_main.cpp"
set test_linker="t_main.o"

wcpp %lib_src% flow >nul
cp flow.hpp "src/tests"
mv flow.hpp src
wcpp ./src/tests/cases test_specifications >nul
mv cases.hpp src/tests/test_cases.hpp
g++ -c %test_compiler% -std=c++11
if %errorlevel% EQU 0 (
	call :create_bin_dir
	g++ -o ./%bin_dir%/%test_binary_name% %test_linker% -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer
	.\bin\%test_binary_name%
)
rm %test_linker%
exit /b

:c_header_only
wcpp %lib_src% flow >nul
mv flow.hpp src
exit /b

:create_bin_dir
if NOT EXIST %bin_dir% mkdir %bin_dir%
exit /b