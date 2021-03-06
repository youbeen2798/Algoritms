#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool visited[25][25];
int cnt;
string arr[25];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector <int> ans;

void dfs(int x, int y) {
	cnt++;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (visited[nx][ny] == false && arr[nx][ny] == '1') {
				dfs(nx, ny);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && arr[i][j] == '1') {
				cnt = 0;
				dfs(i, j);
				ans.push_back(cnt);
			}
		}
	}

	
	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}
