/** 1251
×ÖµäÊ÷ 
**/
#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std;

const int maxN = 500000;
int ch[maxN][26], val[maxN], sz;

void insert (char* s) {
	int u = 0, len = strlen(s);
	for (int i = 0; i < len; ++i) {
		int c = s[i] - 'a';
		if (!ch[u][c]) {
			ch[u][c] = sz++;
		}
		u = ch[u][c];
		val[u]++;
	}
}

int find(char* s) {
	int u = 0, len = strlen(s);
	for (int i = 0; i < len; ++i) {
		int c = s[i] - 'a';
		if (ch[u][c])
			u = ch[u][c];
		else
			return 0;
	}
	return val[u];
}

int main () {
	char str[11];
	sz = 1;
	while (gets(str) && str[0])
		insert(str);
	while (scanf("%s", &str) != EOF)
		printf("%d\n", find(str));
	return 0;
}
