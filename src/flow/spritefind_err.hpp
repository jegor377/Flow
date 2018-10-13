namespace flow {
	namespace exception {
		class SpriteFind: public std::exception {
			std::string err_msg;
		public:
			SpriteFind(const std::string& name) {
				this->err_msg = "Sprite with name \"" + name + "\" not found.";
			}

			const char* what() const throw() {
				return this->err_msg.c_str();
			}
		};
	}
}