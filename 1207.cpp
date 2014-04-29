/** 1207
FrameÀ„∑®£∫
f[n] = min(2 * f[n - r] + 2 ^ r - 1); // r = 1..n-1

**/

#include <iostream>
#include <cmath>
#include <cstdio> 
using namespace std;

int main() {
	int n, f[65] = {0, 1, 3}, min;
	for (int i = 3; i <= 64; ++i) {
		min = 2 << 30 -1;
		for (int r = 1; r < i; ++r) {
			if (2 * f[r] + pow(2.0, i - r) - 1 < min)
				min = 2 * f[r] + pow(2.0, i - r) - 1;
		}
		f[i] = min;
	}
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", f[n]);
	}
	return 0;
}
