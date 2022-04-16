#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector <bool> premium(int m) { // 1���� ���� m���� �Ҽ� �Ǻ� �Լ�(�Ҽ��� 0, �ƴϸ� 1)
	vector <bool> v(m + 1);

	v[0] = 1;
	v[1] = 1;

	for (int i = 2; i <= sqrt(m); i++) {
		if (v[i] == 1){
			continue;
		}
		for (int j = 2 * i; j <= m; j += i) {
			v[j] = 1;
		}
	}
	return v; // ���� m���� �Ҽ��� 0, �ƴϸ� 1�� ���� ��ȯ
}

int main() {
	ios_base::sync_with_stdio(0); //����� ������
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;

	vector <bool> vt = premium(n);

	for (int i = m; i <= n; i++) { // ���� m���� n����
		if (vt[i] == 0) { // �Ҽ��̸�
			cout << i << '\n'; // ���
		}
	}
}