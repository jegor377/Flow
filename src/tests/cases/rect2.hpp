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