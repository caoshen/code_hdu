/** 1144
**/
#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 100 + 10;
int nk[MAXN], nc[MAXN];
int main() {
	int k, m, c, r;
	while (scanf("%d", &k)) {
		if (k == 0)
			break;
		scanf("%d", &m);
		for (int i = 0; i < k; i++)
			scanf("%04d", &nk[i]);
		int flag = 1;
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &c, &r);
			for (int j = 0; j < c; j++) {
				scanf("%d", &nc[j]);
			}
			int cnt = 0;
			for (int m = 0; m < k; m++) {
				for (int n = 0; n < c; n++) {
					if (nk[m] == nc[n]) {
						cnt++;
						break;
					}
				}
			}
			if (cnt < r) {
				flag = 0;
			}
		}
		if (flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}
