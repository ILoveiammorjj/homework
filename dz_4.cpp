#include <iostream>
using namespace std;

struct Rational {
	int num, dem;
	Rational operator+(Rational r) {
		Rational buf;
		num *= r.dem;
		r.num *= dem;
		buf.num = num + r.num;
		buf.dem = dem * r.dem;
		return buf;
	}
	Rational operator-(Rational r) {
		Rational buf;
		num *= r.dem;
		r.num *= dem;
		buf.num = num - r.num;
		buf.dem = dem * r.dem;
		return buf;
	}
	Rational operator*(Rational r) {
		Rational buf;
		buf.num = num * r.num;
		buf.dem = dem * r.dem;
		return buf;
	}
	Rational operator/(Rational r) {
		Rational buf;
		buf.num = num * r.dem;
		buf.dem = dem * r.num;
		return buf;
	}
	Rational operator=(Rational r) {
		num = r.num;
		dem = r.dem;
	}
};

int main() {
	Rational num1, num2, res;
	num1.num = 2; num1.dem = 3;
	num2.num = 3; num2.dem = -2;
	res = num1 * num2;
	cout << res.num << ' ' << res.dem;
	return 0;
}
