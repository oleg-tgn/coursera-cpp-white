class Incognizable {
public: 
	Incognizable() {};
	Incognizable(const int& a) {
		x = a;
	}
	Incognizable(const int& a, const int& b) {
		x = a;
		y = b;
	}
private:
	int x;
	int y;
};
