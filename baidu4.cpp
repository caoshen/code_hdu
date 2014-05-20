/** 1004
**/
#include <iostream>
#include <cstdio>
using namespace std;

const int maxN = 105;
const int INF = 1 << 30;
int a[maxN][maxN], dp[maxN][maxN];
int m, n;

void dP(int c) {
	for (int i = 1; i <= m; ++i) {
		int tmp = dp[i][c - 1] + a[i][c];
		dp[i][c] = max(dp[i][c], tmp);
		for (int j = i + 1; j <= m; ++j) {
			tmp += a[j][c];
			dp[j][c] = max(dp[j][c], tmp);
		}
	}
	for (int i = m; i >= 1; --i) {
		int tmp = dp[i][c - 1] + a[i][c];
		dp[i][c] = max(dp[i][c], tmp);
		for (int j = i - 1; j >= 1; --j) {
			tmp += a[j][c];
			dp[j][c] = max(dp[j][c], tmp);
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	int t0 = 0;
	while (t--) {
		scanf("%d %d", &m, &n);
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &a[i][j]);
				dp[i][j] = -INF;
			}
		dp[1][1] = a[1][1];
		for (int i = 2; i <= m; ++i)
			dp[i][1] = dp [i - 1][1] + a[i][1];
		for (int i = 2; i <= n; ++i)
			dP(i);
		printf("Case #%d:\n", ++t0);
		printf("%d\n", dp[1][n]);
	}
	return 0;
}
