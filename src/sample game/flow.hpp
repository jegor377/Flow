#pragma once

#include <vector>
#include <string>
#include <cstring>
#include <exception>
#include <algorithm>
#include <memory>
#include <initializer_list>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <iostream>

namespace flow {
// Wrapper CPP imports:
//interfaces
class StringRepresentator {
	virtual std::string to_string() = 0;
};
//physical metrics
class Point2: public StringRepresentator {
public:
	double x;
	double y;

	Point2(const Point2& other) {
		this->x = other.x;
		this->y = other.y;
	}

	Point2(double x=0, double y=0): StringRepresentator() {
		this->x=x;
		this->y=y;
	}

	std::string to_string() {
		return "Point2{x: "+std::to_string(this->x)+", y: "+std::to_string(this->y)+"}";
	}

	Point2 operator+(Point2& other) {
		return Point2(this->x + other.x, this->y + other.y);
	}

	Point2 operator-(Point2& other) {
		return Point2(this->x - other.x, this->y - other.y);
	}

	Point2 operator*(Point2& other) {
		return Point2(this->x * other.x, this->y * other.y);
	}

	Point2 operator/(Point2& other) {
		return Point2(this->x / other.x, this->y / other.y);
	}

	void operator+=(Point2& other) {
		this->x = this->x + other.x;
		this->y = this->y + other.y;
	}

	void operator-=(Point2& other) {
		this->x = this->x - other.x;
		this->y = this->y - other.y;
	}

	void operator*=(Point2& other) {
		this->x = this->x * other.x;
		this->y = this->y * other.y;
	}

	void operator/=(Point2& other) {
		this->x = this->x / other.x;
		this->y = this->y / other.y;
	}

	Point2 operator+(double val) {
		return Point2(this->x + val, this->y + val);
	}

	Point2 operator-(double val) {
		return Point2(this->x - val, this->y - val);
	}

	Point2 operator*(double val) {
		return Point2(this->x * val, this->y * val);
	}

	Point2 operator/(double val) {
		return Point2(this->x / val, this->y / val);
	}

	void operator+=(double val) {
		this->x = this->x + val;
		this->y = this->y + val;
	}

	void operator-=(double val) {
		this->x = this->x - val;
		this->y = this->y - val;
	}

	void operator*=(double val) {
		this->x = this->x * val;
		this->y = this->y * val;
	}

	void operator/=(double val) {
		this->x = this->x / val;
		this->y = this->y / val;
	}

	bool is_equal(Point2& other) {
		return (this->x == other.x) && (this->y == other.y);
	}

	bool is_equal(double val) {
		return (this->x == val) && (this->y == val);
	}

	bool operator==(Point2& other) {
		return this->is_equal(other);
	}

	bool operator!=(Point2& other) {
		return !this->is_equal(other);
	}

	bool operator==(double val) {
		return this->is_equal(val);
	}

	bool operator!=(double val) {
		return !this->is_equal(val);
	}
};

Point2 operator+(double val, Point2& src) {
	return src+val;
}

Point2 operator*(double val, Point2& src) {
	return src*val;
}

class Point : public Point2 {
public:
	double z=0;
	Point(double x=0, double y=0, double z=0) : Point2(x, y) {
		this->z = z;
	}

	std::string to_string() {
		return "Point{x: "+std::to_string(this->x)+", y: "+std::to_string(this->y)+", z: "+std::to_string(this->z)+ "}";
	}

	Point operator+(Point& other) {
		return Point(this->x + other.x, this->y + other.y, this->z + other.z);
	}

	Point operator-(Point& other) {
		return Point(this->x - other.x, this->y - other.y, this->z - other.z);
	}

	Point operator*(Point& other) {
		return Point(this->x * other.x, this->y * other.y, this->z * other.z);
	}

	Point operator/(Point& other) {
		return Point(this->x / other.x, this->y / other.y, this->z / other.z);
	}

	void operator+=(Point& other) {
		this->x = this->x + other.x;
		this->y = this->y + other.y;
		this->z = this->z + other.z;
	}

	void operator-=(Point& other) {
		this->x = this->x - other.x;
		this->y = this->y - other.y;
		this->z = this->z - other.z;
	}

	void operator*=(Point& other) {
		this->x = this->x * other.x;
		this->y = this->y * other.y;
		this->z = this->z * other.z;
	}

	void operator/=(Point& other) {
		this->x = this->x / other.x;
		this->y = this->y / other.y;
		this->z = this->z / other.z;
	}

	Point operator+(double val) {
		return Point(this->x + val, this->y + val, this->z + val);
	}

	Point operator-(double val) {
		return Point(this->x - val, this->y - val, this->z - val);
	}

	Point operator*(double val) {
		return Point(this->x * val, this->y * val, this->z * val);
	}

	Point operator/(double val) {
		return Point(this->x / val, this->y / val, this->z / val);
	}

	void operator+=(double val) {
		this->x = this->x + val;
		this->y = this->y + val;
		this->z = this->z + val;
	}

	void operator-=(double val) {
		this->x = this->x - val;
		this->y = this->y - val;
		this->z = this->z - val;
	}

	void operator*=(double val) {
		this->x = this->x * val;
		this->y = this->y * val;
		this->z = this->z * val;
	}

	void operator/=(double val) {
		this->x = this->x / val;
		this->y = this->y / val;
		this->z = this->z / val;
	}

	bool is_equal(Point& other) {
		return this->Point2::is_equal( *(Point2*)(&other) ) && this->z == other.z;
	}

	bool is_equal(double val) {
		return this->Point2::is_equal( val ) && this->z == val;
	}

	bool operator==(Point& other) {
		return this->is_equal(other);
	}

	bool operator!=(Point& other) {
		return !this->is_equal(other);
	}

	bool operator==(double val) {
		return this->is_equal(val);
	}

