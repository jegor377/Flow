#pragma once

#include "../flow.hpp"
#include <iostream>

namespace game {
	class Floor : public flow::GameEntity {
	public:
		Floor(flow::Flow* engine) : flow::GameEntity(engine) {
			this->name = "floor";
			this->group = "ground";
			this->shared_sprite.sprite = this->engine->get_sprite("floor");
			this->collider.set_pos(flow::Point(200, 100, 20));
			this->collider.set_size(flow::Size(500, 50, 550));
			this->shared_sprite.scale = 0.6;
		}

		void update(double delta) {
			if(this->collider.y < 150) {
				this->collider.y -= 10*delta;
			}
		}
		void event(SDL_Event event) {}
		void collision(flow::Entity& body) {flow::log::info("collision");}
	};
}