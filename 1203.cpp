/** 1203
dp
**/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int c[10005];
double p[10005], dp[10005];

int main() {
	int n, m;
	while (cin >> n >> m, n || m) {
		for (int i = 0; i < m; ++i) {
			cin >> c[i] >> p[i];
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < m; ++i)
			for (int j = n; j >= c[i]; --j)
				dp[j] = max(dp[j], p[i] + (1 - p[i]) * dp[j - c[i]]);
		printf("%.1lf%%\n", 100 * dp[n]);
	}
	return 0;
}
