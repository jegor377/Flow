#pragma once

#include <vector>
#include <string>
#include <cstring>
#include <exception>
#include <algorithm>
#include <memory>
#include <initializer_list>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

// Wrapper CPP imports:
//physical metrics
namespace flow {
	class Point2 {
	public:
		double x;
		double y;

		Point2(double x=0, double y=0) {
			this->x=x;
			this->y=y;
		}
	};

	class Point : public Point2 {
	public:
		double z=0;
		Point(double x=0, double y=0, double z=0) : Point2(x, y) {
			this->z = z;
		}
	};
}
namespace flow {
	class Vector : public Point {
	public:
		Vector(double x=0, double y=0, double z=0) : Point(x, y, z) {};
	};

	Vector new_scale(double scale) {
		Vector result(scale, scale, scale);
		return result;
	}
}
namespace flow {
	class Size2 {
	public:
		double w; // width
		double h; // height
		Size2(double w=0, double h=0) {
			this->w=w;
			this->h=h;
		}
	};

	class Size : public Size2 {
	public:
		double l; // length

		Size(double w=0, double h=0, double l=0) : Size2(w, h) {
			this->l=l;
		}
	};
}
namespace flow {
	enum RectMode {
		SECTION = 0,
		FULL = 1
	};

	class Rect2 : public Point2, public Size2 {
		SDL_Rect sdl_representation;
	public:
		RectMode mode;

		Rect2(double x=0, double y=0, double w=0, double h=0, RectMode mode=FULL) : Point2(x, y), Size2(w, h) {
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

		void set_pos(const Point2& new_pos) {
			this->x = new_pos.x;
			this->y = new_pos.y;
		}

		void set_size(const Size2& new_size) {
			this->w = new_size.w;
			this->h = new_size.h;
		}

		void add_pos(Rect2& other) {
			this->x += other.x;
			this->y += other.y;
		}

		void sub_pos(Rect2& other) {
			this->x -= other.x;
			this->y -= other.y;
		}

		void mul_pos(Rect2& other) {
			this->x *= other.x;
			this->y *= other.y;
		}

		void div_pos(Rect2& other) {
			this->x /= other.x;
			this->y /= other.y;
		}

		void add_size(Rect2& other) {
			this->w += other.w;
			this->h += other.h;
		}

		void sub_size(Rect2& other) {
			this->w -= other.w;
			this->h -= other.h;
		}

		void mul_size(Rect2& other) {
			this->w *= other.w;
			this->h *= other.h;
		}

		void div_size(Rect2& other) {
			this->w /= other.w;
			this->h /= other.h;
		}
	};

	struct Rect : public Point, public Size {
	public:
		Rect(double x=0, double y=0, double z=0, double w=0, double h=0, double l=0) : Point(x, y, z), Size(w, h, l) {};

		void add_pos(Rect& other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
		}

		void sub_pos(Rect& other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
		}

		void mul_pos(Rect& other) {
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
		}

		void div_pos(Rect& other) {
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
		}

		void add_size(Rect& other) {
			this->w += other.w;
			this->h += other.h;
			this->l += other.l;
		}

		void sub_size(Rect& other) {
			this->w -= other.w;
			this->h -= other.h;
			this->l -= other.l;
		}

		void mul_size(Rect& other) {
			this->w *= other.w;
			this->h *= other.h;
			this->l *= other.l;
		}

		void mul_size_by_scale(Vector& other) {
			this->w *= other.x;
			this->h *= other.y;
			this->l *= other.z;
		}

		void div_size(Rect& other) {
			this->w /= other.w;
			this->h /= other.h;
			this->l /= other.l;
		}

		Rect2* to_rect2() {
			Rect2* result = new Rect2(this->x, this->y+this->z, this->w, this->h+this->l, SECTION);
			return result;
		}

		Rect2* to_scaled_rect2(Vector scale) {
			Rect2* result = new Rect2(this->x, this->y+this->z, this->w*scale.x, (this->h*scale.y)+(this->l*scale.z), SECTION);
			return result;
		}

