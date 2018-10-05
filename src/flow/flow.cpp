#include "flow.hpp"

namespace flow {
	Flow::Flow(bool is_debugging, bool is_fixable) {
		this->is_debugging = is_debugging;
		this->is_fixable = is_fixable;
		this->scr_mode = WINDOW;
	}

	void Flow::create_window(const char* w_name, Point2 pos, Size2 size, ScreenMode scr_mode) throw(exception::Window) {
		this->scr_mode = scr_mode;
		this->initialize_window(w_name, pos, size);
		this->initialize_canvas();
	}

	void Flow::add_entity(Entity* entity) {
		;
	}

	Flow::~Flow() {
		SDL_DestroyWindow(this->window);
	}

	void init(int sdl_support_flags, bool is_fixable) throw(exception::Init) {
		if(SDL_Init(sdl_support_flags) < 0) {
			const char* error_msg = SDL_GetError();
			// try to fix a problem. This fix is not in outer method because it's not in a class and it's not needed.
			if(is_fixable) {
				if(SDL_Init(DEFAULT_INIT_FLAGS) >= 0) {
					log::sdl_fix_warn("SDL_Init", "Initing SDL2 with default flags (SDL_INIT_VIDEO|SDL_INIT_AUDIO)", error_msg);
					return;
				}
			}
			throw exception::Init(error_msg);
		}
	}

	void quit() {
		SDL_Quit();
	}

	// flow initialize methods.
	void Flow::initialize_window(const char* w_name, Point2& pos, Size2& size) throw(exception::Window) {
		this->window = SDL_CreateWindow(w_name, pos.x, pos.y, size.w, size.h, this->scr_mode);
		if(this->window == NULL) {
			throw exception::Window(this->is_debugging, "Could not create window", SDL_GetError());
		}
	}

	void Flow::initialize_canvas() throw(exception::Window) {
		this->canvas = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
		if(this->canvas == NULL) {
			const char* error_msg = SDL_GetError();
			// try to fix a problem
			if(!this->fix_create_canvas(error_msg)) {
				throw exception::Window(this->is_debugging, "Could not create canvas (renderer)", error_msg);
			}
		}
	}

	// flow fix methods.
	bool Flow::fix_create_canvas(const char* error_msg) {
		this->canvas = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);
		if(this->canvas != NULL) {
			log::sdl_fix_warn("SDL_CreateRenderer", "Creating renderer as software fallback (SDL_RENDERER_SOFTWARE)", error_msg);
			return true;
		}
		return false;
	}
}