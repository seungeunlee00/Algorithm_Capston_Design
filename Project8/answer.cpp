#include<iostream>

using namespace std;

int main()
{
    int cheeseWithTrap[9][9] = {
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 2, 0},
        {1, 0, 2, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 2, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 1, 2, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int c[9][9] = {{0,},}; // DP 값 저장할 배열 선언 및 0으로 초기화
    int i, j;

    for (int i = 8; i >= 0; i--) {
		for (int j = 0; j < 9; j++) {	
            // 쥐덫을 밟은 경우 dp 배열 값 0으로
			if (cheeseWithTrap[i][j] == 2) {
				c[i][j] = 0; 
                continue;
			}

            // column 값이 증가(진행 방향: →)
			if (j == 0 && i < 8) {
				c[i][j] = c[i + 1][j] + cheeseWithTrap[i][j];
			} // raw 값이 감소(진행 방향: ↑)
			else if (i == 8 && j > 0) {
				c[i][j] = c[i][j - 1] + cheeseWithTrap[i][j];
			} // raw 및 col 값 중 최대값을 선택한 후 현재 치즈 값 더함
			else {
				c[i][j] = max(c[i][j - 1], c[i + 1][j]) + cheeseWithTrap[i][j];
			}
		}
	}

    // dp 배열 출력
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }

    cout << "정답 : " << c[0][8] << endl;
    cout << "Recursive Property: " << "c[i][j] = max(c[i - 1][j], c[i][j - 1]) + cheeseWithTrap[i][j] (쥐덫은 0을 더함)" << endl;
    
    return 0;
}
