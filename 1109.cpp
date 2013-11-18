/* #1109
模拟退火（启发式搜索算法）
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

const int M = 30; // 初始30个点 
const int L = 30; // 迭代次数 
const int N = 1050; // 最多1000个trap 

struct P {
	double x, y, d;
}a[N], b[M]; // x, y 坐标， d 到最近trap的距离 ，a traps数组， b 初始点

const double eps = 1e-3;
int X, Y , n; // 房间大小， trap数

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
	// 初始化M个点
	for (int i = 0; i < M; i++) {
		b[i].x = rand() % (X + 1); // 得到[0, X)的随机数
		b[i].y = rand() % (Y + 1);
		b[i].d = di(b[i].x, b[i].y); 
	}
	// 模拟退火, delta是改变量，由大变小 
	for (double delta = max(X, Y); delta > eps; delta *= 0.88) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < L; j++) {
				double phi = rand(); // 得到一个随机角度
				P tmp;
				tmp.x = b[i].x + cos(phi) * delta; // delta控制参数， 调整b[i]的位置 
				tmp.y = b[i].y + sin(phi) * delta;
				tmp.d = di(tmp.x, tmp.y);
				b[i] = b[i].d < tmp.d ? tmp : b[i]; // L轮迭代后50个点的最大距离				
			}
		} 
	} 
	// 从中选一个最大的
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
