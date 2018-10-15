namespace flow {
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
		bool is_handling_collisions;

		Vector scale;
	private:
		void set_default() {
			this->scale = Vector(1, 1, 1);
			this->is_handling_rendering = true;
			this->is_handling_update = true;
			this->is_handling_events = true;
			this->is_handling_collisions = true;
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
		virtual void collision(std::shared_ptr<Entity> body) = 0;

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

		bool is_in_xy_collision(std::shared_ptr<Entity> body) {
			Rect other_scaled_rect = body->collider;
			other_scaled_rect.mul_size_by_scale(body->scale);
			Rect this_scaled_rect = this->collider;
			this_scaled_rect.mul_size_by_scale(this->scale);
			return this_scaled_rect.is_in_xy_collision(other_scaled_rect);
		}

		bool is_in_xz_collision(std::shared_ptr<Entity> body) {
			Rect other_scaled_rect = body->collider;
			other_scaled_rect.mul_size_by_scale(body->scale);
			Rect this_scaled_rect = this->collider;
			this_scaled_rect.mul_size_by_scale(this->scale);
			return this_scaled_rect.is_in_xz_collision(other_scaled_rect);
		}
	};

	typedef std::shared_ptr<Entity> EntityPtr;
}