//Time Complexity = O(n^2), in-place Yes, Stable Yes

#include<iostream>
using namespace std;

int main(){
    int array[10]={4, 5, 2, 9, 7, 1, 8, 3, 10, 6};
    int temp, i, j;

    for(i = 1; i < 10 ; i++) { // array[0]은 이미 정렬된 상태로 봄
        temp = array[i]; // 삽입될 숫자인 i번째 정수를 temp로 복사

        // 현재 정렬된 배열은 i-1까지이므로 i-1번째부터 역순으로 비교
        // j값은 음수가 아니어야 하고 
        // temp값보다 정렬된 배열에 있는 값이 크면 j번째를 j+1번째로 이동
        for(j = i-1; j >= 0 && array[j] > temp; j--){
            array[j+1] = array[j]; // 배열의 오른쪽으로 이동
        }
        array[j+1] = temp;
    }

    for(int i = 0; i < 10; i++) {
        cout << array[i] <<" ";
    }
    return 0;
}
