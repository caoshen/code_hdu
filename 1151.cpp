/** 1151 
**/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 150;
int map[Maxn][Maxn];
int visit[Maxn];
int match[Maxn];

int n;

int dfs(int u) {
	for (int v = 1; v <= n; ++v) {
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
	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> n >> m;
		memset(match, -1, sizeof(match));
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= m; ++i) {
			int s, e;
			scanf("%d%d", &s, &e);
			map[s][e] = 1;
		}
		int cnt = 0;
		for (int u = 1; u <= n; ++u) {
			memset(visit, 0, sizeof(visit));
			cnt += dfs(u);
		}
		cout << n - cnt << endl;
	}
	return 0;
}
