/* #1055
并查集
*/

#include <iostream>
using namespace std;

struct Node {
	int c, t, p;
	double w;
} a[1010];

int n , r;

int find () {
	double max = 0;
	int pos;
	for (int i = 1; i <= n; i++) {
		if (max < a[i].w && i != r) {
			max = a[i].w;
			pos = i;
		}
	}
	return pos;
}

int main() {
	while (cin >> n >> r, n && r) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].c;
			a[i].t = 1;
			a[i].w = a[i].c;
			ans += a[i].c; 
		}
		// 注意是 <, 因为根节点没有父节点 
		for (int i = 1; i < n; i++) {
			int a1, b1;
			cin >> a1 >> b1;
			a[b1].p = a1; 
		}
		
		int  num = n;
		// 最后还有一个根节点 
		while (num-- > 1) {
			// 找出权值最大的节点 
			int pos = find();
			
			for (int i = 1; i <= n; i++) {
				if (a[i].p == pos)
					a[i].p = a[pos].p;
			}
			// 合并父节点 
			a[pos].w = 0;
			ans += a[pos].c * a[a[pos].p].t;
			a[a[pos].p].t += a[pos].t;
			a[a[pos].p].c += a[pos].c;
			a[a[pos].p].w = (double) a[a[pos].p].c / a[a[pos].p].t;
		}
		cout << ans << endl;
	}
	return 0; 
}
