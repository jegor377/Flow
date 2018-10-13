#include <iostream>
#include <exception>
#include "flow.hpp"
#include "sample/player.hpp"

const bool DEBUG_MODE = true;

int main(int argc, char** argv) {
	try {
		flow::init();
		atexit(flow::quit);

		flow::Flow engine(false);

		engine.create_window();
		flow::log::info("Window created.");

		engine.add_sprite("test", "test.png");
		flow::log::info("Sprites loaded.");

		engine.add_entity( std::make_shared<game::Player>(&engine) );

		engine.game_loop();

		flow::log::info("120 Frames finished.");
		SDL_Delay(2000);
	} catch(std::exception& e) {
		if(DEBUG_MODE) flow::log::error(e.what());
		return 1;
	}
	return 0;
}