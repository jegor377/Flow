#pragma once
#include <string>
#include "../flow.hpp"
#include "../lest_basic.hpp"
//#include <iostream>

void proper_direction_test() {
	flow::Ray r(flow::Vector(1, 2, 2));
	const flow::Vector* r_predicted_direction = r.get_direction();
	EXPECT(r.x == 0 && r.y ==0 && r.z == 0);
	EXPECT(r_predicted_direction->x == 1 && r_predicted_direction->y == 2 && r_predicted_direction->z == 2);
	delete r_predicted_direction;

	flow::Ray r2(1, flow::Vector(1, 3, 3));
	const flow::Vector* r2_predicted_direction = r2.get_direction();
	EXPECT(r2.x == 1 && r2.y ==1 && r2.z == 1);
	EXPECT(r2_predicted_direction->x == 1 && r2_predicted_direction->y == 3 && r2_predicted_direction->z == 3);
	delete r2_predicted_direction;

	flow::Ray r3(1, 2, 3, flow::Vector(1, 4, 4));
	const flow::Vector* r3_predicted_direction = r3.get_direction();
	EXPECT(r3.x == 1 && r3.y ==2 && r3.z == 3);
	EXPECT(r3_predicted_direction->x == 1 && r3_predicted_direction->y == 4 && r3_predicted_direction->z == 4);
	delete r3_predicted_direction;
}

void proper_point_collision_detection_test() {
	flow::Ray r(flow::Vector(0, 3, 3));
	flow::Point collider(3, 3, 3);
	EXPECT(r.is_colliding(collider));

	flow::Ray r2(0, 1, 0, flow::Vector(1, 3, 3));
	flow::Point collider2(3, 10, 9);
	EXPECT(r2.is_colliding(collider2));
}