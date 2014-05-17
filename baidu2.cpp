/** 1002
**/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>

using namespace std;

struct P{
	int t, s;
};

const int maxN = 1005;
P a[maxN];
int b[maxN][maxN];
const int INF = 1 << 30;

int dis(P x, P y) {
	int dt = abs(x.t - y.t);
	int ds = abs(x.s - y.s);
	if (ds > 180)
		ds = 360 - ds;
	return 400 * dt + 1 * ds + 10;
}

int dP(int n) {
	b[0][1] = dis(a[0], a[1]);
	for (int j = 2; j <= n; ++j)
	{
		for (int i = 0; i <= j - 2; ++i)
		{
			b[i][j] = b[i][j - 1] + dis(a[j - 1], a[j]);
		}
		//i = j - 1,b[i][j] = min(b[k][j - 1] + distance(k,j));
		b[j - 1][j] = INF;
		for (int k = 0; k <= j - 2; ++k)
		{
			int tmp = b[k][j - 1] + dis(a[k], a[j]);
			if (tmp < b[j - 1][j])
			{
				b[j - 1][j] = tmp;
			}
		}
	}

	b[n][n] = b[n - 1][n] + dis(a[n - 1], a[n]);

	return b[n][n];
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--) {
		int n;
		scanf("%d", &n);
		a[0].t = a[0].s = 0;
		for (int i = 1; i <= n; ++i)
			scanf("%d %d", &a[i].t, &a[i].s);
		printf("%d\n", dP(n) - 10);	
	}
	return 0;
}
