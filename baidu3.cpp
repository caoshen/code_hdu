/** 1003
×ÖµäÊ÷ 
**/
#include <iostream> 
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxN = 100005;
long long v[maxN], b[maxN];
int a[maxN][2],  sz = 1;

struct Trie {
	Trie* next[2];
	long long v;
};

Trie* root;

void insert(long long x) {
	Trie *p = root, *q;
	
	for (int i = 31; i >= 0; --i) {
		int k = ((1 << i) & x) ? 1 : 0;
		if (p -> next[k] == NULL) {
			q = (Trie *)malloc(sizeof(Trie));
			for (int j = 0; j < 2; ++j)
				q -> next[j] = NULL;
			p -> next[k] = q;
			p = p -> next[k];
		}
		else {
			p = p -> next[k];
		}
	}
	p -> v = x;
}


long long find(long long x) {
	Trie *p = root;
	for (int i = 31; i >= 0; --i) {
		int k = ((1 << i) & x) ? 1 : 0, k1 = k ? 0 : 1;
		if (p -> next[k1])
			p = p -> next[k1];
		else if (p -> next[k])
			p = p -> next[k];
		else
			break;
	}
	return p -> v;
}

int main () {
	int t;
	int n, m, t1 = 0;
	long long s, r;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		root = (Trie *)malloc(sizeof(Trie));
		root -> next[0] = root -> next[1] = NULL;
		for (int i = 0; i < n; ++i) {
			scanf("%I64d", &r);
			insert(r);
		}
		printf("Case #%d:\n", ++t1);
		for (int i = 0; i < m; ++i) {
			scanf("%I64d", &s);
			long long ans = find(s);
			printf("%I64d\n", ans);
		}
	}
	return 0;
}
