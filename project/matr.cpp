#include "matr.h"

int main()
{

    ifstream fin("in.txt");
    ofstream fout("out.txt");
  Matr <double> m1(Size(3, 3)), m2(Size(3, 3));
  for (size_t i = 0; i < m1.size.n; i++)
    for (size_t j = 0; j < m1.size.m; j++)
     fin >> m1.m[i][j];


  for (size_t i = 0; i < m2.size.n; i++)
    for (size_t j = 0; j < m2.size.m; j++)
      m2.m[i][j] = 0;

  Matr<double> res;
  res = m1 + m2;
  Matr<double> res1;
  res1 = m1 * m2;
  double det = m1.Determinant();
  Matr<double> t = m1.Transpose();
  Matr<double> inv = m1.Inverse();
  Matr<double> minor=m1.GetMatr(0,1);
  double y[3] = {0, 1 , 1};
  Matr<double> gaus=m1.gauss(y);
  m1.Print(fout);
  t.Print(fout);
  fout<<"det is "<<det<<endl;
  inv.Print(fout);
  res.Print(fout);
  res1.Print(fout);
  minor.Print(fout);
  gaus.Print(fout);
  //m1.gauss(y,fout);
  return 0;
}
