/** 1209
**/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Ti {
	double ang;
	int h, m;
};

double angle(int h, int m) {
	double d = abs(m * 6 - ((h % 12) * 30 + m * 0.5));
	if (d >= 180)
		d = 360 -d;
	return d;
}

int cmp (Ti a, Ti b) {
	if (abs(a.ang - b.ang) < 0.0001)
		return a.h * 60 + a.m < b.h * 60 + b.m;
	else
		return a.ang < b.ang;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		Ti a[5];
		for (int i = 0; i < 5; ++i) {
			scanf ("%d:%d", &a[i].h, &a[i].m);
			a[i].ang = angle(a[i].h, a[i].m);
		}
		sort(a, a + 5, cmp);
		printf("%02d:%02d\n", a[2].h, a[2].m);
	}
	return 0;
}
