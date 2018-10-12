#pragma once

#include <vector>
#include <string>
#include <cstring>
#include <exception>
#include <algorithm>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Wrapper CPP imports:
//physical metrics
namespace flow {
	class Point2 {
	public:
		int x;
		int y;

		Point2(int x=0, int y=0) {
			this->x=x;
			this->y=y;
		}
	};

	class Point : public Point2 {
	public:
		int z=0;
		Point(int x=0, int y=0, int z=0) : Point2(x, y) {
			this->z = z;
		}
	};
}
namespace flow {
	class Vector : public Point {
		Vector(int x=0, int y=0, int z=0) : Point(x, y, z) {};
	};
}
namespace flow {
	class Size2 {
	public:
		int w; // width
		int h; // height
		Size2(int w=0, int h=0) {
			this->w=w;
			this->h=h;
		}
	};

	class Size : public Size2 {
	public:
		int l; // length

		Size(int w=0, int h=0, int l=0) : Size2(w, h) {
			this->l=l;
		}
	};
}
namespace flow {
	enum RectMode {
		SECTION = 0,
		FULL = 1
	};

	class Rect2 : public Point2, Size2 {
		SDL_Rect sdl_representation;
	public:
		RectMode mode;

		Rect2(int x=0, int y=0, int w=0, int h=0, RectMode mode=FULL) : Point2(x, y), Size2(w, h) {
			this->mode = mode;
		};

		SDL_Rect* get_sdl_rect() {
			if(this->mode == SECTION) {
				this->sdl_representation.x = this->x;
				this->sdl_representation.y = this->y;
				this->sdl_representation.w = this->w;
				this->sdl_representation.h = this->h;
				return &this->sdl_representation;
			}
			return NULL;
		}
	};

	struct Rect : public Point, Size {
	public:
		Rect(int x=0, int y=0, int z=0, int w=0, int h=0, int l=0) : Point(x, y, z), Size(w, h, l) {};

		bool is_colliding(const Rect& other) {
			return false;
		}

		bool is_colliding_with_point(const Point& pt) {
			return false;
		}
	};
}
//sprite
namespace flow {
	class Sprite {
		SDL_Texture* texture;
		const char* name;
		const char* path;

	public:
		Rect2 source_section;
		Rect2 destination_section;

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

		friend void draw(Sprite* sprite);

		Size2* get_size() {
			int w, h;
			SDL_QueryTexture(this->texture, NULL, NULL, &w, &h);
			return new Size2(w, h);
		}

		const char* get_name() {
			return this->name;
		}

		const char* get_path() {
			return this->path;
		}
	};
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

		char* get_name() {
			return this->name;
		}

		char* get_group() {
			return this->group;
		}
	};
}
//types
namespace flow {
	typedef SDL_Window* Window;
	typedef SDL_Renderer* Renderer;
	typedef std::vector<flow::Entity*> EntityList;

	struct EntityPair {
		int id;
		flow::Entity* entity;
	};
	typedef std::vector<EntityPair> EntityMap;
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
	}
}
//exceptions
namespace flow {
	namespace exception {
		class Init: public std::exception {
			std::string err_msg;

		public:
			Init(const char* sdl_err_msg) {
				this->err_msg = "Cannot to init due to SDL2 error: " + std::string(sdl_err_msg) + ".";
			}

			const char* what() const throw() {
				return this->err_msg.c_str();
			}
		};
	}
}
namespace flow {
	namespace exception {
		class Window: public std::exception {
			std::string err_msg;

		public:
			//TODO: Find out why it doesn't work.
			Window(std::string err_msg, const char* sdl_err_msg) {
				this->err_msg = err_msg + ". SDL2 error message: " + std::string(sdl_err_msg) + ".";
			}

			const char* what() const throw() {
				return this->err_msg.c_str();
			}
		};
	}
}
namespace flow {
	namespace exception {
		class SpriteLoad: public std::exception {
			std::string err_msg;

