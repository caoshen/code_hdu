/* #1064
printf�����������������
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	double item, sum = 0, mean;
	for (int i = 0; i < 12 ; i++) {
		cin >> item;
		sum +=item;
	}
	mean = sum / 12;
	printf("$%.2lf\n", mean);
	return 0;
}
