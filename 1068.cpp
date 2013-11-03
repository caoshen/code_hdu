/* #1068
最大独立团 = 总顶点数 - 最小点覆盖数 / 2
*/ 

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 500;
int m[N][N];
int vis[N];
int match[N];
int n;

int dfs (int x) {
	for (int i = 0; i < n; i++) {
		if (m[x][i] && !vis[i]) {
			vis[i] = 1;
			if (match[i] == -1 || dfs (match[i])) {
				match[i] = x;
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	while (cin >> n) {
		memset(m, 0, sizeof(m));
		memset(match, -1, sizeof(match));
		for (int i = 0; i< n; i++) {
			int x, num;
			scanf("%d: (%d)", &x, &num);
			for (int j = 0; j < num; j++) {
				int y;
				cin >> y;
				m[x][y] = 1;
			}
		}
		int m = 0; 
		for (int i = 0; i < n; i++) {
			memset(vis, 0, sizeof(vis));
			if (dfs(i))
				m++;
		}
		cout << n - m / 2 << endl; 
	}
}
