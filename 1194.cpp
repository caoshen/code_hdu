/* 1194
*/
#include <iostream>
using namespace std;

int main() {
	int x, y, a, b, n;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		x = (a + b) / 2;
		y = (a - b) / 2;
		if ( x >= 0 && y >= 0 && x + y == a && x - y == b)
			cout << x << " " << y << endl;
		else
			cout << "impossible" << endl;
	}
	return 0;
}
