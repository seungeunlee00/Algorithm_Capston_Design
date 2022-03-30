//based on the Bubble Sort
//Time Complexity = O(n^2), in-place Yes, Stable Yes
//parallel time --> O(n)

#include<iostream>
using namespace std;

void oddEvenSort(int arr[]) {
	bool Sorted = false;

	while (!Sorted) {
		Sorted = true;

		for(int i = 0; i < 10; i = i+2) {
			if(arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				
				Sorted = false;
			}
		}
		
		for(int i = 1; i < 10; i = i+2) {
			if(arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			
				Sorted = false;
			}
		}
	}
}

int main(){
    int array[10]={4, 5, 2, 9, 7, 1, 8, 3, 10, 6};

    oddEvenSort(array);

    for(int i = 0; i < 10; i++) {
        cout << array[i] <<" ";
    }
    return 0;
}
