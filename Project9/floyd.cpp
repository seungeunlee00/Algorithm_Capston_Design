#include <iostream>
using namespace std;

#define INF 100000000
int weight[6][6] = {
	{0, 0, 0, 0, 0, 0},
	{0, 0, 1, INF, 1, 5}, 
	{0, 9, 0, 3, 2, INF},
	{0, INF, INF, 0, 4, INF},
	{0, INF, INF, 2, 0, 3},
	{0, 3, INF, INF, INF, 0}
};
int P[6][6]{}; 
int D[6][6]{}; // 최단 경로의 길이
 
void floyd(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			D[i][j] = weight[i][j]; // 가중치 행렬 복사
		}
	}

	for (int k = 1; k <= n ; k++) { // 거쳐가는 노드
		for (int i = 1; i <= n; i++) { // 출발지 노드 
			for (int j = 1; j <= n; j++) { // 도착지 노드 
				// k를 거치는 것과 거치지 않는 것을 비교해서
				// k를 거쳐가는 거리가 더 가중치가 낮다면 
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k; // P 행렬에 거쳐간 위치를 저장하고
					D[i][j] = D[i][k] + D[k][j]; // D 행렬에 거쳐가는 길 저장
				}
			}
		}
	}
}

void path(int q, int r) {
	// P[q][r]이 0이 아닐 때 (어딘가를 거쳐갈 때)
	if (P[q][r] != 0) {
		// q에서 r까지의 최소거리 탐색 및 출력
		path(q, P[q][r]);
		cout << "v" << P[q][r] << " -> ";
		path(P[q][r], r);
	}
}

void shortPath(int q, int r) {
	cout << "\nThe shortest path(" << q << ", " << r << ") is v" << q << " -> ";
	path(q, r);
	cout << "v" << r;
}

void printTable(int table[6][6]) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}


int main() {
	floyd(5);

	cout << "D[i][j] is" << endl;
	printTable(D);

	cout << endl << "P[i][j] is" << endl;
	printTable(P);

	shortPath(5, 3);
	shortPath(1, 3);
	shortPath(2, 5);
}
