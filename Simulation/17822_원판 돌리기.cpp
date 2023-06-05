#include <iostream>
#include <deque>
#include <vector>
#include <set>

using namespace std;

int n; //원판 개수
int m; //원판 크기
int t; //회전 횟수

deque<int> dq[51];

struct info {
	int xi;
	int di;
	int ki;
};

vector<info> v;

void rotate(info i) {
	int xi = i.xi; //번호가 xi배수인 원판을 
	int di = i.di; //di방향으로
	int ki = i.ki; //ki칸 회전시킨다.

	if (ki % m == 0) {
		ki = m;
	}
	else {
		ki = ki % m;
	}

	if (di == 0) { //시계방향
		
		for (int x = 1; x <= n; x++) {
			if (x % xi == 0) { //번호가 xi 배수인 원판을
				for (int j = 0; j < ki; j++) {
					int num = dq[x].back();
					dq[x].pop_back();
					dq[x].push_front(num);
				}
			}
		}

	}
	else { //반시계방향
		for (int x = 1; x <= n; x++) {
			if (x % xi == 0) { //번호가 xi 배수인 원판을
				for (int j = 0; j < ki; j++) {
					int num = dq[x].front();
					dq[x].pop_front();
					dq[x].push_back(num);
				}
			}
		}

	}
}

void erase(info i) {
	int xi = i.xi; //번호가 xi배수인 원판

	set<pair<int, int>> s; //삭제될 숫자 위치

	for (int x = 1; x <= n; x++) {
		for (int i = 0; i < m - 1; i++) {
			if (dq[x][i] == dq[x][i + 1] && dq[x][i] != -1) {
				s.insert({ x, i });
				s.insert({ x,i + 1 });
			}
		}
		if (dq[x][0] == dq[x][m - 1] && dq[x][0] != -1) {
			s.insert({ x, 0 });
			s.insert({ x, m - 1 });
		}
	}

	for (int x = 1; x < n; x++) {
		for (int j = 0; j < m; j++) {
			if (dq[x][j] == dq[x + 1][j] && dq[x][j] != -1){
				s.insert({ x, j });
				s.insert({ x + 1, j });
			}
		}
	}


	for (auto tmp : s) {
		dq[tmp.first][tmp.second] = -1;
	}

	if (s.size() == 0) {
		double sum = 0;
		double cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (dq[i][j] != -1) {
					sum += dq[i][j];
					cnt++;
				}
			}
		}

		double average = sum / cnt;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (dq[i][j] != -1 && average < dq[i][j]) {
					dq[i][j]--;
				}
				else if (dq[i][j] != -1 && average > dq[i][j]) {
					dq[i][j]++;
				}
			}
		}
	}
}

void solution() {

	for (int i = 0; i < t; i++) {
		rotate(v[i]);
		erase(v[i]);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (dq[i][j] != -1) {
				ans += dq[i][j];
			}
		}
	}
	cout << ans;
}
void input() {

	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int num;
			cin >> num;
			dq[i].push_back(num);
		}
	}

	for (int i = 0; i < t; i++) {
		int xi, di, ki;
		cin >> xi >> di >> ki; 
		//번호가 xi의 배수인 원판을 di 방향으로 ki칸 회전시킨다.
		v.push_back({ xi, di,ki });
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}