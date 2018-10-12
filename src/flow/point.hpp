namespace flow {
	class Point2 {
	public:
		int x;
		int y;

		Point2(int x=0, int y=0) {
			this->x=x;
			this->y=y;
		}
	};

	class Point : public Point2 {
	public:
		int z=0;
		Point(int x=0, int y=0, int z=0) : Point2(x, y) {
			this->z = z;
		}
	};
}