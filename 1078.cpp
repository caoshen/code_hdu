/* #1078
bfs(x, y) = max { bfs(x1, y1) } + path(x, y)
x1, y1 是从 x, y 出发所有可能到达的路径 
*/

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100;
int sum[MAXN][MAXN];
int path[MAXN][MAXN];
int n, k;

int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int dfs( int x, int y) {
	int num = 0, x1, y1;
	if (sum[x][y] != 0)
		return sum[x][y];
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < 4; j++) {
			x1 = x + i * dx[j];
			y1 = y + i * dy[j];
			if ( x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && path[x1][y1] > path[x][y]) {
				num = num < dfs(x1, y1) ? dfs(x1, y1) : num;
			}
		}
	}
	return sum[x][y] = num + path[x][y];
}

int main() {
	while (cin >> n >> k) {
		if (n == -1 && k == -1)
			break;
		memset(sum, 0, sizeof(sum));
		memset(path, 0, sizeof(path));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> path[i][j];
		cout << dfs(0, 0) << endl;
	}
	return 0;
}
