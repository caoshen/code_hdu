/** 1296
**/
//#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
//using namespace std;

int main () {
	int n;
	char str[200];
	while (scanf("%d%s", &n, str) != EOF) {
		int len = strlen(str), co = 0, e = 0;
		char tmp = '+';
		long long sum = 0;
		for (int i = 0; i <= len;) {
			if (str[i] == '-' || str[i] == '+' || str[i] == '\0') {
				if (tmp == '+')
					sum += co * pow(n, e);
				else
					sum -= co * pow(n, e);
				co = e = 0;
				tmp = str[i];
				i++;
			}
			else if (str[i] == 'X') {
				if (co == 0)
					co = 1;
				if (str[++i] != '^')
					e = 1;
			}
			else if (str[i] == '^') {
				++i;
				while (str[i] >= '0' && str[i] <= '9') {
					e = e * 10 + str[i] - '0';
					++i;
				}
			}
			else {
				co = co * 10 + str[i] - '0';
				++i;
			}
		}
		printf("%I64d\n", sum);
	}
	return 0;
}
