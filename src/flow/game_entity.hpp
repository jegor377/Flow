namespace flow {
	class GameEntity : public Entity {
	public:
		Flow* engine;

		GameEntity(Flow* engine) : Entity() {
			this->engine = engine;
		}

		GameEntity(Flow* engine, Point pos, Size size, char* name, char* group) : Entity(pos, size, name, group) {
			this->engine = engine;
		}

		virtual void update(double delta) = 0;
		virtual void event(SDL_Event* event) = 0;
		virtual void collision(Entity& body) = 0;
	};
}