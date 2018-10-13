namespace flow {
	typedef std::vector<SpritePtr> SpriteList;
	
	class SpriteCollector {
		SpriteList sprites;
	public:

		~SpriteCollector() {
			sprites.clear();
		}

		void add(const Renderer canvas, const std::string& name, const std::string& path) {
			auto sprite = std::make_shared<Sprite>(name, path);
			this->sprites.push_back(sprite);
			this->load_sprite(canvas, sprite);
		}

		void remove(const std::string& name) {
			this->sprites.erase(this->find(name));
		}

		SpritePtr get(const std::string& name) {
			return *(this->find(name));
		}
	private:
		void load_sprite(const Renderer canvas, SpritePtr sprite) {
			sprite->texture = IMG_LoadTexture(canvas, sprite->path.c_str());
			if(sprite->texture == NULL) throw exception::SpriteLoad(sprite->name, sprite->path, SDL_GetError());
		}

		SpriteList::iterator find(const std::string& name) {
			auto sprite_iterator = std::find_if(this->sprites.begin(), this->sprites.end(), [name](SpritePtr e){
				return e->has_name(name);
			});
			if(sprite_iterator != this->sprites.end()) {
				return sprite_iterator;
			}
			throw exception::SpriteFind(name);
		}
	};
}