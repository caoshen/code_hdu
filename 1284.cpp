/** 1284
**/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		int sum = n / 3 + 1;
		for  (int i = 0; i <= n / 3; ++i) {
			sum += (n - i * 3) / 2;
		}
		printf("%d\n", sum);
	}
	return 0;
	
}
