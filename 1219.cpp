/**1219
**/
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char a[100000 + 5];
	while (gets(a)) {
		int b[27] = {0};
		// Ϊʲôд�� for (int i = 0; i < strlen(a); ++i)��TLE? 
		// �ѵ���Ϊÿ��ѭ��������һ��strlen(a) ? 
		int len = strlen(a);
		for (int i = 0; i < len; ++i) {
			int n = a[i] - 'a';
			if (n >= 0 && n < 26)
				++b[n];
		}
		for (int i = 0; i < 26; ++i)
			printf("%c:%d\n", (char)(i + 'a'), b[i]);
		printf("\n");
	}
	return 0;
} 
