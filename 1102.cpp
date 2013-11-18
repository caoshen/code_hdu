/* #1102
kruskal 求最小生成树 
(the distance should be an integer within [1, 1000]
每两点之间都有路径 
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100;
struct e {
	int x, y, w;
	
} r[MAXN * MAXN];
 
int p[MAXN];

int cmp(e e1, e e2) {
	return e1.w < e2.w;
}

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]); 
}

int main() {
	int N, Q;
	while (cin >> N) {
		for (int i = 0; i < N ; i++)
			for (int j = 0; j < N; j++) {
				r[i * N + j].x = i;
				r[i * N + j].y = j;
				cin >> r[i * N + j].w;
	 		}
		cin >> Q;
		for (int i = 0; i < N; i++)
			p[i] = i;
		sort(r, r + N * N, cmp);
		int a, b, x, y;
		for (int i = 0; i < Q; i++) {
			cin >> a >> b;
			// ！ 数组下标从0开始 
			x = find(a - 1);
			y = find(b - 1);
			if (x != y)
				p[x] = y;
		}
		int ans = 0;
		for (int i = 0; i < N * N; i++) {
			int x = find(r[i].x);
			int y = find(r[i].y);
			if (x != y) {
				p[x] = y;
				ans += r[i].w;
			}
		}
		cout << ans << endl;
	}
	return 0;
} 
