/** 1258
**/
#include <iostream>
#include <cstdio>
using namespace std;
int a[20], b[20], c, n, m, flag;

void dfs(int k, int sum) {
	if (sum > n)
		return ;
	if (sum == n) {
		for (int i = 0; i < c - 1; ++i)
			printf("%d+", b[i]);
		printf("%d\n", b[c - 1]);
		flag = 1;
		return;
	}
	int last = -1;
	for (int i = k + 1; i <= m; ++i) {
		if (a[i] != last) {
			b[c++] = a[i];
			dfs(i, sum + a[i]);
			--c;
			last = a[i];
		}
	}
}

int main () {
	while (scanf("%d %d", &n, &m)!= EOF, n, m) {
		for (int i = 1; i <= m; ++i)
			scanf("%d", &a[i]);
		printf("Sums of %d:\n", n);
		flag = 0;
		dfs(0, 0);
		if (!flag)
			printf("NONE\n");
	}
	return 0;
}


