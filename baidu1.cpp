/** 1001
**/
#include <iostream>
using namespace std;

int main () {
	long long t, n, m, v, k;
	cin >> t;
	while (t--) {
		cin >> n >> m >> v >> k;
		int cnt = 0, flag = 1;
		while (m < n) {
			if ((m - v) * k <= m) {
				flag = 0;
				break;
			}
			else {
				m = (m - v) * k;
				++cnt;
			}
		}
		if (flag)
			cout << cnt << endl;
		else
			cout << "-1" << endl;
	}
	return 0;
}
