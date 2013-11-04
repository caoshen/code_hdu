/* #1026
bfs + 反向打印

不能直接出入队，要用优先队列，对于耗时长的节点，要作适当的滞后处理（入队后，往后放）
http://blog.csdn.net/huahua520amy/article/details/9396481
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct P {
	int x, y, t;
} q[10000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int M, N;
char m[100][100];
int dir[100][100], vis[100][100]; 
int tot;

int cmp ( P p, P q) {
	return p.t < q.t;
} 
int out (int x, int y) {
	if ( x == 0 && y == 0) {
		int n = 1;
		printf ("%ds:(%d,%d)->", n, x, y);
		return n;
	}
	else {
		int k = dir[x][y];
		int n = out( x - dx[k], y - dy[k]) ;
		printf ("(%d,%d)\n", x, y);
		for ( int i = 1 ; i <= m[x][y] - '0'; i++)
			printf("%ds:FIGHT AT (%d,%d)\n", ++n, x, y);
		if ( x == M - 1 && y == N - 1)
			return 0;
		else {
			printf ("%ds:(%d,%d)->", ++n, x, y);
			return n;
		}
	}
}
void bfs() {
	int x1, y1, front = 0, rear = 1;
	P p0, p1;
	while (front < rear) {
		p0 = q[front++];
		if (p0.x == M - 1 && p0.y == N - 1) {
				printf("It takes %d seconds to reach the target position, let me show you the way.\n", p0.t);
				out (p0.x, p0.y);
				return; 
		}
		for (int i = 0; i < 4; i++) {
			x1 = p0.x + dx[i];
			y1 = p0.y + dy[i];
			if ( x1 < 0 || x1 >= M || y1 < 0 || y1 >= N || m[x1][y1] == 'X' || vis[x1][y1])
				continue;
			else if ( m[x1][y1] == '.') 
				p1.t = p0.t + 1;
			else {
						p1.t = p0.t + 1 + m[x1][y1] - '0';
			}
			p1.x = x1;
			p1.y = y1;
			dir[x1][y1] = i;
			q[rear++] = p1;	
			sort(q + front, q + rear, cmp);// ！队列重排序， 用时少的在队列前面。 
			vis[x1][y1] = 1;
			
		}
	}
	cout << "God please help our poor hero." << endl;
}

int main() {
	while (	cin >> M >> N) {
		memset(vis, 0, sizeof(vis));
		memset(dir, -1, sizeof(dir));
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				cin >> m[i][j];
		P p0;
		p0.x = 0;
		p0.y = 0;
		p0.t = 0;
		q[0] = p0;
		vis[0][0] = 1;
		bfs();
		cout << "FINISH" << endl;
	}
}
