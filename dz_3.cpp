#include <iostream>

using namespace std;

void selectionSort(int *a, int n) {
    int p, minEl;
    for(int i = 0; i < n-1; ++i) {
        minEl = *(a+i);
        for(int j = i+1; j < n; ++j) {
            if(*(a+j) < minEl) {
                minEl = *(a+j);
                p = j;
            }
        }
        *(a+p) = *(a+i);
        *(a+i) = minEl;
    }
}

int main()
{
    return 0;
}
