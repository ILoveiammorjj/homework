#include <iostream>
using namespace std;

struct Complex {
	double r, i;
	Complex operator+(Complex num) {
		Complex buf;
		buf.r = r + num.r;
		buf.i = i + num.i;
		return buf;
	}
	Complex operator*(Complex num) {
		Complex buf;
		buf.r = r*num.r - i*num.i;
		buf.i = r*num.i + i*num.r;
		return buf;
	}
};
int main() {
	
	return 0;
}
