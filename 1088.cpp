#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string line;
    int count = 0;
    while(getline(cin, line)){
        stringstream sstr (line);//initialize stringstream
        string word;
        while(sstr >> word){
            if(word == "<br>"){
                cout << endl;
                count = 0;
                continue;
            }
            if(word == "<hr>"){
                if(count)
                    cout << endl;
                int i;
                for(i = 0; i < 80; i++)
                    cout << "-";
                cout << endl;
                count = 0;
                continue;
            }
            if(!count){
                cout << word;
                count = word.size();
                continue;
            }
            if(count + word.size() + 1 > 80){
                cout << endl << word;
                count = word.size();
                continue;
            }
            cout << " " << word;
            count += (word.size() + 1);
        }
    }
    cout << endl;
    return 0;
}
