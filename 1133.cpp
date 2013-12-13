/** 1133
(m + n)! * (m + 1 - n) / (m + 1) 
**/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[10000];

void calc (int m, int n) {
	memset(a, 0, sizeof(a));
	if (m < n) {
		printf("0\n");
		return ;
	}
	int c, tmp, len = 1;
	a[0] = 1;
	for (int i = 1; i <= m + n; i++) {
		c = 0;
		// if n == 0 , this step will not execute.
		if (i == m + 1)
			continue;
		for (int j = 0; j < len; j++) {
			tmp = a[j] * i + c;
			a[j] = tmp % 10;
			c = tmp / 10;
			if (c && len <= j + 1)
				len++;
		}
	}
	// if n == 0, the result is m! 
	if(n) {
		// c will be 0 here.
		for (int i = 0; i < len; i++) {
			tmp = a[i] * (m + 1 - n) + c;
			a[i] = tmp % 10;
			c = tmp / 10;
			if (c && len <= i + 1)
				len++;
		}
	}
	for (int i = len - 1; i >= 0; i--) {
		printf("%d", a[i]);
	}
	printf("\n");
}

int main() {
	int m, n, t = 0;
	while (scanf("%d%d", &m, &n)){
		if (m == 0 && n == 0)
			break;
		printf("Test #%d:\n", ++t);
		calc(m , n);
	}
	return 0;
}
