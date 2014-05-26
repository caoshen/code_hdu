/** 1279
**/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int cnt = 0;
		while (n > 1) {
			if (n % 2) {
				if (!cnt)
					printf("%d", n);
				else
					printf(" %d", n);
				n = 3 * n + 1;
				++cnt;
			}
			else {
				n /= 2;
			}
		}
		if (!cnt)
			printf("No number can be output !\n");
		else
			printf("\n");
	}
	return 0;
}
