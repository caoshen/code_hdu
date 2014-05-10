/** 1234
**/
#include <iostream>
#include <cstdio>
using namespace std;

struct re{
	char id[20];
	int b, e;
}a[100];

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int max = 100000000, min = -1, maxi = 0, mini = 0;
		for (int i = 0; i < n; ++i) {
			int pos = 0;
			getchar();
			while ((a[i].id[pos++] = getchar()) != ' ');
			a[i].id[--pos] = '\0';
			int h, m, s;
			scanf("%d:%d:%d", &h, &m, &s);
			a[i].b = h * 60 * 60 + m * 60 + s;
			scanf("%d:%d:%d", &h, &m, &s);
			a[i].e = h * 60 * 60 + m * 60 + s;
			if (a[i].b < max) {
				max = a[i].b;
				maxi = i;
			}
			if (a[i].e > min) {
				min = a[i].e;
				mini = i;
			}
		}
		printf("%s %s\n", a[maxi].id, a[mini].id);
	}
	return 0;
}
