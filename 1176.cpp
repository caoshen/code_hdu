/** 1176
dp
**/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// a[i][j]表示在地点j从时间i开始可以获得的最大收益 
int a[100005][15];

int max(int a, int b, int c) {
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int main() {
	int t;
	while (scanf("%d", &t) != EOF, t) {
		memset(a, 0, sizeof(a));
		int n, x, mx = 0; 
		for (int i = 0; i < t; ++i)	{
			scanf("%d %d", &n, &x);
			++a[x][n + 1];
			mx = x > mx ? x : mx;
		}
		for (int i = mx; i >= 0; --i) {
			for (int j = 1; j <= 11; ++j) {
				a[i][j] += max(a[i + 1][j - 1], a[i + 1][j], a[i + 1][j + 1]);
			}
		}
		printf("%d\n", a[0][6]);
	}
	return 0;
}
