/** 1231
**/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

const int maxN = 10008;
int a[maxN], dp[maxN];


int main()
{
    int n;
    while (~scanf("%d", &n), n) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (a[i] < 0)
                ++cnt;
        }
        if (cnt == n) {
            printf("0 %d %d\n", a[0], a[n - 1]);
            continue;
        }
        memset(dp, 0, sizeof(dp));
        int max = a[0], b = 0, e = 0;
        dp[0] = a[0];
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + a[i] > a[i] ? dp[i - 1] + a[i] : a[i];
            if (max < dp[i]) {
                max = dp[i];
                e = i;
            }
        }
        int sum = 0;
        for (int i = e; i >= 0; --i) {
            sum += a[i];
            if (sum == max) {
                b = i;
                break;
            }
        }
        printf("%d %d %d\n", max, a[b], a[e]);
    }
    return 0;
}
