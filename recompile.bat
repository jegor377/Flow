@echo off

set bin_dir=./bin
set binary_name=bin

set main=./src/main.cpp
set main_o=main.o
set main_remove= 

set lib_src=./src/flow

set compiler=%main%
set linker=%main_o%
set remove=%main_remove%

::compiler
::flow
call :add_compile_files flow
::flow/data
call :add_compile_files data/physical_metrics
call :add_compile_files data/point
call :add_compile_files data/size
call :add_compile_files data/vector
call :add_compile_files data/rect
::flow/exceptions
call :add_compile_files exceptions/init
call :add_compile_files exceptions/window
::flow/logger
call :add_compile_files logger/logger

::linker
::flow
call :add_linker_files flow
::flow/data
call :add_linker_files physical_metrics
call :add_linker_files point
call :add_linker_files size
call :add_linker_files vector
call :add_linker_files rect
::flow/exceptions
call :add_linker_files init
call :add_linker_files window
::flow/logger
call :add_linker_files logger

::remove
::flow
call :add_remove_files flow
::flow/data
call :add_remove_files data/physical_metrics
call :add_remove_files data/point
call :add_remove_files data/size
call :add_remove_files data/vector
call :add_remove_files data/rect
::flow/exceptions
call :add_remove_files exceptions/init
call :add_remove_files exceptions/window
::flow/logger
call :add_remove_files logger/logger

if [%1] == [] (
	goto :recompile
)
if [%1] == [-c] (
	goto :clean
)
if [%1] == [-cx] (
	goto :cleanx
)

echo recompile [-c]
echo.
echo Script for recompiling and cleaning the project.
echo.
echo When runned as recompile without any argument, script just recompiles the project.
echo.
echo -c 		Cleans compile files without executable.
echo -cx 		Cleans compile files with executable.
exit /b

:recompile
g++ -c %compiler% -std=c++11
if %errorlevel% EQU 0 (
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

:add_compile_files
set compiler=%compiler% %lib_src%/%1.hpp %lib_src%/%1.cpp
exit /b

:add_linker_files
set linker=%linker% %1.o
exit /b

:add_remove_files
set remove=%remove% %lib_src%/%1.hpp.gch
exit /b