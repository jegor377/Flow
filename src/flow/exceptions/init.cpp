#include "./init.hpp"

namespace flow {
	namespace exception {
		Init::Init(const char* sdl_err_msg) {
			this->sdl_err_msg = sdl_err_msg;
		}

		const char* Init::what() const throw() {
			return this->sdl_err_msg;
		}
	}
}