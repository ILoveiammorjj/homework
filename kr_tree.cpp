#include <iostream>
#include <string>
 
using namespace std;
 
struct node {
	int d, m, y;
	node * l, * r;
};
 
void del(node * head){
	if(head->l)del(head->l);
	if(head->r)del(head->r);
	delete head;
}
 
bool flag = 0;
 
bool IsOlder(node * cur, node * tmp) {
	if (cur->y > tmp->y) return true;
	if (cur->y < tmp->y) return false;
	if (cur->m > tmp->m) return true;
	if (cur->m < tmp->m) return false;
	if (cur->d > tmp->d) return true;
	if (cur->d < tmp->d) return false;
	flag = 1;
	return true;
}
 
struct BinTree {
 
	node * head;
 
	void snap(node * cur, node * tmp) {
		if (cur == nullptr) {
			head = tmp;
			return;
		}
		if (IsOlder(cur, tmp)) {
			if (flag) {
				delete tmp;
				flag = 0;
				return;
			}
			if (cur->l == nullptr) {
				cur->l = tmp;
				return;
			}
			snap(cur->l, tmp);
		}
		else {
			if (cur->r == nullptr) {
				cur->r = tmp;
				return;
			}
			snap(cur->r, tmp);
		}
 
	}
	// ФОРМАТ XX/XX/XXXX
	void add(string date) {
		int d = stoi(date.substr(0, 2));
		int m = stoi(date.substr(3, 2));
		int y = stoi(date.substr(6, 4));
		node * tmp = new node;
		tmp->d = d;
		tmp->m = m;
		tmp->y = y;
		tmp->l = tmp->r = nullptr;
 
		snap(head, tmp);
	}
	bool search(node * cur, node * tmp) {
		if (cur == nullptr) return false;
		if (IsOlder(cur, tmp)) {
			if (flag) {
				flag = 0;
				return true;
			}
			return search(cur->l, tmp);
		}
		else
			return search(cur->r, tmp);
 
	}
	bool IsTrue(string date) {
		int d = stoi(date.substr(0, 2));
		int m = stoi(date.substr(3, 2));
		int y = stoi(date.substr(6, 4));
		node * tmp = new node;
		tmp->d = d;
		tmp->m = m;
		tmp->y = y;
		tmp->l = tmp->r = nullptr;
		if (search(head, tmp)) {
			delete tmp;
			return true;
		}
		delete tmp;
		return false;
	}
	~BinTree(){
		del(head);
	}
 
	};
 
int main()
{
	int n, m;
	cin >> n;
	struct BinTree t;
	t.head = nullptr;
	string date;
	for (int i = 0; i < n; ++i) {
		cin >> date;
		t.add(date);
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> date;
		if (t.IsTrue(date))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
 
	return 0;
}
