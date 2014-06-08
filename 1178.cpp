/** 1178
**/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		double x = log10(n / 6.0) + log10(n + 1.0) + log10(n + 2.0);
		int e = int(x);
		printf("%.2lfE%d\n", pow(10, x - e), e);
	}
	return 0;
} 
