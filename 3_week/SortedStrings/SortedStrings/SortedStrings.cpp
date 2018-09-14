#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
	void AddString(const string& s) {
		sortedStrings.push_back(s);
		sort(begin(sortedStrings), end(sortedStrings));
	}
	vector<string> GetSortedStrings() {
		return sortedStrings;
	}
private:
	vector<string> sortedStrings;
};


void PrintSortedStrings(SortedStrings& strings) {
	for (const string& s : strings.GetSortedStrings()) {
		cout << s << " ";
	}
	cout << endl;
}

int main() {
	SortedStrings strings;

	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	system("pause");
	return 0;
}
