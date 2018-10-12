namespace flow {
	typedef SDL_Window* Window;
	typedef SDL_Renderer* Renderer;
	typedef std::vector<flow::Entity*> EntityList;

	struct EntityPair {
		int id;
		flow::Entity* entity;
	};
	typedef std::vector<EntityPair> EntityMap;
}