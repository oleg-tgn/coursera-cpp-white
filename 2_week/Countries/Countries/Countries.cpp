#include <iostream>
#include <string>
#include <map>

using namespace std;

void ChangeCapital(string& c, const string& country, const string& new_capital) {
	if (c == "") {
		cout << "Introduce new country " << country << " with capital " << new_capital << endl;
	}
	else if (c == new_capital) {
		cout << "Country " << country << " hasn't changed its capital" << endl;
	}
	else {
		cout << "Country " << country << " has changed its capital from " << c << " to " << new_capital << endl;
	}
	c = new_capital;
}

void Rename(map<string, string>& countries, string old_country_name, string new_country_name) {
	if (old_country_name == new_country_name 
		|| countries.find(old_country_name) == countries.end()
		|| countries.find(new_country_name) != countries.end()) {
		cout << "Incorrect rename, skip" << endl;
	}
	else {
		cout << "Country " << old_country_name << " with capital " << countries[old_country_name] << " has been renamed to " << new_country_name << endl;
		countries[new_country_name] = countries[old_country_name];
		countries.erase(old_country_name);
	}
}

void About(map<string, string>& countries, const string& country) {
	if (countries.find(country) == countries.end()) {
		cout << "Country " << country << " doesn't exist" << endl;
	}
	else {
		cout << "Country " << country << " has capital " << countries[country] << endl;
	}
}


void Dump(map<string, string>& countries) {
	if (countries.size() == 0) {
		cout << "There are no countries in the world" << endl;
	}
	else {
		for (auto c : countries) {
			cout << c.first << "/" << c.second << endl;
		}
	}
}

int main() {
	int Q;
	cin >> Q;
	map<string, string> countries;
	for (int i = 0; i < Q; i++) {
		string key;
		cin >> key;
		if (key == "CHANGE_CAPITAL") {
			string country, new_capital;
			cin >> country >> new_capital;
			ChangeCapital(countries[country], country, new_capital);
		}
		else if (key == "RENAME") {
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			Rename(countries, old_country_name, new_country_name);
		}
		else if (key == "ABOUT") {
			string country;
			cin >> country;
			About(countries, country);
		}
		else if (key == "DUMP") {
			Dump(countries);
		}
	}
	//system("pause");
	return 0;
}