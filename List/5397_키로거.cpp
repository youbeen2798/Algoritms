#include <iostream>
#include <string>
#include <list>
using namespace std;

int n;
string st;

list <char> L;
list <char>::iterator iter;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	while (n--) {
		
		cin >> st;

		L.clear(); //리스트 초기화
		iter = L.begin(); //iter 초기화

		for (int i = 0; i < st.size(); i++) {
			if (st[i] == '>') {
				if (iter != L.end()) {
					iter++;
				}
			}
			else if (st[i] == '<') {
				if (iter != L.begin()) {
					iter--;
				}
			}
			else if (st[i] == '-') {
				if (iter != L.begin()) {
					iter--;
					L.erase(iter++);
				}
			}
			else {
				L.insert(iter, st[i]);
			}			
		}
		for (iter = L.begin(); iter != L.end(); iter++) {
			cout << *iter;
		}
		cout << "\n";
		}	
}
