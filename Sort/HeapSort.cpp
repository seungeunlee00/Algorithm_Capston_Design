// heap -> 우선순위 큐를 위해 고안된 완전 이진 트리 형태의 자료구조
// Time Complexity = O(nlogn), in-place Yes, stable No

#include<iostream>
using namespace std;

void heapify(int array[], int h, int m) {
    // root인 h를 제외한 h의 왼쪽 서브트리와 오른쪽 서브트리는 히프
    // 현재 시점으로 노드의 최대 레벨 순서 번호는 m
    int v = array[h];
    int j;
    for(j = 2*h; j <= m; j = 2*j) {
        if(j < m && array[j] < array[j+1])
            j++;  // j는 값이 큰 왼쪽 또는 오른쪽 자식 노드
        if(v >= array[j]) 
            break;
        else
            array[j/2] = array[j];  //a[j]를 부모 노드로 이동
    }
    array[j/2] = v;
}

void heapSort(int array[]) {
    int n = 10-1; // n은 히프 크기(원소의 수)
                  // a[0]은 사용하지 않고 a[1:n]의 원소를 오름차순으로 정렬
    for(int i = n/2; i >= 1; i--) {  // 배열 a[]을 히프로 변환
        heapify(array, i, n);        // i는 내부 노드
    }
    for (int i = n-1; i >= 1; i--) { // 배열 a[]를 오름차순으로 정렬
        int temp = array[1];         // a[1]은 가장 큰 원소
        array[1] = array[i+1];       // a[1]과 a[i+1]을 교환
        array[i+1] = temp;
        heapify(array, 1, i);
    }
}

int main() {
    int array[10] = {1, 5, 2, 9, 7, 4, 8, 3, 10, 6};

    heapSort(array);

    for(int i = 1; i < 10; i++) {    // a[0]은 사용하지 않으니까 a[1]부터 출력
        cout << array[i] <<" ";
    }

    return 0;
}
