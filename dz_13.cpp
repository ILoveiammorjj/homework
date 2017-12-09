#include <iostream> 
#include <vector> 

using namespace std; 
vector <int> col; 
vector <int> ans; 

void count (int x) 
{ 
if (ans[x]!=-1) {return;} 
int i=1; 
int k=1000000; 
int l; 
while (i*i<=x) 
{ 
count(x-i*i); 
if (col[x-i*i]<k) {l=i; k=col[x-i*i];} 
i++; 
} 
ans[x]=ans[x-l*l]+l; 
col[x]=k+1; 

} 

int main() 
{ 
int X; 
cin»X; 
ans.resize(X+1,-1); 
col.resize(X+1,-1); 
ans[0]=0; 
col[0]=0; 
ans[1]=0; 
col[1]=1; 
count(X); 
cout«ans[X]; 

}
