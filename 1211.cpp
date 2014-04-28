/**1211
rsa
**/


#include <iostream>
#include <cstdio>

#include <cmath>
using namespace std;

const int maxN = 2 << 10 - 1;
int a[maxN];

int pow(int a, int b, int n) {
	int ans = 1;
	while (b--) {
		ans = (ans * a) % n;
	}
	return ans;
}

int main() {
	int p, q, e, l;
	while (cin >> p >> q >> e >> l) {
		int fn = (p - 1) * (q - 1), n = p * q;
		int d;
		for (d = 1; (d * e) % fn != 1; ++d);
		for (int i = 0; i < l; ++i) {
			scanf("%d", &a[i]);
			printf("%c", (char)(pow(a[i], d, n)));
		}
		printf("\n");
	}
	return 0;
}

