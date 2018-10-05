#include "./player.hpp"

namespace game {
	Player::Player() : flow::Entity() {
		;
	}

	void update(double delta) {}
	void event(SDL_Event* delta) {}
	void collision(flow::Entity& body) {}
}