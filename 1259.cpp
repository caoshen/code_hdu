/** 1259
**/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[8] = "ZJUTACM";

void swap(int x, int y) {
	char c = a[x];
	a[x] = a[y];
	a[y] = c;
}

int main () {
	int n, m;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			swap(x - 1, y - 1);
		}
		for (int i = 0; i < 7; ++i)
			if (a[i] == 'J')
				printf("%d\n", i + 1);
		strcpy(a, "ZJUTACM");
	}
	return 0;
}
