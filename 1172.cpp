#include <iostream>
#include <cstdio>
using namespace std;

int rightNum (int a[4], int b[4], int s) {
	int f[4] = {0}, cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4 ; j++) {
			if (f[j])
				continue;
			if (a[i] == b[j]) {
				f[j] = 1;
				cnt++;
				break;
			}
		}
	}
	return s == cnt;
}

int rightPos (int a[4], int b[4], int s) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (a[i] == b[i])
			cnt++;
	}
	return s == cnt;
}

int main() {
	int n;
	while (cin >> n, n) {
		int a[100][4], rn[100], rp[100];
		for (int i = 0; i < n; i++) {
			scanf("%1d%1d%1d%1d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &rn[i], &rp[i]);
		}
		int count = 0, ans = 0;
		for (int i = 0; i < 10000; i++) {
			int tar = i, t[4] = {0}, j = 3;
			while (tar) {
				t[j] = tar % 10;
				tar /= 10;
				j--;
			}
			int flag = 1;
			for (int j = 0; j < n; j++) {
				if (rightNum(t, a[j], rn[j]) == 0 || rightPos(t, a[j], rp[j]) == 0 ) {
					flag = 0;
					break;					
				}
			}
			if (flag) {
				count++;
				ans = i;
			}
		}
		if (count == 1) {
			cout << ans / 1000 << (ans % 1000) / 100 << (ans % 100) / 10 << ans % 10 << endl;
		}
		else
			cout << "Not sure" << endl;
		
	}
}
