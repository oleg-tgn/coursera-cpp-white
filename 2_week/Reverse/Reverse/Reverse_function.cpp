void Reverse(vector<int>& v) {
	int size = v.size();
	vector<int> buf;
	for (int i = size - 1; i >= 0; i--) {
		buf.push_back(v[i]);
	}
	v.clear();
	v = buf;
}