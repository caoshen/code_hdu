/** 1297
**/
#include <iostream>
using namespace std;
const int maxN = 1005;
int a[maxN][600];

int main() {
	a[0][0] = a[1][0] = 1;
	a[2][0] = 2;
	a[3][0] = 4;
	a[4][0] = 7;
	for (int i = 5; i <= 1000; ++i) {
		int c = 0;
		for (int j = 0; j < 600; ++j) {
			int t = a[i - 1][j] + a[i - 2][j] + a[i - 4][j] + c;
			a[i][j] = t % 10;
			c = t / 10;
		}
	}
	int n;
	while (cin >> n) {
		int k;
		for (k = 600 - 1; k >= 0 && a[n][k] == 0; --k);
		for (int i = k; i >= 0; --i)
			cout << a[n][i];
		cout << endl;
	}
	return 0;
}
