#include "./point.hpp"

namespace flow {
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