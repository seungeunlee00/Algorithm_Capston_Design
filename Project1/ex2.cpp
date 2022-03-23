#include <iostream>
using namespace std;

int fibonacci(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main() {
	int n;
	cin >> n;

	clock_t start, end;
	start = clock();

	cout << "F" << n << "=" << fibonacci(n) << endl;

	end = clock();
	cout << "n=" << n << "일 때 2^n 소요시간 = ";
	cout << (float)(end - start) << "ms" << endl;
	return 0;
}