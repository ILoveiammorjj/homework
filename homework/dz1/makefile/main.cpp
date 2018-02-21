#include <iostream>
#include <bits/stdc++.h>
#include "functions.h"

using namespace std;

int main(){
    print_hello();
    cout << endl;
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
