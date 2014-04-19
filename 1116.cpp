/**1116
²¢²é¼¯ 
**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;

const int maxN = 30;
int p[maxN], vis[maxN], out[maxN], in[maxN];

int find(int x) {
	return x == p[x] ? p[x] : p[x] = find(p[x]);
}

void uni(int x, int y) {
	int u = find(x);
	int v = find(y);
	if (u != v)
		p[u] = v;
}

int isOk() {
	set<int> si;
	for (int i = 0; i < maxN; ++i)
		if (vis[i])
			si.insert(find(i));
	if (si.size() > 1)
		return 0;
	int cnt = 0;
	for (int i = 0; i < maxN; ++i) {
		if (abs(in[i] - out[i]) > 1)
			return 0;
		if (abs(in[i] - out[i]) == 1)
			++cnt;
	}
	return cnt <= 2;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		memset(vis, 0, sizeof(vis));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		for (int i = 0; i < maxN; ++i)
			p[i] = i;
		
		for (int i = 0; i < n; ++i) {
			char s[1050];
			scanf("%s", &s);
			int x = s[0] - 'a', y = s[strlen(s) - 1] - 'a';
			vis[x] = vis[y] = 1;
			++out[x];
			++in[y];
			uni(x, y);
		}
		if (n == 1 || isOk())
			printf("Ordering is possible.\n");
		else
			printf("The door cannot be opened.\n");
		
	}
	return 0;
}


