#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
	int size = v.size();
	vector<int> buf;
	for (int i = size - 1; i >= 0; i--) {
		buf.push_back(v[i]);
	}
	return buf;
}

int main() {
	vector<int> numbers = { 1, 5, 3, 4, 2 };
	numbers = Reversed(numbers);

	for (int x : numbers) {
		cout << x;
	}
	system("pause");
	return 0;
}