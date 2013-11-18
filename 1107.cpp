/* #1107
	理解题意，一个格子中最多3个人相遇 
	只有两个门派各一个人才战斗，其他情况不战斗 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 50;

struct P {
	int x, y;
	int a, b, c, d;
	int f;
	char s;
}q[1010];


int main() {
	int T;
	cin >> T;
	while (T--) {
		memset(q, 0, sizeof(q));
		int mov, num = 0;
		cin >> mov;
		while (cin >> q[num].s) {
			if (q[num].s == '0')
				break;
			q[num].f = 1;
			cin >> q[num].x >> q[num].y
				>> q[num].a >> q[num].b
				>> q[num].c;
			num++;
		}
		
		while (mov--) {
			// 战斗 
			for (int i = 0 ; i < 12; i++) {
				for (int j = 0; j < 12; j++) {
					int n0, n1, n2, p0, p1, p2;
					n0 = n1 = n2 = p0 = p1 = p2 =0;
					for (int k = 0; k < num ; k++) {
						if (q[k].x == i + 1 && q[k].y == j + 1) {
							if (q[k].s == 'S') {
								n0++;
								p0 = k;
							}
							else if (q[k].s == 'W') {
								n1++;
								p1 = k;
							}
							else if (q[k].s == 'E'){
								n2++;
								p2 = k;
							}
						}
					}
					if ( n0 + n1 + n2 == 2 && n0 != 2 && n1 != 2 && n2 != 2) {
						q[p0].d = (int) ((0.5 * q[p0].a + 0.5 * q[p0].b) * (q[p0].c + 10) / 100);
						q[p1].d = (int) ((0.8 * q[p1].a + 0.2 * q[p1].b) * (q[p1].c + 10) / 100);
						q[p2].d = (int) ((0.2 * q[p2].a + 0.8 * q[p2].b) * (q[p2].c + 10) / 100);
						
						if (n0 && n1) {
							q[p0].c -= q[p1].d;
							q[p1].c -= q[p0].d;
						}
						if (n0 && n2) {
							q[p0].c -= q[p2].d;
							q[p2].c -= q[p0].d;
						}
						if (n1 && n2) {
							q[p1].c -= q[p2].d;
							q[p2].c -= q[p1].d;
						}
						if (q[p0].c <= 0)
							q[p0].s = '0';
						if (q[p1].c <= 0)
							q[p1].s = '0';
						if (q[p2].c <= 0)
							q[p2].s = '0';
					}
				}
			}
			// 移动
			for (int i = 0; i < num ; i++) {
				if (q[i].s == 'S') {
					if (q[i].x == 12 && q[i].f == 1 || q[i].x == 1 && q[i].f == -1)
						q[i].f = -q[i].f;
					q[i].x += q[i].f;
				}
				if (q[i].s == 'W') {
					if (q[i].y == 12 && q[i].f == 1 || q[i].y == 1 && q[i].f == -1)
						q[i].f = -q[i].f;
					q[i].y += q[i].f;
				}
				if (q[i].s == 'E') {
					if (q[i].x == 12 && q[i].f == 1 || q[i].x == 1 && q[i].f == -1 ||
						q[i].y == 12 && q[i].f == 1 || q[i].y == 1 && q[i].f == -1)
						q[i].f = -q[i].f;
					if (q[i].x == 12 && q[i].y == 1 || q[i].x == 1 && q[i].y == 12)
						q[i].f = 0;
					q[i].x += q[i].f;
					q[i].y += q[i].f;
				}
			}
		}
		int tot0, tot1, tot2, sum1, sum2, sum0;
		tot0 = tot1 = tot2 = sum0 = sum1 = sum2 = 0;
		for (int i = 0; i < num ; i++) {
			if (q[i].s == 'S') {
				tot0++;
				sum0 += q[i].c;
			}
			if (q[i].s == 'W') {
				tot1++;
				sum1 += q[i].c;
			}
			if (q[i].s == 'E') {
				tot2++;
				sum2 += q[i].c;
			}
		}
		printf("%d %d\n%d %d\n%d %d\n***\n", tot0, sum0, tot1, sum1, tot2, sum2);
	}
	return 0;
}
