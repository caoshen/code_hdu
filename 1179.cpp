/**1179
匈牙利算法解决二分图匹配问题 
**/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 200;
int mat[MaxN][MaxN];
int match[MaxN];
int visit[MaxN];
int n, m;

int dfs(int u) {
	for (int v = 0; v < n; ++v) {
		if (mat[u][v] && !visit[v]) {
			visit[v] = 1;
			if (match[v] == -1 || dfs(match[v])) {
				match[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	while (cin >> n >> m) {
		int ans = 0;
		memset(mat, 0 , sizeof(mat));
		memset(match, -1, sizeof(match));
		
		for (int i = 0; i < m; ++i) {
			int num;
			cin >> num;
			for (int j = 0; j < num; ++j) {
				int k;
				cin >> k;
				mat[i][k - 1] = 1;
			}
		}
		for (int i = 0; i < m; ++i) {
			memset(visit, 0, sizeof(visit));
			if (dfs(i))
				++ans;
		}
		cout << ans << endl;
	}
	return 0;
}
