//서로 다른 N개의 자연수의 합이 S라고 할 때, S를 알 때 자연수 N의 최댓값은 얼마일까?

#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0); //입출력 빠르게
	cin.tie(0);
	cout.tie(0);

	long long S;
	cin >> S; //정수 S입력받기

	long long sum = 0;
	int num = 1;
	int cnt = 0;
	while (1) {
		sum += num; //1부터 합 구하기
		cnt++;
		if (sum > S) { // 합이 구하려는 숫자보다 크다면
			cnt--; //cnt 줄이고
			break; //반복문 탈출
		}
		num++;
	}

	cout << cnt;
}