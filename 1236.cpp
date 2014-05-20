/** 1236
**/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN = 1000;

struct St{
	int sc;
	char id[25];
};

St a[maxN];
int b[11];

int cmp (St x, St y) {
	if (x.sc != y.sc)
		return x.sc > y.sc;
	else
		return strcmp(x.id, y.id) > 0 ? 0 : 1;
}

int main () {
	int n, m, g;
	while (scanf("%d", &n) != EOF, n) {
		scanf("%d %d", &m, &g);
		for (int i = 1; i <= m; ++i)
			scanf("%d", &b[i]);
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			int k, sum = 0;
			char str[25];
			scanf("%s %d", str, &k);
			for (int j = 1; j <= k; ++j) {
				int si;
				scanf("%d", &si);
				sum += b[si];
			}
			if (sum >= g) {
				a[++cnt].sc = sum;
				strcpy(a[cnt].id, str);
			}
			else
				continue;
		}
		sort(a + 1, a + 1 + cnt, cmp);
		printf("%d\n", cnt);
		for (int i = 1; i <= cnt; ++i) {
			printf("%s %d\n", a[i].id, a[i].sc);				
		}
	}
	return 0;
}
