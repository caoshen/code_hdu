/** 1222
**/
#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int m, int n) {
	return  (m % n == 0) ? n : gcd(n, m % n);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int m, n;
		scanf("%d%d", &m, &n);
		if (gcd(m, n) > 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
