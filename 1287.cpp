/** 1287
**/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[10005];
char b[10005];

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		int k;
		for (int i = 'A'; i <= 'Z'; ++i) {
			int j;
			for (j = 0; j < n; ++j) {
				b[j] = a[j] ^ i;
				if (b[j] < 'A' || b[j] > 'Z') {
					break;
				}
			}
			if (j == n)
				break;			
		}
		printf("%s\n", b);
		memset(b, 0, sizeof(b));
	}
	return 0;
}
