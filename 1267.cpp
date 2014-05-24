/** 1267
**/
#include <iostream>
#include <cstdio>
using namespace std;
long long dp[21][21];

int main () {
	for (int i = 1; i <= 20; ++i)
		for (int j = 1; j <= i; ++j) {
			if (j == 1)
				dp[i][j] = i;
			else
				dp[i][j] = dp[i - 1][j]  + dp[i][j - 1];
		}
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF)
		printf("%I64d\n", dp[m][n]);
	return 0;
} 
