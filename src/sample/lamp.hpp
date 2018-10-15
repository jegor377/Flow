#pragma once

#include "../flow.hpp"
#include <iostream>

namespace game {
	class Lamp : public flow::GameEntity {
	public:
		Lamp(flow::Flow* engine, double x) : flow::GameEntity(engine) {
			this->name = "l1";
			this->group = "g2";
			this->shared_sprite.sprite = this->engine->get_sprite("lamp");
			this->collider.set_pos(flow::Point(x, 100, 0));
			this->collider.set_size(flow::Size(50, 50, 10));
			this->scale=flow::new_scale(0.5);
		}

		void update(double delta) {}
		void event(SDL_Event event) {}
	};

	class Lamp2 : public flow::GameEntity {
	public:
		Lamp2(flow::Flow* engine, double x) : flow::GameEntity(engine) {
			this->name = "l2";
			this->group = "g2";
			this->shared_sprite.sprite = this->engine->get_sprite("lamp");
			this->collider.set_pos(flow::Point(x, 80, 49));
			this->collider.set_size(flow::Size(50, 50, 10));
			this->scale=flow::new_scale(0.7);
		}

		void update(double delta) {
			if(this->collider.y < 120) {
				this->collider.y += 10*delta;
			}
		}
		void event(SDL_Event event) {}
	};
}