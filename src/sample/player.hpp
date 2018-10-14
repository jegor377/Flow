#pragma once

#include "../flow.hpp"
#include <iostream>

namespace game {
	class Player : public flow::GameEntity {
		int i;
	public:
		Player(flow::Flow* engine) : flow::GameEntity(engine) {
			i=0;
			this->name = "p1";
			this->group = "g1";
			this->shared_sprite.sprite = this->engine->get_sprite("test");
			this->collider.set_pos(flow::Point(0, 0, 100));
			this->collider.set_size(flow::Size(80, 100, 20));
		}

		void update(double delta) {
			this->collider.x += 100.0*delta;
		}
		void event(SDL_Event event) {
			if(event.type == SDL_QUIT) {
				flow::log::info("Exit.");
				this->engine->is_running = false;
			}
		}
		void collision(flow::Entity& body) {flow::log::info("collision");}
	};
}