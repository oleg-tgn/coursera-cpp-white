#include <iostream>

using namespace std;

int main() {
	double N; // ��������� ������
	double A; // ������ ���� ����� ������ X ���������
	double B; // ������ ���� ����� ������ Y ���������
	double X; // ������ ��� ������� A
	double Y; // ������ ��� ������� B
	double Result;
	cin >> N >> A >> B >> X >> Y;
	if (N > B) {
		// �������� ������ Y
		Result = N - N * (Y / 100);
	} 
	else if (N > A) {
		// �������� ������ X
		Result = N - N * (X / 100);
	} 
	else {
		// �� �������� ������
		Result = N;
	}

	cout << Result;
	//system("pause");
	return 0;
}