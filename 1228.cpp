/** 1228
**/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int str2int(string s) {	
	switch (s[0]) {
		case 'z': return 0;
		case 'o': return 1;
		case 't': return s[1] == 'w' ?  2 :  3;
		case 'f': return s[1] == 'o' ?  4 :  5;
		case 's': return s[1] == 'i' ?  6 :  7;
		case 'e': return 8;
		case 'n': return 9;
	}
}

int main() {
	int op1 = 0, op2 = 0, f = 0;
	string str;
	while (cin >> str) {
		if (str == "+") {
			f = 1;
			continue;
		}
		if (str == "=") {
			if (!op1 && !op2)
				break;
			cout << op1 + op2 << endl;
			f = 0;
			op1 = op2 = 0;
			continue;
		}
		if (!f) {
			if (!op1)
				op1 = str2int(str);
			else
				op1 = op1 * 10 + str2int(str);
		}
		else {
			if (!op2)
				op2 = str2int(str);
			else
				op2 = op2 * 10 + str2int(str);
		}
	}
	return 0;
}
