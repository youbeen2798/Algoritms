#include <iostream>
#include <deque>
#include <vector>
#include <set>

using namespace std;

int n; //���� ����
int m; //���� ũ��
int t; //ȸ�� Ƚ��

deque<int> dq[51];

struct info {
	int xi;
	int di;
	int ki;
};

vector<info> v;

void rotate(info i) {
	int xi = i.xi; //��ȣ�� xi����� ������ 
	int di = i.di; //di��������
	int ki = i.ki; //kiĭ ȸ����Ų��.

	if (ki % m == 0) {
		ki = m;
	}
	else {
		ki = ki % m;
	}

	if (di == 0) { //�ð����
		
		for (int x = 1; x <= n; x++) {
			if (x % xi == 0) { //��ȣ�� xi ����� ������
				for (int j = 0; j < ki; j++) {
					int num = dq[x].back();
					dq[x].pop_back();
					dq[x].push_front(num);
				}
			}
		}

	}
	else { //�ݽð����
		for (int x = 1; x <= n; x++) {
			if (x % xi == 0) { //��ȣ�� xi ����� ������
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
	int xi = i.xi; //��ȣ�� xi����� ����

	set<pair<int, int>> s; //������ ���� ��ġ

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
		//��ȣ�� xi�� ����� ������ di �������� kiĭ ȸ����Ų��.
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