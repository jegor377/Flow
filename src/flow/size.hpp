namespace flow {
	class Size2 {
	public:
		double w; // width
		double h; // height
		Size2(double w=0, double h=0) {
			this->w=w;
			this->h=h;
		}
	};

	class Size : public Size2 {
	public:
		double l; // length

		Size(double w=0, double h=0, double l=0) : Size2(w, h) {
			this->l=l;
		}
	};
}