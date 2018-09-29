#pragma once

#include "./point.hpp"
#include "./size.hpp"

namespace flow {
	struct Rect2 : Point2, Size2 {};

	struct Rect : Point, Size {};

	Rect2 new_rect2(int x=0, int y=0, int w=0, int h=0);
	Rect new_rect(int x=0, int y=0, int z=0, int w=0, int h=0, int l=0);
	bool is_colliding(Rect& src, Rect& dst);
	bool is_colliding_pwr(Point& src, Rect& dst);
}