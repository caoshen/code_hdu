/** 1225
**/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct T {
	int sc, ne, ki;
	char id[50];
};

T a[10020];

const int INF = - (1 << 10);

int cmp (T t1, T t2) {
	if ( t1.sc != t2.sc)
		return t1.sc > t2.sc;
	else if (t1.ne != t2.ne)
		return t1.ne > t2.ne;
	else if (t1.ki != t2.ki)
		return t1.ki > t2.ki;
	else
		return t1.id > t2.id;
}

int main () {
	int t;
	while (scanf("%d", &t) != EOF) {
		int n = t * (t - 1);
		char te1[50], te2[50];
		int fi, se, k = 0;
		while (n--) {
			scanf("%s VS %s %d:%d", te1, te2, &fi, &se);
			strcpy(a[k].id, te1);
			a[k].sc = fi > se ? 3 : (fi < se ? 0 : 1);
			a[k].ki = fi;
			a[k++].ne = fi - se;
			strcpy(a[k].id, te2);
			a[k].sc = fi > se ? 0 : (fi < se ? 3 : 1);
			a[k].ki = se;
			a[k++].ne = se - fi;
		}

		for (int i = 0; i < k - 1; ++i) {
			if (a[i].sc == INF)
				continue;
			for (int j = i + 1; j < k; ++j) {
				if (strcmp(a[i].id, a[j].id) == 0) {
					a[i].sc += a[j].sc;
					a[j].sc = INF;
					a[i].ki += a[j].ki;
					a[i].ne += a[j].ne;
				}
			}
		}
		sort(a, a + k, cmp);
		for (int i = 0; i < t; ++i)
			printf("%s %d\n", a[i].id, a[i].sc);
		printf("\n");
	}
	return 0;
}
