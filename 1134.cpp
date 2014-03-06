/**1134
f(n) = (4n - 2) / ( n + 1) f(n - 1)
**/
#include <iostream>
using namespace std;

int a[105][100];

int main() {
	a[0][0] = a[1][0] = 1;
	int i;
	for (i = 2; i <= 100; i++) {
		int c = 0;
		for (int j = 0; j < 100; j++) {
			int tmp = (4 * i - 2) * a[i - 1][j] + c;
			a[i][j] = tmp % 10;
			c = tmp / 10;
		}
		for (int j = 99; j >=0; j--) {
			int tmp = a[i][j] + c * 10;
			a[i][j] = tmp / (i + 1);
			c =  tmp % (i + 1);
		}
	}
	int n;
	while (cin >> n, n != -1) {
		for ( i = 99; i >= 0 && a[n][i] == 0; i--);
		for (int j = i; j >= 0; j--)
			cout << a[n][j];
		cout << endl;
	}
	return 0;
}
