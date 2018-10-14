namespace flow {
	class SharedSprite {
	public:
		SpritePtr sprite;
		Rect2 source_section;
		double scale;

		SharedSprite() {
			this->scale = 1;
			this->sprite.reset();
		}

		SharedSprite(SpritePtr sprite) {
			this->scale = 1;
			this->sprite = sprite;
		}

		SharedSprite(SpritePtr sprite, Rect2 source_section) {
			this->scale = 1;
			this->sprite = sprite;
			this->source_section = source_section;
		}

		const Size2* get_size() {
			if(this->sprite) return this->sprite->get_size();
			throw exception::SpriteAssign();
		}

		const std::string get_name() {
			if(this->sprite) return this->sprite->get_name();
			throw exception::SpriteAssign();
		}

		const std::string get_path() {
			if(this->sprite) return this->sprite->get_path();
			throw exception::SpriteAssign();
		}

		bool has_name(const std::string& name) {
			if(this->sprite) return this->sprite->has_name(name);
			throw exception::SpriteAssign();
		}
	};
}