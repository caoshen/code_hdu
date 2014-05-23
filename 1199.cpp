/** 1299
**/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct S {
	int b, e;
};
S a[8005];

int cmp (S s1, S s2) {
	if (s1.b != s2.b)
		return s1.b < s2.b;
	else
		return s1.e > s2.e;
}

int main() {
	int t;
	while (scanf("%d", &t) != EOF) {
		int left, right, num = 0;
		char c;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= t; ++i) {
			scanf("%d %d %c", &left, &right, &c);
			if (c == 'w') {
				a[++num].b = left;
				a[num].e = right;
			}
			else {
				for (int j = 1; j <= num; ++j) {
					if (a[j].b >= left && a[j].e <= right) {
						a[j].b = a[j].e = -1;
					}
					else if (a[j].b < left && a[j].e > right) {
						a[++num].b = right + 1;
						a[num].e = a[j].e;
						a[j].e = left - 1;						
					}
					else if (left <= a[j].b && a[j].b <= right && right < a[j].e) {
						a[j].b = right  + 1;
					}
					else if (a[j].b < left && a[j].e >= left && a[j].e <= right) {
						a[j].e = left - 1;
					}
					else
						continue;
				}
			}
		}
		sort(a + 1, a + 1 + num, cmp);
		// x,y记录一段白色的左右边界 
		int ma, x, y, ib, ie;
		ma = ib = ie = x = y = -1;
		for (int i = 1; i <= num; ++i)
			if (a[i].b != -1) {
				if (a[i].b <= y + 1)
				 	y = max(y, a[i].e);
				else {
					x = a[i].b;
					y = a[i].e;
				}
				if (ma < y - x + 1) {
					ma = y - x + 1;
					ib = x;
					ie = y;
				}
			}
		if (ma == -1)
			printf("Oh, my god\n");
		else
			printf("%d %d\n", ib, ie);
	}
		return 0;
}
