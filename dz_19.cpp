#include <iostream>

using namespace std;

int Sift_Down(int a);
void Extract_Max();
void Sift_Up(int a);
int s, sz;
int *arr;

int main() {
	// s - макс. размер очереди
	// r - колво запросов
	// num : 1 - извлечь максимальный, 2 - добавить данный элемент в очередь
	int r, num, ins, p;
	cin >> s >> r;
	sz = s;
	s = 0;
	arr = new int[sz];
	for (; r; r--) {
		cin >> num;
		switch (num) {
		case 1: Extract_Max(); break;
		case 2: cin >> ins; Sift_Up(ins); break;
		}
	}
	for (int i = 0; i < s; i++) cout << arr[i] << ' ';
	return 0;
}
int Sift_Down(int a) {
	int k = a * 2 + 1;
	if (k > s - 1) return a + 1;
	if (k + 1 <= s - 1 && arr[k + 1] > arr[k]) k++;
	if (arr[k] > arr[a]) {
		swap(arr[k], arr[a]);
		Sift_Down(k);
	}
	else return a + 1;
}
void Extract_Max() {
	if (s == 0) { cout << -1 << endl; return; }
	if (s == 1) { cout << 0 << ' ' << arr[0] << endl; --s; return; }
	int data = arr[0];
	arr[0] = arr[s - 1];
	--s;
	cout << Sift_Down(0) << ' ' << data << endl;
}
void Sift_Up(int a) {
	if (s + 1 > sz) { cout << -1 << endl; return; }
	++s; arr[s - 1] = a;
	if (s == 1) { cout << 1 << endl; return; }
	int p = s - 1;
	while (p != 0 && arr[(p - 1) / 2] < arr[p]) {
		swap(arr[(p - 1) / 2], arr[p]);
		p = (p - 1) / 2;
	}
}
