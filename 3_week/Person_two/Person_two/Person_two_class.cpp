#include <string>
#include <vector>
#include <map>

struct PersonName {
	string first_name;
	string last_name;
};

class Person {
public:
	Person(const string& f_name, const string& l_name, int year) {
		persons[year].first_name = f_name;
		persons[year].last_name = l_name;
		bornYear = year;
	}

	void ChangeFirstName(int year, const string& f_name) {
		persons[year].first_name = f_name;
	}

	void ChangeLastName(int year, const string& l_name) {
		persons[year].last_name = l_name;
	}

	string GetFullName(int year) const{
		if (year < bornYear) {
			return "No person";
		}
		vector<string> stack_names;
		vector<string> stack_last_names;

		string prev_first_name = "";
		string prev_last_name = "";
		bool printed = false;
		string result;

		for (auto p : persons) {
			string first_name = p.second.first_name != "" ? p.second.first_name : prev_first_name;
			string last_name = p.second.last_name != "" ? p.second.last_name : prev_last_name;

			if (p.first == year) {
				result = PrintHistoryName(first_name, last_name, stack_names, stack_last_names);
				printed = true;
			}
			else if (p.first > year) {
				result = PrintHistoryName(prev_first_name, prev_last_name, stack_names, stack_last_names);
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

	string GetFullNameWithHistory(int year) const {
		if (year < bornYear) {
			return "No person";
		}
		vector<string> stack_names;
		vector<string> stack_last_names;
		// получить все имена и фамилии по состоянию на конец года year
		string first_name = "";
		string last_name = "";

		string result;

		for (auto p : persons) {
			if (p.first <= year) {
				first_name = p.second.first_name != "" ? p.second.first_name : first_name;
				last_name = p.second.last_name != "" ? p.second.last_name : last_name;

				if (first_name != "" && (stack_names.size() == 0 || first_name != stack_names[stack_names.size() - 1])) {
					stack_names.push_back(first_name);
				}
				if (last_name != "" && (stack_last_names.size() == 0 || last_name != stack_last_names[stack_last_names.size() - 1])) {
					stack_last_names.push_back(last_name);
				}
			}
			if (p.first >= year) {
				break;
			}
		}

		result = PrintHistoryName(first_name, last_name, stack_names, stack_last_names);
		return result;
	}
private:
	map<int, PersonName> persons;

	int bornYear;

	string PrintName(string first_name, string last_name) const{
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

	string PrintHistoryName(string first_name, string last_name, vector<string> stack_names, vector<string> stack_last_names) const {
		string result;
		if (first_name != "" && last_name != "") {
			result = first_name + PrintHistory(stack_names) + " " + last_name + PrintHistory(stack_last_names);
		}
		else if (first_name != "" && last_name == "") {
			result = first_name + PrintHistory(stack_names) + " with unknown last name";
		}
		else if (first_name == "" && last_name != "") {
			result = last_name + PrintHistory(stack_last_names) + " with unknown first name";
		}
		else {
			result = "Incognito";
		}
		return result;
	}

	string PrintHistory(vector<string> stack_names) const {
		string result;

		if (stack_names.size() > 1) {
			result += " (";
			for (int i = stack_names.size() - 2; i > 0; --i) {
				result += stack_names[i] + ", ";
			}
			result += stack_names[0];
			result += ")";
		}

		return result;
	}
};