	bool operator!=(double val) {
		return !this->is_equal(val);
	}
};

Point operator+(double val, Point& src) {
	return src+val;
}

Point operator*(double val, Point& src) {
	return src*val;
}
class Vector : public Point {
public:

	Vector() : Point(0, 0, 0) {};
	Vector(double val) : Point(val, val, val) {};
	Vector(double x, double y, double z) : Point(x, y, z) {};

	void add(Vector& other) {
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}

	void sub(Vector& other) {
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
	}

	void mul(Vector& other) {
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
	}

	void div(Vector& other) {
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
	}

	void add_val(double x) {
		this->x += x;
		this->y += x;
		this->z += x;
	}

	void sub_val(double x) {
		this->x -= x;
		this->y -= x;
		this->z -= x;
	}

	void mul_by_val(double x) {
		this->x *= x;
		this->y *= x;
		this->z *= x;
	}

	void div_by_val(double x) {
		this->x /= x;
		this->y /= x;
		this->z /= x;
	}
};

// TODO: Change name to new_scale_of
Vector new_scale(double scale) {
	return Vector(scale);;
}
class Size2: public StringRepresentator {
public:
	double w; // width
	double h; // height
	Size2(double w=0, double h=0): StringRepresentator() {
		this->w=w;
		this->h=h;
	}

	std::string to_string() {
		return "Size2{w: "+std::to_string(this->w)+", h: "+std::to_string(this->h)+"}";
	}

	Size2 operator+(Size2& other) {
		return Size2(this->w + other.w, this->h + other.h);
	}

	Size2 operator-(Size2& other) {
		return Size2(this->w - other.w, this->h - other.h);
	}

	Size2 operator*(Size2& other) {
		return Size2(this->w * other.w, this->h * other.h);
	}

	Size2 operator/(Size2& other) {
		return Size2(this->w / other.w, this->h / other.h);
	}

	void operator+=(Size2& other) {
		this->w = this->w + other.w;
		this->h = this->h + other.h;
	}

	void operator-=(Size2& other) {
		this->w = this->w - other.w;
		this->h = this->h - other.h;
	}

	void operator*=(Size2& other) {
		this->w = this->w * other.w;
		this->h = this->h * other.h;
	}

	void operator/=(Size2& other) {
		this->w = this->w / other.w;
		this->h = this->h / other.h;
	}

	Size2 operator+(double val) {
		return Size2(this->w + val, this->h + val);
	}

	Size2 operator-(double val) {
		return Size2(this->w - val, this->h - val);
	}

	Size2 operator*(double val) {
		return Size2(this->w * val, this->h * val);
	}

	Size2 operator/(double val) {
		return Size2(this->w / val, this->h / val);
	}

	void operator+=(double val) {
		this->w = this->w + val;
		this->h = this->h + val;
	}

	void operator-=(double val) {
		this->w = this->w - val;
		this->h = this->h - val;
	}

	void operator*=(double val) {
		this->w = this->w * val;
		this->h = this->h * val;
	}

	void operator/=(double val) {
		this->w = this->w / val;
		this->h = this->h / val;
	}

	bool is_equal(Size2& other) {
		return (this->w == other.w) && (this->h == other.h);
	}

	bool is_equal(double val) {
		return (this->w == val) && (this->h == val);
	}

	bool operator==(Size2& other) {
		return this->is_equal(other);
	}

	bool operator!=(Size2& other) {
		return !this->is_equal(other);
	}

	bool operator==(double val) {
		return this->is_equal(val);
	}

	bool operator!=(double val) {
		return !this->is_equal(val);
	}
};

Size2 operator+(double val, Size2& src) {
	return src+val;
}

Size2 operator*(double val, Size2& src) {
	return src*val;
}

class Size : public Size2 {
public:
	double l; // length

	Size(double w=0, double h=0, double l=0) : Size2(w, h) {
		this->l=l;
	}

	std::string to_string() {
		return "Size{w: "+std::to_string(this->w)+", h: "+std::to_string(this->h)+", l: "+std::to_string(this->l)+"}";
	}

	Size operator+(Size& other) {
		return Size(this->w + other.w, this->h + other.h, this->l + other.l);
	}

	Size operator-(Size& other) {
		return Size(this->w - other.w, this->h - other.h, this->l - other.l);
	}

	Size operator*(Size& other) {
		return Size(this->w * other.w, this->h * other.h, this->l * other.l);
	}

	Size operator/(Size& other) {
		return Size(this->w / other.w, this->h / other.h, this->l / other.l);
	}

	void operator+=(Size& other) {
		this->w = this->w + other.w;
		this->h = this->h + other.h;
		this->l = this->l + other.l;
	}

	void operator-=(Size& other) {
		this->w = this->w - other.w;
		this->h = this->h - other.h;
		this->l = this->l - other.l;
	}

	void operator*=(Size& other) {
		this->w = this->w * other.w;
		this->h = this->h * other.h;
		this->l = this->l * other.l;
	}

	void operator/=(Size& other) {
		this->w = this->w / other.w;
		this->h = this->h / other.h;
		this->l = this->l / other.l;
	}

	Size operator+(double val) {
		return Size(this->w + val, this->h + val, this->l + val);
	}

	Size operator-(double val) {
		return Size(this->w - val, this->h - val, this->l - val);
	}

	Size operator*(double val) {
		return Size(this->w * val, this->h * val, this->l * val);
	}

	Size operator/(double val) {
		return Size(this->w / val, this->h / val, this->l / val);
	}

	void operator+=(double val) {
		this->w = this->w + val;
		this->h = this->h + val;
		this->l = this->l + val;
	}

	void operator-=(double val) {
		this->w = this->w - val;
		this->h = this->h - val;
		this->l = this->l - val;
	}

	void operator*=(double val) {
		this->w = this->w * val;
		this->h = this->h * val;
		this->l = this->l * val;
	}

