#include <iostream>
using namespace std;
 
struct String {
private:
	int sz;
	char * data;
public:
	String(const char * s) {
		int i;
		for(i = 0; s[i]; ++i);
		sz = i;
		data = new char[sz+1];
		for(i = 0; s[i]; ++i)
			data[i] = s[i];
		data[sz] = '\0';
	}
	~String() { delete [] data; }
	void set(int i, char ch) { if(i > -1 && i < sz) data[i] = ch; }
  char* aget() { return data; }
	char get(int i) { if(i > -1 && i < sz) return data[i]; }
	int size() { return sz; }
	void concat(const char * s) {
		int i;
		for(i = 0; s[i]; ++i);
		char * tmp = new char[sz+i+1];
		for(i = 0; data[i]; ++i)
			tmp[i] = data[i];
		for(i = 0; s[i]; ++i)
			tmp[sz+i] = s[i];
		sz += i;
		tmp[sz+1] = '\0';
		delete [] data;
		data = tmp;
 
	}
 
};
 
int main() {
	return 0;
}
