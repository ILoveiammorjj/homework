#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector <int> a;
	int p;
	while (cin >> p){
		a.push_back(p);
		sort(a.begin(),a.end());
		
		for(int i=0; i < a.size(); i++){
			cout << a[i] << " ";
		}
	}
	return 0;
}
