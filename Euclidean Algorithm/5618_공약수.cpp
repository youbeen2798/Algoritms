#include <iostream>

using namespace std;

int gcd(int a, int b) {
	int r = a % b;

	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	
	return b;
}

int main() {
	ios_base::sync_with_stdio(0); //����� ������
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int* array = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> array[i]; //�迭 �Է¹ޱ�
	}

	if (n == 2) {
		int a = gcd(array[0], array[1]); //�ִ����� ���ϱ�
			for (int i = 1; i <= a; i++) { //�ִ������� ��� (�����) ���ϱ�
				if (a % i == 0) {
					cout << i << "\n";
				}
			}
		}
	else if (n == 3) {
		int temp = gcd(array[0], array[1]); //�� ���� �ִ����� ���ϱ�
		int a = gcd(temp, array[2]); // �� ���� �ִ������� ������ ���� �ִ����� ���ϱ�

		for (int i = 1; i <= a; i++) { //�ִ������� ���(�����) ���ϱ�
			if (a % i == 0) {
				cout << i << "\n";
			}
		}
	}
}