		public:
			SpriteLoad(const char* name, const char* path, const char* sdl_err_msg) {
				this->err_msg = "Cannot to load sprite with name \"";
				this->err_msg += name;
				this->err_msg += "\" and path \"";
				this->err_msg += path;
				this->err_msg += "\". SDL error info: ";
				this->err_msg += sdl_err_msg;
				this->err_msg +=".";
			}
			
			const char* what() const throw() {
				return this->err_msg.c_str();
			}
		};
	}
}
namespace flow {
	namespace exception {
		class EntityFindByName: public std::exception {
			std::string err_msg;
		public:
			EntityFindByName(char* name) {
				std::string name_str = name;
				if(name == NULL) name_str = "NULL";
				
				this->err_msg = "Entity with name \"" + name_str + "\" not found.";
			}

			const char* what() const throw() {
				return this->err_msg.c_str();
			}
		};

		class EntityFindByGroup: public std::exception {
			std::string err_msg;
		public:
			EntityFindByGroup(char* group) {
				std::string group_name = group;
				if(group == NULL) group_name = "NULL";

				this->err_msg = "Entity with group name \"" + group_name + "\" not found.";
			}

			const char* what() const throw() {
				return this->err_msg.c_str();
			}
		};
	}
}
namespace flow {
	namespace exception {
		class NullString: public std::exception {
			std::string method_name;
			std::string additional_info;
		public:
			NullString(std::string method_name, std::string additional_info="") {
				this->method_name = method_name;
				this->additional_info = additional_info;
			}

			const char* what() const throw() {
				std::string err_msg = "Given string (char*) in method with name \"" + this->method_name + "\" is NULL. " + additional_info;
				return err_msg.c_str();
			}
		};
	}
}
//collectors
namespace flow {
	class EntityCollector {
		EntityList entities;
	public:

		~EntityCollector() {
			for(auto entity : entities) {
				delete entity;
			}
		}
		
		/**
		 *  \brief Adds new entity to the collector.
		 *
		 *  \param entity New entity handler.
		 */
		void add(Entity* entity) {
			this->entities.push_back(entity);
		}

		/**
		 *  \brief Removes the first entity that possesses specified name.
		 *
		 *  \param name Entity's name.
		 */
		void remove_by_name(char* name) {
			this->entities.erase(this->find_by_name(name));
		}

		/**
		 *  \brief Removes all entites that belongs to the specified group.
		 *
		 *  \param group Entities' group name.
		 */
		void remove_by_group(char* group) {
			auto found_entities = this->find_by_group(group);
			for(auto entity : found_entities) {
				this->entities.erase(this->entities.begin()+entity.id);
			}
		}

		/**
		 *  \brief Finds the first entity that possesses specified name.
		 *
		 *  \param name Entity's name.
		 *  \return Entity's pointer.
		 */
		Entity* get_by_name(char* name) {
			auto result = this->find_by_name(name);
			return *result;
		}

		/**
		 *  \brief Finds all entites that belongs to the specified group.
		 *
		 *  \param group Entities' group name.
		 *  \return Map of entities' pointers and it's poisitions in Entity Collector.
		 */
		EntityMap get_by_group(char* group) {
			return find_by_group(group);
		}

	private:
		/**
		 *  \brief Finds the first entity that possesses specified name.
		 *
		 *  \param name Entity's name.
		 *  \return Entity's iterator from Entity Collector entities list.
		 */
		EntityList::iterator find_by_name(char* name) {
			if(name == NULL) {
				std::string additional_info = "It can happen when you have specified a NULL (char*) pointer to one of EntityCollector searching methods. I.e get_by_name or remove_by_name.";
				throw exception::NullString("find_by_name", additional_info);
			}
			auto entity_iterator = std::find_if(this->entities.begin(), this->entities.end(), [name](Entity* e){
				return strcmp(e->get_name(), name) == 0;
			});
			if(entity_iterator != this->entities.end()) {
				return entity_iterator;
			}
			throw exception::EntityFindByName(name);
		}

