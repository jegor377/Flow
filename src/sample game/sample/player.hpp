#pragma once

#include "../flow.hpp"
#include <iostream>

namespace game {
	class Player : public flow::GameEntity {
		flow::Vector velocity;
		flow::Vector gravity;
		flow::Vector jump_vel;
		flow::Vector go_straight;
		flow::Vector go_backwards;
		flow::Vector go_left;
		flow::Vector go_right;
		const double BOUNCE = 0.5;
		bool is_colliding_below = false;
		bool is_going_straight = false;
		bool is_going_backwards = false;
		bool is_going_left = false;
		bool is_going_right = false;
	public:
		Player(flow::Flow* engine) : flow::GameEntity(engine) {
			this->name = "p1";
			this->group = "g1";
			this->shared_sprite.sprite = this->engine->get_sprite("wall");
			this->collider.set_pos(flow::Point(230, -100, 100));
			this->collider.set_size(flow::Size(80, 100, 20));
			this->scale = flow::new_scale(1);
			this->gravity = flow::Vector(0, 10, 0);
			this->jump_vel = flow::Vector(0, -300, 0);
			this->go_straight = flow::Vector(0, 0, -15);
			this->go_backwards = flow::Vector(0, 0, 15);
			this->go_left = flow::Vector(-15, 0, 0);
			this->go_right = flow::Vector(15, 0, 0);
		}

		void apply_friction(double friction=0.1) {
			flow::Vector friction_v = this->velocity;
			friction_v.mul_by_val(friction*(-1));
			this->velocity.add(friction_v);
		}

		void update(double delta) {
			auto collision_bodies = this->engine->find_collisions(this);
			this->is_colliding_below = false;
			for(auto body: *collision_bodies) {
				if(body->is_in_group("ground")) {
					is_colliding_below = true;
					if(this->velocity.y > 0) {
						auto bounce_vel = this->velocity;
						bounce_vel.y *= (BOUNCE);
						bounce_vel.y += this->velocity.y;
						this->velocity.y -= bounce_vel.y;
					}
				}
			}
			delete collision_bodies;
			if(!is_colliding_below) {
				this->velocity.add(gravity);
			} else {
				this->apply_friction();
			}
			//if(this->velocity.y <= 7 && this->velocity.y >= -7) this->velocity.y = 0;
			if(is_going_straight) this->velocity.add(go_straight);
			if(is_going_backwards) this->velocity.add(go_backwards);
			if(is_going_left) this->velocity.add(go_left);
			if(is_going_right)this->velocity.add(go_right);
			flow::Vector frame_vel = this->velocity;
			frame_vel.mul_by_val(delta);
			this->move(frame_vel);
		}
		void event(SDL_Event event) {
			
			switch(event.type) {
			case SDL_QUIT:
				flow::log::info("Exit.");
				this->engine->is_running = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				if(is_colliding_below) {
					this->velocity.add(this->jump_vel);
				}
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
				case SDLK_UP:
					is_going_straight = true;
					break;
				case SDLK_DOWN:
					is_going_backwards = true;
					break;
				case SDLK_LEFT:
					is_going_left = true;
					break;
				case SDLK_RIGHT:
					is_going_right = true;
					break;
				}
				break;
			case SDL_KEYUP:
				switch(event.key.keysym.sym) {
				case SDLK_UP:
					is_going_straight = false;
					break;
				case SDLK_DOWN:
					is_going_backwards = false;
					break;
				case SDLK_LEFT:
					is_going_left = false;
					break;
				case SDLK_RIGHT:
					is_going_right = false;
					break;
				}
				break;
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