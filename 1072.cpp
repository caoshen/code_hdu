/* #1073
迷宫问题bfs , not dfs
*/

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 10;
int dx[4] = { 0, 0, -1, 1};
int dy[4] = { 1, -1, 0, 0};
int a[MAXN][MAXN];
int M, N;

struct S {
    int x, y, tot, t;
}start;

void bfs () {
    int front = 0, rear = 1;
    S s[10000], s1, s0; // 数组要开的够大，因为访问过的可能被再次访问
    s[0] = start;
    while (front < rear) {
        s0 = s[front];
        front++;
        for (int i = 0; i < 4; i++) {
            s1.x = s0.x + dx[i];
            s1.y = s0.y + dy[i];
            s1.tot = s0.tot + 1;
            s1.t = s0.t - 1;
            if (s1.x >= 0 && s1.x < M && s1.y >= 0 && s1.y <N && a[s1.x][s1.y] != 0 && s1.t > 0) {
                if (a[s1.x][s1.y] == 3) {
                    cout << s1.tot << endl;
                    return;
                }
                if (a[s1.x][s1.y] == 4) {
                    s1.t = 6;
                    a[s1.x][s1.y] = 0; //走过，不可再走，不然没完没了
                }
                s[rear++] = s1;
            }
        }
    }
    cout << "-1" << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> M >> N;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++) {
                cin >> a[i][j];
                if (a[i][j] == 2) {
                    start.x = i;
                    start.y = j;
                    start.tot = 0;
                    start.t = 6;
                }
            }
        bfs();
    }
    return 0;
}
