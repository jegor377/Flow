#pragma once

#include <vector>
#include <string>
#include <cstring>
#include <exception>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Wrapper CPP imports:
//physical metrics
namespace flow {
	struct Point2 {
		int x=0;
		int y=0;
	};

	struct Point : Point2 {
		int z=0;
	};

	Point2 new_point2(int x, int y) {
		Point result = {};
		result.x = x;
		result.y = y;
		return result;
	}

	Point new_point(int x, int y, int z) {
		Point result = {};
		result.x = x;
		result.y = y;
		result.z = z;
		return result;
	}
}
namespace flow {
	struct Vector : Point {};
}
namespace flow {
	struct Size2 {
		int w; // width
		int h; // height
	};

	struct Size {
		int w; // width
		int h; // height
		int l; // length
	};

	Size2 new_size2(int w, int h) {
		Size2 result = {};
		result.w = w;
		result.h = h;
		return result;
	}

	Size new_size(int w, int h, int l) {
		Size result = {};
		result.w = w;
		result.h = h;
		result.l = l;
		return result;
	}
}
namespace flow {
	struct Rect2 : Point2, Size2 {};

	struct Rect : Point, Size {};

	Rect2 new_rect2(int x, int y, int w, int h) {
		flow::Rect2 result = {};
		result.x = x;
		result.y = y;
		result.w = w;
		result.h = h;
		return result;
	}

	Rect new_rect(int x, int y, int z, int w, int h, int l) {
		flow::Rect result = {};
		result.x = x;
		result.y = y;
		result.z = z;
		result.w = w;
		result.h = h;
		result.l = l;
		return result;
	}

	bool is_colliding(Rect& src, Rect& dst) {
		return false;
	}

	bool is_colliding_pwr(Point& src, Rect& dst) {
		return true;
	}
}
//entities
namespace flow {
	class Entity {
	protected:
		Point pos;
		Size size;
		
		char* name;
		char* group;
	public:
		Entity() {}
	
		Entity(Point pos, Size size, char* name, char* group) {
			this->pos   = pos;
			this->size  = size;
			this->name  = name;
			this->group = group;
		}

		Entity(const Entity& copy_entity) {
			strcpy(this->name, copy_entity.name);
			strcpy(this->group, copy_entity.group);
		}
		
		virtual void update(double delta) = 0;
		virtual void event(SDL_Event* event) = 0;
		virtual void collision(Entity& body) = 0;
	};
}
//types
namespace flow {
	typedef SDL_Window* Window;
	typedef SDL_Renderer* Renderer;
	typedef std::vector<flow::Entity*> EntityList;
}
//logger
namespace flow {
	namespace log {
		void info(std::string msg) {
			SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
		}

		void warn(std::string msg) {
			SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
		}

		void error(std::string msg) {
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
		}

		void debug(std::string msg) {
			SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
		}

		// special functions
		// logs warn when sdl reported error and flow fixed it somehow.
		void sdl_fix_warn(std::string error_source, std::string fix_way, const char* sdl_error_msg) {
			std::string msg = error_source+" reported error (\""+std::string(sdl_error_msg)+"\"). It has been fixed. Fix way: "+fix_way+".";
			warn(msg);
		}

		// logs flow debug if is_debugging flag is set.
		void flow_debug(bool is_debugging, std::string msg) {
			if(is_debugging) {
				debug(msg);
			}
		}
	}
}
//exceptions
namespace flow {
	namespace exception {
		class Init: public std::exception {
			const char* sdl_err_msg;

		public:
			Init(const char* sdl_err_msg) {
				this->sdl_err_msg = sdl_err_msg;
			}

			const char* what() const throw() {
				return this->sdl_err_msg;
			}
		};
	}
}
namespace flow {
	namespace exception {
		class Window: public std::exception {
			const char* sdl_err_msg;

		public:
			Window(bool is_debugging, std::string err_msg, const char* sdl_err_msg) {
				this->sdl_err_msg = std::string(err_msg+". SDL2 error message: "+std::string(sdl_err_msg)+".").c_str();
				log::flow_debug(is_debugging, std::string(sdl_err_msg));
			}

