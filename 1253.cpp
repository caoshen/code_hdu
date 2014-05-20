/** 1253
bfs
**/
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int map[55][55][55], vis[55][55][55];
int a, b, c, m;
int d[6][3] = {0, 0, 1,
            0, 0, -1,
            0, 1, 0,
            0, -1, 0,
            1, 0, 0,
            -1, 0, 0};

struct P{
    int x, y, z;
};

int bfs() {
    queue<P> que;
    memset(vis, 0, sizeof(vis));
    P p0 = {1, 1, b};
    que.push(p0);
    while (!que.empty()) {
        p0 = que.front();
        que.pop();
        if (p0.x == a && p0.y == c && p0.z == 1 && vis[a][c][1] <= m)
            return 1;
        for (int i = 0; i < 6; ++i) {
            P p1 = {p0.x + d[i][0], p0.y + d[i][1], p0.z + d[i][2]};
            if (map[p1.x][p1.y][p1.z] == 0 && !vis[p1.x][p1.y][p1.z]) {
                vis[p1.x][p1.y][p1.z] = vis[p0.x][p0.y][p0.z] + 1;
                que.push(p1);
            }
        }
    }
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        
        scanf("%d%d%d%d", &a, &b, &c, &m);
        memset(map, 1, sizeof(map));
        for (int i = 1; i <= a; ++i)
            for (int k = b; k >= 1; --k)
                for (int j = 1; j <= c; ++j)
                    scanf("%d", &map[i][j][k]);
        int ans = bfs();
        if (ans)
            printf("%d\n", vis[a][c][1]);
        else
            printf("-1\n");
    }
    return 0;
}
