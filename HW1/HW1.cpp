#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int NUM = 95; //아스키코드에서 표현 가능한 문자의 개수(공백 포함)
int skip[NUM]{}; //skip 배열을 전역 변수로 선언
int MisChar(string&, string);

int main() {
	ifstream f("C:\\Users\\이승은\\Desktop\\인하\\3-1\\알고리즘 설계\\과제1\\RFC2616_modified.txt");
	// 파일입력 스트림 객체 f를 선언하고 RFC2616_modified.txt 파일을 연결한다.
	
	if (f.fail()) {                // 파일을 여는데 실패하면  
		cout << "file open error"; // file open error를 출력하고 
		return 1;                  // 프로그램을 종료한다.
	}

	string pattern; // 패턴을 입력 받을 string 선언
	cout << "Enter pattern to search : ";
	getline(cin, pattern); // 공백을 포함해서 패턴을 입력받는다

	int i = 0;    // i는 파일에서 행을 계산할 index
	string line;  // 파일에서 한 줄씩 담을 string 선언
	while (getline(f, line)) { 
	// 문자열이 더 이상 없을 때 까지 한 줄씩 입력받아 line에 저장하는 것을 반복
		int M = pattern.length(); // M은 패턴의 길이
		int N = line.length();    // N은 텍스트의 길이

		int pos = 0;
		int a = 0;
		// pos는 MisChar 함수의 반환 값(찾아낸 패턴의 위치)을 저장
		// a는 반환 된 pos에 M값을 더한 값(다시 탐색을 시작할 위치)을 저장

		// a가 N보다 크면 text의 범위를 벗어난것이므로 반복 종료
		while (a < N) {
			pos = MisChar(pattern, line.substr(a)); // substr를 통해 이전에 찾은 패턴 다음부터 탐색
			pos = pos + a; // 이전에 찾은 a값을 pos에 더해주고
			a = pos + M;   // a값 업데이트

			if (a <= N) // a가 N보다 작거나 같으면(패턴이 텍스트의 끝부분까지 존재한다면)
				cout << "\nLn " << i + 1 << ", Col " << pos + 1 << " : " << line << endl;
		}       // 해당 행, 인덱스, 문장의 내용을 출력
		i++; // 행에 1을 더한다
	}
	cout << "\n탐색 종료\n"; // 문자열의 끝까지 탐색을 완료
	cout << "알고리즘 설계 과제1 12201933 이승은\n";

	f.close();
	return 0;
}

int index(char c) {
	// 공백 문자, 알파벳, 숫자, 특수문자가 들어옴(아스키코드 32 ~ 126)
	return (c - 32); 
}

void InitSkip(string& p) { // skip 배열을 만드는 함수
	int M = p.length();    //M은 패턴의 길이

	for (int i = 0; i < NUM; ++i) // 패턴에 없는 문자면 패턴 문자열 길이만큼 skip
		skip[i] = M; 

	for (int i = 0; i < M; ++i) // 패턴에 있는 문자면 패턴의 끝과 그 문자와의 거리만큼 skip
		skip[index(p[i])] = M - i - 1;

	// 패턴 문자열의 맨 뒤에서 맨 앞까지 0 ~ M-1이 차례로 하나씩 값으로 주어지고
	// 나머지 문자들은 M이 값으로 들어가게 된다.
}

int MisChar(string& p, string t) {
	int M = p.length(); // M은 패턴의 길이
	int N = t.length(); // N은 텍스트의 길이
	//반복자 선언
	int i; // i는 텍스트의 인덱스
	int j; // j는 패턴의 인덱스
	InitSkip(p); //skip 배열을 만듬

	// 패턴의 오른쪽 끝에서부터 비교 시작
	for (i = M - 1, j = M - 1; j >= 0; --i, --j) {
		while (t[i] != p[j]) { // 불일치가 발생하면 

			int k = skip[index(t[i])]; // 불일치 당시 텍스트에서의 문자의 skip 배열 값을 k에 저장

			if (M - j > k) // M - j(패턴의 길이 - 불일치 당시 패턴의 인덱스)가 k보다 크면
				i = i + M - j; //M - j(패턴의 길이 - 불일치 당시 패턴의 인덱스)만큼 텍스트의 오른쪽으로 이동해서 비교
			else           // M - j가 k보다 작거나 같으면
				i = i + k; // k만큼 텍스트의 오른쪽으로 이동해서 비교

			if (i >= N)   // i가 텍스트의 길이보다 같거나 커지면(끝까지 비교를 완료하면)
				return N; // N을 반환

			j = M - 1; // j를 다시 패턴의 마지막인 M - 1로 초기화
		}
	}
	return i + 1; // 패턴의 위치 return
}
