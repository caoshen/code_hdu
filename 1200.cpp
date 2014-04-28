/**1200
**/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int c;
	while (cin >> c , c) {
		string s;
		cin >> s;
		int r;
		r = s.size() % c ? s.size() / (c - 1) : s.size() / c;
		for (int i = 0; i < c; ++i) {
			for (int j = 0; j < r; ++j)
				if (!(j % 2))
					printf("%c", s[i  + j * c ]);
				else
					printf("%c", s[(j + 1) * c - (i + 1)]);
		}
		printf("\n");
	}
	return 0;
}
