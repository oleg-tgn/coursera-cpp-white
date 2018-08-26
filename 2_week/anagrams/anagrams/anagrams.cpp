#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<char, int> BuildCharCounters(string str) {
	map<char, int> res;
	for (auto c : str) {
		res[c]++;
	}
	return res;
}

int main() {	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		map<char, int> counters1, counters2;
		counters1 = BuildCharCounters(s1);
		counters2 = BuildCharCounters(s2);

		if (counters1 == counters2) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	//system("pause");
	return 0;
}