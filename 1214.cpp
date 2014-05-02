/** 1214
ÕÒ¹æÂÉ
n = 2k: a[n] = sum(1..k-1) * 2 = k(k-1)
n = 2k - 1: a[n] = sum(1..k-1) + sum(1..k - 2) = (k-1)^2  
**/
#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n % 2)
			cout << (n / 2) * (n / 2) << endl;
		else
			cout << (n / 2) * (n / 2 - 1) << endl;
	}
	return 0;
} 
