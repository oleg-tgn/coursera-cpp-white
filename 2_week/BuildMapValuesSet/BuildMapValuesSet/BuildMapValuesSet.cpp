#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

set<string> BuildMapValuesSet(map<int, string> originalMap) {
	set<string> build;
	for (auto m : originalMap) {
		build.insert(m.second);
	}

	return build;
}

int main() {
	set<string> values = BuildMapValuesSet({
		{ 1, "odd" },
		{ 2, "even" },
		{ 3, "odd" },
		{ 4, "even" },
		{ 5, "odd" }
	});

	for (const string& value : values) {
		cout << value << endl;
	}

	system("pause");
	return 0;
}