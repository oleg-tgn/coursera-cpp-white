set<string> BuildMapValuesSet(map<int, string> originalMap) {
	set<string> build;
	for (auto m : originalMap) {
		build.insert(m.second);
	}

	return build;
}
