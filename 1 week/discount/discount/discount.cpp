#include <iostream>

using namespace std;

int main() {
	double N; // стоимость товара
	double A; // больше этой суммы скидка X процентов
	double B; // больше этой суммы скидка Y процентов
	double X; // скидка при условии A
	double Y; // скидка при условии B
	double Result;
	cin >> N >> A >> B >> X >> Y;
	if (N > B) {
		// получаем скидку Y
		Result = N - N * (Y / 100);
	} 
	else if (N > A) {
		// получаем скидку X
		Result = N - N * (X / 100);
	} 
	else {
		// не получаем скидки
		Result = N;
	}

	cout << Result;
	//system("pause");
	return 0;
}