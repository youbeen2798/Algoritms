//문제 제목은 에라토스테네스의 체지만, 해당 문제 내용은 소수 구하는 방식과는 거리가 있음!!

#include <iostream>
#include <vector>
using namespace std;


int premium(int n, int k) {
	vector <bool> v(n + 1);
	int count = 0;
	v[0] = 1;
	v[1] = 1;

	for (int i = 2; i <= n; i++) {
		if (v[i] == 1) {
			continue;
		}
		for (int j = i; j <= n; j += i) {
			if (v[j] == 0) {
				v[j] = 1;
				count++;
//				cout << j << ", count: " << count << "\n";
			}
	
			if (count == k) {
				return j;
			}
		}
	}

}


int main() {

	int n, k;
	cin >> n >> k;

	cout << premium(n, k);


}