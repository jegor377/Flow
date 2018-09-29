#include "flow.hpp"

#include <string>

namespace flow {
	Flow* engine(bool is_debugging) {
		Flow* result = new Flow;
		result->is_debugging = is_debugging;
		result->scr_mode = WINDOW;
		return result;
	}

	void create_window(Flow* engine, const char* w_name, Point2 pos, Size2 size, ScreenMode scr_mode) throw(exception::Window) {
		engine->scr_mode = scr_mode;
		engine->window = SDL_CreateWindow(w_name, pos.x, pos.y, size.w, size.h, engine->scr_mode);
		if(engine->window == NULL) {
			throw exception::Window(engine->is_debugging, "Could not create window", SDL_GetError());
		}
		engine->canvas = SDL_CreateRenderer(engine->window, -1, SDL_RENDERER_ACCELERATED);
		if(engine->canvas == NULL) {
			const char* error_msg = SDL_GetError();
			// try to fix a problem
			engine->canvas = SDL_CreateRenderer(engine->window, -1, SDL_RENDERER_SOFTWARE);
			if(engine->canvas != NULL) {
				log::sdl_fix_warn("SDL_CreateRenderer", "Creating renderer as software fallback (SDL_RENDERER_SOFTWARE)", error_msg);
				return;
			}
			throw exception::Window(engine->is_debugging, "Could not create canvas (renderer)", error_msg);
		}
	}

	void destroy_engine(Flow* engine) {

		SDL_DestroyWindow(engine->window);
	}

	void init(int sdl_support_flags) throw(exception::Init) {
		if(SDL_Init(sdl_support_flags) < 0) {
			const char* error_msg = SDL_GetError();
			// try to fix a problem
			if(SDL_Init(DEFAULT_INIT_FLAGS) >= 0) {
				log::sdl_fix_warn("SDL_Init", "Initing SDL2 with default flags (SDL_INIT_VIDEO|SDL_INIT_AUDIO)", error_msg);
				return;
			}
			throw exception::Init(error_msg);
		}
	}

	void quit() {
		SDL_Quit();
	}
}