namespace flow {
	class Size2 {
	public:
		int w; // width
		int h; // height
		Size2(int w=0, int h=0) {
			this->w=w;
			this->h=h;
		}
	};

	class Size : public Size2 {
	public:
		int l; // length

		Size(int w=0, int h=0, int l=0) : Size2(w, h) {
			this->l=l;
		}
	};
}