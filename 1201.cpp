/** 1201
**/
#include <iostream>
#include <cstdio>
using namespace std;

int leap(int y) {
    return !(y % 400) || !(y % 4) && (y % 100);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int y, m, d, day = 0;
        scanf("%d-%d-%d", &y, &m, &d);
        for (int i = 1; i <= 18; ++i) {
            if (leap(y + i))
                day += 366;
            else
                day += 365;
        }
        if (leap(y) && m < 3)
            ++day;
        if (leap(y + 18) && (m < 3))
            --day;
        if ( (m == 2 && d == 29) && !leap(y + 18))
            cout << "-1" << endl;
        else
            cout << day << endl;
    }
    return 0;
}
