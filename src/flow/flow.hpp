#pragma once

#include <vector>
#include <string>
#include <cstring>
#include <exception>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Wrapper CPP imports:
//physical metrics
@import point;
@import vector;
@import size;
@import rect;
//entities
@import entity;
//types
@import types;
//logger
@import logger;
//exceptions
@import init_err;
@import window_err;
@import spriteload_err;
//collectors
@import entity_collector;
@import sprite_collector;

namespace flow {
	const Point2 WINDOW_CENTER(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	const int DEFAULT_INIT_FLAGS = SDL_INIT_VIDEO|SDL_INIT_AUDIO;
	const int DEFAULT_IMG_INIT_FLAGS = IMG_INIT_PNG|IMG_INIT_JPG;

	enum ScreenMode {
		FULLSCREEN = SDL_WINDOW_FULLSCREEN,
		WINDOW = SDL_WINDOW_OPENGL
	};

	class Flow {
		Window window;
		Renderer canvas;
		EntityCollector entity_collector;
		SpriteCollector sprite_collector;

	public:
		bool is_debugging;
		bool is_fixable;
		ScreenMode scr_mode;

		Flow(bool is_debugging=false, bool is_fixable=true) {
			this->is_debugging = is_debugging;
			this->is_fixable = is_fixable;
			this->scr_mode = WINDOW;
		}

		~Flow() {
			SDL_DestroyRenderer(this->canvas);
			SDL_DestroyWindow(this->window);
		}

		void create_window(const char* w_name = "Sample", Point2 pos=WINDOW_CENTER, Size2 size=Size2(640, 480), ScreenMode scr_mode = WINDOW) {// throw(exception::Window)
			this->scr_mode = scr_mode;
			this->initialize_window(w_name, pos, size);
			this->initialize_canvas();
		}

		void add_entity(Entity* entity) {
			entity_collector.add(entity);
		}

		void add_sprite(const char* name, const char* path) {
			sprite_collector.add(this->canvas, name, path);
		}

		void game_loop() {
			;
		}

	private:
		//initializing methods.
		void initialize_window(const char* w_name, Point2& pos, Size2& size) {// throw(exception::Window)
			this->window = SDL_CreateWindow(w_name, pos.x, pos.y, size.w, size.h, this->scr_mode);
			if(this->window == NULL) {
				throw exception::Window(this->is_debugging, "Could not create window", SDL_GetError());
			}
		}

		void initialize_canvas() {//throw(exception::Window)
			this->canvas = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if(this->canvas == NULL) {
				const char* error_msg = SDL_GetError();
				// try to fix a problem
				if(!this->fix_create_canvas(error_msg)) {
					throw exception::Window(this->is_debugging, "Could not create canvas (renderer)", error_msg);
				}
			}
		}

		//fix methods. Return value says if the problem was fixed.
		bool fix_create_canvas(const char* error_msg) {
			this->canvas = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);
			if(this->canvas != NULL) {
				log::sdl_fix_warn("SDL_CreateRenderer", "Creating renderer as software fallback (SDL_RENDERER_SOFTWARE)", error_msg);
				return true;
			}
			return false;
		}
	};

	void init(int sdl_support_flags=DEFAULT_INIT_FLAGS, int img_init_flags=DEFAULT_IMG_INIT_FLAGS, bool is_fixable=true) {// throw(exception::Init)
		// Initing SDL2
		if(SDL_Init(sdl_support_flags) < 0) {
			const char* error_msg = SDL_GetError();
			bool is_problem_fixed = false;
			// try to fix a problem. This fix is not in outer method because it's not in a class and it's not needed.
			if(is_fixable) {
				if(SDL_Init(DEFAULT_INIT_FLAGS) >= 0) {
					log::sdl_fix_warn("SDL_Init", "Initing SDL2 with default flags (SDL_INIT_VIDEO|SDL_INIT_AUDIO)", error_msg);
					is_problem_fixed = true;
				}
			}
			if(!is_problem_fixed) throw exception::Init(error_msg);
		}
		// Initing SDL2_image
		if(!(IMG_Init(img_init_flags) & img_init_flags)) {
			const char* error_msg = IMG_GetError();
			bool is_problem_fixed = false;
			// try to fix a problem by initing sdl2_image with default init flags.
			if(is_fixable) {
				if(IMG_Init(DEFAULT_IMG_INIT_FLAGS) & DEFAULT_IMG_INIT_FLAGS) {
					log::sdl_fix_warn("IMG_Init", "Initing SDL2_image with default flags (IMG_INIT_PNG|IMG_INIT_JPG)", error_msg);
					is_problem_fixed = true;
				}
			}
			if(!is_problem_fixed) throw exception::Init(error_msg);
		}
	}

	void quit() {
		IMG_Quit();
		SDL_Quit();
	}
}