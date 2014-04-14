/** 1153**/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	long long n, i;
	while (cin >> n, n) {
		if (n == 2) 
			cout << "Impossible" << endl;
		else {
			vector<int> vi(n, 1);
			for (i = 1; i < n; ++i) {
				vi[i * i % n] = 0;
			}
			for (i = 1; i < n; ++i) {
				cout << vi[i];
			}
			cout << endl;
		}
	}
	return 0;
}
