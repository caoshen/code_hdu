/**1157
**/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN = 10010;
int a[maxN];

int main() {
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		cout << a[(n - 1) / 2] << endl;
	}
	return 0;
}
