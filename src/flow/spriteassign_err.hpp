namespace exception {
	class SpriteAssign: public std::exception {
	public:
		const char* what() const throw() {
			return "Sprite reference not assigned in SharedSprite.";
		}
	};
}