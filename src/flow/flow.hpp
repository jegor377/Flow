#pragma once

#include <SDL2/SDL.h>
#include "./logger/logger.hpp"
#include "./data/physical_metrics.hpp"
#include "./exceptions/init.hpp"
#include "./exceptions/window.hpp"

namespace flow {
	const Point2 WINDOW_CENTER = new_point2(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	const int DEFAULT_INIT_FLAGS = SDL_INIT_VIDEO|SDL_INIT_AUDIO;

	enum ScreenMode {
		FULLSCREEN = SDL_WINDOW_FULLSCREEN,
		WINDOW = SDL_WINDOW_OPENGL
	};

	struct Flow {
		bool is_debugging;
		ScreenMode scr_mode;
		SDL_Window* window;
		SDL_Renderer* canvas;
	};

	Flow* engine(bool is_debugging=false);
	void create_window(Flow* engine, const char* w_name = "sample", Point2 pos=WINDOW_CENTER, Size2 size=new_size2(640, 480), ScreenMode scr_mode = WINDOW) throw(exception::Window);
	void destroy_engine(Flow* engine);

	void init(int sdl_support_flags=DEFAULT_INIT_FLAGS) throw(exception::Init);
	void quit();
}