/** 1264
**/
#include <iostream>
#include <cstring>
using namespace std;

const int maxN = 105;
int map[maxN][maxN];

int main () {
	int x1, y1, x2, y2;
	while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != EOF) {
		int ans = 0; 
		if (x1 == y1 && y1 == x2 && x2 == y2 && (y2 == -1 || y2 == -2)) {
			for (int i = 0; i < maxN; ++i)
				for (int j = 0; j < maxN; ++j)
					if (map[i][j])
						++ans;
			cout << ans << endl;
			memset(map, 0, sizeof(map));
		}
		else {
			if (x1 > x2)
				swap(x1, x2);
			if (y1 > y2)
				swap(y1, y2);
			for (int i = x1; i < x2; ++i)
				for (int j = y1; j < y2; ++j)
					map[i][j] = 1;
		}
	}
	return 0;
} 
