#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

struct point{
    double x, y;
};

double dis(point a, point b){
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

point center(point a, point b){
    point mid, cen;
    double dx , dy, c, ang;
    mid.x = (a.x + b.x) / 2;
    mid.y = (a.y + b.y) / 2;
    c = sqrt(1 - dis(mid, a));
    dx = b.x - a.x;
    dy = b.y - a.y;
    ang = atan( - dx / dy);
    if(fabs(dy) < 1e-6){
        cen.x = mid.x;
        cen.y = mid.y + c;
    }
    else{
        cen.x = mid.x + c * cos(ang);
        cen.y = mid.y + c * sin(ang);
    }
    return cen;
}

int main()
{
    int t;
    point p[305];
    cin >> t;
    while(t--){
        int n, i, j, k, max = 1;
        scanf("%d", &n);//cin >> n;
        for(i = 0; i < n; i++){
            scanf("%lf%lf", &p[i].x, &p[i].y);//cin >> p[i].x >> p[i].y ;
        }
        for(i = 0; i < n; i++)
            for(j = i + 1; j < n; j++){
                if(dis(p[i], p[j]) > 4)
                    continue;
                int tmp = 0;
                point o = center(p[i], p[j]);
                for(k = 0; k < n; k++)
                    if(dis(o, p[k]) < 1.000001)
                        tmp++;
                if(max < tmp)
                    max = tmp;
            }
        cout << max << endl;
    }
    return 0;
}
