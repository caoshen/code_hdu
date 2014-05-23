/** 1174
**/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int t;
	double h1,r1,x1,y1,z1,h2,r2,x2,y2,z2,x3,y3,z3;
	scanf("%d", &t);
	while (t--) {
		scanf("%lf%lf%lf%lf%lf", &h1, &r1, &x1, &y1, &z1);
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &h2, &r2, &x2, &y2, &z2, &x3, &y3, &z3);
		double dx, dy, dz, h;
		dx = x2 - x1;
		dy = y2 - y1;
		dz = 0.9 * h2 - r2 + z2 - (h1 - r1 + z1);
		h = (pow(dy * z3 - dz * y3, 2) + pow(dx * z3 - x3 * dz, 2) + pow(dx * y3 - x3 * dy, 2)) / (pow(x3, 2) + pow(y3, 2) + pow(z3, 2));
		// 注意还要判断土匪是不是在警察面前 
		if (h <= r1 * r1 && (dx * x3 + dy * y3 + dz * z3) < 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
