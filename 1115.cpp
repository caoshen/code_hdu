/** 1115
重心
**/
#include <iostream>
#include <cstdio>
using namespace std;

struct Point {
	int x, y;
};

Point a[1000000 + 10];

int croProd(Point a, Point b, Point c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &a[i].x, &a[i].y);
		}
		double sumM, sumX, sumY;
		sumM = sumX = sumY = 0;
		for (int i = 1; i < n - 1; ++i) {
			double xt, yt,mt;
			mt = croProd(a[0], a[i], a[i + 1]);
			xt = (a[0].x + a[i].x + a[i + 1].x);
			yt = (a[0].y + a[i].y + a[i + 1].y);
			sumX += xt * mt;
			sumY += yt * mt;
			sumM += mt;
		}
		// 只需要在最后/3, 不必在循环中/3 
		printf("%.2lf %.2lf\n", sumX / (3 * sumM), sumY / (3 * sumM));
	}
	return 0;
}
