/** 1248
**/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, min = 1 << 20;
		scanf("%d", &n);
		for (int i = 0; i <= n / 150; ++i)
			for (int j = 0; j <= (n - 150 * i) / 200; ++j)
				for (int k = 0; k <= (n - 150 * i - 200 * j)/ 350; ++k) {
					int tip = n - (150 * i + 200 * j + 350 * k );
					if (tip <= min)
						min = tip;
				}
		printf("%d\n", min);
	}
	return 0;
}
