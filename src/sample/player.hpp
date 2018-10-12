#pragma once

#include "../flow.hpp"
#include <iostream>

namespace game {
	class Player : public flow::GameEntity {
	public:
		Player(flow::Flow* engine) : flow::GameEntity(engine) {
			this->name = (char*)"p1";
			this->group = (char*)"g1";
		}

		void update(double delta) {std::cout<<"test"<<std::endl;};
		void event(SDL_Event* delta) {std::cout<<"test"<<std::endl;};
		void collision(flow::Entity& body) {std::cout<<"test"<<std::endl;};
	};
}