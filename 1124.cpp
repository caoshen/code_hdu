/** 1124
z(n) = n / 5 + n / 25 + n / 125 + ...
**/
#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, sum = 0;
		cin >> n;
		while (n) {
			n /= 5;
			sum += n;
		}
		cout << sum << endl;
	}
	return 0;
}
