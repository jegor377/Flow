enum RectMode {
	SECTION = 0,
	FULL = 1
};

// TODO: Add division by 0 exception.
class Rect2 : public Point2, public Size2 {
	SDL_Rect sdl_representation;
public:
	RectMode mode;

	Rect2(double x=0, double y=0, double w=0, double h=0, RectMode mode=FULL) : Point2(x, y), Size2(w, h) {
		this->mode = mode;
	};

	Rect2(const Rect2& other) {
		this->x = other.x;
		this->y = other.y;
		this->w = other.w;
		this->h = other.h;
		this->mode = other.mode;
	}

	std::string to_string() {
		return "Rect2{x: "+std::to_string(this->x)+", y: "+std::to_string(this->y)+", w: "+std::to_string(this->w)+", h: "+std::to_string(this->h)+", mode: "+(this->mode == SECTION ? "SECTION" : "FULL")+"}";
	}

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

	Rect2 operator+(Rect2& other) {
		return Rect2(this->x + other.x, this->y + other.y, this->w + other.w, this->h + other.h, this->mode);
	}

	Rect2 operator-(Rect2& other) {
		return Rect2(this->x - other.x, this->y - other.y, this->w - other.w, this->h - other.h, this->mode);
	}

	Rect2 operator*(Rect2& other) {
		return Rect2(this->x * other.x, this->y * other.y, this->w * other.w, this->h *+ other.h, this->mode);
	}

	Rect2 operator/(Rect2& other) {
		return Rect2(this->x / other.x, this->y / other.y, this->w / other.w, this->h / other.h, this->mode);
	}

	void operator+=(Rect2& other) {
		this->Point2::operator+=( *(Point2*)(&other) );
		this->Size2::operator+=( *(Size2*)(&other) );
	}

	void operator-=(Rect2& other) {
		this->Point2::operator-=( *(Point2*)(&other) );
		this->Size2::operator-=( *(Size2*)(&other) );
	}

	void operator*=(Rect2& other) {
		this->Point2::operator*=( *(Point2*)(&other) );
		this->Size2::operator*=( *(Size2*)(&other) );
	}

	void operator/=(Rect2& other) {
		this->Point2::operator/=( *(Point2*)(&other) );
		this->Size2::operator/=( *(Size2*)(&other) );
	}

	Rect2 operator+(double val) {
		return Rect2(this->x + val, this->y + val, this->w + val, this->h + val, this->mode);
	}

	Rect2 operator-(double val) {
		return Rect2(this->x - val, this->y - val, this->w - val, this->h - val, this->mode);
	}

	Rect2 operator*(double val) {
		return Rect2(this->x * val, this->y * val, this->w * val, this->h * val, this->mode);
	}

	Rect2 operator/(double val) {
		return Rect2(this->x / val, this->y / val, this->w / val, this->h / val, this->mode);
	}

	void operator+=(double val) {
		this->Point2::operator+=( val );
		this->Size2::operator+=( val );
	}

	void operator-=(double val) {
		this->Point2::operator-=( val );
		this->Size2::operator-=( val );
	}

	void operator*=(double val) {
		this->Point2::operator*=( val );
		this->Size2::operator*=( val );
	}

	void operator/=(double val) {
		this->Point2::operator/=( val );
		this->Size2::operator/=( val );
	}

	// Returns true if all position and size values are equal. Doesn't take mode into account.
	bool is_vequal(Rect2& other) {
		return this->Point2::is_equal( *(Point2*)(&other) ) && this->Size2::is_equal( *(Size2*)(&other) );
	}

	// Returns true if all position, size and mode values are equal. Takes mode into account.
	bool is_equal(Rect2& other) {
		return this->is_vequal(other) && this->mode == other.mode;
	}

	// Returns true if all position, size are equal to value.
	bool is_equal(double val) {
		return this->Point2::is_equal( val ) && this->Size2::is_equal( val );
	}

	bool operator==(Rect2& other) {
		return this->is_equal(other);
	}

	bool operator!=(Rect2& other) {
		return !this->is_equal(other);
	}

	bool operator==(double val) {
		return this->is_equal(val);
	}

