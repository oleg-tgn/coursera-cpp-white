#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> mas(N);

	for (auto& m : mas) {
		cin >> m;
	}

	sort(begin(mas), end(mas), [](string s1, string s2) {
		transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
		transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
		return s1 < s2;
	});
	
	for (const auto& m : mas) {
		cout << m << " ";
	}
	//system("pause");
	return 0;
}
