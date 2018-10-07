namespace flow {
	namespace exception {
		class Init: public std::exception {
			const char* sdl_err_msg;

		public:
			Init(const char* sdl_err_msg) {
				this->sdl_err_msg = sdl_err_msg;
			}

			const char* what() const throw() {
				return this->sdl_err_msg;
			}
		};
	}
}