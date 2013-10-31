/* #1056 
i应该从0开始计数 
*/ 
#include <iostream>
using namespace std;

int main() {
	double length;
	while(cin >> length) {
		if (length == 0)
			break;
		double sum = 0;
		int i = 0;
		while (sum < length) {
			sum +=  (double)1 / (i + 2);
			i++;
		}
		cout << i << " card(s)" << endl;
	}
}
