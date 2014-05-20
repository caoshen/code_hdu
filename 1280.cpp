/** 1280
**/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[3005], b[4500005];

int cmp(int a, int b) {
	return a > b;
}
int main () {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		int len = 0;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				b[len++] = a[i] + a[j];
		sort (b, b + len, cmp);
		for (int i = 0; i < m; ++i)
			if (i != m - 1)
				printf("%d ", b[i]);
			else
				printf("%d", b[i]);
		printf("\n");	
	}
	return 0;
} 
