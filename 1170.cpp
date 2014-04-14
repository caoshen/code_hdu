/** 1170
**/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		char c;
		getchar();
		scanf("%c %d %d", &c, &a, &b);
		
		if (c == '+') {
			printf("%d\n", a + b);
		}
		else if (c == '-') {
			printf("%d\n", a - b);
		}
		else if (c == '*') {
			printf("%d\n", a * b);
		}
		else if (c == '/') {
			int d = a % b;
			if (d)
				printf("%.2lf\n", (double)a / b);
			else
				printf("%d\n", a / b);
		}
	}
	return 0;
}
