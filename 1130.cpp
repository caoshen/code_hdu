/* #1130
递推 
n == 100, trees很大 
*/
#include <iostream>
using namespace std;

int a[105][100]; // catalan
int b[105]; // len 

void catalan() {
	int i, j, carry, len = 1, temp;
	a[1][0] = b[1] = 1;
	
	for (i = 2; i <= 100; i++) {
		carry = 0;
		// 乘法
		for (j = 0; j < len; j++) {
			a[i][j] = a[i - 1][j] * (4 * i - 2);
		}
		for (j = 0; j < len; j++) {
			temp = a[i][j] + carry;
			a[i][j] = temp % 10;
			carry = temp / 10;
		}
		while (carry) {
			a[i][len++] = carry % 10;
			carry /= 10;
		}
		// 除法
		for (j = len - 1; j >=0; j--) {
			temp = a[i][j] + carry * 10;
			a[i][j] = temp / (i + 1);
			carry = temp % (i + 1); 
		}
		while (!a[i][--len]);
		b[i] = ++len;
	} 
}

int main() {
	int n;
	catalan();
	while (cin >> n) {
		for (int i = b[n] - 1; i >=0; i--)
			cout << a[n][i];
		cout << endl;
	}
}
