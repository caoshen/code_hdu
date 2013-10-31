/* #1052
做什么都要细心！
一个简单的题目都要调3次！
何况是生活？生活可以调试吗？！

http://blog.csdn.net/qzh3578/article/details/12707889
*/ 

#include <iostream>
#include <algorithm>
using namespace std;

int cmp(int a, int b) {
	return a > b;
}

int main() {
	int n;
	while (cin >> n) {
		if (n == 0)
			break;
		int a[1000], b[1000];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		sort(a, a + n, cmp);
		sort(b, b + n, cmp);
		int i = 0, j = 0, i2 = n-1, j2 = n-1, m = 0, t = 0;
		while ( t++ < n) {
			if (a[i] > b[j]) { // 最快马> , 比较 
				m++;
				i++;
				j++;
			}
			else if(a[i] < b[j]) { // 最快马< , 最慢与最快比 
				m--;
				i2--;
				j++;
			}
			else { // 最快马= , 最慢与最慢比
				if (a[i2] > b[j2]){  // 最慢马> , 最慢与最慢比 
					m++;
					i2--;
					j2--;
				}
				else { // 最慢马 <=, 最慢与最快比 
					if(a[i2] < b[j]) // < , m-- 
						m--;
					i2--;
					j++;
				}
			}
		}
		cout << 200 * m << endl;
	}
} 
