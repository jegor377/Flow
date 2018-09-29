#pragma once

namespace flow {
	struct Size2 {
		int w; // width
		int h; // height
	};

	struct Size {
		int w; // width
		int h; // height
		int l; // length
	};

	Size2 new_size2(int w = 0, int h = 0);
	Size new_size(int w=0, int h=0, int l=0);
}