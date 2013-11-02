/* #1073 
1. getline() �����ȡ��β�Ļ���
2. ��������ַ�����ͬ�� Accepted
	���ȥ���հ��ַ�����ͬ��PE
	���ȥ����հ��ַ���ͬ�� WA
	
˼������Ҫ��ȫ������һ���㷨�ǲ��Ǽ���Ч��
 
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
