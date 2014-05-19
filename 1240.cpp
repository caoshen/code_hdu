/** 1240
bfs
find a path in cube
**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

char a[12][12][12];
int vis[12][12][12];
int n, s1, s2, s3, e1, e2, e3;
int d[6][3] = {0, 0, 1,
			0, 0, -1,
			1, 0, 0,
			-1, 0, 0,
			0, 1, 0,
			0, -1, 0};

struct P{
	int x, y, z;
};

int bfs() {
	queue<P> que;
	memset(vis, 0, sizeof(vis));
	P p0 = {s1 + 1, s2 + 1, s3 + 1};
	que.push(p0);
	while (!que.empty()) {
		p0 = que.front();
		que.pop();
		if (p0.x == e1 + 1 && p0.y == e2 + 1 && p0.z == e3 + 1)
				return 1;
		for (int i = 0; i < 6; ++i) {
			P p1 = {p0.x + d[i][0], p0.y + d[i][1], p0.z + d[i][2]};
			if (a[p1.x][p1.y][p1.z] == 'O' && !vis[p1.x][p1.y][p1.z]) {
				que.push(p1);
				vis[p1.x][p1.y][p1.z] = vis[p0.x][p0.y][p0.z] + 1;
			}
		}
	}
	return 0;
}

int main () {
	
	while (scanf("START %d", &n) != EOF) {
		getchar();
		for (int k = 1; k <= n; ++k)
			for (int j = 1; j <= n; ++j) {
				for (int i = 1; i <= n; ++i)
					scanf("%c", &a[i][j][k]);
				getchar();
			}
	
		scanf("%d %d %d", &s1, &s2, &s3);
		scanf("%d %d %d", &e1, &e2, &e3);
		char endc[10];
		scanf("%s", endc);
		getchar();
		
		int ans = bfs();
		if (a[s1 + 1][s2 + 1][s3 + 1] == 'X' || a[e1 + 1][e2 + 1][e3 + 1] == 'X') {
			printf("NO ROUTE\n");
			continue;
		}
		if (ans)
			printf("%d %d\n", n, vis[e1 + 1][e2 + 1][e3 + 1]);
		else
			printf("NO ROUTE\n");
	}
	return 0;
}
