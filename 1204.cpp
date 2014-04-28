/**1204
**/
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	int n, m;
	double p, q;
	while (~(scanf("%d %d %lf %lf", &n, &m, &p, &q))) {
		double win, lose, draw;
		win = p * (1 - q);
		lose = (1 - p) * q;
		draw = p * q + (1- p) * (1 - q);
		if (n == 0) {
			printf("0.00\n");
			continue;
		}
		if (m == 0) {
			printf("1.00\n");
			continue;
		}
		if ( p == 0 || q == 1) {
			cout << "0.00" << endl;
			continue;
		}
		if ( p == 1 || q == 0) {
			cout << "1.00" << endl;
			continue;
		}
		if (p == q) {
			printf("%.2lf\n", (double)n / (m + n));
			continue;
		}
		else {
			double k = lose / win;
			double ans = (1 - pow(k, n)) / (1 - pow(k, m + n));
			printf("%.2lf\n", ans);
		}
	}
	return 0;
}
