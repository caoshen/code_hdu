/**1155
动能 重力势能 弹性势能
**/ 
#include <iostream>
using namespace std;

int main() {
	double k, l, s, w;
	while (cin >> k >> l >> s >> w) {
		if (k + l + s + w == 0)
			break;
		double e1, e2 , e3;
		e1 = w * 10 * 10 / 2;
		e2 = w * 9.81 * s;
		e3 = k * (s - l) * (s - l) / 2;
		if (s <= l) {
			if (e1 < e2) {
				cout << "Killed by the impact." << endl;
			}
			else
				cout << "James Bond survives." << endl;
		}
		else {
			if (e3 > e2) {
				cout << "Stuck in the air." << endl;
			}
			else if (e2 - e3 <= e1) {
				cout << "James Bond survives." << endl;
			}
			else {
				cout << "Killed by the impact." << endl;
			}
		}
	}
}
