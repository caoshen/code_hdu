/** 1263
**/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct F {
	char fr[20], pr[20];
	int m;
};

F a[105];

int cmp (F f1, F f2) {
	if (strcmp(f1.pr, f2.pr) != 0)
		return strcmp(f1.pr, f2.pr) < 0;
	else if (strcmp(f1.fr, f2.fr) != 0)
		return strcmp(f1.fr, f2.fr) < 0;
	else
		return f1.m > f2.m;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%s%s%d", a[i].fr, a[i].pr, &a[i].m);
		sort(a, a + n, cmp);
		F cur = {"", "", 0};
		for (int i = 0; i < n; ++i) {
			// 比较是不是同一产地， 设置当前值 
			if (strcmp(cur.pr, a[i].pr)) {
				printf("%s\n", a[i].pr);
				cur = a[i];
			}
			// 比较下一个交易是不是同一种产地同一种水果 
			if (!strcmp(cur.pr, a[i + 1].pr) && !strcmp(cur.fr, a[i + 1].fr)) {
				cur.m += a[i + 1].m;
			}
			// 如果不是，就可以打印交易，并重新设置水果类型 和 购买数量 
			else {
				printf("   |----%s(%d)\n", cur.fr, cur.m);
				strcpy(cur.fr, a[i + 1].fr);
				cur.m = a[i + 1].m;
			}
		}
		if (t)
			printf("\n");
	}
	return 0;
}
