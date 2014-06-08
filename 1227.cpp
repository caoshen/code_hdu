/** 1227
**/
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int INF = 1 << 30;
int a[205], cost[205][205], dp[205][35];



int main() {
	int n, k, t = 0;
	while (cin >> n >> k, n, k) {
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				cost[i][j] = 0;
				int mid = (i + j) >> 1;
				for (int l = i; l <= j; ++l)
					cost[i][j] += abs(a[l] - a[mid]);
			}
	
		memset(dp, 0, sizeof(0));
		for (int i = 1; i <= n; ++i)
			dp[i][1] = cost[1][i];
		for (int i = 2; i <= n; ++i)
			for (int j = 2; j <= k; ++j) {
				dp[i][j] = INF;
				for (int l = j - 1; l <= i - 1; ++l)
					dp[i][j] = min(dp[l][j - 1] + cost[l + 1][i], dp[i][j]);
			}
		cout << "Chain " << ++t << endl;
		cout << "Total distance sum = " << dp[n][k] << endl << endl;
	}
	return 0;
} 