	void operator/=(double val) {
		this->w = this->w / val;
		this->h = this->h / val;
		this->l = this->l / val;
	}

	bool is_equal(Size& other) {
		return this->Size2::is_equal( *(Size2*)(&other) ) && this->l == other.l;
	}

	bool is_equal(double val) {
		return this->Size2::is_equal( val ) && this->l == val;
	}

	bool operator==(Size& other) {
		return this->is_equal(other);
	}

	bool operator!=(Size& other) {
		return !this->is_equal(other);
	}

	bool operator==(double val) {
		return this->is_equal(val);
	}

	bool operator!=(double val) {
		return !this->is_equal(val);
	}
};

Size operator+(double val, Size& src) {
	return src+val;
}

Size operator*(double val, Size& src) {
	return src*val;
}
enum RectMode {
	SECTION = 0,
	FULL = 1
};

// TODO: Add division by 0 exception.
class Rect2 : public Point2, public Size2 {
	SDL_Rect sdl_representation;
public:
	RectMode mode;

	Rect2(double x=0, double y=0, double w=0, double h=0, RectMode mode=FULL) : Point2(x, y), Size2(w, h) {
		this->mode = mode;
	};

	Rect2(const Rect2& other) {
		this->x = other.x;
		this->y = other.y;
		this->w = other.w;
		this->h = other.h;
		this->mode = other.mode;
	}

	std::string to_string() {
		return "Rect2{x: "+std::to_string(this->x)+", y: "+std::to_string(this->y)+", w: "+std::to_string(this->w)+", h: "+std::to_string(this->h)+", mode: "+(this->mode == SECTION ? "SECTION" : "FULL")+"}";
	}

	SDL_Rect* get_sdl_rect() {
		if(this->mode == SECTION) {
			this->sdl_representation.x = this->x;
			this->sdl_representation.y = this->y;
			this->sdl_representation.w = this->w;
			this->sdl_representation.h = this->h;
			return &this->sdl_representation;
		}
		return NULL;
	}

	Rect2 operator+(Rect2& other) {
		return Rect2(this->x + other.x, this->y + other.y, this->w + other.w, this->h + other.h, this->mode);
	}

	Rect2 operator-(Rect2& other) {
		return Rect2(this->x - other.x, this->y - other.y, this->w - other.w, this->h - other.h, this->mode);
	}

	Rect2 operator*(Rect2& other) {
		return Rect2(this->x * other.x, this->y * other.y, this->w * other.w, this->h *+ other.h, this->mode);
	}

	Rect2 operator/(Rect2& other) {
		return Rect2(this->x / other.x, this->y / other.y, this->w / other.w, this->h / other.h, this->mode);
	}

	void operator+=(Rect2& other) {
		this->Point2::operator+=( *(Point2*)(&other) );
		this->Size2::operator+=( *(Size2*)(&other) );
	}

	void operator-=(Rect2& other) {
		this->Point2::operator-=( *(Point2*)(&other) );
		this->Size2::operator-=( *(Size2*)(&other) );
	}

	void operator*=(Rect2& other) {
		this->Point2::operator*=( *(Point2*)(&other) );
		this->Size2::operator*=( *(Size2*)(&other) );
	}

	void operator/=(Rect2& other) {
		this->Point2::operator/=( *(Point2*)(&other) );
		this->Size2::operator/=( *(Size2*)(&other) );
	}

	Rect2 operator+(double val) {
		return Rect2(this->x + val, this->y + val, this->w + val, this->h + val, this->mode);
	}

	Rect2 operator-(double val) {
		return Rect2(this->x - val, this->y - val, this->w - val, this->h - val, this->mode);
	}

	Rect2 operator*(double val) {
		return Rect2(this->x * val, this->y * val, this->w * val, this->h * val, this->mode);
	}

	Rect2 operator/(double val) {
		return Rect2(this->x / val, this->y / val, this->w / val, this->h / val, this->mode);
	}

	void operator+=(double val) {
		this->Point2::operator+=( val );
		this->Size2::operator+=( val );
	}

	void operator-=(double val) {
		this->Point2::operator-=( val );
		this->Size2::operator-=( val );
	}

	void operator*=(double val) {
		this->Point2::operator*=( val );
		this->Size2::operator*=( val );
	}

	void operator/=(double val) {
		this->Point2::operator/=( val );
		this->Size2::operator/=( val );
	}

	// Returns true if all position and size values are equal. Doesn't take mode into account.
	bool is_vequal(Rect2& other) {
		return this->Point2::is_equal( *(Point2*)(&other) ) && this->Size2::is_equal( *(Size2*)(&other) );
	}

	// Returns true if all position, size and mode values are equal. Takes mode into account.
	bool is_equal(Rect2& other) {
		return this->is_vequal(other) && this->mode == other.mode;
	}

	// Returns true if all position, size are equal to value.
	bool is_equal(double val) {
		return this->Point2::is_equal( val ) && this->Size2::is_equal( val );
	}

	bool operator==(Rect2& other) {
		return this->is_equal(other);
	}

	bool operator!=(Rect2& other) {
		return !this->is_equal(other);
	}

	bool operator==(double val) {
		return this->is_equal(val);
	}

	bool operator!=(double val) {
		return !this->is_equal(val);
	}

	void set_pos(const Point2& new_pos) {
		this->x = new_pos.x;
		this->y = new_pos.y;
	}

	void set_size(const Size2& new_size) {
		this->w = new_size.w;
		this->h = new_size.h;
	}

	void operator+=(Point2& pos) {
		this->Point2::operator+=( pos );
	}

	void operator-=(Point2& pos) {
		this->Point2::operator-=( pos );
	}

	void operator*=(Point2& pos) {
		this->Point2::operator*=( pos );
	}

	void operator/=(Point2& pos) {
		this->Point2::operator/=( pos );
	}

	void operator+=(Size2& size) {
		this->Size2::operator+=( size );
	}

