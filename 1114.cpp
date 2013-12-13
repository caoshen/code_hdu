/** 1114
DP:
f(n) = min { f(n - v) + val(v), f(n)}
**/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Coin {
	int val, wei;
} a[510];

int amount[10010];
		
int main() {
	int T, E, F, N, P, W;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &E, &F);
		int tot = F - E;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &P, &W);
			a[i].val = P;
			a[i].wei = W;
		}
		amount[0] = 0;
		for (int i = 1; i <= tot; i++)
			amount[i] = 10000000;
		for (int i = 0; i < N; i++) {
			for (int j = a[i].wei; j <= tot; j++) {
				amount[j] = amount[j] > amount[j - a[i].wei] + a[i].val ?  amount[j - a[i].wei] + a[i].val : amount[j];
			}
		}
		if (amount[tot] == 10000000)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", amount[tot]);
	}
	return 0;
}
