/** 1249
a[n] = a[n - 1] + 6 * (n - 1);
= a[1] + 6 * n * (n - 1) / 2
= 2 + 3 * n * (n - 1)
**/
#include <iostream>
#include <cstdio>
using namespace std; 

int main () {
	int t;
	scanf ("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", 2 + 3 * n * (n - 1));
	}
	return 0;
}
