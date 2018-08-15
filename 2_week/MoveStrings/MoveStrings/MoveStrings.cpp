#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
	for (string s : source) {
		destination.push_back(s);
	}
	source.clear();
}

int main() {
	vector<string> source = { "a", "b", "c" };
	vector<string> destination = { "z" };
	MoveStrings(source, destination);
	
	for (string d : destination) {
		cout << d << ", ";
	}
	system("pause");
	return 0;
}