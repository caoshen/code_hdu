#include <iostream>

using namespace std;

int main()
{

    int n, u, d;
    while(cin >> n >> u >> d){
        if(n == 0)
            break;
        int dis = 0, t = 0;
        while(dis < n){
            dis += u;
            t++;
            if(dis >= n)
                break;
            dis -= d;
            t++;
        }
        cout << t << endl;
    }
    return 0;
}
