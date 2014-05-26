/** 1274
**/
#include <iostream>
#include <cstdio>
using namespace std;
char c[305];

int isnum (char c) {
	return '0' <= c && c <= '9';
}

int doit(int pos) {
	int i;
	for (i = pos; c[i] != ')' && i < strlen(c); ++i) {
		int sum = 0, p = -1;
		for (;isnum(c[i]); ++i)
			sum = sum * 10 + c[i] - '0';
		if (!sum)
			sum = 1;
		while (sum--) {
			if (c[i] == '(')
				p = doit(i + 1);
			else
				printf("%c", c[i]);
		}
		if (p != -1)
			i = p;
	}
	return i;
}

int main () {
	int t;
	scanf("%d\n", &t);
	while (t--) {
		gets(c);
		doit(0);
		printf("\n");
	}
	return 0;
}
