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
		}

		void update(double delta) {
			if((i++)==120) this->engine->is_running = false;
		}
		void event(SDL_Event* delta) {flow::log::info("event");}
		void collision(flow::Entity& body) {flow::log::info("collision");}
	};
}