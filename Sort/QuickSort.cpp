// conquer(정복) & divide(분할) --> 순환 호출이 이루어지기 전에 대부분의 작업이 수행
// Time Complexity = O(nlogn), in-place Yes, Stable Yes or No

#include<iostream>
using namespace std;

int arr[10] = {4, 5, 2, 9, 7, 1, 8, 3, 10, 6};

void quickSort(int start, int end) {
    if(start >= end) return; // 원소가 1개인 경우

    int pivot = start;
    int i = pivot + 1; // 왼쪽 출발 지점
    int j = end;       // 오늘쪽 출발 지점

    while(i <= j) { // 교차하기 전까지 반복

        // i이 가리키는 곳이 pivot보다 크면 멈춤
        while(i <= end && arr[i] <= arr[pivot]) {
            i++; 
        }
        // j가 가리키는 곳이 pivot보다 작으면 멈춤
        while(j > start && arr[j] >= arr[pivot]) {
            j--;
        }

        if(i > j) { // 교차하면 arr[j]랑 arr[pivot] 교환
            int temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        } else { // arr[i]와 arr[j] 교환
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    //재귀 호출
    quickSort(start, j - 1);
    quickSort(j + 1, end); // j랑 pivot이랑 교환했으니까 다음부터는 j빼고 정렬
}

int main(){
    quickSort(0, 9);

	for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
