namespace flow {
	class SpriteCollector {
		std::vector<Sprite*> sprites;
	public:

		~SpriteCollector() {
			for(auto sprite : sprites) {
				delete sprite;
			}
		}

		void add(const Renderer canvas, const char* name, const char* path) {
			auto sprite = new Sprite(name, path);
			this->sprites.push_back(sprite);
			this->load_sprite(canvas, sprite);
		}

		void remove(const char* name) {
			;
		}

		Sprite* get(const char* name) {
			;
		}
	private:
		void load_sprite(const Renderer canvas, Sprite* sprite) {
			sprite->texture = IMG_LoadTexture(canvas, sprite->path);
			if(sprite->texture == NULL) throw exception::SpriteLoad(sprite->name, sprite->path, SDL_GetError());
		}
	};
}