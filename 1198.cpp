/** 1198
**/
#include <iostream>
#include <cstdio>
using namespace std;

int a[55][55], p[55 * 55];

int d[11][4] = {1, 0, 0, 1,
				1, 1, 0, 0, 
				0, 0, 1, 1,
				0, 1, 1, 0,
				1, 0, 1, 0,
				0, 1, 0, 1,
				1, 1, 0, 1,
				1, 0, 1, 1,
				0, 1, 1, 1,
				1, 1, 1, 0,
				1, 1, 1, 1};

int find (int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

void uni(int x, int y) {
	int u = find(x), v = find(y);
	if (u != v) {
		p[u] = v;	
	}
}

int main() {
	int m, n;
	char c;
	while (cin >> m >> n) {
		if (m == -1 && n == -1)
			break;
		getchar();
		for (int i = 0; i < m * n; ++i)
			p[i] = i;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				c = getchar();
				a[i][j] = c - 'A';
				if (j >= 1 && d[a[i][j - 1]][1] && d[a[i][j]][3])
					uni(i * n + j, i * n + j - 1);
				if (i >= 1 && d[a[i- 1][j]][2] && d[a[i][j]][0])
					uni(i * n + j, (i - 1) * n + j);
			}
			getchar();
		}
		int ans = 0;
		for (int i = 0; i < m * n; ++i)
			if (p[i] == i)
				++ans;
		cout << ans << endl;
	}
	return 0;
}
