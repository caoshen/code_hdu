/** 1290
**/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


int main () {
	int n;
	while (cin >> n) {
		printf("%d\n", (n * n * n + 5 * n) / 6 + 1);
	}
	return 0;		
}
