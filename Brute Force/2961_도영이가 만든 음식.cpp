//직접 조합을 이용하여 완전탐색을 한 문제
//

#include <iostream>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
using namespace std;

vector <int> collect;

void Combination(vector <pair<int, int>> v, vector <pair<int, int>> comb, int r, int index, int depth) {
	//벡터 v는 입력받은 벡터
	// 벡터 comb는 처음에 빈 벡터로 시작하며, 하나의 조합이 완성되면 r크기를 가지는 벡터가 될 것임
	// r은 v중에서 몇 개를 더 뽑아야 하는지를 나타내는 수
	// index는 v로부터 원소를 뽑을 때 뽑은 원소를 comb에 넣을 위치(인덱스)
	// depth은 v를 순회하는 인덱스
	int sour = 1;
	int bitter = 0;

	if (r == 0)  //depth가 v.size에 도달하기 전에 r개만큼 다 뽑은 경우로, comb가 결정되어 조합의 한 경우가 결정된 때
	{
		for (int i = 0; i < comb.size(); i++) {
			sour *= comb[i].first; //신맛은 곱하고
			bitter += comb[i].second; //쓴맛은 더한다.
		}

		collect.push_back(abs(sour - bitter)); // 최종 신맛과 최종 쓴맛의 차이를 collect 벡터에 저장

	}
	else if (depth == v.size()) // depth가 v.size()에 도달했으나, 즉, v의 모든 원소를 순회했는데도 r이 0이 되지 않아 조합의 경우들 중 하나가 될 수 없는 케이스
	{
		return; //정답 중 하나가 될 수 없으므로 return한다.
	}
	else
	{
		comb[index].first = v[depth].first;
		comb[index].second = v[depth].second;

		Combination(v, comb, r - 1, index + 1, depth + 1);

		Combination(v, comb, r, index, depth + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); //입출력 빠르게
	cin.tie(0);
	cout.tie(0);

	int k;
	cin >> k;
	
	vector <pair<int, int>> v(k);

	for (int i = 0; i < k; i++) {
		cin >> v[i].first >> v[i].second;
	}


	for (int r = 1; r <= k; r++) {

		vector <pair<int, int>> comb(r); //조합의 개수가 r인 경우
		Combination(v, comb, r, 0, 0);
	}


	sort(collect.begin(), collect.end()); //신맛과 쓴맛이 모여진 값들의 모임들 중 가장 작은 값을 가져야 하므로 정렬
	
	cout << collect[0]; //가장 작은 값 출력

	return 0;
}