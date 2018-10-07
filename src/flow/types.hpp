typedef SDL_Window* Window;
typedef SDL_Renderer* Renderer;
typedef std::vector<flow::Entity*> EntityList;

namespace flow {
	class EntityCollector {
		EntityList entities;
	public:
		
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