/** 1148**/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct P {
	int id;
	string t;
};

struct M {
	P p1, p2;
};

struct R {
	int w, l;
};

M m[110];
R r[110];

int cmp (P p1, P p2) {
	if (p1.t == "rock" && p2.t == "scissors" ||
		p1.t == "scissors" && p2.t == "paper" ||
		p1.t == "paper" && p2.t == "rock")
		return 1;
	else if (p1.t == p2.t)
		return 0;
	else
		return -1;
}

int main() {
	int n, k;
	int fir = 1;
	while (cin >> n >> k, n) {
		if (!fir)
			cout << endl;
		else
			fir = 0;
		memset(r, 0, sizeof(r));
		for (int i = 0; i < k; ++i) {
			cin >> m[i].p1.id >> m[i].p1.t
				>> m[i].p2.id >> m[i].p2.t;			
			if (cmp(m[i].p1, m[i].p2) == 1 ) {
				int index1 = m[i].p1.id, index2 = m[i].p2.id;
				r[index1].w++;
				r[index2].l++;
			}
			else if (cmp(m[i].p1, m[i].p2) == 0) {
				continue;
			}
			else {
				int index1 = m[i].p1.id, index2 = m[i].p2.id;
				r[index1].l++;
				r[index2].w++;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (r[i].w || r[i].l) {
				printf("%.3lf\n", (double)r[i].w / (r[i].w + r[i].l));
			}
			else {
				printf("-\n");
			}
		}
	}
	return 0;
}
