/** 1129
simulate crytography
**/
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int k, a[100], b[100];
	string s;
	while (cin >> k, k) {
		cin >> s;
		int n = s.size();
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 0; i < n; i++) {
			if (s[i] == '_')
				a[i] = 0;
			else if (s[i] == '.')
				a[i] = 27;
			else {
				a[i] = s[i] - 'a' + 1;
			}
			b[(k * i) % n] = (i + a[i]) % 28;
		}
		for (int i = 0; i < n; i++) {
			if (b[i] == 0)
				cout << '_';
			else if (b[i] == 27)
				cout << '.';
			else
				cout << (char) (b[i] - 1 + 'a') ;
		}
		cout << endl;
	}
	return 0;
}
