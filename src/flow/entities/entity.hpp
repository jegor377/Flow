#pragma once

#include <SDL2/SDL.h>
#include "../data/point.hpp"
#include "../data/size.hpp"

namespace flow {
	class Entity {
	protected:
		Point pos;
		Size size;
		
		const char* name;
		const char* group;
	public:
		virtual void update(int delta) = 0;
		virtual void render(SDL_Renderer* canvas) = 0;
		virtual void events(SDL_Event* event) = 0;
	};
}