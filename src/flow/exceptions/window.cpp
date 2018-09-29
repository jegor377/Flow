#include "./window.hpp"

namespace flow {
	namespace exception {
		Window::Window(bool is_debugging, std::string err_msg, const char* sdl_err_msg) {
			this->sdl_err_msg = std::string(err_msg+". SDL2 error message: "+std::string(sdl_err_msg)+".").c_str();
			log::flow_debug(is_debugging, std::string(sdl_err_msg));
		}

		const char* Window::what() const throw() {
			return this->sdl_err_msg;
		}
	}
}