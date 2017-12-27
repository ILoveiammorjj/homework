#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
typedef struct les {
	int start;
	int finish;
	string bla;
}les;

void quickSortR(les* a, int N) {

	long i = 0, j = N;
	int temp, p;
	p = a[N >> 1].finish;
	les temp1;

	do {
		while (a[i].finish < p) i++;
		while (a[j].finish > p) j--;

		if (i <= j) {
			temp1 = a[i]; a[i] = a[j]; a[j] = temp1;
			i++; j--;
		}
	} while (i <= j);

	if (j > 0) quickSortR(a, j);
	if (N > i) quickSortR(a + i, N - i);
}
int main() {
	int n;
	cin >> n;
	n++;
	string st1;
	les *mas = new les[n];
	for (int i = 0; i < n; i++) {
		getline(cin, st1);
		int g = st1.length();
		string r, r2, r1;
		int j;

		for (j = 0; j < g; j++) {
			if (st1[j] == ' ') {
				break;
			}
			r = r + st1[j];
		}
		mas[i].start = atoi(r.c_str());
		j++;
		for (j; j < g; j++) {
			if (st1[j] == ' ') {
				break;
			}
			r1 = r1 + st1[j];
		}
		mas[i].finish = atoi(r1.c_str());
		j++;
		for (j; j < g; j++) {
			r2 = r2 + st1[j];
		}
		mas[i].bla = r2;
	}
	quickSortR(mas, n - 1);
	int finmin = mas[1].finish;
	cout << mas[1].bla;
	for (int i = 1; i < n; i++) {
		if (finmin < mas[i].start) {
			cout << mas[i].bla;
			finmin = mas[i].finish;
		}
	}
	return 0;
}
