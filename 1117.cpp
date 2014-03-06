#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		int s = ceil(n / 4.0);
		cout << "Printing order for " << n << " pages:" << endl;
		for (int i = 1, j = 1; i <= s; i++) {
			for (int k = 1; k <= 2; k++, j++) {
				if (j > n)
					break;
				cout << "Sheet " << i;
				k % 2 ? cout << ", front: " : cout << ", back : ";
				if (j + n <= 4 * s) {
					if (j % 2)
						cout << "Blank, " << j << endl;
					else
						cout << j << ", Blank" << endl;
				}
				else {
					if (j % 2)
						cout << 4 * s - j + 1 << ", " << j << endl;
					else
						cout << j << ", " << 4 * s - j + 1 << endl;
				}
			}
		}
	}
	return 0;
}
