#pragma once

#include <exception>

namespace flow {
	namespace exception {
		class Init: public std::exception {
			const char* sdl_err_msg;

		public:
			Init(const char* sdl_err_msg);

			virtual const char* what() const throw();
		};
	}
}