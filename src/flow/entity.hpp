class Entity {
protected:
	std::string name;
	std::string group;
public:
	Rect collider;

	SharedSprite shared_sprite;
	
	bool is_handling_rendering;
	bool is_handling_update;
	bool is_handling_events;

	Vector scale;
private:
	void set_default() {
		this->scale = Vector(1, 1, 1);
		this->is_handling_rendering = true;
		this->is_handling_update = true;
		this->is_handling_events = true;
	}

public:
	Entity() {
		this->set_default();
	}

	Entity(Rect collider, const std::string& name, const std::string& group) {
		this->collider = collider;
		this->name = name;
		this->group = group;
		this->set_default();
	}
	
	virtual void update(double delta) = 0;
	virtual void event(SDL_Event event) = 0;

	const std::string get_name() {
		return this->name;
	}

	const std::string get_group() {
		return this->group;
	}

	bool has_name(const std::string& name) {
		return this->name == name;
	}

	bool is_in_group(const std::string& group) {
		return this->group == group;
	}

	Rect get_scaled_collider() {
		Rect result = this->collider;
		result.mul_size_by_vector(this->scale);
		return result;
	}

	bool is_scaled_colliding(std::shared_ptr<Entity> body) {
		Rect other = body->get_scaled_collider();
		return this->get_scaled_collider().is_colliding(other);
	}

	bool is_scaled_colliding(Entity* body) {
		Rect other = body->get_scaled_collider();
		return this->get_scaled_collider().is_colliding(other);
	}

	bool is_in_xy_collision(std::shared_ptr<Entity> body) {
		Rect other = body->get_scaled_collider();
		return this->get_scaled_collider().is_in_xy_collision(other);
	}

	bool is_in_xz_collision(std::shared_ptr<Entity> body) {
		Rect other = body->get_scaled_collider();
		return this->get_scaled_collider().is_in_xz_collision(other);
	}

	void move(Vector& movement) {
		this->collider.add_vector(movement);
	}
};

typedef std::shared_ptr<Entity> EntityPtr;