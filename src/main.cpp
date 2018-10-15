#include <iostream>
#include <exception>
#include "flow.hpp"
#include "sample/player.hpp"
#include "sample/wall.hpp"
#include "sample/lamp.hpp"
#include "sample/floor.hpp"

const bool DEBUG_MODE = true;

int main(int argc, char** argv) {
	try {
		flow::init();
		atexit(flow::quit);

		flow::Flow engine(false, true);

		engine.create_window();
		flow::log::info("Window created.");

		engine.add_sprite("wall", "wall.png");
		engine.add_sprite("floor", "floor.png");
		engine.add_sprite("lamp", "lamp.png");
		flow::log::info("Sprites loaded.");

		//engine.add_entity( std::make_shared<game::Wall>(&engine, 100) );
		//engine.add_entity( std::make_shared<game::Wall>(&engine, 250) );
		//engine.add_entity( std::make_shared<game::Lamp>(&engine, 200) );
		//engine.add_entity( std::make_shared<game::Floor>(&engine) );
		//engine.add_entity( std::make_shared<game::Lamp2>(&engine, 110) );
		engine.add_entity( std::make_shared<game::Debugging>(&engine) );
		engine.add_entity( std::make_shared<game::Table>(&engine) );
		engine.add_entity( std::make_shared<game::Leg>(&engine, "l11", 0, -25) );
		engine.add_entity( std::make_shared<game::Leg>(&engine, "l21", 250-80, -25) );
		engine.add_entity( std::make_shared<game::Leg>(&engine, "l12", 0, 275-50) );
		engine.add_entity( std::make_shared<game::Leg>(&engine, "l22", 250-80, 275-50) );
		engine.add_entity( std::make_shared<game::FlyingLeg>(&engine, (250-80)/2, 550/4) );
		engine.add_entity( std::make_shared<game::SpecialLeg>(&engine, 0-40, 275) );
		
		engine.game_loop();

		flow::log::info("Game loop finished.");
	} catch(std::exception& e) {
		if(DEBUG_MODE) flow::log::error(e.what());
		return 1;
	}
	return 0;
}