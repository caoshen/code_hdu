/* #1075
用map保存字典 
注意时间限制，每一行只能扫描一遍
如果在一行中多次扫描,TLE 
*/

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<string, string> dic;
int main() {
	string s1, s2;
	char c[15];
	while (scanf("%s", c)) {
		s1 = c;
		if ( s1 == "START")
			continue;
		if ( s1 == "END")
			break;
		scanf("%s", c);
		s2 = c;
		dic.insert(make_pair(s2, s1));
	}
	string s;
	map<string, string>::iterator it;
	getchar(); // 这里要补一个getchar() 
	while(1) {
		getline(cin, s);
		if (s == "START")
			continue;
		if (s == "END")
			break;
		for (int i = 0; i < s.size();) {
			if (s[i] <= 'z' && s[i] >= 'a') {
				string s1;
				while (i < s.size() && s[i] <= 'z' && s[i] >= 'a') {
					s1.push_back(s[i]);
					i++;
				}
				it = dic.find(s1);
				if (it != dic.end())
					cout << it -> second;
				else
					cout << s1;
			}
			else {
				cout << s[i];
				i++;
			}
		}
		cout << endl;			
//		while (it != dic.end()) {
//			string::size_type pos = s.find(it -> first);
//			if (pos != string::npos)
//				s.replace(pos, (it -> first).size(), it -> second);
//			it++;
//		}
//		cout << s << endl;
	}
	return 0;
}
