/** 1173
**/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 10;
double x[MAXN], y[MAXN];
int main() {
	 int n;
	 while (scanf("%d", &n)) {
	 	if (!n)
	 		break;
	 	for (int i = 0; i < n; i++) {
	 		scanf("%lf%lf", &x[i], &y[i]);
	 	}
	 	sort(x, x + n);
	 	sort(y, y + n);
	 	printf("%.2f %.2f\n", x[n / 2], y[n / 2]);
	 }
	 return 0;
}
