#include "./rect.hpp"

namespace flow {
	Rect2 new_rect2(int x, int y, int w, int h) {
		flow::Rect2 result = {};
		result.x = x;
		result.y = y;
		result.w = w;
		result.h = h;
		return result;
	}

	Rect new_rect(int x, int y, int z, int w, int h, int l) {
		flow::Rect result = {};
		result.x = x;
		result.y = y;
		result.z = z;
		result.w = w;
		result.h = h;
		result.l = l;
		return result;
	}

	bool is_colliding(Rect& src, Rect& dst) {
		return false;
	}

	bool is_colliding_pwr(Point& src, Rect& dst) {
		return true;
	}
}