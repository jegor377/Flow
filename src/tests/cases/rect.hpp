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