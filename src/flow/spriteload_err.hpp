namespace flow {
	namespace exception {
		class SpriteLoad: public std::exception {
			std::string err_msg;

		public:
			SpriteLoad(const std::string& name, const std::string& path, const char* sdl_err_msg) {
				this->err_msg = "Cannot to load sprite with name \"";
				this->err_msg += name;
				this->err_msg += "\" and path \"";
				this->err_msg += path;
				this->err_msg += "\". SDL error info: ";
				this->err_msg += sdl_err_msg;
				this->err_msg +=".";
			}
			
			const char* what() const throw() {
				return this->err_msg.c_str();
			}
		};
	}
}