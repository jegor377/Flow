#pragma once

#include "../flow.hpp"
#include <iostream>

namespace game {
	class Player : public flow::GameEntity {
		flow::Vector velocity;
		flow::Vector gravity;
		flow::Vector jump_vel;
		const double BOUNCE = 0.5;
		bool is_colliding_below = false;
	public:
		Player(flow::Flow* engine) : flow::GameEntity(engine) {
			this->name = "p1";
			this->group = "g1";
			this->shared_sprite.sprite = this->engine->get_sprite("wall");
			this->collider.set_pos(flow::Point(230, -100, 100));
			this->collider.set_size(flow::Size(80, 100, 20));
			this->scale = flow::new_scale(0.4);
			this->gravity = flow::Vector(0, 10, 0);
			this->jump_vel = flow::Vector(0, -300, 0);
		}

		void update(double delta) {
			auto collision_bodies = this->engine->find_collisions(this);
			this->is_colliding_below = false;
			for(auto body: *collision_bodies) {
				if(body->is_in_group("ground")) {
					is_colliding_below = true;
					if(this->velocity.y > 0) {
						auto bounce_vel = this->velocity;
						bounce_vel.mul_by_val(BOUNCE);
						bounce_vel.add(this->velocity);
						this->velocity.sub(bounce_vel);
						if(this->velocity.y<0) this->velocity.y = 0;
					}
				}
			}
			delete collision_bodies;
			if(!is_colliding_below) {
				this->velocity.add(gravity);
			}
			flow::Vector frame_vel = this->velocity;
			frame_vel.mul_by_val(delta);
			this->move(frame_vel);
		}
		void event(SDL_Event event) {
			if(event.type == SDL_QUIT) {
				flow::log::info("Exit.");
				this->engine->is_running = false;
			} else if(event.type == SDL_MOUSEBUTTONDOWN) {
				if(is_colliding_below) {
					this->velocity.add(this->jump_vel);
				}
			}
		}
	};

	class Debugging : public flow::GameEntity {
	public:
		Debugging(flow::Flow* engine) : flow::GameEntity(engine) {
			this->is_handling_rendering = false;
			this->is_handling_update = false;
		}

		void update(double delta) {}
		void event(SDL_Event event) {
			if(event.type == SDL_QUIT) {
				flow::log::info("Exit.");
				this->engine->is_running = false;
			}
		}
	};
}