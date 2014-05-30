/** 1276
**/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[5005];

int main() {
    int n;
    scanf("%d", &n);
    while (n--)  {
        memset(a, 0, sizeof(a));
        int m;
        scanf("%d", &m);
        int t = m, d = 2;
        while (t > 3) {
            int num = 0;
            for (int i = 1; i <= m; ++i) {
                if (!a[i]) { 
                    ++num;
                    if(num % d == 0) {
                        a[i] = 1;
                        --t;
                    } 
                }
            }
            d = 5 - d;
        }
        printf("1"); 
        for (int i = 2; i <= m; ++i)
            if (!a[i])
                printf(" %d", i);
        printf("\n");
    }
    return 0;
} 
