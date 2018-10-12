namespace flow {
	enum RectMode {
		SECTION = 0,
		FULL = 1
	};

	class Rect2 : public Point2, Size2 {
		SDL_Rect sdl_representation;
	public:
		RectMode mode;

		Rect2(int x=0, int y=0, int w=0, int h=0, RectMode mode=FULL) : Point2(x, y), Size2(w, h) {
			this->mode = mode;
		};

		SDL_Rect* get_sdl_rect() {
			if(this->mode == SECTION) {
				this->sdl_representation.x = this->x;
				this->sdl_representation.y = this->y;
				this->sdl_representation.w = this->w;
				this->sdl_representation.h = this->h;
				return &this->sdl_representation;
			}
			return NULL;
		}
	};

	struct Rect : public Point, Size {
	public:
		Rect(int x=0, int y=0, int z=0, int w=0, int h=0, int l=0) : Point(x, y, z), Size(w, h, l) {};

		bool is_colliding(const Rect& other) {
			return false;
		}

		bool is_colliding_with_point(const Point& pt) {
			return false;
		}
	};
}