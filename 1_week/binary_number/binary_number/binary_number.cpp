#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<int> binary;
	cin >> n;

	/*
	* решение через остатки от деления
	*/
	int result = 0;
	while (n > 0) {
		binary.push_back(n % 2);
		n /= 2;
	}
	for (int i = binary.size() - 1; i >= 0; i--) {
		cout << binary[i];
	}

	//system("pause");
	return 0;
}