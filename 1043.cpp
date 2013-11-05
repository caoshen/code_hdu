/* #1043
bfs + 打表
*/

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 362880 +500;
struct Node {
	int s[9], loc, status;
	string path;
} q[MAXN];

int fac[10];
string index = "lrud";
string path[MAXN];
int vis[MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void init() {
	fac[0] = 1; 
	for (int i = 1; i < 10; i++) {
		fac[i] = fac[i - 1] * i;
	}
	memset(vis, 0, sizeof(vis));
}

int cantor(int s[]) {
	int sum = 0;
	for (int i = 0; i< 9; i++) {
		int n =0;
		for (int j = i + 1; j < 9; j++) {
			if (s[i] > s[j])
				n++;
		}
		sum += n * fac[8 - i];
	}
	return sum + 1;
}

void bfs() {
	Node n0, n1;
	int aim = 0, front = 0, rear = 0;
	n0.s[8] = 0;
	for (int i = 0; i < 8; i++)
		n0.s[i] = i + 1;
	n0.loc = 8;
	for (int i = 0; i < 9; i++)
		aim += fac[i];
	n0.status = aim;
	n0.path = "";
	vis[aim] = 1;
	path[aim] = "";
	q[rear++] = n0;
	while (front < rear) {
		n0 = q[front++];
		int x  = n0.loc /3 , y = n0.loc % 3; // 0的位置
		for (int i = 0; i < 4; i++){
			int x1, y1;
			x1 = x + dx[i];
			y1 = y + dy[i];
			if (x1 < 0 || x1 > 2 || y1 < 0 || y1 > 2 )
				continue;
			n1 = n0;
			n1.loc = x1 * 3 + y1;
			// 顺序不能颠倒 
			n1.s[n0.loc] = n1.s[n1.loc];
			n1.s[n1.loc] = 0;
			n1.status = cantor(n1.s);
			if (!vis[n1.status]) {
				vis[n1.status] = 1;
				n1.path = index[i] + n0.path;
				path[n1.status] = n1.path;
				q[rear++] = n1;
			}
		} 
	}	
}

int main() {
	init();
	bfs();
	Node cur;
	char c;
	while (cin >> c) {
		if (c == 'x') {
			cur.loc = 0;
			cur.s[0] = 0;
		}
		else {
				cur.s[0] = c - '0';
		}
		for (int i = 1; i < 9; i++) {
			cin >> c;
			if (c == 'x') {
				cur.loc = i;
				cur.s[i] = 0;
			}
			
			else {
				cur.s[i] = c - '0';
			}
		}
		cur.status = cantor(cur.s);
		if(vis[cur.status]) {
			cout << path[cur.status] << endl;
		}
		else {
			cout << "unsolvable" << endl;
		}
	}
}

