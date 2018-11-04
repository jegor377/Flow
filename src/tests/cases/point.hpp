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