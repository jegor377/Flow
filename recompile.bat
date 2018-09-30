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

::flow
call :add_flow_files flow
::flow/data
call :add_flow_files data physical_metrics
call :add_flow_files data point
call :add_flow_files data size
call :add_flow_files data vector
call :add_flow_files data rect
::flow/entites
call :add_flow_files entities entity
::flow/exceptions
call :add_flow_files exceptions init
call :add_flow_files exceptions window
::flow/logger
call :add_flow_files logger logger
::flow/types
call :add_flow_files types types

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

:: %1 = file path (folder name), %2 = file name
:add_flow_files
if [%2] NEQ [] (
	call :add_compile_files %1/%2
	call :add_linker_files %2
	call :add_remove_files %1/%2
)
if [%2] EQU [] (
	call :add_compile_files %1
	call :add_linker_files %1
	call :add_remove_files %1
)
exit /b