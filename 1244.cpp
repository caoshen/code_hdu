/** 1244
**/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[1005], b[25], s[1005], dp[10005][25];

int main() {
	int n, m;
	while (scanf("%d", &n) != EOF, n) {
		scanf("%d", &m);
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &b[i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
			s[i] = a[i] + s[i - 1];
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m && j <= i; ++j) {
				if (i >= b[j]) {
					dp[i][j] = max(dp[i- 1][j], dp[i - b[j]][j - 1] + s[i] - s[i - b[j]]);
				}
				else
					dp[i][j] = dp[i - 1][j];
			}	
		printf("%d\n", dp[n][m]);
	}
	return 0;
}
