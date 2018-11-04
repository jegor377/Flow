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