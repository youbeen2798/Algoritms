#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int weight;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	vector <int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int max = 0;

	for (int i = 0; i < n; i++) {
		weight = v[i] * (n - i);
		if (weight > max) {
			max = weight;
		}
	}
	cout << max;
}