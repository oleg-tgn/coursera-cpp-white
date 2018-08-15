bool IsPalindrom(string str) {
	for (int i = 0; i <= str.size() / 2; i++) {
		if (str[i] != str[str.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

vector<string> PalindromFilter(vector<string> mas, int minLength) {
	vector<string> res;
	for (string a : mas) {
		if (a.size() >= minLength && IsPalindrom(a)) {
			res.push_back(a);
		}
	}
	return res;
}