	void operator-=(Size2& size) {
		this->Size2::operator-=( size );
	}

	void operator*=(Size2& size) {
		this->Size2::operator*=( size );
	}

	void operator/=(Size2& size) {
		this->Size2::operator/=( size );
	}

	void add_pos(Point2& other) {
		this->x += other.x;
		this->y += other.y;
	}

	void sub_pos(Point2& other) {
		this->x -= other.x;
		this->y -= other.y;
	}

	void mul_pos(Point2& other) {
		this->x *= other.x;
		this->y *= other.y;
	}

	void div_pos(Point2& other) {
		this->x /= other.x;
		this->y /= other.y;
	}

	void add_size(Size2& other) {
		this->w += other.w;
		this->h += other.h;
	}

	void sub_size(Size2& other) {
		this->w -= other.w;
		this->h -= other.h;
	}

	void mul_size(Size2& other) {
		this->w *= other.w;
		this->h *= other.h;
	}

	void div_size(Size2& other) {
		this->w /= other.w;
		this->h /= other.h;
	}
};

Rect2 operator+(double val, Rect2& src) {
	return src+val;
}
Rect2 operator*(double val, Rect2& src) {
	return src*val;
}

struct Rect : public Point, public Size {
public:
	Rect(double x=0, double y=0, double z=0, double w=0, double h=0, double l=0) : Point(x, y, z), Size(w, h, l) {};

	std::string to_string() {
		return "Rect{x: "+std::to_string(this->x)+", y: "+std::to_string(this->y)+", z: "+std::to_string(this->z)+", w: "+std::to_string(this->w)+", h: "+std::to_string(this->h)+", l: "+std::to_string(this->l)+"}";
	}

	Rect operator+(Rect& other) {
		return Rect(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w, this->h + other.h, this->l + other.l);
	}

	Rect operator-(Rect& other) {
		return Rect(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w, this->h - other.h, this->l - other.l);
	}

	Rect operator*(Rect& other) {
		return Rect(this->x * other.x, this->y * other.y, this->z * other.z, this->w * other.w, this->h *+ other.h, this->l * other.l);
	}

	Rect operator/(Rect& other) {
		return Rect(this->x / other.x, this->y / other.y, this->z / other.z, this->w / other.w, this->h / other.h, this->l / other.l);
	}

	void operator+=(Rect& other) {
		this->Point::operator+=( *(Point*)(&other) );
		this->Size::operator+=( *(Size*)(&other) );
	}

	void operator-=(Rect& other) {
		this->Point::operator-=( *(Point*)(&other) );
		this->Size::operator-=( *(Size*)(&other) );
	}

	void operator*=(Rect& other) {
		this->Point::operator*=( *(Point*)(&other) );
		this->Size::operator*=( *(Size*)(&other) );
	}

	void operator/=(Rect& other) {
		this->Point::operator/=( *(Point*)(&other) );
		this->Size::operator/=( *(Size*)(&other) );
	}

	Rect operator+(double val) {
		return Rect(this->x + val, this->y + val, this->z + val, this->w + val, this->h + val, this->l + val);
	}

	Rect operator-(double val) {
		return Rect(this->x - val, this->y - val, this->z - val, this->w - val, this->h - val, this->l - val);
	}

	Rect operator*(double val) {
		return Rect(this->x * val, this->y * val, this->z * val, this->w * val, this->h * val, this->l * val);
	}

	Rect operator/(double val) {
		return Rect(this->x / val, this->y / val, this->z / val, this->w / val, this->h / val, this->l / val);
	}

	void operator+=(double val) {
		this->Point::operator+=( val );
		this->Size::operator+=( val );
	}

	void operator-=(double val) {
		this->Point::operator-=( val );
		this->Size::operator-=( val );
	}

	void operator*=(double val) {
		this->Point::operator*=( val );
		this->Size::operator*=( val );
	}

	void operator/=(double val) {
		this->Point::operator/=( val );
		this->Size::operator/=( val );
	}

	bool is_equal(Rect& other) {
		return this->Point::is_equal( *(Point*)(&other) ) && this->Size::is_equal( *(Size*)(&other) );
	}

	// Returns true if all position, size are equal to value.
	bool is_equal(double val) {
		return this->Point::is_equal( val ) && this->Size::is_equal( val );
	}

	bool operator==(Rect& other) {
		return this->is_equal(other);
	}

	bool operator!=(Rect& other) {
		return !this->is_equal(other);
	}

	bool operator==(double val) {
		return this->is_equal(val);
	}

	bool operator!=(double val) {
		return !this->is_equal(val);
	}

	void operator+=(Point& pos) {
		this->Point::operator+=( pos );
	}

	void operator-=(Point& pos) {
		this->Point::operator-=( pos );
	}

	void operator*=(Point& pos) {
		this->Point::operator*=( pos );
	}

	void operator/=(Point& pos) {
		this->Point::operator/=( pos );
	}

	void operator+=(Size& size) {
		this->Size::operator+=( size );
	}

	void operator-=(Size& size) {
		this->Size::operator-=( size );
	}

	void operator*=(Size& size) {
		this->Size::operator*=( size );
	}

	void operator/=(Size& size) {
		this->Size::operator/=( size );
	}

	void add_val(double x) {
		this->x += x;
		this->y += x;
		this->z += x;
	}

	void sub_val(double x) {
		this->x -= x;
		this->y -= x;
		this->z -= x;
	}

	void mul_by_val(double x) {
		this->x *= x;
		this->y *= x;
		this->z *= x;
	}

	void div_by_val(double x) {
		this->x /= x;
		this->y /= x;
		this->z /= x;
	}

	void add_pos(Rect& other) {
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}

	void add_vector(Vector& other) {
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
	}

	void sub_pos(Rect& other) {
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
	}

	void sub_vector(Vector& other) {
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
	}

	void mul_pos(Rect& other) {
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
	}

