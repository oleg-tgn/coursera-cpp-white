#include <iostream>

using namespace std;

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

int main() {
	Incognizable a;
	Incognizable b = {};
	Incognizable c = { 0 };
	Incognizable d = { 0, 1 };
	return 0;
}