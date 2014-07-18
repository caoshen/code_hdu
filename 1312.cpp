#include <iostream>
#include <queue>
#include <utility>
#include <cstdio>
using namespace std;

char mat[20][20];
int vis[20][20];
int x, y, m, n;
int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

typedef pair<int, int> Node ;

int bfs() {
	queue<Node> q;
	Node p(x, y);
	int ret = 0;
	q.push(p);
	while (!q.empty()) {
		Node p0 = q.front();
		q.pop();
		++ret;		
		int x = p0.first, y = p0.second;
		for (int i = 0; i < 4; ++i) {
			int x0 = x + d[i][0];
			int y0 = y + d[i][1];
			if (x0 < m && x0 >= 0 && y0 < n && y0 >= 0 && mat[x0][y0] == '.' && vis[x0][y0] == 0) {
				vis[x0][y0] = 1;
				q.push(make_pair(x0, y0));
			}
		}
	}
	return ret;
}

int main() {
	while (cin >> n  >> m, m + n) {
		x = -1, y = -1;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> mat[i][j];
				if (mat[i][j] == '@') {
					x = i;
					y = j;
				}
			}
		}
		memset(vis, 0, sizeof(vis));
		cout << bfs() << endl;
	}
}
