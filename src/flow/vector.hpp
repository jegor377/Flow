namespace flow {
	class Vector : public Point {
	public:
		Vector(double x=0, double y=0, double z=0) : Point(x, y, z) {};
	};

	Vector new_scale(double scale) {
		Vector result(scale, scale, scale);
		return result;
	}
}