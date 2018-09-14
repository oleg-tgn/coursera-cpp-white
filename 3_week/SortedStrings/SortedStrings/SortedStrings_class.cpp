class SortedStrings {
public:
	void AddString(const string& s) {
		sortedStrings.push_back(s);
		sort(begin(sortedStrings), end(sortedStrings));
	}
	vector<string> GetSortedStrings() {
		return sortedStrings;
	}
private:
	vector<string> sortedStrings;
};