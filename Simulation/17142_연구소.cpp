#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n; //연구소 크기
int m; //놓을 수 있는 바이러스 개수
int map[51][51];
//0은 빈칸, 1은 벽, 2는 바이러스 위치
int spread_map[51][51];
bool visited[51][51];
vector<pair<int, int>> virus;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans = 9999;

bool inrange(int x, int y) {
	if (1 <= x && x <= n && 1 <= y && y <= n) {
		return true;
	}
	return false;
}

void spread(vector<pair<int, int>> virus) {

	memset(visited, false, sizeof(visited));
	memset(spread_map, 0, sizeof(spread_map));
	queue<pair<int, int>> q;

	for (int i = 0; i < virus.size(); i++) {
		q.push({ virus[i] });
		visited[virus[i].first][virus[i].second] = true;
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int k = spread_map[x][y];

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (inrange(nx, ny)) {
				if (map[nx][ny] != 1 && !visited[nx][ny]) {
					//빈칸이고
					spread_map[nx][ny] = k + 1;
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
				//else if (map[nx][ny] == 2 && !visited[nx][ny]) {
				//	map[nx][ny] = 0; //활성으로 변한다.
				//	q.push({ nx,ny });
				//}
			}
		}
	}	
}

void check() {

	int tmp_ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 0 && !visited[i][j]) {
				return;
			}
			else if (map[i][j] == 0) {
				tmp_ans = max(tmp_ans, spread_map[i][j]);
			}
		}
	}

	ans = min(ans, tmp_ans);
}
void combination(vector<pair<int, int>> arr, vector<pair<int, int>> comb, int r, int idx, int depth) {

	if (r == 0) {
		spread(comb);
		check();
		return;
	}
	else if (arr.size() == depth) {
		return;
	}
	else {

		comb[idx] = arr[depth];

		combination(arr, comb, r - 1, idx + 1, depth + 1);
		combination(arr, comb, r, idx, depth + 1);
	}
}
void solution() {

	vector<pair<int, int>> comb(m);

	combination(virus, comb, m, 0, 0);

	if (ans == 9999) {
		cout << -1;
	}
	else {
		cout << ans;
	}

}

void input() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}