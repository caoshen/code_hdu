/* #1109
ģ���˻�����ʽ�����㷨��
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const int M = 30; // ��ʼ30���� 
const int L = 30; // �������� 
const int N = 1050; // ���1000��trap 

struct P {
	double x, y, d;
}a[N], b[M]; // x, y ���꣬ d �����trap�ľ��� ��a traps���飬 b ��ʼ��

const double eps = 1e-3;
int X, Y , n; // �����С�� trap��

double dist( double x, double y) {
	return x * x + y * y;
} 

double di(double x, double y) {
	if (x < 0 || y < 0 ||
		x > X || y > Y)
		return 0;
	double d = 1e10;
	for (int i = 0; i < n; i++) {
		d = min (d, dist(x - a[i].x, y - a[i].y));
	}
	return d;
}

void work() {
	cin >> X >> Y >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y;
	// ��ʼ��M����
	for (int i = 0; i < M; i++) {
		b[i].x = rand() % (X + 1); // �õ�[0, X)�������
		b[i].y = rand() % (Y + 1);
		b[i].d = di(b[i].x, b[i].y); 
	}
	// ģ���˻�, delta�Ǹı������ɴ��С 
	for (double delta = max(X, Y); delta > eps; delta *= 0.88) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < L; j++) {
				double phi = rand(); // �õ�һ������Ƕ�
				P tmp;
				tmp.x = b[i].x + cos(phi) * delta; // delta���Ʋ����� ����b[i]��λ�� 
				tmp.y = b[i].y + sin(phi) * delta;
				tmp.d = di(tmp.x, tmp.y);
				b[i] = b[i].d < tmp.d ? tmp : b[i]; // L�ֵ�����50�����������				
			}
		} 
	} 
	// ����ѡһ������
	P p0 = b[0]; 
	for (int i = 1; i < M; i++) {
		p0 = p0.d < b[i].d ? b[i] : p0;
	}
	printf("The safest point is (%.1f, %.1f).\n", p0.x, p0.y);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		work();
	}
	return 0;
}
