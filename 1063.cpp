#include <iostream>

using namespace std;

const int MAXN = 150;

int main()
{
    string str;
    int n;
    while(cin >> str >> n){
        int a = 0, sum[MAXN] = {1}, i, count = 0;
        for(i = 0; i <= str.size() - 1; i++){
            if(str[i] == '.'){
                count = (str.size() - 1 - i) * n;
                continue;
            }
            a = (a * 10)  + str[i] - '0';
        }

        while(n >= 1){
            n--;
            int c = 0;
            for(i = 0; i < MAXN; i++){
                int tmp = sum[i] * a + c;
                c = tmp / 10;
                sum[i] = tmp % 10;
            }
        }

        int j, k, l;
        for(j = MAXN - 1; sum[j] == 0; j--);
        for(k = 0; sum[k] == 0; k++);

        if(j < count - 1 ){
            cout << ".";
            for(l = 0; l < count - 1 - j; l++)
                cout << "0";
        }
        for(i = j; i >= k; i--){
            if(i == count - 1){
                cout << ".";
            }
            cout << sum[i];
        }
        if(k + 1 > count)
            for(i = k - 1; i >= count; i--)
                cout << sum[i];
        cout << endl;
    }
    return 0;
}
