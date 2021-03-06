#include <iostream>
#include <algorithm>
#include <vector>
#define INF 2000000000
using namespace std;
vector <int> answer(2);

int main() {

    //양쪽 끝에서 춟라한 두 포인터가 서로 반대 방향으로 다가워서 좁혀지는 형태의 투포인터 알고리즘ㄴ

    ios_base::sync_with_stdio(0); //입출력 빠르게
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n; //배열 원소 개수받기

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; //배열 원소 입력받기
    }

    sort(arr, arr + n); //배열 정렬

    int start = 0; // start은 왼쪽 끝에서
    int end = n - 1; // end는 오른쪽 끝에서 시작
    int min = INF; //현재까지 0에 가장 가까웠던 합

    while (start < end) {
        int sum = arr[start] + arr[end]; //두 원소의 합

        if (min > abs(sum)) { //기존에 구했던 두 수의 합보다 더 작은 합이 나왔으니 정답 후보가 될 수 있음

            min = abs(sum); 
            answer[0] = arr[start];
            answer[1] = arr[end];

            if (sum == 0) {
                break;
            }
        }

        if (sum < 0) {
            start++; //0보다 작으므로 두 수의 합이 더 커져야 하므로 start 증가 (작은 값을 더 큰값으로 대체)
        }

        else {
            end--; //0보다 크므로 두 수의 합이 더 작아야 0에 더 가까워지므로 end를 감소시킴 (큰 값을 더 작은 값으로 대체)
        }
    }

    cout << answer[0] << " " << answer[1];
}