#include <map>

struct PersonName {
	string first_name;
	string last_name;
};

class Person {
public:
	void ChangeFirstName(int year, const string& f_name) {
		// добавить факт изменения имени на first_name в год year
		persons[year].first_name = f_name;
	}
	void ChangeLastName(int year, const string& l_name) {
		persons[year].last_name = l_name;
	}
	
	string GetFullName(int year) {
		// получить имя и фамилию по состоянию на конец года year
		string prev_first_name = "";
		string prev_last_name = "";
		bool printed = false;
		string result;

		for (auto p : persons) {
			string first_name = p.second.first_name != "" ? p.second.first_name : prev_first_name;
			string last_name = p.second.last_name != "" ? p.second.last_name : prev_last_name;

			if (p.first == year) {
				result = PrintName(first_name, last_name);
				printed = true;
			}
			else if (p.first > year) {
				result = PrintName(prev_first_name, prev_last_name);
				printed = true;
			}
			prev_first_name = first_name;
			prev_last_name = last_name;
			
			if (printed) break;
		}

		if (!printed) {
			result = PrintName(prev_first_name, prev_last_name);
		}
		return result;
	}
private:
	map<int, PersonName> persons;

	string PrintName(string first_name, string last_name) {
		string result;
		if (first_name != "" && last_name != "") {
			result = first_name + " " + last_name;
		}
		else if (first_name != "" && last_name == "") {
			result = first_name + " with unknown last name";
		}
		else if (first_name == "" && last_name != "") {
			result = last_name + " with unknown first name";
		}
		else {
			result = "Incognito";
		}
		return result;
	}
};
