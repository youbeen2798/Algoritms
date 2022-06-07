#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[500005];

int lower_idx(int target, int len){
	int st = 0;
	int en = len;

	while (st < en) {
		int mid = (st + en) / 2;
		if (target > a[mid]) {
			st = mid + 1;
		}
		else {
			en = mid;
		}
	}
	return st;
}

int upper_idx(int target, int len) {
	int st = 0;
	int en = len;
	while (st < en) {
		int mid = (st + en) / 2;
		if (target >= a[mid]) {
			st = mid + 1;
		}
		else {
			en = mid;
		}
	}
	return st;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);
	cin >> m;

	while (m--) {
		int k;
		cin >> k;
		
		int low_idx = lower_idx(k, n);
		int high_idx = upper_idx(k, n);

		cout << high_idx - low_idx << "\n";
	}
}