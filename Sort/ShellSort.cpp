// 삽입 정렬을 간단하게 변형
// Time Complexity = O(n^1.5)

#include<iostream>
using namespace std;

void shellSort(int array[]) {
    int h, k;
    // 첫번째 h값 계산
    for(h = 1; h < 10; h = 3*h + 1) {  } // 증가식
    while (h > 0) {
		    for (int i = h; i < 10; i++) {

          // Insertion Sort
			    int temp = array[i];
          for(k = i - h; k >= 0 && array[k] > temp; k = k - h){
              array[k + h] = array[k];
          }
			    array[k + h] = temp;

		    }
		    h = int(h / 3);  // 감소식
	  }
}

int main() {
	int array[10]={4, 5, 2, 9, 7, 1, 8, 3, 10, 6};

	shellSort(array);

    for(int i = 0; i < 10; i++) {
        cout << array[i] <<" ";
    }

	return 0;
}
