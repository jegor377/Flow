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