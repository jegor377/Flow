namespace flow {
	class Entity {
	protected:
		Point pos;
		Size size;
		
		char* name;
		char* group;
	public:
		Entity() {}
	
		Entity(Point pos, Size size, char* name, char* group) {
			this->pos   = pos;
			this->size  = size;
			this->name  = name;
			this->group = group;
		}

		Entity(const Entity& copy_entity) {
			strcpy(this->name, copy_entity.name);
			strcpy(this->group, copy_entity.group);
		}
		
		void render(SDL_Renderer* canvas) {
			;
		}

		virtual void update(double delta) = 0;
		virtual void event(SDL_Event* event) = 0;
		virtual void collision(Entity& body) = 0;
	};
}