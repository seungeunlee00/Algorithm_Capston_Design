//Time Complexity = O(n^2), in-place Yes, Stable Yes

#include<iostream>
using namespace std;

int main(){
    int array[10]={4, 5, 2, 9, 7, 1, 8, 3, 10, 6};

    for(int i = 0; i < 10 ; i++) {
        for(int j = 0; j < 10-1-i; j++) {
            if(array[j] > array[j+1]) { // 인접한 두 원소 검사 
                int temp = array[j];    // j와 j+1 exchange
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < 10; i++) {
        cout << array[i] <<" ";
    }
    return 0;
}
