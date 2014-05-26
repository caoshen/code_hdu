/** 1266
**/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int flag = 0;
		long long n;
		
		scanf("%I64d", &n);
		if (n < 0) {
			flag = 1;
			n *= -1;
		}
		int cnt = 0;
		while (n % 10 == 0 && n) {
			n /= 10;
			++cnt;
		}
		long long sum = 0;
		while (n) {
			sum = sum * 10 + n % 10;
			n /= 10;
		}
		while (cnt--)
			sum *= 10;
		if(flag)
			sum *= -1;
		printf("%I64d\n", sum);
	}
	return 0;
}
