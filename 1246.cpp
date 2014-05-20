/** 1246
**/

#include <iostream>
using namespace std;
int a[305] = {1, 1};

int main() {
	int n;
	for (int i = 3; i < 305; i += 2)
		for (int j = 305 - i;  j >= 0; --j)
			a[i + j] += a[j];
	while (cin >> n) {
		cout << a[n] << endl;
	}
	return 0;
}
