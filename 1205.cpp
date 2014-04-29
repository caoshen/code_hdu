/** 1205
**/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int  a[1000005];

int cmp(int a, int b) {
	return a > b;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		sort(a, a + n, cmp);
		int cnt = a[0] - 1;
		for (int i = 1; i < n && cnt > 0; ++i)
			cnt -= a[i];
		if (cnt > 0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
