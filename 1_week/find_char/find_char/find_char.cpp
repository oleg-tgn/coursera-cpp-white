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
			// ��������� ������ ���, ������� ������
			cout << i;
			break;
		}
	}
	if (countCharF == 1) {
		//����������� 1 ���
		cout << -1;
	}
	else if (countCharF == 0) {
		//�� �����������
		cout << -2;
	}
	
	//system("pause");
	return 0;
}