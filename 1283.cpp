/** 1283
**/
#include <iostream>
#include <string>
using namespace std;

int a, b, m1, m2, r1, r2, r3;

void fa() {
	r1 = m1;
}

void fb() {
	r2 = m2;
}

void fc() {
	m1 = r3;
}

void fd() {
	m2 = r3;
}

void fe() {
	r3 = r1 + r2;
}

void ff() {
	r3 = r1 - r2;
}

int main() {
	string str;
	while (cin >> a >> b >> str) {
		m1 = a;
		m2 = b;
		r1 = r2 = r3 = 0;
		for (int i = 0; i < str.size(); ++i) {
			switch(str[i]) {
				case 'A': fa(); break;
				case 'B': fb(); break;
				case 'C': fc(); break;
				case 'D': fd(); break;
				case 'E': fe(); break;
				case 'F': ff(); break;
			}
		}
		cout << m1 <<"," << m2 << endl;
	}
	return 0;
}
