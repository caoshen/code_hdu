/**1195
bfs
TLEÁË 
**/

#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <cstring>
using namespace std;

int vis[10000];
struct P {
	//string ss;
	int ar[4];
	int step;
};

//string mi(string s, int a) {
//	if (s[a] == '1')
//		s[a] = '9';
//	else
//		s[a] -= 1;
//	return s;
//} 
//
//string pl(string s, int a) {
//	if (s[a] == '9')
//		s[a] = '1';
//	else
//		s[a] += 1;
//	return s;
//}
//
//string sw(string s, int a, int b) {
//	char tmp = s[a];
//	s[a] = s[b];
//	s[b] = tmp;
//	return s;
//}

int tra(int ar[4]) {
	//return s[3] - '0' + (s[2] - '0') * 10 + (s[1] - '0') * 100 + (s[0] - '0') * 1000;
	return ar[0] * 1000 + ar[1] * 100 + ar[2] * 10 + ar[3];
}

string a, b;

void bfs() {
	memset(vis, 0, sizeof(vis));
	queue<P> q; 
	P p1, p0;
	for (int i = 0; i < 4; i++)
		p1.ar[i] = a[i] - '0';
	p1.step = 0;
	vis[tra(p1.ar)] = 1;
	q.push(p1);
	int cnt = 1000;
		
	while (!q.empty()) {
		p0 = q.front();
		if (p0.ar[0] == b[0] - '0' &&
			p0.ar[1] == b[1] - '0' &&
			p0.ar[2] == b[2] - '0' &&
			p0.ar[3] == b[3] - '0') {
			if (p0.step < cnt)
				cnt = p0.step; 
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			for(int j = 0; j < 3; j++) {
				P p2;
				for (int k = 0; k < 4; k++)
					p2.ar[k] = p0.ar[k];
				if (j == 0) {
					p2.ar[i] = p2.ar[i] == 1 ? 9 : p2.ar[i] - 1;
				}
				if (j == 1) {
					p2.ar[i] = p2.ar[i] == 9 ? 1 : p2.ar[i] + 1;
				}
				if (j == 2 && i < 3) {
					int tmp = p2.ar[i];
					p2.ar[i] = p2.ar[i+1];
					p2.ar[i+1] = tmp;
				}
				if (vis[tra(p2.ar)]) 
					continue;
				vis[tra(p2.ar)] = 1;
				p2.step = p0.step + 1;
				q.push(p2);
			}
		}
	}
	cout << cnt << endl;
	return;
}

int main() {
	int n;
	cin >> n;
	
	while (n--) {
		cin >> a >> b;
		bfs();	
	}
	return 0;
}
