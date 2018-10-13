namespace flow {
	class Sprite {
		SDL_Texture* texture;
		std::string name;
		std::string path;

	public:
		Sprite(const std::string& name, const std::string& path) {
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

		const Size2* get_size() {
			if(this->texture != NULL) {
				int w, h;
				SDL_QueryTexture(this->texture, NULL, NULL, &w, &h);
				return new Size2(w, h);
			} else return NULL;
		}

		const std::string get_name() {
			return this->name;
		}

		const std::string get_path() {
			return this->path;
		}

		bool has_name(const std::string& name) {
			return this->name == name;
		}
	};

	typedef std::shared_ptr<Sprite> SpritePtr;
}