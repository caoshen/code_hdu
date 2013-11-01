/* #1084
	1.每个学生有id(代表第几个), n(答题个数), t(时间)
	2.将他们排序(cmp)
	3.找到每个分数段的长度， 处于分数段前半的+5, 如果只有一个人，+5
	4. 根据他们的id把5填过去
	6. 打印score数组。
	
	思考问题要有条有理！ 
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
