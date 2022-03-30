#include<iostream>
using namespace std;

const int N = 8;

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

		cout<<"odd index\n";
		for (int i = 0; i < N; i++) {
			cout<< arr[i] <<" ";
		}
		cout<<"\n";
		
		for(int i = 1; i < N; i = i+2) {
			if(arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			
				Sorted = false;
			}
		}
		
		cout<<"even index\n";
		for (int i = 0; i < N; i++) {
			cout<< arr[i] <<" ";
		}
		cout<<"\n";
	}
}


int main() {
	int arr[N] = {2, 1, 5, 3, 7, 9, 4, 10};

	oddEvenSort(arr);
	
	cout<<"\n최종 정렬 결과\n";
	for(int i = 0; i < N; i++) {
		cout<<arr[i]<<" ";
	}
	return 0;
}
