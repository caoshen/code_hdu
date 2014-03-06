/**1196**/
#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		int t = n, ans = 1;
		while (t % 2 == 0) {
			ans *= 2;
			t /= 2;
		}
		cout << ans << endl;
	}
	return 0;
}
