namespace exception {
	class EntityFindByName: public std::exception {
		std::string err_msg;
	public:
		EntityFindByName(const std::string& name) {
			this->err_msg = "Entity with name \"" + name + "\" not found.";
		}

		const char* what() const throw() {
			return this->err_msg.c_str();
		}
	};

	class EntityFindByGroup: public std::exception {
		std::string err_msg;
	public:
		EntityFindByGroup(const std::string& group) {
			this->err_msg = "Entity with group name \"" + group + "\" not found.";
		}

		const char* what() const throw() {
			return this->err_msg.c_str();
		}
	};
}