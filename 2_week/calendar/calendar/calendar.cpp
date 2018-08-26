#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<vector<string>> plans(31);
	vector<int> months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int current_month = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string key;
		int k;
		string plan;
		cin >> key ;

		if (key == "ADD") {
			cin >> k >> plan;
			plans[k - 1].push_back(plan);
		}
		else if (key == "NEXT") {
			current_month = (current_month + 1) % 12;

			int m = months[current_month];
			int pm = months[current_month - 1];
			if (m > pm) {
				plans.resize(m);
			}
			else if (m < pm) {
				auto v1 = plans[m - 1];
				for (int j = m; j < pm; j++) {
					auto v2 = plans[j];
					v1.insert(end(v1), begin(v2), end(v2));
				}
				plans[m - 1] = v1;
				plans.resize(m);
			}
		}
		else if (key == "DUMP") {
			cin >> k;
			cout << plans[k - 1].size() << " ";
			for (auto p : plans[k - 1]) {
				cout << p << " ";
			}
			cout << endl;
		}
	}
	//system("pause");
	return 0;
}