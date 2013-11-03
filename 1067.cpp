/* #1068

bfs + hash

http://blog.csdn.net/u010709592/article/details/9282969 
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = 4;
const int N = 8;
const int MOD = 1000007;
long long tar;
long long base[33] = {1};

struct S {
	int map[M][N];
	long long step;
	int sx[5], sy[5];
} q[100000];

long long ha[MOD];
int flag;

long long hash(int t[][N]) {
	long long h = 0;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			h += t[i][j] * base[i * N + j] ;
	if (h == tar)
		flag = 1;
	return h;
}

int insert(long long v) {
	long long p = v % MOD; 
	while (ha[p] != -1 && ha[p] != v) {
		p = (p + 10) % MOD;
	}
	if (ha[p] == -1) {
		ha[p] = v;
		return 1;
	}
	return 0;
}

int work (int t[][N]) {
	long long st = hash(t);
	return insert(st);
}
int aim[M][N] = {
	11, 12, 13, 14, 15, 16, 17, 0,
	21, 22, 23, 24, 25, 26, 27, 0,
	31, 32, 33, 34, 35, 36, 37, 0,
	41, 42, 43, 44, 45, 46, 47, 0};

 void bfs() {
 	S s0, s1;
 	int front = 0, rear = 1;
	while (front < rear) {
		s0 = q[front++];
		for (int i = 1; i <= 4; i++ ) {
			s1 = s0;
			int x = s1.sx[i];
			int y = s1.sy[i];
			for (int a = 0; a < M; a++)
				for (int b = 0; b < N; b++) {
					if (s1.map[a][b] == 0)
						continue;
					if (s1.map[a][b] != s1.map[x][y - 1] + 1)
						continue;
					swap(s1.map[a][b], s1.map[x][y]);
					if (work(s1.map)) {// Хажи
						s1.step = s0.step + 1;
						s1.sx[i] = a;
						s1.sy[i] = b;
						q[rear++] = s1;
						if (flag) {
							cout << s1.step << endl; 
							return;
						}
					}
				}
		}		
	}
	cout << "-1" << endl; 	
 }
 
int main() {
	for (int i = 1; i < 33;  i++)
		base[i] = base[i - 1] * 2;
		
	int T;
	S si;
	tar = 98430874871LL;
	cin >> T;
	while (T--) {
		memset(q, 0, sizeof(q));
		memset(ha, -1, sizeof(ha));
		flag = 0;
		int k = 0;
		si.map[0][0] = si.map[1][0]
			= si.map[2][0] = si.map[3][0] = 0;
		for (int i = 0; i < M; i++)
			for(int j = 1; j < N; j++) {
				cin >> si.map[i][j];
				if(si.map[i][j] == 11) {
					si.sx[++k] = i;
					si.sy[k] = j;
					swap(si.map[i][j], si.map[0][0]);				
				}
				if(si.map[i][j] == 21) {
					si.sx[++k] = i;
					si.sy[k] = j;
					swap(si.map[i][j], si.map[1][0]);				
				}
				if(si.map[i][j] == 31) {
					si.sx[++k] = i;
					si.sy[k] = j;
					swap(si.map[i][j], si.map[2][0]);				
				}
				if(si.map[i][j] == 41) {
					si.sx[++k] = i;
					si.sy[k] = j;
					swap(si.map[i][j], si.map[3][0]);				
				}
			}
			si.step = 0;
			work(si.map);
			q[0] = si;
			if (flag)
				cout << "0" << endl;
			else
				bfs();
	}	
}
