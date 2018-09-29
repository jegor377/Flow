#pragma once

#include <string>
#include <SDL2/SDL.h>

namespace flow {
	namespace log {
		void info(std::string msg);
		void warn(std::string msg);
		void error(std::string msg);
		void debug(std::string msg);

		// special functions
		// logs warn when sdl reported error and flow fixed it somehow.
		void sdl_fix_warn(std::string error_source, std::string fix_way, const char* sdl_error_msg);
		// logs flow debug if is_debugging flag is set.
		void flow_debug(bool is_debugging, std::string msg);
	}
}