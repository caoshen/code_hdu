#include <iostream>

using namespace std;
const int MAXN = 5845;

int min(int a, int b, int c, int d){
    if(a <= b && a <= c && a <= d)
        return a;
    else if(b <= a && b <= c && b <= d)
        return b;
    else if(c <= a && c <= b && c <= d)
        return c;
    else
        return d;
}

int main()
{
    int a[MAXN] = {1, 1}, i, t1 , t2, t3, t4;
    t1 = t2 = t3 = t4 = 1;
    for(i = 2; i <= MAXN; i++){
        int t = min(a[t1] * 2, a[t2] * 3 , a[t3] * 5, a[t4] * 7);

        if(t == a[t1] * 2)
            t1++;
        if(t == a[t2] * 3)
            t2++;
        if(t == a[t3] * 5)
            t3++;
        if(t == a[t4] * 7)
            t4++;
        a[i] = t;
    }

    int n;
    while(cin >> n){
        if(n == 0)
            break;
        if(n % 10 == 1 && n % 100 != 11)
            cout << "The " << n << "st humble number is " << a[n] << "." << endl;
        else if(n % 10 == 2 && n % 100 != 12)
            cout << "The " << n << "nd humble number is " << a[n] << "." << endl;
        else if(n % 10 == 3 && n % 100 != 13)
            cout << "The " << n << "rd humble number is " << a[n] << "." << endl;
        else
            cout << "The " << n << "th humble number is " << a[n] << "." << endl;
    }
    return 0;
}