		void set_pos(const Point& new_pos) {
			this->x = new_pos.x;
			this->y = new_pos.y;
			this->z = new_pos.z;
		}

		void set_size(const Size& new_size) {
			this->w = new_size.w;
			this->h = new_size.h;
			this->l = new_size.l;
		}

		bool is_colliding(Rect& other) {
			return this->x < other.x + other.w && this->x + this->w > other.x && this->y < other.y + other.h && this->y + this->h > other.y && this->z < other.z + other.l && this->z + this->l > other.z;
		}

		bool is_colliding_with_point(Point& pt) {
			bool is_x_collision = this->x<=pt.x && this->x+this->w>=pt.x;
			bool is_y_collision = this->y<=pt.y && this->y+this->h>=pt.y;
			bool is_z_collision = this->z<=pt.z && this->z+this->l>=pt.z;
			return is_x_collision && is_y_collision && is_z_collision;
		}

		bool is_in_xy_collision(Rect& other) {
			return this->x < other.x + other.w && this->x + this->w > other.x && this->y < other.y + other.h && this->y + this->h > other.y;
		}

		bool is_in_xz_collision(Rect& other) {
			return this->x < other.x + other.w && this->x + this->w > other.x && this->z < other.z + other.l && this->z + this->l > other.z;
		}
	};
}
//sprite exceptions
namespace flow {
	namespace exception {
		class SpriteAssign: public std::exception {
		public:
			const char* what() const throw() {
				return "Sprite reference not assigned in SharedSprite.";
			}
		};
	}
}
namespace flow {
	namespace exception {
		class SpriteFind: public std::exception {
			std::string err_msg;
		public:
			SpriteFind(const std::string& name) {
				this->err_msg = "Sprite with name \"" + name + "\" not found.";
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
			SpriteLoad(const std::string& name, const std::string& path, const char* sdl_err_msg) {
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
//sprite
namespace flow {
	class Sprite {
		SDL_Texture* texture;
		std::string name;
		std::string path;

	public:
		Sprite(const std::string& name, const std::string& path) {
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
		friend class Flow;

		const Size2* get_size() {
			if(this->texture != NULL) {
				int w, h;
				SDL_QueryTexture(this->texture, NULL, NULL, &w, &h);
				return new Size2(w, h);
			} else return NULL;
		}

		const std::string get_name() {
			return this->name;
		}

		const std::string get_path() {
			return this->path;
		}

		bool has_name(const std::string& name) {
			return this->name == name;
		}
	};

	typedef std::shared_ptr<Sprite> SpritePtr;
}
namespace flow {
	class SharedSprite {
	public:
		SpritePtr sprite;
		Rect2 source_section;

		SharedSprite() {
			this->sprite.reset();
		}

		SharedSprite(SpritePtr sprite) {
			this->sprite = sprite;
		}

		SharedSprite(SpritePtr sprite, Rect2 source_section) {
			this->sprite = sprite;
			this->source_section = source_section;
		}

		const Size2* get_size() {
			if(this->sprite) return this->sprite->get_size();
			throw exception::SpriteAssign();
		}

		const std::string get_name() {
			if(this->sprite) return this->sprite->get_name();
			throw exception::SpriteAssign();
		}

		const std::string get_path() {
			if(this->sprite) return this->sprite->get_path();
			throw exception::SpriteAssign();
		}

		bool has_name(const std::string& name) {
			if(this->sprite) return this->sprite->has_name(name);
			throw exception::SpriteAssign();
		}
	};
}
//entities
namespace flow {
	class Entity {
	protected:
		std::string name;
		std::string group;
	public:
		Rect collider;

		SharedSprite shared_sprite;
		
		bool is_handling_rendering;
		bool is_handling_update;
		bool is_handling_events;
		bool is_handling_collisions;

		Vector scale;
	private:
		void set_default() {
			this->scale = Vector(1, 1, 1);
			this->is_handling_rendering = true;
			this->is_handling_update = true;
			this->is_handling_events = true;
			this->is_handling_collisions = true;
		}

	public:
		Entity() {
			this->set_default();
		}
	
		Entity(Rect collider, const std::string& name, const std::string& group) {
			this->collider = collider;
			this->name = name;
			this->group = group;
			this->set_default();
		}
		
		virtual void update(double delta) = 0;
		virtual void event(SDL_Event event) = 0;
		virtual void collision(std::shared_ptr<Entity> body) = 0;

		const std::string get_name() {
			return this->name;
		}

		const std::string get_group() {
			return this->group;
		}

		bool has_name(const std::string& name) {
			return this->name == name;
		}

		bool is_in_group(const std::string& group) {
			return this->group == group;
		}

		bool is_in_xy_collision(std::shared_ptr<Entity> body) {
			Rect other_scaled_rect = body->collider;
			other_scaled_rect.mul_size_by_scale(body->scale);
			Rect this_scaled_rect = this->collider;
			this_scaled_rect.mul_size_by_scale(this->scale);
			return this_scaled_rect.is_in_xy_collision(other_scaled_rect);
		}

		bool is_in_xz_collision(std::shared_ptr<Entity> body) {
			Rect other_scaled_rect = body->collider;
			other_scaled_rect.mul_size_by_scale(body->scale);
			Rect this_scaled_rect = this->collider;
			this_scaled_rect.mul_size_by_scale(this->scale);
			return this_scaled_rect.is_in_xz_collision(other_scaled_rect);
		}
	};

	typedef std::shared_ptr<Entity> EntityPtr;
}
//types
namespace flow {
	typedef SDL_Window* Window;
	typedef SDL_Renderer* Renderer;
}
//logger
namespace flow {
	namespace log {
		void info(const std::string& msg) {
			SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
		}

		void warn(const std::string& msg) {
			SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
		}

		void error(const std::string& msg) {
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
		}

		void debug(const std::string& msg) {
			SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
		}

		// special functions
		// logs warn when sdl reported error and flow fixed it somehow.
		void sdl_fix_warn(const std::string& error_source, const std::string& fix_way, const char* sdl_error_msg) {
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
			Window(const std::string& err_msg, const char* sdl_err_msg) {
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
		class EntityFindByName: public std::exception {
			std::string err_msg;
		public:
			EntityFindByName(const std::string& name) {
				this->err_msg = "Entity with name \"" + name + "\" not found.";
			}

			const char* what() const throw() {
				return this->err_msg.c_str();
			}
		};

		class EntityFindByGroup: public std::exception {
			std::string err_msg;
		public:
			EntityFindByGroup(const std::string& group) {
				this->err_msg = "Entity with group name \"" + group + "\" not found.";
			}

			const char* what() const throw() {
				return this->err_msg.c_str();
			}
		};
	}
}
//collectors
namespace flow {
	struct EntityPair {
		int id;
		EntityPtr entity;
	};

	typedef std::vector<EntityPtr> EntityList;
	typedef std::vector<EntityPair> EntityMap;

	class EntityCollector {
		EntityList entities;
	public:

		friend class Flow;

		~EntityCollector() {
			entities.clear();
		}
		
		/**
		 *  \brief Adds new entity to the collector.
		 *
		 *  \param entity New entity handler.
		 */
		void add(EntityPtr entity) {
			this->entities.push_back(entity);
		}

		/**
		 *  \brief Removes the first entity that possesses specified name.
		 *
		 *  \param name Entity's name.
		 */
		void remove_by_name(const std::string& name) {
			this->entities.erase(this->find_by_name(name));
		}

		/**
		 *  \brief Removes all entites that belongs to the specified group.
		 *
		 *  \param group Entities' group name.
		 */
		void remove_by_group(const std::string& group) {
			auto found_entities = this->find_by_group(group);
			for(auto entity : found_entities) {
				this->entities.erase(this->entities.begin()+entity.id);
			}
		}

		/**
		 *  \brief Finds the first entity that possesses specified name.
		 *
		 *  \param name Entity's name.
		 *  \return Entity's shared pointer.
		 */
		EntityPtr get_by_name(const std::string& name) {
			auto result = this->find_by_name(name);
			return *result;
		}

		/**
		 *  \brief Finds all entites that belongs to the specified group.
		 *
		 *  \param group Entities' group name.
		 *  \return Map of entities' pointers and it's poisitions in Entity Collector.
		 */
		EntityMap get_by_group(const std::string& group) {
			return find_by_group(group);
		}

	private:
		/**
		 *  \brief Finds the first entity that possesses specified name.
		 *
		 *  \param name Entity's name.
		 *  \return Entity's iterator from Entity Collector entities list.
		 */
		EntityList::iterator find_by_name(const std::string& name) {
			auto entity_iterator = std::find_if(this->entities.begin(), this->entities.end(), [name](EntityPtr e){
				return e->has_name(name);
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
		EntityMap find_by_group(const std::string& group) {
			EntityMap result;
			for(int entity_id = 0; entity_id < this->entities.size(); entity_id++) {
				if(this->entities[entity_id]->is_in_group(group)) {
					EntityPair new_pair = {entity_id, this->entities[entity_id]};
					result.push_back(new_pair);
				}
			}
			if(result.size()==0) throw exception::EntityFindByGroup(group);
			return result;
		}

		EntityList sort() {
			EntityList result = this->entities;
			std::sort(result.begin(), result.end(), [](EntityPtr& e1, EntityPtr& e2){
				const double e1_y_point = (e1->collider.y+e1->collider.h*e1->scale.y/2);
				const double e2_y_point = (e2->collider.y+e2->collider.h*e2->scale.y/2);
				if(e1->is_in_xy_collision(e2)) {
					return e1->collider.z <= e2->collider.z;
				}
				return e1_y_point > e2_y_point;
			});
			return result;
		}
	};
}
namespace flow {
	typedef std::vector<SpritePtr> SpriteList;
	
	class SpriteCollector {
		SpriteList sprites;
	public:

		~SpriteCollector() {
			sprites.clear();
		}

		void add(const Renderer canvas, const std::string& name, const std::string& path) {
			auto sprite = std::make_shared<Sprite>(name, path);
			this->sprites.push_back(sprite);
			this->load_sprite(canvas, sprite);
		}

		void remove(const std::string& name) {
			this->sprites.erase(this->find(name));
		}

		SpritePtr get(const std::string& name) {
			return *(this->find(name));
		}
	private:
		void load_sprite(const Renderer canvas, SpritePtr sprite) {
			sprite->texture = IMG_LoadTexture(canvas, sprite->path.c_str());
			if(sprite->texture == NULL) throw exception::SpriteLoad(sprite->name, sprite->path, SDL_GetError());
		}

		SpriteList::iterator find(const std::string& name) {
			auto sprite_iterator = std::find_if(this->sprites.begin(), this->sprites.end(), [name](SpritePtr e){
				return e->has_name(name);
			});
			if(sprite_iterator != this->sprites.end()) {
				return sprite_iterator;
			}
			throw exception::SpriteFind(name);
		}
	};
}
//events
namespace flow {
	class EventList {
		std::vector<SDL_Event> events;

	public:
		~EventList() {
			this->events.clear();
		}

		void add(SDL_Event event) {
			this->events.push_back(event);
		}

		std::vector<SDL_Event> get() {
			return this->events;
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

		bool is_fixable;
		bool debug;

		Rect2 window_rect;
	public:
		ScreenMode scr_mode;
		bool is_running = true;
		Uint64 last_update_time;

		Flow(bool is_fixable=true, bool debug=false) {
			this->debug = debug;
			this->is_fixable = is_fixable;
			this->scr_mode = WINDOW;
			this->last_update_time = SDL_GetPerformanceCounter();
		}

		~Flow() {
			SDL_DestroyRenderer(this->canvas);
			SDL_DestroyWindow(this->window);
		}

		void create_window(const std::string& w_name = "Sample", bool use_vsync=true, Point2 pos=WINDOW_CENTER, Size2 size=Size2(640, 480), ScreenMode scr_mode = WINDOW) {
			this->window_rect.set_pos(pos);
			this->window_rect.set_size(size);
			this->scr_mode = scr_mode;
			this->initialize_window(w_name, pos, size);
			this->initialize_canvas(use_vsync);
		}

		// entity methods
		void add_entity(std::shared_ptr<Entity> entity) {
			entity_collector.add(entity);
		}

		void remove_entity_by_name(const std::string& name) {
			entity_collector.remove_by_name(name);
		}

		void remove_entities_by_group(const std::string& group) {
			entity_collector.remove_by_group(group);
		}

		EntityPtr get_entity_by_name(const std::string& name) {
			return entity_collector.get_by_name(name);
		}

		EntityMap get_entities_by_group(const std::string& group) {
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

		Rect2 get_window_rect() {
			return this->window_rect;
		}

		void game_loop() {
			while(this->is_running) {
				// Pulling events from event stack.
				auto events = this->get_events();

				// Sorting entities in order to easly render them later. It must be done because algorithm needs to know witch entity goes first and witch to cover.
				auto entities_copy = this->entity_collector.sort();

				// Calculate game delta time.
				auto update_time_now = SDL_GetPerformanceCounter();
				double delta_time = (double)(update_time_now - this->last_update_time) / (double)SDL_GetPerformanceFrequency();
				this->last_update_time = update_time_now;

				// Clear renderer (canvas).
				if(this->debug) SDL_SetRenderDrawColor(this->canvas, 0, 0, 0, 0);
				SDL_RenderClear(this->canvas);

				// Iteratre through all entities in order to update, handle events and copy their sprites into the screen:)
				for(auto entity : entities_copy) {
					if(entity->is_handling_update) this->update(entity, delta_time);
					if(entity->is_handling_events) this->handle_events(entity, events);
					if(entity->is_handling_rendering) this->render(entity);
				}

				// Present renderer (canvas) on screen.
				SDL_RenderPresent(this->canvas);

				delete events;
			}
		}

	private:
		// game stuff
		EventList* get_events() {
			EventList* result = new EventList();
			SDL_Event event;
			while(SDL_PollEvent(&event)) {
				result->add(event);
			}
			return result;
		}

		void handle_events(const EntityPtr& entity, EventList* events) {
			for(auto event: events->get()) {
				entity->event(event);
			}
		}

		void update(const EntityPtr& entity, const double& delta_time) {
			entity->update(delta_time);
			if(entity->is_handling_collisions) handle_collisions(entity, delta_time);
		}


		void handle_collisions(const EntityPtr& entity, const double& delta_time) {
			for(auto _entity: this->entity_collector.entities) {
				if(_entity.get() != entity.get()) {
					if(entity->collider.is_colliding(_entity->collider)) {
						entity->collision(_entity);
					}
				}
			}
		}

		void render(const EntityPtr& entity) {
			auto copy_texture = entity->shared_sprite.sprite->texture;
			Rect2& source_section = entity->shared_sprite.source_section;
			auto destination_rect = entity->collider.to_scaled_rect2(entity->scale);
			SDL_RenderCopyEx(this->canvas, copy_texture, source_section.get_sdl_rect(), destination_rect->get_sdl_rect(), 0.0, NULL, SDL_FLIP_NONE);
			if(this->debug) {
				SDL_SetRenderDrawColor(this->canvas, 255, 0, 0, 255);
				SDL_Rect point = {
					(int)(destination_rect->x+destination_rect->w/2),
					(int)(destination_rect->y+destination_rect->h/2+entity->collider.l*entity->scale.y/2),
					3,
					3
				};
				SDL_RenderFillRect(this->canvas, &point);
			}
			delete destination_rect;
		}

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
namespace flow {
	class GameEntity : public Entity {
	public:
		Flow* engine;

		GameEntity(Flow* engine) : Entity() {
			this->engine = engine;
		}

		GameEntity(Flow* engine, Rect collider, const std::string& name, const std::string& group) : Entity(collider, name, group) {
			this->engine = engine;
		}

		virtual void update(double delta) = 0;
		virtual void event(SDL_Event event) = 0;
		virtual void collision(EntityPtr body) = 0;
	};
}