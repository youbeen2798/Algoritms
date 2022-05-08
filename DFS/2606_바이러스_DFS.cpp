//BFS Ȥ�� DFS�� Ǫ�� ���� 
//�Ʒ� �ڵ�� DFS�� Ȱ����

#include <iostream>
#define MAX 101
using namespace std;

int N, M; //��������, ��������
int sum = 0;
bool map[MAX][MAX];
bool visited[MAX]; //���� �湮 ����

void  DFS(int v) { //1 2
	visited[v] = true;

	for (int i = 1; i <= N; i++) {
		if (map[v][i] == 1 && visited[i] == 0) { //���� ������ ����Ǿ� �ְ� �湮���� �ʾҴٸ�
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