/** 1220
**/

#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		cout << (n * n * n) * (n * n * n - 1) / 2 - 3 * (n * n) * (n - 1) << endl;
	}
	return 0;
} 
