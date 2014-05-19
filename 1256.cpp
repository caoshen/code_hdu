/** 1256
draw 8
**/

#include <iostream>
#include <cstdio>
using namespace std;

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		char c;
		int n;
		//scanf("%c %d", &c, &n);
		cin >> c >> n;
		int hh, lh;
		if ((n-3) % 2) {
			hh = (n - 4) / 2;
			lh = (n - 2) / 2;
		}
		else {
			hh = lh = (n - 3) / 2;
		}
		int w = n / 6 + 1;
		for (int i = 0; i < w; ++i)
			printf(" ");
		for (int i = 0; i < lh; ++i)
			printf("%c", c);
		printf("\n");
		for (int i = 0; i < hh; ++i) {
			for (int j = 0; j <w; ++j)
				printf("%c", c);
			for (int i = 0; i < lh; ++i)
				printf(" ");
			for (int j = 0; j <w; ++j)
				printf("%c", c);
			printf("\n");	
		}
		for (int i = 0; i < w; ++i)
			printf(" ");
		for (int i = 0; i < lh; ++i)
			printf("%c", c);
		printf("\n");
		for (int i = 0; i < lh; ++i) {
			for (int j = 0; j <w; ++j)
				printf("%c", c);
			for (int i = 0; i < lh; ++i)
				printf(" ");
			for (int j = 0; j <w; ++j)
				printf("%c", c);
			printf("\n");	
		}
		for (int i = 0; i < w; ++i)
			printf(" ");
		for (int i = 0; i < lh; ++i)
			printf("%c", c);
		printf("\n");
		if (t)
			printf("\n");
	}
	return 0;
}
