#include <iostream>

using namespace std;

int main()
{ int n, m ;
 cin>>n>>m ;
 int *a= new int [n*m];
 for (int i=0; i<n; ++i){
    for (int j=0; j<m; ++j){
        int k;
        cin>>k;
        *(a+i*m+j)=k;
    }
 }

    return 0;
}
