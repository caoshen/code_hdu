/** 1212
A % B : A 是一个大数
**/
#include <iostream>
using namespace std;

int main() {
	string sa;
	int b;
	while (cin >> sa >> b) {
		int ans = sa[0] - '0';
		for (int i = 1; i < sa.size(); ++i) {
			ans = (ans * 10 + sa[i] - '0') % b;
		}
		cout << ans << endl;
	}
	return 0;
} 
