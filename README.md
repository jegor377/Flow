# Flow (IN DEVELOP :/)
Fatally Lazy On Wednesday - SDL2 based C++ game engine working in 3D space but rendering in fake "isometric" 2d graphics. Engine is standalone header file (.hpp) for C++.

## Compiling
You don't need actually to compile this code. **Engine is standalone header file (.hpp) so you can just grab it from src/flow.hpp and include it in your project.**

But if you really want to work on this code then you need to know that the real sources of this engine is in src/flow directory. I recomend you to clone Wrapper CPP (https://github.com/jegor377/Wrapper-CPP), compile it and drop somewhere where you can use it easly (I've droped it into my system PATH). I use it to link all the headers into single header. It keeps things simple and nice.

After doing so, you can just use my recompile scripts in project directory. Recompile.bat for Windows and recompile.sh for Linux. It does all the compiling stuff by me. I don't use make or cmake because I'm too lazy to learn it but It's still easy and I don't need to change stuff in recompile scripts so often. I use MSYS in my windows machine and the windows' script is using its commands also (It's easy to change btw...) so I recomend you to install it while installing Min-GW, in Min-GW's package manager.

## Release date
Someday I'll finish this project. Someday...

## Used outside libraries
* https://www.libsdl.org/ (SDL2)
* https://github.com/martinmoene/lest (only lest_basic.hpp)
