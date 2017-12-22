#include<iostream> 
using namespace std;
void quickSort(int arr[], int left, int right, int k) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
			for (int f = left; f <= right ; f++) {
			}
		}
	}
	if (k < j) {
		if (left < j)
		quickSort(arr, left, j,k);
	}
	if (k >= i) {
		if (i < right)
		quickSort(arr, i, right, k-j);
	}
}
int main() {
	int n,k;
	cin >> n;
	int *ar = new int[n];
	for (int i = 0; i < n; i++) {
		cin>>ar[i];
	}
	cin >> k;
	quickSort(ar, 0, n-1 , k-1);
	cout << ar[k-1];
	return 0;
}