	void mul_by_vector(Vector& other) {
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
	}

	void div_pos(Rect& other) {
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
	}

	void div_by_vector(Vector& other) {
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
	}

	void add_size(Rect& other) {
		this->w += other.w;
		this->h += other.h;
		this->l += other.l;
	}

	void sub_size(Rect& other) {
		this->w -= other.w;
		this->h -= other.h;
		this->l -= other.l;
	}

	void mul_size(Rect& other) {
		this->w *= other.w;
		this->h *= other.h;
		this->l *= other.l;
	}

	void mul_size_by_vector(Vector& other) {
		this->w *= other.x;
		this->h *= other.y;
		this->l *= other.z;
	}

	void div_size(Rect& other) {
		this->w /= other.w;
		this->h /= other.h;
		this->l /= other.l;
	}

	Rect2* to_rect2() {
		Rect2* result = new Rect2(this->x, this->y+this->z, this->w, this->h+this->l, SECTION);
		return result;
	}

	Rect2* to_scaled_rect2(Vector scale) {
		Rect2* result = new Rect2(this->x, this->y+this->z, this->w*scale.x, (this->h*scale.y)+(this->l*scale.z), SECTION);
		return result;
	}

	void set_pos(const Point& new_pos) {
		this->x = new_pos.x;
		this->y = new_pos.y;
		this->z = new_pos.z;
	}

	void set_size(const Size& new_size) {
		this->w = new_size.w;
		this->h = new_size.h;
		this->l = new_size.l;
	}

	bool is_colliding(Rect& other) {
		return this->x < other.x + other.w && this->x + this->w > other.x && this->y < other.y + other.h && this->y + this->h > other.y && this->z < other.z + other.l && this->z + this->l > other.z;
	}

	bool is_colliding_with_point(Point& pt) {
		bool is_x_collision = this->x<=pt.x && this->x+this->w>=pt.x;
		bool is_y_collision = this->y<=pt.y && this->y+this->h>=pt.y;
		bool is_z_collision = this->z<=pt.z && this->z+this->l>=pt.z;
		return is_x_collision && is_y_collision && is_z_collision;
	}

	bool is_in_xy_collision(Rect& other) {
		return this->x < other.x + other.w && this->x + this->w > other.x && this->y < other.y + other.h && this->y + this->h > other.y;
	}

	bool is_in_xz_collision(Rect& other) {
		return this->x < other.x + other.w && this->x + this->w > other.x && this->z < other.z + other.l && this->z + this->l > other.z;
	}
};

Rect operator+(double val, Rect& src) {
	return src+val;
}
Rect operator*(double val, Rect& src) {
	return src*val;
}
//sprite exceptions
namespace exception {
	class SpriteAssign: public std::exception {
	public:
		const char* what() const throw() {
			return "Sprite reference not assigned in SharedSprite.";
		}
	};
}
namespace exception {
	class SpriteFind: public std::exception {
		std::string err_msg;
	public:
		SpriteFind(const std::string& name) {
			this->err_msg = "Sprite with name \"" + name + "\" not found.";
		}

		const char* what() const throw() {
			return this->err_msg.c_str();
		}
	};
}
namespace exception {
	class SpriteLoad: public std::exception {
		std::string err_msg;

	public:
		SpriteLoad(const std::string& name, const std::string& path, const char* sdl_err_msg) {
			this->err_msg = "Cannot to load sprite with name \"";
			this->err_msg += name;
			this->err_msg += "\" and path \"";
			this->err_msg += path;
			this->err_msg += "\". SDL error info: ";
			this->err_msg += sdl_err_msg;
			this->err_msg +=".";
		}
		
		const char* what() const throw() {
			return this->err_msg.c_str();
		}
	};
}
//sprite
class Sprite {
	SDL_Texture* texture;
	std::string name;
	std::string path;

public:
	Sprite(const std::string& name, const std::string& path) {
		this->texture = NULL;
		this->name = name;
		this->path = path;
	}

	~Sprite() {
		this->remove_sprite();
	}
private:
	void remove_sprite() {
		if(this->texture != NULL) {
			SDL_DestroyTexture(this->texture);
			this->texture = NULL;
		}
	}
public:
	friend class SpriteCollector;
	friend class Flow;

	const Size2* get_size() {
		if(this->texture != NULL) {
			int w, h;
			SDL_QueryTexture(this->texture, NULL, NULL, &w, &h);
			return new Size2(w, h);
		} else return NULL;
	}

	const std::string get_name() {
		return this->name;
	}

	const std::string get_path() {
		return this->path;
	}

	bool has_name(const std::string& name) {
		return this->name == name;
	}
};

typedef std::shared_ptr<Sprite> SpritePtr;
class SharedSprite {
public:
	SpritePtr sprite;
	Rect2 source_section;

	SharedSprite() {
		this->sprite.reset();
	}

	SharedSprite(SpritePtr sprite) {
		this->sprite = sprite;
	}

	SharedSprite(SpritePtr sprite, Rect2 source_section) {
		this->sprite = sprite;
		this->source_section = source_section;
	}

	const Size2* get_size() {
		if(this->sprite) return this->sprite->get_size();
		throw exception::SpriteAssign();
	}

	const std::string get_name() {
		if(this->sprite) return this->sprite->get_name();
		throw exception::SpriteAssign();
	}

	const std::string get_path() {
		if(this->sprite) return this->sprite->get_path();
		throw exception::SpriteAssign();
	}

	bool has_name(const std::string& name) {
		if(this->sprite) return this->sprite->has_name(name);
		throw exception::SpriteAssign();
	}
};
//entities
class Entity {
protected:
	std::string name;
	std::string group;
public:
	Rect collider;

	SharedSprite shared_sprite;
	
	bool is_handling_rendering;
	bool is_handling_update;
	bool is_handling_events;

