/** 1208
dp
**/

#include <iostream>
#include <cstring>
using namespace std;

int main () {
	long long n, a[40][40], dp[50][50];
	while (cin >> n, n != -1) {
		getchar(); // '\n'
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				char c;
				cin >> c;
				a[i][j] = c - '0';
			}
			getchar(); // '\n' 
		}
		memset(dp, 0, sizeof(dp));
		dp[1][1] = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				if (a[i][j] == 0)
					continue;
				dp[i][j + a[i][j]] += dp[i][j];
				dp[i + a[i][j]][j] += dp[i][j];
			}
		cout << dp[n][n] << endl;
	}
	return 0;
} 
