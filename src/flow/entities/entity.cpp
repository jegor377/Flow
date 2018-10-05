#include <string>
#include "./entity.hpp"

namespace flow {
	Entity::Entity() {}
	
	Entity::Entity(Point pos, Size size, char* name, char* group) {
		this->pos   = pos;
		this->size  = size;
		this->name  = name;
		this->group = group;
	}

	Entity::Entity(const Entity& copy_entity) {
		strcpy(this->name, copy_entity.name);
		strcpy(this->group, copy_entity.group);
	}

	void Entity::render(SDL_Renderer* canvas) {
		;
	}
}