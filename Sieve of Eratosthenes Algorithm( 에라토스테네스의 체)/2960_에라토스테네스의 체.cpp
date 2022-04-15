//문제 제목은 에라토스테네스의 체지만, 해당 문제 내용은 소수 구하는 방식과는 거리가 있음!!

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
    ios_base::sync_with_stdio(0); //입출력 빠르게
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    cout << premium(n, k);


}
