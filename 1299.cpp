/**
1299
**/
#include <iostream>
using namespace std;
const int M = 35000;
int prime[M + 5];

void pi() {
	for (int i = 2; i * i <= M; ++i) {
		if (prime[i] == 0) {
			for (int j = i * i; j <= M; j += i) {
				prime[j] = 1;		
			}
		}	
	}
}

int main() {
	pi();
	int t, d = 1;;
	cin >> t;
	while (t--) {
		int n, sum = 1;
		cin >> n;
		cout << "Scenario #" << d++ << ":" << endl ;
		if (n == 1) {
			cout << 1 << endl << endl;
			continue;
		}
		for (int i = 2; i <= M; ++i) {
			if (!prime[i]) {
				int k = 0;
				while (n % i == 0) {
					n /= i;
					++k;
				}
				sum *= ( 1 + 2 * k);
			}
		}
		if (n > 1)
			sum *= 3;
		cout << (sum + 1) / 2 << endl << endl;
	}
}
