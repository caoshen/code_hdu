/* #1079
���˺þ�Ҳû����֤��������������ҹ��ɣ�������֤���£����˴���������
 
���º��յĺͿ���һ����a����ô���������ξ������ı�a����ż�ԣ�
������11,4��a=11+4����һ������������˭����������״̬˭�����ˣ�������˵���˭
�ɶԷ�����ÿ�ζ�����������ȻӮ�������е������У����е�a��ż����
�·ݿ϶�����ֻ��һ���ͰѶԷ����Ƴ���������****9.30����11.30 Ҳ���ԣ��öԷ�һֱ����������ƽ��������2�¶�һ��
������������a��ż������9.30��11.30���˻�Ӯ��Ҳ����˵��һ������Ե�����ֵa=(��+��)������Ӯ��
״̬����ô��һ�����䣻
*/
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int y, m, d;
		scanf("%d%d%d", &y, &m, &d);
		if ((m + d) % 2 == 0 || ((m == 9 || m == 11) && d == 30))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}