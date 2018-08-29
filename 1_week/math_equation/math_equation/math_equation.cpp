#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double D = b * b - 4 * a * c;
	if (a == 0) {
		if (b != 0) {
			cout << (-c) / b;
		}
	}
	else if (D > 0) {
		cout << (-b - sqrt(D)) / (2 * a) << " ";
		cout << (-b + sqrt(D)) / (2 * a);
	}
	else if (D == 0) {
		cout << (-b) / (2 * a);
	}
	cin >> D;
	return 0;
}