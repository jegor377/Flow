namespace flow {
	class Point2: public StringRepresentator {
	public:
		double x;
		double y;

		Point2(const Point2& other) {
			this->x = other.x;
			this->y = other.y;
		}

		Point2(double x=0, double y=0): StringRepresentator() {
			this->x=x;
			this->y=y;
		}

		std::string to_string() {
			return "Point2{x: "+std::to_string(this->x)+", y: "+std::to_string(this->y)+"}";
		}

		Point2 operator+(Point2& other) {
			return Point2(this->x + other.x, this->y + other.y);
		}

		Point2 operator-(Point2& other) {
			return Point2(this->x - other.x, this->y - other.y);
		}

		Point2 operator*(Point2& other) {
			return Point2(this->x * other.x, this->y * other.y);
		}

		Point2 operator/(Point2& other) {
			return Point2(this->x / other.x, this->y / other.y);
		}

		void operator+=(Point2& other) {
			this->x = this->x + other.x;
			this->y = this->y + other.y;
		}

		void operator-=(Point2& other) {
			this->x = this->x - other.x;
			this->y = this->y - other.y;
		}

		void operator*=(Point2& other) {
			this->x = this->x * other.x;
			this->y = this->y * other.y;
		}

		void operator/=(Point2& other) {
			this->x = this->x / other.x;
			this->y = this->y / other.y;
		}

		Point2 operator+(double val) {
			return Point2(this->x + val, this->y + val);
		}

		Point2 operator-(double val) {
			return Point2(this->x - val, this->y - val);
		}

		Point2 operator*(double val) {
			return Point2(this->x * val, this->y * val);
		}

		Point2 operator/(double val) {
			return Point2(this->x / val, this->y / val);
		}

		void operator+=(double val) {
			this->x = this->x + val;
			this->y = this->y + val;
		}

		void operator-=(double val) {
			this->x = this->x - val;
			this->y = this->y - val;
		}

		void operator*=(double val) {
			this->x = this->x * val;
			this->y = this->y * val;
		}

		void operator/=(double val) {
			this->x = this->x / val;
			this->y = this->y / val;
		}

		bool is_equal(Point2& other) {
			return (this->x == other.x) && (this->y == other.y);
		}

		bool is_equal(double val) {
			return (this->x == val) && (this->y == val);
		}

		bool operator==(Point2& other) {
			return this->is_equal(other);
		}

		bool operator!=(Point2& other) {
			return !this->is_equal(other);
		}

		bool operator==(double val) {
			return this->is_equal(val);
		}

		bool operator!=(double val) {
			return !this->is_equal(val);
		}
	};

	class Point : public Point2 {
	public:
		double z=0;
		Point(double x=0, double y=0, double z=0) : Point2(x, y) {
			this->z = z;
		}

		std::string to_string() {
			return "Point{x: "+std::to_string(this->x)+", y: "+std::to_string(this->y)+", z: "+std::to_string(this->z)+ "}";
		}

		Point operator+(Point& other) {
			return Point(this->x + other.x, this->y + other.y, this->z + other.z);
		}

		Point operator-(Point& other) {
			return Point(this->x - other.x, this->y - other.y, this->z - other.z);
		}

		Point operator*(Point& other) {
			return Point(this->x * other.x, this->y * other.y, this->z * other.z);
		}

		Point operator/(Point& other) {
			return Point(this->x / other.x, this->y / other.y, this->z / other.z);
		}

		void operator+=(Point& other) {
			this->x = this->x + other.x;
			this->y = this->y + other.y;
			this->z = this->z + other.z;
		}

		void operator-=(Point& other) {
			this->x = this->x - other.x;
			this->y = this->y - other.y;
			this->z = this->z - other.z;
		}

		void operator*=(Point& other) {
			this->x = this->x * other.x;
			this->y = this->y * other.y;
			this->z = this->z * other.z;
		}

		void operator/=(Point& other) {
			this->x = this->x / other.x;
			this->y = this->y / other.y;
			this->z = this->z / other.z;
		}

		Point operator+(double val) {
			return Point(this->x + val, this->y + val, this->z + val);
		}

		Point operator-(double val) {
			return Point(this->x - val, this->y - val, this->z - val);
		}

		Point operator*(double val) {
			return Point(this->x * val, this->y * val, this->z * val);
		}

		Point operator/(double val) {
			return Point(this->x / val, this->y / val, this->z / val);
		}

		void operator+=(double val) {
			this->x = this->x + val;
			this->y = this->y + val;
			this->z = this->z + val;
		}

		void operator-=(double val) {
			this->x = this->x - val;
			this->y = this->y - val;
			this->z = this->z - val;
		}

		void operator*=(double val) {
			this->x = this->x * val;
			this->y = this->y * val;
			this->z = this->z * val;
		}

		void operator/=(double val) {
			this->x = this->x / val;
			this->y = this->y / val;
			this->z = this->z / val;
		}

		bool is_equal(Point& other) {
			return this->Point2::is_equal( *(Point2*)(&other) ) && this->z == other.z;
		}

		bool is_equal(double val) {
			return this->Point2::is_equal( val ) && this->z == val;
		}

		bool operator==(Point& other) {
			return this->is_equal(other);
		}

		bool operator!=(Point& other) {
			return !this->is_equal(other);
		}

		bool operator==(double val) {
			return this->is_equal(val);
		}

		bool operator!=(double val) {
			return !this->is_equal(val);
		}
	};
}