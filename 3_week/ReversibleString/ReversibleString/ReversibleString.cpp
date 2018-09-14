#include <iostream>
#include <string>

using namespace std;

class ReversibleString {
public: 
	ReversibleString() {}
	ReversibleString(const string& s) {
		str = s;
	}

	void Reverse() {
		string result;
		for (int i = str.size() - 1; i >= 0; --i) {
			result += str[i];
		}
		str = result;
	}

	string ToString() const {
		return str;
	}
private:
	string str;
};

int main() {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	system("pause");
	return 0;
}