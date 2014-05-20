/** 1262
prime
**/
#include <iostream>
#include <cstdio>
using namespace std;
const int maxN = 10005;
int a[maxN], cnt = 0;

void prim() {
	
	for (int i = 2; i < maxN; ++i) {
		int flag = 1;
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag)
			a[cnt++] = i;
	}
}

int main() {
	int t;
	prim();
	while (scanf("%d", &t) != EOF) {
		int x = maxN, ii = 0, ij = 0;
		for (int i = 0; i < cnt; ++i)
			for (int j = i; j < cnt; ++j) {
				if (a[i] + a[j] == t) {
					if (a[j] - a[i] < x) {
						x = a[j] - a[i];
						ii = i;
						ij = j;
					}
				}
			}
		printf("%d %d\n", a[ii], a[ij]);
	}
	return 0;
}
