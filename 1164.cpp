#include <iostream>
using namespace std;

int p[40000];

void prime() {
	int k = 1;
	for (int i = 2; i <= 65535; i++) {
		int flag = 1;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			p[k++] = i;
		}
	}
}

int main() {
	int n;
	prime();
	while (cin >> n) {
		int tmp = n, k = 1;
		while (tmp != 1) {
			if (tmp % p[k] == 0) {
				cout << p[k];
				tmp /= p[k];
				if (tmp != 1)
					cout << "*";
			}
			else
				k++;
		}
		cout << endl;
	}
	return 0;
}
