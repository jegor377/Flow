#pragma once

#include "../flow.hpp"
#include <iostream>

namespace game {
	class Wall : public flow::GameEntity {
	public:
		Wall(flow::Flow* engine) : flow::GameEntity(engine) {
			this->name = "w1";
			this->group = "g2";
			this->shared_sprite.sprite = this->engine->get_sprite("wall");
			this->collider.set_pos(flow::Point(110, 70, 70));
			this->collider.set_size(flow::Size(80, 100, 20));
		}

		void update(double delta) {
			//this->collider.x += 3*delta;
		}
		void event(SDL_Event event) {}
		void collision(flow::Entity& body) {flow::log::info("collision");}
	};
}