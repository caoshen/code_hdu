/** Kruskal求最小生成树**/ 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 10000;
int p[150];
int m, n;

struct Point {
	double x, y;
}a[150];

struct Edge {
	int s, e;
	double d;
}b[maxn];

double dis(Point a, Point b) {
	double d = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	return sqrt(d);
}

int cmp(Edge a, Edge b) {
	return a.d < b.d;
}

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

double Kruskal() {
	double ans = 0;
	for (int i = 0; i < n; i++)
		p[i] = i;
	sort(b, b + m, cmp);
	for (int i = 0; i < m; i++) {
		int x = find(b[i].s);
		int y = find(b[i].e);
		if (x != y) {
			ans += b[i].d;
			p[x] = y;
		}
	}
	return ans;
}

int main() {
	while (scanf("%d", &n) != EOF) {
		m = 0;
		for (int i = 0; i < n; i++)
			scanf("%lf%lf", &a[i].x, &a[i].y);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				b[m].s = i;
				b[m].e = j;
				b[m++].d = dis(a[i], a[j]); 	
			}
		printf("%.2f\n", Kruskal());	
	}
	return 0;
}
