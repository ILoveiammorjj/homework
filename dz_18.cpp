#include <iostream>
using namespace std;

struct node{
		int data;
		node*next;
	};
	struct list{
		node*head = NULL;
		void push(int new_data){
			node*temp = new node;
			temp -> data = new_data;
			temp -> next = head;
			head = temp;
		}
		int pop() {
			if (head == NULL) {
			 return 0;
			};
			node*temp = head;
			head = head -> next;
			int temp_data = temp -> data;
			delete temp;
			return temp_data;
		}
	};
void sort(list l) {
	node* temp = NULL;
	for(node* i = l.head; i != NULL; i = i->next) {
		temp = i;
		for(node* j = i->next; j != NULL; j = j->next) {
			if(j->data < temp->data) 
				temp = j;
		}
		swap(temp->data, i->data);
	}
}
int main() {
	list S;
	for(int i = 0; i < 10; i++)
	{
		int temp;
		cin>>temp;
		S.push(temp);
		
	}
	sort(S);
	
	for(int i = 0; i < 10; i ++)
	{ 
		cout << S.pop() << ' ';
	}

	return 0;
}
