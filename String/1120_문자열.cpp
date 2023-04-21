#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string A;
string B;
int ans = 100;

void solution() {

	int diff = B.size() - A.size();

	for (int i = 0; i <= diff; i++) {
		int k = 0;
		int tmp_cnt = 0; 
	//	cout << "#####" << "\n";
		for (int j = i; j < i + A.size(); j++) {
	//		cout << "k: " << k << " j: " << j << "\n";
			if (A[k++] != B[j]) {
				tmp_cnt++;
			}
		}
		ans = min(ans, tmp_cnt);
	}

	cout << ans << "\n";
}
void input() {

	cin >> A >> B;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();
}