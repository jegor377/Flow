struct EntityPair {
	int id;
	EntityPtr entity;
};

typedef std::vector<EntityPtr> EntityList;
typedef std::vector<EntityPair> EntityMap;

class EntityCollector {
	EntityList entities;
public:

	//friend class Flow; Remove it in next commit if it doesn't displays errors when compiling.

	~EntityCollector() {
		entities.clear();
	}
	
	/**
	 *  \brief Adds new entity to the collector.
	 *
	 *  \param entity New entity handler.
	 */
	void add(EntityPtr entity) {
		this->entities.push_back(entity);
	}

	EntityList& get_list() {
		return this->entities;
	}

	/**
	 *  \brief Returns size of entities list.
	 *
	 */
	unsigned int size() {
		return this->entities.size();
	}

	/**
	 *  \brief Removes the first entity that possesses specified name.
	 *
	 *  \param name Entity's name.
	 */
	void remove_by_name(const std::string& name) {
		this->entities.erase(this->find_by_name(name));
	}

	/**
	 *  \brief Removes all entites that belongs to the specified group.
	 *
	 *  \param group Entities' group name.
	 */
	void remove_by_group(const std::string& group) {
		auto found_entities = this->find_by_group(group);
		for(int i = found_entities.size()-1; i >= 0; i--) {
			this->entities.erase(this->entities.begin()+found_entities[i].id);
		}
	}

	/**
	 *  \brief Finds the first entity that possesses specified name.
	 *
	 *  \param name Entity's name.
	 *  \return Entity's shared pointer.
	 */
	EntityPtr get_by_name(const std::string& name) {
		auto result = this->find_by_name(name);
		return *result;
	}

	/**
	 *  \brief Finds all entites that belongs to the specified group.
	 *
	 *  \param group Entities' group name.
	 *  \return Map of entities' pointers and it's poisitions in Entity Collector.
	 */
	EntityMap get_by_group(const std::string& group) {
		return find_by_group(group);
	}

	EntityList get_sorted_for_display() {
		EntityList result = this->entities; // DON'T CHANGE THIS. IT HAS TO BE PASSED WITH RESULT.
		std::sort(result.begin(), result.end(), [](EntityPtr& e1, EntityPtr& e2){
			const double e1_y_point = (e1->collider.y+e1->collider.h*e1->scale.y/2);
			const double e2_y_point = (e2->collider.y+e2->collider.h*e2->scale.y/2);
			if(e1->is_in_xy_collision(e2)) {
				return e1->collider.z <= e2->collider.z;
			}
			return e1_y_point > e2_y_point;
		});
		// It's sorting entities based on theirs z and y. If an entity is farther from the player it's displayed first.
		// Otherwise it displays what is under something first.
		return result;
	}

private:
	/**
	 *  \brief Finds the first entity that possesses specified name.
	 *
	 *  \param name Entity's name.
	 *  \return Entity's iterator from Entity Collector entities list.
	 */
	EntityList::iterator find_by_name(const std::string& name) {
		auto entity_iterator = std::find_if(this->entities.begin(), this->entities.end(), [name](EntityPtr e){
			return e->has_name(name);
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
	EntityMap find_by_group(const std::string& group) {
		EntityMap result;
		for(int entity_id = 0; entity_id < this->entities.size(); entity_id++) {
			if(this->entities[entity_id]->is_in_group(group)) {
				EntityPair new_pair = {entity_id, this->entities[entity_id]};
				result.push_back(new_pair);
			}
		}
		if(result.size()==0) throw exception::EntityFindByGroup(group);
		return result;
	}
};