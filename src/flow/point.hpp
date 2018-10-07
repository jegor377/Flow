namespace flow {
	struct Point2 {
		int x=0;
		int y=0;
	};

	struct Point : Point2 {
		int z=0;
	};

	Point2 new_point2(int x, int y) {
		Point result = {};
		result.x = x;
		result.y = y;
		return result;
	}

	Point new_point(int x, int y, int z) {
		Point result = {};
		result.x = x;
		result.y = y;
		result.z = z;
		return result;
	}
}