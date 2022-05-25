#include <iostream>
using namespace std;

struct items {
    int weight, val;
}; 

int P[100][100], n, k;
items jewel[100];

int main() {
    cout << "베낭 무게와 보석 개수를 입력해주세요.\n";
    cin >> k >> n; // 배낭 무게 k, 보석 개수 n

    // 보석의 무게와 가치(w, v)를 입력받는다.
    cout << "보석 무게와 가치를 입력해주세요.\n";
    for (int i = 1; i <= n; i++) {
        int w, v;
        cin >> w >> v;
        jewel[i] = { w, v };
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= k; w++) {
            int wi = jewel[i].weight;
            int pi = jewel[i].val;

            // i번째 물체의 무게를 포함시키지 않는 경우
            if (wi > w) {
                P[i][w] = P[i - 1][w];
            }// i번째 물체의 무게를 포함시키는 경우
            else {
                P[i][w] = max(P[i - 1][w], pi + P[i - 1][w - wi]);
            }

        }
    }
    cout << "입력 2에 대하여 가방에 담은 보석의 최대 가치: " << P[n][k] << endl;
    return 0;
}
