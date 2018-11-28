class Ray : public Point {
	double xy_a;
	double xy_b;
	double xz_a;
	double xz_b;
public:
	/*
	a = (y2-y1)/(x2-x1)
	b = y2-(x2*a)
	*/

	Ray(Vector direction) : Point(0, 0, 0) {
		set_direction(direction);
	};
	Ray(double val, Vector direction) : Point(val, val, val) {
		set_direction(direction);
	};
	Ray(double x, double y, double z, Vector direction) : Point(x, y, z) {
		set_direction(direction);
	};

	std::string to_string() {
		const Vector* direction = this->get_direction();
		std::string ret_str = "Ray{x: "+std::to_string(this->x)+", y: "+std::to_string(this->y)+", z: "+std::to_string(this->z)+", direction(Vector):{x: "+std::to_string(direction->x)+", y: "+std::to_string(direction->y)+", z: "+std::to_string(direction->z)+"}, xy_a: "+std::to_string(this->xy_a)+", xy_b: "+std::to_string(this->xy_b)+", xz_a: "+std::to_string(this->xz_a)+", xz_b: "+std::to_string(this->xz_b)+"}";
		delete direction;
		return ret_str;
	}

	void set_direction(Vector direction) {
		//all this is because direction_pt = direction + this
		this->xy_a = (direction.x != 0 ? (direction.y)/(direction.x) : 0);
		this->xy_b = (this->y+direction.y)-((this->x+direction.x)*xy_a);
		this->xz_a = (direction.x != 0 ? (direction.z)/(direction.x) : 0);
		this->xz_b = (this->z+direction.z)-((this->x+direction.x)*xz_a);
	}

	const Vector* get_direction() {
		double x = this->x+1;
		return new Vector(1, xy_a*x+xy_b-this->y, xz_a*x+xz_b-this->z);
	}

	bool is_colliding(Rect& other) {
		return false;
	}

	bool is_colliding(Point& other) {
		return (xy_a*other.x + xy_b == other.y) && (xz_a*other.x + xz_b == other.z);
	}
};