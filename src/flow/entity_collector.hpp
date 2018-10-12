namespace flow {
	class EntityCollector {
		EntityList entities;
	public:

		~EntityCollector() {
			for(auto entity : entities) {
				delete entity;
			}
		}
		
		void add(Entity* entity) {
			this->entities.push_back(entity);
		}

		void remove_by_name(char* name) {
			;
		}

		void remove_by_group(char* group) {
			;
		}

		// Returns first by name or raises an exception if no found.
		Entity* get_by_name(char* name) {
			;
		}

		EntityList get_by_group(char* group) {
			;
		}
	};
}