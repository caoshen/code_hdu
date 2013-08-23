#include <iostream>

using namespace std;

int loops(int x, int y, char  a[10][10]){
    int i = x, j = y, cnt = 0;
    while(1){
        if(a[i][j] == 'E')
            j++;
        else if(a[i][j] == 'S')
            i++;
        else if(a[i][j] == 'W')
            j--;
        else
            i--;
        cnt++;
        if( i == x && j == y)
            return cnt;
    }
}

int main()
{
    char a[10][10];
    int row, col, start;
    while(cin >> row >> col >> start){
        int i, j, cnt = 0, loop = 0, loopnum = 0;
        int vis[10][10] = {0};
        if(row * col * start == 0)
            break;
        for(i = 0; i < row; i++)
            for(j = 0; j < col; j++)
                cin >> a[i][j];

        i = 0, j = start - 1;

        while(1){
            if((i == 0 && a[i][j] == 'N')
               || (i == row - 1 && a[i][j] == 'S')
               || (j == 0 && a[i][j] == 'W')
               || (j == col - 1 && a[i][j] == 'E')){
                cnt++;
                break;
               }

            if(vis[i][j]){
                loop = 1;
                loopnum = loops(i, j, a);
                break;
            }
            vis[i][j] = 1;
            if(a[i][j] == 'E')
                j++;
            else if(a[i][j] == 'S')
                i++;
            else if(a[i][j] == 'W')
                j--;
            else
                i--;
            cnt++;

        }
        if(loop)
            cout << cnt - loopnum << " step(s) before a loop of " << loopnum << " step(s)" << endl;
        else
            cout << cnt << " step(s) to exit" << endl;
    }
    return 0;
}
