#pragma once

#include <string>
#include "lest_basic.hpp"
#include "flow.hpp"

namespace test_cases {
	const lest::test tests[] = {
		// Non-assign operators
// Point2 and Point2 operators
CASE("Point2 + Point2 operator works correctly"){
	flow::Point2 a(2, 5);
	flow::Point2 b = a + a;
	EXPECT(b.x == 4 && b.y == 10);
},
CASE("Point2 - Point2 operator works correctly"){
	flow::Point2 a(7, 4);
	flow::Point2 b(4, 3);
	flow::Point2 c = a - b;
	EXPECT(c.x == 3 && c.y == 1);
},
CASE("Point2 * Point2 operator works correctly"){
	flow::Point2 a(2, 5);
	flow::Point2 b(3, 4);
	flow::Point2 c = a * b;
	EXPECT(c.x == 6 && c.y == 20);
},
CASE("Point2 / Point2 operator works correctly"){
	flow::Point2 a(50, 15);
	flow::Point2 b(2, 3);
	flow::Point2 c = a / b;
	EXPECT(c.x == 25 && c.y == 5);
},
// Point2 and double operators
CASE("Point2 + double operator works correctly"){
	flow::Point2 a(2, 5);
	double val = 3;
	flow::Point2 b = a + val;
	EXPECT(b.x == 5 && b.y == 8);
},
CASE("Point2 - double operator works correctly"){
	flow::Point2 a(4, 5);
	double val = 3;
	flow::Point2 b = a - val;
	EXPECT(b.x == 1 && b.y == 2);
},
CASE("Point2 * double operator works correctly"){
	flow::Point2 a(2, 5);
	double val = 3;
	flow::Point2 b = a * val;
	EXPECT(b.x == 6 && b.y == 15);
},
CASE("Point2 / double operator works correctly"){
	flow::Point2 a(6, 18);
	double val = 3;
	flow::Point2 b = a / val;
	EXPECT(b.x == 2 && b.y == 6);
},

// Assign operators
// Point2 and Point2 operators
CASE("Point2 += Point2 operator works correctly"){
	flow::Point2 a(2, 5);
	flow::Point2 b(3, 5);
	a += b;
	EXPECT(a.x == 5 && a.y == 10);
},
CASE("Point2 -= Point2 operator works correctly"){
	flow::Point2 a(2, 5);
	flow::Point2 b(3, 5);
	a -= b;
	EXPECT(a.x == -1 && a.y == 0);
},
CASE("Point2 *= Point2 operator works correctly"){
	flow::Point2 a(2, 5);
	flow::Point2 b(3, 5);
	a *= b;
	EXPECT(a.x == 6 && a.y == 25);
},
CASE("Point2 /= Point2 operator works correctly"){
	flow::Point2 a(10, 5);
	flow::Point2 b(2, 5);
	a /= b;
	EXPECT(a.x == 5 && a.y == 1);
},
// Point2 and double operators
CASE("Point2 += double operator works correctly"){
	flow::Point2 a(10, 30);
	double val = 2;
	a += val;
	EXPECT(a.x == 12 && a.y == 32);
},
CASE("Point2 -= double operator works correctly"){
	flow::Point2 a(10, 30);
	double val = 2;
	a -= val;
	EXPECT(a.x == 8 && a.y == 28);
},
CASE("Point2 *= double operator works correctly"){
	flow::Point2 a(10, 30);
	double val = 2;
	a *= val;
	EXPECT(a.x == 20 && a.y == 60);
},
CASE("Point2 /= double operator works correctly"){
	flow::Point2 a(10, 30);
	double val = 2;
	a /= val;
	EXPECT(a.x == 5 && a.y == 15);
},

// methods
CASE("Point2 to_string method works returns correct results"){
	flow::Point2 a(10, 30);
	EXPECT(a.to_string() == ("Point2{x: "+std::to_string(10.0)+", y: "+std::to_string(30.0)+"}") );
},
		// Non-assign operators
// Point and Point operators
CASE("Point + Point operator works correctly"){
	flow::Point a(2, 5, 3);
	flow::Point b = a + a;
	EXPECT(b.x == 4 && b.y == 10 && b.z == 6);
},
CASE("Point - Point operator works correctly"){
	flow::Point a(7, 4, 4);
	flow::Point b(4, 3, 2);
	flow::Point c = a - b;
	EXPECT(c.x == 3 && c.y == 1 && c.z == 2);
},
CASE("Point * Point operator works correctly"){
	flow::Point a(2, 5, 2);
	flow::Point b(3, 4, 3);
	flow::Point c = a * b;
	EXPECT(c.x == 6 && c.y == 20 && c.z == 6);
},
CASE("Point / Point operator works correctly"){
	flow::Point a(50, 15, 6);
	flow::Point b(2, 3, 2);
	flow::Point c = a / b;
	EXPECT(c.x == 25 && c.y == 5 && c.z == 3);
},
// Point and double operators
CASE("Point + double operator works correctly"){
	flow::Point a(2, 5, 3);
	double val = 3;
	flow::Point b = a + val;
	EXPECT(b.x == 5 && b.y == 8 && b.z == 6);
},
CASE("Point - double operator works correctly"){
	flow::Point a(4, 5, 3);
	double val = 3;
	flow::Point b = a - val;
	EXPECT(b.x == 1 && b.y == 2 && b.z == 0);
},
CASE("Point * double operator works correctly"){
	flow::Point a(2, 5, 3);
	double val = 3;
	flow::Point b = a * val;
	EXPECT(b.x == 6 && b.y == 15 && b.z == 9);
},
CASE("Point / double operator works correctly"){
	flow::Point a(6, 18, 9);
	double val = 3;
	flow::Point b = a / val;
	EXPECT(b.x == 2 && b.y == 6 && b.z == 3);
},

// Assign operators
// Point and Point operators
CASE("Point += Point operator works correctly"){
	flow::Point a(2, 5, 3);
	flow::Point b(3, 5, 4);
	a += b;
	EXPECT(a.x == 5 && a.y == 10 && a.z == 7);
},
CASE("Point -= Point operator works correctly"){
	flow::Point a(2, 5, 10);
	flow::Point b(3, 5, 3);
	a -= b;
	EXPECT(a.x == -1 && a.y == 0 && a.z == 7);
},
CASE("Point *= Point operator works correctly"){
	flow::Point a(2, 5, 2);
	flow::Point b(3, 5, 2);
	a *= b;
	EXPECT(a.x == 6 && a.y == 25 && a.z == 4);
},
CASE("Point /= Point operator works correctly"){
	flow::Point a(10, 5, 6);
	flow::Point b(2, 5, 2);
	a /= b;
	EXPECT(a.x == 5 && a.y == 1 && a.z == 3);
},
// Point and double operators
CASE("Point += double operator works correctly"){
	flow::Point a(10, 30, 2);
	double val = 2;
	a += val;
	EXPECT(a.x == 12 && a.y == 32 && a.z == 4);
},
CASE("Point -= double operator works correctly"){
	flow::Point a(10, 30, 4);
	double val = 2;
	a -= val;
	EXPECT(a.x == 8 && a.y == 28 && a.z == 2);
},
CASE("Point *= double operator works correctly"){
	flow::Point a(10, 30, 5);
	double val = 2;
	a *= val;
	EXPECT(a.x == 20 && a.y == 60 && a.z == 10);
},
CASE("Point /= double operator works correctly"){
	flow::Point a(10, 30, 50);
	double val = 2;
	a /= val;
	EXPECT(a.x == 5 && a.y == 15 && a.z == 25);
},

// methods
CASE("Point to_string method works returns correct results"){
	flow::Point a(10, 30, 2);
	EXPECT(a.to_string() == ("Point{x: "+std::to_string(10.0)+", y: "+std::to_string(30.0)+", z: "+std::to_string(2.0)+"}") );
},
		// Non-assign operators
// Size2 and Size2 operators
CASE("Size2 + Size2 operator works correctly"){
	flow::Size2 a(2, 5);
	flow::Size2 b = a + a;
	EXPECT(b.w == 4 && b.h == 10);
},
CASE("Size2 - Size2 operator works correctly"){
	flow::Size2 a(7, 4);
	flow::Size2 b(4, 3);
	flow::Size2 c = a - b;
	EXPECT(c.w == 3 && c.h == 1);
},
CASE("Size2 * Size2 operator works correctly"){
	flow::Size2 a(2, 5);
	flow::Size2 b(3, 4);
	flow::Size2 c = a * b;
	EXPECT(c.w == 6 && c.h == 20);
},
CASE("Size2 / Size2 operator works correctly"){
	flow::Size2 a(50, 15);
	flow::Size2 b(2, 3);
	flow::Size2 c = a / b;
	EXPECT(c.w == 25 && c.h == 5);
},
// Size2 and double operators
CASE("Size2 + double operator works correctly"){
	flow::Size2 a(2, 5);
	double val = 3;
	flow::Size2 b = a + val;
	EXPECT(b.w == 5 && b.h == 8);
},
CASE("Size2 - double operator works correctly"){
	flow::Size2 a(4, 5);
	double val = 3;
	flow::Size2 b = a - val;
	EXPECT(b.w == 1 && b.h == 2);
},
CASE("Size2 * double operator works correctly"){
	flow::Size2 a(2, 5);
	double val = 3;
	flow::Size2 b = a * val;
	EXPECT(b.w == 6 && b.h == 15);
},
CASE("Size2 / double operator works correctly"){
	flow::Size2 a(6, 18);
	double val = 3;
	flow::Size2 b = a / val;
	EXPECT(b.w == 2 && b.h == 6);
},

// Assign operators
// Size2 and Size2 operators
CASE("Size2 += Size2 operator works correctly"){
	flow::Size2 a(2, 5);
	flow::Size2 b(3, 5);
	a += b;
	EXPECT(a.w == 5 && a.h == 10);
},
CASE("Size2 -= Size2 operator works correctly"){
	flow::Size2 a(2, 5);
	flow::Size2 b(3, 5);
	a -= b;
	EXPECT(a.w == -1 && a.h == 0);
},
CASE("Size2 *= Size2 operator works correctly"){
	flow::Size2 a(2, 5);
	flow::Size2 b(3, 5);
	a *= b;
	EXPECT(a.w == 6 && a.h == 25);
},
CASE("Size2 /= Size2 operator works correctly"){
	flow::Size2 a(10, 5);
	flow::Size2 b(2, 5);
	a /= b;
	EXPECT(a.w == 5 && a.h == 1);
},
// Size2 and double operators
CASE("Size2 += double operator works correctly"){
	flow::Size2 a(10, 30);
	double val = 2;
	a += val;
	EXPECT(a.w == 12 && a.h == 32);
},
CASE("Size2 -= double operator works correctly"){
	flow::Size2 a(10, 30);
	double val = 2;
	a -= val;
	EXPECT(a.w == 8 && a.h == 28);
},
CASE("Size2 *= double operator works correctly"){
	flow::Size2 a(10, 30);
	double val = 2;
	a *= val;
	EXPECT(a.w == 20 && a.h == 60);
},
CASE("Size2 /= double operator works correctly"){
	flow::Size2 a(10, 30);
	double val = 2;
	a /= val;
	EXPECT(a.w == 5 && a.h == 15);
},

// methods
CASE("Size2 to_string method works returns correct results"){
	flow::Size2 a(10, 30);
	EXPECT(a.to_string() == ("Size2{w: "+std::to_string(10.0)+", h: "+std::to_string(30.0)+"}") );
},
		// Non-assign operators
// Size and Size operators
CASE("Size + Size operator works correctly"){
	flow::Size a(2, 5, 3);
	flow::Size b = a + a;
	EXPECT(b.w == 4 && b.h == 10 && b.l == 6);
},
CASE("Size - Size operator works correctly"){
	flow::Size a(7, 4, 4);
	flow::Size b(4, 3, 2);
	flow::Size c = a - b;
	EXPECT(c.w == 3 && c.h == 1 && c.l == 2);
},
CASE("Size * Size operator works correctly"){
	flow::Size a(2, 5, 2);
	flow::Size b(3, 4, 3);
	flow::Size c = a * b;
	EXPECT(c.w == 6 && c.h == 20 && c.l == 6);
},
CASE("Size / Size operator works correctly"){
	flow::Size a(50, 15, 6);
	flow::Size b(2, 3, 2);
	flow::Size c = a / b;
	EXPECT(c.w == 25 && c.h == 5 && c.l == 3);
},
// Size and double operators
CASE("Size + double operator works correctly"){
	flow::Size a(2, 5, 3);
	double val = 3;
	flow::Size b = a + val;
	EXPECT(b.w == 5 && b.h == 8 && b.l == 6);
},
CASE("Size - double operator works correctly"){
	flow::Size a(4, 5, 3);
	double val = 3;
	flow::Size b = a - val;
	EXPECT(b.w == 1 && b.h == 2 && b.l == 0);
},
CASE("Size * double operator works correctly"){
	flow::Size a(2, 5, 3);
	double val = 3;
	flow::Size b = a * val;
	EXPECT(b.w == 6 && b.h == 15 && b.l == 9);
},
CASE("Size / double operator works correctly"){
	flow::Size a(6, 18, 9);
	double val = 3;
	flow::Size b = a / val;
	EXPECT(b.w == 2 && b.h == 6 && b.l == 3);
},

// Assign operators
// Size and Size operators
CASE("Size += Size operator works correctly"){
	flow::Size a(2, 5, 3);
	flow::Size b(3, 5, 4);
	a += b;
	EXPECT(a.w == 5 && a.h == 10 && a.l == 7);
},
CASE("Size -= Size operator works correctly"){
	flow::Size a(2, 5, 10);
	flow::Size b(3, 5, 3);
	a -= b;
	EXPECT(a.w == -1 && a.h == 0 && a.l == 7);
},
CASE("Size *= Size operator works correctly"){
	flow::Size a(2, 5, 2);
	flow::Size b(3, 5, 2);
	a *= b;
	EXPECT(a.w == 6 && a.h == 25 && a.l == 4);
},
CASE("Size /= Size operator works correctly"){
	flow::Size a(10, 5, 6);
	flow::Size b(2, 5, 2);
	a /= b;
	EXPECT(a.w == 5 && a.h == 1 && a.l == 3);
},
// Size and double operators
CASE("Size += double operator works correctly"){
	flow::Size a(10, 30, 2);
	double val = 2;
	a += val;
	EXPECT(a.w == 12 && a.h == 32 && a.l == 4);
},
CASE("Size -= double operator works correctly"){
	flow::Size a(10, 30, 4);
	double val = 2;
	a -= val;
	EXPECT(a.w == 8 && a.h == 28 && a.l == 2);
},
CASE("Size *= double operator works correctly"){
	flow::Size a(10, 30, 5);
	double val = 2;
	a *= val;
	EXPECT(a.w == 20 && a.h == 60 && a.l == 10);
},
CASE("Size /= double operator works correctly"){
	flow::Size a(10, 30, 50);
	double val = 2;
	a /= val;
	EXPECT(a.w == 5 && a.h == 15 && a.l == 25);
},

// methods
CASE("Size to_string method works returns correct results"){
	flow::Size a(10, 30, 2);
	EXPECT(a.to_string() == ("Size{w: "+std::to_string(10.0)+", h: "+std::to_string(30.0)+", l: "+std::to_string(2.0)+"}") );
},
	};
}