#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue <int> q;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int input_num;
	string input;

	for (int i = 0; i < n; i++) {
		cin >> input;

		if (input == "push") {
			cin >> input_num;
			q.push(input_num); //데이터 추가
		}

		else if (input == "front") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.front() << "\n"; //제일 최상위 데이터 반환
			}
		}
		
		else if (input == "back") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.back() << "\n"; //제일 마지막 데이터 반환
			}
		}
		else if (input == "size") {
			cout << q.size() << "\n";
		}
		else if (input == "empty") {
			if (q.empty()) { //큐가 비어있으면
				cout << "1" << "\n";
			}
			else { //큐가 비어있지 않으면
				cout << "0" << "\n";
			}
		}
		else if (input == "pop") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.front() << "\n"; //제일 최상위 데이터 반환
				q.pop(); //큐의 front 데이터 삭제
			}
		}
	}

}