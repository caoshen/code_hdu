/** 1131
f(n) = (2n)! / (n + 1)!
**/
#include <iostream>
#include<cstring>
using namespace std;

const int MAXN = 100 + 10;
int a[300];

int main()
{
	int n , c, i, j;
	while (cin >> n, n != 0) {
		memset(a, 0, sizeof(a));
		a[0] = 1;
		for (i = n + 2; i <= 2 * n; i++) {
			c = 0;
			for (j = 0; j < 300; j++) {
				int tmp = a[j] * i + c;
				a[j] = tmp % 10;
				c = tmp / 10;
			}
		}
		
		for ( i = 300 - 1; a[i] == 0; i--);
		for ( j = i; j >= 0; j--)
			cout << a[j];
		cout << endl;
	}
	return 0;
}
