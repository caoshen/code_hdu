/** 1113
**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> vs;

int equal(string a, string b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}

int main() {
	string s;
	while(getline(cin, s), s != "XXXXXX") {
		vs.push_back(s);
	}
	sort(vs.begin(), vs.end());
	while (getline(cin, s), s != "XXXXXX") {
		vector<string>::iterator it = vs.begin();
		int f = 0;
		for(; it != vs.end(); ++it) {
			if (equal(s, *it)) {
				f = 1;
				cout << *it << endl;
			}
		}
		if (!f)
			cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}
	return 0;
}
