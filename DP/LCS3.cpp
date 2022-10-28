#include <iostream>

using namespace std;

string s1;
string s2;
string s3;

int dp[101][101][101];

void solution() {
	for (int i = 1; i < s1.size(); i++) {
		for (int j = 1; j < s2.size(); j++) {
			for (int k = 1; k < s3.size(); k++) {
				if ((s1[i] == s2[j]) && (s2[j] == s3[k])) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else {
					dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
				}
			}
		}
	}

	int size1 = s1.size();
	int size2 = s2.size();
	int size3 = s3.size();

	cout << dp[size1 - 1][size2 - 1][size3 - 1];
}
void input() {
	cin >> s1 >> s2 >> s3;

	s1 = s1 + ' ';
	s2 = s2 + ' ';
	s3 = s3 + ' ';

	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solution();

}