			const char* what() const throw() {
				return this->sdl_err_msg;
			}
		};
	}
}
namespace flow {
	namespace exception {
		class SpriteLoad: public std::exception {
			char* err_msg;

		public:
			SpriteLoad(const char* name, const char* path, const char* sdl_err_msg) {
				char* err_msg = new char[strlen("Cannot to load sprite with name \"\" and path \"\". ")+strlen(name)+strlen(path)+strlen(sdl_err_msg)+1];
				const char* init_str = "Cannot to load sprite with name \"";
				strcpy(err_msg, init_str);
				strcat(err_msg, name);
				strcat(err_msg, "\" and path \"");
				strcat(err_msg, path);
				strcat(err_msg, "\". ");
				strcat(err_msg, sdl_err_msg);
				this->err_msg = err_msg;
			}

			~SpriteLoad() {
				delete err_msg;
			}

			const char* what() const throw() {
				return (const char*)(this->err_msg);
			}
		};
	}
}
//collectors
namespace flow {
	class EntityCollector {
		EntityList entities;
	public:
		
		void add(Entity* entity) {
			this->entities.push_back(entity);
		}

		void remove_by_name(char* name) {
			;
		}

		void remove_by_group(char* group) {
			;
		}

		// Returns first by name or raises an exception if no found.
		Entity* get_by_name(char* name) {
			;
		}

		EntityList get_by_group(char* group) {
			;
		}
	};
}
namespace flow {
	class Sprite {
		SDL_Texture* texture;
		const char* name;
		const char* path;

	public:
		Sprite(const char* name, const char* path) {
			this->texture = NULL;
			this->name = name;
			this->path = path;
		}

		~Sprite() {
			this->remove_sprite();
		}
	private:
		void remove_sprite() {
			if(this->texture != NULL) {
				SDL_DestroyTexture(this->texture);
				this->texture = NULL;
			}
		}
	public:
		friend class SpriteCollector;
		void load_sprite(Sprite* sprite);
		friend void draw(Sprite* sprite);
	};

	class SpriteCollector {
		std::vector<Sprite*> sprites;
		Renderer canvas;
	public:

		SpriteCollector(Renderer canvas) {
			this->canvas = canvas;
		}
		~SpriteCollector() {
			for(auto sprite : sprites) {
				delete sprite;
			}
		}

		void add(const char* name, const char* path) {
			auto sprite = new Sprite(name, path);
			this->sprites.push_back(sprite);
			this->load_sprite(sprite);
		}

		void remove(const char* name) {
			;
		}

		Sprite* get(const char* name) {
			;
		}
	private:
		void load_sprite(Sprite* sprite) {
			sprite->texture = IMG_LoadTexture(this->canvas, sprite->path);
			if(sprite->texture == NULL) throw exception::SpriteLoad(sprite->name, sprite->path, SDL_GetError());
		}
	};
}

namespace flow {
	const Point2 WINDOW_CENTER = new_point2(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
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
		SpriteCollector* sprite_collector;

	public:
		bool is_debugging;
		bool is_fixable;
		ScreenMode scr_mode;

		Flow(bool is_debugging=false, bool is_fixable=true) {
			this->is_debugging = is_debugging;
			this->is_fixable = is_fixable;
			this->scr_mode = WINDOW;

			this->sprite_collector = new SpriteCollector(this->canvas);
		}

		~Flow() {
			SDL_DestroyWindow(this->window);
			delete this->sprite_collector;
		}

		void create_window(const char* w_name = "Sample", Point2 pos=WINDOW_CENTER, Size2 size=new_size2(640, 480), ScreenMode scr_mode = WINDOW) {// throw(exception::Window)
			this->scr_mode = scr_mode;
			this->initialize_window(w_name, pos, size);
			this->initialize_canvas();
		}

		void add_entity(Entity* entity) {
			entity_collector.add(entity);
		}

		void add_sprite(const char* name, const char* path) {
			sprite_collector->add(name, path);
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
			this->canvas = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
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