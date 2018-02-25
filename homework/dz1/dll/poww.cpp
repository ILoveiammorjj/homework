#include "functions.h"

double poww(double a, int n) {
	double res = 1.0;
	while(n) {
		if(n&1) res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}