	bool operator!=(double val) {
		return !this->is_equal(val);
	}

	void set_pos(const Point2& new_pos) {
		this->x = new_pos.x;
		this->y = new_pos.y;
	}

	void set_size(const Size2& new_size) {
		this->w = new_size.w;
		this->h = new_size.h;
	}

	void operator+=(Point2& pos) {
		this->Point2::operator+=( pos );
	}

	void operator-=(Point2& pos) {
		this->Point2::operator-=( pos );
	}

	void operator*=(Point2& pos) {
		this->Point2::operator*=( pos );
	}

	void operator/=(Point2& pos) {
		this->Point2::operator/=( pos );
	}

	void operator+=(Size2& size) {
		this->Size2::operator+=( size );
	}

	void operator-=(Size2& size) {
		this->Size2::operator-=( size );
	}

	void operator*=(Size2& size) {
		this->Size2::operator*=( size );
	}

	void operator/=(Size2& size) {
		this->Size2::operator/=( size );
	}

	void add_pos(Point2& other) {
		this->x += other.x;
		this->y += other.y;
	}

	void sub_pos(Point2& other) {
		this->x -= other.x;
		this->y -= other.y;
	}

	void mul_pos(Point2& other) {
		this->x *= other.x;
		this->y *= other.y;
	}

	void div_pos(Point2& other) {
		this->x /= other.x;
		this->y /= other.y;
	}

	void add_size(Size2& other) {
		this->w += other.w;
		this->h += other.h;
	}

	void sub_size(Size2& other) {
		this->w -= other.w;
		this->h -= other.h;
	}

	void mul_size(Size2& other) {
		this->w *= other.w;
		this->h *= other.h;
	}

	void div_size(Size2& other) {
		this->w /= other.w;
		this->h /= other.h;
	}
};

Rect2 operator+(double val, Rect2& src) {
	return src+val;
}
Rect2 operator*(double val, Rect2& src) {
	return src*val;
}

struct Rect : public Point, public Size {
public:
	Rect(double x=0, double y=0, double z=0, double w=0, double h=0, double l=0) : Point(x, y, z), Size(w, h, l) {};

	std::string to_string() {
		return "Rect{x: "+std::to_string(this->x)+", y: "+std::to_string(this->y)+", z: "+std::to_string(this->z)+", w: "+std::to_string(this->w)+", h: "+std::to_string(this->h)+", l: "+std::to_string(this->l)+"}";
	}

	Rect operator+(Rect& other) {
		return Rect(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w, this->h + other.h, this->l + other.l);
	}

	Rect operator-(Rect& other) {
		return Rect(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w, this->h - other.h, this->l - other.l);
	}

	Rect operator*(Rect& other) {
		return Rect(this->x * other.x, this->y * other.y, this->z * other.z, this->w * other.w, this->h *+ other.h, this->l * other.l);
	}

	Rect operator/(Rect& other) {
		return Rect(this->x / other.x, this->y / other.y, this->z / other.z, this->w / other.w, this->h / other.h, this->l / other.l);
	}

	void operator+=(Rect& other) {
		this->Point::operator+=( *(Point*)(&other) );
		this->Size::operator+=( *(Size*)(&other) );
	}

	void operator-=(Rect& other) {
		this->Point::operator-=( *(Point*)(&other) );
		this->Size::operator-=( *(Size*)(&other) );
	}

	void operator*=(Rect& other) {
		this->Point::operator*=( *(Point*)(&other) );
		this->Size::operator*=( *(Size*)(&other) );
	}

	void operator/=(Rect& other) {
		this->Point::operator/=( *(Point*)(&other) );
		this->Size::operator/=( *(Size*)(&other) );
	}

	Rect operator+(double val) {
		return Rect(this->x + val, this->y + val, this->z + val, this->w + val, this->h + val, this->l + val);
	}

	Rect operator-(double val) {
		return Rect(this->x - val, this->y - val, this->z - val, this->w - val, this->h - val, this->l - val);
	}

	Rect operator*(double val) {
		return Rect(this->x * val, this->y * val, this->z * val, this->w * val, this->h * val, this->l * val);
	}

