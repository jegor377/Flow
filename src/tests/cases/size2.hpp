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