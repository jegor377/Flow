#pragma once

#include "../flow.hpp"
#include <iostream>

namespace game {
	class Player : public flow::GameEntity {
	public:
		Player(flow::Flow* engine) : flow::GameEntity(engine) {
			this->name = "p1";
			this->group = "g1";
			this->shared_sprite.sprite = this->engine->get_sprite("wall");
			this->collider.set_pos(flow::Point(230, 0, 50));
			this->collider.set_size(flow::Size(80, 100, 20));
		}

		void update(double delta) {
			/*if(this->collider.x < 150) {
				this->collider.x += 10*delta;
			}*/
			if(this->collider.y > 100) {
				this->collider.y -= 10*delta;
			}
		}
		void event(SDL_Event event) {
			if(event.type == SDL_QUIT) {
				flow::log::info("Exit.");
				this->engine->is_running = false;
			}
		}
		void collision(flow::EntityPtr body) {flow::log::info("collision");}
	};

	class Debugging : public flow::GameEntity {
	public:
		Debugging(flow::Flow* engine) : flow::GameEntity(engine) {
			this->is_handling_rendering = false;
			this->is_handling_update = false;
			this->is_handling_collisions = false;
		}

		void update(double delta) {}
		void event(SDL_Event event) {
			if(event.type == SDL_QUIT) {
				flow::log::info("Exit.");
				this->engine->is_running = false;
			}
		}
		void collision(flow::EntityPtr body) {}
	};
}