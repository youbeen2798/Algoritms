//���� ������ �����佺�׳׽��� ü����, �ش� ���� ������ �Ҽ� ���ϴ� ��İ��� �Ÿ��� ����!!

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