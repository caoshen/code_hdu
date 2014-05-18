/** 1237
**/
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main() {
	char c;
	int a;
	while (scanf("%d", &a)) {
		c = getchar();
		if (a == 0 && c == '\n')
			break;
		stack<double> si;
		si.push(a);
		c  = getchar();
		while (scanf("%d", &a)) {
			double re = 0;
			switch(c) {
				case '+' :
					si.push(a);
					break;
				case '-' :
					si.push(- a);
					break;
				case '*' :
					re = si.top() * a;
					si.pop();
					si.push(re);
					break;
				case '/' :
					re = si.top() / a;
					si.pop();
					si.push(re);
					break;
			}
			if (getchar() == '\n')
				break;
			c = getchar();	
		}
		double ans = 0;
		while (!si.empty()) {
			ans += si.top();
			si.pop();
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
