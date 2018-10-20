namespace flow {
	class Vector : public Point {
	public:

		Vector() : Point(0, 0, 0) {};
		Vector(double val) : Point(val, val, val) {};
		Vector(double x, double y, double z) : Point(x, y, z) {};

		void add(Vector& other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
		}

		void sub(Vector& other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
		}

		void mul(Vector& other) {
			this->x *= other.x;
			this->y *= other.y;
			this->z *= other.z;
		}

		void div(Vector& other) {
			this->x /= other.x;
			this->y /= other.y;
			this->z /= other.z;
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
	};

	// TODO: Change name to new_scale_of
	Vector new_scale(double scale) {
		return Vector(scale);;
	}
}