	Vector scale;
private:
	void set_default() {
		this->scale = Vector(1, 1, 1);
		this->is_handling_rendering = true;
		this->is_handling_update = true;
		this->is_handling_events = true;
	}

public:
	Entity() {
		this->set_default();
	}

	Entity(Rect collider, const std::string& name, const std::string& group) {
		this->collider = collider;
		this->name = name;
		this->group = group;
		this->set_default();
	}
	
	virtual void update(double delta) = 0;
	virtual void event(SDL_Event event) = 0;

	const std::string get_name() {
		return this->name;
	}

	const std::string get_group() {
		return this->group;
	}

	bool has_name(const std::string& name) {
		return this->name == name;
	}

	bool is_in_group(const std::string& group) {
		return this->group == group;
	}

	Rect get_scaled_collider() {
		Rect result = this->collider;
		result.mul_size_by_vector(this->scale);
		return result;
	}

	bool is_scaled_colliding(std::shared_ptr<Entity> body) {
		Rect other = body->get_scaled_collider();
		return this->get_scaled_collider().is_colliding(other);
	}

	bool is_scaled_colliding(Entity* body) {
		Rect other = body->get_scaled_collider();
		return this->get_scaled_collider().is_colliding(other);
	}

	bool is_in_xy_collision(std::shared_ptr<Entity> body) {
		Rect other = body->get_scaled_collider();
		return this->get_scaled_collider().is_in_xy_collision(other);
	}

	bool is_in_xz_collision(std::shared_ptr<Entity> body) {
		Rect other = body->get_scaled_collider();
		return this->get_scaled_collider().is_in_xz_collision(other);
	}

	void move(Vector& movement) {
		this->collider.add_vector(movement);
	}
};

typedef std::shared_ptr<Entity> EntityPtr;
//types
typedef SDL_Window* Window;
typedef SDL_Renderer* Renderer;
//logger
namespace log {
	void info(const std::string& msg) {
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
	}

	void warn(const std::string& msg) {
		SDL_LogWarn(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
	}

	void error(const std::string& msg) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
	}

	void debug(const std::string& msg) {
		SDL_LogDebug(SDL_LOG_CATEGORY_APPLICATION, msg.c_str());
	}

	// special functions
	// logs warn when sdl reported error and flow fixed it somehow.
	void sdl_fix_warn(const std::string& error_source, const std::string& fix_way, const char* sdl_error_msg) {
		std::string msg = error_source+" reported error (\""+std::string(sdl_error_msg)+"\"). It has been fixed. Fix way: "+fix_way+".";
		warn(msg);
	}
}
//exceptions
namespace exception {
	class Init: public std::exception {
		std::string err_msg;

	public:
		Init(const char* sdl_err_msg) {
			this->err_msg = "Cannot to init due to SDL2 error: " + std::string(sdl_err_msg) + ".";
		}

		const char* what() const throw() {
			return this->err_msg.c_str();
		}
	};
}
namespace exception {
	class Window: public std::exception {
		std::string err_msg;

	public:
		//TODO: Find out why it doesn't work.
		Window(const std::string& err_msg, const char* sdl_err_msg) {
			this->err_msg = err_msg + ". SDL2 error message: " + std::string(sdl_err_msg) + ".";
		}

		const char* what() const throw() {
			return this->err_msg.c_str();
		}
	};
}
namespace exception {
	class EntityFindByName: public std::exception {
		std::string err_msg;
	public:
		EntityFindByName(const std::string& name) {
			this->err_msg = "Entity with name \"" + name + "\" not found.";
		}

		const char* what() const throw() {
			return this->err_msg.c_str();
		}
	};

	class EntityFindByGroup: public std::exception {
		std::string err_msg;
	public:
		EntityFindByGroup(const std::string& group) {
			this->err_msg = "Entity with group name \"" + group + "\" not found.";
		}

		const char* what() const throw() {
			return this->err_msg.c_str();
		}
	};
}
//collectors
struct EntityPair {
	int id;
	EntityPtr entity;
};

typedef std::vector<EntityPtr> EntityList;
typedef std::vector<EntityPair> EntityMap;

class EntityCollector {
	EntityList entities;
public:

	friend class Flow;

	~EntityCollector() {
		entities.clear();
	}
	
	/**
	 *  \brief Adds new entity to the collector.
	 *
	 *  \param entity New entity handler.
	 */
	void add(EntityPtr entity) {
		this->entities.push_back(entity);
	}

	/**
	 *  \brief Returns size of entities list.
	 *
	 */
	unsigned int size() {
		return this->entities.size();
	}

	/**
	 *  \brief Removes the first entity that possesses specified name.
	 *
	 *  \param name Entity's name.
	 */
	void remove_by_name(const std::string& name) {
		this->entities.erase(this->find_by_name(name));
	}

	/**
	 *  \brief Removes all entites that belongs to the specified group.
	 *
	 *  \param group Entities' group name.
	 */
	void remove_by_group(const std::string& group) {
		auto found_entities = this->find_by_group(group);
		for(int i = found_entities.size()-1; i >= 0; i--) {
			this->entities.erase(this->entities.begin()+found_entities[i].id);
		}
	}

	/**
	 *  \brief Finds the first entity that possesses specified name.
	 *
	 *  \param name Entity's name.
	 *  \return Entity's shared pointer.
	 */
	EntityPtr get_by_name(const std::string& name) {
		auto result = this->find_by_name(name);
		return *result;
	}

	/**
	 *  \brief Finds all entites that belongs to the specified group.
	 *
	 *  \param group Entities' group name.
	 *  \return Map of entities' pointers and it's poisitions in Entity Collector.
	 */
	EntityMap get_by_group(const std::string& group) {
		return find_by_group(group);
	}

