#pragma once

#include <SDL2/SDL.h>
#include "../data/point.hpp"
#include "../data/size.hpp"

namespace flow {
	class Entity {
	protected:
		Point pos;
		Size size;
		
		char* name;
		char* group;
	public:
		Entity();
		Entity(Point pos, Size size, char* name, char* group);
		Entity(const Entity& copy_entity);

		virtual void update(double delta) = 0;
		void render(SDL_Renderer* canvas);
		virtual void event(SDL_Event* event) = 0;
		virtual void collision(Entity& body) = 0;
	};
}