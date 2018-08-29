#include <iostream>
#include <string>

using namespace std;

int main() {
	int countCharF = 0;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'f') {
			countCharF++;
		}
		if (countCharF == 2) {
			// встретили второй раз, выводим индекс
			cout << i;
			break;
		}
	}
	if (countCharF == 1) {
		//встретилась 1 раз
		cout << -1;
	}
	else if (countCharF == 0) {
		//не встретилась
		cout << -2;
	}
	
	//system("pause");
	return 0;
}