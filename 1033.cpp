#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while(cin >> s){
        int x = 300, y = 420;
        cout << x << " " << y << " moveto" << endl;
        x += 10;
        cout << x << " " << y << " lineto" << endl;
        int i, n = 0;
        for(i = 0; i < s.size(); i++){
            if(n == 0 && s[i] == 'V'){
                y += 10;
                cout << x << " " << y << " lineto" << endl;
                n = 1;
                continue;
            }
            if(n == 0 && s[i] == 'A'){
                y -= 10;
                cout << x << " " << y << " lineto" << endl;
                n = 2;
                continue;
            }
            if(n == 1 && s[i] == 'V'){
                x -= 10;
                cout << x << " " << y << " lineto" << endl;
                n = 3;
                continue;
            }
            if(n == 1 && s[i] == 'A'){
                x += 10;
                cout << x << " " << y << " lineto" << endl;
                n = 0;
                continue;
            }
            if(n == 2 && s[i] == 'V'){
                x += 10;
                cout << x << " " << y << " lineto" << endl;
                n = 0;
                continue;
            }
            if(n == 2 && s[i] == 'A'){
                x -= 10;
                cout << x << " " << y << " lineto" << endl;
                n = 3;
                continue;
            }
            if(n == 3 && s[i] == 'V'){
                y -= 10;
                cout << x << " " << y << " lineto" << endl;
                n = 2;
                continue;
            }
            if(n == 3 && s[i] == 'A'){
                y += 10;
                cout << x << " " << y << " lineto" << endl;
                n = 1;
                continue;
            }
        }
        cout << "stroke" << endl;
        cout << "showpage" << endl;

    }
    return 0;
}
