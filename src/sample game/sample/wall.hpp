#pragma once

#include "../flow.hpp"
#include <iostream>

namespace game {
	class Wall : public flow::GameEntity {
	public:
		Wall(flow::Flow* engine, double x) : flow::GameEntity(engine) {
			this->name = "w1";
			this->group = "g2";
			this->shared_sprite.sprite = this->engine->get_sprite("wall");
			this->collider.set_pos(flow::Point(x, 100, 70));
			this->collider.set_size(flow::Size(80, 100, 20));
		}

		void update(double delta) {
			//this->collider.x += 3*delta;
		}
		void event(SDL_Event event) {
		}
	};

	class Leg : public flow::GameEntity {
	public:
		Leg(flow::Flow* engine, std::string name, int x_off, int z_off) : flow::GameEntity(engine) {
			this->name = name;
			this->group = "g2";
			this->shared_sprite.sprite = this->engine->get_sprite("wall");
			this->collider.set_pos(flow::Point(200+x_off, 101, 0+z_off));
			this->collider.set_size(flow::Size(80, 100, 20));
		}

		void update(double delta) {
			//this->collider.x += 3*delta;
		}
		void event(SDL_Event event) {
		}
	};

	class SpecialLeg : public flow::GameEntity {
		bool go_up = true;
	public:
		SpecialLeg(flow::Flow* engine, int x_off, int z_off) : flow::GameEntity(engine) {
			this->name = "special_leg";
			this->group = "g2";
			this->shared_sprite.sprite = this->engine->get_sprite("wall");
			this->collider.set_pos(flow::Point(200+x_off, 102, 0+z_off));
			this->collider.set_size(flow::Size(80, 100, 20));
			this->scale = flow::new_scale(1.05);
		}

		void update(double delta) {
			if(go_up) {
				if(this->collider.z > 180) {
					this->collider.z -= 40*delta;
				} else {
					go_up = false;
				}
			} else {
				if(this->collider.z < 320) {
					this->collider.z += 40*delta; 
				} else {
					go_up = true;
				}
			}
		}
		void event(SDL_Event event) {
		}
	};

	class FlyingLeg : public flow::GameEntity {
		bool go_up = true;
	public:
		FlyingLeg(flow::Flow* engine, int x_off, int z_off) : flow::GameEntity(engine) {
			this->name = "flying_leg";
			this->group = "g2";
			this->shared_sprite.sprite = this->engine->get_sprite("wall");
			this->collider.set_pos(flow::Point(200+x_off, 75, 0+z_off));
			this->collider.set_size(flow::Size(80, 100, 20));
			this->scale = flow::new_scale(1.1);
		}

		void update(double delta) {
			if(go_up) {
				if(this->collider.y > 5) {
					this->collider.y -= 40*delta;
				} else {
					go_up = false;
				}
			} else {
				if(this->collider.y < 200) {
					this->collider.y += 40*delta; 
				} else {
					go_up = true;
				}
			}
		}
		void event(SDL_Event event) {
		}
	};
}