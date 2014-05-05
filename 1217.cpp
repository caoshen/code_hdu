/** 1217
点对最短路径 floyd算法 
**/
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
double a[40][40];
int n;

void floyd() {
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				a[i][j] = max(a[i][j], a[i][k] * a[k][j]);
}

int main() {
	int t = 0;
	while (cin >> n, n) {
		string sn;
		map<string, int> sm;
		for (int i = 1; i <= n; ++i) {
			cin >> sn; 
			sm[sn] = i;
		}
		int e;
		cin >> e;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < e; ++i) {
			string s1, s2;
			double d;
			cin >> s1 >> d >> s2;
			a[sm[s1]][sm[s2]] = d;
		}
		floyd();
		int flag = 0;
		for (int i = 1; i <= n; ++i) {
			if (a[i][i] > 1 ) {
				flag = 1;
				break;
			}
		}
		
		if (flag)
			cout << "Case " << ++t << ": Yes" << endl;
		else
			cout << "Case " << ++t << ": No" << endl;
	}
	return 0;
}
