/* 一个数(非零)模九余数叫九余数
九余数是这个数每位数之和
如果九余数之和为0，那么每位数之和为9！
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		int t = n;
		for (int i = 2; i <= n; i++) {
			t = (t * n) % 9;
			if (t == 0)
				break;
		}
		if (t)
			cout << t << endl;
		else
			cout << "9" << endl;
	}
	return 0;
} 
 
