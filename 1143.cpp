/** 1143
f(n) = 4 * f(n - 2) - f(n - 4)
**/
#include <iostream>
using namespace std;

int a[35];

int main() {
	a[0] = 1;
	a[2] = 3;
	for (int i = 4; i <= 30; i++) {
		a[i] = 4 * a[i - 2] - a[i - 4];
	}
	int n;
	while (cin >> n, n != -1) {
		cout << a[n] << endl;
	}
}
