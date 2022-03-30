#include<iostream>
#include<ctime>
using namespace std;

int main() {
	const int N = 200;
	int a[N][N], b[N][N], c[N][N], ab[N][N], abc[N][N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = 1;
			b[i][j] = 2;
			c[i][j] = 3;
			ab[i][j] = 0;
			abc[i][j] = 0;
		}
	}

	clock_t start, end;
	start = clock();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				ab[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				abc[i][j] += ab[i][k] * c[k][j];
			}
		}
	}

	end = clock();
	cout << "n=" << N << "일 때 n^3 소요시간 = ";
	cout << (float)(end - start) << "ms" << endl;
	return 0;
}
