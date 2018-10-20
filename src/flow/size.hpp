namespace flow {
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
	};

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
	};
}