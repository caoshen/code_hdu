/** 1165
ֱ�Ӱ���ʽ���TLE���������Ƴ�m=0,1,2,3ʱ�Ĺ�ʽ 
**/
#include <iostream>
#include <cmath>
using namespace std;

int ackermann(int m, int n) {
	if (m == 0) {
		return n + 1;
	}
	else if (m == 1) {
		return n + 2;
	}
	else if (m == 2) {
		return 2 * n + 3;
	}
	else if (m == 3){
		return pow(2.0, n + 3) - 3;
	}
	return -1;
}

int main(){
	int m, n;
	while (cin >> m >> n) {
		cout << ackermann(m, n) << endl;
	}
}
