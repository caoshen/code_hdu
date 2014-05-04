/** 1216
lucky number
**/
#include <iostream>
#include <cstdio>
using namespace std;
const int maxN = 3000 + 1;
// 2 << 16 - 1 µÈÓÚ 2 << 15 
int a[2 << 16 - 1] = {1,1}, b[maxN];

void find() {
	for (int i = 0; i < maxN;) {
		int k;
		for (k = b[i] + 1; a[k] == 1; ++k);
		b[++i] = k;
		for (int cnt = k, j = cnt + 1; j < 2 << 16 - 1; ++j)
			if (!a[j] && !(--cnt)) {
				a[j] = 1;
				cnt = k;
			}
	}
}

int main() {
	int n;
	find();
	while (~scanf("%d", &n), n) {
		printf("%d\n", b[n]);
	}
	return 0;
}