	Rect operator/(double val) {
		return Rect(this->x / val, this->y / val, this->z / val, this->w / val, this->h / val, this->l / val);
	}

	void operator+=(double val) {
		this->Point::operator+=( val );
		this->Size::operator+=( val );
	}

	void operator-=(double val) {
		this->Point::operator-=( val );
		this->Size::operator-=( val );
	}

	void operator*=(double val) {
		this->Point::operator*=( val );
		this->Size::operator*=( val );
	}

	void operator/=(double val) {
		this->Point::operator/=( val );
		this->Size::operator/=( val );
	}

	bool is_equal(Rect& other) {
		return this->Point::is_equal( *(Point*)(&other) ) && this->Size::is_equal( *(Size*)(&other) );
	}

	// Returns true if all position, size are equal to value.
	bool is_equal(double val) {
		return this->Point::is_equal( val ) && this->Size::is_equal( val );
	}

	bool operator==(Rect& other) {
		return this->is_equal(other);
	}

	bool operator!=(Rect& other) {
		return !this->is_equal(other);
	}

	bool operator==(double val) {
		return this->is_equal(val);
	}

	bool operator!=(double val) {
		return !this->is_equal(val);
	}

	void operator+=(Point& pos) {
		this->Point::operator+=( pos );
	}

	void operator-=(Point& pos) {
		this->Point::operator-=( pos );
	}

	void operator*=(Point& pos) {
		this->Point::operator*=( pos );
	}

	void operator/=(Point& pos) {
		this->Point::operator/=( pos );
	}

	void operator+=(Size& size) {
		this->Size::operator+=( size );
	}

	void operator-=(Size& size) {
		this->Size::operator-=( size );
	}

	void operator*=(Size& size) {
		this->Size::operator*=( size );
	}

	void operator/=(Size& size) {
		this->Size::operator/=( size );
	}

	void add_val(double x) {
		this->x += x;
		this->y += x;
		this->z += x;
	}

	void sub_val(double x) {
		this->x -= x;
		this->y -= x;
		this->z -= x;
	}

	void mul_by_val(double x) {
		this->x *= x;
		this->y *= x;
		this->z *= x;
	}

	void div_by_val(double x) {
		this->x /= x;
		this->y /= x;
		this->z /= x;
	}

	void add_pos(Rect& other) {
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}

	void add_vector(Vector& other) {
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}

	void sub_pos(Rect& other) {
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
	}

	void sub_vector(Vector& other) {
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
	}

	void mul_pos(Rect& other) {
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
	}

	void mul_by_vector(Vector& other) {
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
	}

	void div_pos(Rect& other) {
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
	}

	void div_by_vector(Vector& other) {
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

	void mul_size_by_vector(Vector& other) {
		this->w *= other.x;
		this->h *= other.y;
		this->l *= other.z;
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

	Rect2* to_scaled_rect2(Vector scale) {
		Rect2* result = new Rect2(this->x, this->y+this->z, this->w*scale.x, (this->h*scale.y)+(this->l*scale.z), SECTION);
		return result;
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
		return this->x < other.x + other.w && this->x + this->w > other.x && this->y < other.y + other.h && this->y + this->h > other.y && this->z < other.z + other.l && this->z + this->l > other.z;
	}

	bool is_colliding_with_point(Point& pt) {
		bool is_x_collision = this->x<=pt.x && this->x+this->w>=pt.x;
		bool is_y_collision = this->y<=pt.y && this->y+this->h>=pt.y;
		bool is_z_collision = this->z<=pt.z && this->z+this->l>=pt.z;
		return is_x_collision && is_y_collision && is_z_collision;
	}

	bool is_in_xy_collision(Rect& other) {
		return this->x < other.x + other.w && this->x + this->w > other.x && this->y < other.y + other.h && this->y + this->h > other.y;
	}

	bool is_in_xz_collision(Rect& other) {
		return this->x < other.x + other.w && this->x + this->w > other.x && this->z < other.z + other.l && this->z + this->l > other.z;
	}
};

Rect operator+(double val, Rect& src) {
	return src+val;
}
Rect operator*(double val, Rect& src) {
	return src*val;
}