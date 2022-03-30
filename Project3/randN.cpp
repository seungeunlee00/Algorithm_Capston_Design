#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

const int N = 100'000;

void oddEvenSort(int arr[]) {
	bool Sorted = false;

	while (!Sorted) {
		Sorted = true;

		for(int i = 0; i < N; i = i+2) {
			if(arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				
				Sorted = false;
			}
		}

		for(int i = 1; i < N; i = i+2) {
			if(arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			
				Sorted = false;
			}
		}
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
		a[i] = rand() % 1001;
	}

	time_t start, end;
	start = time(NULL);

	oddEvenSort(a);

	end = time(NULL);
	
	checkSort(a);

	cout<<"N="<<N<<" 일 때 소요 시간: "<<(float)(end - start) << "초\n";
	return 0;
}
