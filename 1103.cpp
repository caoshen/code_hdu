/* #1103
使用队列模拟排队 
*/
#include <iostream>
#include <cstdio>
#include <deque> 
using namespace std;

deque<int> q[3];
int a[3];
 
int main() {
	while(cin >> a[0] >> a[1] >> a[2], a[1] || a[2] || a[3]) {
		int h, m, t, p, tot= 0;
		string s;
		for (int i = 0; i < 3; i++)
			q[i].clear();
		while (cin >> s, s != "#") {
			h = (s[0] - '0') * 10 + (s[1] - '0');
			m = (s[3] - '0') * 10 + (s[4] - '0');
			t = h * 60 + m;
			cin >> p;
			int k;
			if (p == 1 || p == 2)
				k = 0;
			else if (p == 3 || p == 4)
				k = 1;
			else if (p ==5 || p == 6)
				k = 2;
			else
				break;
		
			if (q[k].size() < a[k]) {
				q[k].push_back(t);
				tot += p; 
			}
			else {
				int tmp = q[k].front() + 30;
				// 第一桌离开的时间 < 等待30分钟后，可以等 
				if (tmp <= t + 30) {
					q[k].pop_front(); //吃完后就有一张空桌子，给第一群等待的人 
					// 开吃时间 = 第一桌离开时间 
					if (t < tmp)
						t = tmp;
					q[k].push_back(t);
					tot += p; 
				}
			}
		}
		cout << tot << endl;
	}
	return 0;
} 
