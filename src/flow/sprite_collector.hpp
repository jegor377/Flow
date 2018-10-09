namespace flow {
	class Sprite {
		SDL_Texture* texture;
		const char* name;
		const char* path;

	public:
		Sprite(const char* name, const char* path) {
			this->texture = NULL;
			this->name = name;
			this->path = path;
		}

		~Sprite() {
			this->remove_sprite();
		}
	private:
		void remove_sprite() {
			if(this->texture != NULL) {
				SDL_DestroyTexture(this->texture);
				this->texture = NULL;
			}
		}
	public:
		friend void load_sprite(Sprite* sprite);
		friend void draw(Sprite* sprite);
	};

	class SpriteCollector {
		std::vector<Sprite*> sprites;
		Renderer canvas;
	public:

		SpriteCollector(Renderer canvas) {
			this->canvas = canvas;
		}
		~SpriteCollector() {
			for(auto sprite : sprites) {
				delete sprite;
			}
		}

		void add(const char* name, const char* path) {
			auto sprite = new Sprite(name, path);
			this->sprites.push_back(sprite);
			this->load_sprite(sprite);
		}

		void remove(const char* name) {
			;
		}

		Sprite* get(const char* name) {
			;
		}
	private:
		void load_sprite(Sprite* sprite) {
			sprite->texture = IMG_LoadTexture(this->canvas, sprite->path);
			if(sprite->texture == NULL) throw exception::SpriteLoad(sprite->name, sprite->path, SDL_GetError());
		}
	};
}