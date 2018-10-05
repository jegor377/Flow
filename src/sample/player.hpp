#pragma once

#include "../flow/flow.hpp"

namespace game {
	class Player : public flow::Entity {
	public:
		Player();

		void update(double delta);
		void event(SDL_Event* delta);
		void collision(flow::Entity& body);
	};
}