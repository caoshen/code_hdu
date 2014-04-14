/** 1556
Ïß¶ÎÊ÷ binary index tree
**/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
const int maxN =  100000 + 50;
int a[maxN];

int sum(int end) {
	int s = 0;
	while (end > 0) {
		s += a[end];
		end -= end & -end;
	}
	return s;
}

void add(int x, int num) {
	while (x <= n) {
		a[x] += num;
		x += x & -x;
	}
}

int main() {
	while (cin >> n, n) {
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			add(a, 1);
			add(b + 1, -1);
		}
		for (int i = 1; i <= n; ++i) {
			if (i < n)
				cout << sum(i) << " ";
			else
				cout << sum(i) << endl; 
		}
	}
	return 0;
}
