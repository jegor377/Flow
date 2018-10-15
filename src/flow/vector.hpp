namespace flow {
	class Vector : public Point {
	public:
		Vector(double x=0, double y=0, double z=0) : Point(x, y, z) {};

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

	Vector new_scale(double scale) {
		Vector result(scale, scale, scale);
		return result;
	}
}