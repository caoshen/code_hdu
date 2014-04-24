/**
²î·Ö 
**/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxN = 105;

int a[maxN][maxN];

int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		int s, c;
		cin >> s >> c;
		for (int i = 1; i <= s; ++i) {
			cin >> a[0][i];
		}
		// 1..s-1½×²î·Ö 
		for (int i = 1; i < s; ++i) {
			for (int j = 1; j <= s - i; ++j) 
				a[i][j] = a[i - 1][j + 1] - a[i - 1][j];
		}
		// µ¹ÍÆ
		for (int i = s - 1; i >= 0; --i) {
			for (int j = 1; j <= c; ++j)
				a[i][s - i + j] = a[i + 1][s - i + j - 1] + a[i][s - i + j - 1];
		}
		for (int i = s + 1; i <= s + c; ++i)
			if (i == s + c)
				cout << a[0][i] << endl;
			else
				cout << a[0][i] << " "; 
	}
	return 0;
} 
