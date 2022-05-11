#include <iostream>
#include <iomanip>
using namespace std;

void MaxCheese(int array[9][9]);

int main() {
	int p[9][9] = {
	{-1, -1, 1, -1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, 1, -1, 2, -1},
	{1, -1, 2, -1, -1, -1, -1, 1, -1},
	{-1, -1, -1, -1, 1, 2, -1, -1, -1},
	{-1, 1, -1, 1, -1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, 2, 1, 2, -1},
	{-1, 1, -1, -1, 1, -1, -1, -1, -1},
	{-1, -1, -1, -1, -1, 1, -1, -1, -1},
	{-1, -1, -1, -1, -1, -1, -1, -1, -1} 
	};

	MaxCheese(p);
	return 0;
}

void MaxCheese(int p[9][9]) {
	int map[9][9] = { 0 };

	if (p[8][0] == 1) // 시작 지점
		map[8][0] = 1;

	for (int i = 7; i >= 0; i--) { 
		if (p[i][0] == -1) // 아무것도 없을때 그대로 진행
			map[i][0] = map[i + 1][0];

		else if (p[i][0] == 1) // 치즈가 있을때 그대로 진행
			map[i][0] = map[i + 1][0] + 1;

		else // 쥐덫이 있을때 그 위치에 -1 대입
			map[i][0] = -1;
	}

	for (int j = 1; j <= 8; j++) {
		if (p[8][j] == -1)
			map[8][j] = map[8][j - 1];

		else if (p[8][j] == 1)
			map[8][j] = map[8][j - 1] + 1;

		else 
			map[8][j] = -1;
	}

	// [7][0] ~ [0][8]
	for (int i = 7; i >= 0; i--) {
		for (int j = 1; j <= 8; j++) {
			if (p[i][j] == -1)
				map[i][j] = max(map[i][j - 1], map[i + 1][j]);
			
			else if (p[i][j] == 1)
				map[i][j] = max(map[i][j - 1], map[i + 1][j]) + 1;

			else // 쥐덫을 만나면 -1을 대입
				map[i][j] = -1;
		}
	}

	cout << "치즈의 경로\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << setw(4) << map[i][j];
		}
		cout << endl;
	}
	cout << "먹을 수 있는 치즈의 최대값 : " << map[0][8] << endl;
}
