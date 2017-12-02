#include <iostream>
int m,n;
long long * a;
using namespace std;
long long stage(int i)
{	if(i < m) return 0;
	if(a[i]!=-1) return a[i];

	
	 a[i]=stage(i-1)+stage(i-3)+stage(i-4)+(i%2==0 ? stage(i/2) : 0);	
	return a[i];

	
	
	
	
}
int main() {
	
	cin >> m >> n;
	a = new long long int[n+1];

	for(int i=0;i<n+1;++i)
		a[i]=-1;
	a[m]=1;
	cout << stage(n);
	return 0;
}