		/**
		 *  \brief Finds all entites that belongs to the specified group.
		 *
		 *  \param group Entities' group name.
		 *  \return Map of entities' pointers and it's poisitions in Entity Collector.
		 */
		EntityMap find_by_group(char* group) {
			EntityMap result;
			if(group == NULL) {
				std::string additional_info = "It can happen when you have specified a NULL (char*) pointer to one of EntityCollector searching methods. I.e get_by_group or remove_by_group.";
				throw exception::NullString("find_by_group", additional_info);
			}
			for(int entity_id = 0; entity_id < this->entities.size(); entity_id++) {
				if(strcmp(this->entities[entity_id]->get_group(), group) == 0) {
					EntityPair new_pair = {entity_id, this->entities[entity_id]};
					result.push_back(new_pair);
				}
			}
			if(result.size()==0) throw exception::EntityFindByGroup(group);
			return result;
		}
	};
}
namespace flow {
	class SpriteCollector {
		std::vector<Sprite*> sprites;
	public:

		~SpriteCollector() {
			for(auto sprite : sprites) {
				delete sprite;
			}
		}

		void add(const Renderer canvas, const char* name, const char* path) {
			auto sprite = new Sprite(name, path);
			this->sprites.push_back(sprite);
			this->load_sprite(canvas, sprite);
		}

		void remove(const char* name) {
			;
		}

		Sprite* get(const char* name) {
			;
		}
	private:
		void load_sprite(const Renderer canvas, Sprite* sprite) {
			sprite->texture = IMG_LoadTexture(canvas, sprite->path);
			if(sprite->texture == NULL) throw exception::SpriteLoad(sprite->name, sprite->path, SDL_GetError());
		}
	};
}

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
		bool is_fixable;
		ScreenMode scr_mode;

		Flow(bool is_fixable=true) {
			this->is_fixable = is_fixable;
			this->scr_mode = WINDOW;
		}

		~Flow() {
			SDL_DestroyRenderer(this->canvas);
			SDL_DestroyWindow(this->window);
		}

		void create_window(const char* w_name = "Sample", Point2 pos=WINDOW_CENTER, Size2 size=Size2(640, 480), ScreenMode scr_mode = WINDOW) {
			this->scr_mode = scr_mode;
			this->initialize_window(w_name, pos, size);
			this->initialize_canvas();
		}

		// entity methods
		void add_entity(Entity* entity) {
			entity_collector.add(entity);
		}

		void remove_entity_by_name(char* name) {
			entity_collector.remove_by_name(name);
		}

		void remove_entities_by_group(char* group) {
			entity_collector.remove_by_group(group);
		}

		Entity* get_entity_by_name(char* name) {
			return entity_collector.get_by_name(name);
		}

		EntityMap get_entities_by_group(char* group) {
			return entity_collector.get_by_group(group);
		}

		// sprite methods
		void add_sprite(const char* name, const char* path) {
			sprite_collector.add(this->canvas, name, path);
		}

		// game stuff
		void game_loop() {
			;
		}

	private:
		//initializing methods.
		void initialize_window(const char* w_name, Point2& pos, Size2& size) {
			this->window = SDL_CreateWindow(w_name, pos.x, pos.y, size.w, size.h, this->scr_mode);
			if(this->window == NULL) {
				throw exception::Window("Cannot to create window", SDL_GetError());
			}
		}

		void initialize_canvas() {
			this->canvas = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
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
namespace flow {
	class GameEntity : public Entity {
	public:
		Flow* engine;

		GameEntity(Flow* engine) : Entity() {
			this->engine = engine;
		}

		GameEntity(Flow* engine, Point pos, Size size, char* name, char* group) : Entity(pos, size, name, group) {
			this->engine = engine;
		}

		virtual void update(double delta) = 0;
		virtual void event(SDL_Event* event) = 0;
		virtual void collision(Entity& body) = 0;
	};
}