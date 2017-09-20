#include <iostream>

using namespace std;

const int range = 1000; // свойство распределения простых чисел n/ln(n)
const int maxN = 8;

bool a[range]; // смотрим с 2
int field[maxN+2][maxN+2]; // +2 смотреть границу
int primeNum[range];

void findPrime() { //
    int q = 0;
    for(int i = 2; i < range; ++i) {
        if(a[i] == 0) {  // i простое
            primeNum[q++] = i;
            for(int j = i+i; j < range; j += i) {
                a[j] = 1;
            }
        }
    }
}
void d(int &x, int &y, int &i) {
    while(field[x][y] == 1) {
        field[x][y] = primeNum[i]*primeNum[i];
        ++x; ++i;
    }
    --x; --y;
}
void l(int &x, int &y, int &i) {
    while(field[x][y] == 1) {
        field[x][y] = primeNum[i]*primeNum[i];
        --y; ++i;
    }
    ++y; --x;
}
void u(int &x, int &y, int &i) {
    while(field[x][y] == 1) {
        field[x][y] = primeNum[i]*primeNum[i];
        --x; ++i;
    }
    ++x; ++y;
}
void r(int &x, int &y, int &i) {
    while(field[x][y] == 1) {
        field[x][y] = primeNum[i]*primeNum[i];
        ++y; ++i;
    }
    --y; ++x;
}

int main() {

    int n = 0;
    cin >> n; // n < 9

    if(n < 1) {
        exit(0);
    }

    findPrime();

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            field[i][j] = 1;
        }
    }

    int sz = n*n;

    int x = 1, y = n;

    for(int i = 0; i < sz;) {
        d(x, y, i);
        l(x, y, i);
        u(x, y, i);
        r(x, y, i);
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << field[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
