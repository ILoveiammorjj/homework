#include <iostream>
#include <cmath>
using namespace std;


int main() {
	int m, n;
	cin >> m >> n;
	char **a = new char*[m];
	for(int i = 0; i < m; ++i) {
		a[i] = new char[n];
		for(int j = 0; j < n; ++j)
			a[i][j] = ' ';
	}
	int k = 0;
	for(int i = m-1; i >= 0 && k < ceil(n/2.0); --i) {
		for(int j = 0+k; j < n-k; ++j)
			a[i][j] = '|';
		++k;
	}
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
