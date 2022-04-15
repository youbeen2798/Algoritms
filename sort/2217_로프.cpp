#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int* array = new int[n]; //�迭 ����

	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	sort(array, array + n); //�迭 �������� ����

	int* weight = new int[n];

	for (int i = 0; i < n; i++) {
		weight[i] = array[i] * (n - i);
	}

	sort(weight, weight + n);

	cout << weight[n - 1];

}