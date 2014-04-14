/** 1166
Ê÷×´Êý×é binary index tree  
**/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxN = 50000 + 50;
int a[maxN], n;

int sum(int end) {
	int s = 0;
	while (end > 0) {
		s += a[end];
		end -= end & -end;
	}
	return s;
}

void update(int x, int num) {
	while (x <= n) {
		a[x] += num;
		x += x & -x;
	}
}

int main() {
	int t;
	cin >> t;
	int cnt = 0;
	while (t--) {
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; ++i) {
			int num;
			scanf("%d", &num);
			update(i, num);
		}
		cout << "Case " << ++cnt << ":" << endl;
		int a, b;
		char c[10];
		while (scanf("%s", &c)) {
			if (c[0] == 'E'){
				break;
			}
			scanf("%d %d", &a, &b); 
			if (c[0] == 'Q') {
				cout << sum(b) - sum(a - 1) << endl;
			}
			else if (c[0] == 'A') {
				update(a, b);
			}
			else if (c[0] == 'S') {
				update(a, -b);
			}
		}
	}
	return 0;
}
