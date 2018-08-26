#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
	int Q;
	cin >> Q;
	vector<bool> WorryQuiet;
	vector<int> result;

	for (int i = 0; i < Q; i++) {
		int size = WorryQuiet.size();
		string key;
		int n;
		cin >> key;
		if (key == "COME") {
			cin >> n;
			WorryQuiet.resize(size + n, false);
		}
		else if (key == "WORRY") {
			cin >> n;
			WorryQuiet[n] = true;
		}
		else if (key == "QUIET") {
			cin >> n;
			WorryQuiet[n] = false;
		}
		else if (key == "WORRY_COUNT") {
			int countWorry = 0;
			for (auto b : WorryQuiet) {
				if (b == true) {
					countWorry++;
				}
			}
			result.push_back(countWorry);
		}
	}

	for (auto r : result) {
		cout << r << endl;
	}
	
	system("pause");
	return 0;
}