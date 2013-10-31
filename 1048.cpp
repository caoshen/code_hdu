/* #1048
”√getline(cin , str)∂¡“ª––
*/ 


#include <iostream>
#include <string>
using namespace std;

string convert(string s) {
	string temp;
	string::iterator iter;
	for(iter = s.begin(); iter != s.end(); iter++) {
		if (*iter == ',' || *iter == ' ')
			temp += *iter;
		else
			temp += (*iter - 'A' - 5 + 26) % 26 + 'A';
	}
	return temp;
}

int main() {
	string s;
	while(1) {
		getline(cin, s);
		if (s == "ENDOFINPUT")
			break;
		if (s == "START" || s == "END")
			continue;
		cout << convert(s) << endl;
	}
	return 0;
}
