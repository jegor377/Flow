namespace flow {
	namespace exception {
		class SpriteLoad: public std::exception {
			char* err_msg;

		public:
			SpriteLoad(const char* name, const char* path, const char* sdl_err_msg) {
				char* err_msg = new char[strlen("Cannot to load sprite with name \"\" and path \"\". ")+strlen(name)+strlen(path)+strlen(sdl_err_msg)+1];
				strcat(err_msg, "Cannot to load sprite with name \"");
				strcat(err_msg, name);
				strcat(err_msg, "\" and path \"");
				strcat(err_msg, path);
				strcat(err_msg, "\". ");
				strcat(err_msg, sdl_err_msg);
				this->err_msg = err_msg;
			}

			~SpriteLoad() {
				delete err_msg;
			}

			const char* what() const throw() {
				return (const char*)(this->err_msg);
			}
		};
	}
}