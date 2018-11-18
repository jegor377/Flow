#pragma once

#include "flow.hpp"

class TestEntity: public flow::GameEntity {
public:
	TestEntity(std::string name, std::string group = "sample"): flow::GameEntity(NULL) {
		this->name = name;
		this->group = group;
	}

	void update(double delta) {}
	void event(SDL_Event event) {}
};