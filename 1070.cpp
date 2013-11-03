/* #1070
如果最便宜的牛奶不止一种，那么选择容量最大的!!
*/
#include <iostream>
using namespace std;

struct M {
	string s;
	int c, v;
	double p;
} a[100];
int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		double min = 10000;
		int id = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i].s >> a[i].c >> a[i].v;
			if (a[i].v >= 1000) {
				a[i].p = (double) a[i].c / 5;
			}
			else if (a[i].v >= 800 && a[i].v < 1000) {
				a[i].p = (double) a[i].c / 4;
			}
			else if (a[i].v >= 600 && a[i].v < 800) {
				a[i].p = (double) a[i].c / 3;
			}
			else if (a[i].v >= 400 && a[i].v < 600) {
				a[i].p = (double) a[i].c / 2;
			}
			else if (a[i].v >= 200 && a[i].v < 400) {
				a[i].p = (double) a[i].c;
			}
			else {
				a[i].p = -1;
			}
			if (a[i].p > 0 && (min == a[i].p && a[id].v < a[i].v || min > a[i].p)) {
				min = a[i].p;
				id = i;
			}
		}
		cout << a[id].s << endl;
		
	}
	return 0;
}
