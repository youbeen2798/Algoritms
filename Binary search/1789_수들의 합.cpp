//���� �ٸ� N���� �ڿ����� ���� S��� �� ��, S�� �� �� �ڿ��� N�� �ִ��� ���ϱ�?

#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0); //����� ������
	cin.tie(0);
	cout.tie(0);

	long long S;
	cin >> S; //���� S�Է¹ޱ�

	long long sum = 0;
	int num = 1;
	int cnt = 0;
	while (1) {
		sum += num; //1���� �� ���ϱ�
		cnt++;
		if (sum > S) { // ���� ���Ϸ��� ���ں��� ũ�ٸ�
			cnt--; //cnt ���̰�
			break; //�ݺ��� Ż��
		}
		num++;
	}

	cout << cnt;
}