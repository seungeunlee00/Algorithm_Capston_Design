//Time Complexity = O(n^2), in-place Yes, Stable No

#include<iostream>
using namespace std;

int main(){
    int array[10]={4, 5, 2, 9, 7, 1, 8, 3, 10, 6};

    // 마지막 숫자는 자동으로 정렬되기 때문에 n-1개 만큼 반복
    for(int i = 0; i < 9; i++) {
        int smallest = i; // array[i]값을 최솟값이라고 가정

        // 최솟값 탐색
        for(int j = i+1; j < 10; j++) {
            if(array[j] < array[smallest]) {
                smallest = j;
            }
        }
        int temp = array[i];
        array[i] = array[smallest];
        array[smallest] = temp;
    }

    for(int i = 0; i < 10; i++) {
        cout << array[i] <<" ";
    }
    return 0;
}
