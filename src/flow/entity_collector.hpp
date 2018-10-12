namespace flow {
	class EntityCollector {
		EntityList entities;
	public:

		~EntityCollector() {
			for(auto entity : entities) {
				delete entity;
			}
		}
		
		/**
		 *  \brief Adds new entity to the collector.
		 *
		 *  \param entity New entity handler.
		 */
		void add(Entity* entity) {
			this->entities.push_back(entity);
		}

		/**
		 *  \brief Removes the first entity that possesses specified name.
		 *
		 *  \param name Entity's name.
		 */
		void remove_by_name(char* name) {
			this->entities.erase(this->find_by_name(name));
		}

		/**
		 *  \brief Removes all entites that belongs to the specified group.
		 *
		 *  \param group Entities' group name.
		 */
		void remove_by_group(char* group) {
			auto found_entities = this->find_by_group(group);
			for(auto entity : found_entities) {
				this->entities.erase(this->entities.begin()+entity.id);
			}
		}

		/**
		 *  \brief Finds the first entity that possesses specified name.
		 *
		 *  \param name Entity's name.
		 *  \return Entity's pointer.
		 */
		Entity* get_by_name(char* name) {
			auto result = this->find_by_name(name);
			return *result;
		}

		/**
		 *  \brief Finds all entites that belongs to the specified group.
		 *
		 *  \param group Entities' group name.
		 *  \return Map of entities' pointers and it's poisitions in Entity Collector.
		 */
		EntityMap get_by_group(char* group) {
			return find_by_group(group);
		}

	private:
		/**
		 *  \brief Finds the first entity that possesses specified name.
		 *
		 *  \param name Entity's name.
		 *  \return Entity's iterator from Entity Collector entities list.
		 */
		EntityList::iterator find_by_name(char* name) {
			if(name == NULL) {
				std::string additional_info = "It can happen when you have specified a NULL (char*) pointer to one of EntityCollector searching methods. I.e get_by_name or remove_by_name.";
				throw exception::NullString("find_by_name", additional_info);
			}
			auto entity_iterator = std::find_if(this->entities.begin(), this->entities.end(), [name](Entity* e){
				return strcmp(e->get_name(), name) == 0;
			});
			if(entity_iterator != this->entities.end()) {
				return entity_iterator;
			}
			throw exception::EntityFindByName(name);
		}

		/**
		 *  \brief Finds all entites that belongs to the specified group.
		 *
		 *  \param group Entities' group name.
		 *  \return Map of entities' pointers and it's poisitions in Entity Collector.
		 */
		EntityMap find_by_group(char* group) {
			EntityMap result;
			if(group == NULL) {
				std::string additional_info = "It can happen when you have specified a NULL (char*) pointer to one of EntityCollector searching methods. I.e get_by_group or remove_by_group.";
				throw exception::NullString("find_by_group", additional_info);
			}
			for(int entity_id = 0; entity_id < this->entities.size(); entity_id++) {
				if(strcmp(this->entities[entity_id]->get_group(), group) == 0) {
					EntityPair new_pair = {entity_id, this->entities[entity_id]};
					result.push_back(new_pair);
				}
			}
			if(result.size()==0) throw exception::EntityFindByGroup(group);
			return result;
		}
	};
}