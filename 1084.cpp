/* #1084
	1.ÿ��ѧ����id(����ڼ���), n(�������), t(ʱ��)
	2.����������(cmp)
	3.�ҵ�ÿ�������εĳ��ȣ� ���ڷ�����ǰ���+5, ���ֻ��һ���ˣ�+5
	4. �������ǵ�id��5���ȥ
	6. ��ӡscore���顣
	
	˼������Ҫ�������� 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct P {
	int id;
	int n;
	int t;
}a[110];


int cmp (P a, P b) {
	if (a.n == b.n)
		return a.t < b.t;
	else
		return a.n > b.n;
}

int main() {
	int T;
	while (cin >> T, T >= 0) {
		int score[110] = {0};
		int h, m, s;
		for (int i = 0; i < T; i++) {
			scanf("%d%d:%d:%d", &a[i].n, &h, &m, &s);
			a[i].id = i;
			a[i].t = 3600 * h + 60 * m + s;
			score[i] = 100 - (5 - a[i].n)* 10;
		}
		sort(a, a + T, cmp);
		int i , j;
		for (i = 0 ; i < T; i = j) {
			int temp = a[i].n, tot = 0, cur = i;
			for (j = i; (a[j].n == temp) && j < T; j++) {
					tot++;
			}
			if (a[i].n == 5 || a[i].n == 0)
				continue;
			if (tot > 1)
				tot /= 2;
			while (tot--)
				score[a[cur++].id] += 5;				
			
		}
		for (int i = 0; i < T; i++)
			cout << score[i] << endl;
		cout << endl;	
	}
	return 0;
}
