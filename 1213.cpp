/** 1213
²¢²é¼¯
**/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxN = 1005;
int p[maxN];

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

void uni(int x, int y) {
	int u = find(x);
	int v = find(y);
	if (u != v)
		p[u] = v;
}

int main() {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
			p[i] = i;
		for (int i = 0; i < m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			uni(a, b);
		}
		int ans = 0, pa = 0;
		for (int i = 1; i <= n; ++i)
			p[i] = find(i);
		sort(p + 1, p + 1 + n);
		for (int i = 1; i <= n; ++i) {
			if (pa != p[i]) {
				pa = p[i];
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
