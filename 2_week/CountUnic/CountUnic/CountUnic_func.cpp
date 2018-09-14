#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	int N;
	set<string> str;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string x;
		cin >> x;
		str.insert(x);
	}

	cout << str.size() << endl;

	//system("pause");
	return 0;
}