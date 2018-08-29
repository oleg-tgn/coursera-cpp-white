#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;


int main() {
	map<vector<string>, int> route_and_stops;
	int number = 0;
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int n;
		cin >> n;
		vector<string> stops;
		for (int j = 0; j < n; j++) {
			string stop;
			cin >> stop;
			stops.push_back(stop);
		}
		if (route_and_stops.count(stops) == 0) {
			number++;
			route_and_stops[stops] = number;
			cout << "New bus " << number << endl;
		}
		else {
			cout << "Already exists for " << route_and_stops[stops] << endl;
		}
	}

	//system("pause");
	return 0;
}