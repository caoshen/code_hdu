/* һ����(����)ģ�������о�����
�������������ÿλ��֮��
���������֮��Ϊ0����ôÿλ��֮��Ϊ9��
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		int t = n;
		for (int i = 2; i <= n; i++) {
			t = (t * n) % 9;
			if (t == 0)
				break;
		}
		if (t)
			cout << t << endl;
		else
			cout << "9" << endl;
	}
	return 0;
} 
 
