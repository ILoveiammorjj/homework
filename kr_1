#include <iostream>
using namespace std;

int main() {
	int l;
	cin>>l;
	int *a=new int [l];
	for(int i=0;i<l;++i)
	cin>>a[i];
	for(int i=0;i<l-1;++i){
		int ind = i;
		for(int j=i+1;j<l;++j){
			if(a[ind]>a[j])
			ind=j;
			
		}
		int u = a[i];
		a[i] = a[ind];
		a[ind] = u;
	}
	
	int k=0;
	for(int i=0;i<l-1;++i){
		if(a[i]==a[i+1])
		++k;
	}
	int nl=l-k;
	int *b=new int[nl];
	for(int i=0, j=0;i<l-1;++i){
		if(a[i]!=a[i+1])
		b[j++]=a[i];
	}
	b[nl-1]=a[l-1];
	for(int j=0;j<nl;++j)
	cout<<b[j]<<' ';
	return 0;
}
