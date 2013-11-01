/* #1080
LCS 问题
用DP
注意矩阵的设置
*/
 
#include <iostream> 
#include <cstring>
using namespace std;

int max (int x, int y, int z) {
	return x > y ? ( x > z ? x : z) : ( y > z ? y : z);
}

int dp[110][110];

int map[5][5] = {
	5, - 3, -4, -2, -1,
	-3, 5, -1, -2, -1,
	-4, -1, 5, -3, -2,
	-2, -2, -3, 5, -2,
	-1, -1, -2, -2, 5,
};

int main () {
	int T;
	cin >> T;
	while (T--) {
		int len1, len2, str1[110], str2[110];
		char c;
		cin >> len1;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= len1; i++) {
			cin >> c;
			int n;
			switch (c) {
				case 'A' : 
					n = 1;
					break;
				case 'C' :
					n = 2;
					break;
				case 'G' :
					n = 3;
					break;
				case 'T' :
					n = 4;
					break; 
			}
			str1[i] = n;
			dp[i][0] = dp[i - 1][0] + map[n][0];
		}
		cin >> len2;
		for (int i = 1; i <= len2; i++) {
			cin >> c;
			int n;
			switch (c) {
				case 'A' : 
					n = 1;
					break;
				case 'C' :
					n = 2;
					break;
				case 'G' :
					n = 3;
					break;
				case 'T' :
					n = 4;
					break; 
			}
			str2[i] = n;
			dp[0][i] = dp[0][i - 1] + map[0][n];
		}
		for (int i = 1; i <= len1; i++)
			for (int j = 1; j <= len2; j++) {
				dp[i][j] = max (dp[i - 1][j] + map[str1[i]][0], dp[i][j - 1] + map[0][str2[j]], dp[i - 1][j - 1] + map[str1[i]][str2[j]]);
			}
		cout << dp[len1][len2] << endl;
	}	
}
