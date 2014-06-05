/** 1294
**/
#include <iostream>
using namespace std;
long long f[41];
int cnt[41], n;

long long com(long long n, long long m) {
	long long res = 1;
	m = min(m, n - m);
	for (int i = 1; i <= m; ++i)
		res = res * (n - i + 1) / i;
	return res;
}

int dfs(int tmp, int left) {
	// 拆分完成 
	if (left == 0) {
		long long res = 1;
		for (int i = 1; i <= n; ++i) {
			// 拆分为i的数目为0 
			if (!cnt[i])
				continue;
			// 从f[i]种tree中选择cnt[i]个 
			res *= com(f[i] + cnt[i] - 1, cnt[i]); 
		}
		f[n] +=  res;
		return 0;
	} 
	for (int i = tmp; i <= left; ++i) {
		// 拆分为 i 
		++cnt[i];
		dfs(i, left - i);
		// 恢复 
		--cnt[i];
	}
	return 0;
}
int main() {
	f[1] = f[2] = 1;
	for (n = 3; n <= 40; ++n) 
		dfs(1, n - 1);
	while (cin >> n)
		cout << f[n] << endl;
	return 0;
}
