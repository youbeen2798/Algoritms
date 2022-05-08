//BFS 혹은 DFS로 푸는 문제 
//아래 코드는 DFS를 활용함

#include <iostream>
#define MAX 101
using namespace std;

int N, M; //정점개수, 간선개수
int sum = 0;
bool map[MAX][MAX];
bool visited[MAX]; //정점 방문 여부

void  DFS(int v) { //1 2
	visited[v] = true;

	for (int i = 1; i <= N; i++) {
		if (map[v][i] == 1 && visited[i] == 0) { //현재 정점과 연결되어 있고 방문하지 않았다면
			sum++;
			DFS(i); //5 6 3
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		map[a][b] = 1;
		map[b][a] = 1;
	}

	DFS(1);

	cout << sum;

	return 0;
}