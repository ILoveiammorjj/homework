#include <iostream>
#include <stdio.h>
using namespace std;
int get(int x, int y, int **a) {
	int i = x;
	int j = y;
	if (a[i - 1][j - 1] == 0) a[i - 1][j - 1]=get(i - 1, j - 1, a);
	if (a[i - 1][j ] == 0) a[i - 1][j] = get(i - 1, j, a);
	if (a[i ][j - 1] == 0) a[i ][j - 1] = get(i , j - 1, a);
	if (a[i - 2][j - 2] == 0) a[i - 2][j - 2] = get(i - 2, j - 2, a);
	if (a[i - 2][j] == 0) a[i - 2][j] = get(i - 2, j, a);
	if (a[i][j - 2] == 0) a[i][j - 2] = get(i, j - 2, a);
	a[i][j] = a[i][j - 1] + a[i - 1][j] + a[i - 1][j - 1] + a[i][j - 2] + a[i - 2][j] + a[i - 2][j - 2];
	return a[x][y];
};
int main() {
	int x,y;
	cin >> x;
	cin >> y;
	int** ar = new int*[x];
	for (int i = 0; i < x; ++i) {
		ar[i] = new int[y];
	}
	ar[0][0] = 1;
	ar[0][1] = 1;
	ar[1][0] = 1;
	ar[1][1] = 3;	
	for (int j = 2; j < y; ++j) 
		ar[0][j] = ar[0][j - 1] + ar[0][j - 2];	
	for (int j = 2; j < y; ++j) 
		ar[1][j] = ar[1][j - 1] + ar[1][j - 2] + ar[0][j] + ar[0][j - 1];
	for (int j = 2; j < x; ++j)
		ar[j][0] = ar[j - 1][0]+ar[j - 2][0];
	for (int j = 2; j < x; ++j)
		ar[j][1] = ar[j - 1][1] + ar[j - 2][1] + ar[j][0] + ar[j - 1][0];
	for (int j = y-1; j >1; j--) {
		for (int i = x-1; i >1; i--) {
			 ar[i][j]=0 ;
		}
	}
	cout << get(x-1, y-1, ar)<<endl;
	return 0;
}
