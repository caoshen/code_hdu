/** 1238
**/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, ms = 100, msi = 0;
		string str;
		vector<string> sv;
		cin >> n; 
		for (int i = 0; i < n; ++i) {
			cin >> str;
			if (str.size() < ms) {
				ms = str.size();
				msi = i;
			}
			sv.push_back(str);
		}
		int len = 0;
		string sm = sv[msi];
		for (int i = 0; i < sm.size(); ++i)
			for (int j = i + 1; j <= sm.size(); ++j) {
				string su(sm.begin() + i, sm.begin() + j), sr(su);
				reverse(sr.begin(), sr.end());
				int  flag = 1;
				for (int k = 0; k < sv.size(); ++k) {
					if (k == msi)
						continue;
					if (sv[k].find(su) ==  sv[k].npos && sv[k].find(sr) == sv[k].npos) {
						flag = 0;
						break;
					}
				}
				if (flag == 1 && su.size() > len) {
					len = su.size();
				}
			}
		cout << len   << endl;
	}
	return 0;
} 
