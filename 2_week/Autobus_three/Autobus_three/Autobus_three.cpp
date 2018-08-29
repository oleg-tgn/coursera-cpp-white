#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
	int N;
	int number = 0;

	cin >> N;
	map<set<string>, int> routes;

	for (int i = 0; i < N; i++) {
		int Q;
		cin >> Q;

		set<string> stops;
		for (int j = 0; j < Q; j++) {
			string stop;
			cin >> stop;
			stops.insert(stop);
		}

		if (routes.count(stops) != 0) {
			cout << "Already exists for " << routes[stops] << endl;
		}
		else {
			routes[stops] = ++number;
			cout << "New bus " << number << endl; 
		}
	}
	system("pause");
	return 0;
}