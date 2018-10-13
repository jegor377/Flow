namespace flow {
	class Entity {
	protected:
		Point pos;
		Size size;
		
		std::string name;
		std::string group;
	public:
		SharedSprite shared_sprite;
		
		bool is_handling_rendering;
		bool is_handling_update;
		bool is_handling_events;
		bool is_handling_collisions;
	private:
		void set_default() {
			this->is_handling_rendering = true;
			this->is_handling_update = true;
			this->is_handling_events = true;
			this->is_handling_collisions = true;
		}

	public:
		Entity() {
			this->set_default();
		}
	
		Entity(Point pos, Size size, const std::string& name, const std::string& group) {
			this->pos   = pos;
			this->size  = size;
			this->name  = name;
			this->group = group;
			this->set_default();
		}
		
		virtual void update(double delta) = 0;
		virtual void event(SDL_Event* event) = 0;
		virtual void collision(Entity& body) = 0;

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
	};

	typedef std::shared_ptr<Entity> EntityPtr;
}