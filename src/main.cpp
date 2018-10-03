#include <iostream>
#include "flow/flow.hpp"

using namespace std;

const bool DEBUG_MODE = true;

int main(int argc, char** argv) {
	try {
		flow::init();
		atexit(flow::quit);

		flow::Flow engine(DEBUG_MODE);

		engine.create_window("Test Window:))");
		flow::log::info("Window created.");
		SDL_Delay(5000);
	} catch(flow::exception::Init& e) {
		flow::log::error( "INIT ERROR: "+std::string(e.what())+"." );
		return 1;
	} catch(flow::exception::Window& e) {
		return 1;
	}
	return 0;
}