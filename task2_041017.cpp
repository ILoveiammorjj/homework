#include <iostream>
using namespace std;

struct String {
	char *str;
	int len;
	String(char *s) {
		int i;
		for(i = 0; s[i]; ++i);
		len = i;
		str = new char[i+1];
		for(i = 0; s[i]; ++i) 
			str[i] = s[i];
		str[i] = '\0';
	}
	char get_n(int n) {
		if(n > -1 && n < len)
			return str[n];
		return '\0';
	}
	void set_n(int n, char ch) {
		if(n > -1 && n < len)
			str[n] = ch;
	}
	void out() {
		for(int i = 0; str[i]; ++i)
			cout << str[i];
	}
};

int main() {
	String str("abacaba");
	str.set_n(2, 'b');
	str.out();
	return 0;
}
