/** 1282
**/
#include <iostream>
#include <cstdio>
using namespace std;

int rev(int a) {
	int sum = 0;
	while (a > 0) {
		sum = sum * 10 + a % 10;
		a /= 10;
	}
	return sum;
}


int main () {
	int n, a[100];
	while (scanf("%d", &n) != EOF) {
		int t = rev(n), m = 0;
		a[0] = n;
		while (t != n) {
			n += t;
			a[++m] = n;
			t = rev(n);
		}
		printf("%d\n", m);
		for (int i = 0; i < m; ++i)
			printf("%d--->", a[i]);
		printf("%d\n", a[m]);
	}
	return 0;
}
