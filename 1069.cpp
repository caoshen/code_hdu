/* #1069
dp 从子问题中寻找最优的一个 
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Z {
	int x, y, z;
}a[200];

int max (int a, int b) {
	return a > b ? a: b;
}
int min (int a, int b) {
	return a < b ? a: b;
}
int add (Z* a, int x, int y ,int z) {
	a -> x = max (x, y);
	a -> y = min (x, y);
	a -> z = z;
}
int cmp (Z a, Z b) {
	if (a.x == b.x)
		return a.y > b.y;
	return a.x > b.x;
}
int main() {
	int t , x1, y1, z1, n = 0;
	while (cin >> t, t != 0) {
		int tot = 0;
		for (int i = 0; i < t; i++)  {
				cin >> x1 >> y1 >> z1;
				add(&a[tot++], x1, y1, z1);
				add(&a[tot++], x1, z1, y1);
				add(&a[tot++], y1, z1, x1);
		}
		sort(a, a + tot, cmp);
		int h[100], maxh = 0;
		h[0] = a[0].z;
		for (int i = 1; i < tot; i++) {
			h[i] = 0;
			// 从下面可能的堆叠方式中选择高度最大的一种
			for (int j = i -1; j >= 0; j--)			
				if (a[i].x < a[j].x && a[i].y < a[j].y)
					h[i] = max(h[i], h[j]);
			
			// 加上自身的高度
			h[i] += a[i].z;
			// 更新最大高度
			 maxh = max(maxh, h[i]);
		}
		cout << "Case " << ++n << ": maximum height = " << maxh << endl; 
	}
}
