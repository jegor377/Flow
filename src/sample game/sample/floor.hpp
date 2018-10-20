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
			this->collider.set_pos(flow::Point(200, 300, 50));
			this->collider.set_size(flow::Size(500, 50, 550));
			this->scale = flow::new_scale(0.6);
		}

		void update(double delta) {
			if(this->collider.y > 10) {
				this->collider.y -= 10*delta;
			}
			std::cout<<"floor: "<<this->collider.y<<std::endl;
		}
		void event(SDL_Event event) {}
	};

	class Table : public flow::GameEntity {
	public:
		Table(flow::Flow* engine) : flow::GameEntity(engine) {
			this->name = "table";
			this->group = "ground";
			this->shared_sprite.sprite = this->engine->get_sprite("floor");
			this->collider.set_pos(flow::Point(200, 50, 0));
			this->collider.set_size(flow::Size(500, 50, 550));
			this->scale = flow::new_scale(0.5);
			this->scale.x = 1;
		}

		void update(double delta) {}
		void event(SDL_Event event) {
		}
	};
}