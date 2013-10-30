/* find_first_of(args) 从一个字符串中查找是不是有args中的字符
如果有， 返回位置，如果没有，返回string::npos
string.size() - 2 如果string.size() == 1,可能返回一个正数:2^32 -1 
所以不能直接 i < string.size() - 2 这么比较 
*/ 

#include <iostream> 
#include <string>

using namespace std;

int isVowel(char c) {
	if( c == 'a' ||
		c == 'e' ||
		c == 'i' ||
		c == 'o' ||
		c == 'u')
		return 1;
	else
		return 0;
}

int main() {
	string password;
	while (cin >> password) {
		if (password == "end")
		break;
		
		int i, flag = 1;
		string vowels("aeiou");		
		// rule 1
		if (password.find_first_of(vowels) == string::npos)
			flag = 0;
		// rule 2
		for (i = 0; i < (int)password.size() - 2; i++) {
			if (isVowel(password[i]) && isVowel(password[i+1]) && isVowel(password[i+2])) {
				flag = 0;
				break;
			}
			if (!(isVowel(password[i]) || isVowel(password[i+1]) || isVowel(password[i+2]))) {
				flag = 0;
				break;
			}
		}			
		// rule 3
		for (i = 0; i < (int)password.size() - 1; i++) {
			if (password[i] == password[i+1] && (password[i] != 'e' && password[i+1] != 'o')) {
				flag = 0;
				break;
			}
		}
		password = "<" + password + ">";
		if (flag == 1) {
			cout << password << " is acceptable." << endl;
		}
		else {
			cout << password << " is not acceptable." << endl;
		}
	}
	return 0;
}
