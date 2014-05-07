#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double dis(double x1, double y1, double x2, double y2) {
	return (x1 - x2) *  (x1 - x2) + (y1 - y2) * (y1 - y2); 
}

int inter(double xr, double yr, double r, double x1, double y1, double x2, double y2) {
	double d1, d2, d3, d4, r2;
	d1 = dis(xr, yr, x1, y1);
	d2 = dis(xr, yr, x2, y2);
	d3 = dis(xr, yr, x1, y2);
	d4 = dis(xr, yr, x2, y1);
	r2 = r * r;
	if (d1 < r2 && d2 < r2 && d3 < r2 && d4 < r2)
		return  0;
	else if (d1 > r2 && d2 > r2 && d3 > r2 && d4 > r2) {
		if ( min(x1, x2) <= xr && xr <= max(x1, x2) && (abs(yr - y1 ) <= r || abs(yr - y2) <= r))
			return 1;
		else if (min(y1, y2) <= yr && yr<= max(y1, y2) && (abs(xr - x1) <= r || abs(xr - x2) <= r) )
			return 1;
		else
			return 0;
	}
	else 
		return 1;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		double xr, yr, r, x1, y1, x2, y2; 
		scanf("%lf%lf%lf%lf%lf%lf%lf", &xr, &yr, &r, &x1, &y1, &x2, &y2);
		if (inter(xr, yr, r, x1, y1, x2, y2)) 
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
