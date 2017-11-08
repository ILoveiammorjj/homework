#include <bits/stdc++.h>
using namespace std;

double poww(double a, int n) {
	double res = 1.0;
	while(n) {
		if(n&1) res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<double> t(n*2);
	for(int i = 0; i < n; ++i) 
		cin >> t[n+i];
	for(int i = n-1; i > 0; --i)
		t[i] = poww(t[2*i], 2) + poww(t[2*i+1], 3) / 20;
	cout << t[1];
	return 0;
}
