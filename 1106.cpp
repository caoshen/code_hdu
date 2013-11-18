/* #1106
sort
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;



int main() {
	string s;
	while (getline(cin, s)) {
		int i = 0, j = 0, a[10010] = {0};
		for (i = 0; i < s.size(); i++) {
			// 求出一个数 
			if (s[i] != '5') {
				a[j] = a[j] * 10 + s[i] - '0';
			}
			// 求个数 
			if (s[i] != '5' && s[i + 1] == '5') {
				j++; 
			}
		}
		// 特殊情况 
		if (s[s.size() - 1] != '5')
			j++;
		sort (a, a + j);
		for (i = 0; i < j - 1; i++)
			cout << a[i] << " ";
		cout << a[i] << endl;
	}
	return 0;
} 
