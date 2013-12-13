/** 1197**/

#include <iostream>
using namespace std;

int main() {
	for (int i = 2992; i <= 9999; i++) {
		int tmp = i, s10, s16, s12;
		s10 = s16 = s12 = 0;
		while (tmp) {
			s10 += tmp % 10;
			tmp /= 10;
		}
		tmp = i;
		while (tmp) {
			s16 += tmp % 16;
			tmp /= 16;
		}
		if (s10 != s16)
			continue;
		tmp = i;
		while (tmp) {
			s12 += tmp % 12;
			tmp /= 12;
		}
		if (s16 == s12)
			cout << i << endl;
	}
	return 0;
}
