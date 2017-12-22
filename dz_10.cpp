#include <iostream>
using namespace std;
int get(int k,int n, int *a) {
	int sum = 0;
	for (int m =n-k ; m < n ; ++m) {
		int x=0;
		if (a[m] == 0) {
			y= get(k, m, a);
		}
		else {
			x = a[m];
		}	
		sum = sum + x;
	}
	a[n] = sum;
	return a[n];
}
int main(){
	int n,k,sum;
	cin >> n ;
	cin >> k;
	if (k > n) {
		k = n;
	}
	int *a = new int[n];
	for (int i = 0; i < n; ++i) {
		a[i] = 0;
	}
	a[0] = 1;
	for (int i = 1; i<k; ++i) {
		sum = 0;
		for (int l = 0; l < k - 1; ++l) {
			sum = sum + a[l];
		}
		a[i] = sum+1;
	}
	if (k != n) {
		cout << get(k, n-1, a) << endl;
	}
	else {
		cout << a[n-1] << endl;
	}
	return 0;
}
