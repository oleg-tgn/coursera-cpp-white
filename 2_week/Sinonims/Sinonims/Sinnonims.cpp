#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

void Add(map<string, set<string>>& sinonims, const string& word1, const string& word2);
void Count(map<string, set<string>>& sinonims, const string& word);
void Check(map<string, set<string>>& sinonims, const string& word1, const string& word2);

int main() {
	int N; 
	cin >> N;
	map<string, set<string>> sinonims;

	for (int i = 0; i < N; i++) {
		string key;
		cin >> key;

		if (key == "ADD") {
			string word1, word2;
			cin >> word1 >> word2;
			Add(sinonims, word1, word2);
		}
		else if (key == "COUNT") {
			string word;
			cin >> word;
			Count(sinonims, word);
		}
		else if (key == "CHECK") {
			string word1, word2;
			cin >> word1 >> word2;
			Check(sinonims, word1, word2);
		}

	}
	//system("pause");
	return 0;
}

void Add(map<string, set<string>>& sinonims, const string& word1, const string& word2) {
	sinonims[word1].insert(word2);
	sinonims[word2].insert(word1);
	return;
}

void Count(map<string, set<string>>& sinonims, const string& word) {
	if (sinonims.count(word) == 0) {
		cout << 0 << endl;
	}
	else {
		cout << sinonims[word].size() << endl;
	}
}

void Check(map<string, set<string>>& sinonims, const string& word1, const string& word2) {
	if (sinonims.count(word1) != 0) {
		if (sinonims[word1].count(word2) != 0) {
			cout << "YES" << endl;
			return;
		}
	}
	
	if (sinonims.count(word2) != 0) {
		if (sinonims[word2].count(word1) != 0) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
	return;
}