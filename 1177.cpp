#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct att {
	int num, t, id;
}a[150];

int cmp (att a, att b) {
	if (a.num > b.num)
		return 1;
	else if (a.num < b.num)
		return 0;
	else
		return a.t < b.t;
}

int main() {
	int n, g, s, c, m;
	while (cin >> n >> g >> s >> c >> m, n + g + s + c + m) {
		for (int i = 0; i < n; i++) {
			int h, min, s;
			scanf("%d %2d:%2d:%2d", &a[i].num, &h, &min, &s);
			a[i].t = h * 60 * 60 + min * 60 + s;
			a[i].id = i + 1; // 这里应该是 i+1，而不是i 
		}
		sort(a, a + n, cmp);
		for (int i = 0; i < n; i++) {
			if (a[i].id != m )
				continue;
			if (i + 1 <= g) {
				cout << "Accepted today? I've got a golden medal :)" << endl;
				break;
			}
			else if (i + 1 <= g + s) {
				cout << "Accepted today? I've got a silver medal :)" << endl;
				break;
			}
			else if (i + 1 <= g + s + c) {
				cout << "Accepted today? I've got a copper medal :)" << endl;
				break;
			}
			else {
				cout << "Accepted today? I've got an honor mentioned :)" << endl;
				break;
			}
		}
	}
	return 0;
}
