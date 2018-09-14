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
