#pragma once

#include <deque>
#include <vector>
#include <string>
#include <cstring>
#include <exception>
#include <algorithm>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Wrapper CPP imports:
//physical metrics
@import point;
@import vector;
@import size;
@import rect;
//sprite
@import sprite;
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
@import entityfind_err;
@import spritefind_err;
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

		bool is_fixable;
	public:
		ScreenMode scr_mode;
		bool is_running = true;
		Uint64 last_update_time;

		Flow(bool is_fixable=true) {
			this->is_fixable = is_fixable;
			this->scr_mode = WINDOW;
			this->last_update_time = SDL_GetPerformanceCounter();
		}

		~Flow() {
			SDL_DestroyRenderer(this->canvas);
			SDL_DestroyWindow(this->window);
		}

		void create_window(const std::string& w_name = "Sample", bool use_vsync=true, Point2 pos=WINDOW_CENTER, Size2 size=Size2(640, 480), ScreenMode scr_mode = WINDOW) {
			this->scr_mode = scr_mode;
			this->initialize_window(w_name, pos, size);
			this->initialize_canvas(use_vsync);
		}

		// entity methods
		void add_entity(std::shared_ptr<Entity> entity) {
			entity_collector.add(entity);
		}

		void remove_entity_by_name(char* name) {
			entity_collector.remove_by_name(name);
		}

		void remove_entities_by_group(char* group) {
			entity_collector.remove_by_group(group);
		}

		EntityPtr get_entity_by_name(char* name) {
			return entity_collector.get_by_name(name);
		}

		EntityMap get_entities_by_group(char* group) {
			return entity_collector.get_by_group(group);
		}

		// sprite methods
		void add_sprite(const std::string& name, const std::string& path) {
			sprite_collector.add(this->canvas, name, path);
		}

		void remove_sprite(const std::string& name) {
			sprite_collector.remove(name);
		}

		SpritePtr get_sprite(const std::string& name) {
			return sprite_collector.get(name);
		}

		// game stuff
		void handle_events() {
			;
		}

		void update() {
			const Uint64 ONE_SEC_IN_MS = 1000;
			auto update_time_now = SDL_GetPerformanceCounter();
			double delta_time = (double)((update_time_now - this->last_update_time)*ONE_SEC_IN_MS) / (double)SDL_GetPerformanceFrequency();
			this->last_update_time = update_time_now;
			for(auto entity : this->entity_collector.entities) {
				entity->update(delta_time);
			}
		}

		void handle_collisions() {
			;
		}

		void render() {
			;
		}

		void game_loop() {
			while(this->is_running) {
				SDL_RenderClear(this->canvas);
				this->handle_events();
				this->update();
				this->render();
				SDL_RenderPresent(this->canvas);
			}
		}

	private:
		//initializing methods.
		void initialize_window(const std::string& w_name, Point2& pos, Size2& size) {
			this->window = SDL_CreateWindow(w_name.c_str(), pos.x, pos.y, size.w, size.h, this->scr_mode);
			if(this->window == NULL) {
				throw exception::Window("Cannot to create window", SDL_GetError());
			}
		}

		void initialize_canvas(bool use_vsync) {
			auto renderer_flags = use_vsync ? SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC : SDL_RENDERER_ACCELERATED;
			this->canvas = SDL_CreateRenderer(this->window, -1, renderer_flags);
			if(this->canvas == NULL) {
				const char* error_msg = SDL_GetError();
				// try to fix a problem
				if(!this->fix_create_canvas(error_msg)) {
					throw exception::Window("Cannot to create canvas (renderer)", error_msg);
				}
			}
		}

		//fix methods. Return value says if the problem was fixed.
		bool fix_create_canvas(const char* error_msg) {
			if(this->is_fixable) {
				this->canvas = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);
				if(this->canvas != NULL) {
					log::sdl_fix_warn("SDL_CreateRenderer", "Creating renderer as software fallback (SDL_RENDERER_SOFTWARE)", error_msg);
					return true;
				}
			}
			return false;
		}
	};

	void init(int sdl_support_flags=DEFAULT_INIT_FLAGS, int img_init_flags=DEFAULT_IMG_INIT_FLAGS, bool is_fixable=true) {
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

//special entities
@import game_entity;