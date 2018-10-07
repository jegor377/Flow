#pragma once

#include "../flow.hpp"
#include <iostream>

namespace game {
	class Player : public flow::Entity {
	public:
		Player() : flow::Entity() {
			;
		}

		void update(double delta) {std::cout<<"test"<<std::endl;};
		void event(SDL_Event* delta) {std::cout<<"test"<<std::endl;};
		void collision(flow::Entity& body) {std::cout<<"test"<<std::endl;};
	};
}