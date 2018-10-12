namespace flow {
	namespace exception {
		class NullString: public std::exception {
			std::string method_name;
			std::string additional_info;
		public:
			NullString(std::string method_name, std::string additional_info="") {
				this->method_name = method_name;
				this->additional_info = additional_info;
			}

			const char* what() const throw() {
				std::string err_msg = "Given string (char*) in method with name \"" + this->method_name + "\" is NULL. " + additional_info;
				return err_msg.c_str();
			}
		};
	}
}