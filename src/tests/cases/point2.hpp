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