/** 1293
**/

#include <iostream>
#include <cstdio>
using namespace std;
const int maxN = 1005;
int a[maxN][600];

int main () {
	a[1][0] = 3;
	a[2][0] = 7;
	for (int i = 3; i <= 1000; ++i) {
		int c = 0, t;
		for (int j = 0; j < 600; ++j) {
			t = a[i - 1][j] * 2 + c;
			a[i][j] = t % 10;
			c = t / 10;
		}
		c = 0;
		for (int j = 0; j < 600; ++j) {
			t = a[i - 2][j] + a[i][j] + c;
			a[i][j] = t % 10;
			c = t / 10;
		}
	}
	int n;
	while (scanf("%d", &n) != EOF) {
		int k;
		for (k = 600 - 1; !a[n][k]; --k);
		for (int i = k; i >= 0; --i)
			printf("%d", a[n][i]);
		printf("\n");
	}
	return 0;
}
