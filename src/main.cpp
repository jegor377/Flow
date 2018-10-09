#include <iostream>
#include "flow.hpp"
#include "sample/player.hpp"

const bool DEBUG_MODE = true;

int main(int argc, char** argv) {
	try {
		flow::init();
		atexit(flow::quit);

		flow::Flow engine(DEBUG_MODE, false);

		engine.create_window("Test Window:))");
		flow::log::info("Window created.");

		game::Player player;
		engine.add_entity(&player);
		
		SDL_Delay(2000);
	} catch(flow::exception::Init& e) {
		flow::log::error( "INIT ERROR: "+std::string(e.what())+"." );
		return 1;
	} catch(flow::exception::Window& e) {
		return 1;
	}
	return 0;
}