#pragma once

#include <exception>
#include <string>
#include "../logger/logger.hpp"

namespace flow {
	namespace exception {
		class Window: public std::exception {
			const char* sdl_err_msg;

		public:
			Window(bool is_debugging, std::string err_msg, const char* sdl_err_msg);

			virtual const char* what() const throw();
		};
	}
}