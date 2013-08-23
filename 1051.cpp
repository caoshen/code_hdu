#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 5005;

struct stick{
    int len, wei;
}p[MAXN];

int cmp(stick a, stick b){
    if(a.len != b.len )
        return a.len < b.len;
    else
        return a.wei < b.wei;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int i, j;
        for(i = 0; i < n; i++)
            cin >> p[i].len >> p[i].wei;
        sort(p, p + n, cmp);

        int dp[MAXN];
        for(i = 0; i < n; i++){
            dp[i] = 1;
            for(j = 0 ; j < i; j++){
                if(p[i].wei < p[j].wei && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
        }

        int ans = 0;
        for(i = 0; i < n; i++)
            ans = max(ans, dp[i]);
        cout << ans << endl;
    }
    return 0;
}
