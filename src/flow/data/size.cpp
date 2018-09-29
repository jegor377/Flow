#include "./size.hpp"

namespace flow {
	Size2 new_size2(int w, int h) {
		Size2 result = {};
		result.w = w;
		result.h = h;
		return result;
	}

	Size new_size(int w, int h, int l) {
		Size result = {};
		result.w = w;
		result.h = h;
		result.l = l;
		return result;
	}
}