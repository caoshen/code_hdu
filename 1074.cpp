/* #1074
状态搜索
*/
 
#include <iostream>
#include <cstring>
using namespace std;

struct S {
	string s;
	int d;
	int c;
	int e;
}a[20];

int Min[70000], last[70000];
int n, t, ok;

void dfs(int time, int now, int ans) {
	if (now >= n)
		return;
	for (int i = 0; i < n; i++) {
		int m = 1 << i;
		if (ok & m)
			continue;
		ok |= m;
		t = time + a[i].e;
		if (t < 0)
			t = 0;
		if ( ans + t < Min[ok]) {
			Min[ok] = ans + t;
			last[ok] = ok & (~m);
			dfs( time + a[i].c, now + 1, ans + t);
 		}
 		ok &= ~m; 
	}
	return;
} 

void print (int t) {
	if (t == 0)
		return;
	int tt = last[t];
	int i;
	print(tt);
	t ^= tt; // 异或表示对称差，t现在是刚完成的那一科 
	for (i = 0; i < n; i++)   {
		if ( t & (1 << i)) {
			cout << a[i].s << endl; 
			break;
		}
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		ok = 0;
		memset(Min, 127, sizeof(Min));
		memset(last, 0, sizeof(last));
		for (int i = 0; i < n; i++) {
			cin >> a[i].s >> a[i].d >> a[i].c;
			a[i].e = a[i].c - a[i].d;
		}
		dfs(0, 0, 0);
		int t = (1 << n) - 1;
		cout << Min[t] << endl;
		print(t);
	}
}
