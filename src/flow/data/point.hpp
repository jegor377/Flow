#pragma once

namespace flow {
	struct Point2 {
		int x=0;
		int y=0;
	};

	struct Point : Point2 {
		int z=0;
	};

	Point2 new_point2(int x=0, int y=0);
	Point new_point(int x=0, int y=0, int z=0);
}