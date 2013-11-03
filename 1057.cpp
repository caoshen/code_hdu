/* #1057
看清题目要求！
*/

#include <iostream>
#include <cstring>
using namespace std;

int D[16];
int m[20][20];
int m1[20][20];
int dx[4] = { 0, 0, 1, -1};
int dy[4] = { 1, -1, 0, 0};

int wei(int x, int y) {
    int w = m[x][y];
    for (int i = 0; i < 4; i++) {
        int x1, y1;
        x1 = x + dx[i];
        y1 = y + dy[i];
        if (x1 >=0 && x1 < 20 && y1 >=0 && y1 < 20)
            w += m[x1][y1];
    }
    int w1 = m[x][y] + D[w];
    if (w1 < 0)
        w1 = 0;
    if (w1 > 3)
        w1 = 3;
    return w1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int d;
        cin >> d;
        for (int i = 0; i < 16; i++) {
                cin >> D[i];
            }
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++) {
                cin >> m[i][j];
            }

        while (d--) {
            for (int i = 0; i < 20; i++)
                for (int j = 0; j < 20; j++) {
                        m1[i][j] = wei(i, j);
                    }
            memcpy(m, m1, sizeof(m));
        }
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (m[i][j] == 0)
                    cout << ".";
                if (m[i][j] == 1)
                    cout << "!";
                if (m[i][j] == 2)
                    cout << "X";
                if (m[i][j] == 3)
                    cout << "#";
                }
            cout << endl;
        }
        if (T)
            cout << endl;
    }
    return 0;
}
