/* #1050
如果两次搬运用到了同一段走廊，就不能同时搬，
找到使用次数最多的那一段,它决定了总时间，
总时间=次数*10

写for循环的时候要注意三个地方是不是对的：
1. 初始化 
2. 跳出条件
3. 自增长 
*/ 
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int lines, a, b, times[200] = {0}, max = 0;
		cin >> lines;
		for(int i = 0; i < lines; i++) {
			cin >> a >> b ;
			if ( a > b) {
				int t = a;
				a = b;
				b = t;
			}
			for (int i = (a + 1) / 2; i <= (b + 1)/ 2; i++)
				times[i]++; 
		}
		for (int i = 0; i < 200; i++) {
			max = max < times[i]? times[i] : max;
		} 
		cout << max * 10 << endl;
	}
	return 0;
}
