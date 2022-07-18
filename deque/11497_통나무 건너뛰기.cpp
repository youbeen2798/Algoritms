#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int t, n;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	for (int test_case = 0; test_case < t; test_case++) {
		cin >> n;

		vector <int> v(n);

		deque <int> dq;

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		sort(v.rbegin(), v.rend());

		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				dq.push_back(v[i]);
			}
			else {
				dq.push_front(v[i]);
			}
		}

		int diff = 0;
		for (int i = 0; i < dq.size()-1; i++) {
			int diff2 = abs(dq[i + 1] - dq[i]);
			if (diff2 > diff) {
				diff = diff2;
			}
		}

		int diff2 = abs(dq.back() - dq.front());

		if (diff2 > diff) {
			diff = diff2;
		}

		cout << diff << "\n";
		
	}
}