	EntityList get_sorted_for_display() {
		EntityList result = this->entities; // DON'T CHANGE THIS. IT HAS TO BE PASSED WITH RESULT.
		std::sort(result.begin(), result.end(), [](EntityPtr& e1, EntityPtr& e2){
			const double e1_y_point = (e1->collider.y+e1->collider.h*e1->scale.y/2);
			const double e2_y_point = (e2->collider.y+e2->collider.h*e2->scale.y/2);
			if(e1->is_in_xy_collision(e2)) {
				return e1->collider.z <= e2->collider.z;
			}
			return e1_y_point > e2_y_point;
		});
		// It's sorting entities based on theirs z and y. If an entity is farther from the player it's displayed first.
		// Otherwise it displays what is under something first.
		return result;
	}

private:
	/**
	 *  \brief Finds the first entity that possesses specified name.
	 *
	 *  \param name Entity's name.
	 *  \return Entity's iterator from Entity Collector entities list.
	 */
	EntityList::iterator find_by_name(const std::string& name) {
		auto entity_iterator = std::find_if(this->entities.begin(), this->entities.end(), [name](EntityPtr e){
			return e->has_name(name);
		});
		if(entity_iterator != this->entities.end()) {
			return entity_iterator;
		}
		throw exception::EntityFindByName(name);
	}

	/**
	 *  \brief Finds all entites that belongs to the specified group.
	 *
	 *  \param group Entities' group name.
	 *  \return Map of entities' pointers and it's poisitions in Entity Collector.
	 */
	EntityMap find_by_group(const std::string& group) {
		EntityMap result;
		for(int entity_id = 0; entity_id < this->entities.size(); entity_id++) {
			if(this->entities[entity_id]->is_in_group(group)) {
				EntityPair new_pair = {entity_id, this->entities[entity_id]};
				result.push_back(new_pair);
			}
		}
		if(result.size()==0) throw exception::EntityFindByGroup(group);
		return result;
	}
};
typedef std::vector<SpritePtr> SpriteList;

class SpriteCollector {
	SpriteList sprites;
public:

	~SpriteCollector() {
		sprites.clear();
	}

	void add(const Renderer canvas, const std::string& name, const std::string& path) {
		auto sprite = std::make_shared<Sprite>(name, path);
		this->sprites.push_back(sprite);
		this->load_sprite(canvas, sprite);
	}

	void remove(const std::string& name) {
		this->sprites.erase(this->find(name));
	}

	SpritePtr get(const std::string& name) {
		return *(this->find(name));
	}
private:
	void load_sprite(const Renderer canvas, SpritePtr sprite) {
		sprite->texture = IMG_LoadTexture(canvas, sprite->path.c_str());
		if(sprite->texture == NULL) throw exception::SpriteLoad(sprite->name, sprite->path, SDL_GetError());
	}

	SpriteList::iterator find(const std::string& name) {
		auto sprite_iterator = std::find_if(this->sprites.begin(), this->sprites.end(), [name](SpritePtr e){
			return e->has_name(name);
		});
		if(sprite_iterator != this->sprites.end()) {
			return sprite_iterator;
		}
		throw exception::SpriteFind(name);
	}
};
//events
class EventList {
	std::vector<SDL_Event> events;

public:
	~EventList() {
		this->events.clear();
	}

	void add(SDL_Event event) {
		this->events.push_back(event);
	}

