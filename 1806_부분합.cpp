#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, sum;
	cin >> n >> sum;

	int* input = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	int start = 0, end = 0, total = input[0];

	int length = 100001;
	while (start <= end && end < n) {
		if (total >= sum) {
			length = min(length, (end - start + 1));
		}
		if(total < sum) {
			end++;
			total += input[end];
		}
		else {
			total -= input[start];
			start++;
		}
	}
}