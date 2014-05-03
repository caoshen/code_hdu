/** 1215
**/
#include <iostream>
#include <cstdio>
using namespace std;
const int maxN = 500000 + 5;

int f(int n) {
	if (n == 1)
		return 0;
	int sum = 1;
	// 优化：i < n变成i * i <= n 
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0 &&  i * i < n)
			sum += i + n / i;
		else if (n % i== 0 && i * i == n)
			sum += i;
		else
			continue;
	return sum;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", f(n));
	}
	return 0;
} 
