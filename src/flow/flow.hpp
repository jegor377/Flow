#pragma once

#include <string>
#include <SDL2/SDL.h>
#include "./logger/logger.hpp"
#include "./data/physical_metrics.hpp"
#include "./exceptions/init.hpp"
#include "./exceptions/window.hpp"
#include "./entities/entity.hpp"
#include "./types/types.hpp"

namespace flow {
	const Point2 WINDOW_CENTER = new_point2(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	const int DEFAULT_INIT_FLAGS = SDL_INIT_VIDEO|SDL_INIT_AUDIO;

	enum ScreenMode {
		FULLSCREEN = SDL_WINDOW_FULLSCREEN,
		WINDOW = SDL_WINDOW_OPENGL
	};

	class Flow {
		Window window;
		Renderer canvas;
		Entities enitites;
	public:
		bool is_debugging;
		bool is_fixable;
		ScreenMode scr_mode;

		Flow(bool is_debugging=false, bool is_fixable=true);
		~Flow();

		void create_window(const char* w_name = "Sample", Point2 pos=WINDOW_CENTER, Size2 size=new_size2(640, 480), ScreenMode scr_mode = WINDOW) throw(exception::Window);
		void add_entity(Entity* entity);

	private:
		//initializing methods.
		void initialize_window(const char* w_name, Point2& pos, Size2& size) throw(exception::Window);
		void initialize_canvas() throw(exception::Window);

		//fix methods. Return value says if the problem was fixed.
		bool fix_create_canvas(const char* error_msg);
	};

	void init(int sdl_support_flags=DEFAULT_INIT_FLAGS, bool is_fixable=true) throw(exception::Init);
	void quit();
}