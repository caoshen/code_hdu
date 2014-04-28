/** 1210**/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int k = 0;
		for (int i = 1; i <= 2 * n && i != n + 1; ++k) {
			if (i <= n)
				i *= 2;
			else
				i = (i - n) * 2 - 1;
		}
		if (k)
			++k;	
		printf("%d\n", k);
	}
	return 0;
}

