/** 1152 **/
#include <iostream>
#include <cstdio>
using namespace std;
const int Maxn = 200000 +  10;
int a[Maxn][2];

int main() {
	int n;
	while (cin >> n, n) {
		int x, y;
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i][0], &a[i][1]);
		}
		x = a[(n - 1) / 2][0];
		y = a[(n - 1) / 2][1];
		int s1, s2;
		s1 = s2 = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i][0] > x && a[i][1] > y || a[i][0] < x && a[i][1] < y)
				s1++;
			else if (a[i][0] > x && a[i][1] < y || a[i][0] < x && a[i][1] > y)
				s2++;
			else
				continue;
		}
		cout << s1 << " " << s2 << endl;
	}
	return 0;
}
