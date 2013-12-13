/** 1181
dfs
i.e. big got them 
b -> g - > t - > m
**/
#include <iostream>
#include <cstring>
using namespace std;

int map[26][26];
int flag = 0;

void dfs(int x) {
	if (flag == 1)
		return;
	if (x == 12) {
		flag = 1;
		return;
	}
	for (int i = 0; i < 26; i++) {
		if (map[x][i] == 1) {
			map[x][i] = 0;
			dfs(i);
			map[x][i] = 1;
		}
	}
}

int main() {
	string s;
	while (cin >> s) {
		memset(map, 0, sizeof(map));
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++) {
				map[s[0] - 'a'][s[s.size() - 1] - 'a'] = 1;
			}
		while (cin >> s) {
			if (s == "0")
				break;
			for (int i = 0; i < 26; i++)
				for (int j = 0; j < 26; j++) {
					map[s[0] - 'a'][s[s.size() - 1] - 'a'] = 1;
				}
		}
		dfs(1); // seach from B
 		if (flag)
			cout << "Yes." << endl;
		else
			cout << "No." << endl;
		flag = 0;
	}
	return 0;
}
