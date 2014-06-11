/** 1247
**/
#include <iostream>
#include <cstdio>
#include <cstring> 
using namespace std;

struct Trie {
	int v;
	Trie* next[27];
};

Trie root;
char map[50000][100];
void insert (char* s) {
	int len = strlen(s);
	Trie* p = &root, *q;
	for (int i = 0; i < len; ++i) {
		int t = s[i] - 'a';
		if (p -> next[t] == NULL) {
			q = new Trie();
			q -> v = -1;
			memset(q -> next, 0, sizeof (q -> next));
			p -> next[t] = q;
			p = q;
		}
		else {
			p = p -> next[t];
		}
	}
	p -> v = 1; // 字符串尾的v为1 
}

int find(char* s) {
	int len = strlen(s);
	Trie *p = &root;
	for (int i = 0; i < len; ++i) {
		int t = s[i] - 'a';
		p = p -> next[t];
		if (!p)
			return -1; // 没找到
	}
	return p -> v; 
}


int main () {
	//freopen("D:\in.txt", "r", stdin);
	int cnt = 0;
	for (int i = 0; i < 26; ++i)
		root.next[i] = NULL;
	while (scanf("%s", map[cnt]) != EOF) {
		insert(map[cnt++]);
	}
	char s1[100] = {'\0'}, s2[100] = {'\0'};
	for (int i = 0; i < cnt; ++i) {
		int len = strlen(map[i]);
		for (int j = 1; j < len; j++) {
			strcpy(s1, map[i]);
			s1[j] = '\0'; // s1长度为j
			strcpy(s2, map[i] + j);
			if (find(s1) == 1 && find(s2) == 1) {
				printf("%s\n", map[i]);
				break; // 找到一种分成两个 word 的方法就停止 
			}
		}
	}
	return 0; 
}
