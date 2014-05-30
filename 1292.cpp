/** 1292
**/

#include <iostream>
#include <cstdio>
using namespace std;

long long a[26][26];
void dp() {
	for (int i = 1; i <= 25; ++i)
		a[i][1] = 1;
	for (int i = 2; i <= 25; ++i)
		for (int j = 2; j <= i; ++j) {
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j] * j;
		}
}

int main () {
	int t;
	scanf("%d", &t);
	dp();
	while (t--) {
		int n;
		scanf("%d", &n);
		long long ans = 0;
		for (int i = 1; i <= n; ++i)
			ans += a[n][i];
		printf("%I64d\n", ans);
	}
	return 0;
}
