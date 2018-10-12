namespace flow {
	namespace exception {
		class Window: public std::exception {
			std::string err_msg;

		public:
			//TODO: Find out why it doesn't work.
			Window(std::string err_msg, const char* sdl_err_msg) {
				this->err_msg = err_msg + ". SDL2 error message: " + std::string(sdl_err_msg) + ".";
			}

			const char* what() const throw() {
				return this->err_msg.c_str();
			}
		};
	}
}