/** 1232
**/
#include <iostream>
#include <cstdio>
using namespace std;
const int maxN = 1000 + 5;
int p[maxN];

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

void uni(int x, int y) {
	int u, v;
	u = find(x);
	v = find(y);
	if (u != v)
		p[u] = v;
}

int main() {
	int n;
	while (~scanf("%d", &n), n) {
		int e;
		scanf("%d", &e);
		for (int i = 1; i <= n; ++i)
			p[i] = i;
		int u, v;
		for (int i = 1; i <= e; ++i) {
			scanf("%d %d", &u, &v);
			uni(u, v);
		}
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
			if (p[i] == i)
				++cnt;
		printf("%d\n", cnt - 1);
	}
	return 0;
}
