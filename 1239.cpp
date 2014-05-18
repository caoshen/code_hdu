/** 1239
**/

#include <iostream>
#include <cstdio>
using namespace std;
int p[5000];

void prim() {
	int cnt = 0;
	for (int i = 2; i <= 10000; ++i) {
		int flag = 1;
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag)
			p[cnt++] = i;
	}
}

int main () {
	int m, a, b;
	prim();
	while (scanf("%d %d %d", &m, &a, &b) != EOF) {
		if (!a && !b && !m)
			break;
		int ip = 0, iq = 0, pro = 0;
		for (int i = 0; p[i] * p[i] <= m; ++i) {
			for (int j = i; a * p[j] <= b * p[i]; ++j) {
				int tmp = p[i] * p[j];
				if (tmp > m)
					break;
				if (tmp > pro) {
					pro = tmp;
					ip = i;
					iq = j;
				}
			}
		}
		printf("%d %d\n", p[ip], p[iq]);
	}
	return 0;
}
