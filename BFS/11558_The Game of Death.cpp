#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T; //1

	while (T--) {
		int N;
		cin >> N; //7
		int* array = new int[N+1];

		for (int i = 1; i <= N; i++) {
			cin >> array[i]; //2 3 4 5 6 7 1
		}

		int k = 0;
		int c = 1;

		while (k < N && c != N) {
			c = array[c]; //2 3 4 5 6 7
			k++; //1 2 3 4 5 6
		}

		if (c != N)
			cout << "0";
		else
			cout << k;

	}
}