#pragma once

#include <string>
#include "lest_basic.hpp"
#include "flow.hpp"
#include "test_entity.hpp"

#include "cases/ray.hpp"

#include <iostream>

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
CASE("double + Point2 operator works correctly"){
	flow::Point2 a(2, 5);
	double val = 3;
	flow::Point2 b = val + a;
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
CASE("double * Point2 operator works correctly"){
	flow::Point2 a(2, 5);
	double val = 3;
	flow::Point2 b = val * a;
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

// equal operators
CASE("Point2 == Point2 operator works correctly"){
	flow::Point2 a(10, 20);
	flow::Point2 b(10, 20);
	flow::Point2 c(20, 10);
	EXPECT(a == b);
	EXPECT( !(a == c) );
},
CASE("Point2 == double operator works correctly"){
	flow::Point2 a(20, 20);
	double b = 20;
	double c = 30;
	EXPECT(a == b);
	EXPECT( !(a == c) );
},
CASE("Point2 != Point2 operator works correctly"){
	flow::Point2 a(10, 20);
	flow::Point2 b(20, 10);
	flow::Point2 c(10, 20);
	EXPECT(a != b);
	EXPECT( !(a != c) );
},
CASE("Point2 != double operator works correctly"){
	flow::Point2 a(20, 20);
	double b = 30;
	double c = 20;
	EXPECT(a != b);
	EXPECT( !(a != c) );
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
CASE("double + Point operator works correctly"){
	flow::Point a(2, 5, 3);
	double val = 3;
	flow::Point b = val + a;
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
CASE("double * Point operator works correctly"){
	flow::Point a(2, 5, 3);
	double val = 3;
	flow::Point b = val * a;
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

// equal operators
CASE("Point == Point operator works correctly"){
	flow::Point a(10, 20, 30);
	flow::Point b(10, 20, 30);
	flow::Point c(30, 20, 10);
	EXPECT(a == b);
	EXPECT( !(a == c) );
},
CASE("Point == double operator works correctly"){
	flow::Point a(20, 20, 20);
	double b = 20;
	double c = 30;
	EXPECT(a == b);
	EXPECT( !(a == c) );
},
CASE("Point != Point operator works correctly"){
	flow::Point a(10, 20, 30);
	flow::Point b(30, 20, 10);
	flow::Point c(10, 20, 30);
	EXPECT(a != b);
	EXPECT( !(a != c) );
},
CASE("Point != double operator works correctly"){
	flow::Point a(20, 20, 20);
	double b = 30;
	double c = 20;
	EXPECT(a != b);
	EXPECT( !(a != c) );
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
CASE("double + Size2 operator works correctly"){
	flow::Size2 a(2, 5);
	double val = 3;
	flow::Size2 b = val + a;
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
CASE("double * Size2 operator works correctly"){
	flow::Size2 a(2, 5);
	double val = 3;
	flow::Size2 b = val * a;
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

// equal operators
CASE("Size2 == Size2 operator works correctly"){
	flow::Size2 a(10, 20);
	flow::Size2 b(10, 20);
	flow::Size2 c(20, 10);
	EXPECT(a == b);
	EXPECT( !(a == c) );
},
CASE("Size2 == double operator works correctly"){
	flow::Size2 a(20, 20);
	double b = 20;
	double c = 30;
	EXPECT(a == b);
	EXPECT( !(a == c) );
},
CASE("Size2 != Size2 operator works correctly"){
	flow::Size2 a(10, 20);
	flow::Size2 b(20, 10);
	flow::Size2 c(10, 20);
	EXPECT(a != b);
	EXPECT( !(a != c) );
},
CASE("Size2 != double operator works correctly"){
	flow::Size2 a(20, 20);
	double b = 30;
	double c = 20;
	EXPECT(a != b);
	EXPECT( !(a != c) );
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
CASE("double + Size operator works correctly"){
	flow::Size a(2, 5, 3);
	double val = 3;
	flow::Size b = val + a;
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
CASE("double * Size operator works correctly"){
	flow::Size a(2, 5, 3);
	double val = 3;
	flow::Size b = val * a;
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

// equal operators
CASE("Size == Size operator works correctly"){
	flow::Size a(10, 20, 30);
	flow::Size b(10, 20, 30);
	flow::Size c(30, 20, 10);
	EXPECT(a == b);
	EXPECT( !(a == c) );
},
CASE("Size == double operator works correctly"){
	flow::Size a(20, 20, 20);
	double b = 20;
	double c = 30;
	EXPECT(a == b);
	EXPECT( !(a == c) );
},
CASE("Size != Size operator works correctly"){
	flow::Size a(10, 20, 30);
	flow::Size b(30, 20, 10);
	flow::Size c(10, 20, 30);
	EXPECT(a != b);
	EXPECT( !(a != c) );
},
CASE("Size != double operator works correctly"){
	flow::Size a(20, 20, 20);
	double b = 30;
	double c = 20;
	EXPECT(a != b);
	EXPECT( !(a != c) );
},

// methods
CASE("Size to_string method works returns correct results"){
	flow::Size a(10, 30, 2);
	EXPECT(a.to_string() == ("Size{w: "+std::to_string(10.0)+", h: "+std::to_string(30.0)+", l: "+std::to_string(2.0)+"}") );
},
// Non-assign operators
// Rect2 and Rect2 operators
CASE("Rect2 + Rect2 operator works correctly"){
	flow::Rect2 a(2, 5, 3, 4, flow::SECTION);
	flow::Rect2 b = a + a;
	EXPECT(b.x == 4 && b.y == 10 && b.w == 6 && b.h == 8 && b.mode == a.mode);
},
CASE("Rect2 - Rect2 operator works correctly"){
	flow::Rect2 a(7, 4, 6, 3, flow::SECTION);
	flow::Rect2 b(4, 3, 3, 3);
	flow::Rect2 c = a - b;
	EXPECT(c.x == 3 && c.y == 1 && c.w == 3 && c.h == 0 && c.mode == a.mode);
},
CASE("Rect2 * Rect2 operator works correctly"){
	flow::Rect2 a(2, 5, 1, 5, flow::SECTION);
	flow::Rect2 b(3, 4, 2, 5);
	flow::Rect2 c = a * b;
	EXPECT(c.x == 6 && c.y == 20 && c.w == 2 && c.h == 25 && c.mode == a.mode);
},
CASE("Rect2 / Rect2 operator works correctly"){
	flow::Rect2 a(50, 15, 100, 20, flow::SECTION);
	flow::Rect2 b(2, 3, 10, 2);
	flow::Rect2 c = a / b;
	EXPECT(c.x == 25 && c.y == 5 && c.w == 10 && c.h == 10 && c.mode == a.mode);
},
// Rect2 and double operators
CASE("Rect2 + double operator works correctly"){
	flow::Rect2 a(2, 5, 7, 0, flow::SECTION);
	double val = 3;
	flow::Rect2 b = a + val;
	EXPECT(b.x == 5 && b.y == 8 && b.w == 10 && b.h == 3 && b.mode == a.mode);
},
CASE("double + Rect2 operator works correctly"){
	flow::Rect2 a(2, 5, 7, 0, flow::SECTION);
	double val = 3;
	flow::Rect2 b = val + a;
	EXPECT(b.x == 5 && b.y == 8 && b.w == 10 && b.h == 3 && b.mode == a.mode);
},
CASE("Rect2 - double operator works correctly"){
	flow::Rect2 a(4, 5, 3, 1, flow::SECTION);
	double val = 3;
	flow::Rect2 b = a - val;
	EXPECT(b.x == 1 && b.y == 2 && b.w == 0 && b.h == (-2) && b.mode == a.mode);
},
CASE("Rect2 * double operator works correctly"){
	flow::Rect2 a(2, 5, 3, 10, flow::SECTION);
	double val = 3;
	flow::Rect2 b = a * val;
	EXPECT(b.x == 6 && b.y == 15 && b.w == 9 && b.h == 30 && b.mode == a.mode);
},
CASE("double * Rect2 operator works correctly"){
	flow::Rect2 a(2, 5, 3, 10, flow::SECTION);
	double val = 3;
	flow::Rect2 b = val * a;
	EXPECT(b.x == 6 && b.y == 15 && b.w == 9 && b.h == 30 && b.mode == a.mode);
},
CASE("Rect2 / double operator works correctly"){
	flow::Rect2 a(6, 18, 9, 3, flow::SECTION);
	double val = 3;
	flow::Rect2 b = a / val;
	EXPECT(b.x == 2 && b.y == 6 && b.w == 3 && b.h == 1 && b.mode == a.mode);
},

// Assign operators
// Rect2 and Rect2 operators
CASE("Rect2 += Rect2 operator works correctly"){
	flow::Rect2 a(2, 5, 3, 4, flow::SECTION);
	flow::Rect2 b(3, 5, 4, 3);
	a += b;
	EXPECT(a.x == 5 && a.y == 10 && a.w == 7 && a.h == 7 && a.mode == flow::SECTION);
},
CASE("Rect2 -= Rect2 operator works correctly"){
	flow::Rect2 a(2, 5, 4, 6, flow::SECTION);
	flow::Rect2 b(3, 5, 2, 6);
	a -= b;
	EXPECT(a.x == -1 && a.y == 0 && a.w == 2 && a.h == 0 && a.mode == flow::SECTION);
},
CASE("Rect2 *= Rect2 operator works correctly"){
	flow::Rect2 a(2, 5, 2, 3, flow::SECTION);
	flow::Rect2 b(3, 5, 2, 2);
	a *= b;
	EXPECT(a.x == 6 && a.y == 25 && a.w == 4 && a.h == 6 && a.mode == flow::SECTION);
},
CASE("Rect2 /= Rect2 operator works correctly"){
	flow::Rect2 a(10, 5, 20, 36, flow::SECTION);
	flow::Rect2 b(2, 5, 5, 6);
	a /= b;
	EXPECT(a.x == 5 && a.y == 1 && a.w == 4 && a.h == 6 && a.mode == flow::SECTION);
},
// Rect2 and double operators
CASE("Rect2 += double operator works correctly"){
	flow::Rect2 a(10, 30, 1, 2, flow::SECTION);
	double val = 2;
	a += val;
	EXPECT(a.x == 12 && a.y == 32 && a.w == 3 && a.h == 4 && a.mode == flow::SECTION);
},
CASE("Rect2 -= double operator works correctly"){
	flow::Rect2 a(10, 30, 1, 2, flow::SECTION);
	double val = 2;
	a -= val;
	EXPECT(a.x == 8 && a.y == 28 && a.w == -1 && a.h == 0 && a.mode == flow::SECTION);
},
CASE("Rect2 *= double operator works correctly"){
	flow::Rect2 a(10, 30, 1, 2, flow::SECTION);
	double val = 2;
	a *= val;
	EXPECT(a.x == 20 && a.y == 60 && a.w == 2 && a.h == 4 && a.mode == flow::SECTION);
},
CASE("Rect2 /= double operator works correctly"){
	flow::Rect2 a(10, 30, 1, 2, flow::SECTION);
	double val = 2;
	a /= val;
	EXPECT(a.x == 5 && a.y == 15 && a.w == 0.5 && a.h == 1 && a.mode == flow::SECTION);
},
// Rect2 and Point2 operators
CASE("Rect2 += Point2 operator works correctly"){
	flow::Rect2 a(10, 30, 1, 2, flow::SECTION);
	flow::Point2 b(5, 10);
	a += b;
	EXPECT(a.x == 15 && a.y == 40 && a.w == 1 && a.h == 2 && a.mode == flow::SECTION);
},
CASE("Rect2 -= Point2 operator works correctly"){
	flow::Rect2 a(10, 30, 1, 2, flow::SECTION);
	flow::Point2 b(5, 10);
	a -= b;
	EXPECT(a.x == 5 && a.y == 20 && a.w == 1 && a.h == 2 && a.mode == flow::SECTION);
},
CASE("Rect2 *= Point2 operator works correctly"){
	flow::Rect2 a(10, 30, 1, 2, flow::SECTION);
	flow::Point2 b(5, 10);
	a *= b;
	EXPECT(a.x == 50 && a.y == 300 && a.w == 1 && a.h == 2 && a.mode == flow::SECTION);
},
CASE("Rect2 /= Point2 operator works correctly"){
	flow::Rect2 a(10, 30, 1, 2, flow::SECTION);
	flow::Point2 b(5, 10);
	a /= b;
	EXPECT(a.x == 2 && a.y == 3 && a.w == 1 && a.h == 2 && a.mode == flow::SECTION);
},
// Rect2 and Size2 operators
CASE("Rect2 += Size2 operator works correctly"){
	flow::Rect2 a(10, 30, 1, 2, flow::SECTION);
	flow::Size2 b(5, 10);
	a += b;
	EXPECT(a.x == 10 && a.y == 30 && a.w == 6 && a.h == 12 && a.mode == flow::SECTION);
},
CASE("Rect2 -= Size2 operator works correctly"){
	flow::Rect2 a(10, 30, 1, 2, flow::SECTION);
	flow::Size2 b(5, 10);
	a -= b;
	EXPECT(a.x == 10 && a.y == 30 && a.w == (-4) && a.h == (-8) && a.mode == flow::SECTION);
},
CASE("Rect2 *= Size2 operator works correctly"){
	flow::Rect2 a(10, 30, 1, 2, flow::SECTION);
	flow::Size2 b(5, 10);
	a *= b;
	EXPECT(a.x == 10 && a.y == 30 && a.w == 5 && a.h == 20 && a.mode == flow::SECTION);
},
CASE("Rect2 /= Size2 operator works correctly"){
	flow::Rect2 a(10, 30, 1, 2, flow::SECTION);
	flow::Size2 b(5, 10);
	a /= b;
	EXPECT(a.x == 10 && a.y == 30 && a.w == (1.0/5.0) && a.h == (2.0/10.0) && a.mode == flow::SECTION);
},

// equal operators
CASE("Rect2 == Rect2 operator works correctly"){
	flow::Rect2 a(10, 20, 30, 40, flow::SECTION);
	flow::Rect2 b(10, 20, 30, 40, flow::SECTION);
	flow::Rect2 c(40, 30, 20, 10);
	EXPECT(a == b);
	EXPECT( !(a == c) );
},
CASE("Rect2 == double operator works correctly"){
	flow::Rect2 a(20, 20, 20, 20, flow::SECTION);
	double b = 20;
	double c = 30;
	EXPECT(a == b);
	EXPECT( !(a == c) );
},
CASE("Rect2 != Rect2 operator works correctly"){
	flow::Rect2 a(10, 20, 30, 40, flow::SECTION);
	flow::Rect2 b(40, 30, 20, 10, flow::FULL);
	flow::Rect2 c(10, 20, 30, 40, flow::SECTION);
	EXPECT(a != b);
	EXPECT( !(a != c) );
},
CASE("Rect2 != double operator works correctly"){
	flow::Rect2 a(20, 20, 20, 20, flow::SECTION);
	double b = 30;
	double c = 20;
	EXPECT(a != b);
	EXPECT( !(a != c) );
},
CASE("Rect2 vequal Rect2 method works correctly"){
	flow::Rect2 a(10, 20, 30, 40, flow::SECTION);
	flow::Rect2 b(10, 20, 30, 40, flow::FULL);
	flow::Rect2 c(10, 20, 30, 40, flow::SECTION);
	EXPECT( a.is_vequal(b) );
	EXPECT( a.is_vequal(c) );
},
CASE("Rect2 !vequal Rect2 method works correctly"){
	flow::Rect2 a(10, 20, 30, 40, flow::SECTION);
	flow::Rect2 d(40, 20, 30, 40, flow::SECTION);
	flow::Rect2 e(40, 20, 30, 40, flow::FULL);
	EXPECT( !a.is_vequal(d) );
	EXPECT( !a.is_vequal(e) );
},

// methods
CASE("Rect2 to_string method works returns correct results"){
	flow::Rect2 a(10, 30, 40, 50, flow::SECTION);
	EXPECT(a.to_string() == ("Rect2{x: "+std::to_string(10.0)+", y: "+std::to_string(30.0)+", w: "+std::to_string(40.0)+", h: "+std::to_string(50.0)+", mode: SECTION}") );
},
// Non-assign operators
// Rect and Rect operators
CASE("Rect + Rect operator works correctly"){
	flow::Rect a(2, 5, 1, 3, 4, 6);
	flow::Rect b = a + a;
	EXPECT(b.x == 4 && b.y == 10 && b.z == 2 && b.w == 6 && b.h == 8 && b.l == 12);
},
CASE("Rect - Rect operator works correctly"){
	flow::Rect a(7, 4, 6, 6, 3, 1);
	flow::Rect b(4, 3, 2, 3, 3, 2);
	flow::Rect c = a - b;
	EXPECT(c.x == 3 && c.y == 1 && c.z == 4 && c.w == 3 && c.h == 0 && c.l == (-1));
},
CASE("Rect * Rect operator works correctly"){
	flow::Rect a(2, 5, 2, 1, 5, 1);
	flow::Rect b(3, 4, 3, 2, 5, 2);
	flow::Rect c = a * b;
	EXPECT(c.x == 6 && c.y == 20 && c.z == 6 && c.w == 2 && c.h == 25 && c.l == 2);
},
CASE("Rect / Rect operator works correctly"){
	flow::Rect a(50, 15, 10, 100, 20, 5);
	flow::Rect b(2, 3, 2, 10, 2, 5);
	flow::Rect c = a / b;
	EXPECT(c.x == 25 && c.y == 5 && c.z == 5 && c.w == 10 && c.h == 10 && c.l == 1);
},
// Rect and double operators
CASE("Rect + double operator works correctly"){
	flow::Rect a(2, 5, 3, 7, 0, 9);
	double val = 3;
	flow::Rect b = a + val;
	EXPECT(b.x == 5 && b.y == 8 && b.z == 6 && b.w == 10 && b.h == 3 && b.l == 12);
},
CASE("double + Rect operator works correctly"){
	flow::Rect a(2, 5, 3, 7, 0, 9);
	double val = 3;
	flow::Rect b = val + a;
	EXPECT(b.x == 5 && b.y == 8 && b.z == 6 && b.w == 10 && b.h == 3 && b.l == 12);
},
CASE("Rect - double operator works correctly"){
	flow::Rect a(4, 5, 6, 3, 1, 9);
	double val = 3;
	flow::Rect b = a - val;
	EXPECT(b.x == 1 && b.y == 2 && b.z == 3 && b.w == 0 && b.h == (-2) && b.l == 6);
},
CASE("Rect * double operator works correctly"){
	flow::Rect a(2, 5, 7, 3, 10, (1/3.0));
	double val = 3;
	flow::Rect b = a * val;
	EXPECT(b.x == 6 && b.y == 15 && b.z == 21 && b.w == 9 && b.h == 30 && b.l == 1);
},
CASE("double * Rect operator works correctly"){
	flow::Rect a(2, 5, 7, 3, 10, (1/3.0));
	double val = 3;
	flow::Rect b = val * a;
	EXPECT(b.x == 6 && b.y == 15 && b.z == 21 && b.w == 9 && b.h == 30 && b.l == 1);
},
CASE("Rect / double operator works correctly"){
	flow::Rect a(6, 18, 12, 9, 3, 21);
	double val = 3;
	flow::Rect b = a / val;
	EXPECT(b.x == 2 && b.y == 6 && b.z == 4 && b.w == 3 && b.h == 1 && b.l == 7);
},

// Assign operators
// Rect and Rect operators
CASE("Rect += Rect operator works correctly"){
	flow::Rect a(2, 5, 3, 3, 4, 1);
	flow::Rect b(3, 5, 2, 4, 3, 2);
	a += b;
	EXPECT(a.x == 5 && a.y == 10 && a.z == 5 && a.w == 7 && a.h == 7 && a.l == 3);
},
CASE("Rect -= Rect operator works correctly"){
	flow::Rect a(2, 5, 4, 4, 6, 5);
	flow::Rect b(3, 5, 2, 2, 6, 2);
	a -= b;
	EXPECT(a.x == -1 && a.y == 0 && a.z == 2 && a.w == 2 && a.h == 0 && a.l == 3);
},
CASE("Rect *= Rect operator works correctly"){
	flow::Rect a(2, 5, 5, 2, 3, (1/2.0));
	flow::Rect b(3, 5, 2, 2, 2, 2);
	a *= b;
	EXPECT(a.x == 6 && a.y == 25 && a.z == 10 && a.w == 4 && a.h == 6 && a.l == 1);
},
CASE("Rect /= Rect operator works correctly"){
	flow::Rect a(10, 5, 4, 20, 36, 100);
	flow::Rect b(2, 5, 2, 5, 6, 10);
	a /= b;
	EXPECT(a.x == 5 && a.y == 1 && a.z == 2 && a.w == 4 && a.h == 6 && a.l == 10);
},
// Rect and double operators
CASE("Rect += double operator works correctly"){
	flow::Rect a(10, 30, 20, 1, 2, 4);
	double val = 2;
	a += val;
	EXPECT(a.x == 12 && a.y == 32 && a.z == 22 && a.w == 3 && a.h == 4 && a.l == 6);
},
CASE("Rect -= double operator works correctly"){
	flow::Rect a(10, 30, 4, 1, 2, 20);
	double val = 2;
	a -= val;
	EXPECT(a.x == 8 && a.y == 28 && a.z == 2 && a.w == -1 && a.h == 0 && a.l == 18);
},
CASE("Rect *= double operator works correctly"){
	flow::Rect a(10, 30, (1/2.0), 1, 2, 2);
	double val = 2;
	a *= val;
	EXPECT(a.x == 20 && a.y == 60 && a.z == 1 && a.w == 2 && a.h == 4 && a.l == 4);
},
CASE("Rect /= double operator works correctly"){
	flow::Rect a(10, 30, 4, 1, 2, (1/2));
	double val = 2;
	a /= val;
	EXPECT(a.x == 5 && a.y == 15 && a.z == 2 && a.w == 0.5 && a.h == 1 && a.l == (1/4));
},
// Rect and Point operators
CASE("Rect += Point operator works correctly"){
	flow::Rect a(10, 30, 1, 1, 2, 3);
	flow::Point b(5, 10, 1);
	a += b;
	EXPECT(a.x == 15 && a.y == 40 && a.z == 2 && a.w == 1 && a.h == 2 && a.l == 3);
},
CASE("Rect -= Point operator works correctly"){
	flow::Rect a(10, 30, 1, 1, 2, 3);
	flow::Point b(5, 10, 1);
	a -= b;
	EXPECT(a.x == 5 && a.y == 20 && a.z == 0 && a.w == 1 && a.h == 2 && a.l == 3);
},
CASE("Rect *= Point operator works correctly"){
	flow::Rect a(10, 30, 1, 1, 2, 3);
	flow::Point b(5, 10, 1);
	a *= b;
	EXPECT(a.x == 50 && a.y == 300 && a.z == 1 && a.w == 1 && a.h == 2 && a.l == 3);
},
CASE("Rect /= Point operator works correctly"){
	flow::Rect a(10, 30, 2, 1, 2, 3);
	flow::Point b(5, 10, 2);
	a /= b;
	EXPECT(a.x == 2 && a.y == 3 && a.z == 1 && a.w == 1 && a.h == 2 && a.l == 3);
},
// Rect and Size operators
CASE("Rect += Size operator works correctly"){
	flow::Rect a(10, 30, 2, 1, 2, 3);
	flow::Size b(5, 10, 3);
	a += b;
	EXPECT(a.x == 10 && a.y == 30 && a.z == 2 && a.w == 6 && a.h == 12 && a.l == 6);
},
CASE("Rect -= Size operator works correctly"){
	flow::Rect a(10, 30, 2, 1, 2, 3);
	flow::Size b(5, 10, 3);
	a -= b;
	EXPECT(a.x == 10 && a.y == 30 && a.z == 2 && a.w == (-4) && a.h == (-8) && a.l == 0);
},
CASE("Rect *= Size operator works correctly"){
	flow::Rect a(10, 30, 2, 1, 2, 3);
	flow::Size b(5, 10, 3);
	a *= b;
	EXPECT(a.x == 10 && a.y == 30 && a.z == 2 && a.w == 5 && a.h == 20 && a.l == 9);
},
CASE("Rect /= Size operator works correctly"){
	flow::Rect a(10, 30, 2, 1, 2, 3);
	flow::Size b(5, 10, 3);
	a /= b;
	EXPECT(a.x == 10 && a.y == 30 && a.z == 2 && a.w == (1.0/5.0) && a.h == (2.0/10.0) && a.l == 1);
},

// equal operators
CASE("Rect == Rect operator works correctly"){
	flow::Rect a(10, 20, 30, 40, 50, 60);
	flow::Rect b(10, 20, 30, 40, 50, 60);
	flow::Rect c(60, 50, 40, 30, 20, 10);
	EXPECT(a == b);
	EXPECT( !(a == c) );
},
CASE("Rect == double operator works correctly"){
	flow::Rect a(20, 20, 20, 20, 20, 20);
	double b = 20;
	double c = 30;
	EXPECT(a == b);
	EXPECT( !(a == c) );
},
CASE("Rect != Rect operator works correctly"){
	flow::Rect a(10, 20, 30, 40, 50, 60);
	flow::Rect b(60, 50, 40, 30, 20, 10);
	flow::Rect c(10, 20, 30, 40, 50, 60);
	EXPECT(a != b);
	EXPECT( !(a != c) );
},
CASE("Rect != double operator works correctly"){
	flow::Rect a(20, 20, 20, 20, 20, 20);
	double b = 30;
	double c = 20;
	EXPECT(a != b);
	EXPECT( !(a != c) );
},

// methods
CASE("Rect to_string method works returns correct results"){
	flow::Rect a(10, 20, 30, 40, 50, 60);
	EXPECT(a.to_string() == ("Rect{x: "+std::to_string(10.0)+", y: "+std::to_string(20.0)+", z: "+std::to_string(30.0)+", w: "+std::to_string(40.0)+", h: "+std::to_string(50.0)+", l: "+std::to_string(60.0)+"}") );
},
CASE("EntityCollector add, get_by_name and size works correctly."){
	flow::EntityCollector entity_collector;
	//creating some sample tests entities.
	entity_collector.add( std::make_shared<TestEntity>("test1") );
	entity_collector.add( std::make_shared<TestEntity>("test2") );

	try{
		//expecting some simple questions to be answered as true. test1 should exist and have its name and test2 should do the same.
		EXPECT( (entity_collector.get_by_name("test1")->get_name() == "test1") );
		EXPECT( (entity_collector.get_by_name("test2")->get_name() == "test2") );
		EXPECT(entity_collector.size() == 2); // entire entity list should also be 2 items in size.
	} catch(flow::exception::EntityFindByName& e) {
		EXPECT(false); // if the questions are answered false then the test fails. If the get_by_name method doesn't find any entity then it should throw an exception.
	}
	
	EXPECT_THROWS( (entity_collector.get_by_name("test3")->get_name() == "test3") ); // expect it to throw because test3 doesn't exist.
},
CASE("EntityCollector add, get_by_group and size works correctly."){
	flow::EntityCollector entity_collector;
	//creating some sample tests entities. First parameter is entity name and second is group name.
	entity_collector.add( std::make_shared<TestEntity>("test1", "g1") );
	entity_collector.add( std::make_shared<TestEntity>("test2", "g2") );
	entity_collector.add( std::make_shared<TestEntity>("test3", "g1") );
	entity_collector.add( std::make_shared<TestEntity>("test4", "g2") );
	entity_collector.add( std::make_shared<TestEntity>("test5", "g1") );
	try{
		//expecting some simple questions to be answered as true.
		flow::EntityMap entities = entity_collector.get_by_group("g2");
		EXPECT(entities.size() == 2);
		int how_much_found = 0;
		for(flow::EntityPair& pair: entities) {
			if(pair.entity->get_name() == "test2") how_much_found++;
			if(pair.entity->get_name() == "test4") how_much_found++;
		}
		EXPECT( (how_much_found == entities.size()) );

		flow::EntityMap entities2 = entity_collector.get_by_group("g1");
		EXPECT(entities2.size() == 3);
		how_much_found = 0;
		for(flow::EntityPair& pair: entities2) {
			if(pair.entity->get_name() == "test1") how_much_found++;
			if(pair.entity->get_name() == "test3") how_much_found++;
			if(pair.entity->get_name() == "test5") how_much_found++;
		}
		EXPECT( (how_much_found == entities2.size()) );
	} catch(flow::exception::EntityFindByGroup& e) {
		EXPECT(false);
	}
	EXPECT_THROWS( (entity_collector.get_by_group("g3").size() > 0) );
},
CASE("EntityCollector add, get_by_name, size and remove_by_name works correctly."){
	flow::EntityCollector entity_collector;
	//creating some sample tests entities.
	entity_collector.add( std::make_shared<TestEntity>("test1") );
	entity_collector.add( std::make_shared<TestEntity>("test2") );
	entity_collector.add( std::make_shared<TestEntity>("test3") );

	try{
		//expecting some simple questions to be answered as true. test1 should exist and have its name and test2 should do the same.
		EXPECT( (entity_collector.get_by_name("test1")->get_name() == "test1") );
		EXPECT( (entity_collector.get_by_name("test2")->get_name() == "test2") );
		EXPECT( (entity_collector.get_by_name("test3")->get_name() == "test3") );
		EXPECT(entity_collector.size() == 3); // entire entity list should also be 2 items in size.
	} catch(flow::exception::EntityFindByName& e) {
		EXPECT(false); // if the questions are answered false then the test fails. If the get_by_name method doesn't find any entity then it should throw an exception.
	}
	
	EXPECT_NO_THROW( entity_collector.remove_by_name("test3") );
	EXPECT_THROWS( entity_collector.remove_by_name("test3") );
	EXPECT(entity_collector.size() == 2);

	EXPECT_THROWS( (entity_collector.get_by_name("test3")->get_name() == "test3") ); // expect it to throw because test3 doesn't exist.
},
CASE("EntityCollector add, get_by_group, size and remove_by_group works correctly."){
	flow::EntityCollector entity_collector;
	//creating some sample tests entities. First parameter is entity name and second is group name.
	entity_collector.add( std::make_shared<TestEntity>("test1", "g1") );
	entity_collector.add( std::make_shared<TestEntity>("test2", "g2") );
	entity_collector.add( std::make_shared<TestEntity>("test3", "g1") );
	entity_collector.add( std::make_shared<TestEntity>("test4", "g2") );
	entity_collector.add( std::make_shared<TestEntity>("test5", "g1") );
	try{
		//expecting some simple questions to be answered as true.
		flow::EntityMap entities = entity_collector.get_by_group("g2");
		EXPECT(entities.size() == 2);
		int how_much_found = 0;
		for(flow::EntityPair& pair: entities) {
			if(pair.entity->get_name() == "test2") how_much_found++;
			if(pair.entity->get_name() == "test4") how_much_found++;
		}
		EXPECT( (how_much_found == entities.size()) );

		flow::EntityMap entities2 = entity_collector.get_by_group("g1");
		EXPECT(entities2.size() == 3);
		how_much_found = 0;
		for(flow::EntityPair& pair: entities2) {
			if(pair.entity->get_name() == "test1") how_much_found++;
			if(pair.entity->get_name() == "test3") how_much_found++;
			if(pair.entity->get_name() == "test5") how_much_found++;
		}
		EXPECT( (how_much_found == entities2.size()) );
	} catch(flow::exception::EntityFindByGroup& e) {
		EXPECT(false);
	}

	EXPECT_NO_THROW( entity_collector.remove_by_group("g1") );
	EXPECT_THROWS( (entity_collector.get_by_group("g1").size() > 0) );
	EXPECT_THROWS( entity_collector.remove_by_group("g1") );

	try {
		//expecting some simple questions to be answered as true.
		flow::EntityMap entities = entity_collector.get_by_group("g2");
		EXPECT(entities.size() == 2);
		int how_much_found = 0;
		for(flow::EntityPair& pair: entities) {
			if(pair.entity->get_name() == "test2") how_much_found++;
			if(pair.entity->get_name() == "test4") how_much_found++;
		}
		EXPECT( (how_much_found == entities.size()) );
	} catch(flow::exception::EntityFindByGroup& e) {
		EXPECT(false);
	}

	EXPECT_THROWS( (entity_collector.get_by_group("g3").size() > 0) );
},
lest::test{"Ray constructor, set_direction and get_direction works correctly.", proper_direction_test},
lest::test{"Point on ray collision detection test.", proper_point_collision_detection_test},
lest::test{"TESTOWY", [](){EXPECT(true);}}, //TODO: weź to kurwa popraw xD
};
}