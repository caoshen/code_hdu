/* #1054
����dp
 dp[r][0] ��ʾ �� r Ϊ���� ���� �� r �� ���� ʿ�� �� ��Сֵ
dp[r][1] �Ƿ�ʿ������Сֵ 
 dp[r][0] =  �� dp[j][1]  j  Ϊ r �� �ӽڵ�
dp[r][1] =  �� min( dp[j][1],dp[j][0] ) + 1��
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 2000;

vector<int> g[MAXN];
int vis[MAXN], dp[MAXN][2];

void dfs(int r)  {
	if (vis[r] == 1)
		return;
	vis[r] = 1;
	dp[r][0] = 0;
	dp[r][1] = 1;
	
	if (g[r].size() == 0)
		return;
	
	for (int i = 0; i < g[r].size(); i++) {
		int j = g[r][i]; // ! �ڽ�� 
		if (vis[j] == 1)
			continue;
		dfs(j);
		dp[r][0] += dp[j][1];
		dp[r][1] += min(dp[j][0] , dp[j][1]);
	}
}

int main() {
	int n;
	while (cin >> n) {
		if (n == 0)
			break;
		memset(vis, 0 , sizeof(vis));
		for (int i = 0; i < n; i++)
			g[i].clear();
		for (int i = 0; i < n; i++) {
			int num, x, y;
			scanf("%d:(%d)", &x, &num);
			for (int j = 0; j < num; j++) {
				cin >> y;
				g[x].push_back(y);
				g[y].push_back(x);
			}
		}
		dfs(0);
		cout << min(dp[0][0], dp[0][1]) << endl;
	}
}
