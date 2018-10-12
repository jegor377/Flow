namespace flow {
	namespace exception {
		class Init: public std::exception {
			std::string err_msg;

		public:
			Init(const char* sdl_err_msg) {
				this->err_msg = "Cannot to init due to SDL2 error: " + std::string(sdl_err_msg) + ".";
			}

			const char* what() const throw() {
				return this->err_msg.c_str();
			}
		};
	}
}