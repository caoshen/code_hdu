/** 1140
if oa ^ 2 - r ^ 2 >=  ab ^ 2
then a can hit b
**/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct P{
	double x, y, z;
};

double pi = 3.1415926;
double r = 40000 / (2 * pi);
P a[110], b[110];
int c[110];

int hit (P a, P b) {
	double oa = a.x * a.x + a.y * a.y + a.z * a.z;
	double ab = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
	if (oa - r * r >= ab)
		return 1;
	return 0;
}

int main() {
	int k, m;
	while (cin >> k >> m , k || m) {
		int count = 0;
		memset(c, 0, sizeof(c));
		for (int i = 0; i < k; i++)
			cin >> a[i].x >> a[i].y >> a[i].z;
		for (int i = 0; i < m; i++)
			cin >> b[i].x >> b[i].y >> b[i].z;
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < m; j++) {
				if (c[j] == 0 && hit(a[i], b[j])) {
					count++;
					c[j] = 1;
				}
					
			}
		}
		cout << count << endl;
	}
	return 0;
}
