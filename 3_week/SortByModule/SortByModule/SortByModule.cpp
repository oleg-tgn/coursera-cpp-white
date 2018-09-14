#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> mas(N);

	for (auto& m : mas) {
		cin >> m;
	}

	sort(begin(mas), end(mas), [](int i, int j) {
		if (i < 0) i = -i;
		if (j < 0) j = -j;

		return i < j;
	});

	for (const auto& m : mas) {
		cout << m << " ";
	}

	//system("pause");
	return 0;
}