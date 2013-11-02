/* #1073 
1. getline() 不会读取行尾的换行
2. 如果两个字符串相同， Accepted
	如果去掉空白字符后相同，PE
	如果去掉后空白字符后不同， WA
	
思考问题要周全，先想一下算法是不是简单有效的
 
*/
#include <iostream>
#include <cstdio>
using namespace std;

int isSpace(char c) {
	if (c == ' ' || c == '\t' || c == '\n')
		return 1;
	else
		return 0;
}

void cmp (string a, string b) {
	string s1, s2;
	if (a == b) {
		cout << "Accepted" << endl;
		return;
	}
	for (int i = 0; i < a.size(); i++) {
		if (!isSpace(a[i]))
			s1 += a[i]; 
	}
	for (int i = 0; i < b.size(); i++) {
		if (!isSpace(b[i]))
			s2 += b[i];
	}
	if (s1 == s2) {
		cout << "Presentation Error" << endl;
		return;
	}
	else
		cout << "Wrong Answer" << endl;
	return;
}
int main() {
	int T;
	cin >> T;
	getchar();
	while (T--) {
		string s1, s2, ss1, ss2;
		int time = 0;
		getchar();
		while (getline(cin,ss1), ss1 != "END") {
			if (time)
				s1 += '\n';
			s1 += ss1;
			time++;
		}
		time = 0;
		getchar();
		while (getline(cin, ss2), ss2 != "END") {
			if (time)
				s2 += '\n';
			s2 += ss2;
			time++;
		}
		cmp(s1, s2);	 
	}
	return 0;
}
