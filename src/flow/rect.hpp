namespace flow {
	enum RectMode {
		SECTION = 0,
		FULL = 1
	};

	class Rect2 : public Point2, public Size2 {
		SDL_Rect sdl_representation;
	public:
		RectMode mode;

		Rect2(double x=0, double y=0, double w=0, double h=0, RectMode mode=FULL) : Point2(x, y), Size2(w, h) {
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

		void set_pos(const Point2& new_pos) {
			this->x = new_pos.x;
			this->y = new_pos.y;
		}

		void set_size(const Size2& new_size) {
			this->w = new_size.w;
			this->h = new_size.h;
		}

		void add_pos(Rect2& other) {
			this->x += other.x;
			this->y += other.y;
		}

		void sub_pos(Rect2& other) {
			this->x -= other.x;
			this->y -= other.y;
		}

		void mul_pos(Rect2& other) {
			this->x *= other.x;
			this->y *= other.y;
		}

		void div_pos(Rect2& other) {
			this->x /= other.x;
			this->y /= other.y;
		}

		void add_size(Rect2& other) {
			this->w += other.w;
			this->h += other.h;
		}

		void sub_size(Rect2& other) {
			this->w -= other.w;
			this->h -= other.h;
		}

		void mul_size(Rect2& other) {
			this->w *= other.w;
			this->h *= other.h;
		}

		void div_size(Rect2& other) {
			this->w /= other.w;
			this->h /= other.h;
		}
	};

	struct Rect : public Point, public Size {
	public:
		Rect(double x=0, double y=0, double z=0, double w=0, double h=0, double l=0) : Point(x, y, z), Size(w, h, l) {};

		void add_pos(Rect& other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
		}

		void sub_pos(Rect& other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
		}

		void mul_pos(Rect& other) {
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
		}

		void div_pos(Rect& other) {
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
		}

		void add_size(Rect& other) {
			this->w += other.w;
			this->h += other.h;
			this->l += other.l;
		}

		void sub_size(Rect& other) {
			this->w -= other.w;
			this->h -= other.h;
			this->l -= other.l;
		}

		void mul_size(Rect& other) {
			this->w *= other.w;
			this->h *= other.h;
			this->l *= other.l;
		}

		void div_size(Rect& other) {
			this->w /= other.w;
			this->h /= other.h;
			this->l /= other.l;
		}

		Rect2* to_rect2() {
			Rect2* result = new Rect2(this->x, this->y+this->z, this->w, this->h+this->l, SECTION);
			return result;
		}

		Rect2* to_scaled_rect2(double scale) {
			Rect2* result = this->to_rect2();
			result->w *= scale;
			result->h *= scale;
		}

		void set_pos(const Point& new_pos) {
			this->x = new_pos.x;
			this->y = new_pos.y;
			this->z = new_pos.z;
		}

		void set_size(const Size& new_size) {
			this->w = new_size.w;
			this->h = new_size.h;
			this->l = new_size.l;
		}

		bool is_colliding(Rect& other) {
			return false;
		}

		bool is_colliding_with_point(Point& pt) {
			return false;
		}
	};
}