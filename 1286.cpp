/** 1286
**/
#include <iostream>
#include <cstdio>
using namespace std;

const int maxN = 32768;
int a[maxN];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		int cnt = 0;
		for (int i = 2; i  <= n / 2; ++i) {
			if (n % i)
				continue;
			for (int j = 1; i * j < n; ++j)
				a[i * j] = 1;
		}
		for (int i = 1; i < n; ++i)
			if (a[i] == 0) ++cnt;
		printf("%d\n", cnt);
	}
	return 0;
}
