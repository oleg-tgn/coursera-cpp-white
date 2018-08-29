#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Autobus {
	string bus;
	vector<string> stops;
};

/*
	NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count 
	остановками с названиями stop1, stop2, ...
*/
void NewBus(vector<Autobus>& buses, map<string, vector<string>>& busesSort) {
	string bus;
	int stop_count;
	cin >> bus >> stop_count;
	
	for (int i = 0; i < stop_count; i++) {
		string stop;
		cin >> stop;

		busesSort[bus].push_back(stop);
		Autobus newBus;
		newBus.bus = bus;
		newBus.stops.push_back(stop);
		buses.push_back(newBus);
	}
}

/*
	BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
*/
bool FindBusStop(vector<string>& stops, string stop) {
	for (auto s : stops) {
		if (s == stop) {
			return true;
		}
	}
	return false;
}

void BusesForStop(vector<Autobus>& buses, string stop) {
	int count = 0;
	for (auto current : buses) {
		if (FindBusStop(current.stops, stop)) {
			count++;
			cout << current.bus << " ";
		}
	}
	if (count == 0) {
		cout << "No stop";
	}
	cout << endl;
}

/*
	STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок.
*/
void StopsForBus(vector<Autobus>& buses, map<string, vector<string>>& busesMap, const string bus) {
	if (busesMap.count(bus) == 0) {
		cout << "No bus" << endl;
		return;
	}
	for (auto stop : busesMap[bus]) {
		cout << "Stop " << stop << ": ";

		int count = 0;
		for (auto b : buses) {
			if (b.bus == bus) continue;
			
			if (FindBusStop(b.stops, stop)) {
				count++;
				cout << b.bus << " ";
			}
		}
		if (count == 0) {
			cout << "no interchange";
		}
		cout << endl;
	}
}

/*
	ALL_BUSES — вывести список всех маршрутов с остановками.
*/
void AllBuses(map<string, vector<string>>& buses) {
	if (buses.size() == 0) {
		cout << "No buses" << endl;
		return;
	}
	for (auto b : buses) {
		cout << "Bus " << b.first << ": ";
		for (auto s : b.second) {
			cout << s << " ";
		}
		cout << endl;
	}
}

int main() {
	int Q; 
	cin >> Q;
	vector<Autobus> buses;
	map<string, vector<string>> busesMap;

	for (int i = 0; i < Q; i++) {
		string key;
		cin >> key;

		if (key == "NEW_BUS") {
			NewBus(buses, busesMap);
		}
		else if (key == "BUSES_FOR_STOP") {
			string stop;
			cin >> stop;
			BusesForStop(buses, stop);
		}
		else if (key == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;
			StopsForBus(buses, busesMap, bus);
		}
		else if (key == "ALL_BUSES") {
			AllBuses(busesMap);
		}
	}

	//system("pause");
	return 0;
}