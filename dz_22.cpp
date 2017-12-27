#include <iostream.h>
#include <conio.h>
 

struct node
{
    int info; 
    node *l, *r;
};
 
node * tree=NULL; 
 

void push(int a,node **t)
{
    if ((*t)==NULL) 
    {
        (*t)=new node; 
        (*t)->info=a; 
        (*t)->l=(*t)->r=NULL; 
        return; 
       
        if (a>(*t)->info) push(a,&(*t)->r); 
        else push(a,&(*t)->l); 
}
 

void print (node *t,int u) 
{
    if (t==NULL) return; 
    else 
    {
    print(t->l,++u);
    for (int i=0;i<u;++i) cout<<"|";
    cout<<t->info<<endl; 
    u--;
    }
    print(t->r,++u); 
}

void delit(node *Tree) {
		if (Tree != NULL) {
			delit(Tree->l);
			delit(Tree->r);
			delete Tree;
		}
	}
 
void main ()
{   
    int n; 
    int s; 
    cout<<"введите количество элементов  ";
    cin>>n; /
    for (int i=0;i<n;++i)
    {
    cout<<"ведите число  ";
    cin>>s; 
   
    push(s,&tree); 
    }
    cout<<"ваше дерево\n";
    print(tree,0);
    getch();       
}
