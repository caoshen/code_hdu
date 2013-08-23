#include <iostream>
#include <stack>
using namespace std;

struct mat{
    char id;
    int row;
    int col;
};

mat arr[26];


int main()
{
    int num, i;
    cin >> num;
    for(i = 0; i < num; i++){
        cin >> arr[i].id >> arr[i].row >> arr[i].col;
    }

    string str;

    while(cin >> str){
        if(str.size() == 1){
            cout << "0" << endl;
            continue;
        }
        stack<char> stk1;
        stack<mat> stk2;
        int sum = 0 , flag = 1;

        for(i = 0; i < str.size(); i++){
            if(str[i] == '(')
                stk1.push(str[i]);
            else if(str[i] == ')'){
                stk1.pop();
                mat m1, m2;
                m1 = stk2.top();
                stk2.pop();
                m2 = stk2.top();
                stk2.pop();
                if(m2.col != m1.row){
                    flag = 0;
                    break;
                }
                sum += m2.row * m2.col * m1.col;
                m2.col = m1.col;
                stk2.push(m2);
            }
            else{
                mat m;
                int j;
                for(j = 0; j < num; j++){
                    if(arr[j].id == str[i]){
                        m = arr[j];
                    }
                }
                stk2.push(m);
            }
        }
        if(flag == 0)
            cout << "error" << endl;
        else
            cout << sum << endl;
    }
    return 0;
}
