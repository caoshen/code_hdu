/** 1171
**/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct F {
	int v, m;
};
F a[55];

int cmp(F i, F j) {
	return i.v < j.v;
}

int ans , n;

void dfs(int x) {
	if (ans > x)
		ans = x;
	for (int i = n - 1; i >=0; --i) {
		if (a[i].m >= 1 && x - a[i].v >=0) {
			a[i].m--;
			dfs(x - a[i].v);
		}
	}
}

int main() {
	while (cin >> n, n > 0) {
		int sum = 0;
		ans = 2 << 30 -1;
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &a[i].v, &a[i].m);
			sum	+= a[i].v * a[i].m;
		}
		
		sort(a, a + n, cmp);
		
		dfs(sum / 2);
		int cs, ss;
		if (sum % 2 == 0) {
			cs = sum / 2 + ans;
			ss = sum - cs;
		}
		else {
			cs = sum / 2 + 1 + ans;
			ss = sum - cs;
		}
		if (cs > ss)
			cout << cs << " " << ss << endl;
		else
			cout << ss << " " << cs << endl;
	}
	return 0;
} 
