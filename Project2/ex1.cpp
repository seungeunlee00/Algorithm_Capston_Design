#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

const int N = 10'000'000;

void shellSort(int a[]) {
	int h = 1;
	while (h < N) {
		h = 5 * h + 1;  // 증가식
	}

	while (h > 0) {
		for (int i = h; i < N; i++) {
			int k = i - h;
			int key = a[i];
			while (k >= 0 && key < a[k]) {
				a[k + h] = a[k];
				k = k - h;
			}
			a[k + h] = key;
		}
		h = int(h / 5);  // 감소식
	}

}

void checkSort(int a[]) {
	int sorted = true;
	for (int i = 0; i < N-1; i++) {
		if (a[i] > a[i + 1]) {
			sorted = false;
		}
		if (!sorted) {
			break;
		}
	}
	if (sorted) {
		cout << "정렬 완료.\n";
	}
	else {
		cout << "정렬 오류\n";
	}
}

int main() {
	int a[N]{}; 

	for (int i = 0; i < N; i++) {
		a[i] = rand();
	}

	time_t start, end;
	start = time(NULL);

	shellSort(a);

	end = time(NULL);
	cout << "증가식: 5h + 1, 감소식 h/5 쉘 정렬 실행 시간 (N = " << N << "): " << (float)(end - start) << "초\n";
	
	checkSort(a);
	return 0;
}

