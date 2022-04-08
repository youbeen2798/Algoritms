#include <iostream>
#include <stack>
using namespace std;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	stack <int> s;
	string st;
	int input;

	for (int i = 0; i < n; i++) {
		cin >> st;

		if (st == "push") { 
			cin >> input;
			s.push(input); //정수를 스택에 넣는 연산
		}

		if (st == "pop") {
			if (s.empty()) {
				cout << "-1" << "\n"; //스택에 들어있는 정수가 없는 경우에는 -1 출력
			}
			else {
				cout << s.top() <<"\n"; //스택에서 가장 위에 있는 수를 출력하고
				s.pop(); //그 수를 뺀다.
			}
		}

		if (st == "size") {
			cout << s.size() << "\n"; //스택에 들어있는 정수의 개수를 출력
		}

		if (st == "empty") {
			if (s.empty()) { //스택이 비어있으면
				cout << "1" << "\n"; //1 출력
			}
			else { //스택에 비어있지 않다면
				cout << "0" << "\n"; //0 출력
			}
		}
		if (st == "top") {
			if (s.empty()) { //스택에 들어있는 정수가 없다면
				cout << "-1" << "\n"; //-1 출력
			}
			else {
				cout << s.top() << "\n"; //스택의 가장 위에 있는 정수 출력
			}
		}
	}
}
