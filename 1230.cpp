#include <iostream>
#include <cstdio>
using namespace std;

int op1[100], op2[100], re[100], a[100];

void find() {
	a[0] = 1;
	int cnt = 0;
	for (int i = 2; i <= 200 && cnt <= 25; ++i) {
		int f = 1;
		for (int j = 2; j * j <= i; ++j) {
			if (i % j == 0) {
				f = 0;
				break;
			}
		}
		if (f)
			a[++cnt] = i;
	} 
}

int main() {
	string s1, s2;
	find();
	while (cin >> s1 >> s2) {
		memset(op1, 0, sizeof(op1));
		memset(op2, 0, sizeof(op2));
		memset(re, 0, sizeof(re));
		if (s1 == "0" && s2 == "0")
			break;
		int k1 = 1, sum = 0, f = 0;
		for (int i = s1.size() - 1; i >= 0; --i) {
			if (s1[i] == ',') {
				op1[k1++] = sum;
				sum = 0;
				f = 0;
				continue;
			}
			sum = f ? (s1[i] - '0') * 10 + sum : (s1[i] - '0');
			f = 1;
			if (!i) 
				op1[k1++] = sum;
		}
		int k2 = 1;
		sum = 0;
		f = 0;
		for (int i = s2.size() - 1; i >= 0; --i) {
			if (s2[i] == ',') {
				op2[k2++] = sum;
				sum = 0;
				f = 0;
				continue;
			}
			sum = f ? (s2[i] - '0') * 10 + sum : (s2[i] - '0');
			f = 1;
			if (!i)
				op2[k2++] = sum;
		}
		int len = k1 > k2 ? k1 - 1 : k2 - 1;
		int c = 0;
		for (int i = 1; i <= len; ++i) {
			int t = op1[i] + op2[i] + c;
			c = t / a[i];
			re[i] = t % a[i];
		}
		if (c)
			re[++len] = c;
		for (int i = len; i > 1; --i)
			printf("%d,", re[i]);
		printf("%d\n", re[1]);
	}
	return 0;
}
