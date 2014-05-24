/** 1289
**/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main () {
	float d;
	while (scanf("%f", &d) != EOF) {
		float d0 = 1.0, fra;
		int t = 0;
		if (d == 0) {
			printf("0 0\n");
			continue;
		}
		if (abs(d) >= 1) {
			while (d0 <= abs(d)) {
				d0 *= 2;
				++t;
			}
			d0 /= 2;
			--t;
		}
		else {
			while (d0 > abs(d)) {
				d0 /= 2;
				--t;
			}
		}
		fra = d / d0;
		printf("%d %.6f\n", t, fra);
	}
	return 0;
}
