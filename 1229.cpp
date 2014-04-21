/**1229**/

#include <iostream>
using namespace std;

int main() {
	int a, b, k;
	while (cin >> a >> b >> k) {
		if (a == 0 && b == 0)
			break;
		int c = a, d = b, f = 0;
		while (k--) {
			if (c % 10 != d % 10) {
				f = 1;
				break;
			}
			c /= 10;
			d /= 10;
		}
		if (f)
			cout << a + b << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}
