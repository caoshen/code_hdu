/** 1161
**/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	while(getline(cin, s)) {
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		cout << s << endl;
	}
}
