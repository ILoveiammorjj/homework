#include <iostream>
using namespace std;
 
void snake(int ** a, int n, int m) {
	int num = 0;
	int i = n-1, j = m-1;
	while(true) {
		while(i > -1 && a[i][j] == 0) { a[i][j] = ++num; --i; }
		++i; --j;
		if(num == n*m) break;
		while(j > -1 && a[i][j] == 0) { a[i][j] = ++num; --j; }
		++j; ++i;
		if(num == n*m) break;
		while(i < n && a[i][j] == 0) { a[i][j] = ++num; ++i; }
		--i; ++j;
		if(num == n*m) break;
		while(j < m && a[i][j] == 0) { a[i][j] = ++num; ++j; }
		--j; --i;
		if(num == n*m) break;
	}
}
 
int main() {
	int n, m;
	cin >> n >> m;
	int ** a = new int * [n];
	for(int i = 0; i < n; ++i) {
		a[i] = new int [m];
		for(int j = 0; j < m; ++j)
			a[i][j] = 0;
	}
	snake(a, n, m);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
