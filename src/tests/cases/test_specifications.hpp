#pragma once

#include <string>
#include "lest_basic.hpp"
#include "flow.hpp"
#include "test_entity.hpp"

#include "cases/ray.hpp"

#include <iostream>

namespace test_cases {
const lest::test tests[] = {
@import point2;
@import point;
@import size2;
@import size;
@import rect2;
@import rect;
@import entity_collector;
lest::test{"Ray constructor, set_direction and get_direction works correctly.", proper_direction_test},
lest::test{"Point on ray collision detection test.", proper_point_collision_detection_test},
lest::test{"TESTOWY", [](){EXPECT(true);}}, //TODO: weź to kurwa popraw xD
};
}