/** 1128
self number cannot be generated
**/

#include <iostream>
using namespace std;

int a[1000000 + 10];
int main() {
	for (int i = 1; i <= 1000000; i++) {
		int j = i, sum = j;
		while (j) {
			sum += j % 10;
			j /= 10;
		}
		a[sum] = 1;
		if (!a[i])
			cout << i << endl;
	}
	return 0;
}
