#pragma once

#include <string>
#include "lest_basic.hpp"
#include "flow.hpp"

namespace test_cases {
	const lest::test tests[] = {
		@import point2;
		@import point;
		@import size2;
		@import size;
	};
}