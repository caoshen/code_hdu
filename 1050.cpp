/* #1050
������ΰ����õ���ͬһ�����ȣ��Ͳ���ͬʱ�ᣬ
�ҵ�ʹ�ô���������һ��,����������ʱ�䣬
��ʱ��=����*10

дforѭ����ʱ��Ҫע�������ط��ǲ��ǶԵģ�
1. ��ʼ�� 
2. ��������
3. ������ 
*/ 
#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int lines, a, b, times[200] = {0}, max = 0;
		cin >> lines;
		for(int i = 0; i < lines; i++) {
			cin >> a >> b ;
			if ( a > b) {
				int t = a;
				a = b;
				b = t;
			}
			for (int i = (a + 1) / 2; i <= (b + 1)/ 2; i++)
				times[i]++; 
		}
		for (int i = 0; i < 200; i++) {
			max = max < times[i]? times[i] : max;
		} 
		cout << max * 10 << endl;
	}
	return 0;
}
