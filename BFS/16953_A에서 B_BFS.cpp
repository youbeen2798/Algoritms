#include <iostream>
#include <queue>
using namespace std;

int A, B;

queue <pair<long long,long long>> q;
int mini = 1000000;
void BFS(long long a, long long cnt) {
	q.push(make_pair(a, cnt)); //2 1

	while (!q.empty()) {
		pair<long long, long long> now = q.front();
//		cout << "now.first: " << now.first << "\n"; //2
//		cout << "now.second: " << now.second << "\n"; //1
		q.pop();

		if (now.first == B) {
//			cout << "now.second: " << now.second << "\n";
//			cout << "mini: " << mini << "\n";

			if (now.second <= mini) {
				mini = now.second;
			}
		}
		if (now.first *2 <= B) {
			q.push(make_pair(now.first * 2, now.second + 1));
		}
		if (now.first * 10 + 1 <= B) {
			q.push(make_pair(now.first * 10 + 1, now.second + 1));
		}
	}

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B;

	BFS(A, 1); // 2 1

	if (mini == 1000000) {
		cout << -1;
	}
	else {
		cout << mini;
	}
}