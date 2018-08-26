#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> days(n);
	int sumDays = 0;
	
	for (auto& d : days) {
		cin >> d;
		sumDays += d;
	}

	int roundDays = sumDays / n;
	int countDaysRound = 0;
	for (auto d : days) {
		if (d > roundDays) {
			countDaysRound++;
		}
	}

	cout << countDaysRound << endl;
	for (int i = 0; i < n; i++) {
		if (days[i] > roundDays) {
			cout << i << " ";
		}
	}

	//system("pause");
	return 0;
}