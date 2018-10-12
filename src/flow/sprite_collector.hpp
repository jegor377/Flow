namespace flow {
	class Sprite {
		SDL_Texture* texture;
		const char* name;
		const char* path;

	public:
		Rect2 source_section;
		Rect2 destination_section;

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
		friend class SpriteCollector;

		friend void draw(Sprite* sprite);

		Size2* get_size() {
			int w, h;
			SDL_QueryTexture(this->texture, NULL, NULL, &w, &h);
			return new Size2(w, h);
		}

		const char* get_name() {
			return this->name;
		}

		const char* get_path() {
			return this->path;
		}
	};

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