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
}