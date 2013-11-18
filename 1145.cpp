/* #1145
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
double a[50];

double calc(double t, double a, double b, double c) {
	double i = (4 * a * c - b * b) / (4 * a);
	double j = a + b + c;
	double k = a* t * t + b * t + c;
	return - b / (2 * a) > 1 || - b / ( 2 * a) < t ? max(j, k) : i;
}

int main()
{
	int n;
	double t;
	while (cin >> n >> t, n != 0 || t != 0) {
		a[0] = 1;
		for (int i = 1; i <= n; i++) {
			a[i] = calc(t, - a[i - 1] / (1 - t), 1 / (1 - t), (a[i - 1] - t) / (1 - t));
		}
		printf("%.3f\n", a[n]);
	}
	return 0;
}
