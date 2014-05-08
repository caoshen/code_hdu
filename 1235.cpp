/** 1235
**/
#include <iostream>
#include <cstdio>
using namespace std;

int a[1000 + 5];

int main() {
	int t;
	while (~scanf("%d", &t), t) {
		for (int i = 0; i < t; ++i)
			scanf("%d", &a[i]);
		int s, cnt = 0;
		scanf("%d", &s);
		for (int i = 0; i < t; ++i)
			if (a[i] == s)
				++cnt;
		printf("%d\n", cnt);	
	}
	return 0;
}
