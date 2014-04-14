/** 1159 
LCS
**/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int dp[1000][1000];
string s1, s2;

int lcs () {
	int m = s1.size(), n = s2.size();
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][ j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
			}
		}
	}
	cout << dp[m][n] << endl;
}

int main() {
	while (cin >> s1 >> s2) {
		memset(dp, 0, sizeof(dp));
		lcs();
	}
	return 0;
}
