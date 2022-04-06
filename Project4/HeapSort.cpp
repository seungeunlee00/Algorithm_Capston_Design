#include<iostream>
#include<ctime>
using namespace std;

const int n = 1'000'000;

void MaxHeapify(int array[], int n, int i) {
    int p = i; // 부모 node index
    int l = 2*i + 1; // 왼쪽 자식의 node index
    int r = 2*i + 2; // 오른쪽 자식의 node index

    if(l < n && array[p] < array[l]) {
        p = l; // 부모 node index에 왼쪽 자식 node index 대입
    }
    if(r < n && array[p] < array[r]) {
        p = r; // 부모 node index에 오른쪽 자식 node index 대입
    }
    if(i != p){ // 위 과정을 통해 i와 p 값이 달라졌다면
        int temp = array[i];     // 리스트의 i 인덱스 값과 
        array[i] = array[p];     // p 인덱스 값 교환
        array[p] = temp;
        MaxHeapify(array, n, p); // 다시 heapify
    }
}

void MaxHeap(int array[]) {
    for(int i = n/2-1; i >= 0; i--) {   // 배열을 max heap로 변환
        MaxHeapify(array, n, i);        // i는 내부 노드
    }
    // heap에서 가장 큰 원소를 추출해 오름차순으로 정렬
    for (int i = n-1; i > 0; i--) {
        int temp = array[0];        // a[0]은 가장 큰 원소
        array[0] = array[i];        // a[0]과 a[i]를 교환
        array[i] = temp;           
        MaxHeapify(array, i, 0);
    }
}

void MinHeapify(int array[], int n, int i) {
    int p = i; // 부모 node index
    int l = 2*i + 1; // 왼쪽 자식의 node index
    int r = 2*i + 2; // 오른쪽 자식의 node index

    if(l < n && array[p] > array[l]) {
        p = l; // 부모 node index에 왼쪽 자식 node index 대입
    }
    if(r < n && array[p] > array[r]) {
        p = r; // 부모 node index에 오른쪽 자식 node index 대입
    }
    if(i != p){ // 위 과정을 통해 i와 p 값이 달라졌다면
        int temp = array[i];     // 리스트의 i 인덱스 값과 
        array[i] = array[p];     // p 인덱스 값 교환
        array[p] = temp;
        MinHeapify(array, n, p); // 다시 heapify
    }
}

void MinHeap(int array[]) {
    for(int i = n/2-1; i >= 0; i--) {   // 배열을 min heap로 변환
        MinHeapify(array, n, i);        // i는 내부 노드
    }
    // heap에서 가장 작은 원소를 추출해 내림차순으로 정렬
    for (int i = n-1; i > 0; i--) {
        int temp = array[0];        // a[0]은 가장 작은 원소
        array[0] = array[i];        // a[0]과 a[i]를 교환
        array[i] = temp;           
        MinHeapify(array, i, 0);
    }
}

void MaxCheckSort(int a[]) { // 오름차순 정렬 체크
	int sorted = true;
	for (int i = 0; i < n-1; i++) {
		if (a[i] > a[i + 1]) {
			sorted = false;
		}
		if (!sorted) {
			break;
		}
	}
	if (sorted) {
		cout << "Maxheap sorting complete!\n";
	}
	else {
		cout << "Maxheap sorting error!\n";
	}
}

void MinCheckSort(int a[]) { // 내림차순 정렬 체크
	int sorted = true;
	for (int i = 0; i > n-1; i++) {
		if (a[i] < a[i + 1]) {
			sorted = false;
		}
		if (!sorted) {
			break;
		}
	}
	if (sorted) {
		cout << "Minheap sorting complete!\n";
	}
	else {
		cout << "Minheap sorting error!\n";
	}
}

int main() {
    
    /*
    int array[10] = {6, 2, 8, 1, 3, 9, 4, 5, 10, 7};

    MaxHeap(array);
    cout<<"MaxHeap 정렬 결과\n"; //오름차순
    for(int i = 0; i < 10; i++) {   
        cout << array[i] <<" ";
    }

    MinHeap(array);
    cout<<"\nMinHeap 정렬 결과\n"; // 내림차순
    for(int i = 0; i < 10; i++) {    
        cout << array[i] <<" ";
    }
    */
    
    int array[n]{}; 

	  for (int i = 0; i < n; i++) {
		  array[i] = rand();
	  }

    //MaxHeap
    clock_t start, end;
	  start = clock();
	  MaxHeap(array);
	  end = clock();
	  MaxCheckSort(array);
	  cout<<"Maxheap sorting (N="<<n<<") time cost: "<<(float)(end - start) << "ms\n";

    //MinHeap
  	start = clock();
  	MinHeap(array);
   	end = clock();
   	MinCheckSort(array);
  	cout<<"Minheap sorting (N="<<n<<") time cost: "<<(float)(end - start) << "ms\n";
    
    return 0;
}
