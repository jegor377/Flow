namespace flow {
	class Point2 {
	public:
		double x;
		double y;

		Point2(double x=0, double y=0) {
			this->x=x;
			this->y=y;
		}
	};

	class Point : public Point2 {
	public:
		double z=0;
		Point(double x=0, double y=0, double z=0) : Point2(x, y) {
			this->z = z;
		}
	};
}