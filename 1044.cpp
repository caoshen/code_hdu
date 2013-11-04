/* #1044
bfs 求最短路 + dfs  
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN =  55;
char map[MAXN][MAXN];
int t[MAXN][MAXN];
int vis1[MAXN][MAXN], vis2[MAXN];
int val[30];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int m, n, l, w;
int sum, ans;

struct P {
	int x, y, step;
} q[3000];

void bfs(int x, int y, int s) {
	P p0, p1;
	int front = 0, rear = 0;
	 p0.x = x;
	 p0.y = y;
	 p0.step = 0;
	 q[rear++] = p0;
	 vis1[x][y] = 1;
	 while (front < rear) {
	 	p0 = q[front++];
	 	for (int i = 0; i < 4; i++) {
	 		p1.x = p0.x + dx[i];
	 		p1.y = p0.y + dy[i];
	 		if (p1.x < 0 || p1.x >= m || p1.y < 0 || p1.y >=n
			 	|| map[p1.x][p1.y] == '*' ||	vis1[p1.x][p1.y])
			 	continue;
			p1.step = p0.step + 1;
			vis1[p1.x][p1.y] = 1;
			if (map[p1.x][p1.y] == '@') {
				t[s][0] = p1.step;
			}
			if (map[p1.x][p1.y] == '<') {
				t[s][w + 1] = p1.step;
			}
			if (map[p1.x][p1.y] >= 'A' && map[p1.x][p1.y] <= 'Z' )
				t[s][map[p1.x][p1.y] - 'A' + 1] = p1.step;
			q[rear++] = p1;
	 	}
	 }
}

// x : 当前找到的东西， 开始是 入口 @, 状态0
// y : 价值
// time: 时间
 
void dfs( int x , int y, int time) {
	//到达时间限制 或者 东西已经捡完 
	if ( time > l || ans == sum)
		return;
	// 到达出口 
	if ( x == w + 1) {
		ans = ans < y ? y : ans; 
	}
	// 找东西
	for (int i = 1; i <= w + 1; i++) {
		// 如果第i个东西没有访问过而且图中存在 
		if (!vis2[i] && t[x][i]) {
			vis2[i] = 1;
			dfs(i, y + val[i], time + t[x][i]);
			vis2[i] = 0; 
		}  
	}
}

int main() {
	int T;
	cin >> T;
	int x = 0;
	while (T--) {
		x++;
		ans = -1, sum = 0;
		cin >> m >> n >> l >> w;
		for (int i = 1; i <= w; i++) {
			cin >> val[i];
			sum += val[i];
		}
		val[w + 1] = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		// 初始化访问标志与最短路 
		memset(vis1, 0, sizeof(vis1));
		memset(vis2, 0, sizeof(vis2));
		memset(t, 0, sizeof(t));
		
		// 构造最短路
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) {
				memset(vis1, 0, sizeof(vis1));
				memset(q, 0, sizeof(q));
				if (map[i][j] == '@') {
					bfs(i, j , 0);
				}
				if (map[i][j] == '<') {
					bfs(i, j, w + 1);
				}
				if (map[i][j] >= 'A' && map[i][j] <= 'Z' ) {
					bfs(i, j, map[i][j] - 'A' + 1);
				} 
		}
		vis2[0] = 1;
		dfs (0, 0, 0);
		if  (ans >= 0) 
			printf ("Case #%d:\nThe best score is %d\n", x, ans); 
		else
			printf ("Impossible");
		if (T)
			cout << endl;
	}
	return 0;
}
