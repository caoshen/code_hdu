/** 1263
**/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct F {
	char fr[20], pr[20];
	int m;
};

F a[105];

int cmp (F f1, F f2) {
	if (strcmp(f1.pr, f2.pr) != 0)
		return strcmp(f1.pr, f2.pr) < 0;
	else if (strcmp(f1.fr, f2.fr) != 0)
		return strcmp(f1.fr, f2.fr) < 0;
	else
		return f1.m > f2.m;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%s%s%d", a[i].fr, a[i].pr, &a[i].m);
		sort(a, a + n, cmp);
		F cur = {"", "", 0};
		for (int i = 0; i < n; ++i) {
			// �Ƚ��ǲ���ͬһ���أ� ���õ�ǰֵ 
			if (strcmp(cur.pr, a[i].pr)) {
				printf("%s\n", a[i].pr);
				cur = a[i];
			}
			// �Ƚ���һ�������ǲ���ͬһ�ֲ���ͬһ��ˮ�� 
			if (!strcmp(cur.pr, a[i + 1].pr) && !strcmp(cur.fr, a[i + 1].fr)) {
				cur.m += a[i + 1].m;
			}
			// ������ǣ��Ϳ��Դ�ӡ���ף�����������ˮ������ �� �������� 
			else {
				printf("   |----%s(%d)\n", cur.fr, cur.m);
				strcpy(cur.fr, a[i + 1].fr);
				cur.m = a[i + 1].m;
			}
		}
		if (t)
			printf("\n");
	}
	return 0;
}
