#include <iostream>

using namespace std;

const int MAXN = 100;

int main()
{
    int num;
    while(cin >> num){
        int i, a[MAXN], d[MAXN], count = 0;
        if(num == 0)
            break;
        for(i = 0; i < num; i++){
            cin >> a[i];
        }
        while(1){
            int flag = 1;
            for(i = 0; i < num - 1; i++)
                if(a[i] != a[i+1]){
                    flag = 0;
                    break;
                }
            if(flag){
                cout << count << " " << a[0] << endl;
                break;
            }
            count++;
            for(i = 0; i < num; i++){
                d[i] = a[i] /= 2;
            }
            for(i = 0; i < num; i++){
                a[(i+1)%num] += d[i];
                if(a[(i+1)%num]%2 == 1)
                    ++a[(i+1)%num];
            }
        }
        continue;
    }
    return 0;
}
