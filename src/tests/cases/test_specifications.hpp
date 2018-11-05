#pragma once

#include <string>
#include "lest_basic.hpp"
#include "flow.hpp"
#include <iostream>

namespace test_cases {
	const lest::test tests[] = {
		@import point2;
		@import point;
		@import size2;
		@import size;
		@import rect2;
		@import rect;
	};
}