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
			q.push(input_num); //������ �߰�
		}

		else if (input == "front") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.front() << "\n"; //���� �ֻ��� ������ ��ȯ
			}
		}
		
		else if (input == "back") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.back() << "\n"; //���� ������ ������ ��ȯ
			}
		}
		else if (input == "size") {
			cout << q.size() << "\n";
		}
		else if (input == "empty") {
			if (q.empty()) { //ť�� ���������
				cout << "1" << "\n";
			}
			else { //ť�� ������� ������
				cout << "0" << "\n";
			}
		}
		else if (input == "pop") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.front() << "\n"; //���� �ֻ��� ������ ��ȯ
				q.pop(); //ť�� front ������ ����
			}
		}
	}

}