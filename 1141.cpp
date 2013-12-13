/**1141
**/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int y;
	while (cin >> y , y ) {
		int n =  pow(2.0, (y - 1960) / 10) * 4;
		int num = 1;
		double sum = 0;
		while (sum <= n) {
			sum += log(num++) / log(2);
		}
		num--;
		cout << --num << endl;
	}
}
