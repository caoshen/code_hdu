/* #1065
สýังฬโ 
*/
#include <iostream>
#include <cstdio>
using namespace std;

const double pi = 3.1415926;

int main() {
	int T, n = 0;
	cin >> T;
	while (T--) {
		
		double x, y ;
		int year;
		cin >> x >> y;
		year = pi * ( x * x + y * y) / 100 + 1;
		printf("Property %d: This property will begin eroding in year %d.\n", ++n, year); 
	}
	cout << "END OF OUTPUT." << endl; 
} 
