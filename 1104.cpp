/* #1104
bfs + ȡģ 
*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, K, M, vis[1000000];
struct P {
	int val, step;
	string s;
} p0, p1;

void bfs(int n, int k, int m) {
	memset(vis, 0, sizeof(vis));
	int t = ((n + 1) % k + k) % k;
	queue<P> q;
	p0.val = n;
	p0.step = 0;
	p0.s = "";
	q.push(p0);
	vis[(p0.val %k + k)%k] = 1;
	while (!q.empty()) {
		p0 = q.front();
		q.pop();
		if ((p0.val %k + k) % k == t) {
			cout << p0.step << endl;
			cout << p0.s << endl;
			return;
		}
		for (int i = 0; i < 4; i++) {
			p1 = p0;
			p1.step = p0.step + 1;
			if (i == 0) {
				p1.val = (p0.val + m) % (m * k);
				p1.s += "+";
			}
			if (i == 1) {
				p1.val = (p0.val - m) % (m * k);
				p1.s += "-";
			}
			if (i == 2) {
				p1.val = (p0.val * m) % (m * k);
				p1.s += "*";
			}
			if (i == 3) {
				p1.val = (p0.val % m + m) % m % (m * k);
				p1.s += "%";
			}
			if(!vis[(p1.val % k + k) % k]) {
				q.push(p1);
				vis[(p1.val % k + k) % k] = 1;
			}
		}
	}
			cout << "0" << endl;
}

int main() {
	while (cin >> N >> K >> M, N || K || M) {
		bfs(N, K, M);
	}
	return 0;
}
