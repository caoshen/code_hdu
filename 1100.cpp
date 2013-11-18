/* #1100
ตÝน้ 
*/

#include <iostream>
#include <string>
using namespace std;

const int MAXN = 19;
int a[MAXN];
int b[MAXN];

string tree (int n, int index) {
	string s("X");
	int i, j;
	for (i = 0, j = n - 1; i < n; i++, j--) {
		if (index >= a[i] * a[j])
			index -= a[i] * a[j];
		else
			break;
	}
	int l = index / a[j], r = index % a[j];
	if (i) s =  '(' + tree(i, l) + ')' + s;
	if (j) s =   s +  '(' + tree(j, r) + ')';
	return s;
}

int main() {
	b[0] = a[0] = a[1] = 1;
	b[1] = b[0] + a[0];
	for (int i = 2; i < MAXN; i++) {
		a[i] = 0;
		for (int j = 0; j < i; j++) {
			a[i] += a[j] * a[i - j - 1];
			b[i] = b[i - 1] + a[i];
		}
	}
	int n;
	while ( cin >> n, n > 0) {
		int num = 0;
		for (num = 0; num < MAXN; num++) {
			if (b[num] > n)
				break;
		}
		int index = n - b[num - 1];
		cout << tree(num , index) << endl;
	}
}
