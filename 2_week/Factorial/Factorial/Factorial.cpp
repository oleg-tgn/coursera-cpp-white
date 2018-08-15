int Factorial(int x) {
	if (x <= 0) {
		return 1;
	}
	int res = 1;
	for (int i = 1; i <= x; i++) {
		res *= i;
	}
	return res;
}