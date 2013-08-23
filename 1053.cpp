#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;



struct cmp{
    bool operator()(int a, int b){
        return a > b;
    }
};



int nonprefix(string str)
{
    int i;
    map<char, int> char2int;
    priority_queue<int,vector<int>, cmp> codenum;

    for(i = 0; i < str.size(); i++){
        char2int[str[i]]++;
    }
    map<char, int>::iterator imap = char2int.begin();

    while(imap != char2int.end()){
        codenum.push(imap -> second);
        imap++;
    }


    int weight = 0;

    if(codenum.size() == 1){
        return codenum.top() * 1;
    }
    while(codenum.size() != 1){
        int n1, n2;
        n1 = codenum.top();
        codenum.pop();
        n2 = codenum.top();
        codenum.pop();
        codenum.push(n1+n2);
        weight += n1 + n2;
    }

    return weight;
}
int main()
{
    string str;
    while(cin >> str){
        if(str == "END")
            break;
        cout << 8 * str.size() << " " << nonprefix(str) << " ";
        printf("%.1f\n", double(8*str.size())/nonprefix(str));
    }
    return 0;
}
