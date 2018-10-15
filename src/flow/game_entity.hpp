namespace flow {
	class GameEntity : public Entity {
	public:
		Flow* engine;

		GameEntity(Flow* engine) : Entity() {
			this->engine = engine;
		}

		GameEntity(Flow* engine, Rect collider, const std::string& name, const std::string& group) : Entity(collider, name, group) {
			this->engine = engine;
		}

		virtual void update(double delta) = 0;
		virtual void event(SDL_Event event) = 0;
		virtual void collision(EntityPtr body) = 0;
	};
}