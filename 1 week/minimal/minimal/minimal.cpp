//#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> strings;
	string str;
	int n = 3;
	for (int i = 0; i < n; i++) {
		cin >> str;
		strings.push_back(str);
	}
	/*
	* Use Algorithm
	*/
	//cout << *min_element(strings.begin(), strings.end());
	/*
	* Use IF
	*/
	string min_str = strings[0];
	for (int i = 1; i < n; i++) {
		if (strings[i] < min_str) {
			min_str = strings[i];
		}
	}
	cout << min_str;
	//cin >> n;
	return 0;
}