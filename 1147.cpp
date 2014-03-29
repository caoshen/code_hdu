/** 1147
判断线段相交，如果l1 X l2 > 0, 那么 l1 在 l2的顺时针方向
lst.remove_if(unaryPred) 调用lst.erase删除所有等于指定值或使指定的谓词函数返回非零值的元素 
**/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <list>
using namespace std;

struct Point {
    Point() {
    }
    Point(double dx, double dy): x(dx), y(dy) {
    } 
    double x, y;
};

Point a[100050][2];

int cro(Point a, Point b, Point c, Point d) {
    Point e = Point(b.x - a.x, b.y - a.y);
    Point f = Point(c.x - a.x, c.y - a.y);
    Point g = Point(d.x - a.x, d.y - a.y);
    Point h = Point(d.x - c.x, d.y - c.y);
    Point i = Point(a.x - c.x, a.y - c.y);
    Point j = Point(b.x - c.x, b.y - c.y);
    
    return (e.x * f.y - e.y * f.x) * (e.x * g.y - e.y * g.x) <= 0 &&
        (h.x * i.y - h.y * i.x) * (h.x * j.y - h.y * j.x) <= 0;    
}

int top;

int croTop(int i) {
    return cro(a[i][0], a[i][1], a[top][0], a[top][1]);    
}

int main() {
    int n;
    while (cin >> n, n) {
        list<int> li;

        for (int i = 0; i < n; ++i) {
            //cin >> a[i][0].x >> a[i][0].y >> a[i][1].x >> a[i][1].y;
            scanf("%lf%lf%lf%lf", &a[i][0].x, &a[i][0].y, &a[i][1].x, &a[i][1].y);
            top = i;
            li.remove_if(croTop);
            li.push_back(top);
        }
        cout << "Top sticks: ";
        for (list<int>::iterator it = li.begin(); it != li.end();) {
            cout << *it + 1; 
            if (++it == li.end())
                cout << "." << endl;
            else
                cout << ", ";
        } 
    }
    return 0;
}
