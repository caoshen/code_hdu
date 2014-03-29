/** 1150
二分图 最小覆盖数 = 最大匹配数 
**/
#include <iostream>
#include <cstring>
using namespace std;

const int Maxn = 110;
int map[Maxn][Maxn];
int visit[Maxn];
int match[Maxn];
int m, n, k;

int dfs(int u) {
	for (int v = 1; v < n; ++v) {
		if (map[u][v] && !visit[v]) {
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
	while (cin >> m,m) {
		cin >> n >> k;
		memset(map, 0, sizeof(map));
		memset(match, -1, sizeof(match));
		for (int i = 0; i < k; ++i) {
			int d, e, f;
			cin >> d >> e >> f;
			if (e && f) {
				map[e][f] = 1;
			}
		}
		int cnt = 0;
		for (int u = 1; u < m; u++) {
			memset(visit, 0, sizeof(visit));
				cnt += dfs(u);
		}
		cout << cnt << endl;
	}
	return 0;
}

