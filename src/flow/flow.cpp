#include "flow.hpp"

#include <string>

namespace flow {
	Flow::Flow(bool is_debugging, bool is_fixable) {
		this->is_debugging = is_debugging;
		this->is_fixable = is_fixable;
		this->scr_mode = WINDOW;
	}

	void Flow::create_window(const char* w_name, Point2 pos, Size2 size, ScreenMode scr_mode) throw(exception::Window) {
		this->scr_mode = scr_mode;
		this->window = SDL_CreateWindow(w_name, pos.x, pos.y, size.w, size.h, this->scr_mode);
		if(this->window == NULL) {
			throw exception::Window(this->is_debugging, "Could not create window", SDL_GetError());
		}
		this->canvas = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
		if(this->canvas == NULL) {
			const char* error_msg = SDL_GetError();
			// try to fix a problem
			this->canvas = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);
			if(this->canvas != NULL) {
				log::sdl_fix_warn("SDL_CreateRenderer", "Creating renderer as software fallback (SDL_RENDERER_SOFTWARE)", error_msg);
				return;
			}
			throw exception::Window(this->is_debugging, "Could not create canvas (renderer)", error_msg);
		}
	}

	Flow::~Flow() {
		SDL_DestroyWindow(this->window);
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