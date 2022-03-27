// divide(분할) & conquer(정복)
// Time Complexity = O(nlogn), in-place No, Stable Yes

#include<iostream>
using namespace std;

int arr[10] = {4, 5, 2, 9, 7, 1, 8, 3, 10, 6};
int sorted[10]; // 정렬된 임시배열  --> 추가 공간 필요(in-place 아님!)

void merge(int start, int end){
	int mid = (start + end) / 2;
	int i = start;    // 정렬된 왼쪽 배열에 대한 index
	int j = mid + 1;  // 정렬된 오른쪽 배열에 대한 index
	int k = start;    // sorted 배열의 index

    // 비교하여 데이터 정렬 및 합병
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			sorted[k] = arr[i]; 
			i++;
        	} else {
			sorted[k] = arr[j];
           		j++;
        	} 
        k++;
	}

    // 남아 있는 데이터 정리
	if(i > mid) {   // 전반부는 다 처리되고 후반부에 남은 데이터들을 sorted에 삽입
		for(int t = j; t <= end; t++){
			sorted[k] = arr[t];
			k++;
		}
	} else {        // 후반부는 다 처리되고 전반부에 남은 데이터들을 sorted에 삽입
		for(int t = i; t <= mid; t++){
			sorted[k] = arr[t];
			k++;
		}
	}

    // sorted 배열에 저장된 값을 원래 배열에 넣어줌
	for (int t = start; t <= end; t++) {
        arr[t] = sorted[t];
    }
}

void mergeSort(int start,int end) {
	if (start < end) {
		int mid = (start + end) / 2; 
		mergeSort(start, mid);       // 전반부 정렬 
		mergeSort(mid + 1, end);  // 후반부 정렬
		merge(start, end);         // 병합
	}
}

int main(){
	mergeSort(0, 9);

	for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
