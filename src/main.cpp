#include <iostream>
#include "flow/flow.hpp"

using namespace std;

const bool DEBUG_MODE = true;

int main(int argc, char** argv) {
	try {
		flow::init(SDL_INIT_EVERYTHING);
		atexit(flow::quit);

		flow::Flow* engine = flow::engine(DEBUG_MODE);

		flow::create_window(engine, "Test Window:)");
		flow::log::info("Window created.");

		flow:destroy_engine(engine);
		delete engine;
	} catch(flow::exception::Init& e) {
		flow::log::error( "INIT ERROR: "+std::string(e.what())+"." );
	} catch(flow::exception::Window& e) {}
	return 0;
}