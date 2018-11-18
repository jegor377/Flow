struct EntityPair {
	int id;
	EntityPtr entity;
};

typedef std::vector<EntityPtr> EntityList;
typedef std::vector<EntityPair> EntityMap;

class EntityCollector {
	EntityList entities;
public:

	friend class Flow;

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
		bool found_at_least_one = false;
		try{
			while(true) {
				auto found_entity = this->find_first_by_group(group);
				found_at_least_one = true;
				this->entities.erase(this->entities.begin()+found_entity.id);
			}
		} catch(exception::EntityFindByGroup& e) {
			if(!found_at_least_one) throw e;
			return;
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

	// TODO: change name
	EntityList sort() {
		EntityList result = this->entities;
		std::sort(result.begin(), result.end(), [](EntityPtr& e1, EntityPtr& e2){
			const double e1_y_point = (e1->collider.y+e1->collider.h*e1->scale.y/2);
			const double e2_y_point = (e2->collider.y+e2->collider.h*e2->scale.y/2);
			if(e1->is_in_xy_collision(e2)) {
				return e1->collider.z <= e2->collider.z;
			}
			return e1_y_point > e2_y_point;
		});
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

	/**
	 *  \brief Finds first entity that belongs to the specified group.
	 *
	 *  \param group Entities' group name.
	 *  \return Pair of entity's pointer and it's poisition in Entity Collector.
	 */
	EntityPair find_first_by_group(const std::string& group) {
		for(int entity_id = 0; entity_id < this->entities.size(); entity_id++) {
			if(this->entities[entity_id]->is_in_group(group)) {
				return EntityPair{entity_id, this->entities[entity_id]};
			}
		}
		throw exception::EntityFindByGroup(group);
	}
};