	std::vector<SDL_Event> get() {
		return this->events;
	}
};


const Point2 WINDOW_CENTER(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
const int DEFAULT_INIT_FLAGS = SDL_INIT_VIDEO|SDL_INIT_AUDIO;
const int DEFAULT_IMG_INIT_FLAGS = IMG_INIT_PNG|IMG_INIT_JPG;

enum ScreenMode {
	FULLSCREEN = SDL_WINDOW_FULLSCREEN,
	WINDOW = SDL_WINDOW_OPENGL
};

class Flow {
	Window window;
	Renderer canvas;

	EntityCollector entity_collector;
	SpriteCollector sprite_collector;

	bool is_fixable;
	bool debug;

	Rect2 window_rect;
public:
	ScreenMode scr_mode;
	bool is_running = true;
	Uint64 last_update_time;

	Flow(bool is_fixable=true, bool debug=false) {
		this->debug = debug;
		this->is_fixable = is_fixable;
		this->scr_mode = WINDOW;
		this->last_update_time = SDL_GetPerformanceCounter();
	}

	~Flow() {
		SDL_DestroyRenderer(this->canvas);
		SDL_DestroyWindow(this->window);
	}

	void create_window(const std::string& w_name = "Sample", bool use_vsync=true, Point2 pos=WINDOW_CENTER, Size2 size=Size2(640, 480), ScreenMode scr_mode = WINDOW) {
		this->window_rect.set_pos(pos);
		this->window_rect.set_size(size);
		this->scr_mode = scr_mode;
		this->initialize_window(w_name, pos, size);
		this->initialize_canvas(use_vsync);
	}

	// entity methods
	void add_entity(std::shared_ptr<Entity> entity) {
		entity_collector.add(entity);
	}

	void remove_entity_by_name(const std::string& name) {
		entity_collector.remove_by_name(name);
	}

	void remove_entities_by_group(const std::string& group) {
		entity_collector.remove_by_group(group);
	}

	EntityPtr get_entity_by_name(const std::string& name) {
		return entity_collector.get_by_name(name);
	}

	EntityMap get_entities_by_group(const std::string& group) {
		return entity_collector.get_by_group(group);
	}

	// sprite methods
	void add_sprite(const std::string& name, const std::string& path) {
		sprite_collector.add(this->canvas, name, path);
	}

	void remove_sprite(const std::string& name) {
		sprite_collector.remove(name);
	}

	SpritePtr get_sprite(const std::string& name) {
		return sprite_collector.get(name);
	}

	Rect2 get_window_rect() {
		return this->window_rect;
	}

	EntityList* find_collisions(Entity* body) {
		EntityList* result = new EntityList();
		for(auto other: this->entity_collector.entities) {
			if(other.get() != body) {
				if(body->is_scaled_colliding(other)) {
					result->push_back(other);
				}
			}
		}
		return result;
	}

	void game_loop() {
		while(this->is_running) {
			// Pulling events from event stack.
			auto events = this->get_events();

			// Sorting entities in order to easly render them later. It must be done because algorithm needs to know witch entity goes first and witch to cover.
			auto entities_copy = this->entity_collector.get_sorted_for_display();

			// Calculate game delta time.
			auto update_time_now = SDL_GetPerformanceCounter();
			double delta_time = (double)(update_time_now - this->last_update_time) / (double)SDL_GetPerformanceFrequency();
			this->last_update_time = update_time_now;

			// Clear renderer (canvas).
			if(this->debug) SDL_SetRenderDrawColor(this->canvas, 0, 0, 0, 0);
			SDL_RenderClear(this->canvas);

			// Iteratre through all entities in order to update, handle events and copy their sprites into the screen:)
			for(auto entity : entities_copy) {
				if(entity->is_handling_update) this->update(entity, delta_time);
				if(entity->is_handling_events) this->handle_events(entity, events);
				if(entity->is_handling_rendering) this->render(entity);
			}

			// Present renderer (canvas) on screen.
			SDL_RenderPresent(this->canvas);

			delete events;
		}
	}

private:
	// game stuff
	EventList* get_events() {
		EventList* result = new EventList();
		SDL_Event event;
		while(SDL_PollEvent(&event)) {
			result->add(event);
		}
		return result;
	}

	void handle_events(const EntityPtr& entity, EventList* events) {
		for(auto event: events->get()) {
			entity->event(event);
		}
	}

	void update(const EntityPtr& entity, const double& delta_time) {
		entity->update(delta_time);
	}

	void render(const EntityPtr& entity) {
		auto copy_texture = entity->shared_sprite.sprite->texture;
		Rect2& source_section = entity->shared_sprite.source_section;
		auto destination_rect = entity->collider.to_scaled_rect2(entity->scale);
		SDL_RenderCopyEx(this->canvas, copy_texture, source_section.get_sdl_rect(), destination_rect->get_sdl_rect(), 0.0, NULL, SDL_FLIP_NONE);
		if(this->debug) {
			SDL_SetRenderDrawColor(this->canvas, 255, 0, 0, 255);
			SDL_Rect point = {
				(int)(destination_rect->x+destination_rect->w/2),
				(int)(destination_rect->y+destination_rect->h/2+entity->collider.l*entity->scale.y/2),
				3,
				3
			};
			SDL_RenderFillRect(this->canvas, &point);
		}
		delete destination_rect;
	}

	//initializing methods.
	void initialize_window(const std::string& w_name, Point2& pos, Size2& size) {
		this->window = SDL_CreateWindow(w_name.c_str(), pos.x, pos.y, size.w, size.h, this->scr_mode);
		if(this->window == NULL) {
			throw exception::Window("Cannot to create window", SDL_GetError());
		}
	}

	void initialize_canvas(bool use_vsync) {
		auto renderer_flags = use_vsync ? SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC : SDL_RENDERER_ACCELERATED;
		this->canvas = SDL_CreateRenderer(this->window, -1, renderer_flags);
		if(this->canvas == NULL) {
			const char* error_msg = SDL_GetError();
			// try to fix a problem
			if(!this->fix_create_canvas(error_msg)) {
				throw exception::Window("Cannot to create canvas (renderer)", error_msg);
			}
		}
	}

	//fix methods. Return value says if the problem was fixed.
	bool fix_create_canvas(const char* error_msg) {
		if(this->is_fixable) {
			this->canvas = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);
			if(this->canvas != NULL) {
				log::sdl_fix_warn("SDL_CreateRenderer", "Creating renderer as software fallback (SDL_RENDERER_SOFTWARE)", error_msg);
				return true;
			}
		}
		return false;
	}
};

void init(int sdl_support_flags=DEFAULT_INIT_FLAGS, int img_init_flags=DEFAULT_IMG_INIT_FLAGS, bool is_fixable=true) {
	// Initing SDL2
	if(SDL_Init(sdl_support_flags) < 0) {
		const char* error_msg = SDL_GetError();
		bool is_problem_fixed = false;
		// try to fix a problem. This fix is not in outer method because it's not in a class and it's not needed.
		if(is_fixable) {
			if(SDL_Init(DEFAULT_INIT_FLAGS) >= 0) {
				log::sdl_fix_warn("SDL_Init", "Initing SDL2 with default flags (SDL_INIT_VIDEO|SDL_INIT_AUDIO)", error_msg);
				is_problem_fixed = true;
			}
		}
		if(!is_problem_fixed) throw exception::Init(error_msg);
	}
	// Initing SDL2_image
	if(!(IMG_Init(img_init_flags) & img_init_flags)) {
		const char* error_msg = IMG_GetError();
		bool is_problem_fixed = false;
		// try to fix a problem by initing sdl2_image with default init flags.
		if(is_fixable) {
			if(IMG_Init(DEFAULT_IMG_INIT_FLAGS) & DEFAULT_IMG_INIT_FLAGS) {
				log::sdl_fix_warn("IMG_Init", "Initing SDL2_image with default flags (IMG_INIT_PNG|IMG_INIT_JPG)", error_msg);
				is_problem_fixed = true;
			}
		}
		if(!is_problem_fixed) throw exception::Init(error_msg);
	}
}

void quit() {
	IMG_Quit();
	SDL_Quit();
}

//special entities
class GameEntity : public Entity {
public:
	Flow* engine;

	GameEntity(Flow* engine) : Entity() {
		this->engine = engine;
	}

	GameEntity(Flow* engine, Rect collider, const std::string& name, const std::string& group) : Entity(collider, name, group) {
		this->engine = engine;
	}

	virtual void update(double delta) = 0;
	virtual void event(SDL_Event event) = 0;
};
}