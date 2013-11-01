/* #1085
硬币组合问题，母函数求解 
*/

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 8050;
int sum[MAXN];

int main() {
	int a, b, c;
	while (cin >> a >> b >> c) {
		if (a == 0 && b == 0 & c == 0)
			break;
		int x[1010], y[1010], z[1010];
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i <= a; i++) {
			//x[i] = i;
			for (int j = 0; j <= b; j++) {
				//y[j] = 2 * j;
				sum[i + 2 * j]++;
			}
		}
		int ratio[MAXN] = {0}; // 保存系数 
		for (int i = 0; i <= a + 2 * b; i ++) {
			ratio[i] = sum[i];
			sum[i] = 0;
		}
		for (int k = 0; k <= a + 2 * b; k++)
			for (int i = 0; i <= c; i++) {
				//z[i] = 5 * i;
				sum[k + 5 * i] += ratio[k];
		}
		// TLE
//		for (int i = 0; i <= a; i++)
//			for (int j = 0; j <= b; j++)
//				for (int k = 0; k <= c; k++) {
//					sum[x[i] + y[j] + z[k]]++; 
//				}
		for (int i = 0; i < MAXN; i++) {
			if (sum[i] == 0) {
				cout << i << endl;
				break;				
			}
		}
	}
	return 0;
}
