#pragma once
#include <iostream>
#include <assert.h>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;
struct Size
{
  int n, m;
  Size(int n, int m) : n(n) , m(m) {}
  Size() {}
  bool operator == (const Size &size) const
  {
    if (size.n != n || size.m != m)
      return false;
    return true;
  }
};

template <typename T>
class Matr
{
private:

 double abs(double x)
    {
        if (x>0)
            return x;
        return -x;
    }
public:
  Matr<T> GetMatr(int i_d, int j_d)
  {
    Matr<T> matr = *this;
    int i, j, i1 = 0, j1 = 0;

    matr.size.n = matr.size.n - 1;
    matr.size.m = matr.size.m - 1;

    matr.m.erase(matr.m.begin() + i_d);

    for (i = 0; i < size.n - 1; i++)
      matr.m[i].erase(matr.m[i].begin() + j_d);

    return matr;
  }

  Matr<T> s_alg(int x, int y)
  {
    int i, j;
    Matr<T> m_new(size);

    for (i = 0; i < size.n; i++)
      for (j = 0; j < size.n; j++)
        m_new.m[i][j] = i == y && j == x ? 1 : i == y || j == x ? 0 : m[i][j];

    return m_new;
  }

  vector<vector<T> > m;
  T *x;
  Size size;
  Matr(Size size_) : size(size_)
  {
    x = new T[size.n];
    vector<T> rows;
    for (int i = 0; i < size.m; i++)
      rows.push_back(0);

    for (int j = 0; j < size.n; j++)
      m.push_back(rows);
  }
  Matr<T> Transpose()
  {
    Matr<T> t(Size(size.m, size.n));

    for (size_t i = 0; i < size.n; i++)
      for (size_t j = 0; j < size.m; j++)
        t.m[j][i] = m[i][j];
    return t;
  }

T Determinant() {
    int i, j, d, k;
    int n;
    Matr<T> p(size);
    assert(size.n == size.m);
    j = 0; d = 0;
    k = 1; //(-1) в степени i
    n = size.m - 1;

    if (size.m == 1) {
      d = m[0][0];
      return(d);
    }
    if (size.m == 2) {
      d = m[0][0] * m[1][1] - m[1][0] * m[0][1];

      return(d);
    }
    if (size.m>2) {
      for (i = 0; i<size.m; i++) {
        p = GetMatr(i, 0);
        d = d + k * m[i][0] * p.Determinant();
        k = -k;
      }
    }
    return(d);
  }
  void operator*=(T num)
  {
    for (size_t i = 0; i < size.n; i++)
      for (size_t j = 0; j < size.m; j++)
        m[i][j] *= num;
  }

  Matr<T> operator*(const Matr<T> &m2)
  {
    Matr<T> m1 = *this;
    assert(m1.size.m == m2.size.n);

    Matr<T> prod(Size(m1.size));//= Unit(m1->size);
    int i, j;

    for (i = 0; i < prod.size.n; i++)
      for (j = 0; j < prod.size.m; j++)
      {
        double sum = 0;
        int k;

        for (k = 0; k < prod.size.m; k++)
          sum += m1.m[i][k] * m2.m[k][j];

        prod.m[i][j] = sum;
      }
    return prod;
  }

  Matr<T> operator+(const Matr &m2)
  {
    Matr<T> m1 = *this;
    assert(m1.size == m2.size);
    Matr<T> matr(Size(m1.size));

    for (size_t i = 0; i < m1.size.n; i++)
      for (size_t j = 0; j < m1.size.m; j++)
        matr.m[i][j] = m1.m[i][j] + m2.m[i][j];

    return matr;
  }
  Matr<T> operator-(const Matr &m2)
  {
    Matr<T> m1 = *this;
    assert(m1.size == m2.size);
    Matr<T> matr(Size(m1.size));

    for (size_t i = 0; i < m1.size.n; i++)
      for (size_t j = 0; j < m1.size.m; j++)
        matr.m[i][j] = m1.m[i][j] - m2.m[i][j];

    return matr;
  }
  void Print(ostream &out)
  {
    out << "matr is:" << endl;
    for (size_t i = 0; i < size.n; i++)
      for (size_t j = 0; j < size.m; j++)
        if (j == size.m - 1)
          out << m[i][j] << endl;
        else
          out << m[i][j] << ' ';
  }
  Matr<T> Inverse()
  {
    int i, j;
    Matr<T> m_t = *this;
    double k = m_t.Determinant();
    if(k==0)
        cout<<"Can't find inverse"<<endl;
    for (i = 0; i < size.n; i++)
      for (j = 0; j < size.n; j++)
      {
        /* Building algebraic transpose adjunct */
        Matr<T> tmp = s_alg(i, j);

        m_t.m[i][j] = tmp.Determinant();
      }

    for (i = 0; i < size.n; i++)
      for (j = 0; j < size.n; j++)
        {
            m_t.m[i][j]=m_t.m[i][j]/k;
        }

    return m_t;
  }
  Matr(){}
  Matr<T> gauss(T *y)
  {
    T max;
    int k, index;
    const double eps = 0.00001;  // точность
    k = 0;
    while (k < size.n)
    {
      // Поиск строки с максимальным a[i][k]
      max = abs(m[k][k]);
      index = k;
      for (int i = k + 1; i < size.n; i++)
      {
        if (abs(m[i][k]) > max)
        {
          max = abs(m[i][k]);
          index = i;
        }
      }
      // Перестановка строк
      if (max < eps)
      {
        // нет ненулевых диагональных элементов
        cout << "There is no ";
        cout << index << " efef" << endl;

      }
      for (int j = 0; j < size.n; j++)
      {
        double temp = m[k][j];
        m[k][j] = m[index][j];
        m[index][j] = temp;
      }
      double temp = y[k];
      y[k] = y[index];
      y[index] = temp;
      // Нормализация уравнений
      for (int i = k; i < size.n; i++)
      {
        double temp = m[i][k];
        if ((temp < eps)& (temp > -eps)) continue; // для нулевого коэффициента пропустить
        for (int j = 0; j < size.n; j++)
          m[i][j] = m[i][j] / temp;
        y[i] = y[i] / temp;
        if (i == k)  continue; // уравнение не вычитать само из себя
        for (int j = 0; j < size.n; j++)
          m[i][j] = m[i][j] - m[k][j];
        y[i] = y[i] - y[k];
      }
      k++;
    }
    // обратная подстановка
    for (k = size.n - 1; k >= 0; k--)
    {
      x[k] = y[k];
      for (int i = 0; i < k; i++)
        y[i] = y[i] - m[i][k] * x[k];

    }
    return x;
  }
  T &elem(int i, int j) {return m[i][j];}
};
