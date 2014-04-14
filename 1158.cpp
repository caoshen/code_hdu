/** 1158
**/
#include <iostream>
#include <cstring>
using namespace std;

int dp[15][150];
int a[150];

const int INF = 2 << 20 - 1;

int main() {
	int n;
	while (cin >> n, n) {
		int hire, sal, fire;
		cin >> hire >> sal >> fire;
		int maxP = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			if (a[i] > maxP)
				maxP = a[i];
		}
		for (int i = 0; i < 15; ++i) {
			for (int j = 0; j < 150; ++j) {
				dp[i][j] = INF;
			}
		}
		// 最开始cost为0 
		dp[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = a[i]; j <= maxP; ++j) {
				for (int k = a[i - 1]; k <= maxP; ++k) {
					if (k < j) {
						dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * sal + (j - k) * hire);
					}
					else {
						dp[i][j] = min(dp[i][j], dp[i - 1][k] + j * sal + (k - j) * fire);
					}
				}
			}
		}
		int ans = INF;
		for (int j = 0; j <= maxP; ++j) {
			if (dp[n][j] < ans)
				ans = dp[n][j];
		}
		cout << ans << endl;
	}
	return 0;
}
