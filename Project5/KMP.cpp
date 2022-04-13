#include<iostream>
#include<cstring>
using namespace std;

int nextt[10];

void InitNext(string p) {
    int i, j;
    int M = p.length();
    nextt[0] = -1;
    for (i = 0, j = -1; i < M; i++, j++) {
        nextt[i] = j;
        while ((j >= 0) && (p[i] != p[j])) {
            j = nextt[j];
        }
    }
}

int KMP(string t, string p) {
    int N = t.length();
    int M = p.length();
    InitNext(p);
    int i, j;
    for (i = 0, j = 0; j < M && i < N; i++, j++) {
        while ((j >= 0) && (t[i] != p[j])) {
            j = nextt[j];
        }
    }
    if (j == M) {
        return i - M;
    }
    else {
        return i;
    }
}

int main() {
    
    string t = "ababababcababababcaabbabababcaab";
    string p = "abababca";
    
    //string t = "This class is an algorithm design class. Therefore, students will have time to learn about algorithms and implement each algorithm themselves.";
    //string p = "algorithm";

    string replaceStr;
    for (int i = 0; i < p.length(); i++) {
        replaceStr.append("0");
    }
    
    while (1) {
        cout << "패턴이 발생한 위치: " << KMP(t, p) << endl;
        t.replace(KMP(t, p), p.length(), replaceStr);
        if (KMP(t,p) == t.length()) break;
    }
    cout << "탐색 종료";

    return 0;
}
