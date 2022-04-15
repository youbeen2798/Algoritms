//���� ������ �����佺�׳׽��� ü����, �ش� ���� ������ �Ҽ� ���ϴ� ��İ��� �Ÿ��� ����!!

#include <iostream>
using namespace std;

int premium(int n, int k) {
    int* array = new int[n + 1];

    int count = 0;

    for (int i = 2; i <= n; i++) {
        if (array[i] == 1)
            continue;
        for (int j = i; j <= n; j += i) {
            if (array[j] == 0) {
                array[j] = 1;
                count++;
            }
            if (count == k) {
                return j;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    cout << premium(n, k);


}