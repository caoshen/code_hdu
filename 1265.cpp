/** 1265
**/
#include <iostream>
#include <cstdio>
using namespace std;

int main () {
	int t;
	cin >> t;
	while (t--) {
		float d;
		cin >> d;
		int a[33] = {0, 0};
		int sign = 0, e = 0;
		if (d == 0) {
			cout << "00000000" << endl;
			continue;
		}
		if (d == -0) {
			cout << "80000000" << endl;
			continue;
		}
		if (d < 0) {
			d = -d;
			sign = 1;
			a[1] = 1;
		}
		if (d >= 2) {
			while (d >= 2) {
				d /= 2;
				++e;
			}
		}
		else if (d < 1) {
			while (d < 1) {
				d *= 2;
				--e;
			}
		}
		e += 127;
		for (int i = 9; i >= 2 && e > 0; --i) {
			if (e % 2 == 1)
				a[i] = 1;
			else
				a[i] = 0;
			e /= 2;
		}
		d -= 1;
		for (int i = 10; i <= 32; ++i) {
			d *= 2;
			if (d  >= 1) {
				a[i] = 1;
				d -= 1;
			}
			else
				a[i] = 0;
			if (i == 32 && d > 0)
				a[i] = 1;
		}
		
		for (int i = 1; i <= 32; ++i) {
			int tmp = a[i] * 8 + a[++i] * 4 + a[++i] * 2 + a[++i];
			printf("%X", tmp);
		}
		cout << endl;
	}
	return 0;
}
