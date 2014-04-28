/** 1202
**/
#include <iostream>
#include <cstdio>
using namespace std;
double a[100], b[100];

int main() {
	int t;
	while (scanf("%d", &t) != EOF) {
		double sab = 0, sa = 0, g = 0;
		for (int i = 0; i < t; ++i) {
			scanf("%lf %lf", &a[i], &b[i]);
			if (b[i] == -1)
				continue;
			else {
				int p = (int) (b[i] / 10), pa = 0;
				switch (p) {
					case 10:
					case 9:
						pa = 4;
						break;
					case 8:
						pa = 3;
						break;
					case 7:
						pa = 2;
						break;
					case 6:
						pa = 1;
						break;
					default:
						pa = 0;
				}
				sab += a[i] * pa;
				sa += a[i];
			}
		}
		if (sa)
			printf("%.2lf\n", sab / sa);
		else
			printf("-1\n");
	}
	return 0;
} 
