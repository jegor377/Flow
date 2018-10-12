namespace flow {
	namespace exception {
		class EntityFindByName: public std::exception {
			std::string err_msg;
		public:
			EntityFindByName(char* name) {
				std::string name_str = name;
				if(name == NULL) name_str = "NULL";
				
				this->err_msg = "Entity with name \"" + name_str + "\" not found.";
			}

			const char* what() const throw() {
				return this->err_msg.c_str();
			}
		};

		class EntityFindByGroup: public std::exception {
			std::string err_msg;
		public:
			EntityFindByGroup(char* group) {
				std::string group_name = group;
				if(group == NULL) group_name = "NULL";

				this->err_msg = "Entity with group name \"" + group_name + "\" not found.";
			}

			const char* what() const throw() {
				return this->err_msg.c_str();
			}
		};
	}
}